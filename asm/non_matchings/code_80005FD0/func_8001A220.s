.section .late_rodata

glabel jpt_800ED36C
.word L8001A25C, L8001A274, L8001A28C
.word L8001A2A4, L8001A2BC, L8001A2D4

.section .text

glabel func_8001A220
/* 01AE20 8001A220 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 01AE24 8001A224 AFBF0014 */  sw    $ra, 0x14($sp)
/* 01AE28 8001A228 AFA40018 */  sw    $a0, 0x18($sp)
/* 01AE2C 8001A22C 24040006 */  li    $a0, 6
/* 01AE30 8001A230 0C0ADF8D */  jal   random_int
/* 01AE34 8001A234 AFA5001C */   sw    $a1, 0x1c($sp)
/* 01AE38 8001A238 2C410006 */  sltiu $at, $v0, 6
/* 01AE3C 8001A23C 1020002B */  beqz  $at, .L8001A2EC
/* 01AE40 8001A240 8FA5001C */   lw    $a1, 0x1c($sp)
/* 01AE44 8001A244 00027080 */  sll   $t6, $v0, 2
/* 01AE48 8001A248 3C01800F */  lui   $at, %hi(jpt_800ED36C) # 0x800f
/* 01AE4C 8001A24C 002E0821 */  addu  $at, $at, $t6
/* 01AE50 8001A250 8C2ED36C */  lw    $t6, %lo(jpt_800ED36C)($at) # -0x2c94($at)
/* 01AE54 8001A254 01C00008 */  jr    $t6
/* 01AE58 8001A258 00000000 */   nop   
glabel L8001A25C
/* 01AE5C 8001A25C 0005C040 */  sll   $t8, $a1, 1
/* 01AE60 8001A260 3C018016 */  lui   $at, %hi(D_80164680) # 0x8016
/* 01AE64 8001A264 00380821 */  addu  $at, $at, $t8
/* 01AE68 8001A268 240F0004 */  li    $t7, 4
/* 01AE6C 8001A26C 10000024 */  b     .L8001A300
/* 01AE70 8001A270 A42F4680 */   sh    $t7, %lo(D_80164680)($at) # 0x4680($at)
glabel L8001A274
/* 01AE74 8001A274 00054040 */  sll   $t0, $a1, 1
/* 01AE78 8001A278 3C018016 */  lui   $at, %hi(D_80164680) # 0x8016
/* 01AE7C 8001A27C 00280821 */  addu  $at, $at, $t0
/* 01AE80 8001A280 24190005 */  li    $t9, 5
/* 01AE84 8001A284 1000001E */  b     .L8001A300
/* 01AE88 8001A288 A4394680 */   sh    $t9, %lo(D_80164680)($at) # 0x4680($at)
glabel L8001A28C
/* 01AE8C 8001A28C 00055040 */  sll   $t2, $a1, 1
/* 01AE90 8001A290 3C018016 */  lui   $at, %hi(D_80164680) # 0x8016
/* 01AE94 8001A294 002A0821 */  addu  $at, $at, $t2
/* 01AE98 8001A298 24090006 */  li    $t1, 6
/* 01AE9C 8001A29C 10000018 */  b     .L8001A300
/* 01AEA0 8001A2A0 A4294680 */   sh    $t1, %lo(D_80164680)($at) # 0x4680($at)
glabel L8001A2A4
/* 01AEA4 8001A2A4 00056040 */  sll   $t4, $a1, 1
/* 01AEA8 8001A2A8 3C018016 */  lui   $at, %hi(D_80164680) # 0x8016
/* 01AEAC 8001A2AC 002C0821 */  addu  $at, $at, $t4
/* 01AEB0 8001A2B0 240B0007 */  li    $t3, 7
/* 01AEB4 8001A2B4 10000012 */  b     .L8001A300
/* 01AEB8 8001A2B8 A42B4680 */   sh    $t3, %lo(D_80164680)($at) # 0x4680($at)
glabel L8001A2BC
/* 01AEBC 8001A2BC 00057040 */  sll   $t6, $a1, 1
/* 01AEC0 8001A2C0 3C018016 */  lui   $at, %hi(D_80164680) # 0x8016
/* 01AEC4 8001A2C4 002E0821 */  addu  $at, $at, $t6
/* 01AEC8 8001A2C8 240D0008 */  li    $t5, 8
/* 01AECC 8001A2CC 1000000C */  b     .L8001A300
/* 01AED0 8001A2D0 A42D4680 */   sh    $t5, %lo(D_80164680)($at) # 0x4680($at)
glabel L8001A2D4
/* 01AED4 8001A2D4 0005C040 */  sll   $t8, $a1, 1
/* 01AED8 8001A2D8 3C018016 */  lui   $at, %hi(D_80164680) # 0x8016
/* 01AEDC 8001A2DC 00380821 */  addu  $at, $at, $t8
/* 01AEE0 8001A2E0 240F0001 */  li    $t7, 1
/* 01AEE4 8001A2E4 10000006 */  b     .L8001A300
/* 01AEE8 8001A2E8 A42F4680 */   sh    $t7, %lo(D_80164680)($at) # 0x4680($at)
.L8001A2EC:
/* 01AEEC 8001A2EC 00054040 */  sll   $t0, $a1, 1
/* 01AEF0 8001A2F0 3C018016 */  lui   $at, %hi(D_80164680) # 0x8016
/* 01AEF4 8001A2F4 00280821 */  addu  $at, $at, $t0
/* 01AEF8 8001A2F8 24190008 */  li    $t9, 8
/* 01AEFC 8001A2FC A4394680 */  sh    $t9, %lo(D_80164680)($at) # 0x4680($at)
.L8001A300:
/* 01AF00 8001A300 8FBF0014 */  lw    $ra, 0x14($sp)
/* 01AF04 8001A304 27BD0018 */  addiu $sp, $sp, 0x18
/* 01AF08 8001A308 03E00008 */  jr    $ra
/* 01AF0C 8001A30C 00000000 */   nop   
