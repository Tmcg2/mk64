/**
 * @file hud_renderer.c renders hud elements
 * A more suitable name may be print.c
**/

#include <ultra64.h>
#include <PR/gbi.h>
#include <macros.h>
#include <defines.h>
#include <common_structs.h>
#include <actor_types.h>
#include <config.h>
#include "memory.h"
#include "math_util.h"
#include "math_util_2.h"
#include "objects.h"
#include "waypoints.h"
#include "bomb_kart.h"
#include "common_textures.h"
#include "render_player.h"
#include "code_80004740.h"
#include "code_80005FD0.h"
#include "code_80057C60.h"
#include "code_8006E9C0.h"
#include "hud_renderer.h"
#include "code_80071F00.h"
#include "code_80091750.h"
#include "collision.h"
#include "main.h"
#include "menus.h"
#include "code_80086E70.h"
#include "code_800029B0.h"
#include "src/data/data_800E45C0.h"
#include "courses/all_course_data.h"
#include <vehicles.h>

void func_800431B0(Vec3f pos, Vec3su orientation, f32 scale, Vtx *vtx) {
    rsp_set_matrix_transformation(pos, orientation, scale);
    gSPVertex(gDisplayListHead++, vtx, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
}

void func_80043220(Vec3f pos, Vec3su orientation, f32 scale, Gfx *gfx) {
    rsp_set_matrix_transformation(pos, orientation, scale);
    gSPDisplayList(gDisplayListHead++, &D_0D0077A0);
    gSPDisplayList(gDisplayListHead++, gfx);
}

UNUSED void func_80043288(Vec3f pos, Vec3su orientation, f32 arg2, Gfx *gfx) {
    rsp_set_matrix_transformation(pos, orientation, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0077A0);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    gSPDisplayList(gDisplayListHead++, gfx);
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void func_80043328(Vec3f arg0, Vec3su arg1, f32 arg2, Gfx *gfx) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0077D0);
    gSPDisplayList(gDisplayListHead++, gfx);
}

UNUSED void func_80043390(Vec3f arg0, Vec3su arg1, f32 arg2, Gfx *gfx) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0077F8);
    gSPDisplayList(gDisplayListHead++, gfx);
}

UNUSED void func_800433F8(Vec3f arg0, Vec3su arg1, f32 arg2, Gfx *gfx) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007828);
    gSPDisplayList(gDisplayListHead++, gfx);
}

UNUSED void func_80043460(Vec3f arg0, Vec3su arg1, f32 arg2, Gfx *gfx) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007828);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    gSPDisplayList(gDisplayListHead++, gfx);
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void func_80043500(Vec3f arg0, Vec3su arg1, f32 arg2, Gfx *gfx) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007850);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    gSPDisplayList(gDisplayListHead++, gfx);
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void func_800435A0(Vec3f arg0, Vec3su arg1, f32 arg2, Gfx *gfx, s32 arg4) {
    rsp_set_matrix_transformation_inverted_x_y_orientation(arg0, arg1, arg2);

    gSPDisplayList(gDisplayListHead++, D_0D007878);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 0xFF, 0xFF, 0xFF, arg4);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    gSPDisplayList(gDisplayListHead++, gfx);
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

UNUSED void func_80043668(Vec3f arg0, Vec3su arg1, f32 arg2, Gfx *gfx) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0078A0);
    gSPDisplayList(gDisplayListHead++, gfx);
}

UNUSED void func_800436D0(s32 arg0, s32 arg1, u16 arg2, f32 arg3, Vtx *vtx) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D0078A0);
    gSPVertex(gDisplayListHead++, vtx, 3, 0);
    gSPDisplayList(gDisplayListHead++, D_0D006930);

}

UNUSED void func_80043764(s32 arg0, s32 arg1, u16 arg2, f32 arg3, Vtx *vtx) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D0078A0);
    gSPVertex(gDisplayListHead++, vtx, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
}

UNUSED void func_800437F8(s32 arg0, s32 arg1, u16 arg2, f32 arg3, Vtx *vtx, s32 arg5) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D0078A0);

    gDPSetRenderMode(gDisplayListHead++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    vtx[0].v.cn[3] = arg5;
    vtx[1].v.cn[3] = arg5;
    vtx[2].v.cn[3] = arg5;
    vtx[3].v.cn[3] = arg5;
    gSPVertex(gDisplayListHead++, vtx, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
}

UNUSED void func_800438C4(s32 arg0, s32 arg1, u16 arg2, f32 arg3, Vtx *vtx, s32 arg5) {
    vtx[1].v.ob[0] = arg5;
    vtx[2].v.ob[0] = arg5;
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D0078A0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gSPVertex(gDisplayListHead++, vtx, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
}

UNUSED void func_8004398C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, Vtx *vtx, s32 arg5) {
    vtx[0].v.ob[0] = arg5;
    vtx[3].v.ob[0] = arg5;
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D0078A0);
    gDPSetRenderMode(gDisplayListHead++, G_RM_CLD_SURF, G_RM_CLD_SURF2);
    gSPVertex(gDisplayListHead++, vtx, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
}
    
s32 func_80043A54(s32 arg0) {
    s32 temp_a1;
    s32 phi_v0;
    s32 phi_v1 = 0;

    phi_v0 = arg0;
    do {
        phi_v1++;
        temp_a1 = phi_v0 / 2;
        phi_v0 = temp_a1;
    } while (temp_a1 != 1);
    return phi_v1;
}

void func_80043A84(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, height, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_80043C28(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureTile(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_32b, width, height,
        0, 0, width - 1, height - 1, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_80043D50(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0,
        G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_80043EF8(u8 *texture, s32 width, s32 height, s32 someMask) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0,
        G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, someMask, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_800440B8(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureTile(gDisplayListHead++, texture, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height,
        0, 0, width - 1, height - 1, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_800441E0(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_IA, G_IM_SIZ_16b, width, height, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_80044388(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureTile(gDisplayListHead++, texture, G_IM_FMT_IA, G_IM_SIZ_16b, width, height,
        0, 0, width - 1, height - 1, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_800444B0(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_IA, G_IM_SIZ_8b, width, height, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_80044658(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureTile(gDisplayListHead++, texture, G_IM_FMT_IA, G_IM_SIZ_8b, width, height,
        0, 0, width - 1, height - 1, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_8004477C(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_80044924(u8 *texture, s32 width, s32 height) {
    // This macro ought to be equivalent to the block of macros below but it doesn't match
    // See comment above the `gDPLoadBlock` macro
    // gDPLoadTextureBlock_4b(gDisplayListHead++, texture, G_IM_FMT_I, width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 1, texture);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_16b, 0, G_TX_RENDERTILE, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gDisplayListHead++);
    // The last argument to this macro really should be `CALC_DXT_4b(width)` but that creates a massive diff
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, (((width * height) + 3) >> 2) - 1, ((width / 16) + 2047) / (width / 16));
    gDPPipeSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_IA, G_IM_SIZ_4b, (((width >> 1) + 7) >> 3), G_TX_RENDERTILE, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (width-1) << G_TEXTURE_IMAGE_FRAC, (height-1) << G_TEXTURE_IMAGE_FRAC);
}

UNUSED void func_80044AB8(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureTile_4b(gDisplayListHead++, texture, G_IM_FMT_IA, width, height,
        0, 0, width - 1, height - 1, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_80044BF8(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void func_80044DA0(u8 *image, s32 width, s32 height) {
    // This macro ought to be equivalent to the block of macros below but it doesn't match
    // See comment above the `gDPLoadBlock` macro
    // gDPLoadTextureBlock_4b(gDisplayListHead++, image, G_IM_FMT_I, width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_16b, 1, image);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_16b, 0, G_TX_RENDERTILE, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gDisplayListHead++);
    // The last argument to this macro really should be `CALC_DXT_4b(width)` but that creates a massive diff
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, (((width * height) + 3) >> 2) - 1, ((width / 16) + 2047) / (width / 16));
    gDPPipeSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_4b, (((width >> 1) + 7) >> 3), G_TX_RENDERTILE, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (width-1) << G_TEXTURE_IMAGE_FRAC, (height-1) << G_TEXTURE_IMAGE_FRAC);
}

// Appears to be a complete copy of `func_80044F34`?
void func_80044F34(u8 *image, s32 width, s32 height) {
    // This macro ought to be equivalent to the block of macros below but it doesn't match
    // See comment above the `gDPLoadBlock` macro
    // gDPLoadTextureBlock_4b(gDisplayListHead++, image, G_IM_FMT_I, width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    
    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_16b, 1, image);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_16b, 0, G_TX_RENDERTILE, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPLoadSync(gDisplayListHead++);
    // The last argument to this macro really should be `CALC_DXT_4b(width)` but that creates a massive diff
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, (((width * height) + 3) >> 2) - 1, ((width / 16) + 2047) / (width / 16));
    gDPPipeSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_4b, (((width >> 1) + 7) >> 3), G_TX_RENDERTILE, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (width-1) << G_TEXTURE_IMAGE_FRAC, (height-1) << G_TEXTURE_IMAGE_FRAC);
}

void func_800450C8(u8 *image, s32 width, s32 height) {
    // This macro ought to be equivalent to the block of macros below but it doesn't match
    // See comment above the `gDPLoadBlock` macro
    // gDPLoadTextureBlock_4b(gDisplayListHead++, image, G_IM_FMT_I, width, height, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_WRAP, G_TX_NOMASK, masks, G_TX_NOLOD, G_TX_NOLOD);
    s32 masks = func_80043A54(width);

    gDPSetTextureImage(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_16b, 1, image);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_16b, 0, G_TX_RENDERTILE, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, masks, G_TX_NOLOD);
    gDPLoadSync(gDisplayListHead++);
    // The last argument to this macro really should be `CALC_DXT_4b(width)` but that creates a massive diff
    gDPLoadBlock(gDisplayListHead++, G_TX_LOADTILE, 0, 0, (((width * height) + 3) >> 2) - 1, ((width / 16) + 2047) / (width / 16));
    gDPPipeSync(gDisplayListHead++);
    gDPSetTile(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_4b, (((width >> 1) + 7) >> 3), G_TX_RENDERTILE, G_TX_RENDERTILE, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOLOD, G_TX_MIRROR | G_TX_WRAP, masks, G_TX_NOLOD);
    gDPSetTileSize(gDisplayListHead++, G_TX_RENDERTILE, 0, 0, (width-1) << G_TEXTURE_IMAGE_FRAC, (height-1) << G_TEXTURE_IMAGE_FRAC);
}

void rsp_load_texture(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_CI, G_IM_SIZ_8b, width, height, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

void rsp_load_texture_mask(u8 *texture, s32 width, s32 height, s32 someMask) {
    gDPLoadTextureBlock(gDisplayListHead++, texture, G_IM_FMT_CI, G_IM_SIZ_8b, width, height, 0,
        G_TX_MIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_CLAMP, someMask, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

UNUSED void func_80045614(u8 *texture, s32 width, s32 height) {
    gDPLoadTextureTile(gDisplayListHead++, texture, G_IM_FMT_CI, G_IM_SIZ_8b, width, height,
        0, 0, width - 1, height - 1, 0,
        G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
}

UNUSED void func_80045738(u8 *image1, u8 *image2, s32 width, s32 height) {
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, TEXEL0, 0, 0, 0, TEXEL1, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);

    gDPLoadMultiBlock(gDisplayListHead++, image2, 0x100, G_TX_RENDERTILE, G_IM_FMT_I, G_IM_SIZ_8b, width, height, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadTextureBlock(gDisplayListHead++, image1, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, G_TX_MIRROR | G_TX_CLAMP, G_TX_MIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);

    gDPSetTile(gDisplayListHead++, G_IM_FMT_I, G_IM_SIZ_8b, (width + 7) >> 3, 0x0100, 1, 0, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);;
    gDPSetTileSize(gDisplayListHead++, 1, 0, 0, (width-1) << G_TEXTURE_IMAGE_FRAC, (height-1) << G_TEXTURE_IMAGE_FRAC);
}

void func_80045B2C(Vtx *arg0) {
    gSPVertex(gDisplayListHead++, arg0, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
}

void func_80045B74(Vtx *arg0) {
    gSPVertex(gDisplayListHead++, arg0, 3, 0);
    gSPDisplayList(gDisplayListHead++, D_0D006930);
}

UNUSED void func_80045BBC(Vec3f arg0, Vec3su arg1, f32 arg2, Vtx *arg3) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0078A0);
    gSPVertex(gDisplayListHead++, arg3, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
}

UNUSED void func_80045C48(Vec3f arg0, Vec3su arg1, f32 arg2, Vtx *arg3) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0078D0);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    gSPVertex(gDisplayListHead++, arg3, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void func_80045D0C(u8 *texture, Vtx *arg1, s32 width, s32 arg3, s32 height) {
    s32 heightIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        func_80043D50(img, width, height);
        func_80045B2C(&arg1[vertexIndex]);
            img += width * height * 2;
            vertexIndex += 4;
        }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80045E10(u8 *texture, Vtx *arg1, s32 width, s32 arg3, s32 height) {
    s32 heightIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        func_80043D50(img, width, height);
        func_80045B2C(&arg1[vertexIndex]);
            img += width * (height - 1) * 2;
            vertexIndex += 4;
        }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80045F18(u8 *texture, Vtx *arg1, s32 width, s32 arg3, s32 height, s32 someMask) {
    s32 heightIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        func_80043EF8(img, width, height, someMask);
        func_80045B2C(&arg1[vertexIndex]);
            img += width * (height - 1) * 2;
            vertexIndex += 4;
        }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

//! @todo tlut/texture unconfirmed. This could be texture1 and texture2
UNUSED void func_80046030(u8 *tlut, u8 *texture, Vtx *arg2, s32 width, s32 arg4, s32 height) {
    s32 var_s0 = 0;
    u8 *img1 = tlut;
    u8 *img2 = texture;
    s32 temp_lo_2;
    s32 var;
    s32 i;


    gSPDisplayList(gDisplayListHead++, D_0D008138);

    for (i = 0; i < arg4 / height; i++) {
        func_80045738(img1, img2, width, height);
        func_80045B2C(&arg2[var_s0]);
        var = height - 1;
        temp_lo_2 = (width * var);
        img1 += temp_lo_2 * 2;
        img2 += temp_lo_2;
        var_s0 += 4;
    }
    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
    gSPDisplayList(gDisplayListHead++, D_0D008120);
}

void func_800461A4(u8 *texture, Vtx *arg1, s32 width, s32 arg3, s32 height) {
    s32 heightIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        func_80043A84(img, width, height);
        func_80045B2C(&arg1[vertexIndex]);
            img += width * height * 4;
            vertexIndex += 4;
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800462A8(u8 *texture, Vtx *arg1, s32 width, s32 arg3, s32 height) {
    s32 heightIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        func_80043A84(img, width, height);
        func_80045B2C(&arg1[vertexIndex]);
            img += width * (height - 1) * 4;
            vertexIndex += 4;
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800463B0(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, UNUSED s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007928);
    func_80045D0C(texture, arg5, arg6, arg7, arg9);
}

void func_80046424(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, UNUSED s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007968);
    func_8004B614(D_801656C0, D_801656D0, D_801656E0, 128, 128, 128, 255);
    func_80045D0C(texture, arg5, arg6, arg7, arg9);
}

UNUSED void func_800464D0(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, UNUSED s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007948);
    func_80045E10(texture, arg5, arg6, arg7, arg9);
}

UNUSED void func_80046544(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, UNUSED s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D0079A8);
    func_80045E10(texture, arg5, arg6, arg7, arg9);
}

void func_800465B8(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 arg4, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, UNUSED s32 arg9, s32 argA) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D0079E8);

    set_transparency(arg4);
    func_80045E10(texture, arg6, arg7, arg8, argA);
}

UNUSED void func_80046634(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, UNUSED s32 arg9, s32 argA) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007948);
    func_80046030(tlut, texture, arg6, arg7, arg8, argA);
}

void func_800466B0(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx* arg5, s32 arg6, s32 arg7) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007948);
    func_80043D50(texture, arg6, arg7);
    func_80045B74(arg5);
}

UNUSED void func_80046720(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, UNUSED s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007928);
    func_800461A4(texture, arg5, arg6, arg7, arg9);
}

UNUSED void func_80046794(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, UNUSED s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007948);
    func_800462A8(texture, arg5, arg6, arg7, arg9);
}

void func_80046808(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, UNUSED s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007948);
    func_80045E10(texture, arg4, arg5, arg6, arg8);
}

UNUSED void func_80046874(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, UNUSED s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0079C8);
    func_80045E10(texture, arg4, arg5, arg6, arg8);
}

void func_800468E0(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, UNUSED s32 arg7, s32 arg8, s32 arg9) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0079C8);
    func_80045F18(texture, arg4, arg5, arg6, arg8, arg9);
}

UNUSED void func_80046954(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, UNUSED s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0079C8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    func_80045E10(texture, arg4, arg5, arg6, arg8);
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
}

void func_80046A00(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007948);
    func_80043D50(texture, arg5, arg6);
    func_80045B74(arg4);
}

UNUSED void func_80046A68(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, UNUSED s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D0079C8);
    func_800462A8(texture, arg4, arg5, arg6, arg8);
}

UNUSED void func_80046AD4(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture) {
    func_800464D0(arg0, arg1, arg2, arg3, texture, common_vtx_player_minimap_icon, 8, 8, 8, 8);
}

UNUSED void func_80046B38(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture) {
    func_800464D0(arg0, arg1, arg2, arg3, texture, common_vtx_rectangle, 16, 16, 16, 16);
}

UNUSED void func_80046B9C(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture) {
    func_80046808(arg0, arg1, arg2, texture, common_vtx_rectangle, 16, 16, 16, 16);
}

UNUSED void func_80046BEC(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_800466B0(arg0, arg1, arg2, arg3, texture, arg5, 16, 16);
}

UNUSED void func_80046C3C(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4) {
    func_80046A00(arg0, arg1, arg2, texture, arg4, 16, 16);
}

UNUSED void func_80046C78(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture) {
    func_800464D0(arg0, arg1, arg2, arg3, texture, D_0D005AE0, 32, 32, 32, 32);
}

UNUSED void func_80046CDC(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture) {
    func_800464D0(arg0, arg1, arg2, arg3, texture, &D_0D005FB0, 64, 32, 64, 32);
}

UNUSED void func_80046D40(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture) {
    func_80046808(arg0, arg1, arg2, texture, &D_0D005FB0, 64, 32, 64, 32);
}

UNUSED void func_80046D90(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture) {
    func_800464D0(arg0, arg1, arg2, arg3, texture, D_0D0060B0, 64, 64, 64, 32);
}

UNUSED void func_80046DF4(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 arg4, u8 *texture) {
    func_800465B8(arg0, arg1, arg2, arg3, arg4, texture, D_0D0060B0, 64, 64, 64, 32);
}

void func_80046E60(u8 *tlut, u8 *texture, s32 width, s32 height) {
    gSPDisplayList(gDisplayListHead++, D_0D007D78);
    gDPLoadTLUT_pal256(gDisplayListHead++, tlut);
    rsp_load_texture(texture, width, height);
}

void func_80046F60(u8 *tlut, u8 *arg1, s32 arg2, s32 arg3, s32 arg4) {
    gSPDisplayList(gDisplayListHead++, D_0D007D78);
    gDPLoadTLUT_pal256(gDisplayListHead++, tlut);
    rsp_load_texture_mask(arg1, arg2, arg3, arg4);
}

void func_80047068(u8 *tlut, u8 *texture, Vtx *arg2, UNUSED s32 arg3, s32 arg4, s32 width, s32 height) {
    s32 heightIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    gDPLoadTLUT_pal256(gDisplayListHead++, tlut);
    for (heightIndex = 0; heightIndex < arg4 / height; heightIndex++) {
        rsp_load_texture(img, width, height);
        gSPVertex(gDisplayListHead++, &arg2[vertexIndex], 4, 0);
        gSPDisplayList(gDisplayListHead++, common_rectangle_display);
        img += width * height;
        vertexIndex += 4;
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void draw_rectangle_texture_overlap(u8 *tlut, u8 *texture, Vtx *arg2, UNUSED s32 arg3, s32 arg4, s32 width, s32 height) {
    s32 heightIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    gDPLoadTLUT_pal256(gDisplayListHead++, tlut);
    for (heightIndex = 0; heightIndex < arg4 / height; heightIndex++) {
        rsp_load_texture(img, width, height);
        gSPVertex(gDisplayListHead++, &arg2[vertexIndex], 4, 0);
        gSPDisplayList(gDisplayListHead++, common_rectangle_display);
        img += width * (height - 1);
        vertexIndex += 4;
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_8004747C(u8 *tlut, u8 *texture, Vtx *arg2, UNUSED s32 arg3, s32 arg4, s32 width, s32 height, s32 someMask) {
    s32 heightIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    gDPLoadTLUT_pal256(gDisplayListHead++, tlut);
    for (heightIndex = 0; heightIndex < arg4 / height; heightIndex++) {
        rsp_load_texture_mask(img, width, height, someMask);
        gSPVertex(gDisplayListHead++, &arg2[vertexIndex], 4, 0);
        gSPDisplayList(gDisplayListHead++, common_rectangle_display);
        img += width * (height - 1);
        vertexIndex += 4;
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_8004768C(u8 *tlut, u8 *texture, Vtx *arg2, s32 arg3, s32 width, s32 height) {
    s32 heightIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    gDPLoadTLUT_pal256(gDisplayListHead++, tlut);
    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        // Something seems off about arguments here, but if it matches it matches
        rsp_load_texture(img, height, width);
        gSPVertex(gDisplayListHead++, &arg2[vertexIndex], 4, 0);
        gSPDisplayList(gDisplayListHead++, common_rectangle_display);
        img += height * width;
        vertexIndex += 4;
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_8004788C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007CB8);
    func_80047068(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_80047910(s32 x, s32 y, u16 angle, f32 size, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    func_80042330(x, y, angle, size);
    gSPDisplayList(gDisplayListHead++, D_0D007CD8);
    draw_rectangle_texture_overlap(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_80047994(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007CF8);
    draw_rectangle_texture_overlap(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_80047A18(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007D18);
    func_80047068(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_80047A9C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007D38);
    draw_rectangle_texture_overlap(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

UNUSED void func_80047B20(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007D38);
    func_8004768C(tlut, texture, arg6, arg7, arg8, arg9);
}

void func_80047B9C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 arg4, u8 *tlut, u8 *texture, Vtx *arg7, s32 arg8, s32 arg9, s32 argA, s32 argB) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007DB8);
    set_transparency(arg4);
    func_80047068(tlut, texture, arg7, arg8, arg9, argA, argB);
}

UNUSED void func_80047C28(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 arg4, u8 *tlut, u8 *texture, Vtx *arg7, s32 arg8, s32 arg9, s32 argA, s32 argB) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007DD8);
    set_transparency(arg4);
    draw_rectangle_texture_overlap(tlut, texture, arg7, arg8, arg9, argA, argB);
}

void func_80047CB4(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 arg4, u8 *tlut, u8 *texture, Vtx *arg7, s32 arg8, s32 arg9, s32 argA, s32 argB) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007E38);
    set_transparency(arg4);
    func_80047068(tlut, texture, arg7, arg8, arg9, argA, argB);
}

UNUSED void func_80047D40(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 arg4, u8 *tlut, u8 *texture, Vtx *arg7, s32 arg8, s32 arg9, s32 argA, s32 argB) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007E58);
    set_transparency(arg4);
    draw_rectangle_texture_overlap(tlut, texture, arg7, arg8, arg9, argA, argB);
}

UNUSED void func_80047DCC(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007CB8);
    func_80047068(tlut, texture, arg5, arg6, arg7, arg8, arg9);
}

