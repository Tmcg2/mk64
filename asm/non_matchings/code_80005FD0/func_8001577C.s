.section .late_rodata

glabel D_800ED220
.double -0.7

glabel D_800ED228
.double 0.7

.section .text

glabel func_8001577C
/* 01637C 8001577C 27BDFF70 */  addiu $sp, $sp, -0x90
/* 016380 80015780 AFBF002C */  sw    $ra, 0x2c($sp)
/* 016384 80015784 AFB20028 */  sw    $s2, 0x28($sp)
/* 016388 80015788 AFB10024 */  sw    $s1, 0x24($sp)
/* 01638C 8001578C AFB00020 */  sw    $s0, 0x20($sp)
/* 016390 80015790 AFA50094 */  sw    $a1, 0x94($sp)
/* 016394 80015794 AFA60098 */  sw    $a2, 0x98($sp)
/* 016398 80015798 848300AE */  lh    $v1, 0xae($a0)
/* 01639C 8001579C 3C058016 */  lui   $a1, %hi(gPathIndexByPlayerId) # 0x8016
/* 0163A0 800157A0 8C860008 */  lw    $a2, 8($a0)
/* 0163A4 800157A4 000370C0 */  sll   $t6, $v1, 3
/* 0163A8 800157A8 01C37023 */  subu  $t6, $t6, $v1
/* 0163AC 800157AC 000E7100 */  sll   $t6, $t6, 4
/* 0163B0 800157B0 C48E0004 */  lwc1  $f14, 4($a0)
/* 0163B4 800157B4 C48C0000 */  lwc1  $f12, ($a0)
/* 0163B8 800157B8 00034840 */  sll   $t1, $v1, 1
/* 0163BC 800157BC 00A92821 */  addu  $a1, $a1, $t1
/* 0163C0 800157C0 01C37023 */  subu  $t6, $t6, $v1
/* 0163C4 800157C4 94A545B0 */  lhu   $a1, %lo(gPathIndexByPlayerId)($a1) # 0x45b0($a1)
/* 0163C8 800157C8 3C12800E */  lui   $s2, %hi(gPlayerOne)
/* 0163CC 800157CC 000E7080 */  sll   $t6, $t6, 2
/* 0163D0 800157D0 3C0F8016 */  lui   $t7, %hi(gNearestWaypointByCameraId) # $t7, 0x8016
/* 0163D4 800157D4 8E52C4DC */  lw    $s2, %lo(gPlayerOne)($s2)
/* 0163D8 800157D8 25EF4668 */  addiu $t7, %lo(gNearestWaypointByCameraId) # addiu $t7, $t7, 0x4668
/* 0163DC 800157DC 00071040 */  sll   $v0, $a3, 1
/* 0163E0 800157E0 01C37023 */  subu  $t6, $t6, $v1
/* 0163E4 800157E4 00E08825 */  move  $s1, $a3
/* 0163E8 800157E8 000E70C0 */  sll   $t6, $t6, 3
/* 0163EC 800157EC 004F4021 */  addu  $t0, $v0, $t7
/* 0163F0 800157F0 00808025 */  move  $s0, $a0
/* 0163F4 800157F4 85070000 */  lh    $a3, ($t0)
/* 0163F8 800157F8 AFA80034 */  sw    $t0, 0x34($sp)
/* 0163FC 800157FC AFA20038 */  sw    $v0, 0x38($sp)
/* 016400 80015800 AFA9003C */  sw    $t1, 0x3c($sp)
/* 016404 80015804 AFA30074 */  sw    $v1, 0x74($sp)
/* 016408 80015808 AFA50010 */  sw    $a1, 0x10($sp)
/* 01640C 8001580C AFA50044 */  sw    $a1, 0x44($sp)
/* 016410 80015810 0C0034CF */  jal   func_8000D33C
/* 016414 80015814 024E9021 */   addu  $s2, $s2, $t6
/* 016418 80015818 8FA80034 */  lw    $t0, 0x34($sp)
/* 01641C 8001581C 8FA9003C */  lw    $t1, 0x3c($sp)
/* 016420 80015820 8FB80044 */  lw    $t8, 0x44($sp)
/* 016424 80015824 3C0A8016 */  lui   $t2, %hi(gNearestWaypointByPlayerId) # 0x8016
/* 016428 80015828 A5020000 */  sh    $v0, ($t0)
/* 01642C 8001582C 3C0C8016 */  lui   $t4, %hi(gWaypointCountByPathIndex) # 0x8016
/* 016430 80015830 01495021 */  addu  $t2, $t2, $t1
/* 016434 80015834 0018C840 */  sll   $t9, $t8, 1
/* 016438 80015838 854A4438 */  lh    $t2, %lo(gNearestWaypointByPlayerId)($t2) # 0x4438($t2)
/* 01643C 8001583C 850B0000 */  lh    $t3, ($t0)
/* 016440 80015840 01996021 */  addu  $t4, $t4, $t9
/* 016444 80015844 958C45C8 */  lhu   $t4, %lo(gWaypointCountByPathIndex)($t4) # 0x45c8($t4)
/* 016448 80015848 24060032 */  li    $a2, 50
/* 01644C 8001584C 2407000F */  li    $a3, 15
/* 016450 80015850 3144FFFF */  andi  $a0, $t2, 0xffff
/* 016454 80015854 A7AA008C */  sh    $t2, 0x8c($sp)
/* 016458 80015858 3165FFFF */  andi  $a1, $t3, 0xffff
/* 01645C 8001585C A7AB008E */  sh    $t3, 0x8e($sp)
/* 016460 80015860 0C001EFE */  jal   func_80007BF8
/* 016464 80015864 AFAC0010 */   sw    $t4, 0x10($sp)
/* 016468 80015868 8FA30074 */  lw    $v1, 0x74($sp)
/* 01646C 8001586C 87AA008C */  lh    $t2, 0x8c($sp)
/* 016470 80015870 1C40000E */  bgtz  $v0, .L800158AC
/* 016474 80015874 87AB008E */   lh    $t3, 0x8e($sp)
/* 016478 80015878 8FAD0038 */  lw    $t5, 0x38($sp)
/* 01647C 8001587C 00111880 */  sll   $v1, $s1, 2
/* 016480 80015880 3C058016 */  lui   $a1, %hi(D_80164680) # 0x8016
/* 016484 80015884 3C068016 */  lui   $a2, %hi(D_80164688) # 0x8016
/* 016488 80015888 00A32821 */  addu  $a1, $a1, $v1
/* 01648C 8001588C 00CD3021 */  addu  $a2, $a2, $t5
/* 016490 80015890 84C64680 */  lh    $a2, %lo(D_80164680)($a2) # 0x4680($a2)
/* 016494 80015894 8CA54688 */  lw    $a1, %lo(D_80164688)($a1) # 0x4688($a1)
/* 016498 80015898 AFA3003C */  sw    $v1, 0x3c($sp)
/* 01649C 8001589C 0C0068D2 */  jal   func_8001A348
/* 0164A0 800158A0 02202025 */   move  $a0, $s1
/* 0164A4 800158A4 10000042 */  b     .L800159B0
/* 0164A8 800158A8 8FA3003C */   lw    $v1, 0x3c($sp)
.L800158AC:
/* 0164AC 800158AC 00037080 */  sll   $t6, $v1, 2
/* 0164B0 800158B0 3C018016 */  lui   $at, %hi(D_80163068)
/* 0164B4 800158B4 002E0821 */  addu  $at, $at, $t6
/* 0164B8 800158B8 C4243068 */  lwc1  $f4, %lo(D_80163068)($at)
/* 0164BC 800158BC 3C01800F */  lui   $at, %hi(D_800ED220)
/* 0164C0 800158C0 D426D220 */  ldc1  $f6, %lo(D_800ED220)($at)
/* 0164C4 800158C4 46002021 */  cvt.d.s $f0, $f4
/* 0164C8 800158C8 3C018016 */  lui   $at, %hi(D_80164688)
/* 0164CC 800158CC 4626003C */  c.lt.d $f0, $f6
/* 0164D0 800158D0 00111880 */  sll   $v1, $s1, 2
/* 0164D4 800158D4 00230821 */  addu  $at, $at, $v1
/* 0164D8 800158D8 45000017 */  bc1f  .L80015938
/* 0164DC 800158DC 00000000 */   nop
/* 0164E0 800158E0 C4284688 */  lwc1  $f8, %lo(D_80164688)($at)
/* 0164E4 800158E4 3C01BFE0 */  li    $at, 0xBFE00000 # -1.750000
/* 0164E8 800158E8 44818800 */  mtc1  $at, $f17
/* 0164EC 800158EC 44808000 */  mtc1  $zero, $f16
/* 0164F0 800158F0 460042A1 */  cvt.d.s $f10, $f8
/* 0164F4 800158F4 014B1023 */  subu  $v0, $t2, $t3
/* 0164F8 800158F8 4630503C */  c.lt.d $f10, $f16
/* 0164FC 800158FC 00000000 */  nop
/* 016500 80015900 4500000D */  bc1f  .L80015938
/* 016504 80015904 00000000 */   nop
/* 016508 80015908 00420019 */  multu $v0, $v0
/* 01650C 8001590C 02202025 */  move  $a0, $s1
/* 016510 80015910 3C053F80 */  lui   $a1, 0x3f80
/* 016514 80015914 24060003 */  li    $a2, 3
/* 016518 80015918 00007812 */  mflo  $t7
/* 01651C 8001591C 29E10005 */  slti  $at, $t7, 5
/* 016520 80015920 10200005 */  beqz  $at, .L80015938
/* 016524 80015924 00000000 */   nop
/* 016528 80015928 0C0068D2 */  jal   func_8001A348
/* 01652C 8001592C AFA3003C */   sw    $v1, 0x3c($sp)
/* 016530 80015930 1000001F */  b     .L800159B0
/* 016534 80015934 8FA3003C */   lw    $v1, 0x3c($sp)
.L80015938:
/* 016538 80015938 3C01800F */  lui   $at, %hi(D_800ED228)
/* 01653C 8001593C D432D228 */  ldc1  $f18, %lo(D_800ED228)($at)
/* 016540 80015940 3C013FE0 */  li    $at, 0x3FE00000 # 1.750000
/* 016544 80015944 00111880 */  sll   $v1, $s1, 2
/* 016548 80015948 4620903C */  c.lt.d $f18, $f0
/* 01654C 8001594C 00000000 */  nop
/* 016550 80015950 45000017 */  bc1f  .L800159B0
/* 016554 80015954 00000000 */   nop
/* 016558 80015958 44812800 */  mtc1  $at, $f5
/* 01655C 8001595C 3C018016 */  lui   $at, %hi(D_80164688)
/* 016560 80015960 00230821 */  addu  $at, $at, $v1
/* 016564 80015964 C4264688 */  lwc1  $f6, %lo(D_80164688)($at)
/* 016568 80015968 44802000 */  mtc1  $zero, $f4
/* 01656C 8001596C 014B1023 */  subu  $v0, $t2, $t3
/* 016570 80015970 46003221 */  cvt.d.s $f8, $f6
/* 016574 80015974 4628203C */  c.lt.d $f4, $f8
/* 016578 80015978 00000000 */  nop
/* 01657C 8001597C 4500000C */  bc1f  .L800159B0
/* 016580 80015980 00000000 */   nop
/* 016584 80015984 00420019 */  multu $v0, $v0
/* 016588 80015988 02202025 */  move  $a0, $s1
/* 01658C 8001598C 3C05BF80 */  lui   $a1, 0xbf80
/* 016590 80015990 24060002 */  li    $a2, 2
/* 016594 80015994 0000C012 */  mflo  $t8
/* 016598 80015998 2B010005 */  slti  $at, $t8, 5
/* 01659C 8001599C 10200004 */  beqz  $at, .L800159B0
/* 0165A0 800159A0 00000000 */   nop
/* 0165A4 800159A4 0C0068D2 */  jal   func_8001A348
/* 0165A8 800159A8 AFA3003C */   sw    $v1, 0x3c($sp)
/* 0165AC 800159AC 8FA3003C */  lw    $v1, 0x3c($sp)
.L800159B0:
/* 0165B0 800159B0 3C018016 */  lui   $at, %hi(D_801645F8)
/* 0165B4 800159B4 00230821 */  addu  $at, $at, $v1
/* 0165B8 800159B8 C42A45F8 */  lwc1  $f10, %lo(D_801645F8)($at)
/* 0165BC 800159BC 3C018016 */  lui   $at, %hi(D_80164618)
/* 0165C0 800159C0 00230821 */  addu  $at, $at, $v1
/* 0165C4 800159C4 E60A0000 */  swc1  $f10, ($s0)
/* 0165C8 800159C8 C4304618 */  lwc1  $f16, %lo(D_80164618)($at)
/* 0165CC 800159CC 3C018016 */  lui   $at, %hi(D_80164638)
/* 0165D0 800159D0 00230821 */  addu  $at, $at, $v1
/* 0165D4 800159D4 E6100004 */  swc1  $f16, 4($s0)
/* 0165D8 800159D8 C4324638 */  lwc1  $f18, %lo(D_80164638)($at)
/* 0165DC 800159DC 3C014018 */  li    $at, 0x40180000 # 2.375000
/* 0165E0 800159E0 44815800 */  mtc1  $at, $f11
/* 0165E4 800159E4 E6120008 */  swc1  $f18, 8($s0)
/* 0165E8 800159E8 C6460014 */  lwc1  $f6, 0x14($s2)
/* 0165EC 800159EC 44805000 */  mtc1  $zero, $f10
/* 0165F0 800159F0 02202025 */  move  $a0, $s1
/* 0165F4 800159F4 E606000C */  swc1  $f6, 0xc($s0)
/* 0165F8 800159F8 C6440018 */  lwc1  $f4, 0x18($s2)
/* 0165FC 800159FC 46002221 */  cvt.d.s $f8, $f4
/* 016600 80015A00 462A4400 */  add.d $f16, $f8, $f10
/* 016604 80015A04 462084A0 */  cvt.s.d $f18, $f16
/* 016608 80015A08 E6120010 */  swc1  $f18, 0x10($s0)
/* 01660C 80015A0C C646001C */  lwc1  $f6, 0x1c($s2)
/* 016610 80015A10 E6060014 */  swc1  $f6, 0x14($s0)
/* 016614 80015A14 0C00534C */  jal   func_80014D30
/* 016618 80015A18 8FA50044 */   lw    $a1, 0x44($sp)
/* 01661C 80015A1C C60A0010 */  lwc1  $f10, 0x10($s0)
/* 016620 80015A20 C6100004 */  lwc1  $f16, 4($s0)
/* 016624 80015A24 C604000C */  lwc1  $f4, 0xc($s0)
/* 016628 80015A28 C6080000 */  lwc1  $f8, ($s0)
/* 01662C 80015A2C 46105481 */  sub.s $f18, $f10, $f16
/* 016630 80015A30 46082301 */  sub.s $f12, $f4, $f8
/* 016634 80015A34 E7B20080 */  swc1  $f18, 0x80($sp)
/* 016638 80015A38 C6040008 */  lwc1  $f4, 8($s0)
/* 01663C 80015A3C C6060014 */  lwc1  $f6, 0x14($s0)
/* 016640 80015A40 E7AC0084 */  swc1  $f12, 0x84($sp)
/* 016644 80015A44 46043381 */  sub.s $f14, $f6, $f4
/* 016648 80015A48 0C0ADE0C */  jal   atan2s
/* 01664C 80015A4C E7AE007C */   swc1  $f14, 0x7c($sp)
/* 016650 80015A50 C7A00084 */  lwc1  $f0, 0x84($sp)
/* 016654 80015A54 C7AE007C */  lwc1  $f14, 0x7c($sp)
/* 016658 80015A58 A6020026 */  sh    $v0, 0x26($s0)
/* 01665C 80015A5C 46000202 */  mul.s $f8, $f0, $f0
/* 016660 80015A60 00000000 */  nop
/* 016664 80015A64 460E7282 */  mul.s $f10, $f14, $f14
/* 016668 80015A68 0C033850 */  jal   sqrtf
/* 01666C 80015A6C 460A4300 */   add.s $f12, $f8, $f10
/* 016670 80015A70 46000306 */  mov.s $f12, $f0
/* 016674 80015A74 0C0ADE0C */  jal   atan2s
/* 016678 80015A78 C7AE0080 */   lwc1  $f14, 0x80($sp)
/* 01667C 80015A7C A6020024 */  sh    $v0, 0x24($s0)
/* 016680 80015A80 A6000028 */  sh    $zero, 0x28($s0)
/* 016684 80015A84 8FBF002C */  lw    $ra, 0x2c($sp)
/* 016688 80015A88 8FB20028 */  lw    $s2, 0x28($sp)
/* 01668C 80015A8C 8FB10024 */  lw    $s1, 0x24($sp)
/* 016690 80015A90 8FB00020 */  lw    $s0, 0x20($sp)
/* 016694 80015A94 03E00008 */  jr    $ra
/* 016698 80015A98 27BD0090 */   addiu $sp, $sp, 0x90
