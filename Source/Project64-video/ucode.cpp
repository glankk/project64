/***************************************************************************
*                                                                          *
* Project64-video - A Nintendo 64 gfx plugin.                              *
* http://www.pj64-emu.com/                                                 *
* Copyright (C) 2017 Project64. All rights reserved.                       *
* Copyright (C) 2003-2009  Sergey 'Gonetz' Lipski                          *
* Copyright (C) 2002 Dave2001                                              *
*                                                                          *
* License:                                                                 *
* GNU/GPLv2 http://www.gnu.org/licenses/gpl-2.0.html                       *
* version 2 of the License, or (at your option) any later version.         *
*                                                                          *
****************************************************************************/
#include <Project64-video/rdp.h>
#include <Project64-video/Gfx_1.3.h>
#include <Project64-video/trace.h>
#include <Project64-video/ucode.h>
#include "ucode00.h"
#include "ucode01.h"
#include "ucode02.h"
#include "ucode03.h"
#include "ucode04.h"
#include "ucode05.h"
#include "ucode06.h"
#include "ucode07.h"
#include "ucode08.h"
#include "ucode09.h"

rdp_instr gfx_instruction[10][256] =
{
    {
        // uCode 0 - RSP SW 2.0X
        // 00-3f
        // games: Super Mario 64, Tetrisphere, Demos
        spnoop, uc0_matrix, rsp_reserved0, uc0_movemem,
        uc0_vertex, rsp_reserved1, uc0_displaylist, rsp_reserved2,
        rsp_reserved3, uc6_sprite2d, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 40-7f: Unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 80-bf: Immediate commands
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, uc0_tri4, rdphalf_cont, rdphalf_2,
        rdphalf_1, uc0_line3d, uc0_cleargeometrymode, uc0_setgeometrymode,
        uc0_enddl, uc0_setothermode_l, uc0_setothermode_h, uc0_texture,
        uc0_moveword, uc0_popmatrix, uc0_culldl, uc0_tri1,
        // c0-ff: RDP commands
        rdp_noop, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, rdp_setscissor, rdp_setprimdepth, rdp_setothermode,
        rdp_loadtlut, undef, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },

    // uCode 1 - F3DEX 1.XX
    // 00-3f
    // games: Mario Kart, Star Fox
    {
        spnoop, uc0_matrix, rsp_reserved0, uc0_movemem,
        uc1_vertex, rsp_reserved1, uc0_displaylist, rsp_reserved2,
        rsp_reserved3, uc6_sprite2d, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 40-7f: unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 80-bf: Immediate commands
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, uc6_loaducode,
        uc1_branch_z, uc1_tri2, uc2_modifyvtx, rdphalf_2,
        uc1_rdphalf_1, uc1_line3d, uc0_cleargeometrymode, uc0_setgeometrymode,
        uc0_enddl, uc0_setothermode_l, uc0_setothermode_h, uc0_texture,
        uc0_moveword, uc0_popmatrix, uc2_culldl, uc1_tri1,
        // c0-ff: RDP commands
        rdp_noop, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, rdp_setscissor, rdp_setprimdepth, rdp_setothermode,
        rdp_loadtlut, undef, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },

    // uCode 2 - F3DEX 2.XX
    // games: Zelda 64
    {
        // 00-3f
        spnoop, uc2_vertex, uc2_modifyvtx, uc2_culldl,
        uc1_branch_z, uc2_tri1, uc2_quad, uc2_quad,
        uc2_line3d, uc6_bg_1cyc, uc6_bg_copy, uc6_obj_rendermode/*undef*/,
        undef, undef, undef, undef,
        uc0_tri4, uc0_tri4, uc0_tri4, uc0_tri4,
        uc0_tri4, uc0_tri4, uc0_tri4, uc0_tri4,
        uc0_tri4, uc0_tri4, uc0_tri4, uc0_tri4,
        uc0_tri4, uc0_tri4, uc0_tri4, uc0_tri4,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        // 40-7f: unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        // 80-bf: unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        // c0-ff: RDP commands mixed with uc2 commands
        rdp_noop, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,
        undef, undef, undef, uc2_special3,
        uc2_special2, uc2_dlist_cnt, uc2_dma_io, uc0_texture,
        uc2_pop_matrix, uc2_geom_mode, uc2_matrix, uc2_moveword,
        uc2_movemem, uc2_load_ucode, uc0_displaylist, uc0_enddl,
        spnoop, uc1_rdphalf_1, uc0_setothermode_l, uc0_setothermode_h,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, rdp_setscissor, rdp_setprimdepth, rdp_setothermode,
        rdp_loadtlut, uc2_rdphalf_2, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },

    // uCode 3 - "RSP SW 2.0D", but not really
    // 00-3f
    // games: Wave Race
    // ** Added by Gonetz **
    {
        spnoop, uc0_matrix, rsp_reserved0, uc0_movemem,
        uc3_vertex, rsp_reserved1, uc0_displaylist, rsp_reserved2,
        rsp_reserved3, uc6_sprite2d, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 40-7f: unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 80-bf: Immediate commands
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, uc3_tri2, rdphalf_cont, rdphalf_2,
        rdphalf_1, uc3_quad3d, uc0_cleargeometrymode, uc0_setgeometrymode,
        uc0_enddl, uc0_setothermode_l, uc0_setothermode_h, uc0_texture,
        uc0_moveword, uc0_popmatrix, uc0_culldl, uc3_tri1,
        // c0-ff: RDP commands
        rdp_noop, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, rdp_setscissor, rdp_setprimdepth, rdp_setothermode,
        rdp_loadtlut, undef, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },

    {
        // uCode 4 - RSP SW 2.0D EXT
        // 00-3f
        // games: Star Wars: Shadows of the Empire
        spnoop, uc0_matrix, rsp_reserved0, uc0_movemem,
        uc4_vertex, rsp_reserved1, uc0_displaylist, rsp_reserved2,
        rsp_reserved3, uc6_sprite2d, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 40-7f: Unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 80-bf: Immediate commands
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, uc0_tri4, rdphalf_cont, rdphalf_2,
        rdphalf_1, uc4_quad3d, uc0_cleargeometrymode, uc0_setgeometrymode,
        uc0_enddl, uc0_setothermode_l, uc0_setothermode_h, uc0_texture,
        uc0_moveword, uc0_popmatrix, uc0_culldl, uc4_tri1,
        // c0-ff: RDP commands
        rdp_noop, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, rdp_setscissor, rdp_setprimdepth, rdp_setothermode,
        rdp_loadtlut, undef, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },

    {
        // uCode 5 - RSP SW 2.0 Diddy
        // 00-3f
        // games: Diddy Kong Racing
        spnoop, uc5_matrix, rsp_reserved0, uc0_movemem,
        uc5_vertex, uc5_tridma, uc0_displaylist, uc5_dl_in_mem,
        rsp_reserved3, uc6_sprite2d, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 40-7f: Unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 80-bf: Immediate commands
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, uc0_tri4, rdphalf_cont, rdphalf_2,
        rdphalf_1, uc0_line3d, uc5_cleargeometrymode, uc5_setgeometrymode,
        uc0_enddl, uc0_setothermode_l, uc0_setothermode_h, uc0_texture,
        uc5_moveword, uc0_popmatrix, uc0_culldl, uc5_dma_offsets,
        // c0-ff: RDP commands
        rdp_noop, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, rdp_setscissor, rdp_setprimdepth, rdp_setothermode,
        rdp_loadtlut, undef, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },

    // uCode 6 - S2DEX 1.XX
    // games: Yoshi's Story
    {
        spnoop, uc6_bg_1cyc, uc6_bg_copy, uc6_obj_rectangle,
        uc6_obj_sprite, uc6_obj_movemem, uc0_displaylist, rsp_reserved2,
        rsp_reserved3, undef/*uc6_sprite2d*/, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 40-7f: unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 80-bf: Immediate commands
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, uc6_loaducode,
        uc6_select_dl, uc6_obj_rendermode, uc6_obj_rectangle_r, rdphalf_2,
        rdphalf_1, uc1_line3d, uc0_cleargeometrymode, uc0_setgeometrymode,
        uc0_enddl, uc0_setothermode_l, uc0_setothermode_h, uc0_texture,
        uc0_moveword, uc0_popmatrix, uc2_culldl, uc1_tri1,
        // c0-ff: RDP commands
        rdp_noop, uc6_obj_loadtxtr, uc6_obj_ldtx_sprite, uc6_obj_ldtx_rect,
        uc6_ldtx_rect_r, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, rdp_setscissor, rdp_setprimdepth, rdp_setothermode,
        rdp_loadtlut, undef, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },
    // uCode 7 - unknown
    // games: Perfect Dark
    {
        // 00-3f
        spnoop, uc0_matrix, rsp_reserved0, uc0_movemem,
        uc7_vertex, rsp_reserved1, uc0_displaylist, uc7_colorbase,
        rsp_reserved3, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        // 40-7f: unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        // 80-bf: unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        undef, uc0_tri4, rdphalf_cont, rdphalf_2,
        rdphalf_1, uc1_tri2, uc0_cleargeometrymode, uc0_setgeometrymode,
        uc0_enddl, uc0_setothermode_l, uc0_setothermode_h, uc0_texture,
        uc0_moveword, uc0_popmatrix, uc0_culldl, uc0_tri1,

        // c0-ff: RDP commands mixed with uc2 commands
        rdp_noop, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,

        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        undef, undef, undef, undef,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, rdp_setscissor, rdp_setprimdepth, rdp_setothermode,

        rdp_loadtlut, rdphalf_2, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },

    // uCode 8 - unknown
    // games: Conker's Bad Fur Day
    {
        // 00-3f
        spnoop, uc8_vertex, uc2_modifyvtx, uc2_culldl,
        uc1_branch_z, uc2_tri1, uc2_quad, uc2_quad,
        uc2_line3d, uc6_bg_1cyc, uc6_bg_copy, uc6_obj_rendermode/*undef*/,
        undef, undef, undef, undef,
        uc8_tri4, uc8_tri4, uc8_tri4, uc8_tri4,
        uc8_tri4, uc8_tri4, uc8_tri4, uc8_tri4,
        uc8_tri4, uc8_tri4, uc8_tri4, uc8_tri4,
        uc8_tri4, uc8_tri4, uc8_tri4, uc8_tri4,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        // 40-7f: unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        // 80-bf: unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,

        // c0-ff: RDP commands mixed with uc2 commands
        rdp_noop, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,
        undef, undef, undef, uc2_special3,
        uc2_special2, uc2_dlist_cnt, uc2_dma_io, uc0_texture,
        uc2_pop_matrix, uc2_geom_mode, uc2_matrix, uc8_moveword,
        uc8_movemem, uc2_load_ucode, uc0_displaylist, uc0_enddl,
        spnoop, rdphalf_1, uc0_setothermode_l, uc0_setothermode_h,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, rdp_setscissor, rdp_setprimdepth, rdp_setothermode,
        rdp_loadtlut, uc2_rdphalf_2, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },

    {
        // uCode 9 - gzsort
        // games: Telefoot Soccer
        // 00-3f
        spnoop, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 40-7f: Unused
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        // 80-bf: Immediate commands
        uc9_object, uc9_rpdcmd, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        undef, undef, undef, undef,
        rdphalf_1, undef, uc0_cleargeometrymode, uc0_setgeometrymode,
        uc0_enddl, uc0_setothermode_l, uc0_setothermode_h, uc0_texture,
        uc0_moveword, undef, uc0_culldl, undef,
        // c0-ff: RDP commands
        rdp_noop, undef, undef, undef,
        undef, undef, undef, undef,
        rdp_trifill, rdp_trifillz, rdp_tritxtr, rdp_tritxtrz,
        rdp_trishade, rdp_trishadez, rdp_trishadetxtr, rdp_trishadetxtrz,

        uc9_mix, uc9_fmlight, uc9_light, undef,
        uc9_mtxtrnsp, uc9_mtxcat, uc9_mult_mpmtx, uc9_link_subdl,
        uc9_set_subdl, uc9_wait_signal, uc9_send_signal, uc0_moveword,
        uc9_movemem, undef, uc0_displaylist, uc0_enddl,

        undef, undef, uc0_setothermode_l, uc0_setothermode_h,
        rdp_texrect, rdp_texrect, rdp_loadsync, rdp_pipesync,
        rdp_tilesync, rdp_fullsync, rdp_setkeygb, rdp_setkeyr,
        rdp_setconvert, uc9_setscissor, rdp_setprimdepth, rdp_setothermode,

        rdp_loadtlut, rdphalf_2, rdp_settilesize, rdp_loadblock,
        rdp_loadtile, rdp_settile, rdp_fillrect, rdp_setfillcolor,
        rdp_setfogcolor, rdp_setblendcolor, rdp_setprimcolor, rdp_setenvcolor,
        rdp_setcombine, rdp_settextureimage, rdp_setdepthimage, rdp_setcolorimage
    },
};