void func_80047E48(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007CD8);
    draw_rectangle_texture_overlap(tlut, texture, arg5, arg6, arg7, arg8, arg9);
}

UNUSED void func_80047EC4(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007D18);
    func_80047068(tlut, texture, arg5, arg6, arg7, arg8, arg9);
}

void func_80047F40(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007D38);
    draw_rectangle_texture_overlap(tlut, texture, arg5, arg6, arg7, arg8, arg9);
}

UNUSED void func_80047FBC(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007D58);
    draw_rectangle_texture_overlap(tlut, texture, arg5, arg6, arg7, arg8, arg9);
}

UNUSED void func_80048038(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007D98);
    func_80047068(tlut, texture, arg5, arg6, arg7, arg8, arg9);
}

void func_800480B4(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007D78);
    draw_rectangle_texture_overlap(tlut, texture, arg5, arg6, arg7, arg8, arg9);
}

void func_80048130(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007D78);
    func_8004747C(tlut, texture, arg5, arg6, arg7, arg8, arg9, argA);
}

UNUSED void func_800481B4(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007D78);
    func_8004768C(tlut, texture, arg5, arg6, arg7, arg8);
}

UNUSED void func_80048228(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007DB8);
    set_transparency(arg3);
    func_80047068(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_800482AC(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007DD8);
    set_transparency(arg3);
    draw_rectangle_texture_overlap(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

UNUSED void func_80048330(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007E38);
    set_transparency(arg3);
    func_80047068(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_800483B4(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007E58);
    set_transparency(arg3);
    draw_rectangle_texture_overlap(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_80048438(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007DF8);
    set_transparency(arg3);
    func_80047068(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_800484BC(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007E18);
    set_transparency(arg3);
    draw_rectangle_texture_overlap(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_80048540(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007E98);
    set_transparency(arg3);
    draw_rectangle_texture_overlap(tlut, texture, arg6, arg7, arg8, arg9, argA);
}

void func_800485C4(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6, s32 arg7, s32 arg8, s32 arg9, s32 argA) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007E98);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_DITHER);
    gDPSetRenderMode(gDisplayListHead++, G_RM_AA_ZB_XLU_SURF, G_RM_AA_ZB_XLU_SURF2);

    set_transparency(arg3);
    draw_rectangle_texture_overlap(tlut, texture, arg6, arg7, arg8, arg9, argA);
    
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_NONE);
}

UNUSED void func_800486B0(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_8004788C(arg0, arg1, arg2, arg3, tlut, texture, arg6, 24, 48, 24, 48);
}

UNUSED void func_80048718(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_8004788C(arg0, arg1, arg2, arg3, tlut, texture, arg6, 32, 32, 32, 32);
}

UNUSED void func_80048780(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_80048540(arg0, arg1, arg2, arg3, tlut, texture, arg6, 48, 48, 48, 40);
}

UNUSED void func_800487DC(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_8004788C(arg0, arg1, arg2, arg3, tlut, texture, arg6, 48, 48, 48, 48);
}

UNUSED void func_80048844(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_8004788C(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 32, 64, 32);
}

UNUSED void func_800488AC(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_8004788C(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 64, 64, 32);
}

UNUSED void func_80048914(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_80047910(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 64, 64, 32);
}

UNUSED void func_8004897C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_80047994(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 64, 64, 32);
}

UNUSED void func_800489E4(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_80047A18(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 64, 64, 32);
}

UNUSED void func_80048A4C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_80047A9C(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 64, 64, 32);
}

UNUSED void func_80048AB4(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 arg4, u8 *tlut, u8 *texture, Vtx *arg7) {
    func_80047B9C(arg0, arg1, arg2, arg3, arg4, tlut, texture, arg7, 64, 64, 64, 32);
}

UNUSED void func_80048B24(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 arg4, u8 *tlut, u8 *texture, Vtx *arg7) {
    func_80047CB4(arg0, arg1, arg2, arg3, arg4, tlut, texture, arg7, 64, 64, 64, 32);
}

UNUSED void func_80048B94(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5) {
    func_80047E48(arg0, arg1, arg2, tlut, texture, arg5, 64, 64, 64, 32);
}

UNUSED void func_80048BE8(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5) {
    func_80047F40(arg0, arg1, arg2, tlut, texture, arg5, 64, 64, 64, 32);
}

UNUSED void func_80048C3C(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5) {
    func_800480B4(arg0, arg1, arg2, tlut, texture, arg5, 64, 64, 64, 32);
}

UNUSED void func_80048C90(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_800482AC(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 64, 64, 32);
}

UNUSED void func_80048CEC(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_800483B4(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 64, 64, 32);
}

UNUSED void func_80048D48(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_800484BC(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 64, 64, 32);
}

UNUSED void func_80048DA4(Vec3f arg0, Vec3su arg1, f32 arg2, s32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_80048540(arg0, arg1, arg2, arg3, tlut, texture, arg6, 64, 64, 64, 32);
}

UNUSED void func_80048E00(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_80047910(arg0, arg1, arg2, arg3, tlut, texture, arg6, 72, 48, 72, 24);
}

UNUSED void func_80048E68(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_80047A18(arg0, arg1, arg2, arg3, tlut, texture, arg6, 72, 48, 72, 24);
}

UNUSED void func_80048ED0(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *tlut, u8 *texture, Vtx *arg6) {
    func_80047A9C(arg0, arg1, arg2, arg3, tlut, texture, arg6, 72, 48, 72, 24);
}

UNUSED void func_80048F38(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *tlut, u8 *texture, Vtx *arg5) {
    func_800480B4(arg0, arg1, arg2, tlut, texture, arg5, 72, 48, 72, 24);
}

void func_80048F8C(u8 *texture, Vtx *arg1, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 heightIndex;
    s32 widthIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        for (widthIndex = 0; widthIndex < arg2 / width; widthIndex++) {
            func_800441E0(img, width, height);
            gSPVertex(gDisplayListHead++, &arg1[vertexIndex], 4, 0);
            gSPDisplayList(gDisplayListHead++, common_rectangle_display);
            img += width * height * 2;
            vertexIndex += 4;
        }
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80049130(u8 *texture, Vtx *arg1, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 heightIndex;
    s32 widthIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        for (widthIndex = 0; widthIndex < arg2 / width; widthIndex++) {
            func_80044388(img, width, height);
            gSPVertex(gDisplayListHead++, &arg1[vertexIndex], 4, 0);
            gSPDisplayList(gDisplayListHead++, common_rectangle_display);
            img += width * height * 2;
            vertexIndex += 4;
        }
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800492D4(u8 *texture, Vtx *arg1, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 heightIndex;
    s32 widthIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        for (widthIndex = 0; widthIndex < arg2 / width; widthIndex++) {
            func_800444B0(img, width, height);
            gSPVertex(gDisplayListHead++, &arg1[vertexIndex], 4, 0);
            gSPDisplayList(gDisplayListHead++, common_rectangle_display);
            img += width * height;
            vertexIndex += 4;
        }
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80049478(u8 *texture, Vtx *arg1, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 heightIndex;
    s32 widthIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        for (widthIndex = 0; widthIndex < arg2 / width; widthIndex++) {
            func_80044658(img, width, height);
            gSPVertex(gDisplayListHead++, &arg1[vertexIndex], 4, 0);
            gSPDisplayList(gDisplayListHead++, common_rectangle_display);
            img += width * height;
            vertexIndex += 4;
        }
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_8004961C(u8 *texture, Vtx *arg1, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 i;
    s32 j;
    s32 var_s2 = 0;
    u8 *img = texture;

    for (i = 0; i < arg3 / height; i++) {
        for (j = 0; j < arg2 / width; j++) {

            func_80044924(img, width, height);
            gSPVertex(gDisplayListHead++, &arg1[var_s2], 4, 0);
            gSPDisplayList(gDisplayListHead++, common_rectangle_display);
            img += (width * height) / 2;
            var_s2 += 4;
        }
    }

    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800497CC(u8 *texture, Vtx *arg1, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 heightIndex;
    s32 widthIndex;
    s32 vertexIndex = 0;
    u8 *img = texture;

    for (heightIndex = 0; heightIndex < arg3 / height; heightIndex++) {
        for (widthIndex = 0; widthIndex < arg2 / width; widthIndex++) {
            func_80044BF8(img, width, height);
            gSPVertex(gDisplayListHead++, &arg1[vertexIndex], 4, 0);
            gSPDisplayList(gDisplayListHead++, common_rectangle_display);
            img += width * height;
            vertexIndex += 4;
        }
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80049970(u8 *texture, Vtx *arg1, s32 arg2, s32 arg3, s32 width, s32 height) {
    s32 i;
    s32 j;
    s32 var_s2 = 0;
    u8 *img = texture;

    for (i = 0; i < arg3 / height; i++) {
        for (j = 0; j < arg2 / width; j++) {
            func_80044DA0(img, width, height);
            gSPVertex(gDisplayListHead++, &arg1[var_s2], 4, 0);
            gSPDisplayList(gDisplayListHead++, common_rectangle_display);
            img += (width * height) / 2;
            var_s2 += 4;
        }
    }
    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80049B20(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A40);
    func_80048F8C(texture, arg5, arg6, arg7, arg8, arg9);
}

UNUSED void func_80049B9C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A40);
    func_80049130(texture, arg5, arg6, arg7, arg8, arg9);
}

void func_80049C18(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A40);
    func_800492D4(texture, arg5, arg6, arg7, arg8, arg9);
}

void func_80049C94(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A60);
    func_800492D4(texture, arg5, arg6, arg7, arg8, arg9);
}

void func_80049D10(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A80);
    func_800492D4(texture, arg5, arg6, arg7, arg8, arg9);
}

void func_80049D8C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007AA0);
    func_800492D4(texture, arg5, arg6, arg7, arg8, arg9);
}

UNUSED void func_80049E08(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 red, s32 green, s32 blue, s32 alpha, u8 *texture, Vtx *arg9, s32 argA, s32 argB, s32 argC, s32 argD) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A40);
    func_8004B35C(red, green, blue, alpha);
    func_800492D4(texture, arg9, argA, argB, argC, argD);
}

UNUSED void func_80049E98(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 red, s32 green, s32 blue, s32 alpha, u8 *texture, Vtx *arg9, s32 argA, s32 argB, s32 argC, s32 argD) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A60);
    func_8004B35C(red, green, blue, alpha);
    func_800492D4(texture, arg9, argA, argB, argC, argD);
}

UNUSED void func_80049F28(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 red, s32 green, s32 blue, s32 alpha, u8 *texture, Vtx *arg9, s32 argA, s32 argB, s32 argC, s32 argD) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007B00);
    func_8004B35C(red, green, blue, alpha);
    func_800492D4(texture, arg9, argA, argB, argC, argD);
}

UNUSED void func_80049FB8(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A40);
    func_80049478(texture, arg5, arg6, arg7, arg8, arg9);
}

UNUSED void func_8004A034(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A60);
    func_80049478(texture, arg5, arg6, arg7, arg8, arg9);
}

void func_8004A0B0(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A40);
    func_8004961C(texture, arg5, arg6, arg7, arg8, arg9);
}

UNUSED void func_8004A12C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 red, s32 green, s32 blue, s32 alpha, u8 *texture, Vtx *arg9, s32 argA, s32 argB, s32 argC, s32 argD) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A60);
    func_8004B35C(red, green, blue, alpha);
    func_8004961C(texture, arg9, argA, argB, argC, argD);
}
UNUSED void func_8004A1BC(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A40);
    gDPSetCombineLERP(gDisplayListHead++, 1, 0, SHADE, 0, 0, 0, 0, TEXEL0, 1, 0, SHADE, 0, 0, 0, 0, TEXEL0);
    func_80049970(texture, arg5, arg6, arg7, arg8, arg9);
}

void func_8004A258(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5, s32 arg6, s32 arg7, s32 arg8, s32 arg9) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A60);
    gDPSetCombineLERP(gDisplayListHead++, 1, 0, SHADE, 0, 0, 0, 0, TEXEL0, 1, 0, SHADE, 0, 0, 0, 0, TEXEL0);
    func_80049970(texture, arg5, arg6, arg7, arg8, arg9);
}

void func_8004A2F4(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 red, s32 green, s32 blue, s32 alpha, u8 *texture, Vtx *arg9, s32 argA, s32 argB, s32 argC, s32 argD) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A40);
    func_8004B414(red, green, blue, alpha);
    func_80049970(texture, arg9, argA, argB, argC, argD);
}

void func_8004A384(s32 arg0, s32 arg1, u16 arg2, f32 arg3, s32 red, s32 green, s32 blue, s32 alpha, u8 *texture, Vtx *arg9, s32 argA, s32 argB, s32 argC, s32 argD) {
    func_80042330(arg0, arg1, arg2, arg3);
    gSPDisplayList(gDisplayListHead++, D_0D007A60);
    func_8004B414(red, green, blue, alpha);
    func_80049970(texture, arg9, argA, argB, argC, argD);
}

void func_8004A414(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007A40);
    func_800492D4(texture, arg4, arg5, arg6, arg7, arg8);
}

UNUSED void func_8004A488(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007A60);
    func_800492D4(texture, arg4, arg5, arg6, arg7, arg8);
}

UNUSED void func_8004A4FC(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007AC0);
    func_800492D4(texture, arg4, arg5, arg6, arg7, arg8);
}

UNUSED void func_8004A570(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007AE0);
    func_800492D4(texture, arg4, arg5, arg6, arg7, arg8);
}

UNUSED void func_8004A5E4(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4) {
    func_8004A414(arg0, arg1, arg2, texture, arg4, 16, 16, 16, 16);
}

void func_8004A630(Collision *arg0, Vec3f arg1, f32 arg2) {
    if (func_80041924(arg0, arg1) != 0) {
        D_80183E50[0] = arg1[0];
        D_80183E50[1] = func_802ABE30(arg1[0], 0.0f, arg1[2], arg0->unk3A) + 0.8;
        D_80183E50[2] = arg1[2];
        rsp_set_matrix_transl_rot_scale(D_80183E50, arg0->orientationVector, arg2);
        gSPDisplayList(gDisplayListHead++, D_0D007B98);
    }
}

void func_8004A6EC(s32 objectIndex, f32 scale) {
    Objects *temp_v0;

    if ((is_obj_index_flag_unk_054_active(objectIndex, 0x00000020) != 0) && (is_obj_index_flag_unk_054_active(objectIndex, 0x00800000) != 0)) {
        temp_v0 = &gObjectList[objectIndex];
        D_80183E50[0] = temp_v0->pos[0];
        D_80183E50[1] = temp_v0->unk_044 + 0.8;
        D_80183E50[2] = temp_v0->pos[2];
        rsp_set_matrix_transformation(D_80183E50, temp_v0->unk_0B8, scale);
        gSPDisplayList(gDisplayListHead++, D_0D007B20);
    }
}

void func_8004A7AC(s32 objectIndex, f32 arg1) {
    Objects *temp_v0;

    if (is_obj_index_flag_unk_054_active(objectIndex, 0x00000020) != 0) {
        temp_v0 = &gObjectList[objectIndex];
        D_80183E50[0] = temp_v0->pos[0];
        D_80183E50[1] = temp_v0->unk_044 + 0.8;
        D_80183E50[2] = temp_v0->pos[2];
        D_80183E98[0] = 0x4000;
        D_80183E98[1] = 0;
        D_80183E98[2] = 0;
        rsp_set_matrix_transformation(D_80183E50, D_80183E98, arg1);
        gSPDisplayList(gDisplayListHead++, D_0D007B20);
    }
}

void func_8004A870(s32 objectIndex, f32 arg1) {
    Mat4 sp30;
    Objects *temp_v0;

    if ((is_obj_index_flag_unk_054_active(objectIndex, 0x00000020) != 0) && (is_obj_index_flag_unk_054_active(objectIndex, 0x00800000) != 0)) {
        temp_v0 = &gObjectList[objectIndex];
        D_80183E50[0] = temp_v0->pos[0];
        D_80183E50[1] = temp_v0->unk_044 + 0.8;
        D_80183E50[2] = temp_v0->pos[2];
        set_transform_matrix(sp30, temp_v0->unk_01C, D_80183E50, 0U, arg1);
        convert_to_fixed_point_matrix(&gGfxPool->mtxHud[gMatrixHudCount], sp30);
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gGfxPool->mtxHud[gMatrixHudCount++]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        gSPDisplayList(gDisplayListHead++, D_0D007B98);
    }
}

void func_8004A9B8(f32 arg0) {
    rsp_set_matrix_transl_rot_scale(D_80183E50, D_80183E70, arg0);
    gSPDisplayList(gDisplayListHead++, D_0D007C10);
}

UNUSED void func_8004AA10(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    rsp_set_matrix_transformation(arg0, arg1, arg2);
    gSPDisplayList(gDisplayListHead++, D_0D007AE0);
    func_8004B6C4(D_80165860, D_8016586C, D_80165878);
    func_800497CC(texture, arg4, arg5, arg6, arg7, arg8);
}

UNUSED void func_8004AAA0(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_80049B20(arg0, arg1, arg2, arg3, texture, arg5, 16, 16, 16, 16);
}

UNUSED void func_8004AB00(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_80049C18(arg0, arg1, arg2, arg3, texture, arg5, 16, 16, 16, 16);
}

UNUSED void func_8004AB60(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *arg4, Vtx *arg5) {
    func_8004A0B0(arg0, arg1, arg2, arg3, arg4, arg5, 16, 16, 16, 16);
}

UNUSED void func_8004ABC0(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_80049B20(arg0, arg1, arg2, arg3, texture, arg5, 32, 32, 32, 32);
}

UNUSED void func_8004AC20(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *arg4, Vtx *arg5) {
    func_80049C18(arg0, arg1, arg2, arg3, arg4, arg5, 32, 32, 32, 32);
}

UNUSED void func_8004AC80(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *arg4, Vtx *arg5) {
    func_8004A0B0(arg0, arg1, arg2, arg3, arg4, arg5, 32, 32, 32, 32);
}

UNUSED void func_8004ACE0(Vec3f arg0, Vec3su arg1, f32 arg2, u8 *texture, Vtx *arg4) {
    func_8004A414(arg0, arg1, arg2, texture, arg4, 32, 32, 32, 32);
}

UNUSED void func_8004AD2C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_80049B20(arg0, arg1, arg2, arg3, texture, arg5, 64, 32, 64, 32);
}

UNUSED void func_8004AD8C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *arg4, Vtx *arg5) {
    func_80049C18(arg0, arg1, arg2, arg3, arg4, arg5, 64, 32, 64, 32);
}

UNUSED void func_8004ADEC(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *arg4, Vtx *arg5) {
    func_80049C94(arg0, arg1, arg2, arg3, arg4, arg5, 64, 32, 64, 32);
}

UNUSED void func_8004AE4C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_80049D10(arg0, arg1, arg2, arg3, texture, arg5, 64, 32, 64, 32);
}

UNUSED void func_8004AEAC(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_80049D8C(arg0, arg1, arg2, arg3, texture, arg5, 64, 32, 64, 32);
}

UNUSED void func_8004AF0C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_80049C18(arg0, arg1, arg2, arg3, texture, arg5, 64, 64, 64, 64);
}

UNUSED void func_8004AF6C(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_80049B20(arg0, arg1, arg2, arg3, texture, arg5, 64, 64, 64, 32);
}

UNUSED void func_8004AFCC(s32 arg0, s32 arg1, u16 arg2, f32 arg3, u8 *texture, Vtx *arg5) {
    func_80049C18(arg0, arg1, arg2, arg3, texture, arg5, 64, 96, 64, 48);
}

UNUSED void func_8004B02C(void) {
    gDPSetRenderMode(gDisplayListHead++, AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_WRAP | ZMODE_XLU | CVG_X_ALPHA | FORCE_BL | GBL_c1(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA), AA_EN | Z_CMP | Z_UPD | IM_RD | CVG_DST_WRAP | ZMODE_XLU | CVG_X_ALPHA | FORCE_BL | GBL_c2(G_BL_CLR_IN, G_BL_A_IN, G_BL_CLR_MEM, G_BL_1MA));
}

void func_8004B05C(u8 *tlut) {
    gDPLoadTLUT_pal256(gDisplayListHead++, tlut);
    gDPLoadSync(gDisplayListHead++);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
}

void func_8004B138(s32 red, s32 green, s32 blue, s32 alpha) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, alpha);
}

UNUSED void func_8004B180(s32 red, s32 green, s32 blue, s32 alpha) {
    gDPSetEnvColor(gDisplayListHead++, red, green, blue, alpha);
}

void func_8004B1C8(s32 primRed, s32 primGreen, s32 primBlue, s32 envRed, s32 envGreen, s32 envBlue, s32 primAlpha) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, primRed, primGreen, primBlue, primAlpha);
    gDPSetEnvColor(gDisplayListHead++, envRed, envGreen, envBlue, 0xFF);
}

UNUSED void func_8004B254(s32 red, s32 green, s32 blue) {
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, 0xFF);
}

void set_transparency(s32 alpha) {
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
}

void func_8004B310(s32 alpha) {
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 0x00, 0x00, 0x00, alpha);
}

void func_8004B35C(s32 red, s32 green, s32 blue, s32 alpha) {
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, alpha);
}

void func_8004B3C8(s32 alpha) {
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, 1, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, 1, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 0x00, 0x00, 0x00, alpha);
}

void func_8004B414(s32 red, s32 green, s32 blue, s32 alpha) {
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, PRIMITIVE, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, alpha);
}

void func_8004B480(s32 red, s32 green, s32 blue) {
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, 0xFF);
}

UNUSED void func_8004B4E8(s32 red, s32 green, s32 blue, s32 alpha) {
    gDPSetCombineLERP(gDisplayListHead++, 1, 0, SHADE, PRIMITIVE, 0, 0, 0, TEXEL0, 1, 0, SHADE, PRIMITIVE, 0, 0, 0, TEXEL0);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, alpha);
}

UNUSED void func_8004B554(s32 alpha) {
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, SHADE, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, SHADE, TEXEL0, 0, PRIMITIVE, 0);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 0xFF, 0xFF, 0xFF, alpha);
}

UNUSED void func_8004B5A8(s32 red, s32 green, s32 blue, s32 alpha) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, alpha);
    gDPSetCombineLERP(gDisplayListHead++, 1, PRIMITIVE_ALPHA, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0, 1, PRIMITIVE_ALPHA, TEXEL0, PRIMITIVE, 0, 0, 0, TEXEL0);
}

void func_8004B614(s32 primRed, s32 primGreen, s32 primBlue, s32 envRed, s32 envGreen, s32 envBlue, s32 primAlpha) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, primRed, primGreen, primBlue, primAlpha);
    gDPSetEnvColor(gDisplayListHead++, envRed, envGreen, envBlue, 0xFF);
    gDPSetCombineLERP(gDisplayListHead++, 1, ENVIRONMENT, TEXEL0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0, 1, ENVIRONMENT, TEXEL0, PRIMITIVE, PRIMITIVE, 0, TEXEL0, 0);
}

void func_8004B6C4(s32 red, s32 green, s32 blue) {
    gDPSetCombineLERP(gDisplayListHead++, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0, 0, 0, 0, PRIMITIVE, 0, 0, 0, TEXEL0);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, 0xFF);
}

void func_8004B72C(s32 primRed, s32 primGreen, s32 primBlue, s32 envRed, s32 envGreen, s32 envBlue, s32 primAlpha) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, primRed, primGreen, primBlue, primAlpha);
    gDPSetEnvColor(gDisplayListHead++, envRed, envGreen, envBlue, 0xFF);
    gDPSetCombineLERP(gDisplayListHead++, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0, PRIMITIVE, ENVIRONMENT, TEXEL0, ENVIRONMENT, TEXEL0, 0, PRIMITIVE, 0);
}

