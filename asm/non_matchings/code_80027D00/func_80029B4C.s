glabel func_80029B4C
/* 02A74C 80029B4C 27BDFF58 */  addiu $sp, $sp, -0xa8
/* 02A750 80029B50 AFBF0024 */  sw    $ra, 0x24($sp)
/* 02A754 80029B54 AFB00020 */  sw    $s0, 0x20($sp)
/* 02A758 80029B58 AFA500AC */  sw    $a1, 0xac($sp)
/* 02A75C 80029B5C AFA600B0 */  sw    $a2, 0xb0($sp)
/* 02A760 80029B60 AFA700B4 */  sw    $a3, 0xb4($sp)
/* 02A764 80029B64 8C8E00BC */  lw    $t6, 0xbc($a0)
/* 02A768 80029B68 3C024000 */  lui   $v0, 0x4000
/* 02A76C 80029B6C 44800000 */  mtc1  $zero, $f0
/* 02A770 80029B70 01C27824 */  and   $t7, $t6, $v0
/* 02A774 80029B74 144F0018 */  bne   $v0, $t7, .L80029BD8
/* 02A778 80029B78 00808025 */   move  $s0, $a0
/* 02A77C 80029B7C 94980254 */  lhu   $t8, 0x254($a0)
/* 02A780 80029B80 3C01800E */  lui   $at, %hi(D_800DDBD4)
/* 02A784 80029B84 C4900224 */  lwc1  $f16, 0x224($a0)
/* 02A788 80029B88 0018C880 */  sll   $t9, $t8, 2
/* 02A78C 80029B8C 00390821 */  addu  $at, $at, $t9
/* 02A790 80029B90 C424DBD4 */  lwc1  $f4, %lo(D_800DDBD4)($at)
/* 02A794 80029B94 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 02A798 80029B98 44813000 */  mtc1  $at, $f6
/* 02A79C 80029B9C 3C013FF8 */  li    $at, 0x3FF80000 # 1.937500
/* 02A7A0 80029BA0 44812800 */  mtc1  $at, $f5
/* 02A7A4 80029BA4 46062203 */  div.s $f8, $f4, $f6
/* 02A7A8 80029BA8 44802000 */  mtc1  $zero, $f4
/* 02A7AC 80029BAC 3C014032 */  li    $at, 0x40320000 # 2.781250
/* 02A7B0 80029BB0 44818800 */  mtc1  $at, $f17
/* 02A7B4 80029BB4 460084A1 */  cvt.d.s $f18, $f16
/* 02A7B8 80029BB8 44808000 */  mtc1  $zero, $f16
/* 02A7BC 80029BBC 46249182 */  mul.d $f6, $f18, $f4
/* 02A7C0 80029BC0 460042A1 */  cvt.d.s $f10, $f8
/* 02A7C4 80029BC4 46265202 */  mul.d $f8, $f10, $f6
/* 02A7C8 80029BC8 00000000 */  nop   
/* 02A7CC 80029BCC 46304482 */  mul.d $f18, $f8, $f16
/* 02A7D0 80029BD0 1000000D */  b     .L80029C08
/* 02A7D4 80029BD4 46209320 */   cvt.s.d $f12, $f18
.L80029BD8:
/* 02A7D8 80029BD8 96080254 */  lhu   $t0, 0x254($s0)
/* 02A7DC 80029BDC 3C01800E */  lui   $at, %hi(D_800DDBD4)
/* 02A7E0 80029BE0 00084880 */  sll   $t1, $t0, 2
/* 02A7E4 80029BE4 00290821 */  addu  $at, $at, $t1
/* 02A7E8 80029BE8 C424DBD4 */  lwc1  $f4, %lo(D_800DDBD4)($at)
/* 02A7EC 80029BEC 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 02A7F0 80029BF0 44815000 */  mtc1  $at, $f10
/* 02A7F4 80029BF4 3C014190 */  li    $at, 0x41900000 # 18.000000
/* 02A7F8 80029BF8 44814000 */  mtc1  $at, $f8
/* 02A7FC 80029BFC 460A2183 */  div.s $f6, $f4, $f10
/* 02A800 80029C00 46083302 */  mul.s $f12, $f6, $f8
/* 02A804 80029C04 00000000 */  nop   
.L80029C08:
/* 02A808 80029C08 860A002E */  lh    $t2, 0x2e($s0)
/* 02A80C 80029C0C 860B00C0 */  lh    $t3, 0xc0($s0)
/* 02A810 80029C10 44050000 */  mfc1  $a1, $f0
/* 02A814 80029C14 44070000 */  mfc1  $a3, $f0
/* 02A818 80029C18 014B6021 */  addu  $t4, $t2, $t3
/* 02A81C 80029C1C AFAC0010 */  sw    $t4, 0x10($sp)
/* 02A820 80029C20 E7AC0048 */  swc1  $f12, 0x48($sp)
/* 02A824 80029C24 27A4005C */  addiu $a0, $sp, 0x5c
/* 02A828 80029C28 0C0AD950 */  jal   func_802B6540
/* 02A82C 80029C2C 3C063F80 */   lui   $a2, 0x3f80
/* 02A830 80029C30 C7AC0048 */  lwc1  $f12, 0x48($sp)
/* 02A834 80029C34 3C01800F */  lui   $at, %hi(D_800ED798)
/* 02A838 80029C38 D430D798 */  ldc1  $f16, %lo(D_800ED798)($at)
/* 02A83C 80029C3C 46006021 */  cvt.d.s $f0, $f12
/* 02A840 80029C40 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 02A844 80029C44 46300481 */  sub.d $f18, $f0, $f16
/* 02A848 80029C48 44814000 */  mtc1  $at, $f8
/* 02A84C 80029C4C 27A4008C */  addiu $a0, $sp, 0x8c
/* 02A850 80029C50 27A5005C */  addiu $a1, $sp, 0x5c
/* 02A854 80029C54 46209120 */  cvt.s.d $f4, $f18
/* 02A858 80029C58 46086081 */  sub.s $f2, $f12, $f8
/* 02A85C 80029C5C E7A4008C */  swc1  $f4, 0x8c($sp)
/* 02A860 80029C60 C60A0070 */  lwc1  $f10, 0x70($s0)
/* 02A864 80029C64 F7A00038 */  sdc1  $f0, 0x38($sp)
/* 02A868 80029C68 E7A20094 */  swc1  $f2, 0x94($sp)
/* 02A86C 80029C6C 46005187 */  neg.s $f6, $f10
/* 02A870 80029C70 E7A20040 */  swc1  $f2, 0x40($sp)
/* 02A874 80029C74 0C0AD8EE */  jal   func_802B63B8
/* 02A878 80029C78 E7A60090 */   swc1  $f6, 0x90($sp)
/* 02A87C 80029C7C C6100198 */  lwc1  $f16, 0x198($s0)
/* 02A880 80029C80 C7AA008C */  lwc1  $f10, 0x8c($sp)
/* 02A884 80029C84 02002025 */  move  $a0, $s0
/* 02A888 80029C88 E7B00080 */  swc1  $f16, 0x80($sp)
/* 02A88C 80029C8C C612019C */  lwc1  $f18, 0x19c($s0)
/* 02A890 80029C90 26050198 */  addiu $a1, $s0, 0x198
/* 02A894 80029C94 E7B20084 */  swc1  $f18, 0x84($sp)
/* 02A898 80029C98 C60401A0 */  lwc1  $f4, 0x1a0($s0)
/* 02A89C 80029C9C E7A40088 */  swc1  $f4, 0x88($sp)
/* 02A8A0 80029CA0 C6060014 */  lwc1  $f6, 0x14($s0)
/* 02A8A4 80029CA4 C6120018 */  lwc1  $f18, 0x18($s0)
/* 02A8A8 80029CA8 46065200 */  add.s $f8, $f10, $f6
/* 02A8AC 80029CAC C606001C */  lwc1  $f6, 0x1c($s0)
/* 02A8B0 80029CB0 E6080198 */  swc1  $f8, 0x198($s0)
/* 02A8B4 80029CB4 C7B00090 */  lwc1  $f16, 0x90($sp)
/* 02A8B8 80029CB8 46128100 */  add.s $f4, $f16, $f18
/* 02A8BC 80029CBC E604019C */  swc1  $f4, 0x19c($s0)
/* 02A8C0 80029CC0 C7AA0094 */  lwc1  $f10, 0x94($sp)
/* 02A8C4 80029CC4 46065200 */  add.s $f8, $f10, $f6
/* 02A8C8 80029CC8 E60801A0 */  swc1  $f8, 0x1a0($s0)
/* 02A8CC 80029CCC C7B00088 */  lwc1  $f16, 0x88($sp)
/* 02A8D0 80029CD0 8FA70084 */  lw    $a3, 0x84($sp)
/* 02A8D4 80029CD4 8FA60080 */  lw    $a2, 0x80($sp)
/* 02A8D8 80029CD8 0C0ABE8D */  jal   func_802AFA34
/* 02A8DC 80029CDC E7B00010 */   swc1  $f16, 0x10($sp)
/* 02A8E0 80029CE0 C7AC0048 */  lwc1  $f12, 0x48($sp)
/* 02A8E4 80029CE4 3C01800F */  lui   $at, %hi(D_800ED7A0)
/* 02A8E8 80029CE8 D432D7A0 */  ldc1  $f18, %lo(D_800ED7A0)($at)
/* 02A8EC 80029CEC 46006387 */  neg.s $f14, $f12
/* 02A8F0 80029CF0 C7B00040 */  lwc1  $f16, 0x40($sp)
/* 02A8F4 80029CF4 460070A1 */  cvt.d.s $f2, $f14
/* 02A8F8 80029CF8 27A4008C */  addiu $a0, $sp, 0x8c
/* 02A8FC 80029CFC 46321100 */  add.d $f4, $f2, $f18
/* 02A900 80029D00 27A5005C */  addiu $a1, $sp, 0x5c
/* 02A904 80029D04 462022A0 */  cvt.s.d $f10, $f4
/* 02A908 80029D08 E7AA008C */  swc1  $f10, 0x8c($sp)
/* 02A90C 80029D0C C6060070 */  lwc1  $f6, 0x70($s0)
/* 02A910 80029D10 E7AE0034 */  swc1  $f14, 0x34($sp)
/* 02A914 80029D14 F7A20028 */  sdc1  $f2, 0x28($sp)
/* 02A918 80029D18 46003207 */  neg.s $f8, $f6
/* 02A91C 80029D1C E7B00094 */  swc1  $f16, 0x94($sp)
/* 02A920 80029D20 0C0AD8EE */  jal   func_802B63B8
/* 02A924 80029D24 E7A80090 */   swc1  $f8, 0x90($sp)
/* 02A928 80029D28 C61201B0 */  lwc1  $f18, 0x1b0($s0)
/* 02A92C 80029D2C C7A6008C */  lwc1  $f6, 0x8c($sp)
/* 02A930 80029D30 02002025 */  move  $a0, $s0
/* 02A934 80029D34 E7B20080 */  swc1  $f18, 0x80($sp)
/* 02A938 80029D38 C60401B4 */  lwc1  $f4, 0x1b4($s0)
/* 02A93C 80029D3C 260501B0 */  addiu $a1, $s0, 0x1b0
/* 02A940 80029D40 E7A40084 */  swc1  $f4, 0x84($sp)
/* 02A944 80029D44 C60A01B8 */  lwc1  $f10, 0x1b8($s0)
/* 02A948 80029D48 E7AA0088 */  swc1  $f10, 0x88($sp)
/* 02A94C 80029D4C C6080014 */  lwc1  $f8, 0x14($s0)
/* 02A950 80029D50 C6040018 */  lwc1  $f4, 0x18($s0)
/* 02A954 80029D54 46083400 */  add.s $f16, $f6, $f8
/* 02A958 80029D58 C608001C */  lwc1  $f8, 0x1c($s0)
/* 02A95C 80029D5C E61001B0 */  swc1  $f16, 0x1b0($s0)
/* 02A960 80029D60 C7B20090 */  lwc1  $f18, 0x90($sp)
/* 02A964 80029D64 46049280 */  add.s $f10, $f18, $f4
/* 02A968 80029D68 E60A01B4 */  swc1  $f10, 0x1b4($s0)
/* 02A96C 80029D6C C7A60094 */  lwc1  $f6, 0x94($sp)
/* 02A970 80029D70 46083400 */  add.s $f16, $f6, $f8
/* 02A974 80029D74 E61001B8 */  swc1  $f16, 0x1b8($s0)
/* 02A978 80029D78 C7B20088 */  lwc1  $f18, 0x88($sp)
/* 02A97C 80029D7C 8FA70084 */  lw    $a3, 0x84($sp)
/* 02A980 80029D80 8FA60080 */  lw    $a2, 0x80($sp)
/* 02A984 80029D84 0C0ABE8D */  jal   func_802AFA34
/* 02A988 80029D88 E7B20010 */   swc1  $f18, 0x10($sp)
/* 02A98C 80029D8C 3C01800F */  lui   $at, %hi(D_800ED7A8)
/* 02A990 80029D90 D7A00038 */  ldc1  $f0, 0x38($sp)
/* 02A994 80029D94 D424D7A8 */  ldc1  $f4, %lo(D_800ED7A8)($at)
/* 02A998 80029D98 3C014080 */  li    $at, 0x40800000 # 4.000000
/* 02A99C 80029D9C C7B20034 */  lwc1  $f18, 0x34($sp)
/* 02A9A0 80029DA0 46240281 */  sub.d $f10, $f0, $f4
/* 02A9A4 80029DA4 44812000 */  mtc1  $at, $f4
/* 02A9A8 80029DA8 27A4008C */  addiu $a0, $sp, 0x8c
/* 02A9AC 80029DAC 27A5005C */  addiu $a1, $sp, 0x5c
/* 02A9B0 80029DB0 462051A0 */  cvt.s.d $f6, $f10
/* 02A9B4 80029DB4 46049300 */  add.s $f12, $f18, $f4
/* 02A9B8 80029DB8 E7A6008C */  swc1  $f6, 0x8c($sp)
/* 02A9BC 80029DBC C6080070 */  lwc1  $f8, 0x70($s0)
/* 02A9C0 80029DC0 E7AC0094 */  swc1  $f12, 0x94($sp)
/* 02A9C4 80029DC4 46004407 */  neg.s $f16, $f8
/* 02A9C8 80029DC8 E7AC0040 */  swc1  $f12, 0x40($sp)
/* 02A9CC 80029DCC 0C0AD8EE */  jal   func_802B63B8
/* 02A9D0 80029DD0 E7B00090 */   swc1  $f16, 0x90($sp)
/* 02A9D4 80029DD4 C60A01C8 */  lwc1  $f10, 0x1c8($s0)
/* 02A9D8 80029DD8 C7B0008C */  lwc1  $f16, 0x8c($sp)
/* 02A9DC 80029DDC 02002025 */  move  $a0, $s0
/* 02A9E0 80029DE0 E7AA0080 */  swc1  $f10, 0x80($sp)
/* 02A9E4 80029DE4 C60601CC */  lwc1  $f6, 0x1cc($s0)
/* 02A9E8 80029DE8 260501C8 */  addiu $a1, $s0, 0x1c8
/* 02A9EC 80029DEC E7A60084 */  swc1  $f6, 0x84($sp)
/* 02A9F0 80029DF0 C60801D0 */  lwc1  $f8, 0x1d0($s0)
/* 02A9F4 80029DF4 E7A80088 */  swc1  $f8, 0x88($sp)
/* 02A9F8 80029DF8 C6120014 */  lwc1  $f18, 0x14($s0)
/* 02A9FC 80029DFC C6060018 */  lwc1  $f6, 0x18($s0)
/* 02AA00 80029E00 46128100 */  add.s $f4, $f16, $f18
/* 02AA04 80029E04 C612001C */  lwc1  $f18, 0x1c($s0)
/* 02AA08 80029E08 E60401C8 */  swc1  $f4, 0x1c8($s0)
/* 02AA0C 80029E0C C7AA0090 */  lwc1  $f10, 0x90($sp)
/* 02AA10 80029E10 46065200 */  add.s $f8, $f10, $f6
/* 02AA14 80029E14 E60801CC */  swc1  $f8, 0x1cc($s0)
/* 02AA18 80029E18 C7B00094 */  lwc1  $f16, 0x94($sp)
/* 02AA1C 80029E1C 46128100 */  add.s $f4, $f16, $f18
/* 02AA20 80029E20 E60401D0 */  swc1  $f4, 0x1d0($s0)
/* 02AA24 80029E24 C7AA0088 */  lwc1  $f10, 0x88($sp)
/* 02AA28 80029E28 8FA70084 */  lw    $a3, 0x84($sp)
/* 02AA2C 80029E2C 8FA60080 */  lw    $a2, 0x80($sp)
/* 02AA30 80029E30 0C0ABE8D */  jal   func_802AFA34
/* 02AA34 80029E34 E7AA0010 */   swc1  $f10, 0x10($sp)
/* 02AA38 80029E38 3C01800F */  lui   $at, %hi(D_800ED7B0)
/* 02AA3C 80029E3C D7A20028 */  ldc1  $f2, 0x28($sp)
/* 02AA40 80029E40 D426D7B0 */  ldc1  $f6, %lo(D_800ED7B0)($at)
/* 02AA44 80029E44 C7AA0040 */  lwc1  $f10, 0x40($sp)
/* 02AA48 80029E48 27A4008C */  addiu $a0, $sp, 0x8c
/* 02AA4C 80029E4C 46261200 */  add.d $f8, $f2, $f6
/* 02AA50 80029E50 27A5005C */  addiu $a1, $sp, 0x5c
/* 02AA54 80029E54 46204420 */  cvt.s.d $f16, $f8
/* 02AA58 80029E58 E7B0008C */  swc1  $f16, 0x8c($sp)
/* 02AA5C 80029E5C C6120070 */  lwc1  $f18, 0x70($s0)
/* 02AA60 80029E60 E7AA0094 */  swc1  $f10, 0x94($sp)
/* 02AA64 80029E64 46009107 */  neg.s $f4, $f18
/* 02AA68 80029E68 0C0AD8EE */  jal   func_802B63B8
/* 02AA6C 80029E6C E7A40090 */   swc1  $f4, 0x90($sp)
/* 02AA70 80029E70 C60601E0 */  lwc1  $f6, 0x1e0($s0)
/* 02AA74 80029E74 C7B2008C */  lwc1  $f18, 0x8c($sp)
/* 02AA78 80029E78 02002025 */  move  $a0, $s0
/* 02AA7C 80029E7C E7A60080 */  swc1  $f6, 0x80($sp)
/* 02AA80 80029E80 C60801E4 */  lwc1  $f8, 0x1e4($s0)
/* 02AA84 80029E84 260501E0 */  addiu $a1, $s0, 0x1e0
/* 02AA88 80029E88 E7A80084 */  swc1  $f8, 0x84($sp)
/* 02AA8C 80029E8C C61001E8 */  lwc1  $f16, 0x1e8($s0)
/* 02AA90 80029E90 E7B00088 */  swc1  $f16, 0x88($sp)
/* 02AA94 80029E94 C6040014 */  lwc1  $f4, 0x14($s0)
/* 02AA98 80029E98 C6080018 */  lwc1  $f8, 0x18($s0)
/* 02AA9C 80029E9C 46049280 */  add.s $f10, $f18, $f4
/* 02AAA0 80029EA0 C604001C */  lwc1  $f4, 0x1c($s0)
/* 02AAA4 80029EA4 E60A01E0 */  swc1  $f10, 0x1e0($s0)
/* 02AAA8 80029EA8 C7A60090 */  lwc1  $f6, 0x90($sp)
/* 02AAAC 80029EAC 46083400 */  add.s $f16, $f6, $f8
/* 02AAB0 80029EB0 E61001E4 */  swc1  $f16, 0x1e4($s0)
/* 02AAB4 80029EB4 C7B20094 */  lwc1  $f18, 0x94($sp)
/* 02AAB8 80029EB8 46049280 */  add.s $f10, $f18, $f4
/* 02AABC 80029EBC E60A01E8 */  swc1  $f10, 0x1e8($s0)
/* 02AAC0 80029EC0 C7A60088 */  lwc1  $f6, 0x88($sp)
/* 02AAC4 80029EC4 8FA70084 */  lw    $a3, 0x84($sp)
/* 02AAC8 80029EC8 8FA60080 */  lw    $a2, 0x80($sp)
/* 02AACC 80029ECC 0C0ABE8D */  jal   func_802AFA34
/* 02AAD0 80029ED0 E7A60010 */   swc1  $f6, 0x10($sp)
/* 02AAD4 80029ED4 8E0D00BC */  lw    $t5, 0xbc($s0)
/* 02AAD8 80029ED8 31AE0008 */  andi  $t6, $t5, 8
/* 02AADC 80029EDC 55C0002E */  bnel  $t6, $zero, .L80029F98
/* 02AAE0 80029EE0 960F0254 */   lhu   $t7, 0x254($s0)
/* 02AAE4 80029EE4 C60801A8 */  lwc1  $f8, 0x1a8($s0)
/* 02AAE8 80029EE8 C61001D8 */  lwc1  $f16, 0x1d8($s0)
/* 02AAEC 80029EEC 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 02AAF0 80029EF0 44812000 */  mtc1  $at, $f4
/* 02AAF4 80029EF4 46104480 */  add.s $f18, $f8, $f16
/* 02AAF8 80029EF8 26040230 */  addiu $a0, $s0, 0x230
/* 02AAFC 80029EFC 3C063F00 */  lui   $a2, 0x3f00
/* 02AB00 80029F00 46049003 */  div.s $f0, $f18, $f4
/* 02AB04 80029F04 44050000 */  mfc1  $a1, $f0
/* 02AB08 80029F08 0C008973 */  jal   move_f32_towards
/* 02AB0C 80029F0C 00000000 */   nop   
/* 02AB10 80029F10 C60A01C0 */  lwc1  $f10, 0x1c0($s0)
/* 02AB14 80029F14 C60601F0 */  lwc1  $f6, 0x1f0($s0)
/* 02AB18 80029F18 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 02AB1C 80029F1C 44818000 */  mtc1  $at, $f16
/* 02AB20 80029F20 46065200 */  add.s $f8, $f10, $f6
/* 02AB24 80029F24 2604023C */  addiu $a0, $s0, 0x23c
/* 02AB28 80029F28 3C063F00 */  lui   $a2, 0x3f00
/* 02AB2C 80029F2C 46104003 */  div.s $f0, $f8, $f16
/* 02AB30 80029F30 44050000 */  mfc1  $a1, $f0
/* 02AB34 80029F34 0C008973 */  jal   move_f32_towards
/* 02AB38 80029F38 00000000 */   nop   
/* 02AB3C 80029F3C C61201A8 */  lwc1  $f18, 0x1a8($s0)
/* 02AB40 80029F40 C60401C0 */  lwc1  $f4, 0x1c0($s0)
/* 02AB44 80029F44 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 02AB48 80029F48 44813000 */  mtc1  $at, $f6
/* 02AB4C 80029F4C 46049280 */  add.s $f10, $f18, $f4
/* 02AB50 80029F50 260401FC */  addiu $a0, $s0, 0x1fc
/* 02AB54 80029F54 3C063F00 */  lui   $a2, 0x3f00
/* 02AB58 80029F58 46065003 */  div.s $f0, $f10, $f6
/* 02AB5C 80029F5C 44050000 */  mfc1  $a1, $f0
/* 02AB60 80029F60 0C008973 */  jal   move_f32_towards
/* 02AB64 80029F64 00000000 */   nop   
/* 02AB68 80029F68 C60801D8 */  lwc1  $f8, 0x1d8($s0)
/* 02AB6C 80029F6C C61001F0 */  lwc1  $f16, 0x1f0($s0)
/* 02AB70 80029F70 3C014000 */  li    $at, 0x40000000 # 2.000000
/* 02AB74 80029F74 44812000 */  mtc1  $at, $f4
/* 02AB78 80029F78 46104480 */  add.s $f18, $f8, $f16
/* 02AB7C 80029F7C 260401F8 */  addiu $a0, $s0, 0x1f8
/* 02AB80 80029F80 3C063F00 */  lui   $a2, 0x3f00
/* 02AB84 80029F84 46049003 */  div.s $f0, $f18, $f4
/* 02AB88 80029F88 44050000 */  mfc1  $a1, $f0
/* 02AB8C 80029F8C 0C008973 */  jal   move_f32_towards
/* 02AB90 80029F90 00000000 */   nop   
/* 02AB94 80029F94 960F0254 */  lhu   $t7, 0x254($s0)
.L80029F98:
/* 02AB98 80029F98 3C01800E */  lui   $at, %hi(D_800DDBD4)
/* 02AB9C 80029F9C C6040224 */  lwc1  $f4, 0x224($s0)
/* 02ABA0 80029FA0 000FC080 */  sll   $t8, $t7, 2
/* 02ABA4 80029FA4 00380821 */  addu  $at, $at, $t8
/* 02ABA8 80029FA8 C42ADBD4 */  lwc1  $f10, %lo(D_800DDBD4)($at)
/* 02ABAC 80029FAC 3C014190 */  li    $at, 0x41900000 # 18.000000
/* 02ABB0 80029FB0 44813000 */  mtc1  $at, $f6
/* 02ABB4 80029FB4 3C013F80 */  li    $at, 0x3F800000 # 1.000000
/* 02ABB8 80029FB8 44818000 */  mtc1  $at, $f16
/* 02ABBC 80029FBC 46065202 */  mul.s $f8, $f10, $f6
/* 02ABC0 80029FC0 C6060230 */  lwc1  $f6, 0x230($s0)
/* 02ABC4 80029FC4 C60A023C */  lwc1  $f10, 0x23c($s0)
/* 02ABC8 80029FC8 46065001 */  sub.s $f0, $f10, $f6
/* 02ABCC 80029FCC 46104480 */  add.s $f18, $f8, $f16
/* 02ABD0 80029FD0 46049082 */  mul.s $f2, $f18, $f4
/* 02ABD4 80029FD4 46020303 */  div.s $f12, $f0, $f2
/* 02ABD8 80029FD8 0C0ADF10 */  jal   func_802B7C40
/* 02ABDC 80029FDC E7A20050 */   swc1  $f2, 0x50($sp)
/* 02ABE0 80029FE0 860800CA */  lh    $t0, 0xca($s0)
/* 02ABE4 80029FE4 C7A20050 */  lwc1  $f2, 0x50($sp)
/* 02ABE8 80029FE8 0002C823 */  negu  $t9, $v0
/* 02ABEC 80029FEC 24010002 */  li    $at, 2
/* 02ABF0 80029FF0 31090002 */  andi  $t1, $t0, 2
/* 02ABF4 80029FF4 11210005 */  beq   $t1, $at, .L8002A00C
/* 02ABF8 80029FF8 A6190206 */   sh    $t9, 0x206($s0)
/* 02ABFC 80029FFC 8E0200BC */  lw    $v0, 0xbc($s0)
/* 02AC00 8002A000 304A0008 */  andi  $t2, $v0, 8
/* 02AC04 8002A004 11400005 */  beqz  $t2, .L8002A01C
/* 02AC08 8002A008 01401025 */   move  $v0, $t2
.L8002A00C:
/* 02AC0C 8002A00C 8E0200BC */  lw    $v0, 0xbc($s0)
/* 02AC10 8002A010 A6000206 */  sh    $zero, 0x206($s0)
/* 02AC14 8002A014 304B0008 */  andi  $t3, $v0, 8
/* 02AC18 8002A018 01601025 */  move  $v0, $t3
.L8002A01C:
/* 02AC1C 8002A01C 24010008 */  li    $at, 8
/* 02AC20 8002A020 1041000E */  beq   $v0, $at, .L8002A05C
/* 02AC24 8002A024 C7A400B0 */   lwc1  $f4, 0xb0($sp)
/* 02AC28 8002A028 C60801F8 */  lwc1  $f8, 0x1f8($s0)
/* 02AC2C 8002A02C C61001FC */  lwc1  $f16, 0x1fc($s0)
/* 02AC30 8002A030 46104001 */  sub.s $f0, $f8, $f16
/* 02AC34 8002A034 0C0ADF10 */  jal   func_802B7C40
/* 02AC38 8002A038 46020303 */   div.s $f12, $f0, $f2
/* 02AC3C 8002A03C 00022C00 */  sll   $a1, $v0, 0x10
/* 02AC40 8002A040 00056403 */  sra   $t4, $a1, 0x10
/* 02AC44 8002A044 01802825 */  move  $a1, $t4
/* 02AC48 8002A048 260400C4 */  addiu $a0, $s0, 0xc4
/* 02AC4C 8002A04C 0C00898D */  jal   move_s16_towards
/* 02AC50 8002A050 3C063F00 */   lui   $a2, 0x3f00
/* 02AC54 8002A054 1000001A */  b     .L8002A0C0
/* 02AC58 8002A058 8E1900BC */   lw    $t9, 0xbc($s0)
.L8002A05C:
/* 02AC5C 8002A05C C6120024 */  lwc1  $f18, 0x24($s0)
/* 02AC60 8002A060 46049001 */  sub.s $f0, $f18, $f4
/* 02AC64 8002A064 46020303 */  div.s $f12, $f0, $f2
/* 02AC68 8002A068 0C0ADF10 */  jal   func_802B7C40
/* 02AC6C 8002A06C E7A00054 */   swc1  $f0, 0x54($sp)
/* 02AC70 8002A070 C7A00054 */  lwc1  $f0, 0x54($sp)
/* 02AC74 8002A074 44805000 */  mtc1  $zero, $f10
/* 02AC78 8002A078 00022880 */  sll   $a1, $v0, 2
/* 02AC7C 8002A07C 00A22821 */  addu  $a1, $a1, $v0
/* 02AC80 8002A080 4600503E */  c.le.s $f10, $f0
/* 02AC84 8002A084 00057C40 */  sll   $t7, $a1, 0x11
/* 02AC88 8002A088 000F2C03 */  sra   $a1, $t7, 0x10
/* 02AC8C 8002A08C 260400C4 */  addiu $a0, $s0, 0xc4
/* 02AC90 8002A090 45000008 */  bc1f  .L8002A0B4
/* 02AC94 8002A094 00000000 */   nop   
/* 02AC98 8002A098 04410003 */  bgez  $v0, .L8002A0A8
/* 02AC9C 8002A09C 00022883 */   sra   $a1, $v0, 2
/* 02ACA0 8002A0A0 24410003 */  addiu $at, $v0, 3
/* 02ACA4 8002A0A4 00012883 */  sra   $a1, $at, 2
.L8002A0A8:
/* 02ACA8 8002A0A8 00056C00 */  sll   $t5, $a1, 0x10
/* 02ACAC 8002A0AC 10000001 */  b     .L8002A0B4
/* 02ACB0 8002A0B0 000D2C03 */   sra   $a1, $t5, 0x10
.L8002A0B4:
/* 02ACB4 8002A0B4 0C00898D */  jal   move_s16_towards
/* 02ACB8 8002A0B8 3C063F00 */   lui   $a2, 0x3f00
/* 02ACBC 8002A0BC 8E1900BC */  lw    $t9, 0xbc($s0)
.L8002A0C0:
/* 02ACC0 8002A0C0 24010008 */  li    $at, 8
/* 02ACC4 8002A0C4 33280008 */  andi  $t0, $t9, 8
/* 02ACC8 8002A0C8 1501000B */  bne   $t0, $at, .L8002A0F8
/* 02ACCC 8002A0CC 00000000 */   nop   
/* 02ACD0 8002A0D0 860900CA */  lh    $t1, 0xca($s0)
/* 02ACD4 8002A0D4 24010002 */  li    $at, 2
/* 02ACD8 8002A0D8 312A0002 */  andi  $t2, $t1, 2
/* 02ACDC 8002A0DC 15410006 */  bne   $t2, $at, .L8002A0F8
/* 02ACE0 8002A0E0 00000000 */   nop   
/* 02ACE4 8002A0E4 C6060D9C */  lwc1  $f6, 0xd9c($s0)
/* 02ACE8 8002A0E8 4600320D */  trunc.w.s $f8, $f6
/* 02ACEC 8002A0EC 440C4000 */  mfc1  $t4, $f8
/* 02ACF0 8002A0F0 00000000 */  nop   
/* 02ACF4 8002A0F4 A60C00C4 */  sh    $t4, 0xc4($s0)
.L8002A0F8:
/* 02ACF8 8002A0F8 0C0AAF44 */  jal   func_802ABD10
/* 02ACFC 8002A0FC 9604011A */   lhu   $a0, 0x11a($s0)
/* 02AD00 8002A100 304D00FF */  andi  $t5, $v0, 0xff
/* 02AD04 8002A104 31A3FFFF */  andi  $v1, $t5, 0xffff
/* 02AD08 8002A108 240100FE */  li    $at, 254
/* 02AD0C 8002A10C 1461000E */  bne   $v1, $at, .L8002A148
/* 02AD10 8002A110 A60D00F8 */   sh    $t5, 0xf8($s0)
/* 02AD14 8002A114 8E0200BC */  lw    $v0, 0xbc($s0)
/* 02AD18 8002A118 3C040010 */  lui   $a0, 0x10
/* 02AD1C 8002A11C 24010008 */  li    $at, 8
/* 02AD20 8002A120 00447024 */  and   $t6, $v0, $a0
/* 02AD24 8002A124 108E0008 */  beq   $a0, $t6, .L8002A148
/* 02AD28 8002A128 304F0008 */   andi  $t7, $v0, 8
/* 02AD2C 8002A12C 51E10007 */  beql  $t7, $at, .L8002A14C
/* 02AD30 8002A130 240100FC */   li    $at, 252
/* 02AD34 8002A134 8E18000C */  lw    $t8, 0xc($s0)
/* 02AD38 8002A138 3C010080 */  lui   $at, 0x80
/* 02AD3C 8002A13C 31A3FFFF */  andi  $v1, $t5, 0xffff
/* 02AD40 8002A140 0301C825 */  or    $t9, $t8, $at
/* 02AD44 8002A144 AE19000C */  sw    $t9, 0xc($s0)
.L8002A148:
/* 02AD48 8002A148 240100FC */  li    $at, 252
.L8002A14C:
/* 02AD4C 8002A14C 5461000D */  bnel  $v1, $at, .L8002A184
/* 02AD50 8002A150 8FBF0024 */   lw    $ra, 0x24($sp)
/* 02AD54 8002A154 8E0200BC */  lw    $v0, 0xbc($s0)
/* 02AD58 8002A158 24010004 */  li    $at, 4
/* 02AD5C 8002A15C 30480004 */  andi  $t0, $v0, 4
/* 02AD60 8002A160 11010007 */  beq   $t0, $at, .L8002A180
/* 02AD64 8002A164 30490008 */   andi  $t1, $v0, 8
/* 02AD68 8002A168 24010008 */  li    $at, 8
/* 02AD6C 8002A16C 51210005 */  beql  $t1, $at, .L8002A184
/* 02AD70 8002A170 8FBF0024 */   lw    $ra, 0x24($sp)
/* 02AD74 8002A174 8E0A000C */  lw    $t2, 0xc($s0)
/* 02AD78 8002A178 354B8000 */  ori   $t3, $t2, 0x8000
/* 02AD7C 8002A17C AE0B000C */  sw    $t3, 0xc($s0)
.L8002A180:
/* 02AD80 8002A180 8FBF0024 */  lw    $ra, 0x24($sp)
.L8002A184:
/* 02AD84 8002A184 8FB00020 */  lw    $s0, 0x20($sp)
/* 02AD88 8002A188 27BD00A8 */  addiu $sp, $sp, 0xa8
/* 02AD8C 8002A18C 03E00008 */  jr    $ra
/* 02AD90 8002A190 00000000 */   nop   
