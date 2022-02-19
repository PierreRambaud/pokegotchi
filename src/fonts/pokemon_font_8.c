/*******************************************************************************
 * Size: 8 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef POKEMON_FONT_8
#define POKEMON_FONT_8 1
#endif

#if POKEMON_FONT_8

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x6f, 0xff, 0x60, 0x66,

    /* U+0022 "\"" */
    0xb6, 0x80,

    /* U+0023 "#" */
    0x4d, 0xfd, 0x32, 0x6f, 0xe9, 0x80,

    /* U+0024 "$" */
    0x23, 0xe8, 0xe2, 0xd5, 0xc4,

    /* U+0025 "%" */
    0x43, 0x49, 0x20, 0x82, 0x49, 0x61, 0x0,

    /* U+0026 "&" */
    0x30, 0xd1, 0xa1, 0x95, 0xb9, 0x9e, 0x80,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x34, 0x88, 0x84, 0x30,

    /* U+0029 ")" */
    0xc2, 0x11, 0x12, 0xc0,

    /* U+002A "*" */
    0x25, 0x5c, 0xea, 0x90,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002C "," */
    0xf6,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x2, 0x8, 0x20, 0x82, 0x8, 0x20, 0x0,

    /* U+0030 "0" */
    0x38, 0x9b, 0x1e, 0x36, 0x47, 0x0,

    /* U+0031 "1" */
    0x31, 0xc3, 0xc, 0x33, 0xf0,

    /* U+0032 "2" */
    0x7d, 0x8c, 0x3b, 0xce, 0x1f, 0xc0,

    /* U+0033 "3" */
    0x7e, 0x18, 0xe0, 0x3c, 0x6f, 0x80,

    /* U+0034 "4" */
    0x1c, 0x79, 0xb6, 0x6f, 0xe1, 0x80,

    /* U+0035 "5" */
    0xfd, 0x83, 0xf0, 0x3c, 0x6f, 0x80,

    /* U+0036 "6" */
    0x7d, 0x83, 0xf6, 0x3c, 0x6f, 0x80,

    /* U+0037 "7" */
    0xff, 0x8c, 0x30, 0xc3, 0x6, 0x0,

    /* U+0038 "8" */
    0x7d, 0x8d, 0xf6, 0x3c, 0x6f, 0x80,

    /* U+0039 "9" */
    0x7d, 0x8f, 0x1b, 0xf0, 0x6f, 0x80,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+003B ";" */
    0xf3, 0xd8,

    /* U+003C "<" */
    0x19, 0x99, 0x86, 0x18, 0x60,

    /* U+003D "=" */
    0xf8, 0x1, 0xf0,

    /* U+003E ">" */
    0xc3, 0xc, 0x33, 0x33, 0x0,

    /* U+003F "?" */
    0x7e, 0xe7, 0xce, 0x18, 0x0, 0x18, 0x18,

    /* U+0040 "@" */
    0x38, 0x8a, 0xec, 0xca, 0x97, 0xd0, 0x9e,

    /* U+0041 "A" */
    0x10, 0x50, 0xa2, 0x27, 0xd0, 0x60, 0x80,

    /* U+0042 "B" */
    0xf9, 0xa, 0x17, 0xe8, 0x30, 0x7f, 0x0,

    /* U+0043 "C" */
    0x3c, 0x86, 0x4, 0x8, 0x8, 0x4f, 0x0,

    /* U+0044 "D" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x0,

    /* U+0045 "E" */
    0xff, 0x2, 0x7, 0xe8, 0x10, 0x3f, 0x80,

    /* U+0046 "F" */
    0xff, 0x2, 0x7, 0xe8, 0x10, 0x20, 0x0,

    /* U+0047 "G" */
    0x3c, 0x86, 0x4, 0xf8, 0x28, 0x4f, 0x0,

    /* U+0048 "H" */
    0x83, 0x6, 0xf, 0xf8, 0x30, 0x60, 0x80,

    /* U+0049 "I" */
    0xf9, 0x8, 0x42, 0x13, 0xe0,

    /* U+004A "J" */
    0x7e, 0x10, 0x20, 0x48, 0x91, 0x1c, 0x0,

    /* U+004B "K" */
    0x85, 0x12, 0x45, 0x8c, 0x90, 0xa0, 0x80,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x3f, 0x80,

    /* U+004D "M" */
    0x83, 0x8e, 0xac, 0x98, 0x30, 0x60, 0x80,

    /* U+004E "N" */
    0x83, 0x86, 0x8c, 0x98, 0xb0, 0xe0, 0x80,

    /* U+004F "O" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0x8e, 0x0,

    /* U+0050 "P" */
    0xfd, 0x6, 0xf, 0xe8, 0x10, 0x20, 0x0,

    /* U+0051 "Q" */
    0x38, 0x8a, 0xc, 0x18, 0xa8, 0x8e, 0x80,

    /* U+0052 "R" */
    0xfd, 0x6, 0xf, 0xe8, 0x90, 0xa0, 0x80,

    /* U+0053 "S" */
    0x79, 0xa, 0x3, 0xe0, 0x30, 0x5f, 0x0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x0,

    /* U+0055 "U" */
    0x83, 0x6, 0xc, 0x18, 0x28, 0x4f, 0x80,

    /* U+0056 "V" */
    0x83, 0x5, 0x12, 0x22, 0x85, 0x4, 0x0,

    /* U+0057 "W" */
    0x83, 0x26, 0xad, 0x5c, 0x78, 0xe0, 0x80,

    /* U+0058 "X" */
    0xc6, 0x88, 0xa0, 0x82, 0x88, 0xb1, 0x80,

    /* U+0059 "Y" */
    0x82, 0x88, 0xa0, 0x81, 0x2, 0x4, 0x0,

    /* U+005A "Z" */
    0xfe, 0x8, 0x20, 0x82, 0x8, 0x3f, 0x80,

    /* U+005B "[" */
    0xf2, 0x49, 0x38,

    /* U+005C "\\" */
    0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,

    /* U+005D "]" */
    0xe4, 0x92, 0x78,

    /* U+005E "^" */
    0x22, 0xa2,

    /* U+005F "_" */
    0xfe,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0x70, 0x27, 0xa2, 0x7c,

    /* U+0062 "b" */
    0x82, 0x8, 0x3e, 0x86, 0x1f, 0x80,

    /* U+0063 "c" */
    0x7a, 0x18, 0x21, 0x78,

    /* U+0064 "d" */
    0x4, 0x10, 0x5f, 0x86, 0x17, 0xc0,

    /* U+0065 "e" */
    0x7a, 0x1f, 0xe0, 0x7c,

    /* U+0066 "f" */
    0x18, 0x92, 0x3f, 0x20, 0x82, 0x0,

    /* U+0067 "g" */
    0x7e, 0x18, 0x5f, 0x7, 0xe0,

    /* U+0068 "h" */
    0x84, 0x21, 0xe8, 0xc6, 0x20,

    /* U+0069 "i" */
    0xbc,

    /* U+006A "j" */
    0x20, 0x92, 0x70,

    /* U+006B "k" */
    0x82, 0x8, 0xec, 0xc2, 0xc8, 0xc0,

    /* U+006C "l" */
    0xfe,

    /* U+006D "m" */
    0xed, 0x26, 0x4c, 0x99, 0x20,

    /* U+006E "n" */
    0xf4, 0x63, 0x18, 0x80,

    /* U+006F "o" */
    0x7a, 0x18, 0x61, 0x78,

    /* U+0070 "p" */
    0xfa, 0x18, 0x7e, 0x82, 0x0,

    /* U+0071 "q" */
    0x7e, 0x18, 0x5f, 0x4, 0x10,

    /* U+0072 "r" */
    0x9e, 0x8c, 0x20, 0x80,

    /* U+0073 "s" */
    0x7a, 0x7, 0x81, 0xf8,

    /* U+0074 "t" */
    0x27, 0xc8, 0x42, 0xc,

    /* U+0075 "u" */
    0x8c, 0x63, 0x17, 0x80,

    /* U+0076 "v" */
    0x8c, 0x62, 0xa2, 0x0,

    /* U+0077 "w" */
    0x83, 0x26, 0x4d, 0x54, 0x40,

    /* U+0078 "x" */
    0xc4, 0x50, 0x41, 0x44, 0x60,

    /* U+0079 "y" */
    0x8c, 0x62, 0xf0, 0xf8,

    /* U+007A "z" */
    0xfc, 0x23, 0x10, 0xfc,

    /* U+007B "{" */
    0x29, 0x28, 0x92, 0x20,

    /* U+007C "|" */
    0xff, 0xe0,

    /* U+007D "}" */
    0x89, 0x22, 0x92, 0x80,

    /* U+007E "~" */
    0x66, 0x60,

    /* U+00A1 "¡" */
    0x66, 0x6, 0xff, 0xf6,

    /* U+00A2 "¢" */
    0x23, 0xe9, 0x4a, 0x3c, 0x80,

    /* U+00A3 "£" */
    0x39, 0x14, 0x10, 0xf1, 0x4, 0x3f,

    /* U+00A4 "¤" */
    0x85, 0xe4, 0x92, 0x7a, 0x10,

    /* U+00A5 "¥" */
    0x7a, 0x5e, 0x8e, 0x23, 0x88,

    /* U+00A6 "¦" */
    0xf1, 0xe0,

    /* U+00A7 "§" */
    0x76, 0x72, 0xcb, 0x45, 0xa6, 0x9c, 0xdc,

    /* U+00A8 "¨" */
    0xa0,

    /* U+00A9 "©" */
    0x38, 0x8a, 0xed, 0x1a, 0x37, 0x51, 0x1c,

    /* U+00AB "«" */
    0x12, 0x6d, 0xb7, 0xe6, 0xc6, 0xc4, 0x80,

    /* U+00AC "¬" */
    0xf8, 0x42,

    /* U+00AE "®" */
    0x38, 0x8a, 0xed, 0x5b, 0x35, 0x51, 0x1c,

    /* U+00AF "¯" */
    0xf8,

    /* U+00B0 "°" */
    0x69, 0x96,

    /* U+00B1 "±" */
    0x27, 0xc8, 0xf, 0x80,

    /* U+00B4 "´" */
    0x60,

    /* U+00B6 "¶" */
    0x6f, 0x7a, 0xd2, 0x94, 0xa5,

    /* U+00B7 "·" */
    0xf0,

    /* U+00B8 "¸" */
    0x70,

    /* U+00BA "º" */
    0x7a, 0x18, 0x61, 0x78,

    /* U+00BB "»" */
    0x91, 0xb1, 0xb3, 0xf6, 0xdb, 0x24, 0x0,

    /* U+00BF "¿" */
    0x18, 0x18, 0x0, 0x18, 0x63, 0xe6, 0x7e,

    /* U+00C0 "À" */
    0x10, 0x10, 0x41, 0x44, 0x5f, 0xe0, 0x80,

    /* U+00C1 "Á" */
    0x10, 0x40, 0x41, 0x44, 0x5f, 0xe0, 0x80,

    /* U+00C2 "Â" */
    0x10, 0x50, 0x41, 0x44, 0x5f, 0xe0, 0x80,

    /* U+00C3 "Ã" */
    0x65, 0x30, 0x41, 0x44, 0x5f, 0xe0, 0x80,

    /* U+00C4 "Ä" */
    0x28, 0x20, 0xa2, 0x27, 0xd0, 0x60, 0x80,

    /* U+00C5 "Å" */
    0x10, 0x50, 0x41, 0x44, 0x5f, 0xe0, 0x80,

    /* U+00C6 "Æ" */
    0x1e, 0x50, 0xa2, 0x67, 0x91, 0x23, 0x80,

    /* U+00C7 "Ç" */
    0x3c, 0x86, 0x4, 0x4, 0x27, 0x84, 0x18,

    /* U+00C8 "È" */
    0x20, 0x23, 0xfc, 0xf, 0xd0, 0x3f, 0x80,

    /* U+00C9 "É" */
    0x8, 0x23, 0xfc, 0xf, 0xd0, 0x3f, 0x80,

    /* U+00CA "Ê" */
    0x10, 0x53, 0xfc, 0xf, 0xd0, 0x3f, 0x80,

    /* U+00CB "Ë" */
    0x28, 0x3, 0xfc, 0xf, 0xd0, 0x3f, 0x80,

    /* U+00CC "Ì" */
    0x41, 0x3e, 0x42, 0x13, 0xe0,

    /* U+00CD "Í" */
    0x11, 0x3e, 0x42, 0x13, 0xe0,

    /* U+00CE "Î" */
    0x22, 0xbe, 0x42, 0x13, 0xe0,

    /* U+00CF "Ï" */
    0x50, 0x3e, 0x42, 0x13, 0xe0,

    /* U+00D0 "Ð" */
    0xf9, 0xa, 0xf, 0x98, 0x30, 0xbe, 0x0,

    /* U+00D1 "Ñ" */
    0x32, 0x9b, 0xd, 0x19, 0x31, 0x61, 0x80,

    /* U+00D2 "Ò" */
    0x10, 0x11, 0xf4, 0x18, 0x30, 0x5f, 0x0,

    /* U+00D3 "Ó" */
    0x10, 0x41, 0xf4, 0x18, 0x30, 0x5f, 0x0,

    /* U+00D4 "Ô" */
    0x10, 0x51, 0xf4, 0x18, 0x30, 0x5f, 0x0,

    /* U+00D5 "Õ" */
    0x65, 0x31, 0xf4, 0x18, 0x30, 0x5f, 0x0,

    /* U+00D6 "Ö" */
    0x28, 0x71, 0x14, 0x18, 0x28, 0x8e, 0x0,

    /* U+00D7 "×" */
    0x8a, 0x88, 0xa8, 0x80,

    /* U+00D8 "Ø" */
    0x3a, 0x8a, 0x2c, 0x9a, 0x28, 0xae, 0x0,

    /* U+00D9 "Ù" */
    0x20, 0x22, 0xc, 0x18, 0x28, 0x4f, 0x80,

    /* U+00DA "Ú" */
    0x10, 0x42, 0xc, 0x18, 0x28, 0x4f, 0x80,

    /* U+00DB "Û" */
    0x10, 0x52, 0xc, 0x18, 0x28, 0x4f, 0x80,

    /* U+00DC "Ü" */
    0x28, 0x2, 0xc, 0x18, 0x28, 0x4f, 0x80,

    /* U+00DD "Ý" */
    0x9, 0x25, 0x11, 0x41, 0x2, 0x4, 0x0,

    /* U+00DE "Þ" */
    0x81, 0xfa, 0xc, 0x1f, 0xd0, 0x20, 0x0,

    /* U+00DF "ß" */
    0xf2, 0x28, 0xae, 0x86, 0x99, 0x80,

    /* U+00E0 "à" */
    0x40, 0x87, 0x2, 0x7a, 0x27, 0xc0,

    /* U+00E1 "á" */
    0x10, 0x87, 0x2, 0x7a, 0x27, 0xc0,

    /* U+00E2 "â" */
    0x21, 0x47, 0x2, 0x7a, 0x27, 0xc0,

    /* U+00E3 "ã" */
    0x66, 0x67, 0x2, 0x7a, 0x27, 0xc0,

    /* U+00E4 "ä" */
    0x50, 0x7, 0x2, 0x7a, 0x27, 0xc0,

    /* U+00E5 "å" */
    0x21, 0x47, 0x2, 0x7a, 0x27, 0xc0,

    /* U+00E6 "æ" */
    0x68, 0x57, 0xe4, 0x7c,

    /* U+00E7 "ç" */
    0x7a, 0x18, 0x1e, 0x10, 0xc0,

    /* U+00E8 "è" */
    0x20, 0x47, 0xa1, 0xfe, 0x7, 0xc0,

    /* U+00E9 "é" */
    0x31, 0x80, 0xf2, 0x17, 0xe8, 0xf, 0x80,

    /* U+00EA "ê" */
    0x21, 0x47, 0xa1, 0xfe, 0x7, 0xc0,

    /* U+00EB "ë" */
    0x50, 0x7, 0xa1, 0xfe, 0x7, 0xc0,

    /* U+00EC "ì" */
    0x91, 0x54,

    /* U+00ED "í" */
    0x62, 0xa8,

    /* U+00EE "î" */
    0x54, 0x24, 0x90,

    /* U+00EF "ï" */
    0xa1, 0x24, 0x80,

    /* U+00F0 "ð" */
    0x8, 0x70, 0x9e, 0x8a, 0x27, 0x0,

    /* U+00F1 "ñ" */
    0x66, 0x6f, 0x22, 0x8a, 0x28, 0x80,

    /* U+00F2 "ò" */
    0x40, 0x87, 0xa1, 0x86, 0x17, 0x80,

    /* U+00F3 "ó" */
    0x10, 0x87, 0xa1, 0x86, 0x17, 0x80,

    /* U+00F4 "ô" */
    0x21, 0x47, 0xa1, 0x86, 0x17, 0x80,

    /* U+00F5 "õ" */
    0x66, 0x67, 0xa1, 0x86, 0x17, 0x80,

    /* U+00F6 "ö" */
    0x50, 0x7, 0xa1, 0x86, 0x17, 0x80,

    /* U+00F7 "÷" */
    0x20, 0x3e, 0x2, 0x0,

    /* U+00F8 "ø" */
    0x2, 0xfa, 0x34, 0xaa, 0x4f, 0x20, 0x0,

    /* U+00F9 "ù" */
    0x41, 0x23, 0x18, 0xc5, 0xe0,

    /* U+00FA "ú" */
    0x11, 0x23, 0x18, 0xc5, 0xe0,

    /* U+00FB "û" */
    0x22, 0xa3, 0x18, 0xc5, 0xe0,

    /* U+00FC "ü" */
    0x50, 0x23, 0x18, 0xc5, 0xe0,

    /* U+00FD "ý" */
    0x11, 0x23, 0x18, 0xbc, 0x3e,

    /* U+00FE "þ" */
    0x82, 0xf, 0xa1, 0x87, 0xe8, 0x20,

    /* U+00FF "ÿ" */
    0x50, 0x23, 0x18, 0xbc, 0x3e,

    /* U+3041 "ぁ" */
    0x21, 0xe2, 0x1e, 0x95, 0x90,

    /* U+3042 "あ" */
    0x21, 0xf8, 0x81, 0xe6, 0x75, 0x64, 0xb2,

    /* U+3043 "ぃ" */
    0x94, 0x62, 0x80,

    /* U+3044 "い" */
    0x85, 0x6, 0xc, 0x18, 0x2a, 0x8, 0x0,

    /* U+3045 "ぅ" */
    0x60, 0x69, 0x16,

    /* U+3046 "う" */
    0xf0, 0x1d, 0x10, 0x84, 0x4c,

    /* U+3047 "ぇ" */
    0x60, 0xf2, 0x69,

    /* U+3048 "え" */
    0x30, 0x1, 0xf0, 0x41, 0x7, 0x12, 0x43,

    /* U+3049 "ぉ" */
    0x21, 0xd2, 0x1c, 0xa9, 0xa0,

    /* U+304A "お" */
    0x23, 0xf4, 0x81, 0xe6, 0x34, 0x68, 0xb2,

    /* U+304B "か" */
    0x40, 0x8b, 0xca, 0x54, 0x91, 0x2, 0x18,

    /* U+304C "が" */
    0x4, 0x24, 0x22, 0x4, 0x5e, 0x52, 0xa4, 0x88,
    0x10, 0xc0,

    /* U+304D "き" */
    0x11, 0xfc, 0x27, 0xf0, 0x51, 0xa0, 0x3e,

    /* U+304E "ぎ" */
    0x4, 0x24, 0x20, 0x8f, 0xe1, 0x3f, 0x82, 0x8d,
    0x1, 0xf0,

    /* U+304F "く" */
    0x12, 0x48, 0x84, 0x21,

    /* U+3050 "ぐ" */
    0x10, 0x41, 0x14, 0x98, 0x88, 0x8, 0x8,

    /* U+3051 "け" */
    0x5, 0xa, 0x7c, 0x28, 0x50, 0xa1, 0x4,

    /* U+3052 "げ" */
    0x4, 0x24, 0x20, 0x28, 0x53, 0xe1, 0x42, 0x85,
    0x8, 0x20,

    /* U+3053 "こ" */
    0x7c, 0x4, 0x0, 0x0, 0x10, 0x1f, 0x80,

    /* U+3054 "ご" */
    0x4, 0x24, 0x20, 0x7, 0xc0, 0x40, 0x0, 0x1,
    0x1, 0xf8,

    /* U+3055 "さ" */
    0x20, 0x23, 0xf8, 0x47, 0xd0, 0x20, 0x3e,

    /* U+3056 "ざ" */
    0x4, 0x24, 0x21, 0x1, 0x1f, 0xc2, 0x3e, 0x81,
    0x1, 0xf0,

    /* U+3057 "し" */
    0x84, 0x21, 0x8, 0x46, 0x2e,

    /* U+3058 "じ" */
    0x8a, 0x99, 0x20, 0x82, 0x28, 0x9c,

    /* U+3059 "す" */
    0x5, 0xfc, 0x11, 0xe4, 0x47, 0x81, 0xc,

    /* U+305A "ず" */
    0x4, 0x24, 0x20, 0x2f, 0xe0, 0x8f, 0x22, 0x3c,
    0x8, 0x60,

    /* U+305B "せ" */
    0x44, 0x8b, 0xfa, 0x24, 0x49, 0x10, 0x1e,

    /* U+305C "ぜ" */
    0x4, 0x24, 0x22, 0x24, 0x5f, 0xd1, 0x22, 0x48,
    0x80, 0xf0,

    /* U+305D "そ" */
    0x7c, 0x20, 0x87, 0xf1, 0x4, 0x8, 0xe,

    /* U+305E "ぞ" */
    0x4, 0x24, 0x23, 0xe1, 0x4, 0x3f, 0x88, 0x20,
    0x40, 0x70,

    /* U+305F "た" */
    0x20, 0x43, 0xf2, 0x5, 0xe8, 0x24, 0x47,

    /* U+3060 "だ" */
    0x4, 0x24, 0x21, 0x2, 0x1f, 0x90, 0x2f, 0x41,
    0x22, 0x38,

    /* U+3061 "ち" */
    0x20, 0x43, 0xf2, 0x7, 0xc8, 0x40, 0x8e,

    /* U+3062 "ぢ" */
    0x4, 0x24, 0x21, 0x2, 0x1f, 0x90, 0x3e, 0x42,
    0x4, 0x70,

    /* U+3063 "っ" */
    0xf0, 0x42, 0x26, 0x0,

    /* U+3064 "つ" */
    0xf8, 0x10, 0x41, 0x9, 0xc0,

    /* U+3065 "づ" */
    0x8, 0x91, 0x0, 0x3, 0xe0, 0x41, 0x4, 0x27,
    0x0,

    /* U+3066 "て" */
    0xfe, 0x18, 0x41, 0x2, 0x2, 0x3, 0x0,

    /* U+3067 "で" */
    0x4, 0x24, 0x20, 0xf, 0xe1, 0x84, 0x10, 0x20,
    0x20, 0x30,

    /* U+3068 "と" */
    0x20, 0x40, 0xb1, 0x84, 0x10, 0x20, 0x3f,

    /* U+3069 "ど" */
    0x4, 0x24, 0x21, 0x2, 0x5, 0x8c, 0x20, 0x81,
    0x1, 0xf8,

    /* U+306A "な" */
    0x20, 0x4b, 0xca, 0x8, 0x47, 0x91, 0x9c,

    /* U+306B "に" */
    0x9f, 0x2, 0x4, 0xa, 0x14, 0x27, 0x80,

    /* U+306C "ぬ" */
    0x8, 0x91, 0x73, 0x5d, 0x34, 0xea, 0xa7,

    /* U+306D "ね" */
    0x20, 0x43, 0xb1, 0x92, 0x2c, 0xea, 0x97,

    /* U+306E "の" */
    0x38, 0xaa, 0x4c, 0x99, 0x32, 0x59, 0x0,

    /* U+306F "は" */
    0x5, 0x3e, 0x14, 0x29, 0xd4, 0xe9, 0x4c,

    /* U+3070 "ば" */
    0x4, 0x24, 0x20, 0x29, 0xf0, 0xa1, 0x4e, 0xa7,
    0x4a, 0x60,

    /* U+3071 "ぱ" */
    0xe, 0x14, 0x38, 0x29, 0xf0, 0xa1, 0x4e, 0xa7,
    0x4a, 0x60,

    /* U+3072 "ひ" */
    0xf0, 0x49, 0x1a, 0x28, 0xd1, 0x1c, 0x0,

    /* U+3073 "び" */
    0x4, 0x24, 0x20, 0xf, 0x4, 0x91, 0xa2, 0x8d,
    0x11, 0xc0,

    /* U+3074 "ぴ" */
    0xe, 0x14, 0x38, 0xf, 0x4, 0x91, 0xa2, 0x8d,
    0x11, 0xc0,

    /* U+3075 "ふ" */
    0x38, 0x10, 0x42, 0x48, 0xb1, 0x4c, 0x0,

    /* U+3076 "ぶ" */
    0x4, 0x24, 0x20, 0x3, 0x81, 0x4, 0x24, 0x8b,
    0x14, 0xc0,

    /* U+3077 "ぷ" */
    0xe, 0x14, 0x38, 0x3, 0x81, 0x4, 0x24, 0x8b,
    0x14, 0xc0,

    /* U+3078 "へ" */
    0x20, 0xa2, 0x20, 0x20, 0x20,

    /* U+3079 "べ" */
    0x4, 0x24, 0x20, 0x0, 0x4, 0x14, 0x44, 0x4,
    0x4,

    /* U+307A "ぺ" */
    0xe, 0x14, 0x38, 0x0, 0x4, 0x14, 0x44, 0x4,
    0x4,

    /* U+307B "ほ" */
    0x1f, 0xa, 0x7c, 0x29, 0xd4, 0xe9, 0x4c,

    /* U+307C "ぼ" */
    0x4, 0x24, 0x20, 0xf8, 0x53, 0xe1, 0x4e, 0xa7,
    0x4a, 0x60,

    /* U+307D "ぽ" */
    0xe, 0x14, 0x38, 0xf8, 0x53, 0xe1, 0x4e, 0xa7,
    0x4a, 0x60,

    /* U+307E "ま" */
    0x9, 0xf0, 0x9f, 0x9, 0xe8, 0xde,

    /* U+307F "み" */
    0x70, 0x20, 0x53, 0xf9, 0x54, 0xa9, 0x24,

    /* U+3080 "む" */
    0x21, 0xe4, 0x8b, 0xa, 0x14, 0x58, 0x9e,

    /* U+3081 "め" */
    0x8, 0x91, 0x63, 0x6a, 0xb2, 0x6c, 0xa2,

    /* U+3082 "も" */
    0x20, 0x43, 0xe1, 0xf, 0x84, 0x8, 0x8e,

    /* U+3083 "ゃ" */
    0x51, 0xed, 0x51, 0x28, 0x80,

    /* U+3084 "や" */
    0x48, 0x93, 0xf2, 0x15, 0x29, 0x88, 0x10,

    /* U+3085 "ゅ" */
    0x12, 0xed, 0x65, 0x38, 0x40,

    /* U+3086 "ゆ" */
    0x9, 0x7b, 0x2c, 0x58, 0xb5, 0x47, 0x10,

    /* U+3087 "ょ" */
    0x10, 0xc4, 0xe9, 0xb8,

    /* U+3088 "よ" */
    0x8, 0x10, 0x38, 0x40, 0x9f, 0xa2, 0xb8,

    /* U+3089 "ら" */
    0x60, 0x68, 0x2e, 0xc4, 0x10, 0x5e,

    /* U+308A "り" */
    0x8c, 0x63, 0x18, 0x84, 0x4c,

    /* U+308B "る" */
    0x7c, 0x10, 0xc3, 0xe8, 0x26, 0x52, 0x9e,

    /* U+308C "れ" */
    0x20, 0x43, 0xb1, 0x92, 0x2c, 0xa9, 0x11,

    /* U+308D "ろ" */
    0x7c, 0x10, 0xc3, 0xe8, 0x20, 0x40, 0x9e,

    /* U+308E "ゎ" */
    0x47, 0x93, 0x95, 0x0,

    /* U+308F "わ" */
    0x20, 0x43, 0xb5, 0x92, 0x2c, 0x68, 0x92,

    /* U+3090 "ゐ" */
    0xe0, 0x71, 0x95, 0x1a, 0x75, 0x53, 0x80,

    /* U+3091 "ゑ" */
    0x7c, 0x31, 0xf4, 0x13, 0x27, 0x9b, 0x49,

    /* U+3092 "を" */
    0x27, 0x90, 0xdb, 0x29, 0x7,

    /* U+3093 "ん" */
    0x10, 0x20, 0x81, 0x7, 0x9, 0x22, 0x43,

    /* U+3094 "ゔ" */
    0x8, 0x91, 0x3c, 0x1, 0xc8, 0x82, 0x8, 0x46,
    0x0,

    /* U+3095 "ゕ" */
    0x4b, 0x95, 0x24, 0x20,

    /* U+3096 "ゖ" */
    0x95, 0xe5, 0x2a, 0x0,

    /* U+3099 "゙" */
    0x29, 0x40,

    /* U+309A "゚" */
    0xf7, 0x80,

    /* U+309B "゛" */
    0x29, 0x40,

    /* U+309C "゜" */
    0xf7, 0x80,

    /* U+309D "ゝ" */
    0x88, 0x94,

    /* U+309E "ゞ" */
    0x12, 0x49, 0x4, 0x10, 0x88,

    /* U+309F "ゟ" */
    0x20, 0x40, 0xf9, 0x7, 0xc8, 0x50, 0xce,

    /* U+30A0 "゠" */
    0xf0, 0xf0,

    /* U+30A1 "ァ" */
    0xf8, 0x4a, 0x64, 0x0,

    /* U+30A2 "ア" */
    0xfe, 0x4, 0x48, 0xe1, 0x2, 0x18, 0x0,

    /* U+30A3 "ィ" */
    0x12, 0xe2, 0x20,

    /* U+30A4 "イ" */
    0x4, 0x10, 0x8c, 0xd0, 0x41, 0x4,

    /* U+30A5 "ゥ" */
    0x27, 0xe2, 0x26, 0x0,

    /* U+30A6 "ウ" */
    0x10, 0x23, 0xfc, 0x18, 0x20, 0x41, 0xc,

    /* U+30A7 "ェ" */
    0x71, 0x9, 0xf0,

    /* U+30A8 "エ" */
    0x7c, 0x20, 0x40, 0x81, 0x2, 0x3f, 0x80,

    /* U+30A9 "ォ" */
    0x17, 0xcc, 0xa9, 0x0,

    /* U+30AA "オ" */
    0x8, 0x13, 0xf8, 0xc2, 0x89, 0x22, 0xc,

    /* U+30AB "カ" */
    0x20, 0x41, 0xf9, 0x12, 0x24, 0x50, 0xc6,

    /* U+30AC "ガ" */
    0x4, 0x24, 0x21, 0x2, 0xf, 0xc8, 0x91, 0x22,
    0x86, 0x30,

    /* U+30AD "キ" */
    0x11, 0xfc, 0x40, 0x8f, 0xe2, 0x4, 0x8,

    /* U+30AE "ギ" */
    0x4, 0x24, 0x20, 0x8f, 0xe2, 0x4, 0x7f, 0x10,
    0x20, 0x40,

    /* U+30AF "ク" */
    0x7d, 0x18, 0x41, 0x4, 0x27, 0x0,

    /* U+30B0 "グ" */
    0x4, 0x24, 0x20, 0x7, 0xc8, 0xa1, 0x2, 0x4,
    0x11, 0xc0,

    /* U+30B1 "ケ" */
    0x40, 0x81, 0xfa, 0x28, 0x40, 0x82, 0x18,

    /* U+30B2 "ゲ" */
    0x4, 0x24, 0x22, 0x4, 0xf, 0xd1, 0x42, 0x4,
    0x10, 0xc0,

    /* U+30B3 "コ" */
    0xfc, 0x10, 0x41, 0x4, 0x1f, 0xc0,

    /* U+30B4 "ゴ" */
    0x4, 0x24, 0x20, 0xf, 0xc0, 0x81, 0x2, 0x4,
    0xb, 0xf0,

    /* U+30B5 "サ" */
    0x44, 0x8b, 0xfa, 0x24, 0x40, 0x81, 0x1c,

    /* U+30B6 "ザ" */
    0x4, 0x24, 0x22, 0x24, 0x5f, 0xd1, 0x22, 0x4,
    0x8, 0xe0,

    /* U+30B7 "シ" */
    0xe0, 0x1e, 0x41, 0x4, 0x2f, 0x0,

    /* U+30B8 "ジ" */
    0x8, 0x91, 0x0, 0xe0, 0x1e, 0x41, 0x4, 0x2f,
    0x0,

    /* U+30B9 "ス" */
    0xfc, 0x8, 0x10, 0x41, 0x84, 0xb0, 0x80,

    /* U+30BA "ズ" */
    0x4, 0x24, 0x20, 0xf, 0xc0, 0x81, 0x4, 0x18,
    0x4b, 0x8,

    /* U+30BB "セ" */
    0x40, 0x83, 0xfa, 0x14, 0x48, 0x10, 0x1e,

    /* U+30BC "ゼ" */
    0x4, 0x24, 0x22, 0x4, 0x1f, 0xd0, 0xa2, 0x40,
    0x80, 0xf0,

    /* U+30BD "ソ" */
    0x83, 0x5, 0x8, 0x20, 0x41, 0xc, 0x0,

    /* U+30BE "ゾ" */
    0x4, 0x24, 0x20, 0x8, 0x30, 0x50, 0x82, 0x4,
    0x10, 0xc0,

    /* U+30BF "タ" */
    0x7e, 0x85, 0xcc, 0x70, 0x20, 0x8e, 0x0,

    /* U+30C0 "ダ" */
    0x4, 0x24, 0x20, 0x7, 0xe8, 0x5c, 0xc7, 0x2,
    0x8, 0xe0,

    /* U+30C1 "チ" */
    0x6, 0xf0, 0x27, 0xf0, 0x81, 0x4, 0x30,

    /* U+30C2 "ヂ" */
    0x4, 0x24, 0x20, 0x37, 0x81, 0x3f, 0x84, 0x8,
    0x21, 0x80,

    /* U+30C3 "ッ" */
    0xad, 0x42, 0x26, 0x0,

    /* U+30C4 "ツ" */
    0xa6, 0x9a, 0x41, 0x4, 0x27, 0x0,

    /* U+30C5 "ヅ" */
    0x8, 0x91, 0x0, 0xa6, 0x9a, 0x41, 0x4, 0x27,
    0x0,

    /* U+30C6 "テ" */
    0x7c, 0x3, 0xf8, 0x40, 0x81, 0xc, 0x0,

    /* U+30C7 "デ" */
    0x4, 0x24, 0x20, 0x7, 0xc0, 0x3f, 0x84, 0x8,
    0x10, 0xc0,

    /* U+30C8 "ト" */
    0x84, 0x21, 0xe8, 0xc2, 0x10,

    /* U+30C9 "ド" */
    0x12, 0x49, 0x8, 0x43, 0xd1, 0x84, 0x20,

    /* U+30CA "ナ" */
    0x8, 0x13, 0xf8, 0x40, 0x81, 0x4, 0x30,

    /* U+30CB "ニ" */
    0x7c, 0x0, 0x0, 0x0, 0x0, 0x3f, 0x80,

    /* U+30CC "ヌ" */
    0xfe, 0x4, 0x8, 0xa0, 0x82, 0x98, 0x80,

    /* U+30CD "ネ" */
    0x10, 0x23, 0xf8, 0x21, 0x86, 0xb4, 0x88,

    /* U+30CE "ノ" */
    0x4, 0x10, 0x42, 0x8, 0xcc, 0x0,

    /* U+30CF "ハ" */
    0x48, 0x89, 0x12, 0x18, 0x30, 0x40,

    /* U+30D0 "バ" */
    0x4, 0x24, 0x20, 0x0, 0x9, 0x11, 0x22, 0x43,
    0x6, 0x8,

    /* U+30D1 "パ" */
    0xe, 0x14, 0x38, 0x0, 0x9, 0x11, 0x22, 0x43,
    0x6, 0x8,

    /* U+30D2 "ヒ" */
    0x81, 0x2, 0x37, 0x88, 0x10, 0x20, 0x3f,

    /* U+30D3 "ビ" */
    0x4, 0x24, 0x24, 0x8, 0x11, 0xbc, 0x40, 0x81,
    0x1, 0xf8,

    /* U+30D4 "ピ" */
    0xe, 0x14, 0x3c, 0x8, 0x11, 0xbc, 0x40, 0x81,
    0x1, 0xf8,

    /* U+30D5 "フ" */
    0xfe, 0x4, 0x8, 0x20, 0x41, 0xc, 0x0,

    /* U+30D6 "ブ" */
    0x4, 0x24, 0x20, 0xf, 0xe0, 0x40, 0x82, 0x4,
    0x10, 0xc0,

    /* U+30D7 "プ" */
    0xe, 0x14, 0x38, 0xf, 0xe0, 0x40, 0x82, 0x4,
    0x10, 0xc0,

    /* U+30D8 "ヘ" */
    0x20, 0xa2, 0x20, 0x20, 0x20,

    /* U+30D9 "ベ" */
    0x4, 0x24, 0x20, 0x0, 0x4, 0x14, 0x44, 0x4,
    0x4,

    /* U+30DA "ペ" */
    0xe, 0x14, 0x38, 0x0, 0x4, 0x14, 0x44, 0x4,
    0x4,

    /* U+30DB "ホ" */
    0x10, 0x23, 0xf8, 0x85, 0x4a, 0x54, 0xc9,

    /* U+30DC "ボ" */
    0x4, 0x24, 0x20, 0x81, 0x1f, 0xc4, 0x2a, 0x52,
    0xa6, 0x48,

    /* U+30DD "ポ" */
    0xe, 0x14, 0x38, 0x81, 0x1f, 0xc4, 0x2a, 0x52,
    0xa6, 0x48,

    /* U+30DE "マ" */
    0xfe, 0x4, 0xa, 0x22, 0x82, 0x2, 0x0,

    /* U+30DF "ミ" */
    0x78, 0x0, 0x1e, 0x0, 0xf, 0x3,

    /* U+30E0 "ム" */
    0x20, 0x40, 0x82, 0x24, 0x50, 0x7f, 0x80,

    /* U+30E1 "メ" */
    0x4, 0x48, 0x50, 0x40, 0xc6, 0x70, 0x0,

    /* U+30E2 "モ" */
    0xfc, 0x40, 0x87, 0xf2, 0x4, 0x7, 0x80,

    /* U+30E3 "ャ" */
    0x47, 0xd2, 0xa4, 0x0,

    /* U+30E4 "ヤ" */
    0x21, 0xfc, 0x89, 0x22, 0x84, 0x8, 0x0,

    /* U+30E5 "ュ" */
    0x70, 0x85, 0xf0,

    /* U+30E6 "ユ" */
    0x78, 0x10, 0x20, 0x40, 0x9f, 0xc0,

    /* U+30E7 "ョ" */
    0xf1, 0xf1, 0xf0,

    /* U+30E8 "ヨ" */
    0xfe, 0x4, 0xb, 0xf0, 0x20, 0x7f, 0x80,

    /* U+30E9 "ラ" */
    0x7c, 0x3, 0xf8, 0x10, 0x41, 0xc, 0x0,

    /* U+30EA "リ" */
    0x86, 0x18, 0x61, 0x4, 0x23, 0x0,

    /* U+30EB "ル" */
    0x50, 0xa1, 0x42, 0x85, 0xa, 0x67, 0x0,

    /* U+30EC "レ" */
    0x82, 0x8, 0x21, 0x8a, 0xcc, 0x0,

    /* U+30ED "ロ" */
    0xff, 0x6, 0xc, 0x18, 0x3f, 0xe0, 0x80,

    /* U+30EE "ヮ" */
    0xfc, 0x44, 0xc0,

    /* U+30EF "ワ" */
    0xff, 0x6, 0xc, 0x10, 0x20, 0x8e, 0x0,

    /* U+30F0 "ヰ" */
    0x9, 0xfd, 0x22, 0x4f, 0xe1, 0x2, 0x4,

    /* U+30F1 "ヱ" */
    0xfe, 0x4, 0x48, 0xe1, 0x2, 0x3f, 0x80,

    /* U+30F2 "ヲ" */
    0xfe, 0x4, 0xb, 0xf0, 0x20, 0x9e, 0x0,

    /* U+30F3 "ン" */
    0xe2, 0x4, 0x8, 0x10, 0x20, 0xbe, 0x0,

    /* U+30F4 "ヴ" */
    0x4, 0x24, 0x20, 0x81, 0x1f, 0xe0, 0xc1, 0x2,
    0x8, 0x60,

    /* U+30F5 "ヵ" */
    0x47, 0xd3, 0x11, 0x0,

    /* U+30F6 "ヶ" */
    0x43, 0xe4, 0x22, 0x0,

    /* U+30F7 "ヷ" */
    0x4, 0x24, 0x20, 0xf, 0xf0, 0x60, 0xc1, 0x2,
    0x8, 0xe0,

    /* U+30F8 "ヸ" */
    0x4, 0x24, 0x20, 0x4f, 0xe9, 0x12, 0x7f, 0x8,
    0x10, 0x20,

    /* U+30F9 "ヹ" */
    0x4, 0x24, 0x20, 0xf, 0xe0, 0x44, 0x8e, 0x10,
    0x23, 0xf8,

    /* U+30FA "ヺ" */
    0x4, 0x24, 0x20, 0xf, 0xe0, 0x40, 0xbf, 0x2,
    0x9, 0xe0,

    /* U+30FB "・" */
    0xf0,

    /* U+30FC "ー" */
    0xfc,

    /* U+30FD "ヽ" */
    0x84, 0x21,

    /* U+30FE "ヾ" */
    0x8, 0x99, 0x10, 0x20, 0x40,

    /* U+30FF "ヿ" */
    0xfc, 0x10, 0x41, 0x4, 0x10, 0x40
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 128, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 7, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 18, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 32, .adv_w = 128, .box_w = 1, .box_h = 3, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 33, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 37, .adv_w = 128, .box_w = 4, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 41, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 45, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 49, .adv_w = 128, .box_w = 2, .box_h = 4, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 50, .adv_w = 128, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 2},
    {.bitmap_index = 51, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 52, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 59, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 70, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 128, .box_w = 2, .box_h = 6, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 128, .box_w = 2, .box_h = 7, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 122, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 127, .adv_w = 128, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 130, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 135, .adv_w = 128, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 149, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 205, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 210, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 231, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 280, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 308, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 322, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 128, .box_w = 3, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 332, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 339, .adv_w = 128, .box_w = 3, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 128, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 344, .adv_w = 128, .box_w = 7, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 345, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 346, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 370, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 376, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 381, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 128, .box_w = 1, .box_h = 6, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 128, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 390, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 128, .box_w = 1, .box_h = 7, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 397, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 415, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 420, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 428, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 432, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 445, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 450, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 454, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 128, .box_w = 3, .box_h = 9, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 462, .adv_w = 128, .box_w = 1, .box_h = 11, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 464, .adv_w = 128, .box_w = 3, .box_h = 9, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 468, .adv_w = 128, .box_w = 6, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 470, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 479, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 485, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 490, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 495, .adv_w = 128, .box_w = 1, .box_h = 11, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 497, .adv_w = 128, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 504, .adv_w = 128, .box_w = 3, .box_h = 1, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 505, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 512, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 519, .adv_w = 128, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 2},
    {.bitmap_index = 528, .adv_w = 128, .box_w = 5, .box_h = 1, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 529, .adv_w = 128, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 531, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 536, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 541, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 2},
    {.bitmap_index = 542, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 543, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 554, .adv_w = 128, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 561, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 575, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 610, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 617, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 624, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 631, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 638, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 645, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 650, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 655, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 660, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 672, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 679, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 686, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 693, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 700, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 707, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 718, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 725, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 732, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 739, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 746, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 753, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 760, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 767, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 773, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 779, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 785, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 791, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 797, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 803, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 809, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 813, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 818, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 824, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 831, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 837, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 843, .adv_w = 128, .box_w = 2, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 845, .adv_w = 128, .box_w = 2, .box_h = 7, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 847, .adv_w = 128, .box_w = 3, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 850, .adv_w = 128, .box_w = 3, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 853, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 859, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 865, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 871, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 877, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 883, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 889, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 895, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 899, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 906, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 911, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 916, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 921, .adv_w = 128, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 926, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 931, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 937, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 942, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 947, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 954, .adv_w = 128, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 957, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 964, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 967, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 972, .adv_w = 128, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 975, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 982, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 987, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 994, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1001, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1011, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1018, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1028, .adv_w = 128, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1032, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1039, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1046, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1056, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1063, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1073, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1080, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1090, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1095, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1101, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1108, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1118, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1125, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1135, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1142, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1152, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1159, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1169, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1176, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1186, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1190, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1195, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1204, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1211, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1221, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1228, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1238, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1245, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1252, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1259, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1266, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1273, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1280, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1290, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1300, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1307, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1317, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1327, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1334, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1344, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1354, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1359, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1368, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1377, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1384, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1394, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1404, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1410, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1417, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1424, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1431, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1438, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1443, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1450, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1455, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1462, .adv_w = 128, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1466, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1473, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1479, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1484, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1491, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1498, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1505, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1509, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1516, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1523, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1530, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1535, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1542, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1551, .adv_w = 128, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1555, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1559, .adv_w = 0, .box_w = 4, .box_h = 3, .ofs_x = -8, .ofs_y = 7},
    {.bitmap_index = 1561, .adv_w = 0, .box_w = 3, .box_h = 3, .ofs_x = -8, .ofs_y = 7},
    {.bitmap_index = 1563, .adv_w = 128, .box_w = 4, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1565, .adv_w = 128, .box_w = 3, .box_h = 3, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 1567, .adv_w = 128, .box_w = 3, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1569, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1574, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1581, .adv_w = 128, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 1583, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1587, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1594, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1597, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1603, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1607, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1614, .adv_w = 128, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1617, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1624, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1628, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1635, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1642, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1652, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1659, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1669, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1675, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1685, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1692, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1702, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1708, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1718, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1725, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1735, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1741, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1750, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1757, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1767, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1774, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1784, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1791, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1801, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1808, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1818, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1825, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1835, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1839, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1845, .adv_w = 128, .box_w = 6, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1854, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1861, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1871, .adv_w = 128, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1876, .adv_w = 128, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1883, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1890, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1897, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1904, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1911, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1917, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1923, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1933, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1943, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1950, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1960, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1970, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1977, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1987, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1997, .adv_w = 128, .box_w = 7, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2002, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2011, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2020, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2027, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2037, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2047, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2054, .adv_w = 128, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2060, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2067, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2074, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2081, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2085, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2092, .adv_w = 128, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2095, .adv_w = 128, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2101, .adv_w = 128, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2104, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2111, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2118, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2124, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2131, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2137, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2144, .adv_w = 128, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2147, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2154, .adv_w = 128, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2161, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2168, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2175, .adv_w = 128, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2182, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2192, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2196, .adv_w = 128, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2200, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2210, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2220, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2230, .adv_w = 128, .box_w = 7, .box_h = 11, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2240, .adv_w = 128, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 2},
    {.bitmap_index = 2241, .adv_w = 128, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 2242, .adv_w = 128, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 2244, .adv_w = 128, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 2249, .adv_w = 128, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_1[] = {
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 0, 9, 10, 0, 11, 12, 13,
    14, 0, 0, 15, 0, 16, 17, 18,
    0, 19, 20
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 161, .range_length = 27, .glyph_id_start = 96,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_1, .list_length = 27, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 191, .range_length = 65, .glyph_id_start = 117,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 12353, .range_length = 86, .glyph_id_start = 182,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 12441, .range_length = 103, .glyph_id_start = 268,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 5,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t pokemon_font_8 = {
#else
lv_font_t pokemon_font_8 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 11,          /*The maximum line height required by the font*/
    .base_line = 1,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if POKEMON_FONT_8*/

