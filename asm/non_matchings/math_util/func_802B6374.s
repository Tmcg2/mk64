glabel func_802B6374
/* 11F984 802B6374 C48C0000 */  lwc1  $f12, ($a0)
/* 11F988 802B6378 C48E0004 */  lwc1  $f14, 4($a0)
/* 11F98C 802B637C C4820008 */  lwc1  $f2, 8($a0)
/* 11F990 802B6380 460C6102 */  mul.s $f4, $f12, $f12
/* 11F994 802B6384 00000000 */  nop   
/* 11F998 802B6388 460E7182 */  mul.s $f6, $f14, $f14
/* 11F99C 802B638C 46062200 */  add.s $f8, $f4, $f6
/* 11F9A0 802B6390 46021282 */  mul.s $f10, $f2, $f2
/* 11F9A4 802B6394 46085000 */  add.s $f0, $f10, $f8
/* 11F9A8 802B6398 46000004 */  sqrt.s $f0, $f0
/* 11F9AC 802B639C 46006403 */  div.s $f16, $f12, $f0
/* 11F9B0 802B63A0 46007483 */  div.s $f18, $f14, $f0
/* 11F9B4 802B63A4 E4900000 */  swc1  $f16, ($a0)
/* 11F9B8 802B63A8 46001103 */  div.s $f4, $f2, $f0
/* 11F9BC 802B63AC E4920004 */  swc1  $f18, 4($a0)
/* 11F9C0 802B63B0 03E00008 */  jr    $ra
/* 11F9C4 802B63B4 E4840008 */   swc1  $f4, 8($a0)
