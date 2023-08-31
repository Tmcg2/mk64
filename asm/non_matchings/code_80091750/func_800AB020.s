.section .late_rodata

glabel jpt_800F25F4
.word L800AB090, L800AB044, L800AB088, L800AB090
.word L800AB04C

.section .text

glabel func_800AB020
/* 0ABC20 800AB020 8C8E0004 */  lw    $t6, 4($a0)
/* 0ABC24 800AB024 2DC10005 */  sltiu $at, $t6, 5
/* 0ABC28 800AB028 10200019 */  beqz  $at, .L800AB090
/* 0ABC2C 800AB02C 000E7080 */   sll   $t6, $t6, 2
/* 0ABC30 800AB030 3C01800F */  lui   $at, %hi(jpt_800F25F4)
/* 0ABC34 800AB034 002E0821 */  addu  $at, $at, $t6
/* 0ABC38 800AB038 8C2E25F4 */  lw    $t6, %lo(jpt_800F25F4)($at)
/* 0ABC3C 800AB03C 01C00008 */  jr    $t6
/* 0ABC40 800AB040 00000000 */   nop   
glabel L800AB044
/* 0ABC44 800AB044 240F0004 */  li    $t7, 4
/* 0ABC48 800AB048 AC8F0004 */  sw    $t7, 4($a0)
glabel L800AB04C
/* 0ABC4C 800AB04C 8C82001C */  lw    $v0, 0x1c($a0)
/* 0ABC50 800AB050 2401000C */  li    $at, 12
/* 0ABC54 800AB054 5840000A */  blezl $v0, .L800AB080
/* 0ABC58 800AB058 AC80001C */   sw    $zero, 0x1c($a0)
/* 0ABC5C 800AB05C 0041001A */  div   $zero, $v0, $at
/* 0ABC60 800AB060 0000C012 */  mflo  $t8
/* 0ABC64 800AB064 0058C823 */  subu  $t9, $v0, $t8
/* 0ABC68 800AB068 2728FFFE */  addiu $t0, $t9, -2
/* 0ABC6C 800AB06C 05010008 */  bgez  $t0, .L800AB090
/* 0ABC70 800AB070 AC88001C */   sw    $t0, 0x1c($a0)
/* 0ABC74 800AB074 03E00008 */  jr    $ra
/* 0ABC78 800AB078 AC80001C */   sw    $zero, 0x1c($a0)

/* 0ABC7C 800AB07C AC80001C */  sw    $zero, 0x1c($a0)
.L800AB080:
/* 0ABC80 800AB080 03E00008 */  jr    $ra
/* 0ABC84 800AB084 AC800004 */   sw    $zero, 4($a0)

glabel L800AB088
/* 0ABC88 800AB088 240A0003 */  li    $t2, 3
/* 0ABC8C 800AB08C AC8A0004 */  sw    $t2, 4($a0)
.L800AB090:
glabel L800AB090
/* 0ABC90 800AB090 03E00008 */  jr    $ra
/* 0ABC94 800AB094 00000000 */   nop   
