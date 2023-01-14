# Makefile to rebuild MK64 split image

### Default target ###

default: all

### Build Options ###

# These options can either be changed by modifying the makefile, or
# by building with 'make SETTING=value'. 'make clean' may be required.

# Version of the game to build
VERSION ?= us
# If COMPARE is 1, check the output sha1sum when building 'all'
COMPARE ?= 1
export LANG := C

ifeq ($(VERSION),us)
  VERSION_CFLAGS := -DVERSION_US
  VERSION_ASFLAGS := --defsym VERSION_US=1
  TARGET := mk64.us
endif

# COMPILER - selects the C compiler to use
#   ido - uses the SGI IRIS Development Option compiler, which is used to build
#         an original matching N64 ROM
#   gcc - uses the GNU C Compiler
COMPILER ?= ido
$(eval $(call validate-option,COMPILER,ido gcc))

### Utility Functions ###
# Returns the path to the command $(1) if exists. Otherwise returns an empty string.
find-command = $(shell which $(1) 2>/dev/null)

################ Target Executable and Sources ###############

# BUILD_DIR is location where all build artifacts are placed
BUILD_DIR_BASE := build
BUILD_DIR := $(BUILD_DIR_BASE)/$(VERSION)

# Directories containing source files
INCLUDE_DIRS := include
SRC_DIRS := src src/audio src/os src/os/math courses
ASM_DIRS := asm asm/audio asm/os asm/os/non_matchings data data/sound_data
COURSE_DIRS := $(shell find courses -mindepth 2 -type d)

TEXTURES_DIR = textures

ALL_DIRS = $(BUILD_DIR) $(addprefix $(BUILD_DIR)/,$(SRC_DIRS) $(COURSE_DIRS) $(INCLUDE_DIRS) $(ASM_DIRS) $(ALL_KARTS_DIRS) $(TEXTURES_DIR)/raw $(TEXTURES_DIR)/standalone $(TEXTURES_DIR)/startup_logo $(TEXTURES_DIR)/crash_screen $(TEXTURES_DIR)/trophy)

################### Universal Dependencies ###################

# (This is a bit hacky, but a lot of rules implicitly depend
# on tools and assets, and we use directory globs further down
# in the makefile that we want should cover assets.)

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(MAKECMDGOALS),distclean)

# Make sure assets exist
NOEXTRACT ?= 0
ifeq ($(NOEXTRACT),0)
DUMMY != ./extract_assets.py $(VERSION) >&2 || echo FAIL
ifeq ($(DUMMY),FAIL)
  $(error Failed to extract assets)
endif
endif

# Make tools if out of date
DUMMY != make -s -C tools >&2 || echo FAIL
ifeq ($(DUMMY),FAIL)
  $(error Failed to build tools)
endif

endif
endif

LD_SCRIPT = mk64.ld
MIO0_DIR = bin

# Files with GLOBAL_ASM blocks
GLOBAL_ASM_C_FILES != grep -rl 'GLOBAL_ASM(' $(wildcard src/*.c)
GLOBAL_ASM_AUDIO_C_FILES != grep -rl 'GLOBAL_ASM(' $(wildcard src/audio/*.c)
GLOBAL_ASM_O_FILES = $(foreach file,$(GLOBAL_ASM_C_FILES),$(BUILD_DIR)/$(file:.c=.o))
GLOBAL_ASM_AUDIO_O_FILES = $(foreach file,$(GLOBAL_ASM_AUDIO_C_FILES),$(BUILD_DIR)/$(file:.c=.o))
# GLOBAL_ASM_DEP = $(BUILD_DIR)/src/audio/non_matching_dep

COURSE_ASM_FILES := $(wildcard courses/*/*/packed.s)

