glabel func_800C2274
/* 0C2E74 800C2274 308700FF */  andi  $a3, $a0, 0xff
/* 0C2E78 800C2278 00077080 */  sll   $t6, $a3, 2
/* 0C2E7C 800C227C 01C77021 */  addu  $t6, $t6, $a3
/* 0C2E80 800C2280 000E70C0 */  sll   $t6, $t6, 3
/* 0C2E84 800C2284 27BDFFB8 */  addiu $sp, $sp, -0x48
/* 0C2E88 800C2288 3C05803B */  lui   $a1, %hi(gSequencePlayers) # $a1, 0x803b
/* 0C2E8C 800C228C 01C77021 */  addu  $t6, $t6, $a3
/* 0C2E90 800C2290 24A51510 */  addiu $a1, %lo(gSequencePlayers) # addiu $a1, $a1, 0x1510
/* 0C2E94 800C2294 000E70C0 */  sll   $t6, $t6, 3
/* 0C2E98 800C2298 00AE7821 */  addu  $t7, $a1, $t6
/* 0C2E9C 800C229C 8DF80000 */  lw    $t8, ($t7)
/* 0C2EA0 800C22A0 AFBE0038 */  sw    $fp, 0x38($sp)
/* 0C2EA4 800C22A4 03A0F025 */  move  $fp, $sp
/* 0C2EA8 800C22A8 0018CFC2 */  srl   $t9, $t8, 0x1f
/* 0C2EAC 800C22AC AFBF003C */  sw    $ra, 0x3c($sp)
/* 0C2EB0 800C22B0 AFB30034 */  sw    $s3, 0x34($sp)
/* 0C2EB4 800C22B4 AFB20030 */  sw    $s2, 0x30($sp)
/* 0C2EB8 800C22B8 AFB1002C */  sw    $s1, 0x2c($sp)
/* 0C2EBC 800C22BC AFB00028 */  sw    $s0, 0x28($sp)
/* 0C2EC0 800C22C0 AFA40048 */  sw    $a0, 0x48($sp)
/* 0C2EC4 800C22C4 13200062 */  beqz  $t9, .L800C2450
/* 0C2EC8 800C22C8 2406000F */   li    $a2, 15
/* 0C2ECC 800C22CC 3C02800E */  lui   $v0, %hi(gScreenModeSelection) # $v0, 0x800e
/* 0C2ED0 800C22D0 8C42C530 */  lw    $v0, %lo(gScreenModeSelection)($v0)
/* 0C2ED4 800C22D4 00074880 */  sll   $t1, $a3, 2
/* 0C2ED8 800C22D8 01274821 */  addu  $t1, $t1, $a3
/* 0C2EDC 800C22DC 10400010 */  beqz  $v0, .L800C2320
/* 0C2EE0 800C22E0 000948C0 */   sll   $t1, $t1, 3
/* 0C2EE4 800C22E4 24010001 */  li    $at, 1
/* 0C2EE8 800C22E8 10410005 */  beq   $v0, $at, .L800C2300
/* 0C2EEC 800C22EC 24030003 */   li    $v1, 3
/* 0C2EF0 800C22F0 10430005 */  beq   $v0, $v1, .L800C2308
/* 0C2EF4 800C22F4 3C08800E */   lui   $t0, %hi(gPlayerCountSelection1) # $t0, 0x800e
/* 0C2EF8 800C22F8 1000000A */  b     .L800C2324
/* 0C2EFC 800C22FC 01274821 */   addu  $t1, $t1, $a3
.L800C2300:
/* 0C2F00 800C2300 10000007 */  b     .L800C2320
/* 0C2F04 800C2304 2406000E */   li    $a2, 14
.L800C2308:
/* 0C2F08 800C2308 8D08C538 */  lw    $t0, %lo(gPlayerCountSelection1)($t0)
/* 0C2F0C 800C230C 2406000C */  li    $a2, 12
/* 0C2F10 800C2310 14680003 */  bne   $v1, $t0, .L800C2320
/* 0C2F14 800C2314 00000000 */   nop   
/* 0C2F18 800C2318 10000001 */  b     .L800C2320
/* 0C2F1C 800C231C 2406000D */   li    $a2, 13
.L800C2320:
/* 0C2F20 800C2320 01274821 */  addu  $t1, $t1, $a3
.L800C2324:
/* 0C2F24 800C2324 000948C0 */  sll   $t1, $t1, 3
/* 0C2F28 800C2328 00A95021 */  addu  $t2, $a1, $t1
/* 0C2F2C 800C232C 00065880 */  sll   $t3, $a2, 2
/* 0C2F30 800C2330 014B6021 */  addu  $t4, $t2, $t3
/* 0C2F34 800C2334 8D820030 */  lw    $v0, 0x30($t4)
/* 0C2F38 800C2338 241200FF */  li    $s2, 255
/* 0C2F3C 800C233C 30EA00FF */  andi  $t2, $a3, 0xff
/* 0C2F40 800C2340 90500058 */  lbu   $s0, 0x58($v0)
/* 0C2F44 800C2344 000A5C00 */  sll   $t3, $t2, 0x10
/* 0C2F48 800C2348 2405FFFF */  li    $a1, -1
/* 0C2F4C 800C234C 52500017 */  beql  $s2, $s0, .L800C23AC
/* 0C2F50 800C2350 24010001 */   li    $at, 1
/* 0C2F54 800C2354 804D0059 */  lb    $t5, 0x59($v0)
/* 0C2F58 800C2358 31AE0003 */  andi  $t6, $t5, 3
/* 0C2F5C 800C235C A7CE0046 */  sh    $t6, 0x46($fp)
/* 0C2F60 800C2360 8051005A */  lb    $s1, 0x5a($v0)
/* 0C2F64 800C2364 30CD00FF */  andi  $t5, $a2, 0xff
/* 0C2F68 800C2368 000D7200 */  sll   $t6, $t5, 8
/* 0C2F6C 800C236C 322F000F */  andi  $t7, $s1, 0xf
/* 0C2F70 800C2370 000FC400 */  sll   $t8, $t7, 0x10
/* 0C2F74 800C2374 00188C03 */  sra   $s1, $t8, 0x10
/* 0C2F78 800C2378 2A21000A */  slti  $at, $s1, 0xa
/* 0C2F7C 800C237C 54200003 */  bnel  $at, $zero, .L800C238C
/* 0C2F80 800C2380 8048005B */   lb    $t0, 0x5b($v0)
/* 0C2F84 800C2384 24110009 */  li    $s1, 9
/* 0C2F88 800C2388 8048005B */  lb    $t0, 0x5b($v0)
.L800C238C:
/* 0C2F8C 800C238C 3C010600 */  lui   $at, 0x600
/* 0C2F90 800C2390 01616025 */  or    $t4, $t3, $at
/* 0C2F94 800C2394 31090007 */  andi  $t1, $t0, 7
/* 0C2F98 800C2398 A7C90042 */  sh    $t1, 0x42($fp)
/* 0C2F9C 800C239C 0C032EFA */  jal   func_800CBBE8
/* 0C2FA0 800C23A0 018E2025 */   or    $a0, $t4, $t6
/* 0C2FA4 800C23A4 A7D10044 */  sh    $s1, 0x44($fp)
/* 0C2FA8 800C23A8 24010001 */  li    $at, 1
.L800C23AC:
/* 0C2FAC 800C23AC 12010006 */  beq   $s0, $at, .L800C23C8
/* 0C2FB0 800C23B0 87D10044 */   lh    $s1, 0x44($fp)
/* 0C2FB4 800C23B4 24010002 */  li    $at, 2
/* 0C2FB8 800C23B8 5201001E */  beql  $s0, $at, .L800C2434
/* 0C2FBC 800C23BC 87CB0046 */   lh    $t3, 0x46($fp)
/* 0C2FC0 800C23C0 10000024 */  b     .L800C2454
/* 0C2FC4 800C23C4 8FDF003C */   lw    $ra, 0x3c($fp)
.L800C23C8:
/* 0C2FC8 800C23C8 87CF0046 */  lh    $t7, 0x46($fp)
/* 0C2FCC 800C23CC 3C138019 */  lui   $s3, %hi(D_8018FC10) # $s3, 0x8019
/* 0C2FD0 800C23D0 2673FC10 */  addiu $s3, %lo(D_8018FC10) # addiu $s3, $s3, -0x3f0
/* 0C2FD4 800C23D4 000FC080 */  sll   $t8, $t7, 2
/* 0C2FD8 800C23D8 02781021 */  addu  $v0, $s3, $t8
/* 0C2FDC 800C23DC A4510000 */  sh    $s1, ($v0)
/* 0C2FE0 800C23E0 87D90042 */  lh    $t9, 0x42($fp)
/* 0C2FE4 800C23E4 00008025 */  move  $s0, $zero
/* 0C2FE8 800C23E8 A4590002 */  sh    $t9, 2($v0)
.L800C23EC:
/* 0C2FEC 800C23EC 00104080 */  sll   $t0, $s0, 2
/* 0C2FF0 800C23F0 02688821 */  addu  $s1, $s3, $t0
/* 0C2FF4 800C23F4 86250000 */  lh    $a1, ($s1)
/* 0C2FF8 800C23F8 00102400 */  sll   $a0, $s0, 0x10
/* 0C2FFC 800C23FC 00044C03 */  sra   $t1, $a0, 0x10
/* 0C3000 800C2400 12450004 */  beq   $s2, $a1, .L800C2414
/* 0C3004 800C2404 01202025 */   move  $a0, $t1
/* 0C3008 800C2408 0C006AAB */  jal   func_8001AAAC
/* 0C300C 800C240C 86260002 */   lh    $a2, 2($s1)
/* 0C3010 800C2410 A6320000 */  sh    $s2, ($s1)
.L800C2414:
/* 0C3014 800C2414 26100001 */  addiu $s0, $s0, 1
/* 0C3018 800C2418 320A00FF */  andi  $t2, $s0, 0xff
/* 0C301C 800C241C 29410004 */  slti  $at, $t2, 4
/* 0C3020 800C2420 1420FFF2 */  bnez  $at, .L800C23EC
/* 0C3024 800C2424 01408025 */   move  $s0, $t2
/* 0C3028 800C2428 1000000A */  b     .L800C2454
/* 0C302C 800C242C 8FDF003C */   lw    $ra, 0x3c($fp)
/* 0C3030 800C2430 87CB0046 */  lh    $t3, 0x46($fp)
.L800C2434:
/* 0C3034 800C2434 3C138019 */  lui   $s3, %hi(D_8018FC10) # $s3, 0x8019
/* 0C3038 800C2438 2673FC10 */  addiu $s3, %lo(D_8018FC10) # addiu $s3, $s3, -0x3f0
/* 0C303C 800C243C 000B6880 */  sll   $t5, $t3, 2
/* 0C3040 800C2440 026D1021 */  addu  $v0, $s3, $t5
/* 0C3044 800C2444 A4510000 */  sh    $s1, ($v0)
/* 0C3048 800C2448 87CC0042 */  lh    $t4, 0x42($fp)
/* 0C304C 800C244C A44C0002 */  sh    $t4, 2($v0)
.L800C2450:
/* 0C3050 800C2450 8FDF003C */  lw    $ra, 0x3c($fp)
.L800C2454:
/* 0C3054 800C2454 03C0E825 */  move  $sp, $fp
/* 0C3058 800C2458 8FD00028 */  lw    $s0, 0x28($fp)
/* 0C305C 800C245C 8FD1002C */  lw    $s1, 0x2c($fp)
/* 0C3060 800C2460 8FD20030 */  lw    $s2, 0x30($fp)
/* 0C3064 800C2464 8FD30034 */  lw    $s3, 0x34($fp)
/* 0C3068 800C2468 8FDE0038 */  lw    $fp, 0x38($fp)
/* 0C306C 800C246C 03E00008 */  jr    $ra
/* 0C3070 800C2470 27BD0048 */   addiu $sp, $sp, 0x48