void func_8004B7DC(s32 x, s32 y, s32 width, s32 height, s32 arg4, s32 arg5, s32 arg6) {

    s32 xh = (((x + width) - 1) << 2);
    s32 yh = (((y + height) - 1) << 2);
    s32 xl = ((x * 4));
    s32 yl = y * 4;

    s32 xh2 = (((x + width)) << 2);
    s32 yh2 = ((y + height) << 2);

    if (arg6 == 0) {
        //! @todo Update to F3DEX. Uses OLD definition for gspTextureRectangle.
        gSPTextureRectangle(gDisplayListHead++, xl, yl, xh, yh, G_TX_RENDERTILE, arg4 << 5, (arg5 << 5), 4 << 10, 1 << 10);
        return;
    }
    gSPTextureRectangle(gDisplayListHead++, xl, yl, xh2, yh2, G_TX_RENDERTILE, arg4 << 5, (arg5 << 5), 1 << 10, 1 << 10);
}

void func_8004B950(s32 x, s32 y, s32 width, s32 height, s32 arg4) {
    func_8004B7DC(x, y, width, height, 0, 0, arg4);
}

void func_8004B97C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    UNUSED s32 pad[2];
    s32 sp2C;
    s32 var_a1;
    s32 var_v0;
    s32 var_v1;

    if ((-arg2 < arg0) && (-arg3 < arg1)) {
        var_v0 = 0;
        var_v1 = 0;
        sp2C = arg0;
        var_a1 = arg1;
        if (arg0 < 0) {
            var_v1 = -arg0;
            sp2C = 0;
        }
        if (arg1 < 0) {
            var_v0 = -arg1;
            var_a1 = 0;
        }
        func_8004B7DC(sp2C, var_a1, arg2 - var_v1, arg3 - var_v0, var_v1, var_v0, arg4);
    }
}

void func_8004BA08(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    UNUSED s32 pad[2];
    s32 sp2C;
    s32 phi_a1;
    s32 phi_v1;
    s32 phi_v0;

    if ((-arg2 < arg0) && (-arg3 < arg1)) {
        phi_v0 = 0;
        phi_v1 = 0;
        sp2C = arg0;
        phi_a1 = arg1;
        if (arg0 < 0) {
            phi_v1 = -arg0;
            sp2C = 0;
        }
        if (arg1 < 0) {
            phi_v0 = -arg1;
            phi_a1 = 0;
        }
        func_8004B7DC(sp2C, phi_a1, arg2 - phi_v1, arg3 - phi_v0, phi_v1 + arg2, phi_v0, arg4);
    }
}

void func_8004BA98(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    UNUSED s32 pad[2];
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s32 phi_a3;
    s32 phi_v0;
    s32 phi_v1;

    if ((-arg2 < arg0) && (-arg3 < arg1)) {
        sp34 = arg0;
        sp30 = arg1;
        phi_v0 = arg4;
        sp2C = arg2;
        phi_a3 = arg3;
        phi_v1 = arg5;
        if (arg0 < 0) {
            phi_v0 = arg4 - arg0;
            sp34 = 0;
            sp2C = arg2 + arg0;
        }
        if (arg1 < 0) {
            phi_v1 = arg5 - arg1;
            sp30 = 0;
            phi_a3 = arg3 + arg1;
        }
        func_8004B7DC(sp34, sp30, sp2C, phi_a3, phi_v0, phi_v1, arg6);
    }
}

UNUSED void func_8004BB34(void) {

}

void func_8004BB3C(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4) {
    s16 t;
    s16 s;
    s16 temp_t9;
    s32 var_t0;
    s32 var_t1;
    s32 xl;
    s32 yl;
    s32 thing0;
    s32 thing1;

    var_t0 = (arg2 * 4 * arg4) + 0.5;
    var_t1 = (arg3 * 4 * arg4) + 0.5;
    xl = (arg0 * 4) - (var_t0 / 2);
    yl = (arg1 * 4) - (var_t1 / 2);
    if (-var_t0 < xl) {
        t = 0;
        if (-var_t1 < yl) {
            s = 0;
            if (xl < 0) {
                var_t0 += xl;
                s = (-xl * 8) / arg4;
                xl = 0;
            }
            if (yl < 0) {
                var_t1 += yl;
                t = (-yl * 8) / arg4;
                yl = 0;
            }
            temp_t9 = (1024.0f / arg4) + 0.5;
            gSPTextureRectangle(gDisplayListHead++, xl, yl, xl + var_t0, yl + var_t1, 0, s, t, temp_t9, temp_t9);
        }
    }
}

UNUSED void func_8004BD14(s32 x, s32 y, u32 width, u32 height, s32 alpha, u8 *texture1, u8 *texture2) {
    gSPDisplayList(gDisplayListHead++, D_0D007F38);
    gSPDisplayList(gDisplayListHead++, D_0D008138);
    gDPSetTextureLOD(gDisplayListHead++, G_TL_TILE);
    gDPSetPrimColor(gDisplayListHead++, 0, 0, 0x00, 0x00, 0x00, alpha);
    gDPSetCombineLERP(gDisplayListHead++, TEXEL1, TEXEL0, PRIMITIVE_ALPHA, TEXEL0, TEXEL1, TEXEL0, PRIMITIVE, TEXEL0, 0, 0, 0, COMBINED, 0, 0, 0, COMBINED);
    gDPLoadMultiTile(gDisplayListHead++, texture1,   0,   G_TX_RENDERTILE, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, 0, width - 1, height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gDPLoadMultiTile(gDisplayListHead++, texture2, 256, G_TX_RENDERTILE+1, G_IM_FMT_RGBA, G_IM_SIZ_16b, width, height, 0, 0, width - 1, height - 1, 0, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMIRROR | G_TX_CLAMP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    func_8004B950(x, y, width, height, 2);
    gSPDisplayList(gDisplayListHead++, D_0D008120);
}

void func_8004C024(s16 arg0, s16 arg1, s16 arg2, u16 red, u16 green, u16 blue, u16 alpha) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, alpha);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    func_8004B97C(arg0, arg1, arg2, 1, 1);
}

