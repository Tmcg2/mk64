glabel func_8007ABFC
/* 07B7FC 8007ABFC 00047140 */  sll   $t6, $a0, 5
/* 07B800 8007AC00 01C47021 */  addu  $t6, $t6, $a0
/* 07B804 8007AC04 3C0F8019 */  lui   $t7, %hi(D_8018CA70) # $t7, 0x8019
/* 07B808 8007AC08 25EFCA70 */  addiu $t7, %lo(D_8018CA70) # addiu $t7, $t7, -0x3590
/* 07B80C 8007AC0C 000E7080 */  sll   $t6, $t6, 2
/* 07B810 8007AC10 01CF1821 */  addu  $v1, $t6, $t7
/* 07B814 8007AC14 80780070 */  lb    $t8, 0x70($v1)
/* 07B818 8007AC18 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 07B81C 8007AC1C AFBF0014 */  sw    $ra, 0x14($sp)
/* 07B820 8007AC20 AFA50024 */  sw    $a1, 0x24($sp)
/* 07B824 8007AC24 17000019 */  bnez  $t8, .L8007AC8C
/* 07B828 8007AC28 00803025 */   move  $a2, $a0
/* 07B82C 8007AC2C 0004C880 */  sll   $t9, $a0, 2
/* 07B830 8007AC30 3C048018 */  lui   $a0, %hi(gItemWindowObjectByPlayerId) # 0x8018
/* 07B834 8007AC34 00992021 */  addu  $a0, $a0, $t9
/* 07B838 8007AC38 8C843E88 */  lw    $a0, %lo(gItemWindowObjectByPlayerId)($a0) # 0x3e88($a0)
/* 07B83C 8007AC3C 24050004 */  li    $a1, 4
/* 07B840 8007AC40 AFA30018 */  sw    $v1, 0x18($sp)
/* 07B844 8007AC44 AFA60020 */  sw    $a2, 0x20($sp)
/* 07B848 8007AC48 0C01C8D5 */  jal   func_80072354
/* 07B84C 8007AC4C AFA4001C */   sw    $a0, 0x1c($sp)
/* 07B850 8007AC50 8FA30018 */  lw    $v1, 0x18($sp)
/* 07B854 8007AC54 10400009 */  beqz  $v0, .L8007AC7C
/* 07B858 8007AC58 8FA4001C */   lw    $a0, 0x1c($sp)
/* 07B85C 8007AC5C 00002825 */  move  $a1, $zero
/* 07B860 8007AC60 0C01C8E9 */  jal   func_800723A4
/* 07B864 8007AC64 AFA30018 */   sw    $v1, 0x18($sp)
/* 07B868 8007AC68 8FA20024 */  lw    $v0, 0x24($sp)
/* 07B86C 8007AC6C 8FA30018 */  lw    $v1, 0x18($sp)
/* 07B870 8007AC70 50400003 */  beql  $v0, $zero, .L8007AC80
/* 07B874 8007AC74 3C051900 */   lui   $a1, 0x1900
/* 07B878 8007AC78 A0620076 */  sb    $v0, 0x76($v1)
.L8007AC7C:
/* 07B87C 8007AC7C 3C051900 */  lui   $a1, (0x19008406 >> 16) # lui $a1, 0x1900
.L8007AC80:
/* 07B880 8007AC80 34A58406 */  ori   $a1, (0x19008406 & 0xFFFF) # ori $a1, $a1, 0x8406
/* 07B884 8007AC84 0C032418 */  jal   func_800C9060
/* 07B888 8007AC88 93A40023 */   lbu   $a0, 0x23($sp)
.L8007AC8C:
/* 07B88C 8007AC8C 8FBF0014 */  lw    $ra, 0x14($sp)
/* 07B890 8007AC90 27BD0020 */  addiu $sp, $sp, 0x20
/* 07B894 8007AC94 03E00008 */  jr    $ra
/* 07B898 8007AC98 00000000 */   nop   
