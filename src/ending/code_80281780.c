#include <ultra64.h>
#include <macros.h>
#include <defines.h>
#include <config.h>

#include "code_80281780.h"
#include "types.h"
#include "memory.h"
#include "camera.h"
#include "camera_junk.h"
#include "spawn_players.h"
#include "skybox_and_splitscreen.h"
#include "code_8006E9C0.h"
#include "podium_ceremony_actors.h"
#include "code_80005FD0.h"
#include "collision.h"
#include "code_80281C40.h"
#include "code_800029B0.h"
#include "code_80091750.h"
#include "main.h"
#include "menus.h"
#include "render_courses.h"

u8 defaultCharacterIds[] = {
    1, 2, 3, 4, 5, 6, 7, 0
};

void debug_switch_character_ceremony_cutscene(void) {
    if (gEnableDebugMode) {
        if (gControllerOne->button & HOLD_ALL_DPAD_AND_C_BUTTONS) {
            // Allows to switch character in debug mode?
            if (gControllerOne->button & U_CBUTTONS) {
                gCharacterSelections[0] = LUIGI;
            }
            else if (gControllerOne->button & L_CBUTTONS) {
                gCharacterSelections[0] = YOSHI;
            }
            else if (gControllerOne->button & R_CBUTTONS) {
                gCharacterSelections[0] = TOAD;
            }
            else if (gControllerOne->button & D_CBUTTONS) {
                gCharacterSelections[0] = DK;
            }
            else if (gControllerOne->button & U_JPAD) {
                gCharacterSelections[0] = WARIO;
            }
            else if (gControllerOne->button & L_JPAD) {
                gCharacterSelections[0] = PEACH;
            }
            else if (gControllerOne->button & R_JPAD) {
                gCharacterSelections[0] = BOWSER;
            } else {
                gCharacterSelections[0] = MARIO;
            }
            //! @todo confirm this.
            // Resets gCharacterIdByGPOverallRank to default?
            bcopy(&defaultCharacterIds, &gCharacterIdByGPOverallRank, 8);
        }
    }
}

s32 func_80281880(s32 arg0) {
    s32 i;
    for (i = 0; i < NUM_PLAYERS; i++) {
        if (gCharacterIdByGPOverallRank[i] == gCharacterSelections[arg0]) break;
    }
    return i;
}

void func_802818BC(void) {
    s32 temp_v0;
    UNUSED s32 pad;
    s32 sp1C;
    s32 temp_v0_2;

    if (gPlayerCount != TWO_PLAYERS_SELECTED) {
        D_802874D8.unk1D = func_80281880(0);
        D_802874D8.unk1E = gCharacterSelections[0];
        return;
    }
    // weird pattern but if it matches it matches
    temp_v0 = sp1C = func_80281880(0);
    temp_v0_2 = func_80281880(1);
    if (sp1C < temp_v0_2) {
        D_802874D8.unk1E = gCharacterSelections[0];
        D_802874D8.unk1D = temp_v0;
    } else {
        D_802874D8.unk1E = gCharacterSelections[1];
        D_802874D8.unk1D = temp_v0_2;
    }
}

void load_ceremony_cutscene(void) {
    Camera *camera = &cameras[0];

    gCurrentCourseId = COURSE_ROYAL_RACEWAY;
    D_800DC5B4 = (u16)1;
    gIsMirrorMode = 0;
    gMenuSelectionFromEndingSequence = 0xFFFF;
    D_80287554 = 0;
    func_802A4D18();
    func_802A74BC();
    camera->unk_B4 = 60.0f;
    gCameraZoom[0] = 60.0f;
    D_800DC5EC->screenWidth = SCREEN_WIDTH;
    D_800DC5EC->screenHeight = SCREEN_HEIGHT;
    D_800DC5EC->screenStartX = 160;
    D_800DC5EC->screenStartY = 120;
    gScreenModeSelection = SCREEN_MODE_1P;
    gNextFreeMemoryAddress = (s32) gFreeMemoryResetAnchor;
    gActiveScreenMode = SCREEN_MODE_1P;
    gModeSelection = GRAND_PRIX;
    load_course(gCurrentCourseId);
    D_8015F730 = (s32) gNextFreeMemoryAddress;
    set_segment_base_addr(0xB, (void *) decompress_segments((u8 *) &_data_821D10SegmentRomStart, (u8 *) &_data_825800SegmentRomStart));
    set_segment_base_addr(6, (void *) decompress_segments((u8 *) &_course_banshee_boardwalk_dl_mio0SegmentRomStart, (u8 *) &_course_yoshi_valley_dl_mio0SegmentRomStart));
    D_8015F8E4 = -2000.0f;

    D_8015F6EA = -0x15A1;
    D_8015F6EE = -0x15A1;
    D_8015F6F2 = -0x15A1;

    D_8015F6E8 = 0x15A1;
    D_8015F6EC = 0x15A1;
    D_8015F6F0 = 0x15A1;

    D_8015F59C = 0;
    D_8015F5A0 = 0;
    D_8015F58C = 0;
    D_8015F588 = (u16)0;
    D_800DC5BC = (u16)0;
    D_800DC5C8 = (u16)0;
    gSurfaceMap = (mk64_surface_map_ram *) gNextFreeMemoryAddress;
    //! @bug these segmented addresses need to be symbols for mobility
    // d_course_royal_raceway_packed_dl_67E8
    set_vertex_data_with_default_section_id(0x070067E8, -1);
    // d_course_royal_raceway_packed_dl_AEF8
    set_vertex_data_with_default_section_id(0x0700AEF8, -1);
    // d_course_royal_raceway_packed_dl_A970
    set_vertex_data_with_default_section_id(0x0700A970, 8);
    // d_course_royal_raceway_packed_dl_AC30
    set_vertex_data_with_default_section_id(0x0700AC30, 8);
    // d_course_royal_raceway_packed_dl_CE0
    set_vertex_data_with_default_section_id(0x07000CE0, 0x10);
    // d_course_royal_raceway_packed_dl_E88
    set_vertex_data_with_default_section_id(0x07000E88, 0x10);
    // d_course_royal_raceway_packed_dl_A618
    set_vertex_data_with_default_section_id(0x0700A618, -1);
    // d_course_royal_raceway_packed_dl_A618
    set_vertex_data_with_default_section_id(0x0700A618, -1);
    // d_course_royal_raceway_packed_dl_23F8
    set_vertex_data_with_default_section_id(0x070023F8, 1);
    // d_course_royal_raceway_packed_dl_2478
    set_vertex_data_with_default_section_id(0x07002478, 1);
    func_80295C6C();
    debug_switch_character_ceremony_cutscene();
    func_802818BC();
    func_8003D080();
    init_object_list();
    func_8001C05C();
    balloons_and_fireworks_init();
    func_802816B8();
    func_80093E60();
    D_801625F8 = (s32) gHeapEndPtr - gNextFreeMemoryAddress;
    D_801625FC = ((f32) D_801625F8 / 1000.0f);
}
