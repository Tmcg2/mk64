glabel func_80083B0C
/* 08470C 80083B0C 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 084710 80083B10 AFBF0024 */  sw    $ra, 0x24($sp)
/* 084714 80083B14 AFB00020 */  sw    $s0, 0x20($sp)
/* 084718 80083B18 3C050600 */  lui   $a1, %hi(gTLUTSnowman) # $a1, 0x600
/* 08471C 80083B1C 3C060600 */  lui   $a2, %hi(gTextureSnowmanBody) # $a2, 0x600
/* 084720 80083B20 240E0040 */  li    $t6, 64
/* 084724 80083B24 00808025 */  move  $s0, $a0
/* 084728 80083B28 AFAE0010 */  sw    $t6, 0x10($sp)
/* 08472C 80083B2C 24C65D20 */  addiu $a2, %lo(gTextureSnowmanBody) # addiu $a2, $a2, 0x5d20
/* 084730 80083B30 24A54B20 */  addiu $a1, %lo(gTLUTSnowman) # addiu $a1, $a1, 0x4b20
/* 084734 80083B34 0C01CD11 */  jal   func_80073444
/* 084738 80083B38 24070040 */   li    $a3, 64
/* 08473C 80083B3C 001078C0 */  sll   $t7, $s0, 3
/* 084740 80083B40 01F07823 */  subu  $t7, $t7, $s0
/* 084744 80083B44 3C188016 */  lui   $t8, %hi(D_80165C18) # $t8, 0x8016
/* 084748 80083B48 27185C18 */  addiu $t8, %lo(D_80165C18) # addiu $t8, $t8, 0x5c18
/* 08474C 80083B4C 000F7940 */  sll   $t7, $t7, 5
/* 084750 80083B50 3C190D00 */  lui   $t9, %hi(D_0D0060B0) # $t9, 0xd00
/* 084754 80083B54 273960B0 */  addiu $t9, %lo(D_0D0060B0) # addiu $t9, $t9, 0x60b0
/* 084758 80083B58 01F81021 */  addu  $v0, $t7, $t8
/* 08475C 80083B5C AC590074 */  sw    $t9, 0x74($v0)
/* 084760 80083B60 3C01800F */  lui   $at, %hi(D_800EF260) # $at, 0x800f
/* 084764 80083B64 C424F260 */  lwc1  $f4, %lo(D_800EF260)($at)
/* 084768 80083B68 A04000D2 */  sb    $zero, 0xd2($v0)
/* 08476C 80083B6C AFA2002C */  sw    $v0, 0x2c($sp)
/* 084770 80083B70 02002025 */  move  $a0, $s0
/* 084774 80083B74 0C01C922 */  jal   func_80072488
/* 084778 80083B78 E4440000 */   swc1  $f4, ($v0)
/* 08477C 80083B7C 44800000 */  mtc1  $zero, $f0
/* 084780 80083B80 02002025 */  move  $a0, $s0
/* 084784 80083B84 44050000 */  mfc1  $a1, $f0
/* 084788 80083B88 44060000 */  mfc1  $a2, $f0
/* 08478C 80083B8C 44070000 */  mfc1  $a3, $f0
/* 084790 80083B90 0C022E03 */  jal   func_8008B80C
/* 084794 80083B94 00000000 */   nop   
/* 084798 80083B98 8FA2002C */  lw    $v0, 0x2c($sp)
/* 08479C 80083B9C 3C013FC0 */  li    $at, 0x3FC00000 # 1.500000
/* 0847A0 80083BA0 44813000 */  mtc1  $at, $f6
/* 0847A4 80083BA4 34088000 */  li    $t0, 32768
/* 0847A8 80083BA8 24090002 */  li    $t1, 2
/* 0847AC 80083BAC 3C050400 */  lui   $a1, (0x04000210 >> 16) # lui $a1, 0x400
/* 0847B0 80083BB0 34A50210 */  ori   $a1, (0x04000210 & 0xFFFF) # ori $a1, $a1, 0x210
/* 0847B4 80083BB4 02002025 */  move  $a0, $s0
/* 0847B8 80083BB8 A44000B2 */  sh    $zero, 0xb2($v0)
/* 0847BC 80083BBC A44000B4 */  sh    $zero, 0xb4($v0)
/* 0847C0 80083BC0 A44800B6 */  sh    $t0, 0xb6($v0)
/* 0847C4 80083BC4 A44900C8 */  sh    $t1, 0xc8($v0)
/* 0847C8 80083BC8 0C01C870 */  jal   func_800721C0
/* 0847CC 80083BCC E4460034 */   swc1  $f6, 0x34($v0)
/* 0847D0 80083BD0 8FBF0024 */  lw    $ra, 0x24($sp)
/* 0847D4 80083BD4 8FB00020 */  lw    $s0, 0x20($sp)
/* 0847D8 80083BD8 27BD0030 */  addiu $sp, $sp, 0x30
/* 0847DC 80083BDC 03E00008 */  jr    $ra
/* 0847E0 80083BE0 00000000 */   nop   