void func_8004C148(s16 arg0, s16 arg1, s16 arg2, u16 red, u16 green, u16 blue, u16 alpha) {
    gDPSetPrimColor(gDisplayListHead++, 0, 0, red, green, blue, alpha);
    gDPSetTextureLUT(gDisplayListHead++, G_TT_NONE);
    gDPSetTexturePersp(gDisplayListHead++, G_TP_NONE);
    gDPSetCombineMode(gDisplayListHead++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    func_8004B97C(arg0, arg1, 1, arg2, 1);
}

void func_8004C268(u32 arg0, u32 arg1, u8 *texture, u32 width, u32 arg4, u32 height, s32 arg6)
{
    s32 i;
    u8 *img2;

    arg0 -= (width / 2);
    arg1 -= (arg4 / 2);
    img2 = texture;

    for (i = 0; (u32)i < (arg4 / height); i++) {
        func_80043D50(img2, width, height);
        func_8004B97C(arg0, arg1, width, height, arg6);
        //! @todo fakematch?
        #ifdef AVOID_UB
        img2 += (width * height) * 2;
        #else
        img2 += (width * height) * 2 ^ ((arg4 / height) * 0);
        #endif
        arg1 += height;
    }
}

UNUSED void func_8004C354() {
}

UNUSED void func_8004C35C() {
}

void func_8004C364(s32 arg0, s32 arg1, u32 arg2, u32 arg3, u8 *texture) {
    gSPDisplayList(gDisplayListHead++, D_0D008108);
    gSPDisplayList(gDisplayListHead++, D_0D007EF8);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    func_80043D50(texture, arg2, arg3);
    func_8004B97C(arg0 - (arg2 >> 1), arg1 - (arg3 >> 1), arg2, arg3, 0);
    gSPDisplayList(gDisplayListHead++, D_0D007EB8);
}

void func_8004C450(s32 arg0, s32 arg1, u32 arg2, u32 arg3, u8 *texture) {

    gSPDisplayList(gDisplayListHead++, D_0D007F38);
    func_8004B614(D_801656C0, D_801656D0, D_801656E0, 0x80, 0x80, 0x80, 0xFF);
    func_80043D50(texture, arg2, arg3);
    func_8004B97C(arg0 - (arg2 >> 1), arg1 - (arg3 >> 1), arg2, arg3, 1);
    gSPDisplayList(gDisplayListHead++, D_0D007EB8);
}

UNUSED void func_8004C53C(s32 arg0, s32 arg1, u32 arg2, u32 arg3, u8 *texture) {

    gSPDisplayList(gDisplayListHead++, D_0D008108);
    gSPDisplayList(gDisplayListHead++, D_0D007EF8);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    func_800440B8(texture, arg2, arg3);
    func_8004B97C(arg0 - (arg2 >> 1), arg1 - (arg3 >> 1), arg2, arg3, 0);
    gSPDisplayList(gDisplayListHead++, D_0D007EB8);
}

void func_8004C628(s32 arg0, s32 arg1, u32 arg2, u32 arg3, u8 *texture) {

    gSPDisplayList(gDisplayListHead++, D_0D007EF8);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    func_80043A84(texture, arg2, arg3);
    func_8004B97C(arg0 - (arg2 >> 1), arg1 - (arg3 >> 1), arg2, arg3, 1);
    gSPDisplayList(gDisplayListHead++, D_0D007EB8);
}

#ifdef MIPS_TO_C
//generated by m2c commit b7eac665cffd02361f73cec283ef16d0a35a0e5b
void func_8004C6FC(s16 arg0, s16 arg1, s8 *arg2, u32 arg3, u32 arg4) {
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v0_4;
    s32 temp_t5;
    s32 temp_v0_3;
    s32 var_s3;
    s32 var_s4;
    s8 *var_s5;
    u32 temp_t3;
    u32 temp_t8;
    u32 var_s0;
    u32 var_s6;
    u32 var_t2;

    var_s4 = arg1 - (arg4 >> 1);
    gSPDisplayList(gDisplayListHead++, D_0D007EF8);
    temp_t8 = arg3 * arg4 * 4;
    temp_t3 = temp_t8 >> 0xC;
    var_s5 = arg2;
    var_s6 = temp_t8;
    var_t2 = temp_t3;
    gDPSetRenderMode(gDisplayListHead++, G_RM_XLU_SURF, G_RM_XLU_SURF2);
    if (temp_t8 & 0xFFF) {
        var_t2 = temp_t3 + 1;
    }
    var_s0 = arg4 / var_t2;
    var_s3 = 0;
    if ((s32) var_t2 > 0) {
        do {
            temp_t5 = arg3 * var_s0 * 4;
            func_80043C28(var_s5, (s32) arg3, (s32) var_s0);
            func_8004B950(arg0 - (arg3 >> 1), var_s4, (s32) arg3, (s32) var_s0, 1);
            temp_v0_3 = var_s6 - temp_t5;
            var_s5 += temp_t5;
            if (temp_v0_3 < 0) {
                var_s0 = var_s6 / arg3;
            } else {
                var_s6 = (u32) temp_v0_3;
            }
            var_s3 += 1;
            var_s4 += var_s0;
        } while (var_s3 < (s32) var_t2);
    }
    gSPDisplayList(gDisplayListHead++, D_0D007EB8);
}
#else
GLOBAL_ASM("asm/non_matchings/hud_renderer/func_8004C6FC.s")
#endif

void func_8004C8D4(s16 arg0, s16 arg1) {
    func_8004C6FC(arg0, arg1, D_8018D1E0, 0x100, 0x80);
}

UNUSED void func_8004C91C(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4, s32 arg5) {
    gSPDisplayList(gDisplayListHead++, D_0D008108);
    gSPDisplayList(gDisplayListHead++, D_0D007EF8);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    func_8004C268(arg0, arg1, texture, arg3, arg4, arg5, 0);
    gSPDisplayList(gDisplayListHead++, D_0D007EB8);
}

void func_8004C9D8(s32 arg0, s32 arg1, s32 arg2, u8 *texture, s32 arg4, s32 arg5, UNUSED s32 arg6, s32 arg7) {
    gSPDisplayList(gDisplayListHead++, D_0D007F38);
    set_transparency(arg2);
    func_8004C268(arg0, arg1, texture, arg4, arg5, arg7, 1);
}

void func_8004CA58(s32 arg0, s32 arg1, f32 arg2, u8 *texture, s32 arg4, s32 arg5) {
    gSPDisplayList(gDisplayListHead++, D_0D007F78);
    func_80043D50(texture, arg4, arg5);
    func_8004BB3C(arg0, arg1, arg4, arg5, arg2);
}

void func_8004CAD0(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C364(arg0, arg1, 8, 8, texture);
}

UNUSED void func_8004CB00(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C364(arg0, arg1, 8, 16, texture);
}

UNUSED void func_8004CB30(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C364(arg0, arg1, 16, 16, texture);
}

void func_8004CB60(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C364(arg0, arg1, 32, 8, texture);
}

void func_8004CB90(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C364(arg0, arg1, 32, 16, texture);
}

UNUSED void func_8004CBC0(s32 arg0, s32 arg1, f32 arg2, u8 *texture) {
    func_8004CA58(arg0, arg1, arg2, texture, 32, 16);
}

UNUSED void func_8004CBF4(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C364(arg0, arg1, 32, 32, texture);
}

UNUSED void func_8004CC24(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C628(arg0, arg1, 32, 32, texture);
}

UNUSED void func_8004CC54(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C364(arg0, arg1, 40, 32, texture);
}

UNUSED void func_8004CC84(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C91C(arg0, arg1, texture, 48, 48, 24);
}

UNUSED void func_8004CCB4(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C364(arg0, arg1, 64, 32, texture);
}

UNUSED void func_8004CCE4(s32 arg0, s32 arg1, f32 arg2, u8 *texture) {
    func_8004CA58(arg0, arg1, arg2, texture, 64, 32);
}

UNUSED void func_8004CD18(s32 arg0, s32 arg1, u8 *texture) {
    func_8004C91C(arg0, arg1, texture, 64, 64, 32);
}

UNUSED void func_8004CD48(s32 arg0, s32 arg1, UNUSED u8 *texture, s32 width, s32 arg4, s32 height) {
    UNUSED s32 pad;
    s32 var_s0;
    s32 i;
    u8 *img;

    var_s0 = arg1 - (arg4 / 2);
    gSPDisplayList(gDisplayListHead++, D_0D007FE0);

    for (i = 0; i < arg4 / height; i++) {
        func_800441E0(img, width, height);
        func_8004B97C(arg0 - (width / 2), var_s0, width, height, 1);
        img += width * height * 2;
        var_s0 += height;
    }
}

UNUSED void func_8004CE8C(s32 arg0, s32 arg1, u8 *texture, s32 width, s32 arg4, s32 height) {
    s32 var_s0 = arg1 - (arg4 / 2);
    s32 i;
    u8 *img = texture;

    for (i = 0; i < arg4 / height; i++) {
        func_800444B0(img, width, height);
        func_8004B97C(arg0 - (width / 2), var_s0, width, height, 1);
        img += width * height;
        var_s0 += height;
    }
}

UNUSED void func_8004CF9C(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4, UNUSED s32 arg5, s32 arg6) {
    gSPDisplayList(gDisplayListHead++, D_0D007FE0);
    func_8004CE8C(arg0, arg1, texture, arg3, arg4, arg6);
}

UNUSED void func_8004CFF0(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4, UNUSED s32 arg5, s32 arg6) {
    gSPDisplayList(gDisplayListHead++, D_0D008000);
    func_8004CE8C(arg0, arg1, texture, arg3, arg4, arg6);
}

UNUSED void func_8004D044(s32 arg0, s32 arg1, u8 *texture, s32 red, s32 green, s32 blue, s32 alpha, s32 arg7, s32 arg8, UNUSED s32 arg9, s32 argA) {
    gSPDisplayList(gDisplayListHead++, D_0D007FE0);
    func_8004B35C(red, green, blue, alpha);
    func_8004CE8C(arg0, arg1, texture, arg7, arg8, argA);
}

UNUSED void func_8004D0CC(void) {

}

UNUSED void func_8004D0D4(s32 arg0, s32 arg1, u8 *texture, s32 width, s32 arg4, s32 height) {
    s32 var_s0;
    u8 *img;
    s32 i;

    var_s0 = arg1 - (arg4 / 2);
    img = texture;
    gSPDisplayList(gDisplayListHead++, D_0D007FE0);

    for (i = 0; i < arg4 / height; i++) {
            func_80044924(img, width, height);
            func_8004B97C(arg0 - (width / 2), var_s0, width, height, 1);
            img += width * height;
            var_s0 += height;
    }
}

void func_8004D210(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 width, s32 arg8, UNUSED s32 arg9, s32 height) {
    s32 var_s3;
    u8 *img;
    s32 i;

    var_s3 = arg1 - (arg8 / 2);
    img = texture;
    gSPDisplayList(gDisplayListHead++, D_0D007FE0);
    func_8004B35C(arg3, arg4, arg5, arg6);

    for (i = 0; i < arg8 / height; i++) {
        func_80044924(img, width, height);
        func_8004B97C(arg0 - (width / 2), var_s3, width, height, 1);
        img += (width * height) / 2;
        var_s3 += height;
    }

}

void func_8004D37C(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 width, s32 arg8, UNUSED s32 arg9, s32 height) {
    s32 var_s3;
    u8 *img;
    s32 i;


    var_s3 = arg1 - (arg8 / 2);
    img = texture;
    gSPDisplayList(gDisplayListHead++, D_0D007FE0);
    func_8004B414(arg3, arg4, arg5, arg6);

    for (i = 0; i < arg8 / height; i++) {
        func_80044F34(img, width, height);
        func_8004B97C(arg0 - (width / 2), var_s3, width, height, 1);
        img += (width * height) / 2;
        var_s3 += height;
    }
}

void func_8004D4E8(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 width, s32 arg8, UNUSED s32 arg9, s32 height) {
    s32 var_s3;
    u8 *img;
    s32 i;

    var_s3 = arg1 - (arg8 / 2);
    img = texture;
    gSPDisplayList(gDisplayListHead++, D_0D007FE0);
    func_8004B414(arg3, arg4, arg5, arg6);

    for (i = 0; i < arg8 / height; i++) {
        func_800450C8(img, width, height);
        func_8004BA08(arg0 - (width / 2), var_s3, width, height, 1);
        img += (width * height) / 2;
        var_s3 += height;
    }
}

#ifdef NON_MATCHING
//generated by m2c commit b7eac665cffd02361f73cec283ef16d0a35a0e5b
//? func_80044F34(s8 *, s32, s32);                    /* extern */

UNUSED void func_8004D654(s32 arg0, s32 arg1, u8 *texture, f32 arg3, s32 arg4, s32 arg5, s32 arg6, UNUSED s32 arg7, s32 width, s32 arg9, UNUSED s32 argA, s32 height) {
    u8 *img;
    s32 var_s3;
    s32 i;
    // Something weird with (width / 2).
    var_s3 = arg1 - (width / 2);
    img = texture;
    gSPDisplayList(gDisplayListHead++, D_0D008000);
    func_8004B480(arg4, arg5, arg6);

    for (i = 0; i < arg9 / height; i++) {
        func_80044F34(img, width, height);
        func_8004BB3C(arg0, var_s3, width, arg9, arg3);
        img += (width * height) / 2;
        var_s3 += height;
    }
}
#else
GLOBAL_ASM("asm/non_matchings/hud_renderer/func_8004D654.s")
#endif

void func_8004D7B4(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4) {
    s32 sp5C;
    f32 temp_f20;
    s16 temp_s7;
    s16 var_s1;
    u16 temp_s0;
    s32 temp_s5;
    s32 var_s3;
    u8 *img;
    UNUSED s32 test[3];
    s32 i;

    D_801656B0 += D_80165710;
    temp_f20 = D_8018D00C;
    temp_s7 = D_80165708;
    var_s1 = D_801656B0;
    img = texture;
    var_s3 = arg1 - (arg4 / 2);
    gSPDisplayList(gDisplayListHead++, D_0D007FE0);

    sp5C = arg3 * 2;
    for (i = 0; i < arg4; i++) {
        temp_s0 = var_s1;
        temp_s5 = (s32) ((sins(temp_s0) * temp_f20) + (f32) (arg0 - (arg3 / 2)));
        sins(temp_s0);
        func_800441E0(img, arg3, 1);
        func_8004B97C(temp_s5, var_s3, arg3, 1, 1);

        var_s1 += temp_s7;
        var_s3 += 1;
        img += sp5C;
    }
}

void func_8004D93C(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4) {
    f32 temp_f20;
    s16 temp_s7;
    s16 var_s1;
    u16 temp_s0;
    s32 temp_s6;
    s32 var_s4;
    u8 *img;
    s32 i;
    s32 var;

    D_801656B0 += D_80165710;
    temp_f20 = D_8018D00C;
    temp_s7 = D_80165708;
    var_s1 = D_801656B0;
    img = texture;
    var = arg3 / 2;
    var_s4 = arg1 - (arg4 / 2);


    gSPDisplayList(gDisplayListHead++, D_0D007FE0);

    for (i = 0; i < arg4; i++) {
        temp_s0 = var_s1;
        temp_s6 = (s32) ((sins(temp_s0) * temp_f20) + (f32) (arg0 - (var)));
        sins(temp_s0);
        func_800444B0(img, arg3, 1);
        func_8004B97C(temp_s6, var_s4, arg3, 1, 1);
        var_s1 += temp_s7;
        img = &img[arg3];
        var_s4 += 1;
    }
}

UNUSED void func_8004DAB8(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4) {
    f32 temp_f20;
    s16 temp_s7;
    s16 var_s1;
    u16 temp_s0;
    s32 temp_s6;
    u8 *img;
    s32 var_s4;
    s32 var;
    s32 i;

    D_801656B0 += D_80165710;
    temp_f20 = D_8018D00C;
    temp_s7 = D_80165708;
    var_s1 = (s16) D_801656B0;
    img = texture;
    var = arg3 / 2;
    var_s4 = arg1 - (arg4 / 2);

    gSPDisplayList(gDisplayListHead++, D_0D007FE0);
    for (i = 0; i < arg4; i++) {
        temp_s0 = var_s1;
        temp_s6 = (s32) ((sins(temp_s0) * temp_f20) + (f32) (arg0 - (var)));
        sins(temp_s0);
        func_80044924(img, arg3, 1);
        func_8004B97C(temp_s6, var_s4, arg3, 1, 1);
        var_s1 += temp_s7;
        img += arg3;
        var_s4 += 1;
    }
}

UNUSED void func_8004DC34(s32 arg0, s32 arg1, u8 *texture) {
    func_8004CF9C(arg0, arg1, texture, 8, 160, 8, 160);
}

UNUSED void func_8004DC6C(s32 arg0, s32 arg1, u8 *texture) {
    func_8004CF9C(arg0, arg1, texture, 12, 160, 12, 160);
}

UNUSED void func_8004DCA4(s32 arg0, s32 arg1, u8 *texture) {
    func_8004CF9C(arg0, arg1, texture, 12, 192, 12, 192);
}

UNUSED void func_8004DCDC(s32 arg0, s32 arg1, u8 *texture) {
    func_8004CD48(arg0, arg1, texture, 16, 16, 16);
}

UNUSED void func_8004DD0C(s32 arg0, s32 arg1, u8 *texture) {
    func_8004CF9C(arg0, arg1, texture, 16, 160, 16, 160);
}

UNUSED void func_8004DD44(s32 arg0, s32 arg1, u8 *texture) {
    func_8004CD48(arg0, arg1, texture, 32, 32, 32);
}

UNUSED void func_8004DD74(s32 arg0, s32 arg1, u8 *texture) {
    func_8004CF9C(arg0, arg1, texture, 32, 32, 32, 32);
}

UNUSED void func_8004DDAC(s32 arg0, s32 arg1, u8 *texture) {
    func_8004D0D4(arg0, arg1, texture, 32, 32, 32);
}

UNUSED void func_8004DDDC(s32 arg0, s32 arg1, u8 *texture) {
    func_8004D7B4(arg0, arg1, texture, 32, 32);
}

UNUSED void func_8004DE04(s32 arg0, s32 arg1, u8 *texture) {
    func_8004D93C(arg0, arg1, texture, 32, 32);
}

UNUSED void func_8004DE2C(s32 arg0, s32 arg1, u8 *arg2) {
    func_8004DAB8(arg0, arg1, arg2, 32, 32);
}

UNUSED void func_8004DE54(s32 arg0, s32 arg1, u8 *arg2) {
    func_8004CD48(arg0, arg1, arg2, 64, 32, 32);
}

UNUSED void func_8004DE84(s32 arg0, s32 arg1, u8 *arg2) {
    func_8004CD48(arg0, arg1, arg2, 64, 64, 32);
}

UNUSED void func_8004DEB4(s32 arg0, s32 arg1, u8 *texture) {
    func_8004CF9C(arg0, arg1, texture, 64, 96, 64, 48);
}

UNUSED void func_8004DEEC(s32 arg0, s32 arg1, u8 *arg2) {
    func_8004CF9C(arg0, arg1, arg2, 112, 32, 112, 32);
}

UNUSED void func_8004DF24(s32 arg0, s32 arg1, u8 *arg2) {
    func_8004CF9C(arg0, arg1, arg2, 128, 32, 128, 32);
}

void func_8004DF5C(s32 arg0, s32 arg1, u8 *texture, s32 width, s32 arg4, s32 height) {
    s32 var_s0 = var_s0 = arg1 - (arg4 / 2);
    u8 *img = texture;
    s32 i;
    
    for (i = 0; i < arg4 / height; i++) {
            rsp_load_texture(img, width, height);
            func_8004B97C(arg0 - (width / 2), var_s0, width, height, 1);
            img += width * height;
            var_s0 += height;
    }
}

void func_8004E06C(s32 arg0, s32 arg1, u8 *texture, s32 arg3, s32 arg4) {
    f32 temp_f20;
    s16 temp_s7;
    s16 var_s1;
    u16 temp_s0;
    s32 var_s4;
    u8 *img;
    u32 temp_s6;
    s32 i;
    s32 var;


    D_801656B0 += D_80165710;
    temp_f20 = D_8018D00C;
    var_s1 = (s16) D_801656B0;
    temp_s7 = D_80165708;
    img = texture;
    var = arg3 / 2;
    var_s4 = arg1 - (arg4 / 2);

    for (i = 0; i < arg4; i++) {
            temp_s0 = var_s1;
            temp_s6 = (u32) ((sins(temp_s0) * temp_f20) + (f32) (arg0 - var));
            sins(temp_s0);
            rsp_load_texture(img, arg3, 1);
            func_8004B97C(temp_s6, var_s4, arg3, 1, 1);
            var_s1 += temp_s7;
            img += arg3;
            var_s4 += 1;
    }
}

UNUSED void func_8004E238(void) {

}

void func_8004E240(s32 arg0, s32 arg1, u8 *tlut, u8 *texture, s32 arg4, s32 arg5, s32 arg6) {
    gSPDisplayList(gDisplayListHead++, D_0D007CB8);
    func_8004B05C(tlut);
    func_8004DF5C(arg0, arg1, texture, arg4, arg5, arg6);
}

void func_8004E2B8(s32 arg0, s32 arg1, s32 arg2, u8 *tlut, u8 *texture, s32 arg5, s32 arg6, s32 arg7) {
    gSPDisplayList(gDisplayListHead++, D_0D007DB8);
    set_transparency(arg2);
    func_8004B05C(tlut);
    func_8004DF5C(arg0, arg1, texture, arg5, arg6, arg7);
}

void func_8004E338(s32 arg0, s32 arg1, u8 *tlut, u8 *texture, s32 arg4, s32 arg5) {
    gSPDisplayList(gDisplayListHead++, D_0D007DB8);
    set_transparency(D_8016589C);
    func_8004B05C(tlut);
    func_8004E06C(arg0, arg1, texture, arg4, arg5);
}

UNUSED void func_8004E3B8(void) {

}

UNUSED void func_8004E3C0(s32 arg0, s32 arg1, u8 *tlut, u8 *texture, s32 arg4, s32 arg5, UNUSED s32 arg6, s32 arg7) {
    func_8004E240(arg0, arg1, tlut, texture, arg4, arg5, arg7);
}

UNUSED void func_8004E3F4(s32 arg0, s32 arg1, s32 arg2, u8 *tlut, u8 *texture, s32 arg5, s32 arg6, UNUSED s32 arg7, s32 arg8) {
    func_8004E2B8(arg0, arg1, arg2, tlut, texture, arg5, arg6, arg8);
}

UNUSED void func_8004E430(s32 arg0, s32 arg1, u8 *tlut, u8 *texture) {
    func_8004E240(arg0, arg1, tlut, texture, 8, 128, 128);
}

UNUSED void func_8004E464(s32 arg0, s32 arg1, u8 *tlut, u8 *texture) {
    func_8004E240(arg0, arg1, tlut, texture, 32, 32, 32);
}

UNUSED void func_8004E498(s32 arg0, s32 arg1, u8 *tlut, u8 *texture) {
    func_8004E240(arg0, arg1, tlut, texture, 32, 64, 64);
}

void func_8004E4CC(s32 arg0, s32 arg1, u8 *tlut, u8 *texture) {
    func_8004E240(arg0, arg1, tlut, texture, 40, 32, 32);
}

UNUSED void func_8004E500(s32 arg0, s32 arg1, u8 *tlut, u8 *texture) {
    func_8004E240(arg0, arg1, tlut, texture, 48, 48, 24);
}

UNUSED void func_8004E534(s32 arg0, s32 arg1, u8 *tlut, u8 *texture) {
    func_8004E240(arg0, arg1, tlut, texture, 64, 32, 32);
}

UNUSED void func_8004E568(s32 arg0, s32 arg1, u8 *tlut, u8 *texture) {
    func_8004E240(arg0, arg1, tlut, texture, 64, 64, 32);
}

UNUSED void func_8004E59C(s32 arg0, s32 arg1, s32 arg2, u8 *tlut, u8 *texture) {
    func_8004E2B8(arg0, arg1, arg2, tlut, texture, 64, 64, 32);
}

UNUSED void func_8004E5D8(s32 arg0, s32 arg1, u8 *tlut, u8 *arg3) {
    func_8004E338(arg0, arg1, tlut, arg3, 64, 64);
}

UNUSED void func_8004E604(s32 arg0, s32 arg1, u8 *tlut, u8 *texture) {
    func_8004E240(arg0, arg1, tlut, texture, SCREEN_WIDTH, SCREEN_HEIGHT, 6);
}

void func_8004E638(s32 playerId) {
    s32 objectIndex;
    Objects *temp_v1;
    hud_player *temp_v0;

    objectIndex = gItemWindowObjectByPlayerId[playerId];
    temp_v1 = &gObjectList[objectIndex];
    if (temp_v1->state >= 2) {
        temp_v0 = &playerHUD[playerId];
        func_8004E4CC(temp_v0->slideItemBoxX + temp_v0->itemBoxX, temp_v0->slideItemBoxY + temp_v0->itemBoxY, (u8 *) temp_v1->activeTLUT, temp_v1->activeTexture);
    }
}

void func_8004E6C4(s32 playerId) {
    s32 objectIndex;
    Objects *temp_v1;
    hud_player *temp_v0;

    objectIndex = gItemWindowObjectByPlayerId[playerId];
    temp_v1 = &gObjectList[objectIndex];
    if (temp_v1->state >= 2) {
        temp_v0 = &playerHUD[playerId];
        func_80047910(temp_v0->slideItemBoxX + temp_v0->itemBoxX, temp_v0->slideItemBoxY + temp_v0->itemBoxY, 0U, temp_v0->unknownScaling, (u8 *) temp_v1->activeTLUT, (u8 *) temp_v1->activeTexture, D_0D005C30, 0x00000028, 0x00000020, 0x00000028, 0x00000020);
    }
}

void func_8004E78C(s32 playerId) {
    func_8004CB60((s32) playerHUD[playerId].lapX, playerHUD[playerId].lapY + 3, (s32) common_texture_hud_lap);
    func_8004CB90(playerHUD[playerId].lapX + 0x1C, (s32) playerHUD[playerId].lapY, D_800E4570[playerHUD[playerId].alsoLapCount]);
}

void func_8004E800(s32 playerId) {
    if (playerHUD[playerId].unk_81 != 0) {
        if (playerHUD[playerId].lapCount != 3) {
            func_8004A384(playerHUD[playerId].rankX + playerHUD[playerId].slideRankX, playerHUD[playerId].rankY + playerHUD[playerId].slideRankY, 0U,
                playerHUD[playerId].rankScaling, 0x000000FF, D_800E55F8[D_8018CF98[playerId]], 0, 0x000000FF, common_texture_hud_place[D_8018CF98[playerId]],
                D_0D0068F0, 0x00000080, 0x00000040, 0x00000080, 0x00000040);
        } else {
            func_8004A384(playerHUD[playerId].rankX + playerHUD[playerId].slideRankX, playerHUD[playerId].rankY + playerHUD[playerId].slideRankY, 0U,
                playerHUD[playerId].rankScaling, 0x000000FF, D_800E55F8[D_80165594], 0, 0x000000FF, common_texture_hud_place[gGPCurrentRaceRankByPlayerId[playerId]],
                D_0D0068F0, 0x00000080, 0x00000040, 0x00000080, 0x00000040);
        }
    }
}

void func_8004E998(s32 playerId) {
    if (playerHUD[playerId].unk_81 != 0) {
        if (playerHUD[playerId].lapCount != 3) {
            func_8004A384(playerHUD[playerId].rankX + playerHUD[playerId].slideRankX, playerHUD[playerId].rankY + playerHUD[playerId].slideRankY, 0U,
                playerHUD[playerId].rankScaling, 0x000000FF, D_800E5618[gGPCurrentRaceRankByPlayerId[playerId]], 0, 0x000000FF, D_0D015258[gGPCurrentRaceRankByPlayerId[playerId]],
                D_0D006030, 0x00000040, 0x00000040, 0x00000040, 0x00000040);
        } else {
            func_8004A384(playerHUD[playerId].rankX + playerHUD[playerId].slideRankX, playerHUD[playerId].rankY + playerHUD[playerId].slideRankY, 0U,
                playerHUD[playerId].rankScaling, 0x000000FF, D_800E5618[D_80165598], 0, 0x000000FF, D_0D015258[gGPCurrentRaceRankByPlayerId[playerId]],
                D_0D006030, 0x00000040, 0x00000040, 0x00000040, 0x00000040);
        }
    }
}

void func_8004EB30(UNUSED s32 arg0) {

}

void func_8004EB38(s32 playerId) {
    hud_player *temp_s0;

    temp_s0 = &playerHUD[playerId];
    if ((u8) temp_s0->unk_7B != 0) {
        func_8004C9D8(temp_s0->lap1CompletionTimeX - 0x13, temp_s0->timerY + 8, 0x00000080, (s32) common_texture_hud_time, 0x00000020, 0x00000010, 0x00000020, 0x00000010);
        func_8004F950((s32) temp_s0->lap1CompletionTimeX, (s32) temp_s0->timerY, 0x00000080, (s32) temp_s0->someTimer);
    }
    if ((u8) temp_s0->unk_7C != 0) {
        func_8004C9D8(temp_s0->lap2CompletionTimeX - 0x13, temp_s0->timerY + 8, 0x00000050, (s32) common_texture_hud_time, 0x00000020, 0x00000010, 0x00000020, 0x00000010);
        func_8004F950((s32) temp_s0->lap2CompletionTimeX, (s32) temp_s0->timerY, 0x00000050, (s32) temp_s0->someTimer);
    }
    if ((u8) temp_s0->unk_7E != 0) {
        func_8004C9D8((s32) temp_s0->lapAfterImage1X, temp_s0->lapY + 3, 0x00000080, (s32) common_texture_hud_lap, 0x00000020, 8, 0x00000020, 8);
        func_8004C9D8(temp_s0->lapAfterImage1X + 0x1C, (s32) temp_s0->lapY, 0x00000080, D_800E4570[temp_s0->alsoLapCount], 0x00000020, 0x00000010, 0x00000020, 0x00000010);
    }
    if ((u8) temp_s0->unk_7F != 0) {
        func_8004C9D8((s32) temp_s0->lapAfterImage2X, temp_s0->lapY + 3, 0x00000050, (s32) common_texture_hud_lap, 0x00000020, 8, 0x00000020, 8);
        func_8004C9D8(temp_s0->lapAfterImage2X + 0x1C, (s32) temp_s0->lapY, 0x00000050, D_800E4570[temp_s0->alsoLapCount], 0x00000020, 0x00000010, 0x00000020, 0x00000010);
    }
}

void func_8004ED40(s32 arg0) {
    func_8004A2F4(playerHUD[arg0].speedometerX, playerHUD[arg0].speedometerY, 0U, 1.0f, D_8018D300, D_8018D308, D_8018D310, 0xFF, (u8* ) common_texture_speedometer, D_0D0064B0, 0x40, 0x60, 0x40, 0x30);
    func_8004A258(D_8018CFEC, D_8018CFF4, D_8016579E, 1.0f, (u8* ) common_texture_speedometer_needle, &D_0D005FF0, 0x40, 0x20, 0x40, 0x20);
}

void func_8004EE54(s32 arg0) {
    if (gIsMirrorMode != 0) {
        func_8004D4E8(D_8018D2C0[arg0] + D_8018D2F0, D_8018D2D8[arg0] + D_8018D2F8, (u8 *) D_8018D240, (s32) D_8018D300, (s32) D_8018D308, (s32) D_8018D310, 0x000000FF, (s32) D_8018D2B0, (s32) D_8018D2B8, (s32) D_8018D2B0, (s32) D_8018D2B8);
    } else {
        func_8004D37C(D_8018D2C0[arg0] + D_8018D2F0, D_8018D2D8[arg0] + D_8018D2F8, (u8 *) D_8018D240, (s32) D_8018D300, (s32) D_8018D308, (s32) D_8018D310, 0x000000FF, (s32) D_8018D2B0, (s32) D_8018D2B8, (s32) D_8018D2B0, (s32) D_8018D2B8);
    }
}

void func_8004EF9C(s32 arg0) {
    s16 temp_t0;
    s16 temp_v0;

    temp_v0 = D_800E5548[arg0 * 2];
    temp_t0 = D_800E5548[arg0 * 2 + 1];
    func_8004D37C(0x00000104, 0x0000003C, D_8018D248[arg0], 0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF, temp_v0, temp_t0, temp_v0, temp_t0);
}

void func_8004F020(s32 arg0) {
    f32 var_f0;
    f32 var_f2;

    var_f2 = ((D_8018D2C0[arg0] + D_8018D2F0) - (D_8018D2B0 / 2)) + D_8018D2E0;
    var_f0 = ((D_8018D2D8[arg0] + D_8018D2F8) - (D_8018D2B8 / 2)) + D_8018D2E8;
    switch (gCurrentCourseId) {                     /* irregular */
    case COURSE_MARIO_RACEWAY:
        var_f0 = var_f0 - 2.0;
        break;
    case COURSE_CHOCO_MOUNTAIN:
        var_f0 = var_f0 - 16.0;
        break;
    case COURSE_KALAMARI_DESERT:
        var_f0 = var_f0 + 4.0;
        break;
    }
    func_8004CAD0(var_f2, var_f0, common_texture_minimap_finish_line);
}

#ifdef NON_MATCHING
//generated by m2c commit beb457dabfc7a01ec6540a5404a6a05097a13602 on Dec-20-2023
/**
 * characterId of 8 appears to be a type of null check or control flow alteration.
*/
void func_8004F168(s32 arg0, s32 playerId, s32 characterId) {
    Player *player = &gPlayerOne[playerId];
    s32 temp_a0;
    s32 temp_a1;

    if (gPlayerOne->type & PLAYER_EXISTS) {
        temp_a0 = ((D_8018D2C0[arg0] + D_8018D2F0) - ((s16) D_8018D2B0 / 2)) + D_8018D2E0 + (s32) (player->pos[0] * D_8018D2A0);
        temp_a1 = ((D_8018D2D8[arg0] + D_8018D2F8) - ((s16) D_8018D2B8 / 2)) + D_8018D2E8 + (s32) (player->pos[2] * D_8018D2A0);
        if (characterId != 8) {
            if ((gGPCurrentRaceRankByPlayerId[playerId] == 0) && (gModeSelection != BATTLE) && (gModeSelection != TIME_TRIALS)) {
                func_80046424((s32) temp_a0, (s32) temp_a1, (player->rotation[1] + 0x8000) & 0xFFFF, 1.0f, (u8 *) common_texture_minimap_kart_character[characterId], common_vtx_player_minimap_icon, 8, 8, 8, 8);
                // return;
            } else {
                func_800463B0((s32) temp_a0, (s32) temp_a1, (player->rotation[1] + 0x8000) & 0xFFFF, 1.0f, (u8 *) common_texture_minimap_kart_character[characterId], common_vtx_player_minimap_icon, 8, 8, 8, 8);
            }
            //return;
        } else {
            if (gGPCurrentRaceRankByPlayerId[playerId] == 0) {
                func_8004C450((s32) temp_a0, (s32) temp_a1, 8, 8, (u8 *) common_texture_minimap_progress_dot);
                //return;
            } else {
                func_8004C364((s32) temp_a0, (s32) temp_a1, 8, 8, (u8 *) common_texture_minimap_progress_dot);
            }
        }
    }
}
#else
GLOBAL_ASM("asm/non_matchings/hud_renderer/func_8004F168.s")
#endif

// WTF is up with the gPlayerOne access in this function?
void func_8004F3E4(s32 arg0) {
    Player *player;
    s32 playerId;
    s32 idx;

    switch (gModeSelection) {                   /* irregular */
    case GRAND_PRIX:
        for (idx = D_8018D158 - 1; idx >= 0; idx--) {
            playerId = gGPCurrentRacePlayerIdByRank[idx];
            if ((gPlayerOne + playerId)->type & PLAYER_CPU) {
                func_8004F168(arg0, playerId, 8);
            }
        }
        for (idx = D_8018D158 - 1; idx >= 0; idx--) {
            playerId = gGPCurrentRacePlayerIdByRank[idx];
            if (((gPlayerOne + playerId)->type & PLAYER_CPU) != PLAYER_CPU) {
                func_8004F168(arg0, playerId, (gPlayerOne + playerId)->characterId);
            }
        }
        break;
    case TIME_TRIALS:
        for (idx = 0; idx < 8; idx++) {
            if (((gPlayerOne + idx)->type & PLAYER_INVISIBLE_OR_BOMB) == PLAYER_INVISIBLE_OR_BOMB) {
                func_8004F168(arg0, idx, 8);
            }
        }
        func_8004F168(arg0, 0, gPlayerOne->characterId);
        break;
    case VERSUS:
        for (idx = gPlayerCountSelection1 - 1; idx >=0; idx--) {
            playerId = gGPCurrentRacePlayerIdByRank[idx];
            func_8004F168(arg0, playerId, (gPlayerOne + playerId)->characterId);
        }
        break;
    case BATTLE:
        for (idx = 0; idx < gPlayerCountSelection1; idx++) {
            if (!((gPlayerOne + idx)->type & PLAYER_UNKNOWN_0x40)) {
                func_8004F168(arg0, idx, (gPlayerOne + idx)->characterId);
            }
        }
        break;
    }
}

s32 func_8004F674(s32 *arg0, s32 arg1) {
    s32 temp_v0;
    s32 ret;

    temp_v0 = *arg0;
    if (temp_v0 != 0) {
        ret = temp_v0 / arg1;
        *arg0 = temp_v0 % arg1;
    } else {
        *arg0 = 0;
        ret = 0;
    }
    return ret;
}

void func_8004F6D0(s32 arg0) {
    s32 stackPadding0;
    s32 stackPadding1;
    s32 sp24;

    sp24 = arg0;
    if (arg0 >= 599999) {
        sp24 = 599999;
    }
    D_801657D0[0] = func_8004F674(&sp24, 60000);
    D_801657D0[1] = func_8004F674(&sp24, 6000);
    D_801657D0[3] = func_8004F674(&sp24, 1000);
    D_801657D0[4] = func_8004F674(&sp24, 100);
    D_801657D0[6] = func_8004F674(&sp24, 10);
    D_801657D0[7] = sp24;
    D_801657D0[2] = 10;
    D_801657D0[5] = 11;
}

void func_8004F774(s32 arg0, s32 arg1) {
    s32 i;
    s32 phi_s1 = arg0;

    for (i = 0; i < 8; i++) {
        func_8004BA98(phi_s1, arg1, 8, 16, D_801657D0[i] * 8, 0, 0);
        phi_s1 += 8;
    }
}

void print_timer(s32 arg0, s32 arg1, s32 arg2) {
    gSPDisplayList(gDisplayListHead++, D_0D008108);
    gSPDisplayList(gDisplayListHead++, D_0D007EF8);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    func_80043D50(common_texture_hud_normal_digit, 104, 16);
    func_8004F6D0(arg2);
    func_8004F774(arg0, arg1);
    gSPDisplayList(gDisplayListHead++, D_0D007EB8);
}

void func_8004F8CC(s32 arg0, s32 arg1) {
    s32 phi_s1 = arg0;
    s32 i;

    for (i = 0; i < 8; i++) {
        func_8004BA98(phi_s1, arg1, 8, 16, D_801657D0[i] * 8, 0, 1);
        phi_s1 += 8;
    }
}

void func_8004F950(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    gSPDisplayList(gDisplayListHead++, D_0D007F38);
    set_transparency(arg2);
    func_80043D50(common_texture_hud_normal_digit, 104, 16);
    func_8004F6D0(arg3);
    func_8004F8CC(arg0, arg1);
}

void func_8004F9CC(s32 arg0, s32 arg1, s32 arg2) {
    gSPDisplayList(gDisplayListHead++, D_0D007F38);
    func_8004B614(D_801656C0, D_801656D0, D_801656E0, 128, 128, 128, 255);
    func_80043D50(common_texture_hud_normal_digit, 104, 16);
    func_8004F6D0(arg2);
    func_8004F8CC(arg0, arg1);
}

void func_8004FA78(s32 playerId) {
    s32 var_s0;

    if ((gModeSelection != 2) && (gModeSelection != 3)) {
        if (D_8018D320 == playerHUD[playerId].lapCount) {
            if (D_8015F890 == 0) {
                for (var_s0 = 0; var_s0 < 3; var_s0++) {
                    if (D_80165658[var_s0] == 0) {
                        print_timer(playerHUD[playerId].lapCompletionTimeXs[var_s0], playerHUD[playerId].timerY + (var_s0*0x10), playerHUD[playerId].lapDurations[var_s0]);
                    } else {
                        func_8004F9CC(playerHUD[playerId].lapCompletionTimeXs[var_s0], playerHUD[playerId].timerY + (var_s0*0x10), playerHUD[playerId].lapDurations[var_s0]);
                    }
                }
                func_8004CB90(playerHUD[playerId].totalTimeX - 0x13, playerHUD[playerId].timerY + 0x38, common_texture_hud_total_time);
                if (D_801657E5 != 0) {
                    func_8004F9CC(playerHUD[playerId].totalTimeX, playerHUD[playerId].timerY + 0x30, playerHUD[playerId].someTimer);
                } else {
                    print_timer(playerHUD[playerId].totalTimeX, playerHUD[playerId].timerY + 0x30, playerHUD[playerId].someTimer);
                }
            }
        } else {
            if (playerHUD[playerId].blinkTimer == 0) {
                func_8004CB90(playerHUD[playerId].timerX - 0x13, playerHUD[playerId].timerY + 8, common_texture_hud_time);
                print_timer(playerHUD[playerId].timerX, playerHUD[playerId].timerY, playerHUD[playerId].someTimer);
            } else {
                func_8004CB90(playerHUD[playerId].timerX - 0x13, playerHUD[playerId].timerY + 8, common_texture_hud_lap_time);
                if (D_801657E3 != 0) {
                    func_8004F9CC(playerHUD[playerId].timerX, playerHUD[playerId].timerY, playerHUD[playerId].someTimer1);
                } else if (playerHUD[playerId].blinkState == 0) {
                    print_timer(playerHUD[playerId].timerX, playerHUD[playerId].timerY, playerHUD[playerId].someTimer1);
                }
            }
        }
    }
}

void func_8004FC78(s16 arg0, s16 arg1, s8 arg2) {
    gSPDisplayList(gDisplayListHead++, D_0D008108);
    gSPDisplayList(gDisplayListHead++, D_0D007EF8);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
    func_80043D50(common_texture_hud_123, 32, 8);
    func_8004BA98(arg0, arg1, 8, 8, arg2 * 8, 0, 0);
    func_8004BA98(arg0 + 8, arg1, 8, 8, 24, 0, 0);
    func_8004BA98(arg0 + 16, arg1, 8, 8, 16, 0, 0);
    gSPDisplayList(gDisplayListHead++, D_0D007EB8);
}

void func_8004FDB4(f32 arg0, f32 arg1, s16 arg2, s16 arg3, s16 characterId, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    if ((gCurrentCourseId == COURSE_YOSHI_VALLEY) && (arg3 < 3) && (arg8 == 0)) {
        func_80042330((s32) arg0, (s32) arg1, 0U, 1.0f);
        gSPDisplayList(gDisplayListHead++, D_0D007DB8);
        func_8004B35C(0x000000FF, 0x000000FF, 0x000000FF, D_8018D3E0);
        gDPLoadTLUT_pal256(gDisplayListHead++, common_tlut_portrait_bomb_kart_and_question_mark);
        rsp_load_texture(common_texture_portrait_question_mark, 0x00000020, 0x00000020);
        gSPDisplayList(gDisplayListHead++, D_0D0069E0);
    } else {
        func_80042330(arg0, arg1, 0U, 1.0f);
        gSPDisplayList(gDisplayListHead++, D_0D007DB8);
        func_8004B35C(0x000000FF, 0x000000FF, 0x000000FF, arg5);
        gDPLoadTLUT_pal256(gDisplayListHead++, gPortraitTLUTs[characterId]);
        rsp_load_texture(gPortraitTextures[characterId], 0x00000020, 0x00000020);
        if (arg7 != 0) {
            gSPDisplayList(gDisplayListHead++, D_0D0069F8);
        } else {
            gSPDisplayList(gDisplayListHead++, D_0D0069E0);
        }
        if (arg6 != 0) {
            func_80042330(arg0, arg1, 0U, 1.0f);
            gSPDisplayList(gDisplayListHead++, D_0D007A60);
            func_8004B35C(D_8018D3E4, D_8018D3E8, D_8018D3EC, 0x000000FF);
            func_80044924(common_texture_character_portrait_border, 0x20, 0x20);
            gSPDisplayList(gDisplayListHead++, D_0D0069E0);
        }
        gSPDisplayList(gDisplayListHead++, D_0D007DB8);
        func_8004B35C(0x000000FF, 0x000000FF, 0x000000FF, arg5);
        gSPDisplayList(gDisplayListHead++, D_0D007CB8);
        gDPLoadTLUT_pal256(gDisplayListHead++, common_tlut_hud_type_C_rank_font);
        rsp_load_texture(common_texture_hud_type_C_rank_font[arg2], 0x00000010, 0x00000010);
        if (arg7 != 0) {
            func_80042330((s32) (arg0 + 9.0f), (s32) (arg1 + 7.0f), 0U, 1.0f);
        } else {
            func_80042330((s32) (arg0 - 9.0f), (s32) (arg1 + 7.0f), 0U, 1.0f);
        }
        gSPDisplayList(gDisplayListHead++, D_0D006980);
    }
}

void func_80050320(void) {
    s16 temp_v0;
    s16 characterId;
    s32 var_s0;
    s32 lapCount;
    s32 var_a0;

    if (D_801657E2 == 0) {
        for (var_s0 = 0; var_s0 < 4; var_s0++) {
            var_a0 = 0;
            if (D_8018D050[var_s0] >= 0.0f) {
                if (D_8018D078[var_s0] < 0.0) {
                    var_a0 = 1;
                }
                temp_v0 = gGPCurrentRacePlayerIdByRank[var_s0];
                characterId = gGPCurrentRaceCharacterIdByRank[var_s0];
                lapCount = gLapCountByPlayerId[temp_v0];
                if (characterId == gPlayerOne->characterId) {
                    func_8004FDB4(D_8018D028[var_s0], D_8018D050[var_s0], var_s0, lapCount, characterId, 0x000000FF, 1, var_a0, 0);
                } else {
                    func_8004FDB4(D_8018D028[var_s0], D_8018D050[var_s0], var_s0, lapCount, characterId, D_8018D3E0, 0, var_a0, 0);
                }
            }
        }
    } else {
        for (var_s0 = 0; var_s0 < 8; var_s0++) {
            var_a0 = 0;
            if (D_8018D050[var_s0] >= 0.0f) {
                if (D_8018D078[var_s0] <= 0.0) {
                    var_a0 = 1;
                }
                temp_v0 = gGPCurrentRacePlayerIdByRank[var_s0];
                // ????
                characterId = (gPlayerOne + temp_v0)->characterId;
                lapCount = gLapCountByPlayerId[temp_v0];
                if (temp_v0 == 0) {
                    func_8004FDB4(D_8018D028[var_s0], D_8018D050[var_s0], var_s0, lapCount, characterId, 0x000000FF, 1, var_a0, 1);
                } else {
                    func_8004FDB4(D_8018D028[var_s0], D_8018D050[var_s0], var_s0, lapCount, characterId, 0x000000FF, 0, var_a0, 1);
                }
            }
        }
    }
    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

s32 func_80050644(u16 arg0, s32 *arg1, s32 *arg2) {
    s32 var_v0 = 0;
    s32 thing = 0;
    s32 test = gLapCountByPlayerId[arg0];

    if (test < 3) {
        if (gPlayerCountSelection1 == 1) {
            if (test >= 0) {
                thing = (s32) (gLapCompletionPercentByPlayerId[arg0] * 928);
            }
            if (thing < 0x104) {
                *arg1 = thing;
                *arg2 = 0;
                var_v0 = 1;
            } else if (thing < 0x1D0) {
                *arg1 = 0x00000104;
                *arg2 = thing - 0x104;
                var_v0 = 2;
            } else if (thing < 0x2D4) {
                *arg1 = 0x2D4 - thing;
                *arg2 = 0x000000CC;
                var_v0 = 3;
            } else {
                *arg1 = 0;
                *arg2 = 0x3A0 - thing;
                var_v0 = 4;
            }
        } else {
            if (test >= 0) {
                thing = (s32) (gLapCompletionPercentByPlayerId[arg0] * 260);
            }
            *arg1 = thing;
            *arg2 = 0;
        }
    } else if (gPlayerCountSelection1 == 1) {
        *arg1 = 0x00000020;
        *arg2 = (gGPCurrentRaceRankByPlayerId[arg0] * 0x14) + 0x20;
    } else {
        thing = (s32) (gLapCompletionPercentByPlayerId[arg0] * 260);
        *arg1 = thing;
        *arg2 = 0;
    }
    return var_v0;
}

void func_800507D8(u16 bombIndex, s32 *arg1, s32 *arg2) {
    s32 temp_v0 = gBombKarts[bombIndex].waypointIndex;
    s32 var_v1 = 0;

    if (temp_v0 != 0) {
        var_v1 = (s32) (temp_v0 * 0x3A0) / (s32) D_80164430;
    }
    if (var_v1 < 0x104) {
        *arg1 = var_v1;
        *arg2 = 0;
    } else if (var_v1 < 0x1D0) {
        *arg1 = 0x00000104;
        *arg2 = var_v1 - 0x104;
    } else if (var_v1 < 0x2D4) {
        *arg1 = 0x2D4 - var_v1;
        *arg2 = 0x000000CC;
    } else {
        *arg1 = 0;
        *arg2 = 0x3A0 - var_v1;
    }
}

void func_800508C0(void) {
    s32 sp54;
    s32 sp50;
    s32 sp4C;
    s32 temp_v1;
    s16 var_s0;
    s16 stackPadding;
    u16 var_s0_2;
    u16 var_s1;
    u16 var_s2;

    if (gModeSelection == TIME_TRIALS) {
        var_s0 = D_80164378[0];
    } else {
        var_s0 = gGPCurrentRacePlayerIdByRank[0];
    }
    sp4C = func_80050644(var_s0, &sp54, &sp50);
    temp_v1 = gLapCountByPlayerId[var_s0];
    if (temp_v1 > 0) {
        if (temp_v1 == 1) {
            var_s0_2 = 0;
            var_s1 = 0;
            var_s2 = 0x000000FF;
        } else {
            if (temp_v1 == 2) {
                var_s0_2 = 0x00FF;
                var_s1 = 0x000000FF;
                var_s2 = 0;
            } else {
                var_s0_2 = 0x00FF;
                var_s1 = 0;
                var_s2 = 0;
            }
        }
        func_8004C024(0x0020, 0x0012, 0x0104, var_s0_2, var_s1, var_s2, 0x000000FF);
        func_8004C148(0x0124, 0x0012, 0x00CC, var_s0_2, var_s1, var_s2, 0x000000FF);
        func_8004C024(0x0020, 0x00DE, 0x0104, var_s0_2, var_s1, var_s2, 0x000000FF);
        func_8004C148(0x0020, 0x0012, 0x00CC, var_s0_2, var_s1, var_s2, 0x000000FF);
    }
    if ((temp_v1 < 0) || (temp_v1 >= 3)) return;
    switch (temp_v1) {
    case 0:
        var_s0_2 = 0;
        var_s1 = 0;
        var_s2 = 0x00FF;
        break;
    case 1:
        var_s0_2 = 0x00FF;
        var_s1 = 0x00FF;
        var_s2 = 0;
        break;
    case 2:
        var_s0_2 = 0x00FF;
        var_s1 = 0;
        var_s2 = 0;
        break;
    default:
        break;
    }
    switch (sp4C) {
    case 1:
        func_8004C024(0x0020, 0x0012, sp54, var_s0_2, var_s1, var_s2, 0x000000FF);
        break;
    case 2:
        func_8004C024(0x0020, 0x0012, 0x0104, var_s0_2, var_s1, var_s2, 0x000000FF);
        func_8004C148(0x0124, 0x0012, sp50, var_s0_2, var_s1, var_s2, 0x000000FF);
        break;
    case 3:
        func_8004C024(0x0020, 0x0012, 0x0104, var_s0_2, var_s1, var_s2, 0x000000FF);
        func_8004C148(0x0124, 0x0012, 0x00CC, var_s0_2, var_s1, var_s2, 0x000000FF);
        func_8004C024(sp54 + 0x20, 0x00DE, 0x104 - sp54, var_s0_2, var_s1, var_s2, 0x000000FF);
        break;
    case 4:
        func_8004C024(0x0020, 0x0012, 0x0104, var_s0_2, var_s1, var_s2, 0x000000FF);
        func_8004C148(0x0124, 0x0012, 0x00CC, var_s0_2, var_s1, var_s2, 0x000000FF);
        func_8004C024(0x0020, 0x00DE, 0x0104, var_s0_2, var_s1, var_s2, 0x000000FF);
        func_8004C148(0x0020, sp50 + 0x12, 0xCC - sp50, var_s0_2, var_s1, var_s2, 0x000000FF);
        break;
    case 0:
    default:
        break;
    }
}

void func_80050C68(void) {
    s32 stackPadding0;
    s32 sp88;
    s32 sp84;
    s32 stackPadding1;
    s32 var_s1;

    for (var_s1 = 0; var_s1 < NUM_BOMB_KARTS_VERSUS; var_s1++) {
        if ((gBombKarts[var_s1].state != BOMB_STATE_EXPLODED) && (gBombKarts[var_s1].state != BOMB_STATE_INACTIVE)) {
            func_800507D8(var_s1, &sp88, &sp84);
            gSPDisplayList(gDisplayListHead++, D_0D007DB8);
            gDPLoadTLUT_pal256(gDisplayListHead++, common_tlut_portrait_bomb_kart_and_question_mark);
            rsp_load_texture(common_texture_portrait_bomb_kart, 0x00000020, 0x00000020);
            func_80042330(sp88 + 0x20, sp84 + 0x12, 0U, 0.6f);
            gSPDisplayList(gDisplayListHead++, D_0D0069E0);
        }
    }
}

#ifdef NON_MATCHING

// Something about the handling of the `player` variable is weird.
// All commands are present and correct, 2 of them are out of position
void func_80050E34(s32 playerId, s32 arg1) {
    s32 objectIndex;
    s32 spD0;
    s32 spCC;
    s32 stackPadding;
    s32 spC4;
    s32 lapCount;
    s32 characterId;
    s32 spB8;
    s32 temp_v0_2;
    Objects *object;
    Player *player;

    player = &gPlayerOne[playerId];
    lapCount = gLapCountByPlayerId[playerId];
    characterId = player->characterId;
    objectIndex = D_8018CE10[playerId].objectIndex;

    if (gPlayerCountSelection1 == 1) {
        spC4 = 0x00000012;
    } else {
        spC4 = 0x00000078;
    }

    temp_v0_2 = func_80050644(playerId, &spD0, &spCC);
    if ((temp_v0_2 == 2) || (temp_v0_2 == 3)) {
        spB8 = 1;
    } else {
        spB8 = 0;
    }

    if ((gCurrentCourseId == COURSE_YOSHI_VALLEY) && (lapCount < 3)) {
        gSPDisplayList(gDisplayListHead++, D_0D007DB8);
        gDPLoadTLUT_pal256(gDisplayListHead++, common_tlut_portrait_bomb_kart_and_question_mark);
        rsp_load_texture(common_texture_portrait_question_mark, 0x00000020, 0x00000020);
        object = &gObjectList[objectIndex];
        object->pos[0] = object->unk_028[0] + ((f32) (spD0 + 0x20));
        object->pos[1] = object->unk_028[1] + ((f32) (spC4 + spCC));
        object->pos[2] = object->unk_028[2];
        rsp_set_matrix_transformation(object->pos, object->direction_angle, object->sizeScaling);
        gSPDisplayList(gDisplayListHead++, D_0D0069E0);
    } else {
        gDPLoadTLUT_pal256(gDisplayListHead++, gPortraitTLUTs[characterId]);
        gSPDisplayList(gDisplayListHead++, D_0D007DB8);
        if (player->effects & 0x200) {
            func_8004B614((s32) D_801656C0, (s32) D_801656D0, (s32) D_801656E0, 0x00000080, 0x00000080, 0x00000080, (s32) gObjectList[objectIndex].unk_0A0);
        } else {
            set_transparency((s32) gObjectList[objectIndex].unk_0A0);
        }
        rsp_load_texture(gPortraitTextures[characterId], 0x00000020, 0x00000020);
        object = &gObjectList[objectIndex];
        object->pos[0] = object->unk_028[0] + ((f32) (spD0 + 0x20));
        object->pos[1] = object->unk_028[1] + ((f32) (spC4 + spCC));
        object->pos[2] = object->unk_028[2];
        rsp_set_matrix_transformation(object->pos, object->direction_angle, object->sizeScaling);
        if (spB8 != 0) {
            gSPDisplayList(gDisplayListHead++, D_0D0069F8);
        } else {
            gSPDisplayList(gDisplayListHead++, D_0D0069E0);
        }
        gDPLoadTLUT_pal256(gDisplayListHead++, common_tlut_hud_type_C_rank_tiny_font);
        rsp_load_texture(common_texture_hud_type_C_rank_tiny_font[arg1 + 1], 8, 8);
        if (spB8 != 0) {
            func_80042330(spD0 + 0x26, (spC4 + spCC) + 4, 0U, 1.0f);
        } else {
            func_80042330(spD0 + 0x1B, (spC4 + spCC) + 4, 0U, 1.0f);
        }
        gSPDisplayList(gDisplayListHead++, D_0D006950);
        if ((player == gPlayerOne) && (gScreenModeSelection == SCREEN_MODE_1P)) {
            gSPDisplayList(gDisplayListHead++, D_0D007A40);
            func_8004B35C(D_8018D3E4, D_8018D3E8, D_8018D3EC, 0x000000FF);
            func_80044924(common_texture_character_portrait_border, 0x00000020, 0x00000020);
            rsp_set_matrix_transformation(object->pos, object->direction_angle, object->sizeScaling);
            gSPDisplayList(gDisplayListHead++, D_0D0069E0);
        }
    }
}
#else
GLOBAL_ASM("asm/non_matchings/hud_renderer/func_80050E34.s")
#endif

void func_800514BC(void) {
    s32 temp_a0;
    s32 var_s0;
    s32 var_s1;
    s32 var_s3;
    Player *player;

    if (gScreenModeSelection == 0) {
        func_800508C0();
    }
    var_s3 = 8;
    if ((gPlayerCountSelection1 == 2) && (gActiveScreenMode == 2)) {
        var_s3 = 0;
    }
    for (var_s0 = var_s3 - 1, var_s1 = 0; var_s1 < var_s3; var_s1++, var_s0--) {
        temp_a0 = gGPCurrentRacePlayerIdByRank[var_s0];
        player = &gPlayerOne[temp_a0];
        if ((player->type & 0x8000) && ((temp_a0 != 0) || (gPlayerCountSelection1 != 1))) {
            func_80050E34(temp_a0, var_s0);
        }
    }
    if (gModeSelection == 1) {
        func_80050E34(0, D_80164408[0]);
    } else if (gPlayerCountSelection1 == 1) {
        func_80050E34(0, gGPCurrentRaceRankByPlayerId[0]);
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80051638(UNUSED s32 arg0) {
    s32 someIndex;
    s32 leafIndex;
    Objects *object;

    gSPDisplayList(gDisplayListHead++, D_0D0079C8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    func_80043D50(common_texture_particle_leaf, 0x00000020, 0x00000010);
    for(someIndex = 0; someIndex < gLeafParticle_SIZE; someIndex++) {
        leafIndex = gLeafParticle[someIndex];
        if (leafIndex != -1) {
            object = &gObjectList[leafIndex];
            if ((object->state >= 2) && (object->unk_0D5 == 7) && (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX)) {
                rsp_set_matrix_gObjectList(leafIndex);
                gSPDisplayList(gDisplayListHead++, D_0D0069C8);
            }
        }
    }
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800517C8(void) {
    s32 someIndex;
    s32 snowflakeIndex;

    gSPDisplayList(gDisplayListHead++, D_0D007AE0);
    gDPSetCombineLERP(gDisplayListHead++, 1, 0, SHADE, 0, 0, 0, 0, TEXEL0, 1, 0, SHADE, 0, 0, 0, 0, TEXEL0);
    func_80044F34(D_0D0293D8, 0x10, 0x10);
    for (someIndex = 0; someIndex < NUM_SNOWFLAKES; someIndex++) {
        snowflakeIndex = gObjectParticle1[someIndex];
        if (gObjectList[snowflakeIndex].state >= 2) {
            rsp_set_matrix_gObjectList(snowflakeIndex);
            gSPDisplayList(gDisplayListHead++, D_0D006980);
        }
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800518F8(s32 objectIndex, s16 arg1, s16 arg2) {
    s32 pad[1];
    if (gObjectList[objectIndex].unk_054 & 0x10) {
        if (D_8018D228 != gObjectList[objectIndex].unk_0D5) {
            D_8018D228 = gObjectList[objectIndex].unk_0D5;
            func_80044DA0(gObjectList[objectIndex].activeTexture, gObjectList[objectIndex].textureWidth, gObjectList[objectIndex].textureHeight);
        }
        func_80042330(arg1, arg2, 0U, gObjectList[objectIndex].sizeScaling);
        gSPVertex(gDisplayListHead++, gObjectList[objectIndex].vertex, 4, 0);
        gSPDisplayList(gDisplayListHead++, common_rectangle_display);
    }
}

void func_800519D4(s32 objectIndex, s16 arg1, s16 arg2) {
    if (gObjectList[objectIndex].unk_054 & 0x10) {
        if (D_8018D228 != gObjectList[objectIndex].unk_0D5) {
            D_8018D228 = gObjectList[objectIndex].unk_0D5;
            func_80044DA0(gObjectList[objectIndex].activeTexture, gObjectList[objectIndex].textureWidth, gObjectList[objectIndex].textureHeight);
        }
        func_8004B138(0x000000FF, 0x000000FF, 0x000000FF, gObjectList[objectIndex].unk_0A0);
        func_80042330(arg1, arg2, 0U, gObjectList[objectIndex].sizeScaling);
        gSPVertex(gDisplayListHead++, gObjectList[objectIndex].vertex, 4, 0);
        gSPDisplayList(gDisplayListHead++, common_rectangle_display);
    }
}

void func_80051ABC(s16 arg0, s32 arg1) {
    s32 var_s0;
    s32 objectIndex;
    Objects *object;

    D_8018D228 = 0xFF;
    gSPDisplayList(gDisplayListHead++, D_0D007A60);
    if ((u8) D_8018D230 != 0) {
        func_8004B414(0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF);
        for (var_s0 = 0; var_s0 < D_8018D1F0; var_s0++) {
            objectIndex = D_8018CC80[arg1 + var_s0];
            object = &gObjectList[objectIndex];
            func_800519D4(objectIndex, object->unk_09C, arg0 - object->unk_09E);
        }
    } else {
        func_8004B6C4(0x000000FF, 0x000000FF, 0x000000FF);
        for (var_s0 = 0; var_s0 < D_8018D1F0; var_s0++) {
            objectIndex = D_8018CC80[arg1 + var_s0];
            object = &gObjectList[objectIndex];
            func_800518F8(objectIndex, object->unk_09C, arg0 - object->unk_09E);
        }
    }
}

void func_80051C60(s16 arg0, s32 arg1) {
    s16 var_s5;
    s32 var_s0;
    s32 objectIndex;
    Objects *object;

    if (D_801658FE == 0) {
        if (gCurrentCourseId == 6) {
            var_s5 = arg0;
        } else if (gCurrentCourseId == 9) {
            var_s5 = arg0 - 0x10;
        } else if (gCurrentCourseId == 4) {
            var_s5 = arg0 - 0x10;
        } else {
            var_s5 = arg0 + 0x10;
        }
    } else if (gCurrentCourseId == 6) {
        var_s5 = arg0 * 2;
    } else {
        var_s5 = arg0 + 0x20;
    }
    D_8018D228 = 0xFF;
    gSPDisplayList(gDisplayListHead++, D_0D007A60);
    if ((u8) D_8018D230 != 0) {
        func_8004B414(0x000000FF, 0x000000FF, 0x000000FF, 0x000000FF);
        for (var_s0 = 0; var_s0 < D_8018D1F0; var_s0++) {
            objectIndex = D_8018CC80[arg1 + var_s0];
            object = &gObjectList[objectIndex];
            func_800519D4(objectIndex, object->unk_09C, (var_s5 - object->unk_09E) / 2);
        }
    } else {
        func_8004B6C4(0x000000FF, 0x000000FF, 0x000000FF);
        for (var_s0 = 0; var_s0 < D_8018D1F0; var_s0++) {
            objectIndex = D_8018CC80[arg1 + var_s0];
            object = &gObjectList[objectIndex];
            func_800518F8(objectIndex, object->unk_09C, (var_s5 - object->unk_09E) / 2);
        }
    }
}

void func_80051EBC(void) {
    func_80051ABC(240 - D_800DC5EC->cameraHeight, 0); // 28
}

void func_80051EF8(void) {
    s16 temp_a0;

    temp_a0 = 0xF0 - D_800DC5EC->cameraHeight;
    if (gCurrentCourseId == COURSE_KOOPA_BEACH) {
        temp_a0 = temp_a0 - 0x30;
    } else if (gCurrentCourseId == COURSE_MOO_MOO_FARM) {
        temp_a0 = temp_a0 - 0x40;
    } else if (gCurrentCourseId == COURSE_YOSHI_VALLEY) {
        temp_a0 = temp_a0 - 0x40;
    } else {
        temp_a0 = temp_a0 - 0x30;
    }
    func_80051ABC(temp_a0, 0);
}

void func_80051F9C(void) {
    s16 temp_a0;

    temp_a0 = 0xF0 - D_800DC5F0->cameraHeight;
    if (gCurrentCourseId == COURSE_KOOPA_BEACH) {
        temp_a0 = temp_a0 - 0x30;
    } else if (gCurrentCourseId == COURSE_MOO_MOO_FARM) {
        temp_a0 = temp_a0 - 0x40;
    } else if (gCurrentCourseId == COURSE_YOSHI_VALLEY) {
        temp_a0 = temp_a0 - 0x40;
    } else {
        temp_a0 = temp_a0 - 0x30;
    }
    func_80051ABC(temp_a0, D_8018D1F0);
}

void func_80052044(void) {
    func_80051C60(240 - D_800DC5EC->cameraHeight, 0);
}

void func_80052080(void) {
    func_80051C60(240 - D_800DC5F0->cameraHeight, D_8018D1F0);
}

void func_800520C0(s32 arg0) {
    if (gObjectList[arg0].unk_0D5 == 0) {
        D_800E45C0[0].l[0].l.dir[0] = D_800E45C0[1].l[0].l.dir[0] = D_800E45C0[2].l[0].l.dir[0] = D_800E45C0[3].l[0].l.dir[0] = 0;
        D_800E45C0[0].l[0].l.dir[1] = D_800E45C0[1].l[0].l.dir[1] = D_800E45C0[2].l[0].l.dir[1] = D_800E45C0[3].l[0].l.dir[1] = -0x78;
        D_800E45C0[0].l[0].l.dir[2] = D_800E45C0[1].l[0].l.dir[2] = D_800E45C0[2].l[0].l.dir[2] = D_800E45C0[3].l[0].l.dir[2] = 0;
    } else {
        D_800E45C0[0].l[0].l.dir[0] = D_800E45C0[1].l[0].l.dir[0] = D_800E45C0[2].l[0].l.dir[0] = D_800E45C0[3].l[0].l.dir[0] = 0x63;
        D_800E45C0[0].l[0].l.dir[1] = D_800E45C0[1].l[0].l.dir[1] = D_800E45C0[2].l[0].l.dir[1] = D_800E45C0[3].l[0].l.dir[1] = 0x42;
        D_800E45C0[0].l[0].l.dir[2] = D_800E45C0[1].l[0].l.dir[2] = D_800E45C0[2].l[0].l.dir[2] = D_800E45C0[3].l[0].l.dir[2] = 0;
    }
}

void func_8005217C(s32 arg0) {
    Objects *object;
    s32 temp_a3;

    temp_a3 = indexObjectList2[0];
    object = &gObjectList[temp_a3];
    if (object->state >= 2) {
        if (is_obj_index_flag_unk_054_active(temp_a3, 0x00000010) != 0) {
            rsp_set_matrix_transformation(object->pos, object->direction_angle, object->sizeScaling);
            func_800520C0(temp_a3);

            gSPDisplayList(gDisplayListHead++, D_0D007828);
            gSPLight(gDisplayListHead++, &D_800E45C0[0].l[0], LIGHT_1);
            gSPLight(gDisplayListHead++, &D_800E45C0[0].a, LIGHT_2);
            gSPDisplayList(gDisplayListHead++, d_course_banshee_boardwalk_dl_7B38);
            gSPLight(gDisplayListHead++, &D_800E45C0[1].l[0], LIGHT_1);
            gSPLight(gDisplayListHead++, &D_800E45C0[1].a, LIGHT_2);
            gSPDisplayList(gDisplayListHead++, d_course_banshee_boardwalk_dl_7978);
            gSPLight(gDisplayListHead++, &D_800E45C0[2].l[0], LIGHT_1);
            gSPLight(gDisplayListHead++, &D_800E45C0[2].a, LIGHT_2);
            gSPDisplayList(gDisplayListHead++, d_course_banshee_boardwalk_dl_78C0);
            gSPLight(gDisplayListHead++, &D_800E45C0[3].l[0], LIGHT_1);
            gSPLight(gDisplayListHead++, &D_800E45C0[3].a, LIGHT_2);
            gSPDisplayList(gDisplayListHead++, d_course_banshee_boardwalk_dl_7650);
        }
    }
}

void func_800523B8(s32 objectIndex, s32 arg1, u32 arg2) {
    UNUSED s32 pad[2];
    Objects *object;
    Camera *camera = &camera1[arg1];

    object = &gObjectList[objectIndex];
    object->orientation[1] = func_800418AC(object->pos[0], object->pos[2], camera->pos);
    func_800484BC(object->pos, object->orientation, object->sizeScaling, object->unk_0A0, (u8 *) object->activeTLUT, object->activeTexture, object->vertex, 0x00000030, 0x00000028, 0x00000030, 0x00000028);
    if ((is_obj_index_flag_unk_054_active(objectIndex, 0x00000020) != 0) && (arg2 < 0x15F91U)) {
        func_8004A630(&D_8018C830, object->pos, 0.4f);
    }
}

void func_800524B4(s32 arg0) {
    u32 temp_s2;
    s32 someIndex;
    s32 objectIndex;

    for (someIndex = 0; someIndex < 10; someIndex++) {
        objectIndex = indexObjectList3[someIndex];
        if (gObjectList[objectIndex].state >= 2) {
            temp_s2 = func_8008A364(objectIndex, arg0, 0x4000U, 0x00000320);
            if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
                func_800523B8(objectIndex, arg0, temp_s2);
            }
        }
    }
}

void func_80052590(s32 cameraId) {
    s32 var_s2;
    s32 objectIndex;
    Camera *temp_s7;

    objectIndex = indexObjectList1[0];
    temp_s7 = &camera1[cameraId];
    func_80046F60(gObjectList[objectIndex].activeTLUT, gObjectList[objectIndex].activeTexture, 0x00000020, 0x00000040, 5);
    D_80183E80[0] = gObjectList[objectIndex].orientation[0];
    D_80183E80[2] = gObjectList[objectIndex].orientation[2];
    if ((D_8018CFB0 != 0) || (D_8018CFC8 != 0)) {
        for (var_s2 = 0; var_s2 < 40; var_s2++) {
            objectIndex = gObjectParticle2[var_s2];
            if (objectIndex == -1) continue;

            if ((gObjectList[objectIndex].state >= 2) && (gMatrixHudCount < 0x2EF)) {
                D_80183E80[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], temp_s7->pos);
                func_800431B0(gObjectList[objectIndex].pos, D_80183E80, gObjectList[objectIndex].sizeScaling, D_0D0062B0);
            }
        }
    }
    if ((D_8018CFE8 != 0) || (D_8018D000 != 0)) {
        for (var_s2 = 0; var_s2 < 30; var_s2++) {
            objectIndex = gObjectParticle3[var_s2];
            if (objectIndex == -1) continue;

            if ((gObjectList[objectIndex].state >= 2) && (gMatrixHudCount < 0x2EF)) {
                D_80183E80[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], temp_s7->pos);
                func_800431B0(gObjectList[objectIndex].pos, D_80183E80, gObjectList[objectIndex].sizeScaling, D_0D0062B0);
            }
        }
    }
    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800527D8(s32 cameraId) {
    s32 objectIndex;
    Objects *object;

    objectIndex = indexObjectList1[1];
    func_8008A364(objectIndex, cameraId, 0x5555U, 0x00000320);
    if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
        object = &gObjectList[objectIndex];
        if (object->state >= 2) {
            func_80043220(object->pos, object->orientation, object->sizeScaling, object->model);
        }
    }
}

void func_8005285C(s32 arg0) {
    Player *temp_v0;

    temp_v0 = &gPlayerOne[arg0];
    D_80183E40[0] = temp_v0->pos[0];
    D_80183E40[1] = temp_v0->pos[1];
    D_80183E40[2] = temp_v0->pos[2];
    D_80183E80[0] = 0;
    D_80183E80[1] = 0;
    D_80183E80[2] = 0;
    func_80043500(D_80183E40, D_80183E80, 0.02f, d_course_sherbet_land_dl_ice_block);
}

void func_800528EC(s32 arg0) {
    s32 var_s3;
    s32 objectIndex;
    Objects *object;

    D_80183E80[0] = D_8016582C[0];
    D_80183E80[1] = D_8016582C[1];
    D_80183E80[2] = D_8016582C[2];
    gSPDisplayList(gDisplayListHead++, D_0D007B00);
    gSPNumLights(gDisplayListHead++, 1);
    gSPLight(gDisplayListHead++, &D_800E4620.l[0], LIGHT_1);
    gSPLight(gDisplayListHead++, &D_800E4620.a, LIGHT_2);
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    func_800441E0(d_course_sherbet_land_ice, 0x00000020, 0x00000020);
    if (gPlayerCountSelection1 < 3) {
        for (var_s3 = 0; var_s3 < gObjectParticle2_SIZE; var_s3++) {
            objectIndex = gObjectParticle2[var_s3];
            if (objectIndex != -1) {
                object = &gObjectList[objectIndex];
                if (object->state > 0) {
                    rsp_set_matrix_transformation(object->pos, D_80183E80, object->sizeScaling);
                    gSPVertex(gDisplayListHead++, D_0D005BD0, 3, 0);
                    gSPDisplayList(gDisplayListHead++, D_0D006930);
                }
            }
        }
    } else {
        for (var_s3 = 0; var_s3 < gObjectParticle2_SIZE; var_s3++) {
            objectIndex = gObjectParticle2[var_s3];
            if (objectIndex != -1) {
                object = &gObjectList[objectIndex];
                if ((object->state > 0) && (arg0 == object->unk_084[7]) && (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX)) {
                    rsp_set_matrix_transformation(object->pos, D_80183E80, object->sizeScaling);
                    gSPVertex(gDisplayListHead++, D_0D005BD0, 3, 0);
                    gSPDisplayList(gDisplayListHead++, D_0D006930);
                }
            }
        }
    }
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
    gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);
    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80052C60(s32 arg0) {
    s32 playerId;
    s32 objectIndex;

    D_800E4620.l[0].l.dir[0] = D_80165840[0];
    D_800E4620.l[0].l.dir[1] = D_80165840[1];
    D_800E4620.l[0].l.dir[2] = D_80165840[2];
    gSPLight(gDisplayListHead++, &D_800E4620.l[0], LIGHT_1);
    gSPLight(gDisplayListHead++, &D_800E4620.a, LIGHT_2);
    for (playerId = 0; playerId < gPlayerCountSelection1; playerId++) {
        objectIndex = gIndexLakituList[playerId];
        if (objectIndex) {}
        if (func_80072320(objectIndex, 4) != 0) {
            func_8005285C(playerId);
        }
        func_80072320(objectIndex, 0x00000010);
    }
    func_800528EC(arg0);
}

void func_80052D70(s32 playerId) {
    s32 test;
    Player *temp_v1;

    temp_v1 = &gPlayerOne[playerId];
    test = gIndexLakituList[playerId];
    if (func_80072320(test, 8) != 0) {
        D_80183E40[0] = temp_v1->pos[0];
        D_80183E40[1] = temp_v1->unk_074 - 6.5;
        D_80183E40[2] = temp_v1->pos[2];
        func_800435A0(D_80183E40, (u16 *) D_80183E80, 0.02f, d_course_sherbet_land_dl_ice_block, 0x000000FF);
    }
}

void func_80052E30(s32 arg0) {
    s32 var_s0;

    D_800E4620.l[0].l.dir[0] = D_80165840[0];
    D_800E4620.l[0].l.dir[1] = D_80165840[1];
    D_800E4620.l[0].l.dir[2] = D_80165840[2];
    gSPLight(gDisplayListHead++, &D_800E4620.l[0], LIGHT_1);
    gSPLight(gDisplayListHead++, &D_800E4620.a, LIGHT_2);
    D_80183E80[0] = 0;
    D_80183E80[1] = 0;
    D_80183E80[2] = 0;
    if (gPlayerCount == 1) {
        for (var_s0 = 0; var_s0 < gPlayerCountSelection1; var_s0++) {
            func_80052D70(var_s0);
        }
    }
}

void func_80052F20(s32 cameraId) {
    s32 stackPadding[2];
    Camera *sp44;
    s32 someIndex;
    s32 objectIndex;
    Objects *object;

    sp44 = &camera1[cameraId];
    func_80046E60(d_course_frappe_snowland_snow_tlut, d_course_frappe_snowland_snow, 0x00000020, 0x00000020);
    for (someIndex = 0; someIndex < gObjectParticle2_SIZE; someIndex++) {
        objectIndex = gObjectParticle2[someIndex];
        if (objectIndex != -1) {
            object = &gObjectList[objectIndex];
            if (object->state > 0) {
                func_8008A364(objectIndex, cameraId, 0x2AABU, 0x000001F4);
                if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
                    object->orientation[1] = func_800418AC(object->pos[0], object->pos[2], sp44->pos);
                    rsp_set_matrix_gObjectList(objectIndex);
                    gSPDisplayList(gDisplayListHead++, D_0D0069E0);
                }
            }
        }
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_8005309C(s32 cameraId) {
    s32 var_s4;
    s32 objectIndex;
    Camera *camera;

    camera = &camera1[cameraId];
    for (var_s4 = 0; var_s4 < 0x13; var_s4++) {
        objectIndex = indexObjectList1[var_s4];
        if (gObjectList[objectIndex].state >= 2) {
            func_8008A364(objectIndex, cameraId, 0x2AABU, 0x00000258);
            if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
                D_80183E80[0] = (s16) gObjectList[objectIndex].orientation[0];
                D_80183E80[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], camera->pos);
                D_80183E80[2] = (u16) gObjectList[objectIndex].orientation[2];
                if (is_obj_index_flag_unk_054_active(objectIndex, 0x00000010) != 0) {
                    func_800480B4(gObjectList[objectIndex].pos, (u16 *) D_80183E80, gObjectList[objectIndex].sizeScaling, (u8 *) gObjectList[objectIndex].activeTLUT, gObjectList[objectIndex].activeTexture, gObjectList[objectIndex].vertex, 0x00000040, 0x00000040, 0x00000040, 0x00000020);
                }
                objectIndex = indexObjectList2[var_s4];
                D_80183E80[0] = (s16) gObjectList[objectIndex].orientation[0];
                D_80183E80[2] = (u16) gObjectList[objectIndex].orientation[2];
                func_800480B4(gObjectList[objectIndex].pos, (u16 *) D_80183E80, gObjectList[objectIndex].sizeScaling, (u8 *) gObjectList[objectIndex].activeTLUT, gObjectList[objectIndex].activeTexture, gObjectList[objectIndex].vertex, 0x00000040, 0x00000040, 0x00000040, 0x00000020);
            }
        }
    }
}

void func_8005327C(s32 arg0) {
    func_8005309C(arg0);
    func_80052F20(arg0);
}

void func_800532A4(s32 cameraId) {
    s32 stackPadding;
    Camera *camera;
    f32 var_f0;
    f32 var_f2;
    s32 objectIndex;
    Objects *object;

    objectIndex = gIndexLakituList[cameraId];
    camera = &camera1[cameraId];
    if (is_obj_index_flag_unk_054_active(objectIndex, 0x00000010) != 0) {
        object = &gObjectList[objectIndex];
        object->orientation[0] = 0;
        object->orientation[1] = func_800418AC(object->pos[0], object->pos[2], camera->pos);
        object->orientation[2] = 0x8000;
        if (func_80072354(objectIndex, 2) != 0) {
            func_800480B4(object->pos, object->orientation, object->sizeScaling, (u8 *) object->activeTLUT, object->activeTexture, object->vertex, (s32) object->textureWidth, (s32) object->textureHeight, (s32) object->textureWidth, (s32) object->textureHeight / 2);
        } else {
            func_800485C4(object->pos, object->orientation, object->sizeScaling, (s32) object->unk_0A0, (u8 *) object->activeTLUT, object->activeTexture, object->vertex, (s32) object->textureWidth, (s32) object->textureHeight, (s32) object->textureWidth, (s32) object->textureHeight / 2);
        }
        if (gScreenModeSelection == SCREEN_MODE_1P) {
            var_f0 = object->pos[0] - D_8018CF14->pos[0];
            var_f2 = object->pos[2] - D_8018CF14->pos[2];
            if (var_f0 < 0.0f) {
                var_f0 = -var_f0;
            }
            if (var_f2 < 0.0f) {
                var_f2 = -var_f2;
            }
            if ((var_f0 + var_f2) <= 200.0) {
                func_8004A630(&D_8018C0B0[cameraId], object->pos, 0.35f);
            }
        }
    }
}

void func_800534A4(s32 arg0) {
    func_800419F8();
    D_800E4638.l[0].l.dir[0] = D_80165840[0];
    D_800E4638.l[0].l.dir[1] = D_80165840[1];
    D_800E4638.l[0].l.dir[2] = D_80165840[2];
}

void func_800534E8(s32 objectIndex) {
    // Why these don't just use `gSPSetLights1` calls...
    switch (gObjectList[objectIndex].type) { // hmm very strange 80165C18
    case 0:
        gSPLight(gDisplayListHead++, &D_800E4638.l[0], LIGHT_1);
        gSPLight(gDisplayListHead++, &D_800E4638.a, LIGHT_2);
        break;
    case 1:
        gSPLight(gDisplayListHead++, &D_800E4650.l[0], LIGHT_1);
        gSPLight(gDisplayListHead++, &D_800E4650.a, LIGHT_2);
        break;
    case 2:
        gSPLight(gDisplayListHead++, &D_800E4668.l[0], LIGHT_1);
        gSPLight(gDisplayListHead++, &D_800E4668.a, LIGHT_2);
        break;
    case 3:
        gSPLight(gDisplayListHead++, &D_800E4680.l[0], LIGHT_1);
        gSPLight(gDisplayListHead++, &D_800E4680.a, LIGHT_2);
        break;
    case 4:
        gSPLight(gDisplayListHead++, &D_800E4698.l[0], LIGHT_1);
        gSPLight(gDisplayListHead++, &D_800E4698.a, LIGHT_2);
        break;
    default:
        break;
    }
}

void func_800536C8(s32 objectIndex) {
    if ((gObjectList[objectIndex].state >= 2) && (func_80072354(objectIndex, 0x00000040) != 0)) {
        func_8004A7AC(objectIndex, 1.75f);
        rsp_set_matrix_transformation(gObjectList[objectIndex].pos, gObjectList[objectIndex].orientation, gObjectList[objectIndex].sizeScaling);
        func_800534E8(objectIndex);
        gSPDisplayList(gDisplayListHead++, D_0D007828);
        gDPSetTextureLUT(gDisplayListHead++, G_TT_RGBA16);
        gDPLoadTLUT_pal256(gDisplayListHead++, d_course_bowsers_castle_thwomp_tlut);
        rsp_load_texture_mask(gObjectList[objectIndex].activeTexture, 0x00000010, 0x00000040, 4);
        gSPDisplayList(gDisplayListHead++, gObjectList[objectIndex].model);
    }
}

void func_80053870(s32 cameraId) {
    s32 temp_s1;
    s32 var_s2;
    s32 stackPadding0;
    s16 minusone, plusone;
    Camera *camera;
    Objects *object;

    camera = &camera1[cameraId];
    if (cameraId == 0) {
        for (var_s2 = 0; var_s2 < gNumActiveThwomps; var_s2++) {
            temp_s1 = indexObjectList1[var_s2];
            set_object_flag_unk_054_false(temp_s1, 0x00070000);
            func_800722CC(temp_s1, 0x00000110);
        }
    }
    func_800534A4(temp_s1);
    for (var_s2 = 0; var_s2 < gNumActiveThwomps; var_s2++) {
        temp_s1 = indexObjectList1[var_s2];
        minusone = gObjectList[temp_s1].unk_0DF - 1;
        plusone = gObjectList[temp_s1].unk_0DF + 1;
        if (gGamestate != 9) {
            if ((D_8018CF68[cameraId] >= minusone) && (plusone >= D_8018CF68[cameraId]) && (func_8008A140(temp_s1, camera, 0x8000U) != 0)) {
                func_800536C8(temp_s1);
            }
        } else {
            func_800536C8(temp_s1);
        }
    }
    gSPDisplayList(gDisplayListHead++, D_0D0079C8);
    gDPSetCombineMode(gDisplayListHead++, G_CC_MODULATEIA, G_CC_MODULATEIA);
    gSPNumLights(gDisplayListHead++, 1);
    gSPLight(gDisplayListHead++, &D_800E4668.l[0], LIGHT_1);
    gSPLight(gDisplayListHead++, &D_800E4668.a, LIGHT_2);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    gSPSetGeometryMode(gDisplayListHead++, G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    func_80043D50(d_course_bowsers_castle_thwomp_side, 0x00000020, 0x00000020);
    for (var_s2 = 0; var_s2 < gObjectParticle3_SIZE; var_s2++) {
        temp_s1 = gObjectParticle3[var_s2];
        if (temp_s1 != -1) {
            object = &gObjectList[temp_s1];
            if ((object->state > 0) && (object->unk_0D5 == 3) && (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX)) {
                rsp_set_matrix_transformation(object->pos, object->orientation, object->sizeScaling);
                gSPVertex(gDisplayListHead++, D_0D005C00, 3, 0);
                gSPDisplayList(gDisplayListHead++, D_0D006930);
            }
        }
    }
    gSPSetGeometryMode(gDisplayListHead++, G_CULL_BACK);
    gSPClearGeometryMode(gDisplayListHead++, G_LIGHTING);
    gSPTexture(gDisplayListHead++, 0x0001, 0x0001, 0, G_TX_RENDERTILE, G_OFF);
    gSPDisplayList(gDisplayListHead++, D_0D007AE0);
    func_800444B0(D_8018D490, 0x00000020, 0x00000020);
    func_8004B3C8(0);
    D_80183E80[0] = 0;
    D_80183E80[2] = 0x8000;
    for (var_s2 = 0; var_s2 < gObjectParticle2_SIZE; var_s2++) {
        temp_s1 = gObjectParticle2[var_s2];
        if (temp_s1 != -1) {
            object = &gObjectList[temp_s1];
            if ((object->state >= 2) && (object->unk_0D5 == 2) && (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX)) {
                func_8004B138(0x000000FF, 0x000000FF, 0x000000FF, (s32) object->unk_0A0);
                D_80183E80[1] = func_800418AC(object->pos[0], object->pos[2], camera->pos);
                func_800431B0(object->pos, D_80183E80, object->sizeScaling, D_0D005AE0);
            }
        }
    }
}

void func_80053D74(s32 objectIndex, UNUSED s32 arg1, s32 vertexIndex) {
    Objects *temp_v0;

    if (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX) {
        temp_v0 = &gObjectList[objectIndex];
        D_80183E80[2] = (s16) (temp_v0->unk_084[6] + 0x8000);
        rsp_set_matrix_transformation(temp_v0->pos, (u16 *) D_80183E80, temp_v0->sizeScaling);
        func_8004B1C8((s32) temp_v0->unk_084[0], (s32) temp_v0->unk_084[1], (s32) temp_v0->unk_084[2], (s32) temp_v0->unk_084[3], (s32) temp_v0->unk_084[4], (s32) temp_v0->unk_084[5], (s32) temp_v0->unk_0A0);
        gSPVertex(gDisplayListHead++, &D_0D0060B0[vertexIndex], 4, 0);
        gSPDisplayList(gDisplayListHead++, common_rectangle_display);
    }
}

void func_80053E6C(s32 arg0) {
    s32 var_s1;
    s32 objectIndex;

    gSPDisplayList(gDisplayListHead++, D_0D007E98);
    gDPLoadTLUT_pal256(gDisplayListHead++, D_800E52D0);
    func_8004B614(0, 0, 0, 0, 0, 0, 0);
    D_80183E80[0] = 0;
    D_80183E80[1] = 0x8000;
    rsp_load_texture(D_8018D4BC, 0x40, 0x20);
    for (var_s1 = 0; var_s1 < D_80165738; var_s1++) {
        objectIndex = gObjectParticle3[var_s1];
        if ((objectIndex != -1) && (gObjectList[objectIndex].state >= 2)) {
            func_80053D74(objectIndex, arg0, 0);
        }
    }
    rsp_load_texture(D_8018D4C0, 0x40, 0x20);
    for (var_s1 = 0; var_s1 < D_80165738; var_s1++) {
        objectIndex = gObjectParticle3[var_s1];
        if ((objectIndex != -1) && (gObjectList[objectIndex].state >= 2)) {
            func_80053D74(objectIndex, arg0, 4);
        }
    }
}


void func_800540CC(s32 objectIndex, s32 cameraId) {
    Camera *camera;

    camera = &camera1[cameraId];
    if (objectIndex != -1) {
        if ((gObjectList[objectIndex].state >= 2) && (gObjectList[objectIndex].unk_0D5 == 1) && (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX)) {
            func_8004B1C8((s32) gObjectList[objectIndex].type, (s32) gObjectList[objectIndex].type, (s32) gObjectList[objectIndex].type, 0, 0, 0, (s32) gObjectList[objectIndex].unk_0A0);
            D_80183E80[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], camera->pos);
            func_800431B0(gObjectList[objectIndex].pos, D_80183E80, gObjectList[objectIndex].sizeScaling, D_0D005AE0);
        }
    }
}

// Train smoke?
void func_800541BC(s32 cameraId) {
    s32 pad;
    s32 j;
    Camera *camera;
    s32 i;

    camera = &camera1[cameraId];
    gSPDisplayList(gDisplayListHead++, D_0D007AE0);
    func_8004477C(D_0D029458, 32, 32);
    func_8004B72C(255, 255, 255, 255, 255, 255, 255);
    D_80183E80[0] = 0;
    D_80183E80[2] = 0x8000;

// Render smoke for any number of trains. Don't know enough about these variables yet.
#ifdef AVOID_UB_WIP
    for (j = 0; j < NUM_TRAINS; j++) {
        if ((gTrainList[j].someFlags != 0) && (func_80041980(&gTrainList[j].locomotive.position, camera, 0x4000U) != 0)) {

            for (i = 0; i < 128; i++) {
                // Need to make a way to increase this array for each train.
                func_800540CC(gObjectParticle2[i], cameraId);
            }
        }
    }
#else

    if ((gTrainList[0].someFlags != 0) && (func_80041980(&gTrainList[0].locomotive.position, camera, 0x4000U) != 0)) {

        for (i = 0; i < gObjectParticle2_SIZE; i++) {
            func_800540CC(gObjectParticle2[i], cameraId);
        }

    }
    if ((gTrainList[1].someFlags != 0) && (func_80041980(&gTrainList[1].locomotive.position, camera, 0x4000U) != 0)) {
        for (i = 0; i < gObjectParticle3_SIZE; i++) {
            func_800540CC(gObjectParticle3[i], cameraId);
        }
    }
#endif
}

void func_80054324(s32 objectIndex, s32 cameraId) {
    Camera *camera;

    camera = &camera1[cameraId];
    if (objectIndex != -1) {
        if ((gObjectList[objectIndex].state >= 2) && (gObjectList[objectIndex].unk_0D5 == 6) && (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX)) {
            func_8004B1C8((s32) gObjectList[objectIndex].type, (s32) gObjectList[objectIndex].type, (s32) gObjectList[objectIndex].type, gObjectList[objectIndex].unk_0A2, gObjectList[objectIndex].unk_0A2, gObjectList[objectIndex].unk_0A2, (s32) gObjectList[objectIndex].unk_0A0);
            D_80183E80[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], camera->pos);
            func_800431B0(gObjectList[objectIndex].pos, D_80183E80, gObjectList[objectIndex].sizeScaling, D_0D005AE0);
        }
    }
}

// Likely smoke related.
void func_80054414(s32 cameraId) {
    s32 pad[2];
    Camera *camera;
    s32 i;
 
    camera = &camera1[cameraId];
    gSPDisplayList(gDisplayListHead++, D_0D007AE0);

    func_8004477C(D_0D029458, 32, 32);
    func_8004B72C(255, 255, 255, 255, 255, 255, 255);
    D_80183E80[0] = 0;
    D_80183E80[2] = 0x8000;
    if ((gFerries[0].someFlags != 0) && (func_80041980(gFerries[0].position, camera, 0x4000U) != 0)) {
        for (i = 0; i < gObjectParticle2_SIZE; i++) {
            func_80054324(gObjectParticle2[i], cameraId);
        }
    }
    if ((gFerries[1].someFlags != 0) && (func_80041980(gFerries[1].position, camera, 0x4000U) != 0)) {
        for (i = 0; i < gObjectParticle3_SIZE; i++) {
            func_80054324(gObjectParticle3[i], cameraId);
        }
    }
}

void func_8005457C(s32 objectIndex, s32 cameraId) {
    Camera *camera;
    Objects *temp_s0;

    camera = &camera1[cameraId];
    if (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX) {
        temp_s0 = &gObjectList[objectIndex];
        if (temp_s0->unk_0D5 == 9) {
            func_8004B72C(255, (s32) temp_s0->type, 0, (s32) temp_s0->unk_0A2, 0, 0, (s32) temp_s0->unk_0A0);
        } else {
            func_8004B138(255, (s32) temp_s0->type, 0, (s32) temp_s0->unk_0A0);
        }
        D_80183E80[1] = func_800418AC(temp_s0->pos[0], temp_s0->pos[2], camera->pos);
        func_800431B0(temp_s0->pos, D_80183E80, temp_s0->sizeScaling, D_0D005AE0);
    }
}

void func_80054664(s32 cameraId) {
    s32 var_s0;
    s32 objectIndex;

    gSPDisplayList(gDisplayListHead++, D_0D007AE0);
    func_8004477C(common_texture_particle_smoke[D_80165598], 0x00000020, 0x00000020);
    func_8004B414(0, 0, 0, 0x000000FF);
    D_80183E80[0] = 0;
    D_80183E80[2] = 0x8000;
    for (var_s0 = 0; var_s0 < gObjectParticle1_SIZE; var_s0++) {
        objectIndex = gObjectParticle1[var_s0];
        if ((objectIndex != -1) && (gObjectList[objectIndex].state >= 3)) {
            func_8005457C(objectIndex, cameraId);
        }
    }
}

void func_8005477C(s32 objectIndex, u8 arg1, Vec3f arg2) {
    if (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX) {
        switch (arg1) {                          /* irregular */
        case 0:
            func_8004B1C8(0x000000E6, 0x000000FF, 0x000000FF, 0, 0, 0x000000FF, (s32) gObjectList[objectIndex].unk_0A0);
            break;
        case 1:
            func_8004B1C8(0x000000FF, 0x000000FF, 0x00000096, 0x000000FF, 0, 0, (s32) gObjectList[objectIndex].unk_0A0);
            break;
        case 2:
            func_8004B1C8(0x000000FF, 0x000000E6, 0x000000FF, 0x000000FF, 0, 0x00000096, (s32) gObjectList[objectIndex].unk_0A0);
            break;
        case 3:
            func_8004B1C8(0x000000FF, 0x000000FF, 0x0000001E, 0x000000FF, 0, 0, (s32) gObjectList[objectIndex].unk_0A0);
            break;
        default:
            break;
        }
        D_80183E80[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], arg2);
        func_800431B0(gObjectList[objectIndex].pos, D_80183E80, gObjectList[objectIndex].sizeScaling, D_0D005AE0);
    }
}

void func_80054938(s32 cameraId) {
    s32 stackPadding[2];
    Camera *sp54;
    s32 var_s0;
    s32 objectIndex;
    Objects *object;

    sp54 = &camera1[cameraId];
    gSPDisplayList(gDisplayListHead++, D_0D007AE0);
    func_8004477C(common_texture_particle_smoke[D_80165598], 32, 32);
    func_8004B72C(255, 255, 255, 255, 255, 255, 255);
    D_80183E80[0] = 0;
    D_80183E80[2] = 0x8000;
    for (var_s0 = 0; var_s0 < gObjectParticle4_SIZE; var_s0++) {
        objectIndex = gObjectParticle4[var_s0];
        if (objectIndex != -1) {
            object = &gObjectList[objectIndex];
            if (object->state >= 2) {
                if (object->unk_0D8 == 3) {
                    func_8008A364(objectIndex, cameraId, 0x4000U, 0x00000514);
                } else {
                    func_8008A364(objectIndex, cameraId, 0x4000U, 0x000001F4);
                }
                if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
                    func_8005477C(objectIndex, object->unk_0D8, sp54->pos);
                }
            }
        }
    }
}

void func_80054AFC(s32 objectIndex, Vec3f arg1) {
    D_80183E80[0] = func_800418E8(gObjectList[objectIndex].pos[2], gObjectList[objectIndex].pos[1], arg1);
    D_80183E80[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], arg1);
    D_80183E80[2] = (u16) gObjectList[objectIndex].orientation[2];
    func_8004B138((s32) gObjectList[objectIndex].unk_084[0], (s32) gObjectList[objectIndex].unk_084[1], (s32) gObjectList[objectIndex].unk_084[2], (s32) gObjectList[objectIndex].unk_0A0);
    rsp_set_matrix_transformation(gObjectList[objectIndex].pos, (u16 *) D_80183E80, gObjectList[objectIndex].sizeScaling);
    gSPVertex(gDisplayListHead++, D_0D005AE0, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
}

void func_80054BE8(s32 cameraId) {
    s32 var_s0;
    s32 temp_a0;
    Camera *camera;

    camera = &camera1[cameraId];
    gSPDisplayList(gDisplayListHead++, D_0D007AE0);
    func_800444B0(D_8018D488, 0x00000020, 0x00000020);
    func_8004B35C(0x000000FF, 0x000000FF, 0, 0x000000FF);
    D_80183E80[0] = 0;
    for (var_s0 = 0; var_s0 < gObjectParticle3_SIZE; var_s0++) {
        temp_a0 = gObjectParticle3[var_s0];
        if ((temp_a0 != -1) && (gObjectList[temp_a0].state >= 2)) {
            func_80054AFC(temp_a0, camera->pos);
        }
    }
}

void func_80054D00(s32 objectIndex, s32 cameraId) {
    Camera *camera;

    camera = &camera1[cameraId];
    if (gObjectList[objectIndex].state >= 3) {
        func_8008A364(objectIndex, cameraId, 0x2AABU, 0x0000012C);
        if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
            D_80183E80[0] = (s16) gObjectList[objectIndex].orientation[0];
            D_80183E80[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], camera->pos);
            D_80183E80[2] = (u16) gObjectList[objectIndex].orientation[2];
            func_80048130(gObjectList[objectIndex].pos, (u16 *) D_80183E80, gObjectList[objectIndex].sizeScaling, (u8 *) gObjectList[objectIndex].activeTLUT, gObjectList[objectIndex].activeTexture, D_0D0062B0, 0x00000020, 0x00000040, 0x00000020, 0x00000040, 5);
        }
    }
}

