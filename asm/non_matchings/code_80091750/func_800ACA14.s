.section .late_rodata
glabel D_800F26C0
.double 4.2

glabel D_800F26C8
.double 4.2

glabel D_800F26D0
.double 4.2

.section .text

glabel func_800ACA14
/* 0AD614 800ACA14 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0AD618 800ACA18 AFBF0014 */  sw    $ra, 0x14($sp)
/* 0AD61C 800ACA1C 8C820004 */  lw    $v0, 4($a0)
/* 0AD620 800ACA20 00802825 */  move  $a1, $a0
/* 0AD624 800ACA24 2401000B */  li    $at, 11
/* 0AD628 800ACA28 50400008 */  beql  $v0, $zero, .L800ACA4C
/* 0AD62C 800ACA2C 8CAE0020 */   lw    $t6, 0x20($a1)
/* 0AD630 800ACA30 10410015 */  beq   $v0, $at, .L800ACA88
/* 0AD634 800ACA34 2401000C */   li    $at, 12
/* 0AD638 800ACA38 10410013 */  beq   $v0, $at, .L800ACA88
/* 0AD63C 800ACA3C 00000000 */   nop
/* 0AD640 800ACA40 1000007B */  b     .L800ACC30
/* 0AD644 800ACA44 8C820020 */   lw    $v0, 0x20($a0)
/* 0AD648 800ACA48 8CAE0020 */  lw    $t6, 0x20($a1)
.L800ACA4C:
/* 0AD64C 800ACA4C 2408000B */  li    $t0, 11
/* 0AD650 800ACA50 29C1000B */  slti  $at, $t6, 0xb
/* 0AD654 800ACA54 54200005 */  bnel  $at, $zero, .L800ACA6C
/* 0AD658 800ACA58 8CB9001C */   lw    $t9, 0x1c($a1)
/* 0AD65C 800ACA5C 8CAF001C */  lw    $t7, 0x1c($a1)
/* 0AD660 800ACA60 25F80003 */  addiu $t8, $t7, 3
/* 0AD664 800ACA64 ACB8001C */  sw    $t8, 0x1c($a1)
/* 0AD668 800ACA68 8CB9001C */  lw    $t9, 0x1c($a1)
.L800ACA6C:
/* 0AD66C 800ACA6C 2B210065 */  slti  $at, $t9, 0x65
/* 0AD670 800ACA70 14200003 */  bnez  $at, .L800ACA80
/* 0AD674 800ACA74 00000000 */   nop
/* 0AD678 800ACA78 ACA80004 */  sw    $t0, 4($a1)
/* 0AD67C 800ACA7C ACA0001C */  sw    $zero, 0x1c($a1)
.L800ACA80:
/* 0AD680 800ACA80 1000006B */  b     .L800ACC30
/* 0AD684 800ACA84 8CA20020 */   lw    $v0, 0x20($a1)
.L800ACA88:
/* 0AD688 800ACA88 0C02D148 */  jal   func_800B4520
/* 0AD68C 800ACA8C AFA50018 */   sw    $a1, 0x18($sp)
/* 0AD690 800ACA90 10400003 */  beqz  $v0, .L800ACAA0
/* 0AD694 800ACA94 8FA50018 */   lw    $a1, 0x18($sp)
/* 0AD698 800ACA98 10000065 */  b     .L800ACC30
/* 0AD69C 800ACA9C 8CA20020 */   lw    $v0, 0x20($a1)
.L800ACAA0:
/* 0AD6A0 800ACAA0 3C02800E */  lui   $v0, %hi(gControllerFive) # $v0, 0x800e
/* 0AD6A4 800ACAA4 8C42C4CC */  lw    $v0, %lo(gControllerFive)($v0)
/* 0AD6A8 800ACAA8 94430006 */  lhu   $v1, 6($v0)
/* 0AD6AC 800ACAAC 9449000C */  lhu   $t1, 0xc($v0)
/* 0AD6B0 800ACAB0 00692025 */  or    $a0, $v1, $t1
/* 0AD6B4 800ACAB4 308A0800 */  andi  $t2, $a0, 0x800
/* 0AD6B8 800ACAB8 51400022 */  beql  $t2, $zero, .L800ACB44
/* 0AD6BC 800ACABC 308F0400 */   andi  $t7, $a0, 0x400
/* 0AD6C0 800ACAC0 8CA20004 */  lw    $v0, 4($a1)
/* 0AD6C4 800ACAC4 2841000C */  slti  $at, $v0, 0xc
/* 0AD6C8 800ACAC8 1420001D */  bnez  $at, .L800ACB40
/* 0AD6CC 800ACACC 244BFFFF */   addiu $t3, $v0, -1
/* 0AD6D0 800ACAD0 ACAB0004 */  sw    $t3, 4($a1)
/* 0AD6D4 800ACAD4 3C044900 */  lui   $a0, (0x49008000 >> 16) # lui $a0, 0x4900
/* 0AD6D8 800ACAD8 34848000 */  ori   $a0, (0x49008000 & 0xFFFF) # ori $a0, $a0, 0x8000
/* 0AD6DC 800ACADC 0C032384 */  jal   play_sound2
/* 0AD6E0 800ACAE0 AFA50018 */   sw    $a1, 0x18($sp)
/* 0AD6E4 800ACAE4 8FA50018 */  lw    $a1, 0x18($sp)
/* 0AD6E8 800ACAE8 3C01800F */  lui   $at, %hi(D_800F26C0)
/* 0AD6EC 800ACAEC D42626C0 */  ldc1  $f6, %lo(D_800F26C0)($at)
/* 0AD6F0 800ACAF0 C4A40024 */  lwc1  $f4, 0x24($a1)
/* 0AD6F4 800ACAF4 3C014010 */  li    $at, 0x40100000 # 2.250000
/* 0AD6F8 800ACAF8 240CFFFF */  li    $t4, -1
/* 0AD6FC 800ACAFC 46002021 */  cvt.d.s $f0, $f4
/* 0AD700 800ACB00 3C0D800E */  lui   $t5, %hi(gControllerFive) # $t5, 0x800e
/* 0AD704 800ACB04 4626003C */  c.lt.d $f0, $f6
/* 0AD708 800ACB08 00000000 */  nop
/* 0AD70C 800ACB0C 45020008 */  bc1fl .L800ACB30
/* 0AD710 800ACB10 ACAC0008 */   sw    $t4, 8($a1)
/* 0AD714 800ACB14 44814800 */  mtc1  $at, $f9
/* 0AD718 800ACB18 44804000 */  mtc1  $zero, $f8
/* 0AD71C 800ACB1C 00000000 */  nop
/* 0AD720 800ACB20 46280280 */  add.d $f10, $f0, $f8
/* 0AD724 800ACB24 46205420 */  cvt.s.d $f16, $f10
/* 0AD728 800ACB28 E4B00024 */  swc1  $f16, 0x24($a1)
/* 0AD72C 800ACB2C ACAC0008 */  sw    $t4, 8($a1)
.L800ACB30:
/* 0AD730 800ACB30 8DADC4CC */  lw    $t5, %lo(gControllerFive)($t5)
/* 0AD734 800ACB34 95A30006 */  lhu   $v1, 6($t5)
/* 0AD738 800ACB38 95AE000C */  lhu   $t6, 0xc($t5)
/* 0AD73C 800ACB3C 006E2025 */  or    $a0, $v1, $t6
.L800ACB40:
/* 0AD740 800ACB40 308F0400 */  andi  $t7, $a0, 0x400
.L800ACB44:
/* 0AD744 800ACB44 51E00020 */  beql  $t7, $zero, .L800ACBC8
/* 0AD748 800ACB48 30699000 */   andi  $t1, $v1, 0x9000
/* 0AD74C 800ACB4C 8CA20004 */  lw    $v0, 4($a1)
/* 0AD750 800ACB50 3C044900 */  lui   $a0, (0x49008000 >> 16) # lui $a0, 0x4900
/* 0AD754 800ACB54 34848000 */  ori   $a0, (0x49008000 & 0xFFFF) # ori $a0, $a0, 0x8000
/* 0AD758 800ACB58 2841000C */  slti  $at, $v0, 0xc
/* 0AD75C 800ACB5C 10200019 */  beqz  $at, .L800ACBC4
/* 0AD760 800ACB60 24580001 */   addiu $t8, $v0, 1
/* 0AD764 800ACB64 ACB80004 */  sw    $t8, 4($a1)
/* 0AD768 800ACB68 0C032384 */  jal   play_sound2
/* 0AD76C 800ACB6C AFA50018 */   sw    $a1, 0x18($sp)
/* 0AD770 800ACB70 8FA50018 */  lw    $a1, 0x18($sp)
/* 0AD774 800ACB74 3C01800F */  lui   $at, %hi(D_800F26C8)
/* 0AD778 800ACB78 D42426C8 */  ldc1  $f4, %lo(D_800F26C8)($at)
/* 0AD77C 800ACB7C C4B20024 */  lwc1  $f18, 0x24($a1)
/* 0AD780 800ACB80 3C014010 */  li    $at, 0x40100000 # 2.250000
/* 0AD784 800ACB84 24190001 */  li    $t9, 1
/* 0AD788 800ACB88 46009021 */  cvt.d.s $f0, $f18
/* 0AD78C 800ACB8C 3C08800E */  lui   $t0, %hi(gControllerFive) # $t0, 0x800e
/* 0AD790 800ACB90 4624003C */  c.lt.d $f0, $f4
/* 0AD794 800ACB94 00000000 */  nop
/* 0AD798 800ACB98 45020008 */  bc1fl .L800ACBBC
/* 0AD79C 800ACB9C ACB90008 */   sw    $t9, 8($a1)
/* 0AD7A0 800ACBA0 44813800 */  mtc1  $at, $f7
/* 0AD7A4 800ACBA4 44803000 */  mtc1  $zero, $f6
/* 0AD7A8 800ACBA8 00000000 */  nop
/* 0AD7AC 800ACBAC 46260200 */  add.d $f8, $f0, $f6
/* 0AD7B0 800ACBB0 462042A0 */  cvt.s.d $f10, $f8
/* 0AD7B4 800ACBB4 E4AA0024 */  swc1  $f10, 0x24($a1)
/* 0AD7B8 800ACBB8 ACB90008 */  sw    $t9, 8($a1)
.L800ACBBC:
/* 0AD7BC 800ACBBC 8D08C4CC */  lw    $t0, %lo(gControllerFive)($t0)
/* 0AD7C0 800ACBC0 95030006 */  lhu   $v1, 6($t0)
.L800ACBC4:
/* 0AD7C4 800ACBC4 30699000 */  andi  $t1, $v1, 0x9000
.L800ACBC8:
/* 0AD7C8 800ACBC8 11200018 */  beqz  $t1, .L800ACC2C
/* 0AD7CC 800ACBCC 2404001E */   li    $a0, 30
/* 0AD7D0 800ACBD0 0C0277F8 */  jal   func_8009DFE0
/* 0AD7D4 800ACBD4 AFA50018 */   sw    $a1, 0x18($sp)
/* 0AD7D8 800ACBD8 0C0328CC */  jal   func_800CA330
/* 0AD7DC 800ACBDC 24040019 */   li    $a0, 25
/* 0AD7E0 800ACBE0 3C044900 */  lui   $a0, (0x4900801B >> 16) # lui $a0, 0x4900
/* 0AD7E4 800ACBE4 0C032384 */  jal   play_sound2
/* 0AD7E8 800ACBE8 3484801B */   ori   $a0, (0x4900801B & 0xFFFF) # ori $a0, $a0, 0x801b
/* 0AD7EC 800ACBEC 8FA50018 */  lw    $a1, 0x18($sp)
/* 0AD7F0 800ACBF0 3C01800F */  lui   $at, %hi(D_800F26D0)
/* 0AD7F4 800ACBF4 D43226D0 */  ldc1  $f18, %lo(D_800F26D0)($at)
/* 0AD7F8 800ACBF8 C4B00024 */  lwc1  $f16, 0x24($a1)
/* 0AD7FC 800ACBFC 3C014010 */  li    $at, 0x40100000 # 2.250000
/* 0AD800 800ACC00 46008021 */  cvt.d.s $f0, $f16
/* 0AD804 800ACC04 4632003C */  c.lt.d $f0, $f18
/* 0AD808 800ACC08 00000000 */  nop
/* 0AD80C 800ACC0C 45020008 */  bc1fl .L800ACC30
/* 0AD810 800ACC10 8CA20020 */   lw    $v0, 0x20($a1)
/* 0AD814 800ACC14 44812800 */  mtc1  $at, $f5
/* 0AD818 800ACC18 44802000 */  mtc1  $zero, $f4
/* 0AD81C 800ACC1C 00000000 */  nop
/* 0AD820 800ACC20 46240180 */  add.d $f6, $f0, $f4
/* 0AD824 800ACC24 46203220 */  cvt.s.d $f8, $f6
/* 0AD828 800ACC28 E4A80024 */  swc1  $f8, 0x24($a1)
.L800ACC2C:
/* 0AD82C 800ACC2C 8CA20020 */  lw    $v0, 0x20($a1)
.L800ACC30:
/* 0AD830 800ACC30 28410028 */  slti  $at, $v0, 0x28
/* 0AD834 800ACC34 10200002 */  beqz  $at, .L800ACC40
/* 0AD838 800ACC38 244A0001 */   addiu $t2, $v0, 1
/* 0AD83C 800ACC3C ACAA0020 */  sw    $t2, 0x20($a1)
.L800ACC40:
/* 0AD840 800ACC40 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0AD844 800ACC44 27BD0018 */  addiu $sp, $sp, 0x18
/* 0AD848 800ACC48 03E00008 */  jr    $ra
/* 0AD84C 800ACC4C 00000000 */   nop
