#include <ultra64.h>
#include <macros.h>
#include <types.h>
#include <common_structs.h>
#include "main.h"
#include "variables.h"
#include "common_textures.h"
#include "code_8001F980.h"
#include "code_800431B0.h"
#include "code_80280650.h"

void func_80280650(void) {

}

void func_80280658(struct UnkStruct_80280658 *arg0) {
    struct UnkStruct_80280658_2 *temp_v0 = arg0->unk28;

    arg0->unk10 = temp_v0->unk2;
    arg0->unk14 = temp_v0->unk4;
    arg0->unk18 = temp_v0->unk6;
    arg0->unkA = temp_v0->unk8 << 8;
    arg0->unkC = temp_v0->unk9 << 8;
    arg0->unkE = temp_v0->unkA << 8;
    arg0->unk4 = temp_v0->unk0;
}

struct UnkStruct_80280658 *func_802806C8(void) {
    //struct UnkStruct_80280658 *sp1C;
    //s32 temp_v0;
    s32 pad[2];
    struct UnkStruct_80280658 *phi_a0 = D_802874F8;
    s32 i;

    for (i = 0; i < 0xC8 ; i++) {

        if ((phi_a0->unk0 & 1) == 0) {
            bzero(phi_a0, 0x4C);
            phi_a0->unk0 = 1;
            phi_a0->unk24 = 1.0f;
            return phi_a0;
        }

        phi_a0++;
    }
    return NULL;
}

struct UnkStruct_80280658 *func_80280734(struct UnkStruct_80280658 *arg0) {
    struct UnkStruct_80280658 *temp_v0 = func_802806C8();

    temp_v0->unk28 = arg0;
    func_80280658(temp_v0);
    return temp_v0;
}

#ifdef MIPS_TO_C
//generated by m2c commit 3b40ab93768f52ac241c5ae84ef58ef6bc4cb1de
static u16 D_80284E60 = 0;

