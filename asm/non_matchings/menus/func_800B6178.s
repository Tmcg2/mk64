glabel func_800B6178
/* 0B6D78 800B6178 27BDFFD0 */  addiu $sp, $sp, -0x30
/* 0B6D7C 800B617C AFBF002C */  sw    $ra, 0x2c($sp)
/* 0B6D80 800B6180 AFB30028 */  sw    $s3, 0x28($sp)
/* 0B6D84 800B6184 AFB20024 */  sw    $s2, 0x24($sp)
/* 0B6D88 800B6188 AFB10020 */  sw    $s1, 0x20($sp)
/* 0B6D8C 800B618C 10800006 */  beqz  $a0, .L800B61A8
/* 0B6D90 800B6190 AFB0001C */   sw    $s0, 0x1c($sp)
/* 0B6D94 800B6194 24010001 */  li    $at, 1
/* 0B6D98 800B6198 10810003 */  beq   $a0, $at, .L800B61A8
/* 0B6D9C 800B619C 00000000 */   nop   
/* 0B6DA0 800B61A0 10000062 */  b     .L800B632C
/* 0B6DA4 800B61A4 2402FFFF */   li    $v0, -1
.L800B61A8:
/* 0B6DA8 800B61A8 3C11800E */  lui   $s1, %hi(gGamestate) # $s1, 0x800e
/* 0B6DAC 800B61AC 2631C50C */  addiu $s1, %lo(gGamestate) # addiu $s1, $s1, -0x3af4
/* 0B6DB0 800B61B0 8E2E0000 */  lw    $t6, ($s1)
/* 0B6DB4 800B61B4 24100004 */  li    $s0, 4
/* 0B6DB8 800B61B8 AFA40030 */  sw    $a0, 0x30($sp)
/* 0B6DBC 800B61BC 560E0004 */  bnel  $s0, $t6, .L800B61D0
/* 0B6DC0 800B61C0 8FA40030 */   lw    $a0, 0x30($sp)
/* 0B6DC4 800B61C4 0C001471 */  jal   func_800051C4
/* 0B6DC8 800B61C8 AFA40030 */   sw    $a0, 0x30($sp)
/* 0B6DCC 800B61CC 8FA40030 */  lw    $a0, 0x30($sp)
.L800B61D0:
/* 0B6DD0 800B61D0 3C188019 */  lui   $t8, %hi(D_8018EE10) # $t8, 0x8019
/* 0B6DD4 800B61D4 2718EE10 */  addiu $t8, %lo(D_8018EE10) # addiu $t8, $t8, -0x11f0
/* 0B6DD8 800B61D8 000479C0 */  sll   $t7, $a0, 7
/* 0B6DDC 800B61DC 01F89821 */  addu  $s3, $t7, $t8
/* 0B6DE0 800B61E0 0C02D822 */  jal   func_800B6088
/* 0B6DE4 800B61E4 A2600004 */   sb    $zero, 4($s3)
/* 0B6DE8 800B61E8 10400011 */  beqz  $v0, .L800B6230
/* 0B6DEC 800B61EC 00401825 */   move  $v1, $v0
/* 0B6DF0 800B61F0 A2600004 */  sb    $zero, 4($s3)
/* 0B6DF4 800B61F4 00008025 */  move  $s0, $zero
/* 0B6DF8 800B61F8 02608825 */  move  $s1, $s3
/* 0B6DFC 800B61FC 2412003C */  li    $s2, 60
.L800B6200:
/* 0B6E00 800B6200 26190001 */  addiu $t9, $s0, 1
/* 0B6E04 800B6204 26080002 */  addiu $t0, $s0, 2
/* 0B6E08 800B6208 26090003 */  addiu $t1, $s0, 3
/* 0B6E0C 800B620C A2300007 */  sb    $s0, 7($s1)
/* 0B6E10 800B6210 26100004 */  addiu $s0, $s0, 4
/* 0B6E14 800B6214 A229000A */  sb    $t1, 0xa($s1)
/* 0B6E18 800B6218 A2280009 */  sb    $t0, 9($s1)
/* 0B6E1C 800B621C A2390008 */  sb    $t9, 8($s1)
/* 0B6E20 800B6220 1612FFF7 */  bne   $s0, $s2, .L800B6200
/* 0B6E24 800B6224 26310004 */   addiu $s1, $s1, 4
/* 0B6E28 800B6228 10000040 */  b     .L800B632C
/* 0B6E2C 800B622C 00601025 */   move  $v0, $v1
.L800B6230:
/* 0B6E30 800B6230 8FA70030 */  lw    $a3, 0x30($sp)
/* 0B6E34 800B6234 3C0C800E */  lui   $t4, %hi(D_800DC714) # $t4, 0x800e
/* 0B6E38 800B6238 8D8CC714 */  lw    $t4, %lo(D_800DC714)($t4)
/* 0B6E3C 800B623C 00075100 */  sll   $t2, $a3, 4
/* 0B6E40 800B6240 01475023 */  subu  $t2, $t2, $a3
/* 0B6E44 800B6244 000A5280 */  sll   $t2, $t2, 0xa
/* 0B6E48 800B6248 3C048019 */  lui   $a0, %hi(gControllerPak1FileHandle) # $a0, 0x8019
/* 0B6E4C 800B624C 3C058019 */  lui   $a1, %hi(gControllerPak1FileNote) # $a1, 0x8019
/* 0B6E50 800B6250 240B3C00 */  li    $t3, 15360
/* 0B6E54 800B6254 AFAB0010 */  sw    $t3, 0x10($sp)
/* 0B6E58 800B6258 8CA5EB84 */  lw    $a1, %lo(gControllerPak1FileNote)($a1)
/* 0B6E5C 800B625C 2484E868 */  addiu $a0, %lo(gControllerPak1FileHandle) # addiu $a0, $a0, -0x1798
/* 0B6E60 800B6260 25470100 */  addiu $a3, $t2, 0x100
/* 0B6E64 800B6264 24060001 */  li    $a2, 1
/* 0B6E68 800B6268 0C0340F3 */  jal   osPfsReadWriteFile
/* 0B6E6C 800B626C AFAC0014 */   sw    $t4, 0x14($sp)
/* 0B6E70 800B6270 1440001E */  bnez  $v0, .L800B62EC
/* 0B6E74 800B6274 00401825 */   move  $v1, $v0
/* 0B6E78 800B6278 240D0001 */  li    $t5, 1
/* 0B6E7C 800B627C A26D0004 */  sb    $t5, 4($s3)
/* 0B6E80 800B6280 8E2E0000 */  lw    $t6, ($s1)
/* 0B6E84 800B6284 3C0F8019 */  lui   $t7, %hi(gCupSelection) # $t7, 0x8019
/* 0B6E88 800B6288 3C198019 */  lui   $t9, %hi(gCupCourseSelection) # $t9, 0x8019
/* 0B6E8C 800B628C 160E0006 */  bne   $s0, $t6, .L800B62A8
/* 0B6E90 800B6290 3C098016 */   lui   $t1, %hi(D_80162DFC) # $t1, 0x8016
/* 0B6E94 800B6294 81EFEE09 */  lb    $t7, %lo(gCupSelection)($t7)
/* 0B6E98 800B6298 8339EE0B */  lb    $t9, %lo(gCupCourseSelection)($t9)
/* 0B6E9C 800B629C 000FC080 */  sll   $t8, $t7, 2
/* 0B6EA0 800B62A0 03194021 */  addu  $t0, $t8, $t9
/* 0B6EA4 800B62A4 A2680005 */  sb    $t0, 5($s3)
.L800B62A8:
/* 0B6EA8 800B62A8 8D292DFC */  lw    $t1, %lo(D_80162DFC)($t1)
/* 0B6EAC 800B62AC 3C0A8016 */  lui   $t2, %hi(D_80162DE0) # $t2, 0x8016
/* 0B6EB0 800B62B0 00008025 */  move  $s0, $zero
/* 0B6EB4 800B62B4 AE690000 */  sw    $t1, ($s3)
/* 0B6EB8 800B62B8 8D4A2DE0 */  lw    $t2, %lo(D_80162DE0)($t2)
/* 0B6EBC 800B62BC 02608825 */  move  $s1, $s3
/* 0B6EC0 800B62C0 2412003C */  li    $s2, 60
/* 0B6EC4 800B62C4 A26A0006 */  sb    $t2, 6($s3)
.L800B62C8:
/* 0B6EC8 800B62C8 0C02D83A */  jal   func_800B60E8
/* 0B6ECC 800B62CC 02002025 */   move  $a0, $s0
/* 0B6ED0 800B62D0 26100001 */  addiu $s0, $s0, 1
/* 0B6ED4 800B62D4 26310001 */  addiu $s1, $s1, 1
/* 0B6ED8 800B62D8 1612FFFB */  bne   $s0, $s2, .L800B62C8
/* 0B6EDC 800B62DC A2220006 */   sb    $v0, 6($s1)
/* 0B6EE0 800B62E0 0C02D822 */  jal   func_800B6088
/* 0B6EE4 800B62E4 8FA40030 */   lw    $a0, 0x30($sp)
/* 0B6EE8 800B62E8 00401825 */  move  $v1, $v0
.L800B62EC:
/* 0B6EEC 800B62EC 1040000E */  beqz  $v0, .L800B6328
/* 0B6EF0 800B62F0 2412003C */   li    $s2, 60
/* 0B6EF4 800B62F4 A2600004 */  sb    $zero, 4($s3)
/* 0B6EF8 800B62F8 00008025 */  move  $s0, $zero
/* 0B6EFC 800B62FC 02608825 */  move  $s1, $s3
.L800B6300:
/* 0B6F00 800B6300 260B0001 */  addiu $t3, $s0, 1
/* 0B6F04 800B6304 260C0002 */  addiu $t4, $s0, 2
/* 0B6F08 800B6308 260D0003 */  addiu $t5, $s0, 3
/* 0B6F0C 800B630C A2300007 */  sb    $s0, 7($s1)
/* 0B6F10 800B6310 26100004 */  addiu $s0, $s0, 4
/* 0B6F14 800B6314 A22D000A */  sb    $t5, 0xa($s1)
/* 0B6F18 800B6318 A22C0009 */  sb    $t4, 9($s1)
/* 0B6F1C 800B631C A22B0008 */  sb    $t3, 8($s1)
/* 0B6F20 800B6320 1612FFF7 */  bne   $s0, $s2, .L800B6300
/* 0B6F24 800B6324 26310004 */   addiu $s1, $s1, 4
.L800B6328:
/* 0B6F28 800B6328 00601025 */  move  $v0, $v1
.L800B632C:
/* 0B6F2C 800B632C 8FBF002C */  lw    $ra, 0x2c($sp)
/* 0B6F30 800B6330 8FB0001C */  lw    $s0, 0x1c($sp)
/* 0B6F34 800B6334 8FB10020 */  lw    $s1, 0x20($sp)
/* 0B6F38 800B6338 8FB20024 */  lw    $s2, 0x24($sp)
/* 0B6F3C 800B633C 8FB30028 */  lw    $s3, 0x28($sp)
/* 0B6F40 800B6340 03E00008 */  jr    $ra
/* 0B6F44 800B6344 27BD0030 */   addiu $sp, $sp, 0x30