C_FILES := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
S_FILES := $(foreach dir,$(ASM_DIRS),$(wildcard $(dir)/*.s)) $(COURSE_ASM_FILES)
COURSE_FILES := $(foreach dir,$(COURSE_DIRS),$(wildcard $(dir)/model.inc.c))

# Object files
O_FILES := $(foreach file,$(C_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
		   $(foreach file,$(COURSE_FILES),$(BUILD_DIR)/$(file:.c=.o)) \
           $(foreach file,$(S_FILES),$(BUILD_DIR)/$(file:.s=.o))

# Automatic dependency files
DEP_FILES := $(O_FILES:.o=.d) $(BUILD_DIR)/$(LD_SCRIPT).d
##################### Compiler Options #######################

ifeq ($(shell type mips-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  CROSS := mips-linux-gnu-
else ifeq ($(shell type mips64-linux-gnu-ld >/dev/null 2>/dev/null; echo $$?), 0)
  CROSS := mips64-linux-gnu-
else
  CROSS := mips64-elf-
endif

# USE_QEMU_IRIX - when ido is selected, select which way to emulate IRIX programs
#   1 - use qemu-irix
#   0 - statically recompile the IRIX programs
USE_QEMU_IRIX ?= 0
$(eval $(call validate-option,USE_QEMU_IRIX,0 1))
TOOLS_DIR := tools

ifeq ($(USE_QEMU_IRIX),1)
  # Verify that qemu-irix exists
  QEMU_IRIX := $(call find-command,qemu-irix)
  ifeq (,$(QEMU_IRIX))
    $(error Using the IDO compiler requires qemu-irix. Please install qemu-irix package or set the QEMU_IRIX environment variable to the full qemu-irix binary path)
  endif
endif

ifeq ($(USE_QEMU_IRIX),1)
    IRIX_ROOT := $(TOOLS_DIR)/ido5.3_compiler
    CC        := $(QEMU_IRIX) -silent -L $(IRIX_ROOT) $(IRIX_ROOT)/usr/bin/cc
else
    IDO_ROOT := tools/ido5.3_recomp
    CC       := $(IDO_ROOT)/cc
endif

AS      := $(CROSS)as
LD      := $(CROSS)ld
AR      := $(CROSS)ar
OBJDUMP := $(CROSS)objdump
OBJCOPY := $(CROSS)objcopy
PYTHON    := python3

# Prefer clang as C preprocessor if installed on the system
ifneq (,$(call find-command,clang))
  CPP      := clang
  CPPFLAGS := -E -P -x c -Wno-trigraphs
else
  CPP      := cpp
  CPPFLAGS := -P -Wno-trigraphs
endif

MIPSISET := -mips2 -32
OPT_FLAGS := -O2

TARGET_CFLAGS := -nostdinc -I include/libc -DTARGET_N64
CC_CFLAGS := -fno-builtin

INCLUDE_CFLAGS := -I include -I $(BUILD_DIR) -I $(BUILD_DIR)/include -I src -I .

# TODO: Seperate F3D declares into version flags if needed.
GRUCODE_CFLAGS = -DF3DEX_GBI -D_LANGUAGE_C

# Check code syntax with host compiler
CC_CHECK := gcc -fsyntax-only -fsigned-char $(CC_CFLAGS) $(TARGET_CFLAGS) $(INCLUDE_CFLAGS) -std=gnu90 -Wall -Wextra -Wno-format-security -Wno-main -DNON_MATCHING -DAVOID_UB $(VERSION_CFLAGS) $(GRUCODE_CFLAGS)

ASFLAGS = -march=vr4300 -mabi=32 -I include -I $(BUILD_DIR) --defsym F3DEX_GBI=1
CFLAGS = -Wab,-r4300_mul -non_shared -G 0 -Xcpluscomm -Xfullwarn -signed $(OPT_FLAGS) $(TARGET_CFLAGS) $(INCLUDE_CFLAGS) $(VERSION_CFLAGS) $(MIPSISET) $(GRUCODE_CFLAGS)
OBJCOPYFLAGS = --pad-to=0xC00000 --gap-fill=0xFF

LDFLAGS = -T undefined_syms.txt -T $(BUILD_DIR)/$(LD_SCRIPT) -Map $(BUILD_DIR)/$(TARGET).map --no-check-sections

ifeq ($(shell getconf LONG_BIT), 32)
  # Work around memory allocation bug in QEMU
  export QEMU_GUEST_BASE := 1
else
  # Ensure that gcc treats the code as 32-bit
  CC_CHECK += -m32
endif

####################### Other Tools #########################

# N64 tools
MIO0TOOL = $(TOOLS_DIR)/mio0
N64CKSUM = $(TOOLS_DIR)/n64cksum
N64GRAPHICS = $(TOOLS_DIR)/n64graphics
BIN2C = $(PYTHON) $(TOOLS_DIR)/bin2c.py
EXTRACT_DATA_FOR_MIO  := $(TOOLS_DIR)/extract_data_for_mio
EMULATOR = mupen64plus
EMU_FLAGS = --noosd
LOADER = loader64
LOADER_FLAGS = -vwf

SHA1SUM = sha1sum


######################## Targets #############################

default: all

# file dependencies generated by splitter
MAKEFILE_SPLIT = Makefile.split
include $(MAKEFILE_SPLIT)

all: $(BUILD_DIR)/$(TARGET).z64
ifeq ($(COMPARE),1)
	@$(SHA1SUM) -c $(TARGET).sha1
endif

clean:
	$(RM) -r $(BUILD_DIR)

distclean:
	$(RM) -r $(BUILD_DIR_BASE)
	./extract_assets.py --clean
	make -C tools clean

# Make sure build directory exists before compiling anything
DUMMY != mkdir -p $(ALL_DIRS)

##################### Texture Generation #####################

# RGBA32, RGBA16, IA16, IA8, IA4, IA1, I8, I4
$(BUILD_DIR)/%: %.png
	$(N64GRAPHICS) -i $@ -g $< -f $(lastword $(subst ., ,$@))

$(BUILD_DIR)/textures/%.mio0: $(BUILD_DIR)/textures/%
	$(MIO0TOOL) -c $< $@
	
#################### Compressed Segments #####################

$(BUILD_DIR)/%.mio0: %.bin
	$(MIO0TOOL) -c $< $@

$(BUILD_DIR)/%.mio0.o: $(BUILD_DIR)/%.mio0.s
	$(AS) $(ASFLAGS) -o $@ $<

$(BUILD_DIR)/%.mio0.s: $(BUILD_DIR)/%.mio0
	printf ".section .data\n\n.balign 4\n\n.incbin \"$<\"\n" > $@

$(BUILD_DIR)/src/crash_screen.o: src/crash_screen.c
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/crash_screen/crash_screen_font.ia1.inc.c -g textures/crash_screen/crash_screen_font.ia1.png -f ia1 -s u8
	@$(CC_CHECK) -MMD -MP -MT $@ -MF $(BUILD_DIR)/$*.d $<
	$(CC) -c $(CFLAGS) -o $@ $<
	$(PYTHON) tools/set_o32abi_bit.py $@

$(BUILD_DIR)/src/trophy_model.inc.o: src/trophy_model.inc.c
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/trophy/reflection_map_brass.rgba16.inc.c -g textures/trophy/reflection_map_brass.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/trophy/reflection_map_silver.rgba16.inc.c -g textures/trophy/reflection_map_silver.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/trophy/reflection_map_gold.rgba16.inc.c -g textures/trophy/reflection_map_gold.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/trophy/podium1.rgba16.inc.c -g textures/trophy/podium1.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/trophy/podium2.rgba16.inc.c -g textures/trophy/podium2.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/trophy/podium3.rgba16.inc.c -g textures/trophy/podium3.rgba16.png -f rgba16 -s u8
	@$(CC_CHECK) -MMD -MP -MT $@ -MF $(BUILD_DIR)/$*.d $<
	$(CC) -c $(CFLAGS) -o $@ $<
	$(PYTHON) tools/set_o32abi_bit.py $@

$(BUILD_DIR)/src/startup_logo.inc.o: src/startup_logo.inc.c
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/startup_logo/reflection_map_gold.rgba16.inc.c -g textures/startup_logo/reflection_map_gold.rgba16.png -f rgba16 -s u8
	@$(CC_CHECK) -MMD -MP -MT $@ -MF $(BUILD_DIR)/$*.d $<
	$(CC) -c $(CFLAGS) -o $@ $<
	$(PYTHON) tools/set_o32abi_bit.py $@

# common textures
$(BUILD_DIR)/src/common_textures.inc.o: src/common_textures.inc.c
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_00000_tlut.rgba16.inc.c -g textures/132B50_00000_tlut.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_00200.rgba16.inc.c -g textures/132B50_00200.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_01EE8.rgba16.inc.c -g textures/132B50_01EE8.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_03348.rgba16.inc.c -g textures/132B50_03348.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_03B48.rgba16.inc.c -g textures/132B50_03B48.rgba16.png -f rgba16 -s u8
	
	# 132B50_04C68_tlut is an incredibly odd TLUT, its size appears to be 8x29? Which on the surface seems wrong but works in practice?
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_04C68_tlut.rgba16.inc.c -g textures/132B50_04C68_tlut.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTGreenShell.rgba16.inc.c -g textures/gTLUTGreenShell.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTBlueShell.rgba16.inc.c -g textures/gTLUTBlueShell.rgba16.png -f rgba16 -s u8

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_06A58.i4.inc.c -g textures/132B50_06A58.i4.png -f i4 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_06AD8.ia8.inc.c -g textures/132B50_06AD8.ia8.png -f ia8 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_06ED8_tlut.rgba16.inc.c -g textures/132B50_06ED8_tlut.rgba16.png -f rgba16 -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_06EF8.rgba16.ci4.inc.c -g textures/132B50_06EF8.rgba16.ci4.png -f ci4 -s u8 -c rgba16 -w 128 -h 32 -p textures/132B50_06ED8_tlut_gen.rgba16.bin
	
	
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_08150.ia8.inc.c -g textures/132B50_08150.ia8.png -f ia8 -s u8 -w 100 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_08470.ia8.inc.c -g textures/132B50_08470.ia8.png -f ia8 -s u8 -w 100 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_08790.ia8.inc.c -g textures/132B50_08790.ia8.png -f ia8 -s u8 -w 100 -h 8


	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_09958.i4.inc.c -g textures/132B50_09958.i4.png -s u8 -w 64 -h 96 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0A558.i4.inc.c -g textures/132B50_0A558.i4.png -s u8 -w 64 -h 16 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0A958.rgba16.inc.c -g textures/132B50_0A958.rgba16.png -s u8 -w 32 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0AB58.rgba16.inc.c -g textures/132B50_0AB58.rgba16.png -s u8 -w 32 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0AD58.rgba16.inc.c -g textures/132B50_0AD58.rgba16.png -s u8 -w 32 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0B158.rgba16.inc.c -g textures/132B50_0B158.rgba16.png -s u8 -w 32 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0B558.rgba16.inc.c -g textures/132B50_0B558.rgba16.png -s u8 -w 32 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0B958.rgba16.inc.c -g textures/132B50_0B958.rgba16.png -s u8 -w 32 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0BD58.rgba16.inc.c -g textures/132B50_0BD58.rgba16.png -s u8 -w 32 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0C158.rgba16.inc.c -g textures/132B50_0C158.rgba16.png -s u8 -w 32 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0C558.rgba16.inc.c -g textures/132B50_0C558.rgba16.png -s u8 -w 104 -h 16

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0D258.i4.inc.c -g textures/132B50_0D258.i4.png -s u8 -w 128 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0E258.i4.inc.c -g textures/132B50_0E258.i4.png -s u8 -w 128 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_0F258.i4.inc.c -g textures/132B50_0F258.i4.png -s u8 -w 128 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_10258.i4.inc.c -g textures/132B50_10258.i4.png -s u8 -w 128 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_11258.i4.inc.c -g textures/132B50_11258.i4.png -s u8 -w 128 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_12258.i4.inc.c -g textures/132B50_12258.i4.png -s u8 -w 128 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_13258.i4.inc.c -g textures/132B50_13258.i4.png -s u8 -w 128 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_14258.i4.inc.c -g textures/132B50_14258.i4.png -s u8 -w 128 -h 64 -f i4

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_15258.i4.inc.c -g textures/132B50_15258.i4.png -s u8 -w 64 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_15A58.i4.inc.c -g textures/132B50_15A58.i4.png -s u8 -w 64 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_16258.i4.inc.c -g textures/132B50_16258.i4.png -s u8 -w 64 -h 64 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_16A58.i4.inc.c -g textures/132B50_16A58.i4.png -s u8 -w 64 -h 64 -f i4

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_17258_tlut.rgba16.inc.c -g textures/132B50_17258_tlut.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_17458.rgba16.ci8.inc.c -g textures/132B50_17458.rgba16.ci8.png -s u8 -w 64 -h 32 -f ci8 -c rgba16 -p textures/132B50_17258_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_17C58.rgba16.ci8.inc.c -g textures/132B50_17C58.rgba16.ci8.png -s u8 -w 64 -h 32 -f ci8 -c rgba16 -p textures/132B50_17258_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_18458.rgba16.ci8.inc.c -g textures/132B50_18458.rgba16.ci8.png -s u8 -w 64 -h 32 -f ci8 -c rgba16 -p textures/132B50_17258_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_18C58.rgba16.ci8.inc.c -g textures/132B50_18C58.rgba16.ci8.png -s u8 -w 64 -h 32 -f ci8 -c rgba16 -p textures/132B50_17258_tlut.rgba16.png

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_19458_tlut.rgba16.inc.c -g textures/132B50_19458_tlut.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_19658.rgba16.ci8.inc.c -g textures/132B50_19658.rgba16.ci8.png -s u8 -w 16 -h 16 -f ci8 -c rgba16 -p textures/132B50_19458_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_19758.rgba16.ci8.inc.c -g textures/132B50_19758.rgba16.ci8.png -s u8 -w 16 -h 16 -f ci8 -c rgba16 -p textures/132B50_19458_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_19858.rgba16.ci8.inc.c -g textures/132B50_19858.rgba16.ci8.png -s u8 -w 16 -h 16 -f ci8 -c rgba16 -p textures/132B50_19458_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_19958.rgba16.ci8.inc.c -g textures/132B50_19958.rgba16.ci8.png -s u8 -w 16 -h 16 -f ci8 -c rgba16 -p textures/132B50_19458_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_19A58.rgba16.ci8.inc.c -g textures/132B50_19A58.rgba16.ci8.png -s u8 -w 16 -h 16 -f ci8 -c rgba16 -p textures/132B50_19458_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_19B58.rgba16.ci8.inc.c -g textures/132B50_19B58.rgba16.ci8.png -s u8 -w 16 -h 16 -f ci8 -c rgba16 -p textures/132B50_19458_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_19C58.rgba16.ci8.inc.c -g textures/132B50_19C58.rgba16.ci8.png -s u8 -w 16 -h 16 -f ci8 -c rgba16 -p textures/132B50_19458_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_19D58.rgba16.ci8.inc.c -g textures/132B50_19D58.rgba16.ci8.png -s u8 -w 16 -h 16 -f ci8 -c rgba16 -p textures/132B50_19458_tlut.rgba16.png

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_19E58_tlut.rgba16.inc.c -g textures/132B50_19E58_tlut.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A058.rgba16.ci8.inc.c -g textures/132B50_1A058.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A098.rgba16.ci8.inc.c -g textures/132B50_1A098.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A0D8.rgba16.ci8.inc.c -g textures/132B50_1A0D8.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A118.rgba16.ci8.inc.c -g textures/132B50_1A118.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A158.rgba16.ci8.inc.c -g textures/132B50_1A158.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A198.rgba16.ci8.inc.c -g textures/132B50_1A198.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A1D8.rgba16.ci8.inc.c -g textures/132B50_1A1D8.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A218.rgba16.ci8.inc.c -g textures/132B50_1A218.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A258.rgba16.ci8.inc.c -g textures/132B50_1A258.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_1A298.rgba16.ci8.inc.c -g textures/132B50_1A298.rgba16.ci8.png -s u8 -w 8 -h 8 -f ci8 -c rgba16 -p textures/132B50_19E58_tlut.rgba16.png

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_1A2D8.ia4.inc.c -g textures/132B50_1A2D8.ia4.png -s u8 -f ia4


	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTPortraitMario.rgba16.inc.c -g textures/gTLUTPortraitMario.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTPortraitLuigi.rgba16.inc.c -g textures/gTLUTPortraitLuigi.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTPortraitPeach.rgba16.inc.c -g textures/gTLUTPortraitPeach.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTPortraitToad.rgba16.inc.c -g textures/gTLUTPortraitToad.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTPortraitYoshi.rgba16.inc.c -g textures/gTLUTPortraitYoshi.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTPortraitDonkeyKong.rgba16.inc.c -g textures/gTLUTPortraitDonkeyKong.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTPortraitWario.rgba16.inc.c -g textures/gTLUTPortraitWario.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTPortraitBowser.rgba16.inc.c -g textures/gTLUTPortraitBowser.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_1B4D8_tlut.rgba16.inc.c -g textures/132B50_1B4D8_tlut.rgba16.png -s u8 -w 16 -h 16


	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTexturePortraitMario.rgba16.ci8.inc.c -g textures/gTexturePortraitMario.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/gTLUTPortraitMario.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTexturePortraitLuigi.rgba16.ci8.inc.c -g textures/gTexturePortraitLuigi.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/gTLUTPortraitLuigi.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTexturePortraitPeach.rgba16.ci8.inc.c -g textures/gTexturePortraitPeach.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/gTLUTPortraitPeach.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTexturePortraitToad.rgba16.ci8.inc.c -g textures/gTexturePortraitToad.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/gTLUTPortraitToad.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTexturePortraitYoshi.rgba16.ci8.inc.c -g textures/gTexturePortraitYoshi.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/gTLUTPortraitYoshi.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTexturePortraitDonkeyKong.rgba16.ci8.inc.c -g textures/gTexturePortraitDonkeyKong.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/gTLUTPortraitDonkeyKong.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTexturePortraitWario.rgba16.ci8.inc.c -g textures/gTexturePortraitWario.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/gTLUTPortraitWario.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTexturePortraitBowser.rgba16.ci8.inc.c -g textures/gTexturePortraitBowser.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/gTLUTPortraitBowser.rgba16.bin
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/gTexturePortraitMiniBombKart.rgba16.ci8.inc.c -g textures/gTexturePortraitMiniBombKart.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/132B50_1B4D8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/gTexturePortraitQuestionMark.rgba16.ci8.inc.c -g textures/gTexturePortraitQuestionMark.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/132B50_1B4D8_tlut.rgba16.png

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowNone.rgba16.inc.c -g textures/gTLUTItemWindowNone.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowBanana.rgba16.inc.c -g textures/gTLUTItemWindowBanana.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowBananaBunch.rgba16.inc.c -g textures/gTLUTItemWindowBananaBunch.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowMushroom.rgba16.inc.c -g textures/gTLUTItemWindowMushroom.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowDoubleMushroom.rgba16.inc.c -g textures/gTLUTItemWindowDoubleMushroom.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowTripleMushroom.rgba16.inc.c -g textures/gTLUTItemWindowTripleMushroom.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowSuperMushroom.rgba16.inc.c -g textures/gTLUTItemWindowSuperMushroom.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowBlueShell.rgba16.inc.c -g textures/gTLUTItemWindowBlueShell.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowBoo.rgba16.inc.c -g textures/gTLUTItemWindowBoo.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowGreenShell.rgba16.inc.c -g textures/gTLUTItemWindowGreenShell.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowTripleGreenShell.rgba16.inc.c -g textures/gTLUTItemWindowTripleGreenShell.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowRedShell.rgba16.inc.c -g textures/gTLUTItemWindowRedShell.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowTripleRedShell.rgba16.inc.c -g textures/gTLUTItemWindowTripleRedShell.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowStar.rgba16.inc.c -g textures/gTLUTItemWindowStar.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowThunderBolt.rgba16.inc.c -g textures/gTLUTItemWindowThunderBolt.rgba16.png -s u8 -w 16 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTItemWindowFakeItemBox.rgba16.inc.c -g textures/gTLUTItemWindowFakeItemBox.rgba16.png -s u8 -w 16 -h 16


	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowNone.rgba16.ci8.inc.c -g textures/gTextureItemWindowNone.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowNone.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowBanana.rgba16.ci8.inc.c -g textures/gTextureItemWindowBanana.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowBanana.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowBananaBunch.rgba16.ci8.inc.c -g textures/gTextureItemWindowBananaBunch.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowBananaBunch.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowMushroom.rgba16.ci8.inc.c -g textures/gTextureItemWindowMushroom.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowMushroom.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowDoubleMushroom.rgba16.ci8.inc.c -g textures/gTextureItemWindowDoubleMushroom.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowDoubleMushroom.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowTripleMushroom.rgba16.ci8.inc.c -g textures/gTextureItemWindowTripleMushroom.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowTripleMushroom.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowSuperMushroom.rgba16.ci8.inc.c -g textures/gTextureItemWindowSuperMushroom.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowSuperMushroom.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowBlueShell.rgba16.ci8.inc.c -g textures/gTextureItemWindowBlueShell.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowBlueShell.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowBoo.rgba16.ci8.inc.c -g textures/gTextureItemWindowBoo.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowBoo.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowGreenShell.rgba16.ci8.inc.c -g textures/gTextureItemWindowGreenShell.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowGreenShell.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowTripleGreenShell.rgba16.ci8.inc.c -g textures/gTextureItemWindowTripleGreenShell.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowTripleGreenShell.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowRedShell.rgba16.ci8.inc.c -g textures/gTextureItemWindowRedShell.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowRedShell.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowTripleRedShell.rgba16.ci8.inc.c -g textures/gTextureItemWindowTripleRedShell.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowTripleRedShell.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowStar.rgba16.ci8.inc.c -g textures/gTextureItemWindowStar.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowStar.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowThunderBolt.rgba16.ci8.inc.c -g textures/gTextureItemWindowThunderBolt.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowThunderBolt.rgba16.bin
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureItemWindowFakeItemBox.rgba16.ci8.inc.c -g textures/gTextureItemWindowFakeItemBox.rgba16.ci8.png -s u8 -w 40 -h 32 -f ci8 -c rgba16 -p textures/gTLUTItemWindowFakeItemBox.rgba16.bin

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTLakituNoLights.rgba16.inc.c -g textures/gTLUTLakituNoLights.rgba16.png -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTLakituRedLights.rgba16.inc.c -g textures/gTLUTLakituRedLights.rgba16.png -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTLakituBlueLight.rgba16.inc.c -g textures/gTLUTLakituBlueLight.rgba16.png -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTLakituCheckeredFlag.rgba16.inc.c -g textures/gTLUTLakituCheckeredFlag.rgba16.png -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTLakituSecondLap.rgba16.inc.c -g textures/gTLUTLakituSecondLap.rgba16.png -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTLakituFinalLap.rgba16.inc.c -g textures/gTLUTLakituFinalLap.rgba16.png -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTLakituReverse.rgba16.inc.c -g textures/gTLUTLakituReverse.rgba16.png -s u8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTLUTLakituFishing.rgba16.inc.c -g textures/gTLUTLakituFishing.rgba16.png -s u8

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_25ED8_tlut.rgba16.inc.c -g textures/132B50_25ED8_tlut.rgba16.png -s u8
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_260D8.rgba16.ci8.inc.c -g textures/132B50_260D8.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_26558.rgba16.ci8.inc.c -g textures/132B50_26558.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_269D8.rgba16.ci8.inc.c -g textures/132B50_269D8.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_26E58.rgba16.ci8.inc.c -g textures/132B50_26E58.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_272D8.rgba16.ci8.inc.c -g textures/132B50_272D8.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_27758.rgba16.ci8.inc.c -g textures/132B50_27758.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_27BD8.rgba16.ci8.inc.c -g textures/132B50_27BD8.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_28058.rgba16.ci8.inc.c -g textures/132B50_28058.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_284D8.rgba16.ci8.inc.c -g textures/132B50_284D8.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_28958.rgba16.ci8.inc.c -g textures/132B50_28958.rgba16.ci8.png -s u8 -w 24 -h 48 -f ci8 -c rgba16 -p textures/132B50_25ED8_tlut.rgba16.png

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_28DD8.rgba16.inc.c -g textures/132B50_28DD8.rgba16.png -s u8 -w 32 -h 16
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_291D8.rgba16.inc.c -g textures/132B50_291D8.rgba16.png -s u8 -w 16 -h 16

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_293D8.i4.inc.c -g textures/132B50_293D8.i4.png -s u8 -w 16 -h 16 -f i4
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_29458.i8.inc.c -g textures/132B50_29458.i8.png -s u8 -w 32 -h 32 -f i8

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2A858_tlut.rgba16.inc.c -g textures/132B50_2A858_tlut.rgba16.png -s u8
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_29858.rgba16.ci8.inc.c -g textures/132B50_29858.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/132B50_2A858_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_29C58.rgba16.ci8.inc.c -g textures/132B50_29C58.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/132B50_2A858_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_2A058.rgba16.ci8.inc.c -g textures/132B50_2A058.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/132B50_2A858_tlut.rgba16.png
	$(N64GRAPHICS) -Z $(BUILD_DIR)/textures/132B50_2A458.rgba16.ci8.inc.c -g textures/132B50_2A458.rgba16.ci8.png -s u8 -w 32 -h 32 -f ci8 -c rgba16 -p textures/132B50_2A858_tlut.rgba16.png

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2AA58.rgba16.inc.c -g textures/132B50_2AA58.rgba16.png -s u8 -w 16 -h 16

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2AC58.i8.inc.c -g textures/132B50_2AC58.i8.png -s u8 -w 32 -h 32 -f i8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2B058.i8.inc.c -g textures/132B50_2B058.i8.png -s u8 -w 32 -h 32 -f i8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2B458.i8.inc.c -g textures/132B50_2B458.i8.png -s u8 -w 32 -h 32 -f i8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2B858.i8.inc.c -g textures/132B50_2B858.i8.png -s u8 -w 32 -h 32 -f i8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2BC58.i8.inc.c -g textures/132B50_2BC58.i8.png -s u8 -w 32 -h 32 -f i8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2C058.i8.inc.c -g textures/132B50_2C058.i8.png -s u8 -w 32 -h 32 -f i8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2C458.i8.inc.c -g textures/132B50_2C458.i8.png -s u8 -w 32 -h 32 -f i8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/132B50_2C858.i8.inc.c -g textures/132B50_2C858.i8.png -s u8 -w 32 -h 32 -f i8

	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapFinishLine.rgba16.inc.c -g textures/gTextureMiniMapFinishLine.rgba16.png -s u8 -w 8 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapKartMario.rgba16.inc.c -g textures/gTextureMiniMapKartMario.rgba16.png -s u8 -w 8 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapKartLuigi.rgba16.inc.c -g textures/gTextureMiniMapKartLuigi.rgba16.png -s u8 -w 8 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapKartYoshi.rgba16.inc.c -g textures/gTextureMiniMapKartYoshi.rgba16.png -s u8 -w 8 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapKartToad.rgba16.inc.c -g textures/gTextureMiniMapKartToad.rgba16.png -s u8 -w 8 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapKartDonkeyKong.rgba16.inc.c -g textures/gTextureMiniMapKartDonkeyKong.rgba16.png -s u8 -w 8 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapKartWario.rgba16.inc.c -g textures/gTextureMiniMapKartWario.rgba16.png -s u8 -w 8 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapKartPeach.rgba16.inc.c -g textures/gTextureMiniMapKartPeach.rgba16.png -s u8 -w 8 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapKartBowser.rgba16.inc.c -g textures/gTextureMiniMapKartBowser.rgba16.png -s u8 -w 8 -h 8
	$(N64GRAPHICS) -i $(BUILD_DIR)/textures/gTextureMiniMapProgressDot.rgba16.inc.c -g textures/gTextureMiniMapProgressDot.rgba16.png -s u8 -w 8 -h 8
	

	@$(CC_CHECK) -MMD -MP -MT $@ -MF $(BUILD_DIR)/$*.d $<
	$(CC) -c $(CFLAGS) -o $@ $<
	$(PYTHON) tools/set_o32abi_bit.py $@

$(BUILD_DIR)/%.o: %.c
	@$(CC_CHECK) -MMD -MP -MT $@ -MF $(BUILD_DIR)/$*.d $<
	$(CC) -c $(CFLAGS) -o $@ $<
	$(PYTHON) tools/set_o32abi_bit.py $@

$(BUILD_DIR)/%.o: $(BUILD_DIR)/%.c
	@$(CC_CHECK) -MMD -MP -MT $@ -MF $(BUILD_DIR)/$*.d $<
	$(CC) -c $(CFLAGS) -o $@ $<

$(BUILD_DIR)/%.o: %.s $(MIO0_FILES) $(RAW_TEXTURE_FILES)
	$(AS) $(ASFLAGS) -o $@ $<

$(GLOBAL_ASM_O_FILES): CC := $(PYTHON) tools/asm_processor/build.py $(CC) -- $(AS) $(ASFLAGS) --

$(GLOBAL_ASM_AUDIO_O_FILES): CC := $(PYTHON) tools/asm_processor/build.py $(CC) -- $(AS) $(ASFLAGS) --

$(BUILD_DIR)/$(LD_SCRIPT): $(LD_SCRIPT) #repeat for other files
	$(CPP) $(CPPFLAGS) $(VERSION_CFLAGS) -DBUILD_DIR=$(BUILD_DIR) -MMD -MP -MT $@ -MF $@.d -o $@ $<


#################### Libultra                      #####################
$(BUILD_DIR)/src/os/%.o:          OPT_FLAGS :=
$(BUILD_DIR)/src/os/math/%.o:     OPT_FLAGS := -O2
$(BUILD_DIR)/src/os/math/ll%.o:   OPT_FLAGS :=
$(BUILD_DIR)/src/os/math/ll%.o:   MIPSISET := -mips3 -32
$(BUILD_DIR)/src/os/ldiv.o:       OPT_FLAGS := -O2
$(BUILD_DIR)/src/os/string.o:     OPT_FLAGS := -O2
$(BUILD_DIR)/src/os/gu%.o:        OPT_FLAGS := -O3
$(BUILD_DIR)/src/os/al%.o:        OPT_FLAGS := -O3
$(BUILD_DIR)/src/os/__osLeoInterrupt.o:        OPT_FLAGS := -O1
$(BUILD_DIR)/src/os/_Printf.o:        OPT_FLAGS := -O3
$(BUILD_DIR)/src/os/_Litob.o:        OPT_FLAGS := -O3
$(BUILD_DIR)/src/os/_Ldtob.o:        OPT_FLAGS := -O3
$(BUILD_DIR)/src/os/osSyncPrintf.o:        OPT_FLAGS := -O3

# Alternate compiler flags needed for matching
ifeq ($(COMPILER),ido)
    $(BUILD_DIR)/src/audio/%.o:        OPT_FLAGS := -O2 -use_readwrite_const
    $(BUILD_DIR)/src/audio/port_eu.o:  OPT_FLAGS := -O2 -framepointer
    $(BUILD_DIR)/src/audio/external.o:  OPT_FLAGS := -O2 -framepointer
endif

#################### Compile course vertex to mio0 #####################

COURSE_MODEL_TARGETS := $(foreach dir,$(COURSE_DIRS),$(BUILD_DIR)/$(dir)/model.inc.mio0.o)

# Elf the course data to include symbol addresses then convert to binary and compress to mio0. The mio0 file is converted to an object file so that the linker can link it.
$(COURSE_MODEL_TARGETS) : $(BUILD_DIR)/%/model.inc.mio0.o : %/model.inc.c
	$(LD) -t -e 0 -Ttext=0F000000 -Map $(@D)/model.inc.elf.map -o $(@D)/model.inc.elf $(@D)/model.inc.o --no-check-sections
	$(V)$(EXTRACT_DATA_FOR_MIO) $(@D)/model.inc.elf $(@D)/model.inc.bin
	$(MIO0TOOL) -c $(@D)/model.inc.bin $(@D)/model.inc.mio0
	printf ".include \"macros.inc\"\n\n.section .data\n\n.balign 4\n\n.incbin \"$(@D)/model.inc.mio0\"\n\n.balign 4\n\nglabel d_course_$(lastword $(subst /, ,$*))_packed\n\n.incbin \"bin/course_$(lastword $(subst /, ,$*))_packed.bin\"\n" > $(@D)/model.inc.mio0.s
	$(AS) $(ASFLAGS) -o $@ $(@D)/model.inc.mio0.s

####################       STAFF GHOSTS        #####################

# trophy_model.inc.c

$(BUILD_DIR)/src/trophy_model.inc.mio0.o: $(BUILD_DIR)/src/trophy_model.inc.o
	$(LD) -t -e 0 -Ttext=0B000000 -Map $(BUILD_DIR)/src/trophy_model.inc.elf.map -o $(BUILD_DIR)/src/trophy_model.inc.elf $(BUILD_DIR)/src/trophy_model.inc.o --no-check-sections
	$(V)$(EXTRACT_DATA_FOR_MIO) $(BUILD_DIR)/src/trophy_model.inc.elf $(BUILD_DIR)/src/trophy_model.inc.bin
	$(MIO0TOOL) -c $(BUILD_DIR)/src/trophy_model.inc.bin $(BUILD_DIR)/src/trophy_model.inc.mio0
	printf ".include \"macros.inc\"\n\n.data\n\n.balign 4\n\nglabel trophy_model\n\n.incbin \"build/us/src/trophy_model.inc.mio0\"\n\n.balign 16\nglabel data_821D10_end\n" > build/us/src/trophy_model.inc.mio0.s
	$(AS) $(ASFLAGS) -o $(BUILD_DIR)/src/trophy_model.inc.mio0.o $(BUILD_DIR)/src/trophy_model.inc.mio0.s

# startup_logo.inc.c

$(BUILD_DIR)/src/startup_logo.inc.mio0.o: src/startup_logo.inc.c
	$(LD) -t -e 0 -Ttext=06000000 -Map $(BUILD_DIR)/src/startup_logo.inc.elf.map -o $(BUILD_DIR)/src/startup_logo.inc.elf $(BUILD_DIR)/src/startup_logo.inc.o --no-check-sections
	$(V)$(EXTRACT_DATA_FOR_MIO) $(BUILD_DIR)/src/startup_logo.inc.elf $(BUILD_DIR)/src/startup_logo.inc.bin
	$(MIO0TOOL) -c $(BUILD_DIR)/src/startup_logo.inc.bin $(BUILD_DIR)/src/startup_logo.inc.mio0
	printf ".include \"macros.inc\"\n\n.data\n\n\n\n.balign 4\n\n\nglabel startup_logo\n\n.incbin \"build/us/src/startup_logo.inc.mio0\"\n\n.balign 16\n\nglabel data_825800_end\n" > build/us/src/startup_logo.inc.mio0.s
	$(AS) $(ASFLAGS) -o $(BUILD_DIR)/src/startup_logo.inc.mio0.o $(BUILD_DIR)/src/startup_logo.inc.mio0.s

# common_textures.inc.c
$(BUILD_DIR)/src/common_textures.inc.mio0.o: $(BUILD_DIR)/src/common_textures.inc.o
	$(LD) -t -e 0 -Ttext=0D000000 --unresolved-symbols=ignore-all -Map $(BUILD_DIR)/src/common_textures.inc.elf.map -o $(BUILD_DIR)/src/common_textures.inc.elf $(BUILD_DIR)/src/common_textures.inc.o --no-check-sections
	$(V)$(EXTRACT_DATA_FOR_MIO) $(BUILD_DIR)/src/common_textures.inc.elf $(BUILD_DIR)/src/common_textures.inc.bin
	$(MIO0TOOL) -c $(BUILD_DIR)/src/common_textures.inc.bin $(BUILD_DIR)/src/common_textures.inc.mio0
	printf ".include \"macros.inc\"\n\n.section .data\n\n.balign 4\n\n.incbin \"src/common_textures.inc.mio0\"\n\n" > build/us/src/common_textures.inc.mio0.s
	$(AS) $(ASFLAGS) -o $(BUILD_DIR)/src/common_textures.inc.mio0.o $(BUILD_DIR)/src/common_textures.inc.mio0.s


$(BUILD_DIR)/$(TARGET).elf: $(O_FILES) $(COURSE_MIO0_OBJ_FILES) $(BUILD_DIR)/$(LD_SCRIPT) $(BUILD_DIR)/src/startup_logo.inc.mio0.o $(BUILD_DIR)/src/trophy_model.inc.mio0.o $(BUILD_DIR)/src/common_textures.inc.mio0.o $(COURSE_MODEL_TARGETS) undefined_syms.txt
	$(LD) $(LDFLAGS) -o $@

$(BUILD_DIR)/$(TARGET).z64: $(BUILD_DIR)/$(TARGET).elf
	$(OBJCOPY) $(OBJCOPYFLAGS) $< $(@:.z64=.bin) -O binary
	$(N64CKSUM) $(@:.z64=.bin) $@

$(BUILD_DIR)/$(TARGET).hex: $(TARGET).z64
	xxd $< > $@

$(BUILD_DIR)/$(TARGET).objdump: $(BUILD_DIR)/$(TARGET).elf 
	$(OBJDUMP) -D $< > $@

test: $(TARGET).z64
	$(EMULATOR) $(EMU_FLAGS) $<

load: $(TARGET).z64
	$(LOADER) $(LOADER_FLAGS) $<

.PHONY: all clean distclean default diff test load
.SECONDARY:

# Remove built-in rules, to improve  build/us/courses/star_cup/bowsers_castle/model.inc.mio0.performance
MAKEFLAGS += --no-builtin-rules

-include $(DEP_FILES)


print-% : ; $(info $* is a $(flavor $*) variable set to [$($*)]) @true
