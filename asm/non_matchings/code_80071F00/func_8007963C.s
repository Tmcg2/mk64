.section .late_rodata

glabel D_800EEC38
.float 5000.0

glabel D_800EEC3C
.float 0.15

.section .text

glabel func_8007963C
/* 07A23C 8007963C 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 07A240 80079640 AFBF0024 */  sw    $ra, 0x24($sp)
/* 07A244 80079644 AFB00020 */  sw    $s0, 0x20($sp)
/* 07A248 80079648 0C01E47C */  jal   func_800791F0
/* 07A24C 8007964C 00808025 */   move  $s0, $a0
/* 07A250 80079650 3C050D02 */  lui   $a1, %hi(gTLUTLakituCheckeredFlag) # $a1, 0xd02
/* 07A254 80079654 3C060F08 */  lui   $a2, %hi(D_0F07E350) # $a2, 0xf08
/* 07A258 80079658 240E0038 */  li    $t6, 56
/* 07A25C 8007965C AFAE0010 */  sw    $t6, 0x10($sp)
/* 07A260 80079660 24C6E350 */  addiu $a2, %lo(D_0F07E350) # addiu $a2, $a2, -0x1cb0
/* 07A264 80079664 24A554D8 */  addiu $a1, %lo(gTLUTLakituCheckeredFlag) # addiu $a1, $a1, 0x54d8
/* 07A268 80079668 02002025 */  move  $a0, $s0
/* 07A26C 8007966C 0C01CD11 */  jal   func_80073444
/* 07A270 80079670 24070048 */   li    $a3, 72
/* 07A274 80079674 001078C0 */  sll   $t7, $s0, 3
/* 07A278 80079678 3C01800F */  lui   $at, %hi(D_800EEC38) # $at, 0x800f
/* 07A27C 8007967C 01F07823 */  subu  $t7, $t7, $s0
/* 07A280 80079680 3C188016 */  lui   $t8, %hi(D_80165C18) # $t8, 0x8016
/* 07A284 80079684 C420EC38 */  lwc1  $f0, %lo(D_800EEC38)($at)
/* 07A288 80079688 27185C18 */  addiu $t8, %lo(D_80165C18) # addiu $t8, $t8, 0x5c18
/* 07A28C 8007968C 000F7940 */  sll   $t7, $t7, 5
/* 07A290 80079690 3C198019 */  lui   $t9, %hi(D_8018C028) # $t9, 0x8019
/* 07A294 80079694 8F39C028 */  lw    $t9, %lo(D_8018C028)($t9)
/* 07A298 80079698 01F81021 */  addu  $v0, $t7, $t8
/* 07A29C 8007969C 3C080D00 */  lui   $t0, %hi(D_0D006730) # $t0, 0xd00
/* 07A2A0 800796A0 25086730 */  addiu $t0, %lo(D_0D006730) # addiu $t0, $t0, 0x6730
/* 07A2A4 800796A4 AC480074 */  sw    $t0, 0x74($v0)
/* 07A2A8 800796A8 3C01800F */  lui   $at, %hi(D_800EEC3C) # $at, 0x800f
/* 07A2AC 800796AC E440000C */  swc1  $f0, 0xc($v0)
/* 07A2B0 800796B0 E4400008 */  swc1  $f0, 8($v0)
/* 07A2B4 800796B4 E4400004 */  swc1  $f0, 4($v0)
/* 07A2B8 800796B8 AC590064 */  sw    $t9, 0x64($v0)
/* 07A2BC 800796BC C424EC3C */  lwc1  $f4, %lo(D_800EEC3C)($at)
/* 07A2C0 800796C0 3C06800E */  lui   $a2, %hi(D_800E6834) # $a2, 0x800e
/* 07A2C4 800796C4 24C66834 */  addiu $a2, %lo(D_800E6834) # addiu $a2, $a2, 0x6834
/* 07A2C8 800796C8 02002025 */  move  $a0, $s0
/* 07A2CC 800796CC 24050002 */  li    $a1, 2
/* 07A2D0 800796D0 0C021BC4 */  jal   func_80086F10
/* 07A2D4 800796D4 E4440000 */   swc1  $f4, ($v0)
/* 07A2D8 800796D8 02002025 */  move  $a0, $s0
/* 07A2DC 800796DC 0C01C87A */  jal   func_800721E8
/* 07A2E0 800796E0 24050010 */   li    $a1, 16
/* 07A2E4 800796E4 0C01C922 */  jal   func_80072488
/* 07A2E8 800796E8 02002025 */   move  $a0, $s0
/* 07A2EC 800796EC 8FBF0024 */  lw    $ra, 0x24($sp)
/* 07A2F0 800796F0 8FB00020 */  lw    $s0, 0x20($sp)
/* 07A2F4 800796F4 27BD0028 */  addiu $sp, $sp, 0x28
/* 07A2F8 800796F8 03E00008 */  jr    $ra
/* 07A2FC 800796FC 00000000 */   nop   