void func_80054E10(s32 objectIndex) {
    if (gObjectList[objectIndex].state > 0) {
        if (is_obj_index_flag_unk_054_active(objectIndex, 0x00800000) != 0) {
            D_80183E50[0] = gObjectList[objectIndex].pos[0];
            D_80183E50[1] = gObjectList[objectIndex].unk_044 + 0.8;
            D_80183E50[2] = gObjectList[objectIndex].pos[2];
            D_80183E70[0] = gObjectList[objectIndex].velocity[0];
            D_80183E70[1] = gObjectList[objectIndex].velocity[1];
            D_80183E70[2] = gObjectList[objectIndex].velocity[2];
            func_8004A9B8(gObjectList[objectIndex].sizeScaling);
        }
    }
}

// Almost certainly responsible for spawning/handling the moles on Moo Moo farm
void func_80054EB8(UNUSED s32 unused) {
    s32 someIndex;

    for (someIndex = 0; someIndex < NUM_MAX_MOLES; someIndex++) {
        func_80054E10(gObjectParticle1[someIndex]);
    }
}

void func_80054F04(s32 cameraId) {
    s32 var_s2;
    s32 objectIndex;
    Camera *sp44;
    Objects * object;

    sp44 = &camera1[cameraId];
    gSPDisplayList(gDisplayListHead++, D_0D0079C8);
    func_80043D50(d_course_moo_moo_farm_mole_dirt, 0x00000010, 0x00000010);
    for (var_s2 = 0; var_s2 < gObjectParticle2_SIZE; var_s2++) {
        objectIndex = gObjectParticle2[var_s2];
        object = &gObjectList[objectIndex];
        if (object->state > 0) {
            func_8008A364(objectIndex, cameraId, 0x2AABU, 0x000000C8);
            if ((is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) && (gMatrixHudCount <= MTX_HUD_POOL_SIZE_MAX)) {
                object->orientation[1] = func_800418AC(object->pos[0], object->pos[2], sp44->pos);
                rsp_set_matrix_gObjectList(objectIndex);
                gSPDisplayList(gDisplayListHead++, D_0D006980);
            }
        }
    }
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800550A4(s32 arg0) {
    s32 var_s0;

    for (var_s0 = 0; var_s0 < 8; var_s0++) {
        func_80054D00(indexObjectList1[var_s0], arg0);
    }
    for (var_s0 = 0; var_s0 < 11; var_s0++) {
        func_80054D00(indexObjectList2[var_s0], arg0);
    }
    for (var_s0 = 0; var_s0 < 12; var_s0++) {
        func_80054D00(indexObjectList3[var_s0], arg0);
    }
    func_80054EB8(arg0);
    func_80054F04(arg0);
}

void func_80055164(s32 objectIndex) {
    if (gObjectList[objectIndex].state >= 2) {
        gSPDisplayList(gDisplayListHead++, D_0D0077A0);
        rsp_set_matrix_transformation(gObjectList[objectIndex].pos, gObjectList[objectIndex].direction_angle, gObjectList[objectIndex].sizeScaling);
        if (gIsGamePaused == 0) {
            gObjectList[objectIndex].unk_0A2 = func_80004DFC((animation_type_1 *) gObjectList[objectIndex].model, (animation_type_2 **) gObjectList[objectIndex].vertex, 0, gObjectList[objectIndex].unk_0A2);
        } else {
            func_80004DFC((animation_type_1 *) gObjectList[objectIndex].model, (animation_type_2 **) gObjectList[objectIndex].vertex, 0, gObjectList[objectIndex].unk_0A2);
        }
    }
}

void func_80055228(s32 cameraId) {
    s32 var_s1;
    s32 temp_s0;

    for (var_s1 = 0; var_s1 < 4; var_s1++) {
        temp_s0 = indexObjectList1[var_s1];
        func_8008A364(temp_s0, cameraId, 0x4000U, 0x000005DC);
        if (is_obj_index_flag_unk_054_active(temp_s0, 0x00040000) != 0) {
            func_80055164(temp_s0);
        }
    }
}

void func_800552BC(s32 objectIndex) {
    if (gObjectList[objectIndex].state >= 2) {
        rsp_set_matrix_transformation(gObjectList[objectIndex].pos, gObjectList[objectIndex].direction_angle, gObjectList[objectIndex].sizeScaling);
        gSPDisplayList(gDisplayListHead++, D_0D0077D0);
        if (gIsGamePaused == 0) {
            gObjectList[objectIndex].unk_0A2 = func_80004DFC((animation_type_1 *) gObjectList[objectIndex].model, (animation_type_2 **) gObjectList[objectIndex].vertex, 0, gObjectList[objectIndex].unk_0A2);
        } else {
            func_80004DFC((animation_type_1 *) gObjectList[objectIndex].model, (animation_type_2 **) gObjectList[objectIndex].vertex, 0, gObjectList[objectIndex].unk_0A2);
        }
    }
}

void func_80055380(s32 arg0) {
    s32 i;
    s32 var_s1;

    for (i = 0; i < 10; i++) {
        var_s1 = indexObjectList2[i];
        if (func_8008A364(var_s1, arg0, 0x5555U, 0x000005DC) < 0x9C401) {
            D_80165908 = 1;
            func_800722A4(var_s1, 2);
        }
        if (is_obj_index_flag_unk_054_active(var_s1, 0x00040000) != 0) {
            func_800552BC(var_s1);
        }
    }
}

void func_80055458(s32 objectIndex, s32 cameraId) {
    Camera *camera;

    if (gObjectList[objectIndex].state >= 2) {
        camera = &camera1[cameraId];
        func_8004A6EC(objectIndex, 0.5f);
        gObjectList[objectIndex].orientation[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], camera->pos);
        func_800480B4(gObjectList[objectIndex].pos, gObjectList[objectIndex].orientation, gObjectList[objectIndex].sizeScaling, (u8 *) gObjectList[objectIndex].activeTLUT, gObjectList[objectIndex].activeTexture, D_0D0060B0, 0x00000040, 0x00000040, 0x00000040, 0x00000020);
    }
}

