glabel func_802903D8
/* 0F99E8 802903D8 27BDFF88 */  addiu $sp, $sp, -0x78
/* 0F99EC 802903DC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0F99F0 802903E0 C4A60070 */  lwc1  $f6, 0x70($a1)
/* 0F99F4 802903E4 C4840070 */  lwc1  $f4, 0x70($a0)
/* 0F99F8 802903E8 3C0140A0 */  li    $at, 0x40A00000 # 5.000000
/* 0F99FC 802903EC 44815000 */  mtc1  $at, $f10
/* 0F9A00 802903F0 46062200 */  add.s $f8, $f4, $f6
/* 0F9A04 802903F4 3C0E802C */  lui   $t6, %hi(gFloatArray802B8790) # $t6, 0x802c
/* 0F9A08 802903F8 25CE8790 */  addiu $t6, %lo(gFloatArray802B8790) # addiu $t6, $t6, -0x7870
/* 0F9A0C 802903FC 27A20028 */  addiu $v0, $sp, 0x28
/* 0F9A10 80290400 460A4101 */  sub.s $f4, $f8, $f10
/* 0F9A14 80290404 00803825 */  move  $a3, $a0
/* 0F9A18 80290408 00A03025 */  move  $a2, $a1
/* 0F9A1C 8029040C E7A40074 */  swc1  $f4, 0x74($sp)
/* 0F9A20 80290410 8DC10000 */  lw    $at, ($t6)
/* 0F9A24 80290414 AC410000 */  sw    $at, ($v0)
/* 0F9A28 80290418 8DD90004 */  lw    $t9, 4($t6)
/* 0F9A2C 8029041C AC590004 */  sw    $t9, 4($v0)
/* 0F9A30 80290420 8DC10008 */  lw    $at, 8($t6)
/* 0F9A34 80290424 AC410008 */  sw    $at, 8($v0)
/* 0F9A38 80290428 8DD9000C */  lw    $t9, 0xc($t6)
/* 0F9A3C 8029042C AC59000C */  sw    $t9, 0xc($v0)
/* 0F9A40 80290430 8DC10010 */  lw    $at, 0x10($t6)
/* 0F9A44 80290434 AC410010 */  sw    $at, 0x10($v0)
/* 0F9A48 80290438 8DD90014 */  lw    $t9, 0x14($t6)
/* 0F9A4C 8029043C AC590014 */  sw    $t9, 0x14($v0)
/* 0F9A50 80290440 8DC10018 */  lw    $at, 0x18($t6)
/* 0F9A54 80290444 AC410018 */  sw    $at, 0x18($v0)
/* 0F9A58 80290448 8DD9001C */  lw    $t9, 0x1c($t6)
/* 0F9A5C 8029044C 3C01802C */  lui   $at, %hi(D_802B92A0) # $at, 0x802c
/* 0F9A60 80290450 AC59001C */  sw    $t9, 0x1c($v0)
/* 0F9A64 80290454 94880254 */  lhu   $t0, 0x254($a0)
/* 0F9A68 80290458 00084880 */  sll   $t1, $t0, 2
/* 0F9A6C 8029045C 00495021 */  addu  $t2, $v0, $t1
/* 0F9A70 80290460 C5460000 */  lwc1  $f6, ($t2)
/* 0F9A74 80290464 E7A60024 */  swc1  $f6, 0x24($sp)
/* 0F9A78 80290468 94AB0254 */  lhu   $t3, 0x254($a1)
/* 0F9A7C 8029046C 000B6080 */  sll   $t4, $t3, 2
/* 0F9A80 80290470 004C6821 */  addu  $t5, $v0, $t4
/* 0F9A84 80290474 C5A80000 */  lwc1  $f8, ($t5)
/* 0F9A88 80290478 E7A80020 */  swc1  $f8, 0x20($sp)
/* 0F9A8C 8029047C C4A40014 */  lwc1  $f4, 0x14($a1)
/* 0F9A90 80290480 C48A0014 */  lwc1  $f10, 0x14($a0)
/* 0F9A94 80290484 46045181 */  sub.s $f6, $f10, $f4
/* 0F9A98 80290488 E7A60060 */  swc1  $f6, 0x60($sp)
/* 0F9A9C 8029048C C48A0070 */  lwc1  $f10, 0x70($a0)
/* 0F9AA0 80290490 C4880018 */  lwc1  $f8, 0x18($a0)
/* 0F9AA4 80290494 C4A60018 */  lwc1  $f6, 0x18($a1)
/* 0F9AA8 80290498 460A4101 */  sub.s $f4, $f8, $f10
/* 0F9AAC 8029049C C4A80070 */  lwc1  $f8, 0x70($a1)
/* 0F9AB0 802904A0 46083281 */  sub.s $f10, $f6, $f8
/* 0F9AB4 802904A4 460A2181 */  sub.s $f6, $f4, $f10
/* 0F9AB8 802904A8 E7A60064 */  swc1  $f6, 0x64($sp)
/* 0F9ABC 802904AC C4A4001C */  lwc1  $f4, 0x1c($a1)
/* 0F9AC0 802904B0 C488001C */  lwc1  $f8, 0x1c($a0)
/* 0F9AC4 802904B4 46044281 */  sub.s $f10, $f8, $f4
/* 0F9AC8 802904B8 E7AA0068 */  swc1  $f10, 0x68($sp)
/* 0F9ACC 802904BC C4840034 */  lwc1  $f4, 0x34($a0)
/* 0F9AD0 802904C0 C4A80034 */  lwc1  $f8, 0x34($a1)
/* 0F9AD4 802904C4 46044281 */  sub.s $f10, $f8, $f4
/* 0F9AD8 802904C8 E7AA0054 */  swc1  $f10, 0x54($sp)
/* 0F9ADC 802904CC C4840038 */  lwc1  $f4, 0x38($a0)
/* 0F9AE0 802904D0 C4A80038 */  lwc1  $f8, 0x38($a1)
/* 0F9AE4 802904D4 46044281 */  sub.s $f10, $f8, $f4
/* 0F9AE8 802904D8 E7AA0058 */  swc1  $f10, 0x58($sp)
/* 0F9AEC 802904DC C484003C */  lwc1  $f4, 0x3c($a0)
/* 0F9AF0 802904E0 C4A8003C */  lwc1  $f8, 0x3c($a1)
/* 0F9AF4 802904E4 46044281 */  sub.s $f10, $f8, $f4
/* 0F9AF8 802904E8 46063202 */  mul.s $f8, $f6, $f6
/* 0F9AFC 802904EC C7A40060 */  lwc1  $f4, 0x60($sp)
/* 0F9B00 802904F0 E7AA005C */  swc1  $f10, 0x5c($sp)
/* 0F9B04 802904F4 46042282 */  mul.s $f10, $f4, $f4
/* 0F9B08 802904F8 C7A40068 */  lwc1  $f4, 0x68($sp)
/* 0F9B0C 802904FC 46085180 */  add.s $f6, $f10, $f8
/* 0F9B10 80290500 46042282 */  mul.s $f10, $f4, $f4
/* 0F9B14 80290504 C42892A0 */  lwc1  $f8, %lo(D_802B92A0)($at)
/* 0F9B18 80290508 C7A40074 */  lwc1  $f4, 0x74($sp)
/* 0F9B1C 8029050C 46065000 */  add.s $f0, $f10, $f6
/* 0F9B20 80290510 46000004 */  sqrt.s $f0, $f0
/* 0F9B24 80290514 4608003C */  c.lt.s $f0, $f8
/* 0F9B28 80290518 46000386 */  mov.s $f14, $f0
/* 0F9B2C 8029051C 45030131 */  bc1tl .L802909E4
/* 0F9B30 80290520 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F9B34 80290524 4600203C */  c.lt.s $f4, $f0
/* 0F9B38 80290528 00000000 */  nop
/* 0F9B3C 8029052C 4503012D */  bc1tl .L802909E4
/* 0F9B40 80290530 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F9B44 80290534 94980000 */  lhu   $t8, ($a0)
/* 0F9B48 80290538 330F0040 */  andi  $t7, $t8, 0x40
/* 0F9B4C 8029053C 51E0002F */  beql  $t7, $zero, .L802905FC
/* 0F9B50 80290540 94CE0000 */   lhu   $t6, ($a2)
/* 0F9B54 80290544 94AE0000 */  lhu   $t6, ($a1)
/* 0F9B58 80290548 31D90040 */  andi  $t9, $t6, 0x40
/* 0F9B5C 8029054C 53200013 */  beql  $t9, $zero, .L8029059C
/* 0F9B60 80290550 8CCB000C */   lw    $t3, 0xc($a2)
/* 0F9B64 80290554 0C023F07 */  jal   func_8008FC1C
/* 0F9B68 80290558 AFA5007C */   sw    $a1, 0x7c($sp)
/* 0F9B6C 8029055C 0C023F07 */  jal   func_8008FC1C
/* 0F9B70 80290560 8FA4007C */   lw    $a0, 0x7c($sp)
/* 0F9B74 80290564 3C08800E */  lui   $t0, %hi(gPlayerOne) # $t0, 0x800e
/* 0F9B78 80290568 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0F9B7C 8029056C 8D08C4DC */  lw    $t0, %lo(gPlayerOne)($t0)
/* 0F9B80 80290570 24010DD8 */  li    $at, 3544
/* 0F9B84 80290574 3C051900 */  lui   $a1, (0x19008001 >> 16) # lui $a1, 0x1900
/* 0F9B88 80290578 00C82023 */  subu  $a0, $a2, $t0
/* 0F9B8C 8029057C 0081001A */  div   $zero, $a0, $at
/* 0F9B90 80290580 00004812 */  mflo  $t1
/* 0F9B94 80290584 312400FF */  andi  $a0, $t1, 0xff
/* 0F9B98 80290588 0C032418 */  jal   func_800C9060
/* 0F9B9C 8029058C 34A58001 */   ori   $a1, (0x19008001 & 0xFFFF) # ori $a1, $a1, 0x8001
/* 0F9BA0 80290590 10000114 */  b     .L802909E4
/* 0F9BA4 80290594 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F9BA8 80290598 8CCB000C */  lw    $t3, 0xc($a2)
.L8029059C:
/* 0F9BAC 8029059C 3C010040 */  lui   $at, 0x40
/* 0F9BB0 802905A0 00E02025 */  move  $a0, $a3
/* 0F9BB4 802905A4 01616025 */  or    $t4, $t3, $at
/* 0F9BB8 802905A8 ACCC000C */  sw    $t4, 0xc($a2)
/* 0F9BBC 802905AC E7AE0070 */  swc1  $f14, 0x70($sp)
/* 0F9BC0 802905B0 AFA70078 */  sw    $a3, 0x78($sp)
/* 0F9BC4 802905B4 0C023F07 */  jal   func_8008FC1C
/* 0F9BC8 802905B8 AFA6007C */   sw    $a2, 0x7c($sp)
/* 0F9BCC 802905BC 3C0D800E */  lui   $t5, %hi(gPlayerOne) # $t5, 0x800e
/* 0F9BD0 802905C0 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0F9BD4 802905C4 8DADC4DC */  lw    $t5, %lo(gPlayerOne)($t5)
/* 0F9BD8 802905C8 24010DD8 */  li    $at, 3544
/* 0F9BDC 802905CC 3C051900 */  lui   $a1, (0x19008001 >> 16) # lui $a1, 0x1900
/* 0F9BE0 802905D0 00CD2023 */  subu  $a0, $a2, $t5
/* 0F9BE4 802905D4 0081001A */  div   $zero, $a0, $at
/* 0F9BE8 802905D8 0000C012 */  mflo  $t8
/* 0F9BEC 802905DC 330400FF */  andi  $a0, $t8, 0xff
/* 0F9BF0 802905E0 0C032418 */  jal   func_800C9060
/* 0F9BF4 802905E4 34A58001 */   ori   $a1, (0x19008001 & 0xFFFF) # ori $a1, $a1, 0x8001
/* 0F9BF8 802905E8 8FA6007C */  lw    $a2, 0x7c($sp)
/* 0F9BFC 802905EC 8FA70078 */  lw    $a3, 0x78($sp)
/* 0F9C00 802905F0 10000019 */  b     .L80290658
/* 0F9C04 802905F4 C7AE0070 */   lwc1  $f14, 0x70($sp)
/* 0F9C08 802905F8 94CE0000 */  lhu   $t6, ($a2)
.L802905FC:
/* 0F9C0C 802905FC 31D90040 */  andi  $t9, $t6, 0x40
/* 0F9C10 80290600 53200016 */  beql  $t9, $zero, .L8029065C
/* 0F9C14 80290604 8CE200BC */   lw    $v0, 0xbc($a3)
/* 0F9C18 80290608 8CE8000C */  lw    $t0, 0xc($a3)
/* 0F9C1C 8029060C 3C010040 */  lui   $at, 0x40
/* 0F9C20 80290610 00C02025 */  move  $a0, $a2
/* 0F9C24 80290614 01014825 */  or    $t1, $t0, $at
/* 0F9C28 80290618 ACE9000C */  sw    $t1, 0xc($a3)
/* 0F9C2C 8029061C 0C023F07 */  jal   func_8008FC1C
/* 0F9C30 80290620 AFA70078 */   sw    $a3, 0x78($sp)
/* 0F9C34 80290624 3C0A800E */  lui   $t2, %hi(gPlayerOne) # $t2, 0x800e
/* 0F9C38 80290628 8FA70078 */  lw    $a3, 0x78($sp)
/* 0F9C3C 8029062C 8D4AC4DC */  lw    $t2, %lo(gPlayerOne)($t2)
/* 0F9C40 80290630 24010DD8 */  li    $at, 3544
/* 0F9C44 80290634 3C051900 */  lui   $a1, (0x19008001 >> 16) # lui $a1, 0x1900
/* 0F9C48 80290638 00EA2023 */  subu  $a0, $a3, $t2
/* 0F9C4C 8029063C 0081001A */  div   $zero, $a0, $at
/* 0F9C50 80290640 00005812 */  mflo  $t3
/* 0F9C54 80290644 316400FF */  andi  $a0, $t3, 0xff
/* 0F9C58 80290648 0C032418 */  jal   func_800C9060
/* 0F9C5C 8029064C 34A58001 */   ori   $a1, (0x19008001 & 0xFFFF) # ori $a1, $a1, 0x8001
/* 0F9C60 80290650 100000E4 */  b     .L802909E4
/* 0F9C64 80290654 8FBF0014 */   lw    $ra, 0x14($sp)
.L80290658:
/* 0F9C68 80290658 8CE200BC */  lw    $v0, 0xbc($a3)
.L8029065C:
/* 0F9C6C 8029065C 304D0200 */  andi  $t5, $v0, 0x200
/* 0F9C70 80290660 51A0000B */  beql  $t5, $zero, .L80290690
/* 0F9C74 80290664 8CC800BC */   lw    $t0, 0xbc($a2)
/* 0F9C78 80290668 8CD800BC */  lw    $t8, 0xbc($a2)
/* 0F9C7C 8029066C 330F0200 */  andi  $t7, $t8, 0x200
/* 0F9C80 80290670 55E00015 */  bnel  $t7, $zero, .L802906C8
/* 0F9C84 80290674 C7A20054 */   lwc1  $f2, 0x54($sp)
/* 0F9C88 80290678 8CCE000C */  lw    $t6, 0xc($a2)
/* 0F9C8C 8029067C 3C010100 */  lui   $at, 0x100
/* 0F9C90 80290680 01C1C825 */  or    $t9, $t6, $at
/* 0F9C94 80290684 1000000F */  b     .L802906C4
/* 0F9C98 80290688 ACD9000C */   sw    $t9, 0xc($a2)
/* 0F9C9C 8029068C 8CC800BC */  lw    $t0, 0xbc($a2)
.L80290690:
/* 0F9CA0 80290690 344C8000 */  ori   $t4, $v0, 0x8000
/* 0F9CA4 80290694 31090200 */  andi  $t1, $t0, 0x200
/* 0F9CA8 80290698 51200007 */  beql  $t1, $zero, .L802906B8
/* 0F9CAC 8029069C ACEC00BC */   sw    $t4, 0xbc($a3)
/* 0F9CB0 802906A0 8CEA000C */  lw    $t2, 0xc($a3)
/* 0F9CB4 802906A4 3C010100 */  lui   $at, 0x100
/* 0F9CB8 802906A8 01415825 */  or    $t3, $t2, $at
/* 0F9CBC 802906AC 10000005 */  b     .L802906C4
/* 0F9CC0 802906B0 ACEB000C */   sw    $t3, 0xc($a3)
/* 0F9CC4 802906B4 ACEC00BC */  sw    $t4, 0xbc($a3)
.L802906B8:
/* 0F9CC8 802906B8 8CCD00BC */  lw    $t5, 0xbc($a2)
/* 0F9CCC 802906BC 35B88000 */  ori   $t8, $t5, 0x8000
/* 0F9CD0 802906C0 ACD800BC */  sw    $t8, 0xbc($a2)
.L802906C4:
/* 0F9CD4 802906C4 C7A20054 */  lwc1  $f2, 0x54($sp)
.L802906C8:
/* 0F9CD8 802906C8 C7AC0058 */  lwc1  $f12, 0x58($sp)
/* 0F9CDC 802906CC C7B0005C */  lwc1  $f16, 0x5c($sp)
/* 0F9CE0 802906D0 46021282 */  mul.s $f10, $f2, $f2
/* 0F9CE4 802906D4 3C01802C */  lui   $at, %hi(D_802B92A4) # $at, 0x802c
/* 0F9CE8 802906D8 460C6182 */  mul.s $f6, $f12, $f12
/* 0F9CEC 802906DC 46065200 */  add.s $f8, $f10, $f6
/* 0F9CF0 802906E0 46108102 */  mul.s $f4, $f16, $f16
/* 0F9CF4 802906E4 C7AA0060 */  lwc1  $f10, 0x60($sp)
/* 0F9CF8 802906E8 460E5183 */  div.s $f6, $f10, $f14
/* 0F9CFC 802906EC C7AA0068 */  lwc1  $f10, 0x68($sp)
/* 0F9D00 802906F0 46082000 */  add.s $f0, $f4, $f8
/* 0F9D04 802906F4 C7A40064 */  lwc1  $f4, 0x64($sp)
/* 0F9D08 802906F8 46000004 */  sqrt.s $f0, $f0
/* 0F9D0C 802906FC E7A60060 */  swc1  $f6, 0x60($sp)
/* 0F9D10 80290700 460E2203 */  div.s $f8, $f4, $f14
/* 0F9D14 80290704 460E5103 */  div.s $f4, $f10, $f14
/* 0F9D18 80290708 E7A80064 */  swc1  $f8, 0x64($sp)
/* 0F9D1C 8029070C C42892A4 */  lwc1  $f8, %lo(D_802B92A4)($at)
/* 0F9D20 80290710 4608003C */  c.lt.s $f0, $f8
/* 0F9D24 80290714 00000000 */  nop
/* 0F9D28 80290718 45000025 */  bc1f  .L802907B0
/* 0F9D2C 8029071C E7A40068 */   swc1  $f4, 0x68($sp)
/* 0F9D30 80290720 C4EA0070 */  lwc1  $f10, 0x70($a3)
/* 0F9D34 80290724 C4C40070 */  lwc1  $f4, 0x70($a2)
/* 0F9D38 80290728 3C01802C */  lui   $at, %hi(D_802B92A8) # $at, 0x802c
/* 0F9D3C 8029072C 46045200 */  add.s $f8, $f10, $f4
/* 0F9D40 80290730 C42A92A8 */  lwc1  $f10, %lo(D_802B92A8)($at)
/* 0F9D44 80290734 460A4382 */  mul.s $f14, $f8, $f10
/* 0F9D48 80290738 C4C80014 */  lwc1  $f8, 0x14($a2)
/* 0F9D4C 8029073C 460E3102 */  mul.s $f4, $f6, $f14
/* 0F9D50 80290740 46082280 */  add.s $f10, $f4, $f8
/* 0F9D54 80290744 E4EA0014 */  swc1  $f10, 0x14($a3)
/* 0F9D58 80290748 C7A60064 */  lwc1  $f6, 0x64($sp)
/* 0F9D5C 8029074C C4C80018 */  lwc1  $f8, 0x18($a2)
/* 0F9D60 80290750 460E3102 */  mul.s $f4, $f6, $f14
/* 0F9D64 80290754 46082280 */  add.s $f10, $f4, $f8
/* 0F9D68 80290758 E4EA0018 */  swc1  $f10, 0x18($a3)
/* 0F9D6C 8029075C C7A60068 */  lwc1  $f6, 0x68($sp)
/* 0F9D70 80290760 C4C8001C */  lwc1  $f8, 0x1c($a2)
/* 0F9D74 80290764 460E3102 */  mul.s $f4, $f6, $f14
/* 0F9D78 80290768 46082280 */  add.s $f10, $f4, $f8
/* 0F9D7C 8029076C E4EA001C */  swc1  $f10, 0x1c($a3)
/* 0F9D80 80290770 C7A40060 */  lwc1  $f4, 0x60($sp)
/* 0F9D84 80290774 C4C60014 */  lwc1  $f6, 0x14($a2)
/* 0F9D88 80290778 46047202 */  mul.s $f8, $f14, $f4
/* 0F9D8C 8029077C C4C40018 */  lwc1  $f4, 0x18($a2)
/* 0F9D90 80290780 46083281 */  sub.s $f10, $f6, $f8
/* 0F9D94 80290784 E4CA0014 */  swc1  $f10, 0x14($a2)
/* 0F9D98 80290788 C7A60064 */  lwc1  $f6, 0x64($sp)
/* 0F9D9C 8029078C 46067202 */  mul.s $f8, $f14, $f6
/* 0F9DA0 80290790 C4C6001C */  lwc1  $f6, 0x1c($a2)
/* 0F9DA4 80290794 46082281 */  sub.s $f10, $f4, $f8
/* 0F9DA8 80290798 E4CA0018 */  swc1  $f10, 0x18($a2)
/* 0F9DAC 8029079C C7A40068 */  lwc1  $f4, 0x68($sp)
/* 0F9DB0 802907A0 46047202 */  mul.s $f8, $f14, $f4
/* 0F9DB4 802907A4 46083281 */  sub.s $f10, $f6, $f8
/* 0F9DB8 802907A8 1000008D */  b     .L802909E0
/* 0F9DBC 802907AC E4CA001C */   swc1  $f10, 0x1c($a2)
.L802907B0:
/* 0F9DC0 802907B0 C7A40060 */  lwc1  $f4, 0x60($sp)
/* 0F9DC4 802907B4 C7A80064 */  lwc1  $f8, 0x64($sp)
/* 0F9DC8 802907B8 3C01802C */  lui   $at, %hi(D_802B92B0)
/* 0F9DCC 802907BC 46022182 */  mul.s $f6, $f4, $f2
/* 0F9DD0 802907C0 8CEF00BC */  lw    $t7, 0xbc($a3)
/* 0F9DD4 802907C4 24020200 */  li    $v0, 512
/* 0F9DD8 802907C8 460C4282 */  mul.s $f10, $f8, $f12
/* 0F9DDC 802907CC C7A80068 */  lwc1  $f8, 0x68($sp)
/* 0F9DE0 802907D0 31EE0200 */  andi  $t6, $t7, 0x200
/* 0F9DE4 802907D4 3C0B800E */  lui   $t3, %hi(gPlayerOne) # $t3, 0x800e
/* 0F9DE8 802907D8 460A3100 */  add.s $f4, $f6, $f10
/* 0F9DEC 802907DC 46088182 */  mul.s $f6, $f16, $f8
/* 0F9DF0 802907E0 46043280 */  add.s $f10, $f6, $f4
/* 0F9DF4 802907E4 D42492B0 */  ldc1  $f4, %lo(D_802B92B0)($at)
/* 0F9DF8 802907E8 46005483 */  div.s $f18, $f10, $f0
/* 0F9DFC 802907EC 46120202 */  mul.s $f8, $f0, $f18
/* 0F9E00 802907F0 460041A1 */  cvt.d.s $f6, $f8
/* 0F9E04 802907F4 C7A80020 */  lwc1  $f8, 0x20($sp)
/* 0F9E08 802907F8 46243282 */  mul.d $f10, $f6, $f4
/* 0F9E0C 802907FC 104E002C */  beq   $v0, $t6, .L802908B0
/* 0F9E10 80290800 46205420 */   cvt.s.d $f16, $f10
/* 0F9E14 80290804 46088182 */  mul.s $f6, $f16, $f8
/* 0F9E18 80290808 C7A40024 */  lwc1  $f4, 0x24($sp)
/* 0F9E1C 8029080C C7A80060 */  lwc1  $f8, 0x60($sp)
/* 0F9E20 80290810 C4EA0034 */  lwc1  $f10, 0x34($a3)
/* 0F9E24 80290814 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F9E28 80290818 44816000 */  mtc1  $at, $f12
/* 0F9E2C 8029081C 46043083 */  div.s $f2, $f6, $f4
/* 0F9E30 80290820 46024182 */  mul.s $f6, $f8, $f2
/* 0F9E34 80290824 C4E80038 */  lwc1  $f8, 0x38($a3)
/* 0F9E38 80290828 46065100 */  add.s $f4, $f10, $f6
/* 0F9E3C 8029082C E4E40034 */  swc1  $f4, 0x34($a3)
/* 0F9E40 80290830 C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 0F9E44 80290834 46025182 */  mul.s $f6, $f10, $f2
/* 0F9E48 80290838 C4EA003C */  lwc1  $f10, 0x3c($a3)
/* 0F9E4C 8029083C 46064100 */  add.s $f4, $f8, $f6
/* 0F9E50 80290840 E4E40038 */  swc1  $f4, 0x38($a3)
/* 0F9E54 80290844 C7A80068 */  lwc1  $f8, 0x68($sp)
/* 0F9E58 80290848 46024182 */  mul.s $f6, $f8, $f2
/* 0F9E5C 8029084C 46065100 */  add.s $f4, $f10, $f6
/* 0F9E60 80290850 C4EA0014 */  lwc1  $f10, 0x14($a3)
/* 0F9E64 80290854 E4E4003C */  swc1  $f4, 0x3c($a3)
/* 0F9E68 80290858 C7A80074 */  lwc1  $f8, 0x74($sp)
/* 0F9E6C 8029085C C7A60060 */  lwc1  $f6, 0x60($sp)
/* 0F9E70 80290860 46087001 */  sub.s $f0, $f14, $f8
/* 0F9E74 80290864 46003102 */  mul.s $f4, $f6, $f0
/* 0F9E78 80290868 00000000 */  nop
/* 0F9E7C 8029086C 460C2202 */  mul.s $f8, $f4, $f12
/* 0F9E80 80290870 C4E40018 */  lwc1  $f4, 0x18($a3)
/* 0F9E84 80290874 46085181 */  sub.s $f6, $f10, $f8
/* 0F9E88 80290878 E4E60014 */  swc1  $f6, 0x14($a3)
/* 0F9E8C 8029087C C7AA0064 */  lwc1  $f10, 0x64($sp)
/* 0F9E90 80290880 46005202 */  mul.s $f8, $f10, $f0
/* 0F9E94 80290884 00000000 */  nop
/* 0F9E98 80290888 460C4182 */  mul.s $f6, $f8, $f12
/* 0F9E9C 8029088C C4E8001C */  lwc1  $f8, 0x1c($a3)
/* 0F9EA0 80290890 46062281 */  sub.s $f10, $f4, $f6
/* 0F9EA4 80290894 E4EA0018 */  swc1  $f10, 0x18($a3)
/* 0F9EA8 80290898 C7A40068 */  lwc1  $f4, 0x68($sp)
/* 0F9EAC 8029089C 46002182 */  mul.s $f6, $f4, $f0
/* 0F9EB0 802908A0 00000000 */  nop
/* 0F9EB4 802908A4 460C3282 */  mul.s $f10, $f6, $f12
/* 0F9EB8 802908A8 460A4101 */  sub.s $f4, $f8, $f10
/* 0F9EBC 802908AC E4E4001C */  swc1  $f4, 0x1c($a3)
.L802908B0:
/* 0F9EC0 802908B0 8CD900BC */  lw    $t9, 0xbc($a2)
/* 0F9EC4 802908B4 3C013F00 */  li    $at, 0x3F000000 # 0.500000
/* 0F9EC8 802908B8 44816000 */  mtc1  $at, $f12
/* 0F9ECC 802908BC 33280200 */  andi  $t0, $t9, 0x200
/* 0F9ED0 802908C0 1048002A */  beq   $v0, $t0, .L8029096C
/* 0F9ED4 802908C4 C7A60024 */   lwc1  $f6, 0x24($sp)
/* 0F9ED8 802908C8 46068202 */  mul.s $f8, $f16, $f6
/* 0F9EDC 802908CC C7AA0020 */  lwc1  $f10, 0x20($sp)
/* 0F9EE0 802908D0 C7A60060 */  lwc1  $f6, 0x60($sp)
/* 0F9EE4 802908D4 C4C40034 */  lwc1  $f4, 0x34($a2)
/* 0F9EE8 802908D8 460A4083 */  div.s $f2, $f8, $f10
/* 0F9EEC 802908DC 46023202 */  mul.s $f8, $f6, $f2
/* 0F9EF0 802908E0 C4C60038 */  lwc1  $f6, 0x38($a2)
/* 0F9EF4 802908E4 46082281 */  sub.s $f10, $f4, $f8
/* 0F9EF8 802908E8 E4CA0034 */  swc1  $f10, 0x34($a2)
/* 0F9EFC 802908EC C7A40064 */  lwc1  $f4, 0x64($sp)
/* 0F9F00 802908F0 46022202 */  mul.s $f8, $f4, $f2
/* 0F9F04 802908F4 C4C4003C */  lwc1  $f4, 0x3c($a2)
/* 0F9F08 802908F8 46083281 */  sub.s $f10, $f6, $f8
/* 0F9F0C 802908FC E4CA0038 */  swc1  $f10, 0x38($a2)
/* 0F9F10 80290900 C7A60068 */  lwc1  $f6, 0x68($sp)
/* 0F9F14 80290904 46023202 */  mul.s $f8, $f6, $f2
/* 0F9F18 80290908 46082281 */  sub.s $f10, $f4, $f8
/* 0F9F1C 8029090C C4C40014 */  lwc1  $f4, 0x14($a2)
/* 0F9F20 80290910 E4CA003C */  swc1  $f10, 0x3c($a2)
/* 0F9F24 80290914 C7A60074 */  lwc1  $f6, 0x74($sp)
/* 0F9F28 80290918 C7A80060 */  lwc1  $f8, 0x60($sp)
/* 0F9F2C 8029091C 46067001 */  sub.s $f0, $f14, $f6
/* 0F9F30 80290920 46004282 */  mul.s $f10, $f8, $f0
/* 0F9F34 80290924 00000000 */  nop
/* 0F9F38 80290928 460C5182 */  mul.s $f6, $f10, $f12
/* 0F9F3C 8029092C C4CA0018 */  lwc1  $f10, 0x18($a2)
/* 0F9F40 80290930 46062200 */  add.s $f8, $f4, $f6
/* 0F9F44 80290934 E4C80014 */  swc1  $f8, 0x14($a2)
/* 0F9F48 80290938 C7A40064 */  lwc1  $f4, 0x64($sp)
/* 0F9F4C 8029093C 46002182 */  mul.s $f6, $f4, $f0
/* 0F9F50 80290940 00000000 */  nop
/* 0F9F54 80290944 460C3202 */  mul.s $f8, $f6, $f12
/* 0F9F58 80290948 C4C6001C */  lwc1  $f6, 0x1c($a2)
/* 0F9F5C 8029094C 46085100 */  add.s $f4, $f10, $f8
/* 0F9F60 80290950 E4C40018 */  swc1  $f4, 0x18($a2)
/* 0F9F64 80290954 C7AA0068 */  lwc1  $f10, 0x68($sp)
/* 0F9F68 80290958 46005202 */  mul.s $f8, $f10, $f0
/* 0F9F6C 8029095C 00000000 */  nop
/* 0F9F70 80290960 460C4102 */  mul.s $f4, $f8, $f12
/* 0F9F74 80290964 46043280 */  add.s $f10, $f6, $f4
/* 0F9F78 80290968 E4CA001C */  swc1  $f10, 0x1c($a2)
.L8029096C:
/* 0F9F7C 8029096C 94E90000 */  lhu   $t1, ($a3)
/* 0F9F80 80290970 312A4000 */  andi  $t2, $t1, 0x4000
/* 0F9F84 80290974 5140000D */  beql  $t2, $zero, .L802909AC
/* 0F9F88 80290978 94D80000 */   lhu   $t8, ($a2)
/* 0F9F8C 8029097C 8D6BC4DC */  lw    $t3, %lo(gPlayerOne)($t3)
/* 0F9F90 80290980 24010DD8 */  li    $at, 3544
/* 0F9F94 80290984 3C051900 */  lui   $a1, (0x19008001 >> 16) # lui $a1, 0x1900
/* 0F9F98 80290988 00EB2023 */  subu  $a0, $a3, $t3
/* 0F9F9C 8029098C 0081001A */  div   $zero, $a0, $at
/* 0F9FA0 80290990 00006012 */  mflo  $t4
/* 0F9FA4 80290994 318400FF */  andi  $a0, $t4, 0xff
/* 0F9FA8 80290998 0C032418 */  jal   func_800C9060
/* 0F9FAC 8029099C 34A58001 */   ori   $a1, (0x19008001 & 0xFFFF) # ori $a1, $a1, 0x8001
/* 0F9FB0 802909A0 10000010 */  b     .L802909E4
/* 0F9FB4 802909A4 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F9FB8 802909A8 94D80000 */  lhu   $t8, ($a2)
.L802909AC:
/* 0F9FBC 802909AC 3C0E800E */  lui   $t6, %hi(gPlayerOne) # $t6, 0x800e
/* 0F9FC0 802909B0 330F4000 */  andi  $t7, $t8, 0x4000
/* 0F9FC4 802909B4 51E0000B */  beql  $t7, $zero, .L802909E4
/* 0F9FC8 802909B8 8FBF0014 */   lw    $ra, 0x14($sp)
/* 0F9FCC 802909BC 8DCEC4DC */  lw    $t6, %lo(gPlayerOne)($t6)
/* 0F9FD0 802909C0 24010DD8 */  li    $at, 3544
/* 0F9FD4 802909C4 3C051900 */  lui   $a1, (0x19008001 >> 16) # lui $a1, 0x1900
/* 0F9FD8 802909C8 00CE2023 */  subu  $a0, $a2, $t6
/* 0F9FDC 802909CC 0081001A */  div   $zero, $a0, $at
/* 0F9FE0 802909D0 0000C812 */  mflo  $t9
/* 0F9FE4 802909D4 332400FF */  andi  $a0, $t9, 0xff
/* 0F9FE8 802909D8 0C032418 */  jal   func_800C9060
/* 0F9FEC 802909DC 34A58001 */   ori   $a1, (0x19008001 & 0xFFFF) # ori $a1, $a1, 0x8001
.L802909E0:
/* 0F9FF0 802909E0 8FBF0014 */  lw    $ra, 0x14($sp)
.L802909E4:
/* 0F9FF4 802909E4 27BD0078 */  addiu $sp, $sp, 0x78
/* 0F9FF8 802909E8 03E00008 */  jr    $ra
/* 0F9FFC 802909EC 00000000 */   nop
