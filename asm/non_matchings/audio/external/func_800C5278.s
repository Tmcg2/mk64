glabel func_800C5278
/* 0C5E78 800C5278 27BDFF68 */  addiu $sp, $sp, -0x98
/* 0C5E7C 800C527C AFB70044 */  sw    $s7, 0x44($sp)
/* 0C5E80 800C5280 309700FF */  andi  $s7, $a0, 0xff
/* 0C5E84 800C5284 00177100 */  sll   $t6, $s7, 4
/* 0C5E88 800C5288 01D77023 */  subu  $t6, $t6, $s7
/* 0C5E8C 800C528C 3C0F8019 */  lui   $t7, %hi(sSoundBanks) # $t7, 0x8019
/* 0C5E90 800C5290 AFB20030 */  sw    $s2, 0x30($sp)
/* 0C5E94 800C5294 25EF1420 */  addiu $t7, %lo(sSoundBanks) # addiu $t7, $t7, 0x1420
/* 0C5E98 800C5298 000E7180 */  sll   $t6, $t6, 6
/* 0C5E9C 800C529C AFB1002C */  sw    $s1, 0x2c($sp)
/* 0C5EA0 800C52A0 01CF9021 */  addu  $s2, $t6, $t7
/* 0C5EA4 800C52A4 9251002B */  lbu   $s1, 0x2b($s2)
/* 0C5EA8 800C52A8 AFB40038 */  sw    $s4, 0x38($sp)
/* 0C5EAC 800C52AC 241400FF */  li    $s4, 255
/* 0C5EB0 800C52B0 AFBE0048 */  sw    $fp, 0x48($sp)
/* 0C5EB4 800C52B4 03A0F025 */  move  $fp, $sp
/* 0C5EB8 800C52B8 AFBF004C */  sw    $ra, 0x4c($sp)
/* 0C5EBC 800C52BC AFB60040 */  sw    $s6, 0x40($sp)
/* 0C5EC0 800C52C0 AFB5003C */  sw    $s5, 0x3c($sp)
/* 0C5EC4 800C52C4 AFB30034 */  sw    $s3, 0x34($sp)
/* 0C5EC8 800C52C8 AFB00028 */  sw    $s0, 0x28($sp)
/* 0C5ECC 800C52CC 1291001B */  beq   $s4, $s1, .L800C533C
/* 0C5ED0 800C52D0 AFA40098 */   sw    $a0, 0x98($sp)
/* 0C5ED4 800C52D4 0017C100 */  sll   $t8, $s7, 4
/* 0C5ED8 800C52D8 0317C023 */  subu  $t8, $t8, $s7
/* 0C5EDC 800C52DC 0018C180 */  sll   $t8, $t8, 6
/* 0C5EE0 800C52E0 030F9821 */  addu  $s3, $t8, $t7
/* 0C5EE4 800C52E4 3C160602 */  lui   $s6, 0x602
/* 0C5EE8 800C52E8 24150030 */  li    $s5, 48
.L800C52EC:
/* 0C5EEC 800C52EC 02350019 */  multu $s1, $s5
/* 0C5EF0 800C52F0 0000C812 */  mflo  $t9
/* 0C5EF4 800C52F4 02798021 */  addu  $s0, $s3, $t9
/* 0C5EF8 800C52F8 92020028 */  lbu   $v0, 0x28($s0)
/* 0C5EFC 800C52FC 28410003 */  slti  $at, $v0, 3
/* 0C5F00 800C5300 14200007 */  bnez  $at, .L800C5320
/* 0C5F04 800C5304 00000000 */   nop   
/* 0C5F08 800C5308 9209002C */  lbu   $t1, 0x2c($s0)
/* 0C5F0C 800C530C 00002825 */  move  $a1, $zero
/* 0C5F10 800C5310 00095200 */  sll   $t2, $t1, 8
/* 0C5F14 800C5314 0C032EFA */  jal   func_800CBBE8
/* 0C5F18 800C5318 01562025 */   or    $a0, $t2, $s6
/* 0C5F1C 800C531C 92020028 */  lbu   $v0, 0x28($s0)
.L800C5320:
/* 0C5F20 800C5320 10400003 */  beqz  $v0, .L800C5330
/* 0C5F24 800C5324 32E400FF */   andi  $a0, $s7, 0xff
/* 0C5F28 800C5328 0C0311CF */  jal   delete_sound_from_bank
/* 0C5F2C 800C532C 322500FF */   andi  $a1, $s1, 0xff
.L800C5330:
/* 0C5F30 800C5330 9251002B */  lbu   $s1, 0x2b($s2)
/* 0C5F34 800C5334 1691FFED */  bne   $s4, $s1, .L800C52EC
/* 0C5F38 800C5338 00000000 */   nop   
.L800C533C:
/* 0C5F3C 800C533C 00175F00 */  sll   $t3, $s7, 0x1c
/* 0C5F40 800C5340 AFCB0084 */  sw    $t3, 0x84($fp)
/* 0C5F44 800C5344 00002025 */  move  $a0, $zero
/* 0C5F48 800C5348 0C031073 */  jal   func_800C41CC
/* 0C5F4C 800C534C 27C50060 */   addiu $a1, $fp, 0x60
/* 0C5F50 800C5350 8FDF004C */  lw    $ra, 0x4c($fp)
/* 0C5F54 800C5354 03C0E825 */  move  $sp, $fp
/* 0C5F58 800C5358 8FD00028 */  lw    $s0, 0x28($fp)
/* 0C5F5C 800C535C 8FD1002C */  lw    $s1, 0x2c($fp)
/* 0C5F60 800C5360 8FD20030 */  lw    $s2, 0x30($fp)
/* 0C5F64 800C5364 8FD30034 */  lw    $s3, 0x34($fp)
/* 0C5F68 800C5368 8FD40038 */  lw    $s4, 0x38($fp)
/* 0C5F6C 800C536C 8FD5003C */  lw    $s5, 0x3c($fp)
/* 0C5F70 800C5370 8FD60040 */  lw    $s6, 0x40($fp)
/* 0C5F74 800C5374 8FD70044 */  lw    $s7, 0x44($fp)
/* 0C5F78 800C5378 8FDE0048 */  lw    $fp, 0x48($fp)
/* 0C5F7C 800C537C 03E00008 */  jr    $ra
/* 0C5F80 800C5380 27BD0098 */   addiu $sp, $sp, 0x98