void func_80055528(s32 arg0) {
    s32 someIndex;
    s32 test;

    for (someIndex = 0; someIndex < 10; someIndex++) {
        test = indexObjectList1[someIndex];
        func_8008A364(test, arg0, 0x2AABU, 0x00000320);
        if (is_obj_index_flag_unk_054_active(test, 0x00040000) != 0) {
            func_80055458(test, arg0);
        }
    }
}

void func_800555BC(s32 objectIndex, s32 cameraId) {
    Camera *camera;

    if (gObjectList[objectIndex].state >= 2) {
        camera = &camera1[cameraId];
        func_8004A870(objectIndex, 0.7f);
        gObjectList[objectIndex].orientation[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], camera->pos);
        func_800480B4(gObjectList[objectIndex].pos, gObjectList[objectIndex].orientation, gObjectList[objectIndex].sizeScaling, (u8 *) gObjectList[objectIndex].activeTLUT, gObjectList[objectIndex].activeTexture, gObjectList[objectIndex].vertex, 64, 64, 64, 32);
    }
}

void func_8005568C(s32 arg0) {
    s32 test;
    u32 something;
    s32 someIndex;

    for (someIndex = 0; someIndex < 15; someIndex++) {
        test = indexObjectList2[someIndex];
        something = func_8008A364(test, arg0, 0x4000U, 0x000003E8);
        if (is_obj_index_flag_unk_054_active(test, 0x00040000) != 0) {
            set_object_flag_unk_054_true(test, 0x00200000);
            if (something < 0x2711U) {
                set_object_flag_unk_054_true(test, 0x00000020);
            } else {
                set_object_flag_unk_054_false(test, 0x00000020);
            }
            if (something < 0x57E41U) {
                set_object_flag_unk_054_true(test, 0x00400000);
            }
            if (something < 0x52211U) {
                func_800555BC(test, arg0);
            }
        }
    }
}

