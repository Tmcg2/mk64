.section .late_rodata

glabel D_800F1F34
.float 1.2

.section .text

glabel func_800A761C
/* 0A821C 800A761C 27BDFFB0 */  addiu $sp, $sp, -0x50
/* 0A8220 800A7620 AFB00028 */  sw    $s0, 0x28($sp)
/* 0A8224 800A7624 00808025 */  move  $s0, $a0
/* 0A8228 800A7628 3C048028 */  lui   $a0, %hi(D_802874F5) # $a0, 0x8028
/* 0A822C 800A762C 808474F5 */  lb    $a0, %lo(D_802874F5)($a0)
/* 0A8230 800A7630 AFBF002C */  sw    $ra, 0x2c($sp)
/* 0A8234 800A7634 F7B40020 */  sdc1  $f20, 0x20($sp)
/* 0A8238 800A7638 24840001 */  addiu $a0, 1
/* 0A823C 800A763C AFA40038 */  sw    $a0, 0x38($sp)
/* 0A8240 800A7640 0C029E7D */  jal   func_800A79F4
/* 0A8244 800A7644 27A5003C */   addiu $a1, $sp, 0x3c
/* 0A8248 800A7648 3C04800E */  lui   $a0, %hi(D_800E7AA4) # $a0, 0x800e
/* 0A824C 800A764C 0C024C0D */  jal   get_string_width
/* 0A8250 800A7650 8C847AA4 */   lw    $a0, %lo(D_800E7AA4)($a0)
/* 0A8254 800A7654 244E0005 */  addiu $t6, $v0, 5
/* 0A8258 800A7658 448E2000 */  mtc1  $t6, $f4
/* 0A825C 800A765C 3C01800F */  lui   $at, %hi(D_800F1F34) # $at, 0x800f
/* 0A8260 800A7660 C4341F34 */  lwc1  $f20, %lo(D_800F1F34)($at)
/* 0A8264 800A7664 468021A0 */  cvt.s.w $f6, $f4
/* 0A8268 800A7668 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0A826C 800A766C 44815000 */  mtc1  $at, $f10
/* 0A8270 800A7670 8FB90038 */  lw    $t9, 0x38($sp)
/* 0A8274 800A7674 3C09800E */  lui   $t1, %hi(D_800E7AA4) # $t1, 0x800e
/* 0A8278 800A7678 25297AA4 */  addiu $t1, %lo(D_800E7AA4) # addiu $t1, $t1, 0x7aa4
/* 0A827C 800A767C 46143202 */  mul.s $f8, $f6, $f20
/* 0A8280 800A7680 00194080 */  sll   $t0, $t9, 2
/* 0A8284 800A7684 01091821 */  addu  $v1, $t0, $t1
/* 0A8288 800A7688 8C640000 */  lw    $a0, ($v1)
/* 0A828C 800A768C AFA30034 */  sw    $v1, 0x34($sp)
/* 0A8290 800A7690 460A4403 */  div.s $f16, $f8, $f10
/* 0A8294 800A7694 4600848D */  trunc.w.s $f18, $f16
/* 0A8298 800A7698 44189000 */  mfc1  $t8, $f18
/* 0A829C 800A769C 0C024C0D */  jal   get_string_width
/* 0A82A0 800A76A0 AFB80048 */   sw    $t8, 0x48($sp)
/* 0A82A4 800A76A4 244A0005 */  addiu $t2, $v0, 5
/* 0A82A8 800A76A8 448A2000 */  mtc1  $t2, $f4
/* 0A82AC 800A76AC 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0A82B0 800A76B0 44815000 */  mtc1  $at, $f10
/* 0A82B4 800A76B4 468021A0 */  cvt.s.w $f6, $f4
/* 0A82B8 800A76B8 24040005 */  li    $a0, 5
/* 0A82BC 800A76BC 46143202 */  mul.s $f8, $f6, $f20
/* 0A82C0 800A76C0 460A4403 */  div.s $f16, $f8, $f10
/* 0A82C4 800A76C4 4600848D */  trunc.w.s $f18, $f16
/* 0A82C8 800A76C8 440C9000 */  mfc1  $t4, $f18
/* 0A82CC 800A76CC 0C024C36 */  jal   set_text_color
/* 0A82D0 800A76D0 AFAC0044 */   sw    $t4, 0x44($sp)
/* 0A82D4 800A76D4 8E0D000C */  lw    $t5, 0xc($s0)
/* 0A82D8 800A76D8 8FAE0044 */  lw    $t6, 0x44($sp)
/* 0A82DC 800A76DC 8E050010 */  lw    $a1, 0x10($s0)
/* 0A82E0 800A76E0 3C06800E */  lui   $a2, %hi(D_800E7AA4) # $a2, 0x800e
/* 0A82E4 800A76E4 8CC67AA4 */  lw    $a2, %lo(D_800E7AA4)($a2)
/* 0A82E8 800A76E8 E7B40014 */  swc1  $f20, 0x14($sp)
/* 0A82EC 800A76EC E7B40010 */  swc1  $f20, 0x10($sp)
/* 0A82F0 800A76F0 00003825 */  move  $a3, $zero
/* 0A82F4 800A76F4 0C024DBB */  jal   draw_text
/* 0A82F8 800A76F8 01AE2023 */   subu  $a0, $t5, $t6
/* 0A82FC 800A76FC 3C04800E */  lui   $a0, %hi(gGlobalTimer) # $a0, 0x800e
/* 0A8300 800A7700 8C84C54C */  lw    $a0, %lo(gGlobalTimer)($a0)
/* 0A8304 800A7704 24010003 */  li    $at, 3
/* 0A8308 800A7708 0081001A */  div   $zero, $a0, $at
/* 0A830C 800A770C 00002010 */  mfhi  $a0
/* 0A8310 800A7710 0C024C36 */  jal   set_text_color
/* 0A8314 800A7714 00000000 */   nop   
/* 0A8318 800A7718 8FA80034 */  lw    $t0, 0x34($sp)
/* 0A831C 800A771C 8E18000C */  lw    $t8, 0xc($s0)
/* 0A8320 800A7720 8FB90048 */  lw    $t9, 0x48($sp)
/* 0A8324 800A7724 8E050010 */  lw    $a1, 0x10($s0)
/* 0A8328 800A7728 8D060000 */  lw    $a2, ($t0)
/* 0A832C 800A772C E7B40014 */  swc1  $f20, 0x14($sp)
/* 0A8330 800A7730 E7B40010 */  swc1  $f20, 0x10($sp)
/* 0A8334 800A7734 00003825 */  move  $a3, $zero
/* 0A8338 800A7738 0C024DBB */  jal   draw_text
/* 0A833C 800A773C 03192021 */   addu  $a0, $t8, $t9
/* 0A8340 800A7740 8FA40038 */  lw    $a0, 0x38($sp)
/* 0A8344 800A7744 0C029E25 */  jal   convert_number_to_ascii
/* 0A8348 800A7748 27A5003C */   addiu $a1, $sp, 0x3c
/* 0A834C 800A774C 8E09000C */  lw    $t1, 0xc($s0)
/* 0A8350 800A7750 8FAA0048 */  lw    $t2, 0x48($sp)
/* 0A8354 800A7754 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 0A8358 800A7758 44810000 */  mtc1  $at, $f0
/* 0A835C 800A775C 8E050010 */  lw    $a1, 0x10($s0)
/* 0A8360 800A7760 012A2021 */  addu  $a0, $t1, $t2
/* 0A8364 800A7764 2484FFE8 */  addiu $a0, $a0, -0x18
/* 0A8368 800A7768 27A6003D */  addiu $a2, $sp, 0x3d
/* 0A836C 800A776C 00003825 */  move  $a3, $zero
/* 0A8370 800A7770 E7A00014 */  swc1  $f0, 0x14($sp)
/* 0A8374 800A7774 0C024E72 */  jal   func_800939C8
/* 0A8378 800A7778 E7A00010 */   swc1  $f0, 0x10($sp)
/* 0A837C 800A777C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0A8380 800A7780 D7B40020 */  ldc1  $f20, 0x20($sp)
/* 0A8384 800A7784 8FB00028 */  lw    $s0, 0x28($sp)
/* 0A8388 800A7788 03E00008 */  jr    $ra
/* 0A838C 800A778C 27BD0050 */   addiu $sp, $sp, 0x50
