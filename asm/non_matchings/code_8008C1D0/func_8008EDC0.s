glabel func_8008EDC0
/* 08F9C0 8008EDC0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 08F9C4 8008EDC4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 08F9C8 8008EDC8 948E0256 */  lhu   $t6, 0x256($a0)
/* 08F9CC 8008EDCC C4840214 */  lwc1  $f4, 0x214($a0)
/* 08F9D0 8008EDD0 00803825 */  move  $a3, $a0
/* 08F9D4 8008EDD4 19C00004 */  blez  $t6, .L8008EDE8
/* 08F9D8 8008EDD8 E484009C */   swc1  $f4, 0x9c($a0)
/* 08F9DC 8008EDDC 44803000 */  mtc1  $zero, $f6
/* 08F9E0 8008EDE0 00000000 */  nop   
/* 08F9E4 8008EDE4 E486009C */  swc1  $f6, 0x9c($a0)
.L8008EDE8:
/* 08F9E8 8008EDE8 94EF00F8 */  lhu   $t7, 0xf8($a3)
/* 08F9EC 8008EDEC 240100FE */  li    $at, 254
/* 08F9F0 8008EDF0 24E40080 */  addiu $a0, $a3, 0x80
/* 08F9F4 8008EDF4 11E1000D */  beq   $t7, $at, .L8008EE2C
/* 08F9F8 8008EDF8 3C0543C8 */   lui   $a1, 0x43c8
/* 08F9FC 8008EDFC 8CF800BC */  lw    $t8, 0xbc($a3)
/* 08FA00 8008EE00 24010008 */  li    $at, 8
/* 08FA04 8008EE04 3C063F80 */  lui   $a2, 0x3f80
/* 08FA08 8008EE08 33190008 */  andi  $t9, $t8, 8
/* 08FA0C 8008EE0C 53210008 */  beql  $t9, $at, .L8008EE30
/* 08FA10 8008EE10 3C063C23 */   lui   $a2, 0x3c23
/* 08FA14 8008EE14 24E40080 */  addiu $a0, $a3, 0x80
/* 08FA18 8008EE18 24050000 */  li    $a1, 0
/* 08FA1C 8008EE1C 0C008973 */  jal   move_f32_towards
/* 08FA20 8008EE20 AFA70018 */   sw    $a3, 0x18($sp)
/* 08FA24 8008EE24 10000006 */  b     .L8008EE40
/* 08FA28 8008EE28 8FA70018 */   lw    $a3, 0x18($sp)
.L8008EE2C:
/* 08FA2C 8008EE2C 3C063C23 */  lui   $a2, (0x3C23D70A >> 16) # lui $a2, 0x3c23
.L8008EE30:
/* 08FA30 8008EE30 34C6D70A */  ori   $a2, (0x3C23D70A & 0xFFFF) # ori $a2, $a2, 0xd70a
/* 08FA34 8008EE34 0C008973 */  jal   move_f32_towards
/* 08FA38 8008EE38 AFA70018 */   sw    $a3, 0x18($sp)
/* 08FA3C 8008EE3C 8FA70018 */  lw    $a3, 0x18($sp)
.L8008EE40:
/* 08FA40 8008EE40 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 08FA44 8008EE44 44814000 */  mtc1  $at, $f8
/* 08FA48 8008EE48 C4EA0080 */  lwc1  $f10, 0x80($a3)
/* 08FA4C 8008EE4C 3C01FFEF */  lui   $at, (0xFFEFFFFF >> 16) # lui $at, 0xffef
/* 08FA50 8008EE50 3421FFFF */  ori   $at, (0xFFEFFFFF & 0xFFFF) # ori $at, $at, 0xffff
/* 08FA54 8008EE54 4608503E */  c.le.s $f10, $f8
/* 08FA58 8008EE58 00000000 */  nop   
/* 08FA5C 8008EE5C 45020016 */  bc1fl .L8008EEB8
/* 08FA60 8008EE60 8FBF0014 */   lw    $ra, 0x14($sp)
/* 08FA64 8008EE64 8CE800BC */  lw    $t0, 0xbc($a3)
/* 08FA68 8008EE68 84EA00C2 */  lh    $t2, 0xc2($a3)
/* 08FA6C 8008EE6C 44808000 */  mtc1  $zero, $f16
/* 08FA70 8008EE70 01014824 */  and   $t1, $t0, $at
/* 08FA74 8008EE74 29410033 */  slti  $at, $t2, 0x33
/* 08FA78 8008EE78 ACE900BC */  sw    $t1, 0xbc($a3)
/* 08FA7C 8008EE7C 1420000D */  bnez  $at, .L8008EEB4
/* 08FA80 8008EE80 E4F00080 */   swc1  $f16, 0x80($a3)
/* 08FA84 8008EE84 C4F2009C */  lwc1  $f18, 0x9c($a3)
/* 08FA88 8008EE88 3C01800F */  lui   $at, %hi(D_800EF5A0)
/* 08FA8C 8008EE8C D420F5A0 */  ldc1  $f0, %lo(D_800EF5A0)($at)
/* 08FA90 8008EE90 C4EA008C */  lwc1  $f10, 0x8c($a3)
/* 08FA94 8008EE94 46009121 */  cvt.d.s $f4, $f18
/* 08FA98 8008EE98 46202182 */  mul.d $f6, $f4, $f0
/* 08FA9C 8008EE9C 46005421 */  cvt.d.s $f16, $f10
/* 08FAA0 8008EEA0 46208482 */  mul.d $f18, $f16, $f0
/* 08FAA4 8008EEA4 46203220 */  cvt.s.d $f8, $f6
/* 08FAA8 8008EEA8 46209120 */  cvt.s.d $f4, $f18
/* 08FAAC 8008EEAC E4E8009C */  swc1  $f8, 0x9c($a3)
/* 08FAB0 8008EEB0 E4E4008C */  swc1  $f4, 0x8c($a3)
.L8008EEB4:
/* 08FAB4 8008EEB4 8FBF0014 */  lw    $ra, 0x14($sp)
.L8008EEB8:
/* 08FAB8 8008EEB8 27BD0018 */  addiu $sp, $sp, 0x18
/* 08FABC 8008EEBC 03E00008 */  jr    $ra
/* 08FAC0 8008EEC0 00000000 */   nop   