UNUSED void func_800557AC() {

}

void func_800557B4(s32 objectIndex, u32 arg1, u32 arg2) {
    Vec3f sp34;
    Objects *object;

    object = &gObjectList[objectIndex];
    if (object->state >= 2) {
        if (is_obj_index_flag_unk_054_active(objectIndex, 0x00000020) != 0) {
            if (func_80072320(objectIndex, 4) != 0) {
                if (arg2 >= arg1) {
                    sp34[0] = object->pos[0];
                    sp34[1] = object->pos[1] - 1.0;
                    sp34[2] = object->pos[2];
                    rsp_set_matrix_transformation_inverted_x_y_orientation(sp34, object->orientation, object->sizeScaling);
                    gSPDisplayList(gDisplayListHead++, D_0D0077D0);
                    func_80004DFC((animation_type_1 *) object->model, (animation_type_2 **) object->vertex, (s16) object->unk_0D8, (s16) object->itemDisplay);
                }
            } else if (arg1 < 0x15F91U) {
                func_8004A7AC(objectIndex, 1.5f);
            }
        }
        rsp_set_matrix_transformation(object->pos, object->orientation, object->sizeScaling);
        gSPDisplayList(gDisplayListHead++, D_0D0077D0);
        func_80004DFC((animation_type_1 *) object->model, (animation_type_2 **) object->vertex, (s16) object->unk_0D8, (s16) object->itemDisplay);
    }
}

void func_8005592C(s32 cameraId) {
    s32 var_s2;
    s32 objectIndex;
    s32 temp_s1;
    s32 var_a3;
    u16 var_s1;
    u32 var_s3;

    if (gPlayerCountSelection1 == 1) {
        var_s3 = 0x0003D090;
    } else if (gPlayerCountSelection1 == 2) {
        var_s3 = 0x00027100;
    } else {
        var_s3 = 0x00015F90;
    }
    for (var_s2 = 0; var_s2 < 15; var_s2++) {
        objectIndex = indexObjectList1[var_s2];
        if (gObjectList[objectIndex].state >= 2) {
            if (gPlayerCountSelection1 == 1) {
                var_s1 = 0x4000;
                if (var_s2 == 0) {
                    var_a3 = 0x000005DC;
                } else if (func_80072320(objectIndex, 8) != 0) {
                    var_a3 = 0x00000320;
                } else {
                    var_a3 = 0x000003E8;
                }
            } else {
                if (func_80072320(objectIndex, 8) != 0) {
                    var_a3 = 0x000001F4;
                    var_s1 = 0x4000;
                } else {
                    var_a3 = 0x00000258;
                    var_s1 = 0x5555;
                }
            }
            temp_s1 = func_8008A364(objectIndex, cameraId, var_s1, var_a3);
            if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
                func_800557B4(objectIndex, (u32) temp_s1, var_s3);
            }
        }
    }
}

void func_80055AB8(s32 objectIndex, s32 cameraId) {
    Camera *camera;

    camera = &camera1[cameraId];
    if (gObjectList[objectIndex].state >= 2) {
        if (is_obj_index_flag_unk_054_active(objectIndex, 0x00100000) != 0) {
            D_80183E40[0] = gObjectList[objectIndex].pos[0];
            D_80183E40[1] = gObjectList[objectIndex].pos[1] + 16.0;
            D_80183E40[2] = gObjectList[objectIndex].pos[2];
            D_80183E80[0] = 0;
            D_80183E80[1] = func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], camera->pos);
            D_80183E80[2] = 0x8000;
            func_800468E0(D_80183E40, D_80183E80, 0.54f, d_course_rainbow_road_sphere, D_0D0062B0, 0x00000020, 0x00000040, 0x00000020, 0x00000040, 5);
        } else {
            rsp_set_matrix_transformation(gObjectList[objectIndex].pos, gObjectList[objectIndex].direction_angle, gObjectList[objectIndex].sizeScaling);
            gSPDisplayList(gDisplayListHead++, D_0D0077D0);
            func_80004DFC((animation_type_1 *) gObjectList[objectIndex].model, (animation_type_2 **) gObjectList[objectIndex].vertex, 0, (s16) gObjectList[objectIndex].itemDisplay);
        }
    }
}