u16 func_8028076C(void) {
    s32 temp_a1;
    s32 temp_t5;
    s32 temp_t8;
    s32 temp_v0;
    u16 temp_t4;
    u16 var_v0;

    var_v0 = D_80284E60;
    if (var_v0 == 0x560A) {
        D_80284E60 = 0;
        var_v0 = 0 & 0xFFFF;
    }
    temp_t8 = (var_v0 << 8) ^ var_v0;
    temp_a1 = temp_t8 & 0xFF;
    temp_t4 = (temp_a1 << 8) + ((s32) (temp_t8 & 0xFF00) >> 8);
    temp_t5 = ((temp_a1 * 2) ^ temp_t4) & 0xFFFF;
    D_80284E60 = temp_t4;
    if (!(temp_t5 & 1)) {
        temp_v0 = ((temp_t5 >> 1) ^ 0xFF80) & 0xFFFF;
        if (temp_v0 == 0xAA55) {
            D_80284E60 = 0;
        } else {
            D_80284E60 = temp_v0 ^ 0x1FF4;
        }
    } else {
        D_80284E60 = (temp_t5 >> 1) ^ 0xFF80 ^ 0x8180;
    }
    return D_80284E60;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028076C.s")
#endif

f32 func_8028080C(void) {
    return func_8028076C() / 65536.0f;
}

f32 func_80280850(f32 arg0) {
    return (func_8028080C() * arg0) - (arg0 * 0.5f);
}

void func_80280884(void) {

}

#ifdef NON_MATCHING
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_8006BB34(struct UnkStruct_8028088C*, s32, s16, s16); // extern
f32 sins(u16);
extern f32 D_80286B70;
extern s16 D_802874CA;

void func_8028088C(struct UnkStruct_8028088C *arg0) {
    f32 temp_f0;
    s32 temp_at;
    s32 temp_t3;

    func_8006BB34(arg0+1, 0x3F800000, arg0->unk2E, arg0->unk2C);
    arg0->unk14 += D_80286B70;
    temp_f0 = sins(arg0->unk30);
    temp_t3 = arg0->unk3C + 1;
    temp_at = temp_t3 < 0x321;
    arg0->unk30 += arg0->unk32;
    arg0->unk3C = temp_t3;
    arg0->unk2E = temp_f0 * arg0->unk34;
    if (temp_at == 0) {
        arg0->unk0 = 0;
    }
    if (D_802874CA == 1) {
        arg0->unk0 = 0;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028088C.s")
#endif

s32 D_80284E40[] = {
    0x00FF4080, 0x008040FF, 0x0040FF40, 0x00FFFF40
};

void func_8028093C(struct UnkStruct_80280658 *arg0) {
    struct UnkStruct_80280658 *temp_v0;

    if (arg0->unk44 < 0x1E) {
        arg0->unk14 += 2.5f;
        arg0->unk10 += func_80280850(0.2f);
        arg0->unk18 += func_80280850(0.2f);
    } else if (arg0->unk2C == 4) {
        temp_v0 = func_80280734(&D_80284E7C);
        temp_v0->unk10 = arg0->unk10;
        temp_v0->unk14 = arg0->unk14;
        temp_v0->unk18 = arg0->unk18;
        temp_v0->unk30 = D_80284E40[arg0->unk48];
        temp_v0->unk3C = 0xFF;
        temp_v0->unk40 = -0x11;
        temp_v0->unk44 = 0x64;
        temp_v0->unk34 = 1.8700001f;
        temp_v0->unk38 = 1.8700001f;
    }
}

void func_80280A28(Vec3f arg0, Vec3s arg1, f32 arg2) {
    Mat4 sp20;

    func_80021E10(sp20, arg0, arg1);
    sp20[0][0] = D_80287500[0][0] * arg2;
    sp20[0][1] = D_80287500[1][0] * arg2;
    sp20[0][2] = D_80287500[2][0] * arg2;
    sp20[1][0] = D_80287500[0][1] * arg2;
    sp20[1][1] = D_80287500[1][1] * arg2;
    sp20[1][2] = D_80287500[2][1] * arg2;
    sp20[2][0] = D_80287500[0][2] * arg2;
    sp20[2][1] = D_80287500[1][2] * arg2;
    sp20[2][2] = D_80287500[2][2] * arg2;
    func_80022180(&gGfxPool->mtxPool[D_80164AF0 + 0x3EB], sp20);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gGfxPool->mtxPool[D_80164AF0 + 0x3EB]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
}

#ifdef NON_MATCHING
extern u32 D_8018D48C;

void func_80280B50(Vec3f arg0, f32 arg1, s32 rgb, s16 alpha) {
    Vec3f sp4C;
    Vec3s sp44;
    s16 red;
    s16 green;
    s16 blue;

    sp4C[0] = arg0[0];
    sp4C[1] = arg0[1];
    sp4C[2] = arg0[2];
    sp44[0] = 0;
    sp44[1] = camera1->rot[1];
    sp44[2] = 0;
    func_80280A28(sp4C, sp44, arg1);
    gSPDisplayList(gDisplayListHead++, D_0D008DB8);
    gDPLoadTextureBlock(gDisplayListHead++, D_8018D48C, G_IM_FMT_IA, G_IM_SIZ_8b, 32, 32, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    // The exact order of operations for red/green/blue is slightly wrong...
    red   = (rgb >> 0x10) & 0xFF;
    green = (rgb >> 0x08) & 0xFF;
    blue  = (rgb >> 0x00) & 0xFF;
    func_8004B35C(red, green, blue, alpha);
    gSPDisplayList(gDisplayListHead++, D_0D008E48);
    D_80164AF0 += 1;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280B50.s")
#endif

#ifdef MIPS_TO_C
//generated by m2c commit d9d3d6575355663122de59f6b2882d8f174e2355 on Dec-10-2022
static s32 D_80284E50[4] = { 0x007F2040, 0x0040207F, 0x00207F20, 0x007F7F20 };

void func_80280D1C(void *arg0) {
    f32 sp60;
    f32 sp5C;
    f32 sp58;
    f32 temp_f0;
    s32 temp_v0;
    s32 var_s0;
    s32 var_s1;
    s32 var_v1;

    var_s0 = 0;
    var_s1 = 0;
    if (arg0->unk44 < 0x1E) {
        do {
            sp58 = arg0->unk10;
            sp5C = arg0->unk14 - (f32) var_s1;
            sp60 = arg0->unk18;
            func_80280B50(&sp58, ((f32) (0xA - var_s0) / 10.0f) * 2.0f, D_80284E50[arg0->unk48], (s16) (s32) ((f32) ((0x1E - arg0->unk44) * 0x64) / 30.0f));
            var_s0 += 1;
            var_s1 += 2;
        } while (var_s0 != 0xA);
    } else {
        temp_v0 = arg0->unk2C;
        if (temp_v0 < 5) {
            var_v1 = arg0->unk3C + (arg0->unk40 * 2);
            arg0->unk3C = var_v1;
            arg0->unk34 = (f32) (arg0->unk34 + (arg0->unk38 * 2.0f));
        } else {
            temp_f0 = 1.0f + ((f32) ((temp_v0 * 7) - 0x23) / 10.0f);
            var_v1 = (s32) ((f32) arg0->unk3C + ((f32) arg0->unk40 / temp_f0));
            arg0->unk3C = var_v1;
            arg0->unk34 = (f32) (arg0->unk34 + (arg0->unk38 / temp_f0));
            if (var_v1 < 0) {
                arg0->unk3C = 0;
                var_v1 = 0;
            }
        }
        arg0->unk2C = (s32) (arg0->unk2C + 1);
        if ((var_v1 <= 0) || !(arg0->unk34 > 0.0f)) {
            if (arg0->unk2C < 0x1E) {
                goto block_12;
            }
            arg0->unk0 = 0;
        } else {
block_12:
            func_80280B50(arg0 + 0x10, arg0->unk34, arg0->unk30, (s16) var_v1);
        }
    }
    arg0->unk44 = (s32) (arg0->unk44 + 1);
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80280D1C.s")
#endif

void func_80280FA0(s32 arg0) {

}

void func_80280FA8(s32 arg0) {

}

void func_80280FB0(void) {
    D_802874E0 = 0;

    D_802874F8 = func_802A7B70(0x3B60);
    bzero(D_802874F8, 0x3B60);
    func_80280734(&D_80284E88);
}

void func_80280FFC(void) {
    D_802874F4 = 1;
}

void func_8028100C(s32 arg0, s32 arg1, s32 arg2) {

}

#ifdef MIPS_TO_C
//generated by m2c commit 8267401fa4ef7a38942dcca43353cc1bcc6efabc
static struct UnkStruct_80280658 D_80284E64;        /* type too large by 0x40; unable to generate initializer */
static f32 D_80286B80 = 3000.0f;

void func_8028101C(s32 arg0, s32 arg1, s32 arg2) {
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    s32 var_s1;
    struct UnkStruct_80280658 *temp_s0;

    var_s1 = 0;
    sp5C = (f32) arg2;
    sp60 = (f32) arg1;
    sp64 = (f32) arg0;
    do {
        temp_s0 = func_80280734(&D_80284E64);
        temp_s0->unk10 = func_80280850(200.0f) + sp64;
        temp_s0->unk14 = func_80280850(380.0f) + sp60;
        temp_s0->unk18 = func_80280850(600.0f) + sp5C;
        temp_s0->unk2C = (s16) (s32) (func_8028080C() * 7.0f);
        temp_s0->unk30 = func_8028076C();
        temp_s0->unk32 = (s16) (s32) (func_80280850(400.0f) + 900.0f);
        var_s1 += 1;
        temp_s0->unk34 = (s16) (s32) (func_80280850(2000.0f) + D_80286B80);
    } while (var_s1 != 0x64);
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028101C.s")
#endif

#ifdef MIPS_TO_C
//generated by m2c commit 8267401fa4ef7a38942dcca43353cc1bcc6efabc
extern s16 D_802874BE;
extern s16 D_802874C6;
extern s16 D_802874C8;
extern s32 D_80287540;
static s32 D_80284E50[4] = { 0x007F2040, 0x0040207F, 0x00207F20, 0x007F7F20 };
static struct UnkStruct_80280658 D_80284E70;        /* type too large by 0x40; unable to generate initializer */
static f32 D_80286B84 = 1.1f;

void func_8028118C(s32 arg0, s32 arg1, s32 arg2) {
    f32 temp_f0;
    f32 temp_f2;
    s32 temp_v0;
    s32 temp_v1;
    struct UnkStruct_80280658 *temp_s0;

    if (((f32) (D_802874BE + 0xD) * func_8028080C()) < 1.0f) {
        temp_s0 = func_80280734(&D_80284E70);
        temp_s0->unk10 = func_80280850(0.0f) + (f32) arg0;
        temp_s0->unk14 = func_80280850((f32) (D_802874C6 + 0x64)) + (f32) arg1;
        temp_f0 = func_80280850((f32) (D_802874C8 + 0x2BC));
        temp_v1 = D_80287540;
        temp_f2 = D_80286B84;
        temp_v0 = temp_v1 & 3;
        temp_s0->unk48 = temp_v0;
        temp_s0->unk18 = temp_f0 + (f32) arg2;
        temp_s0->unk3C = 0x000000FF;
        temp_s0->unk40 = -0x00000011;
        temp_s0->unk34 = temp_f2;
        temp_s0->unk38 = temp_f2;
        temp_s0->unk30 = D_80284E50[temp_v0];
        D_80287540 = temp_v1 + 1;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_8028118C.s")
#endif

#ifdef MIPS_TO_C
//generated by m2c commit 3b40ab93768f52ac241c5ae84ef58ef6bc4cb1de
void func_8028101C(?, s32, ?);                         /* extern */
void func_8028118C(?, s32, ?);                         /* extern */
void guLookAtF(? *, f32, f32, f32, f32, f32, f32, f32, f32, f32); /* extern */
extern s16 D_802874C4;
extern s32 D_802874E0;
extern Mat4 D_80287500;

void func_802812C8(void) {
    f32 temp_f0;
    s32 var_v0;

    guLookAtF(&D_80287500, cameras->pos[0], cameras->pos[1], cameras->pos[2], cameras->lookAt[0], cameras->lookAt[1], cameras->lookAt[2], cameras->up[0], cameras->up[1], cameras->up[2]);
    if (D_802874F5 < 3) {
        var_v0 = D_802874E0;
        if (var_v0 < 0x12C) {
            temp_f0 = cameras->lookAt[1];
            func_8028118C(-0xE0E, (s32) (((temp_f0 - cameras->pos[1]) * 1.5f) + temp_f0), -0x258);
            var_v0 = D_802874E0;
        }
        if (var_v0 == 0x00000078) {
            func_8028101C(-0xC6C, (s32) ((f32) D_802874C4 + 210.0f), -0x1EF);
            goto block_7;
        }
    } else {
        var_v0 = D_802874E0;
        if (var_v0 == 2) {
            func_8028101C(-0xC6C, (s32) ((f32) D_802874C4 + 210.0f), -0x1EF);
block_7:
            var_v0 = D_802874E0;
        }
    }
    D_802874E0 = var_v0 + 1;
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_802812C8.s")
#endif

#ifdef MIPS_TO_C
//generated by mips_to_c commit 3c3b0cede1a99430bfd3edf8d385802b94f91307
void func_802812C8(); // extern
extern ? D_80284E94;
extern s16 D_802874D0;
extern void *D_802874F8;

void func_80281438(void) {
    ? (*temp_v0)(void *);
    s32 temp_s1;
    s32 temp_s2;
    void *phi_s0;
    s32 phi_s2;
    s32 phi_s1;

    func_802812C8();
    D_802874D0 = 0;
    phi_s2 = 0;
    do {
        phi_s0 = D_802874F8;
        phi_s1 = 0;
loop_2:
        if ((phi_s0->unk0 & 1) != 0) {
            temp_v0 = *(&D_80284E94 + (phi_s0->unk4 * 0xC) + (phi_s2 * 4));
            if (temp_v0 != 0) {
                temp_v0(phi_s0);
            }
        }
        temp_s1 = phi_s1 + 1;
        phi_s0 += 0x4C;
        phi_s1 = temp_s1;
        if (temp_s1 != 0xC8) {
            goto loop_2;
        }
        temp_s2 = phi_s2 + 1;
        phi_s2 = temp_s2;
    } while (temp_s2 != 3);
}
#else
GLOBAL_ASM("asm/non_matchings/code_80280650/func_80281438.s")
#endif

void func_8028150C(void) {
    D_802874D4 = gDisplayListHead;
}

void func_80281520(void) {

}

void func_80281528(void) {

}

void func_80281530(void) {

}

void func_80281538(void) {

}

void func_80281540(void) {

}

void ending_sequence_loop(void) {
    D_80150112 = 0;
    D_802874FC = 0;
    setup_camera_ending_sequence();
    func_80028F70();
    func_80022744();
    func_80059AC8();
    func_80059AC8();
    func_8005A070();
    if (D_802874F4 != 0) {
        func_8001C14C();
        func_800097E0();
    }
    func_80281D00();
    func_80281540();
    gDPFullSync(gDisplayListHead++);
    gSPEndDisplayList(gDisplayListHead++);
}
