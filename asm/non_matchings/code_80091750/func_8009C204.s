.section .late_rodata

glabel D_800F1074
.float 0.457

.section .text

glabel func_8009C204
/* 09CE04 8009C204 27BDFF80 */  addiu $sp, $sp, -0x80
/* 09CE08 8009C208 AFB00058 */  sw    $s0, 0x58($sp)
/* 09CE0C 8009C20C 00808025 */  move  $s0, $a0
/* 09CE10 8009C210 AFBF007C */  sw    $ra, 0x7c($sp)
/* 09CE14 8009C214 AFBE0078 */  sw    $fp, 0x78($sp)
/* 09CE18 8009C218 AFB70074 */  sw    $s7, 0x74($sp)
/* 09CE1C 8009C21C 00C0B825 */  move  $s7, $a2
/* 09CE20 8009C220 00E0F025 */  move  $fp, $a3
/* 09CE24 8009C224 AFB60070 */  sw    $s6, 0x70($sp)
/* 09CE28 8009C228 AFB5006C */  sw    $s5, 0x6c($sp)
/* 09CE2C 8009C22C AFB40068 */  sw    $s4, 0x68($sp)
/* 09CE30 8009C230 AFB30064 */  sw    $s3, 0x64($sp)
/* 09CE34 8009C234 AFB20060 */  sw    $s2, 0x60($sp)
/* 09CE38 8009C238 AFB1005C */  sw    $s1, 0x5c($sp)
/* 09CE3C 8009C23C F7B60050 */  sdc1  $f22, 0x50($sp)
/* 09CE40 8009C240 F7B40048 */  sdc1  $f20, 0x48($sp)
/* 09CE44 8009C244 0C026449 */  jal   segmented_to_virtual_dupe
/* 09CE48 8009C248 00A02025 */   move  $a0, $a1
/* 09CE4C 8009C24C 8C4E0004 */  lw    $t6, 4($v0)
/* 09CE50 8009C250 00408825 */  move  $s1, $v0
/* 09CE54 8009C254 3C01800F */  lui   $at, %hi(D_800F1074) # $at, 0x800f
/* 09CE58 8009C258 11C00067 */  beqz  $t6, .L8009C3F8
/* 09CE5C 8009C25C 3C160200 */   lui   $s6, %hi(D_02007728) # $s6, 0x200
/* 09CE60 8009C260 C4361074 */  lwc1  $f22, %lo(D_800F1074)($at)
/* 09CE64 8009C264 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 09CE68 8009C268 4481A000 */  mtc1  $at, $f20
/* 09CE6C 8009C26C 26D67728 */  addiu $s6, %lo(D_02007728) # addiu $s6, $s6, 0x7728
/* 09CE70 8009C270 24150003 */  li    $s5, 3
/* 09CE74 8009C274 8FB40090 */  lw    $s4, 0x90($sp)
/* 09CE78 8009C278 3C130600 */  lui   $s3, 0x600
/* 09CE7C 8009C27C 86220000 */  lh    $v0, ($s1)
.L8009C280:
/* 09CE80 8009C280 3C0F0200 */  lui   $t7, %hi(D_02007708) # $t7, 0x200
/* 09CE84 8009C284 00009025 */  move  $s2, $zero
/* 09CE88 8009C288 1040000B */  beqz  $v0, .L8009C2B8
/* 09CE8C 8009C28C 25EF7708 */   addiu $t7, %lo(D_02007708) # addiu $t7, $t7, 0x7708
/* 09CE90 8009C290 24010001 */  li    $at, 1
/* 09CE94 8009C294 5041000E */  beql  $v0, $at, .L8009C2D0
/* 09CE98 8009C298 02001025 */   move  $v0, $s0
/* 09CE9C 8009C29C 10550010 */  beq   $v0, $s5, .L8009C2E0
/* 09CEA0 8009C2A0 3C180200 */   lui   $t8, %hi(D_02007768) # $t8, 0x200
/* 09CEA4 8009C2A4 02001025 */  move  $v0, $s0
/* 09CEA8 8009C2A8 AC530000 */  sw    $s3, ($v0)
/* 09CEAC 8009C2AC AC560004 */  sw    $s6, 4($v0)
/* 09CEB0 8009C2B0 10000011 */  b     .L8009C2F8
/* 09CEB4 8009C2B4 26100008 */   addiu $s0, $s0, 8
.L8009C2B8:
/* 09CEB8 8009C2B8 02001025 */  move  $v0, $s0
/* 09CEBC 8009C2BC AC530000 */  sw    $s3, ($v0)
/* 09CEC0 8009C2C0 AC4F0004 */  sw    $t7, 4($v0)
/* 09CEC4 8009C2C4 1000000C */  b     .L8009C2F8
/* 09CEC8 8009C2C8 26100008 */   addiu $s0, $s0, 8
/* 09CECC 8009C2CC 02001025 */  move  $v0, $s0
.L8009C2D0:
/* 09CED0 8009C2D0 AC530000 */  sw    $s3, ($v0)
/* 09CED4 8009C2D4 AC560004 */  sw    $s6, 4($v0)
/* 09CED8 8009C2D8 10000007 */  b     .L8009C2F8
/* 09CEDC 8009C2DC 26100008 */   addiu $s0, $s0, 8
.L8009C2E0:
/* 09CEE0 8009C2E0 02001025 */  move  $v0, $s0
/* 09CEE4 8009C2E4 27187768 */  addiu $t8, %lo(D_02007768) # addiu $t8, $t8, 0x7768
/* 09CEE8 8009C2E8 AC580004 */  sw    $t8, 4($v0)
/* 09CEEC 8009C2EC AC530000 */  sw    $s3, ($v0)
/* 09CEF0 8009C2F0 26100008 */  addiu $s0, $s0, 8
/* 09CEF4 8009C2F4 02A09025 */  move  $s2, $s5
.L8009C2F8:
/* 09CEF8 8009C2F8 0C026E31 */  jal   func_8009B8C4
/* 09CEFC 8009C2FC 8E240004 */   lw    $a0, 4($s1)
/* 09CF00 8009C300 24010002 */  li    $at, 2
/* 09CF04 8009C304 12810005 */  beq   $s4, $at, .L8009C31C
/* 09CF08 8009C308 00404025 */   move  $t0, $v0
/* 09CF0C 8009C30C 5295001E */  beql  $s4, $s5, .L8009C388
/* 09CF10 8009C310 E7B60010 */   swc1  $f22, 0x10($sp)
/* 09CF14 8009C314 10000035 */  b     .L8009C3EC
/* 09CF18 8009C318 8E290018 */   lw    $t1, 0x18($s1)
.L8009C31C:
/* 09CF1C 8009C31C E7B40010 */  swc1  $f20, 0x10($sp)
/* 09CF20 8009C320 E7B40014 */  swc1  $f20, 0x14($sp)
/* 09CF24 8009C324 AFA00018 */  sw    $zero, 0x18($sp)
/* 09CF28 8009C328 AFA0001C */  sw    $zero, 0x1c($sp)
/* 09CF2C 8009C32C 96220008 */  lhu   $v0, 8($s1)
/* 09CF30 8009C330 00122E00 */  sll   $a1, $s2, 0x18
/* 09CF34 8009C334 0005CE03 */  sra   $t9, $a1, 0x18
/* 09CF38 8009C338 AFA20020 */  sw    $v0, 0x20($sp)
/* 09CF3C 8009C33C 9623000A */  lhu   $v1, 0xa($s1)
/* 09CF40 8009C340 03202825 */  move  $a1, $t9
/* 09CF44 8009C344 02002025 */  move  $a0, $s0
/* 09CF48 8009C348 AFA30024 */  sw    $v1, 0x24($sp)
/* 09CF4C 8009C34C 9629000C */  lhu   $t1, 0xc($s1)
/* 09CF50 8009C350 24060400 */  li    $a2, 1024
/* 09CF54 8009C354 24070400 */  li    $a3, 1024
/* 09CF58 8009C358 01375021 */  addu  $t2, $t1, $s7
/* 09CF5C 8009C35C AFAA0028 */  sw    $t2, 0x28($sp)
/* 09CF60 8009C360 962B000E */  lhu   $t3, 0xe($s1)
/* 09CF64 8009C364 AFA80030 */  sw    $t0, 0x30($sp)
/* 09CF68 8009C368 AFA20034 */  sw    $v0, 0x34($sp)
/* 09CF6C 8009C36C 017E6021 */  addu  $t4, $t3, $fp
/* 09CF70 8009C370 AFAC002C */  sw    $t4, 0x2c($sp)
/* 09CF74 8009C374 0C0258FC */  jal   func_800963F0
/* 09CF78 8009C378 AFA30038 */   sw    $v1, 0x38($sp)
/* 09CF7C 8009C37C 1000001A */  b     .L8009C3E8
/* 09CF80 8009C380 00408025 */   move  $s0, $v0
/* 09CF84 8009C384 E7B60010 */  swc1  $f22, 0x10($sp)
.L8009C388:
/* 09CF88 8009C388 E7B40014 */  swc1  $f20, 0x14($sp)
/* 09CF8C 8009C38C AFA00018 */  sw    $zero, 0x18($sp)
/* 09CF90 8009C390 AFA0001C */  sw    $zero, 0x1c($sp)
/* 09CF94 8009C394 96220008 */  lhu   $v0, 8($s1)
/* 09CF98 8009C398 00122E00 */  sll   $a1, $s2, 0x18
/* 09CF9C 8009C39C 00056E03 */  sra   $t5, $a1, 0x18
/* 09CFA0 8009C3A0 AFA20020 */  sw    $v0, 0x20($sp)
/* 09CFA4 8009C3A4 9623000A */  lhu   $v1, 0xa($s1)
/* 09CFA8 8009C3A8 01A02825 */  move  $a1, $t5
/* 09CFAC 8009C3AC 02002025 */  move  $a0, $s0
/* 09CFB0 8009C3B0 AFA30024 */  sw    $v1, 0x24($sp)
/* 09CFB4 8009C3B4 962E000C */  lhu   $t6, 0xc($s1)
/* 09CFB8 8009C3B8 24060400 */  li    $a2, 1024
/* 09CFBC 8009C3BC 24070400 */  li    $a3, 1024
/* 09CFC0 8009C3C0 01D77821 */  addu  $t7, $t6, $s7
/* 09CFC4 8009C3C4 AFAF0028 */  sw    $t7, 0x28($sp)
/* 09CFC8 8009C3C8 9638000E */  lhu   $t8, 0xe($s1)
/* 09CFCC 8009C3CC AFA80030 */  sw    $t0, 0x30($sp)
/* 09CFD0 8009C3D0 AFA20034 */  sw    $v0, 0x34($sp)
/* 09CFD4 8009C3D4 031EC821 */  addu  $t9, $t8, $fp
/* 09CFD8 8009C3D8 AFB9002C */  sw    $t9, 0x2c($sp)
/* 09CFDC 8009C3DC 0C0258FC */  jal   func_800963F0
/* 09CFE0 8009C3E0 AFA30038 */   sw    $v1, 0x38($sp)
/* 09CFE4 8009C3E4 00408025 */  move  $s0, $v0
.L8009C3E8:
/* 09CFE8 8009C3E8 8E290018 */  lw    $t1, 0x18($s1)
.L8009C3EC:
/* 09CFEC 8009C3EC 26310014 */  addiu $s1, $s1, 0x14
/* 09CFF0 8009C3F0 5520FFA3 */  bnel  $t1, $zero, .L8009C280
/* 09CFF4 8009C3F4 86220000 */   lh    $v0, ($s1)
.L8009C3F8:
/* 09CFF8 8009C3F8 8FBF007C */  lw    $ra, 0x7c($sp)
/* 09CFFC 8009C3FC 02001025 */  move  $v0, $s0
/* 09D000 8009C400 8FB00058 */  lw    $s0, 0x58($sp)
/* 09D004 8009C404 D7B40048 */  ldc1  $f20, 0x48($sp)
/* 09D008 8009C408 D7B60050 */  ldc1  $f22, 0x50($sp)
/* 09D00C 8009C40C 8FB1005C */  lw    $s1, 0x5c($sp)
/* 09D010 8009C410 8FB20060 */  lw    $s2, 0x60($sp)
/* 09D014 8009C414 8FB30064 */  lw    $s3, 0x64($sp)
/* 09D018 8009C418 8FB40068 */  lw    $s4, 0x68($sp)
/* 09D01C 8009C41C 8FB5006C */  lw    $s5, 0x6c($sp)
/* 09D020 8009C420 8FB60070 */  lw    $s6, 0x70($sp)
/* 09D024 8009C424 8FB70074 */  lw    $s7, 0x74($sp)
/* 09D028 8009C428 8FBE0078 */  lw    $fp, 0x78($sp)
/* 09D02C 8009C42C 03E00008 */  jr    $ra
/* 09D030 8009C430 27BD0080 */   addiu $sp, $sp, 0x80