void func_80055C38(s32 cameraId) {
    s32 var_s1;
    s32 objectIndex;

    for (var_s1 = 0; var_s1 < 3; var_s1++) {
        objectIndex = indexObjectList2[var_s1];
        func_8008A1D0(objectIndex, cameraId, 0x000005DC, 0x000009C4);
        if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
            func_80055AB8(objectIndex, cameraId);
        }
    }
}

void func_80055CCC(s32 objectIndex, s32 cameraId) {
    UNUSED s32 pad;
    f32 test;
    Camera *camera;

    camera = &camera1[cameraId];
    if (gObjectList[objectIndex].state >= 2) {
        func_8008A454(objectIndex, cameraId, 0x0000012C);
        test = gObjectList[objectIndex].pos[1] - gObjectList[objectIndex].unk_044;
        func_8004A6EC(objectIndex, (20.0 / test) + 0.5);
        if (is_obj_index_flag_unk_054_inactive(objectIndex, 0x00100000) != 0) {
            func_80043328(gObjectList[objectIndex].pos, (u16 *) gObjectList[objectIndex].direction_angle, gObjectList[objectIndex].sizeScaling, d_course_luigi_raceway_dl_F960);
            gSPDisplayList(gDisplayListHead++, d_course_luigi_raceway_dl_F650);
        } else {
            D_80183E80[0] = (s16) gObjectList[objectIndex].direction_angle[0];
            D_80183E80[1] = (s16) (func_800418AC(gObjectList[objectIndex].pos[0], gObjectList[objectIndex].pos[2], camera->pos) + 0x8000);
            D_80183E80[2] = (u16) gObjectList[objectIndex].direction_angle[2];
            func_80043328(gObjectList[objectIndex].pos, D_80183E80, gObjectList[objectIndex].sizeScaling, d_course_luigi_raceway_dl_FBE0);
            gSPDisplayList(gDisplayListHead++, d_course_luigi_raceway_dl_FA20);
            if (gPlayerCountSelection1 == 1) {
                gObjectList[objectIndex].direction_angle[1] = 0;
            }
        }
    }
}

void func_80055E68(s32 arg0) {
    s32 objectIndex;
    objectIndex = indexObjectList1[0];
    if (gGamestate != 9) {
        func_8008A1D0(objectIndex, arg0, 0x000005DC, 0x00000BB8);
        if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
            func_80055CCC(objectIndex, arg0);
        }
    } else {
        set_object_flag_unk_054_false(objectIndex, 0x00100000);
        func_80055CCC(objectIndex, arg0);
    }
}

void func_80055EF4(s32 objectIndex, UNUSED s32 arg1) {
    Objects *object;

    object = &gObjectList[objectIndex];
    if (object->state >= 2) {
        func_80043220(object->pos, object->direction_angle, object->sizeScaling, object->model);
    }
}

void func_80055F48(s32 arg0) {
    s32 someIndex;

    for (someIndex = 0; someIndex < 3; someIndex++) {
        func_80055EF4(indexObjectList1[someIndex], arg0);
    }
}

void func_80055FA0(s32 objectIndex, UNUSED s32 arg1) {
    Mat4 someMatrix1;
    Mat4 someMatrix2;
    Objects *object;

    object = &gObjectList[objectIndex];
    if (object->state >= 2) {
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gGfxPool->mtxPersp[0]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_PROJECTION);
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gGfxPool->mtxLookAt[0]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
        mtxf_set_matrix_transformation(someMatrix1,object->pos, object->direction_angle, object->sizeScaling);
        convert_to_fixed_point_matrix(&gGfxPool->mtxHud[gMatrixHudCount], someMatrix1);
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gGfxPool->mtxHud[gMatrixHudCount++]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_MODELVIEW);
        gSPDisplayList(gDisplayListHead++, D_0D0077A0);
        gSPDisplayList(gDisplayListHead++, object->model);
        gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gGfxPool->mtxLookAt[0]), G_MTX_NOPUSH | G_MTX_MUL | G_MTX_PROJECTION);
        mtxf_identity(someMatrix2);
        render_set_position(someMatrix2, 0);
    }
}

void func_80056160(s32 arg0) {
    func_80055FA0(indexObjectList1[3], arg0);
}

void func_80056188(s32 cameraId) {
    Camera *camera;
    s32 var_s2;
    s32 objectIndex;
    Objects *object;

    camera = &camera1[cameraId];
    for (var_s2 =0; var_s2 < 10; var_s2++) {
        objectIndex = indexObjectList1[var_s2];
        if (D_8018E838[cameraId] == 0) {
            object = &gObjectList[objectIndex];
            if ((object->state >= 2) && (is_obj_index_flag_unk_054_inactive(objectIndex, 0x00080000) != 0) && (func_8008A140(objectIndex, camera, 0x2AABU) != 0)) {
                object->orientation[1] = angle_between_object_camera(objectIndex, camera);
                func_800480B4(object->pos, object->orientation, object->sizeScaling, (u8 *) object->activeTLUT, object->activeTexture, D_0D0060B0, 0x00000040, 0x00000040, 0x00000040, 0x00000020);
            }
        }
    }
}

void func_800562E4(s32 arg0, s32 arg1, s32 arg2) {
    D_80165860 = D_800E46F8[arg0][0];
    D_8016586C = D_800E46F8[arg0][1];
    D_80165878 = D_800E46F8[arg0][2];
    func_8004B138(D_80165860, D_8016586C, D_80165878, arg2);
    rsp_set_matrix_transformation(D_80183E40, D_80183E80, 0.2f);
    func_80044BF8(common_texture_particle_spark[arg1], 0x00000020, 0x00000020);
    gSPVertex(gDisplayListHead++, D_0D005AE0, 4, 0);
    gSPDisplayList(gDisplayListHead++, common_rectangle_display);
}

void func_800563DC(s32 objectIndex, s32 cameraId, s32 arg2) {
    s32 temp_s0;
    s32 temp_v0;
    s32 residue;
    Camera *camera;
    Objects *object;

    camera = &camera1[cameraId];
    object = &gObjectList[objectIndex];
    residue = D_801655CC % 4U;
    D_80183E40[0] = object->pos[0];
    D_80183E40[1] = object->pos[1] + 1.0;
    D_80183E40[2] = object->pos[2];
    D_80183E80[0] = 0;
    D_80183E80[1] = func_800418AC(object->pos[0], object->pos[2], camera->pos);
    D_80183E80[2] = 0x8000;
    rsp_set_matrix_transformation(D_80183E40, D_80183E80, 0.2f);
    gSPDisplayList(gDisplayListHead++, D_0D007E98);
    func_8004B310(arg2);
    draw_rectangle_texture_overlap(common_tlut_bomb, common_texture_bomb[residue], D_0D005AE0, 0x00000020, 0x00000020, 0x00000020, 0x00000020);
    temp_s0 = D_8018D400;
    gSPDisplayList(gDisplayListHead++, D_0D007B00);
    func_8004B414(0, 0, 0, arg2);
    D_80183E40[1] = D_80183E40[1] + 4.0;
    D_80183E80[2] = 0;
    func_800562E4(temp_s0 % 3, temp_s0 % 4, arg2);
    temp_v0 = temp_s0 + 1;
    D_80183E80[2] = 0x6000;
    func_800562E4(temp_v0 % 3, temp_v0 % 4, arg2);
    temp_v0 = temp_s0 + 2;
    D_80183E80[2] = 0xA000;
    func_800562E4(temp_v0 % 3, temp_v0 % 4, arg2);
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_8005669C(s32 objectIndex, UNUSED s32 arg1, s32 arg2) {
    gSPDisplayList(gDisplayListHead++, D_0D0079E8);
    func_8004B310(arg2);
    func_80043D50(D_0D02AA58, 0x00000010, 0x00000010);
    D_80183E40[1] = gObjectList[objectIndex].pos[1] - 2.0;
    D_80183E40[0] = gObjectList[objectIndex].pos[0] + 2.0;
    D_80183E40[2] = gObjectList[objectIndex].pos[2] + 2.0;
    func_800431B0(D_80183E40, D_80183E80, 0.15f, common_vtx_rectangle);
    D_80183E40[0] = gObjectList[objectIndex].pos[0] + 2.0;
    D_80183E40[2] = gObjectList[objectIndex].pos[2] - 2.0;
    func_800431B0(D_80183E40, D_80183E80, 0.15f, common_vtx_rectangle);
    D_80183E40[0] = gObjectList[objectIndex].pos[0] - 2.0;
    D_80183E40[2] = gObjectList[objectIndex].pos[2] - 2.0;
    func_800431B0(D_80183E40, D_80183E80, 0.15f, common_vtx_rectangle);
    D_80183E40[0] = gObjectList[objectIndex].pos[0] - 2.0;
    D_80183E40[2] = gObjectList[objectIndex].pos[2] + 2.0;
    func_800431B0(D_80183E40, D_80183E80, 0.15f, common_vtx_rectangle);
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_800568A0(s32 objectIndex, s32 playerId) {
    Mat4 sp30;
    Player *player;

    player = &gPlayerOne[playerId];
    D_80183E50[0] = gObjectList[objectIndex].pos[0];
    D_80183E50[1] = gObjectList[objectIndex].unk_044 + 0.8;
    D_80183E50[2] = gObjectList[objectIndex].pos[2];
    set_transform_matrix(sp30, player->unk_110.orientationVector, D_80183E50, 0U, 0.5f);
    convert_to_fixed_point_matrix(&gGfxPool->mtxHud[gMatrixHudCount], sp30);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gGfxPool->mtxHud[gMatrixHudCount++]), G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, D_0D007B98);
}

void func_800569F4(s32 arg0) {
    s32 objectIndex;

    objectIndex = D_80183DD8[arg0];
    init_object(objectIndex, 0);
    gObjectList[objectIndex].unk_0A0 = 0;
}

void func_80056A40(s32 arg0, s32 arg1) {
    s32 objectIndex;

    objectIndex = D_80183DD8[arg0];
    init_object(objectIndex, 0);
    gObjectList[objectIndex].unk_0A0 = (s16) arg1;
}

void func_80056A94(s32 arg0) {
    func_80072428(D_80183DD8[arg0]);
}

void func_80056AC0(s32 cameraId) {
    Player *temp_v0;
    s32 temp_s1;
    s32 temp_s0;
    s32 payerId;
    Objects *temp_v1;

    for (payerId = 0; payerId < NUM_BOMB_KARTS_BATTLE; payerId++) {
        temp_s0 = D_80183DD8[payerId];
        temp_v1 = &gObjectList[temp_s0];
        if (temp_v1->state != 0) {
            temp_s1 = temp_v1->unk_0A0;
            temp_v0 = &gPlayerOne[payerId];
            temp_v1->pos[0] = temp_v0->pos[0];
            temp_v1->pos[1] = temp_v0->pos[1] - 2.0;
            temp_v1->pos[2] = temp_v0->pos[2];
            temp_v1->unk_044 = temp_v0->unk_074;
            func_800563DC(temp_s0, cameraId, temp_s1);
            func_8005669C(temp_s0, cameraId, temp_s1);
            func_800568A0(temp_s0, cameraId);
        }
    }
}

void func_80056BF0(s32 bombIndex) {
    s32 stackPadding;
    u8 thing;
    s32 temp_s0;
    s32 temp_v0;
    u8 *bombFrame;
    BombKart sp40 = gBombKarts[bombIndex];

    temp_v0 = D_801655CC % 6U;
    thing = D_800E471C[temp_v0];
    bombFrame = common_texture_bomb[thing];
    D_80183E40[0] = sp40.bombPos[0];
    D_80183E40[1] = sp40.bombPos[1] + 1.0;
    D_80183E40[2] = sp40.bombPos[2];
    func_800480B4(D_80183E40, D_80183E80, 0.25f, common_tlut_bomb, bombFrame, D_0D005AE0, 0x20, 0x20, 0x20, 0x20);
    temp_s0 = D_8018D400;
    gSPDisplayList(gDisplayListHead++, D_0D007B00);
    func_8004B414(0, 0, 0, 0xFF);
    D_80183E40[1] = sp40.bombPos[1] + 5.0;
    D_80183E80[2] = 0;
    func_800562E4((s32) temp_s0 % 3, temp_s0 % 4, 0xFFU);
    temp_v0 = temp_s0 + 1;
    D_80183E80[2] = 0x6000;
    func_800562E4(temp_v0 % 3, temp_v0 % 4, 0xFFU);
    temp_v0 = temp_s0 + 2;
    D_80183E80[2] = 0xA000;
    func_800562E4(temp_v0 % 3, temp_v0 % 4, 0xFFU);
}

void func_80056E24(s32 bombIndex, Vec3f arg1) {
    s32 stackPadding[2];
    BombKart sp2C = gBombKarts[bombIndex];

    D_80183E80[0] = 0;
    D_80183E80[2] = 0x8000;
    gSPDisplayList(gDisplayListHead++, D_0D0079C8);
    func_80043D50(D_0D02AA58, 0x00000010, 0x00000010);
    D_80183E80[1] = func_800418AC(sp2C.wheel1Pos[0], sp2C.wheel1Pos[2], arg1);
    func_800431B0(sp2C.wheel1Pos, D_80183E80, 0.15f, common_vtx_rectangle);
    D_80183E80[1] = func_800418AC(sp2C.wheel2Pos[0], sp2C.wheel2Pos[2], arg1);
    func_800431B0(sp2C.wheel2Pos, D_80183E80, 0.15f, common_vtx_rectangle);
    D_80183E80[1] = func_800418AC(sp2C.wheel3Pos[0], sp2C.wheel3Pos[2], arg1);
    func_800431B0(sp2C.wheel3Pos, D_80183E80, 0.15f, common_vtx_rectangle);
    D_80183E80[1] = func_800418AC(sp2C.wheel4Pos[0], sp2C.wheel4Pos[2], arg1);
    func_800431B0(sp2C.wheel4Pos, D_80183E80, 0.15f, common_vtx_rectangle);
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

void func_80056FCC(s32 bombIndex) {
    Mat4 mat;
    BombKart *temp_v0;

    temp_v0 = &gBombKarts[bombIndex];
    D_80183E50[0] = temp_v0->bombPos[0];
    D_80183E50[1] = temp_v0->yPos + 1.0;
    D_80183E50[2] = temp_v0->bombPos[2];
    set_transform_matrix(mat, D_80164038[bombIndex].orientationVector, D_80183E50, 0U, 0.5f);
    convert_to_fixed_point_matrix(&gGfxPool->mtxHud[gMatrixHudCount], mat);
    gSPMatrix(gDisplayListHead++, VIRTUAL_TO_PHYSICAL(&gGfxPool->mtxHud[gMatrixHudCount++]), G_MTX_LOAD | G_MTX_NOPUSH| G_MTX_MODELVIEW);
    gSPDisplayList(gDisplayListHead++, D_0D007B98);
}

void func_80057114(s32 cameraId) {
    Camera *temp_s7;
    s32 objectIndex;
    s32 temp_s4;
    s32 var_s2;
    s32 state;
    BombKart *var_s1_2;

    if (gGamestate == 5) {
        cameraId = 0;
    }
    temp_s7 = &camera1[cameraId];
    if (cameraId == 0) {
        for (var_s2 = 0; var_s2 < NUM_BOMB_KARTS_VERSUS; var_s2++) {
            objectIndex = D_80183DD8[var_s2];
            if (is_obj_index_flag_unk_054_active(objectIndex, 0x00200000) != 0) {
                gBombKarts[var_s2].unk_4A = 0;
            } else if (gGamestate != 5) {
                gBombKarts[var_s2].unk_4A = 1;
            }
            set_object_flag_unk_054_false(objectIndex, 0x00200000);
        }
    }

    for (var_s2 = 0; var_s2 < NUM_BOMB_KARTS_VERSUS; var_s2++) {
        var_s1_2 = &gBombKarts[var_s2];
        // huh???
        state = var_s1_2->state;
        if (var_s1_2->state != BOMB_STATE_INACTIVE) {
            objectIndex = D_80183DD8[var_s2];
            gObjectList[objectIndex].pos[0] = var_s1_2->bombPos[0];
            gObjectList[objectIndex].pos[1] = var_s1_2->bombPos[1];
            gObjectList[objectIndex].pos[2] = var_s1_2->bombPos[2];
            temp_s4 = func_8008A364(objectIndex, cameraId, 0x31C4U, 0x000001F4);
            if (is_obj_index_flag_unk_054_active(objectIndex, 0x00040000) != 0) {
                set_object_flag_unk_054_true(objectIndex, 0x00200000);
                D_80183E80[0] = 0;
                D_80183E80[1] = func_800418AC(var_s1_2->bombPos[0], var_s1_2->bombPos[2], temp_s7->pos);
                D_80183E80[2] = 0x8000;
                func_800563DC(objectIndex, cameraId, 0x000000FF);
                func_80056E24(var_s2, temp_s7->pos);
                if (((u32) temp_s4 < 0x4E21U) && (state != BOMB_STATE_EXPLODED)) {
                    func_80056FCC(var_s2);
                }
            }
        }
    }
}

UNUSED void func_80057330(void) {

}

UNUSED void func_80057338(void) {

    gSPDisplayList(gDisplayListHead++, D_0D0079C8);
    gSPClearGeometryMode(gDisplayListHead++, G_CULL_BOTH);
    gSPDisplayList(gDisplayListHead++, D_0D007AE0);
    gSPTexture(gDisplayListHead++, 1, 1, 0, G_TX_RENDERTILE, G_OFF);
}

UNUSED void func_800573BC(void) {

}

UNUSED void func_800573C4(void) {
    
}

UNUSED void func_800573CC(void) {
    
}
UNUSED void func_800573D4(void) {
    
}

UNUSED void func_800573DC(void) {
    
}


void func_800573E4(s32 x, s32 y, s8 str) {
    func_8004B7DC(x, y, 8, 8, (((str % 16) * 8) << 16) >> 16, (((unsigned short) (str / 16)) << 19) >> 16, 0);
}

void debug_wrap_text(s32 *x, s32 *y) {
    *x += 8;
    if (*x >= 296) {
        *x = 20;
        *y += 8;
    }
}

void debug_print_string(s32 *x, s32 *y, char *arg2) {
    *x += 20;
    *y += 20;

    while (*arg2 != '\0') {
        if (D_800E5628[(s32)*arg2] >= 0) {
            func_800573E4(*x, *y, D_800E5628[(s32)*arg2]);
        }
        debug_wrap_text(x, y);
        arg2++;
    }
}

void debug_print_number(s32 *x, s32 *y, s32 number, u32 numDigits)
{
    s32 n;
    s8 *ptr;
    s8 remainder;

    debug_wrap_text(x, y);
    n = number;
    if (n < 0) {
        func_800573E4(*x, *y, *D_800E5655);
        debug_wrap_text(x, y);
        n = -number;
    }
      
    *D_801657B8 = -1;
    ptr = D_801657B8;
    if (n != 0) {
        while (n != 0) {
            remainder = n % numDigits;
            *++ptr = remainder;
            n = n / numDigits;
        }
    } else {
        *++ptr = 0;
    }
    
    do {
        func_800573E4(*x, *y, *ptr--);
        debug_wrap_text(x, y);
   } while (*ptr  != -1);
}

/**
 * 801657B8[] does nothing? 0xFF a mask?
 * Index zero is a null/0xFF flag.
 * The other indexes increment 0-9
 * The final index (10) increments the tenth digit.
*/
void func_8005762C(s32 *x, s32 *y, s32 pathCount, u32 numDigits) {
    s8 *ptr;
    s32 count;
    s8 remainder;
    
    debug_wrap_text(x, y);
    *D_801657B8 = -1;
    ptr = D_801657B8;
    count = pathCount;
    if (count != 0) {
        while (count != 0) {
            // Retrives ones digit (31 outputs 1).
            remainder = count % numDigits;
            *++ptr = remainder;
            // Retrieves tens digit (31 outputs 3).
            count = count / numDigits;
        }
    } else {
        *++ptr = 0;
    }
    
    do {
        func_800573E4(*x, *y, *ptr--);
        debug_wrap_text(x, y);
    } while (*ptr != -1);
}

UNUSED void func_80057708() {

}

void load_debug_font(void) {
    gSPDisplayList(gDisplayListHead++, D_0D008108);
    gSPDisplayList(gDisplayListHead++, D_0D008080);
    gDPSetAlphaCompare(gDisplayListHead++, G_AC_THRESHOLD);
}

void func_80057778(void) {
    gSPDisplayList(gDisplayListHead++, D_0D007EB8);
}

void debug_print_str2(s32 xPos, s32 yPos, char *str) {
    debug_print_string(&xPos, &yPos, str);
}

void print_str_num(s32 arg0, s32 arg1, char *arg2, s32 arg3) {
    debug_print_string(&arg0, &arg1, arg2);
    debug_print_number(&arg0, &arg1, arg3, 10);
}

UNUSED void func_80057814(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    debug_print_string(&arg0, &arg1, arg2);
    func_8005762C(&arg0, &arg1, arg3, 10);
}

UNUSED void func_80057858(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    debug_print_string(&arg0, &arg1, arg2);
    debug_print_number(&arg0, &arg1, arg3, 16);
    func_800573E4(arg0, arg1, D_800E5670[0]);
}

UNUSED void func_800578B0(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    debug_print_string(&arg0, &arg1, arg2);
    func_8005762C(&arg0, &arg1, arg3, 16);
    func_800573E4(arg0, arg1, D_800E5670[0]);
}

UNUSED void func_80057908(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    debug_print_string(&arg0, &arg1, arg2);
    debug_print_number(&arg0, &arg1, arg3, 2);
    func_800573E4(arg0, arg1, D_800E566A[0]);
}

UNUSED void func_80057960(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    debug_print_string(&arg0, &arg1, arg2);
    func_8005762C(&arg0, &arg1, arg3, 2);
    func_800573E4(arg0, arg1, D_800E566A[0]);
}

UNUSED void func_800579B8(s32 arg0, s32 arg1, char *arg2) {
    load_debug_font();
    debug_print_string(&arg0, &arg1, arg2);
    func_80057778();
}

void func_800579F8(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    load_debug_font();
    debug_print_string(&arg0, &arg1, arg2);
    debug_print_number(&arg0, &arg1, arg3, 10);
    func_80057778();
}

void func_80057A50(s32 x, s32 y, char *str, u32 arg3) {
    load_debug_font();
    debug_print_string(&x, &y, str);
    func_8005762C(&x, &y, arg3, 10);
    func_80057778();
}

UNUSED void func_80057AA8(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    load_debug_font();
    debug_print_string(&arg0, &arg1, arg2);
    debug_print_number(&arg0, &arg1, arg3, 16);
    func_800573E4(arg0, arg1, D_800E5670[0]);
    func_80057778();
}

UNUSED void func_80057B14(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    load_debug_font();
    debug_print_string(&arg0, &arg1, arg2);
    func_8005762C(&arg0, &arg1, arg3, 16);
    func_800573E4(arg0, arg1, D_800E5670[0]);
    func_80057778();
}

UNUSED void func_80057B80(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    load_debug_font();
    debug_print_string(&arg0, &arg1, arg2);
    debug_print_number(&arg0, &arg1, arg3, 2);
    func_800573E4(arg0, arg1, D_800E566A[0]);
    func_80057778();
}

UNUSED void func_80057BEC(s32 arg0, s32 arg1, char *arg2, u32 arg3) {
    load_debug_font();
    debug_print_string(&arg0, &arg1, arg2);
    func_8005762C(&arg0, &arg1, arg3, 2);
    func_800573E4(arg0, arg1, D_800E566A[0]);
    func_80057778();
}
