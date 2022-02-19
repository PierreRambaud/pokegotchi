/*******************************************************************************
 * Size: 10 px
 * Bpp: 1
 * Opts: 
 ******************************************************************************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

#ifndef POKEMON_FONT_10
#define POKEMON_FONT_10 1
#endif

#if POKEMON_FONT_10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0x73, 0xbf, 0xff, 0xb8, 0x0, 0x73, 0x80,

    /* U+0022 "\"" */
    0x99, 0x90,

    /* U+0023 "#" */
    0x47, 0x7f, 0xd1, 0xc8, 0xe4, 0x77, 0xfd, 0x1c,

    /* U+0024 "$" */
    0x11, 0xf9, 0x1e, 0x16, 0x51, 0x1e, 0x10,

    /* U+0025 "%" */
    0x40, 0xc9, 0x11, 0x1, 0x1, 0x20, 0x1, 0x13,
    0x4,

    /* U+0026 "&" */
    0x38, 0x74, 0x74, 0x39, 0x4d, 0x44, 0xc7, 0x7d,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x3a, 0x21, 0x8, 0x1, 0x7,

    /* U+0029 ")" */
    0xe0, 0x82, 0x10, 0x80, 0x5c,

    /* U+002A "*" */
    0x12, 0x57, 0x9e, 0x12, 0x51, 0x0,

    /* U+002B "+" */
    0x10, 0x4f, 0xc4, 0x10, 0x40,

    /* U+002C "," */
    0xf5, 0x80,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0xfc,

    /* U+002F "/" */
    0x0, 0x81, 0x1, 0x1, 0x1, 0x0, 0x1, 0x1,
    0x0,

    /* U+0030 "0" */
    0x3c, 0x27, 0x30, 0xf8, 0x74, 0x23, 0x90, 0xf0,

    /* U+0031 "1" */
    0x38, 0x78, 0x38, 0x38, 0x38, 0x38, 0xff,

    /* U+0032 "2" */
    0x7e, 0x71, 0xc1, 0xef, 0x87, 0x7, 0x83, 0xfe,

    /* U+0033 "3" */
    0x7f, 0x87, 0x7, 0x0, 0x0, 0x3f, 0x1d, 0xf8,

    /* U+0034 "4" */
    0xf, 0x87, 0xe7, 0x39, 0x8e, 0xe3, 0xbf, 0xf0,
    0x38,

    /* U+0035 "5" */
    0xfe, 0x70, 0x3f, 0x80, 0x40, 0x3f, 0x1d, 0xf8,

    /* U+0036 "6" */
    0x7e, 0x70, 0x3f, 0x9c, 0x4e, 0x3f, 0x1d, 0xf8,

    /* U+0037 "7" */
    0xff, 0xf1, 0xc1, 0xc0, 0xe1, 0x80, 0xc0, 0x60,

    /* U+0038 "8" */
    0x7e, 0x71, 0xdf, 0x8c, 0x4e, 0x3f, 0x1d, 0xf8,

    /* U+0039 "9" */
    0x7e, 0x71, 0xf8, 0xef, 0xf0, 0x38, 0x1d, 0xf8,

    /* U+003A ":" */
    0xfc, 0x1, 0xf8,

    /* U+003B ";" */
    0xf3, 0xd6,

    /* U+003C "<" */
    0xc, 0x67, 0x38, 0x60, 0x41, 0x83,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0xe1, 0xc1, 0x83, 0x8, 0x47, 0x38,

    /* U+003F "?" */
    0x7f, 0xb8, 0xfe, 0x78, 0x70, 0x0, 0x0, 0x1,
    0xc0, 0x70,

    /* U+0040 "@" */
    0x1c, 0x21, 0x2f, 0x31, 0x89, 0x44, 0xfc, 0x2,
    0x81, 0x1e, 0x0,

    /* U+0041 "A" */
    0x8, 0xa, 0x5, 0x8, 0x47, 0xe0, 0x2, 0x3,
    0x1,

    /* U+0042 "B" */
    0xfc, 0x41, 0x20, 0x9f, 0xc8, 0x4, 0x6, 0x3,
    0xfc,

    /* U+0043 "C" */
    0x1f, 0x20, 0x60, 0x10, 0x8, 0x0, 0x1, 0x2,
    0x3e,

    /* U+0044 "D" */
    0xfc, 0x41, 0x20, 0x30, 0x18, 0xc, 0x2, 0x9,
    0xf8,

    /* U+0045 "E" */
    0xff, 0xc0, 0x20, 0x1f, 0xc8, 0x4, 0x2, 0x1,
    0xff,

    /* U+0046 "F" */
    0xff, 0xc0, 0x20, 0x1f, 0xc8, 0x4, 0x2, 0x1,
    0x0,

    /* U+0047 "G" */
    0x1f, 0x20, 0x60, 0x11, 0xf8, 0x8, 0x5, 0x2,
    0x3e,

    /* U+0048 "H" */
    0x80, 0xc0, 0x60, 0x3f, 0xf8, 0xc, 0x6, 0x3,
    0x1,

    /* U+0049 "I" */
    0xfc, 0x41, 0x4, 0x10, 0x41, 0x3f,

    /* U+004A "J" */
    0x7f, 0x82, 0x1, 0x0, 0x80, 0x44, 0x22, 0x10,
    0xf0,

    /* U+004B "K" */
    0x82, 0x42, 0x22, 0x17, 0xe, 0x44, 0x2, 0x9,
    0x1,

    /* U+004C "L" */
    0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x2, 0x1,
    0xff,

    /* U+004D "M" */
    0x80, 0xf1, 0xe5, 0x31, 0x18, 0xc, 0x6, 0x3,
    0x1,

    /* U+004E "N" */
    0x80, 0xf0, 0x64, 0x31, 0x18, 0x4c, 0x6, 0xf,
    0x1,

    /* U+004F "O" */
    0x3c, 0x21, 0x20, 0x30, 0x18, 0x8, 0x1, 0x8,
    0x78,

    /* U+0050 "P" */
    0xff, 0x40, 0x60, 0x3f, 0xe8, 0x4, 0x2, 0x1,
    0x0,

    /* U+0051 "Q" */
    0x3c, 0x21, 0x20, 0x30, 0x18, 0x48, 0x1, 0x8,
    0x79,

    /* U+0052 "R" */
    0xfe, 0x40, 0x60, 0x3f, 0xc8, 0x44, 0x2, 0x9,
    0x1,

    /* U+0053 "S" */
    0x7c, 0x41, 0x20, 0xf, 0xc0, 0x0, 0x6, 0x2,
    0xfc,

    /* U+0054 "T" */
    0xff, 0x84, 0x2, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10,

    /* U+0055 "U" */
    0x80, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x5, 0x2,
    0x7f,

    /* U+0056 "V" */
    0x80, 0xc0, 0x50, 0x88, 0x40, 0x0, 0xa0, 0x50,
    0x10,

    /* U+0057 "W" */
    0x80, 0xe2, 0x39, 0x6e, 0x5b, 0x80, 0xf8, 0x7e,
    0x1e, 0x3,

    /* U+0058 "X" */
    0xc3, 0x42, 0x24, 0x8, 0x24, 0x0, 0x42, 0xc3,

    /* U+0059 "Y" */
    0x80, 0xa1, 0x5, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10,

    /* U+005A "Z" */
    0xff, 0xc0, 0x40, 0x60, 0x20, 0x10, 0x0, 0x4,
    0x3, 0xff,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x8f,

    /* U+005C "\\" */
    0x80, 0x20, 0x4, 0x1, 0x0, 0x40, 0x0, 0x8,
    0x1,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x1f,

    /* U+005E "^" */
    0x10, 0x4, 0xa1,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0060 "`" */
    0x90,

    /* U+0061 "a" */
    0x78, 0x9, 0xf0, 0x28, 0x4f, 0xc0,

    /* U+0062 "b" */
    0x81, 0x2, 0x7, 0xe8, 0x10, 0x60, 0xfe,

    /* U+0063 "c" */
    0x7d, 0x6, 0x4, 0x8, 0x2f, 0x80,

    /* U+0064 "d" */
    0x2, 0x4, 0xb, 0xf0, 0x30, 0x60, 0xbf,

    /* U+0065 "e" */
    0x7d, 0x7, 0xfc, 0x0, 0xf, 0xc0,

    /* U+0066 "f" */
    0xc, 0x24, 0x47, 0xf1, 0x2, 0x4, 0x8,

    /* U+0067 "g" */
    0x7f, 0x6, 0xb, 0xf0, 0x20, 0x7f, 0x0,

    /* U+0068 "h" */
    0x82, 0x8, 0x3e, 0x82, 0x18, 0x61,

    /* U+0069 "i" */
    0xbe,

    /* U+006A "j" */
    0x10, 0x11, 0x11, 0x1e,

    /* U+006B "k" */
    0x81, 0x2, 0x3d, 0xcc, 0x10, 0x2e, 0x47,

    /* U+006C "l" */
    0xff,

    /* U+006D "m" */
    0xf7, 0x44, 0x62, 0x31, 0x18, 0x8c, 0x44,

    /* U+006E "n" */
    0xfa, 0x18, 0x61, 0x86, 0x10,

    /* U+006F "o" */
    0x7d, 0x6, 0xc, 0x10, 0xf, 0x80,

    /* U+0070 "p" */
    0xfd, 0x6, 0xf, 0xe8, 0x10, 0x20, 0x0,

    /* U+0071 "q" */
    0x7f, 0x6, 0xb, 0xf0, 0x20, 0x40, 0x80,

    /* U+0072 "r" */
    0x8f, 0x90, 0xe0, 0x80, 0x80, 0x80,

    /* U+0073 "s" */
    0x7d, 0x1, 0xf0, 0x0, 0x3f, 0x80,

    /* U+0074 "t" */
    0x13, 0xf1, 0x4, 0x10, 0x40, 0xc0,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x85, 0xf0,

    /* U+0076 "v" */
    0x86, 0x18, 0x40, 0x48, 0x40,

    /* U+0077 "w" */
    0x80, 0xc4, 0x62, 0x30, 0x19, 0x4a, 0x10,

    /* U+0078 "x" */
    0xc1, 0x5, 0x80, 0x80, 0x0, 0x16, 0x10, 0x70,

    /* U+0079 "y" */
    0x86, 0x18, 0x5f, 0x4, 0x1f, 0x80,

    /* U+007A "z" */
    0xff, 0x4, 0x38, 0x0, 0x40, 0xff,

    /* U+007B "{" */
    0x21, 0x25, 0x2, 0x48, 0x80,

    /* U+007C "|" */
    0xff, 0xf8,

    /* U+007D "}" */
    0x81, 0x24, 0x42, 0x4a, 0x0,

    /* U+007E "~" */
    0x73, 0x18,

    /* U+00A1 "¡" */
    0x73, 0x80, 0xef, 0xff, 0xee, 0x70,

    /* U+00A2 "¢" */
    0x11, 0xf9, 0x24, 0x90, 0x47, 0xc4,

    /* U+00A3 "£" */
    0x3c, 0x85, 0x2, 0xf, 0x88, 0x10, 0x20, 0xfe,

    /* U+00A4 "¤" */
    0x82, 0xf9, 0x12, 0x24, 0x4f, 0xa0, 0x80,

    /* U+00A5 "¥" */
    0x7a, 0x5e, 0x8f, 0x21, 0x1e, 0x40,

    /* U+00A6 "¦" */
    0xf8, 0xf8,

    /* U+00A7 "§" */
    0x7b, 0x9e, 0x58, 0x72, 0x68, 0x5d, 0x18, 0x28,
    0xe3, 0x78,

    /* U+00A8 "¨" */
    0x90,

    /* U+00A9 "©" */
    0x1e, 0x21, 0x27, 0x32, 0x19, 0xc, 0x86, 0x72,
    0x84, 0x1e, 0x0,

    /* U+00AB "«" */
    0x9, 0x3b, 0x76, 0xfe, 0x76, 0x32, 0x3b, 0x9,

    /* U+00AC "¬" */
    0xfc, 0x10, 0x41,

    /* U+00AE "®" */
    0x1c, 0x21, 0x27, 0x32, 0x99, 0x8c, 0x86, 0x52,
    0x84, 0x1c, 0x0,

    /* U+00AF "¯" */
    0xfc,

    /* U+00B0 "°" */
    0x70, 0x23, 0x17, 0x0,

    /* U+00B1 "±" */
    0x13, 0xf1, 0x0, 0x3, 0xf0,

    /* U+00B4 "´" */
    0x60,

    /* U+00B6 "¶" */
    0x33, 0xe7, 0xc9, 0x93, 0x22, 0x44, 0x89, 0x12,

    /* U+00B7 "·" */
    0xfc,

    /* U+00B8 "¸" */
    0x70,

    /* U+00BA "º" */
    0x7c, 0x83, 0x83, 0x83, 0x83, 0x7c,

    /* U+00BB "»" */
    0x88, 0x77, 0x1d, 0xcf, 0xf7, 0x73, 0x33, 0xb9,
    0x10,

    /* U+00BF "¿" */
    0xc, 0x3, 0x0, 0x0, 0x30, 0x71, 0xdc, 0x6f,
    0x39, 0xfe,

    /* U+00C0 "À" */
    0x8, 0x2, 0x2, 0x2, 0x80, 0x2, 0x13, 0xff,
    0x1,

    /* U+00C1 "Á" */
    0x8, 0x8, 0x2, 0x2, 0x80, 0x2, 0x13, 0xff,
    0x1,

    /* U+00C2 "Â" */
    0x8, 0xa, 0x2, 0x2, 0x80, 0x2, 0x13, 0xff,
    0x1,

    /* U+00C3 "Ã" */
    0x72, 0x46, 0x2, 0x2, 0x80, 0x2, 0x13, 0xff,
    0x1,

    /* U+00C4 "Ä" */
    0x14, 0x4, 0x5, 0x8, 0x47, 0xe0, 0x2, 0x3,
    0x1,

    /* U+00C5 "Å" */
    0x8, 0xa, 0x2, 0x2, 0x80, 0x2, 0x13, 0xff,
    0x1,

    /* U+00C6 "Æ" */
    0xf, 0x8a, 0x5, 0x8, 0xe7, 0xc0, 0x22, 0x11,
    0xf,

    /* U+00C7 "Ç" */
    0x1f, 0x20, 0x60, 0x10, 0x4, 0x8, 0xf8, 0x20,
    0x10, 0x18, 0x0,

    /* U+00C8 "È" */
    0x10, 0x4, 0x3f, 0xf0, 0xf, 0xf4, 0x2, 0x1,
    0xff,

    /* U+00C9 "É" */
    0x4, 0x4, 0x3f, 0xf0, 0xf, 0xe4, 0x2, 0x1,
    0xff,

    /* U+00CA "Ê" */
    0x8, 0xa, 0x3f, 0xf0, 0xf, 0xe4, 0x2, 0x1,
    0xff,

    /* U+00CB "Ë" */
    0x12, 0x0, 0xf, 0xfe, 0x0, 0xff, 0x20, 0x8,
    0x3, 0xff,

    /* U+00CC "Ì" */
    0x40, 0x4f, 0xc4, 0x10, 0x41, 0x3f,

    /* U+00CD "Í" */
    0x8, 0x4f, 0xc4, 0x10, 0x41, 0x3f,

    /* U+00CE "Î" */
    0x11, 0x2f, 0xc4, 0x10, 0x41, 0x3f,

    /* U+00CF "Ï" */
    0x48, 0xf, 0xc4, 0x10, 0x41, 0x3f,

    /* U+00D0 "Ð" */
    0xfc, 0x41, 0x20, 0x3f, 0x18, 0xc, 0x2, 0x9,
    0xf8,

    /* U+00D1 "Ñ" */
    0x18, 0xa3, 0xb0, 0x32, 0x18, 0x8c, 0x6, 0x13,
    0x7,

    /* U+00D2 "Ò" */
    0x8, 0x2, 0x1f, 0x90, 0x18, 0xc, 0x4, 0x0,
    0xfc,

    /* U+00D3 "Ó" */
    0x8, 0x8, 0x1f, 0x90, 0x18, 0xc, 0x4, 0x0,
    0xfc,

    /* U+00D4 "Ô" */
    0x8, 0xa, 0x1f, 0x90, 0x18, 0xc, 0x4, 0x0,
    0xfc,

    /* U+00D5 "Õ" */
    0x72, 0x46, 0x1f, 0x90, 0x18, 0xc, 0x4, 0x0,
    0xfc,

    /* U+00D6 "Ö" */
    0x14, 0xe, 0x10, 0x90, 0x18, 0x8, 0x1, 0x8,
    0x38,

    /* U+00D7 "×" */
    0x85, 0x21, 0x0, 0x4a, 0x10,

    /* U+00D8 "Ø" */
    0x1c, 0xa1, 0x21, 0x31, 0x19, 0x8, 0x1, 0x9,
    0x38,

    /* U+00D9 "Ù" */
    0x10, 0x4, 0x20, 0x30, 0x18, 0x8, 0x5, 0x2,
    0x3f,

    /* U+00DA "Ú" */
    0x8, 0x8, 0x20, 0x30, 0x18, 0x8, 0x5, 0x2,
    0x3f,

    /* U+00DB "Û" */
    0x8, 0x4, 0x8, 0xe, 0x3, 0x80, 0xc0, 0x34,
    0xc, 0xff,

    /* U+00DC "Ü" */
    0x14, 0x0, 0x20, 0x30, 0x18, 0x8, 0x5, 0x2,
    0x3f,

    /* U+00DD "Ý" */
    0x4, 0x44, 0x50, 0x82, 0x80, 0x0, 0x40, 0x20,
    0x10,

    /* U+00DE "Þ" */
    0x80, 0x7f, 0xa0, 0x30, 0x1f, 0xf4, 0x2, 0x1,
    0x0,

    /* U+00DF "ß" */
    0xf9, 0xa, 0x14, 0xe8, 0x10, 0x64, 0xc6,

    /* U+00E0 "à" */
    0x40, 0x21, 0xe0, 0x27, 0xc0, 0xa1, 0x3f,

    /* U+00E1 "á" */
    0x8, 0x21, 0xe0, 0x27, 0xc0, 0xa1, 0x3f,

    /* U+00E2 "â" */
    0x10, 0x91, 0xe0, 0x27, 0xc0, 0xa1, 0x3f,

    /* U+00E3 "ã" */
    0x73, 0x19, 0xe0, 0x27, 0xc0, 0xa1, 0x3f,

    /* U+00E4 "ä" */
    0x48, 0x1, 0xe0, 0x27, 0xc0, 0xa1, 0x3f,

    /* U+00E5 "å" */
    0x10, 0x91, 0xe0, 0x27, 0xc0, 0xa1, 0x3f,

    /* U+00E6 "æ" */
    0x74, 0x15, 0xf8, 0x48, 0x8f, 0xc0,

    /* U+00E7 "ç" */
    0x7d, 0x6, 0x3, 0xe0, 0x81, 0xe, 0x0,

    /* U+00E8 "è" */
    0x10, 0x11, 0xf4, 0x1f, 0xf0, 0x0, 0x3f,

    /* U+00E9 "é" */
    0x38, 0x60, 0xf, 0x88, 0x17, 0xfa, 0x0, 0x0,
    0x7f,

    /* U+00EA "ê" */
    0x10, 0x91, 0xf4, 0x1f, 0xf0, 0x0, 0x3f,

    /* U+00EB "ë" */
    0x48, 0x1, 0xf4, 0x1f, 0xf0, 0x0, 0x3f,

    /* U+00EC "ì" */
    0x91, 0x55,

    /* U+00ED "í" */
    0x62, 0xaa,

    /* U+00EE "î" */
    0x54, 0x24, 0x92,

    /* U+00EF "ï" */
    0xa1, 0x24, 0x90,

    /* U+00F0 "ð" */
    0x4, 0xf, 0x4, 0x7c, 0x4, 0x84, 0x84, 0x78,

    /* U+00F1 "ñ" */
    0x73, 0x1b, 0xe4, 0x28, 0x50, 0xa1, 0x42,

    /* U+00F2 "ò" */
    0x40, 0x21, 0xf4, 0x18, 0x30, 0x40, 0x3e,

    /* U+00F3 "ó" */
    0x8, 0x21, 0xf4, 0x18, 0x30, 0x40, 0x3e,

    /* U+00F4 "ô" */
    0x10, 0x91, 0xf4, 0x18, 0x30, 0x40, 0x3e,

    /* U+00F5 "õ" */
    0x73, 0x19, 0xf4, 0x18, 0x30, 0x40, 0x3e,

    /* U+00F6 "ö" */
    0x48, 0x1, 0xf4, 0x18, 0x30, 0x40, 0x3e,

    /* U+00F7 "÷" */
    0x10, 0xf, 0xc0, 0x0, 0x40,

    /* U+00F8 "ø" */
    0x0, 0xbf, 0x21, 0x91, 0x48, 0x20, 0x81, 0xf1,
    0x0,

    /* U+00F9 "ù" */
    0x40, 0x48, 0x61, 0x86, 0x18, 0x5f,

    /* U+00FA "ú" */
    0x8, 0x48, 0x61, 0x86, 0x18, 0x5f,

    /* U+00FB "û" */
    0x11, 0x28, 0x61, 0x86, 0x18, 0x5f,

    /* U+00FC "ü" */
    0x48, 0x8, 0x61, 0x86, 0x18, 0x5f,

    /* U+00FD "ý" */
    0x8, 0x48, 0x61, 0x85, 0xf0, 0x41, 0xf8,

    /* U+00FE "þ" */
    0x81, 0x3, 0xf4, 0x18, 0x3f, 0xa0, 0x40, 0x80,

    /* U+00FF "ÿ" */
    0x48, 0x8, 0x61, 0x85, 0xf0, 0x41, 0xf8,

    /* U+3041 "ぁ" */
    0x30, 0xf8, 0xc3, 0xe7, 0xd1, 0x5c, 0x80,

    /* U+3042 "あ" */
    0x10, 0x7f, 0x84, 0x3, 0xe7, 0x1f, 0xbe, 0x5b,
    0x11, 0x71, 0x0,

    /* U+3043 "ぃ" */
    0x8a, 0x38, 0x61, 0x60,

    /* U+3044 "い" */
    0x82, 0x81, 0x81, 0x81, 0x81, 0x81, 0x68, 0x10,

    /* U+3045 "ぅ" */
    0x70, 0x1d, 0x18, 0x85, 0xc0,

    /* U+3046 "う" */
    0xf8, 0x7, 0x9e, 0x84, 0x10, 0x41, 0x9, 0xc0,

    /* U+3047 "ぇ" */
    0x70, 0x3e, 0x67, 0x3a, 0x20,

    /* U+3048 "え" */
    0x38, 0x0, 0x0, 0xf, 0xe0, 0x40, 0x40, 0xf0,
    0x78, 0x64, 0x41, 0xc0,

    /* U+3049 "ぉ" */
    0x30, 0xf4, 0xc3, 0xc7, 0x96, 0x9d, 0x0,

    /* U+304A "お" */
    0x30, 0xfe, 0x4c, 0x7, 0xe7, 0xd, 0x86, 0xc3,
    0x61, 0x73, 0x0,

    /* U+304B "か" */
    0x60, 0x62, 0xf9, 0x65, 0x65, 0x64, 0x84, 0x4,
    0x38,

    /* U+304C "が" */
    0x2, 0x9, 0x4, 0x60, 0x60, 0x62, 0xf9, 0x65,
    0x65, 0x64, 0x84, 0x4, 0x38,

    /* U+304D "き" */
    0x8, 0x7f, 0xc1, 0x1f, 0xf0, 0x34, 0x3a, 0x1d,
    0x0, 0x7f, 0x0,

    /* U+304E "ぎ" */
    0x3, 0x4, 0x41, 0x0, 0x0, 0x87, 0xfc, 0x11,
    0xff, 0x3, 0x43, 0xa1, 0xd0, 0x7, 0xf0,

    /* U+304F "く" */
    0x8, 0x84, 0xc8, 0x42, 0xc, 0x10, 0x40,

    /* U+3050 "ぐ" */
    0x8, 0x8, 0x4, 0xc, 0x68, 0x8c, 0x66, 0x10,
    0xc0, 0x10, 0x4, 0x0,

    /* U+3051 "け" */
    0x3, 0x1, 0xa0, 0xd1, 0xf8, 0x34, 0x1a, 0xd,
    0x6, 0x83, 0x3, 0x0,

    /* U+3052 "げ" */
    0x2, 0x9, 0x4, 0x2, 0x82, 0x82, 0x8f, 0x82,
    0x82, 0x82, 0x82, 0x82, 0x4,

    /* U+3053 "こ" */
    0x7f, 0x0, 0x40, 0x0, 0x0, 0x0, 0x2, 0x0,
    0xff,

    /* U+3054 "ご" */
    0x2, 0x9, 0x4, 0x0, 0x7e, 0x7e, 0x1, 0x0,
    0x0, 0x0, 0x0, 0x80, 0x7f,

    /* U+3055 "さ" */
    0x10, 0x0, 0x2, 0x1f, 0xf0, 0x43, 0xfa, 0x1,
    0x0, 0x80, 0x3f, 0x80,

    /* U+3056 "ざ" */
    0x3, 0x4, 0x41, 0x2, 0x0, 0x0, 0x43, 0xfe,
    0x8, 0x7f, 0x40, 0x20, 0x10, 0x7, 0xf0,

    /* U+3057 "し" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x61, 0x85, 0xe0,

    /* U+3058 "じ" */
    0x85, 0x66, 0xcc, 0x48, 0x10, 0x21, 0x42, 0x84,
    0xf0,

    /* U+3059 "す" */
    0x3, 0x7f, 0xc0, 0xc7, 0xe6, 0x33, 0x18, 0xfc,
    0x6, 0xc, 0x0,

    /* U+305A "ず" */
    0x3, 0x4, 0x41, 0x0, 0x60, 0x37, 0xfc, 0xc,
    0x7e, 0x63, 0x31, 0x8f, 0xc0, 0x60, 0xc0,

    /* U+305B "せ" */
    0x63, 0x31, 0x98, 0xdf, 0xf6, 0x33, 0x19, 0x8c,
    0xc8, 0x60, 0xf, 0x80,

    /* U+305C "ぜ" */
    0x3, 0x4, 0x41, 0xc, 0x66, 0x33, 0x1b, 0xfe,
    0xc6, 0x63, 0x31, 0x99, 0xc, 0x1, 0xf0,

    /* U+305D "そ" */
    0x7f, 0x4, 0x0, 0x2, 0xf, 0xf8, 0x40, 0x40,
    0x20, 0x10, 0x7, 0x80,

    /* U+305E "ぞ" */
    0x3, 0x4, 0x41, 0xf, 0xe0, 0x80, 0x0, 0x41,
    0xff, 0x8, 0x8, 0x4, 0x2, 0x0, 0xf0,

    /* U+305F "た" */
    0x10, 0x8, 0x4, 0x1f, 0xe6, 0x3, 0x7d, 0x80,
    0xc0, 0x88, 0x43, 0xc0,

    /* U+3060 "だ" */
    0x1, 0x4, 0x41, 0x82, 0x1, 0x0, 0x83, 0xfc,
    0xc0, 0x6f, 0xb0, 0x18, 0x11, 0x8, 0x78,

    /* U+3061 "ち" */
    0x10, 0x8, 0x4, 0x1f, 0xe6, 0x3, 0xf9, 0x82,
    0xc1, 0x0, 0x87, 0x80,

    /* U+3062 "ぢ" */
    0x1, 0x4, 0x41, 0x82, 0x1, 0x0, 0x83, 0xfc,
    0xc0, 0x7f, 0x30, 0x58, 0x20, 0x10, 0xf0,

    /* U+3063 "っ" */
    0xf8, 0x10, 0x42, 0x70,

    /* U+3064 "つ" */
    0xfc, 0x4, 0x8, 0x10, 0x20, 0x9e, 0x0,

    /* U+3065 "づ" */
    0x4, 0x64, 0x20, 0x0, 0x0, 0x3f, 0x1, 0x2,
    0x4, 0x8, 0x27, 0x80,

    /* U+3066 "て" */
    0xff, 0x83, 0x82, 0x1, 0x1, 0x0, 0x80, 0x20,
    0xe,

    /* U+3067 "で" */
    0x3, 0x4, 0x41, 0x0, 0x0, 0x7, 0xfc, 0x1c,
    0x10, 0x8, 0x8, 0x4, 0x1, 0x0, 0x70,

    /* U+3068 "と" */
    0x10, 0x8, 0x4, 0x2, 0xe1, 0x83, 0x2, 0x1,
    0x0, 0x80, 0x3f, 0xc0,

    /* U+3069 "ど" */
    0x1, 0x4, 0x41, 0x82, 0x1, 0x0, 0x80, 0x5c,
    0x30, 0x60, 0x40, 0x20, 0x10, 0x7, 0xf8,

    /* U+306A "な" */
    0x30, 0x18, 0xc, 0xdf, 0x36, 0x4, 0x1a, 0xc,
    0x7e, 0x63, 0x9e, 0x0,

    /* U+306B "に" */
    0x8f, 0xc0, 0x20, 0x10, 0x8, 0x4, 0x82, 0x41,
    0x20, 0x8f, 0x80,

    /* U+306C "ぬ" */
    0x6, 0x33, 0x1b, 0xcf, 0xf7, 0x6f, 0x46, 0x47,
    0x2d, 0x67, 0x80,

    /* U+306D "ね" */
    0x10, 0x8, 0x3d, 0xde, 0xe1, 0x88, 0x84, 0xcf,
    0x6f, 0x94, 0x8b, 0xc0,

    /* U+306E "の" */
    0x1c, 0x6a, 0x89, 0x89, 0x89, 0x89, 0x89, 0x72,

    /* U+306F "は" */
    0x2, 0x8f, 0x82, 0x82, 0x82, 0x8e, 0x93, 0x92,
    0x92, 0x8c,

    /* U+3070 "ば" */
    0x2, 0x9, 0x4, 0x2, 0x8f, 0x82, 0x82, 0x82,
    0x8e, 0x93, 0x92, 0x92, 0x8c,

    /* U+3071 "ぱ" */
    0x7, 0x5, 0x7, 0x7, 0x8f, 0x82, 0x82, 0x82,
    0x8e, 0x93, 0x92, 0x92, 0x8c,

    /* U+3072 "ひ" */
    0xf8, 0x32, 0x63, 0x62, 0x62, 0x86, 0x84, 0x78,

    /* U+3073 "び" */
    0x2, 0x9, 0x4, 0x0, 0xf8, 0xf8, 0x32, 0x63,
    0x62, 0x62, 0x86, 0x84, 0x78,

    /* U+3074 "ぴ" */
    0x7, 0x5, 0x7, 0x0, 0xf8, 0xf8, 0x32, 0x63,
    0x62, 0x62, 0x86, 0x84, 0x78,

    /* U+3075 "ふ" */
    0x3e, 0x3, 0x6, 0x8, 0xc8, 0x6c, 0x36, 0x1a,
    0x70,

    /* U+3076 "ぶ" */
    0x2, 0x19, 0x4, 0x0, 0x0, 0x3c, 0x4, 0x18,
    0x44, 0x85, 0x85, 0x85, 0x38,

    /* U+3077 "ぷ" */
    0x7, 0x83, 0x41, 0xe0, 0x0, 0x1, 0xf0, 0x18,
    0x30, 0x46, 0x43, 0x61, 0xb0, 0xd3, 0x80,

    /* U+3078 "へ" */
    0x10, 0x34, 0x21, 0x0, 0x60, 0x30, 0x4,

    /* U+3079 "べ" */
    0x3, 0x4, 0x41, 0x0, 0x0, 0x0, 0x0, 0x40,
    0xd0, 0x84, 0x1, 0x80, 0xc0, 0x10,

    /* U+307A "ぺ" */
    0x7, 0x82, 0x41, 0xe0, 0x0, 0x0, 0x0, 0x40,
    0xd0, 0x84, 0x1, 0x80, 0xc0, 0x10,

    /* U+307B "ほ" */
    0xf, 0x82, 0x8f, 0x8f, 0x82, 0x8e, 0x93, 0x93,
    0x92, 0x8c,

    /* U+307C "ぼ" */
    0x2, 0x9, 0x4, 0xf, 0x82, 0x8f, 0x8f, 0x82,
    0x8e, 0x93, 0x93, 0x92, 0x8c,

    /* U+307D "ぽ" */
    0x7, 0x5, 0x7, 0xf, 0x82, 0x8f, 0x8f, 0x82,
    0x8e, 0x93, 0x92, 0x92, 0x8c,

    /* U+307E "ま" */
    0x4, 0x9, 0xf8, 0x27, 0xe0, 0x81, 0x3e, 0x86,
    0xf8,

    /* U+307F "み" */
    0x78, 0x4, 0x2, 0x81, 0x47, 0xfc, 0x52, 0x49,
    0x24, 0x92, 0x32, 0x0,

    /* U+3080 "む" */
    0x30, 0x18, 0x3e, 0x26, 0x17, 0x3, 0x82, 0xc1,
    0x61, 0x70, 0x9f, 0x80,

    /* U+3081 "め" */
    0x4, 0x32, 0x1b, 0xd, 0x87, 0x74, 0xa6, 0x23,
    0x31, 0x98, 0xb1, 0x80,

    /* U+3082 "も" */
    0x30, 0x18, 0xc, 0x1f, 0x83, 0x7, 0xe0, 0xc0,
    0x61, 0x30, 0x87, 0x80,

    /* U+3083 "ゃ" */
    0x48, 0xf9, 0xf6, 0x54, 0x26, 0x8c, 0x0,

    /* U+3084 "や" */
    0x66, 0x33, 0x19, 0x9f, 0xe6, 0xb, 0x45, 0x9c,
    0xce, 0x10, 0x8, 0x0,

    /* U+3085 "ゅ" */
    0x19, 0x7b, 0x6e, 0xd9, 0xa7, 0x86, 0x0,

    /* U+3086 "ゆ" */
    0x4, 0x4, 0xbe, 0xc5, 0x85, 0x85, 0x85, 0xb5,
    0xe, 0x30,

    /* U+3087 "ょ" */
    0x18, 0x71, 0x86, 0x7a, 0x77, 0x80,

    /* U+3088 "よ" */
    0x4, 0x2, 0x1, 0x0, 0xf0, 0x40, 0x20, 0x11,
    0xfc, 0x84, 0xbc, 0x0,

    /* U+3089 "ら" */
    0x60, 0x3a, 0x5, 0xec, 0x20, 0x40, 0x81, 0x7c,

    /* U+308A "り" */
    0x86, 0x18, 0x61, 0x86, 0x10, 0x42, 0x70,

    /* U+308B "る" */
    0x7e, 0xc, 0x0, 0x38, 0x7e, 0x81, 0x39, 0x39,
    0x4d, 0x3e,

    /* U+308C "れ" */
    0x10, 0x8, 0x3d, 0xde, 0xe1, 0x88, 0x84, 0xcd,
    0x66, 0x93, 0x8, 0x40,

    /* U+308D "ろ" */
    0x7e, 0xc, 0x0, 0x38, 0x7e, 0x81, 0x1, 0x1,
    0x1, 0x3e,

    /* U+308E "ゎ" */
    0x63, 0xe6, 0x59, 0xe5, 0xa0,

    /* U+308F "わ" */
    0x10, 0x8, 0x3d, 0xde, 0xe9, 0x88, 0x84, 0xc3,
    0x61, 0x90, 0x89, 0x80,

    /* U+3090 "ゐ" */
    0xf0, 0xe, 0x1c, 0xd2, 0x19, 0x3c, 0x9e, 0x52,
    0xcf,

    /* U+3091 "ゑ" */
    0x7f, 0x7, 0x3, 0x8f, 0xe8, 0xc, 0x4, 0xe2,
    0x7e, 0x77, 0x44, 0x40,

    /* U+3092 "を" */
    0x33, 0xe6, 0x1d, 0x76, 0xe6, 0x98, 0x3c,

    /* U+3093 "ん" */
    0x8, 0x4, 0x4, 0x2, 0x7, 0x83, 0xc1, 0x91,
    0x8, 0x83, 0x80,

    /* U+3094 "ゔ" */
    0x4, 0x64, 0x27, 0xc0, 0xf, 0x1e, 0x42, 0x4,
    0x8, 0x10, 0x47, 0x0,

    /* U+3095 "ゕ" */
    0x65, 0xe7, 0xcb, 0x48, 0x82, 0x0,

    /* U+3096 "ゖ" */
    0x9a, 0xf9, 0xa6, 0x9a, 0x80,

    /* U+3099 "゙" */
    0x14, 0x58,

    /* U+309A "゚" */
    0xf9, 0xf0,

    /* U+309B "゛" */
    0x14, 0x62, 0xc0,

    /* U+309C "゜" */
    0xf9, 0x9f,

    /* U+309D "ゝ" */
    0x86, 0x33, 0x36,

    /* U+309E "ゞ" */
    0x9, 0x96, 0x44, 0x81, 0x81, 0x4, 0x11, 0x80,

    /* U+309F "ゟ" */
    0x10, 0x8, 0x4, 0x3, 0xf1, 0x3, 0xf9, 0x82,
    0xc1, 0x60, 0xc7, 0x80,

    /* U+30A0 "゠" */
    0xf8, 0x1, 0xf0,

    /* U+30A1 "ァ" */
    0xfc, 0x13, 0x4f, 0x39, 0x0,

    /* U+30A2 "ア" */
    0xff, 0x80, 0x42, 0x21, 0xf0, 0x80, 0x40, 0x20,
    0xe0,

    /* U+30A3 "ィ" */
    0x8, 0xbd, 0xe1, 0x8,

    /* U+30A4 "イ" */
    0x2, 0x4, 0x8, 0x23, 0x9d, 0x2, 0x4, 0x8,
    0x10,

    /* U+30A5 "ゥ" */
    0x33, 0xf8, 0x42, 0x9, 0xc0,

    /* U+30A6 "ウ" */
    0x18, 0xc, 0x6, 0x1f, 0xf8, 0xc, 0x6, 0x2,
    0x1, 0x3, 0xe, 0x0,

    /* U+30A7 "ェ" */
    0x78, 0xc3, 0xc, 0xfc,

    /* U+30A8 "エ" */
    0x7f, 0x4, 0x2, 0x1, 0x0, 0x80, 0x40, 0x21,
    0xff,

    /* U+30A9 "ォ" */
    0xb, 0xff, 0xce, 0x6a, 0x20,

    /* U+30AA "オ" */
    0x4, 0x2, 0x1, 0x1f, 0xf0, 0xc1, 0xa0, 0xd0,
    0xc8, 0x84, 0x6, 0x0,

    /* U+30AB "カ" */
    0x10, 0x8, 0x1f, 0xef, 0xf1, 0x8, 0x84, 0x42,
    0xc1, 0x87, 0x0,

    /* U+30AC "ガ" */
    0x3, 0x4, 0x41, 0x80, 0xc1, 0x0, 0x81, 0xfe,
    0xff, 0x10, 0x88, 0x44, 0x2c, 0x18, 0x70,

    /* U+30AD "キ" */
    0x8, 0x7f, 0xff, 0xe1, 0x0, 0x87, 0xfc, 0x20,
    0x10, 0x8, 0x4, 0x0,

    /* U+30AE "ギ" */
    0x3, 0x4, 0x41, 0x1, 0xf, 0xff, 0xfc, 0x20,
    0x10, 0xff, 0x84, 0x2, 0x1, 0x0, 0x80,

    /* U+30AF "ク" */
    0x7e, 0x86, 0x8, 0x10, 0x20, 0x41, 0x3c,

    /* U+30B0 "グ" */
    0x3, 0x4, 0x41, 0x0, 0x0, 0x3, 0xf9, 0xd,
    0x6, 0x3, 0x1, 0x80, 0xc0, 0x87, 0x80,

    /* U+30B1 "ケ" */
    0x40, 0x20, 0x10, 0xf, 0xf4, 0x24, 0x10, 0x8,
    0x4, 0x4, 0x1c, 0x0,

    /* U+30B2 "ゲ" */
    0x2, 0x19, 0x4, 0x40, 0x40, 0x40, 0x7f, 0x42,
    0x82, 0x2, 0x2, 0x4, 0x38,

    /* U+30B3 "コ" */
    0xfe, 0x4, 0x8, 0x10, 0x20, 0x40, 0xff,

    /* U+30B4 "ゴ" */
    0x2, 0x11, 0xc, 0x0, 0x0, 0xfe, 0x2, 0x2,
    0x2, 0x2, 0x2, 0x2, 0xfe,

    /* U+30B5 "サ" */
    0x63, 0x31, 0xbf, 0xff, 0xf6, 0x33, 0x18, 0xc,
    0x6, 0x3, 0xe, 0x0,

    /* U+30B6 "ザ" */
    0x3, 0x4, 0x41, 0xc, 0x66, 0x37, 0xff, 0xfe,
    0xc6, 0x63, 0x1, 0x80, 0xc0, 0x61, 0xc0,

    /* U+30B7 "シ" */
    0xf0, 0x7, 0xcf, 0x90, 0x20, 0x41, 0x7c,

    /* U+30B8 "ジ" */
    0x4, 0x24, 0x20, 0xf, 0x1e, 0x0, 0xf9, 0xf2,
    0x4, 0x8, 0x2f, 0x80,

    /* U+30B9 "ス" */
    0xff, 0x1, 0x80, 0xc0, 0x60, 0x40, 0x60, 0x4d,
    0xc1,

    /* U+30BA "ズ" */
    0x3, 0x4, 0x41, 0x0, 0x0, 0x7, 0xf8, 0xc,
    0x6, 0x3, 0x2, 0x3, 0x2, 0x6e, 0x8,

    /* U+30BB "セ" */
    0x40, 0x40, 0x40, 0xff, 0x41, 0x42, 0x40, 0x40,
    0x40, 0x3e,

    /* U+30BC "ゼ" */
    0x2, 0x9, 0x4, 0x40, 0x40, 0x40, 0xff, 0x41,
    0x42, 0x40, 0x40, 0x40, 0x3e,

    /* U+30BD "ソ" */
    0x81, 0x81, 0x81, 0x41, 0x2, 0x2, 0x4, 0x38,

    /* U+30BE "ゾ" */
    0x2, 0x19, 0x4, 0x0, 0x81, 0x81, 0x81, 0xc1,
    0x41, 0x2, 0x2, 0x4, 0x38,

    /* U+30BF "タ" */
    0x7f, 0xa0, 0x5e, 0x30, 0xf0, 0x8, 0x4, 0xc,
    0x78,

    /* U+30C0 "ダ" */
    0x3, 0xc, 0x41, 0x0, 0x0, 0x3, 0xfd, 0x2,
    0xf1, 0x87, 0x80, 0x40, 0x20, 0x63, 0xc0,

    /* U+30C1 "チ" */
    0x3, 0xbe, 0x1, 0x1f, 0xf0, 0x40, 0x20, 0x10,
    0x10, 0x70, 0x0,

    /* U+30C2 "ヂ" */
    0x3, 0x4, 0x41, 0x0, 0x70, 0x3b, 0xe0, 0x11,
    0xff, 0x4, 0x2, 0x1, 0x1, 0x7, 0x0,

    /* U+30C3 "ッ" */
    0xb6, 0xdb, 0x41, 0x9, 0xc0,

    /* U+30C4 "ツ" */
    0x93, 0x26, 0x4c, 0x90, 0x20, 0x41, 0x1c,

    /* U+30C5 "ヅ" */
    0x4, 0x24, 0x20, 0x0, 0x12, 0x64, 0xc9, 0x92,
    0x4, 0x8, 0x23, 0x80,

    /* U+30C6 "テ" */
    0x7f, 0x0, 0x3f, 0xe0, 0x80, 0x40, 0x20, 0x10,
    0x30,

    /* U+30C7 "デ" */
    0x3, 0x4, 0x41, 0x0, 0x0, 0x3, 0xf8, 0x1,
    0xff, 0x4, 0x2, 0x1, 0x0, 0x81, 0x80,

    /* U+30C8 "ト" */
    0x82, 0x8, 0x20, 0xfa, 0x18, 0x20, 0x82, 0x0,

    /* U+30C9 "ド" */
    0x9, 0x91, 0x20, 0x82, 0x8, 0x3e, 0x86, 0x8,
    0x20, 0x80,

    /* U+30CA "ナ" */
    0x4, 0x2, 0x3f, 0xff, 0xf0, 0x40, 0x20, 0x10,
    0x10, 0x70, 0x0,

    /* U+30CB "ニ" */
    0x7f, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x1,
    0xff,

    /* U+30CC "ヌ" */
    0xff, 0x80, 0x40, 0x21, 0x70, 0xb0, 0x20, 0x2c,
    0xe1,

    /* U+30CD "ネ" */
    0x8, 0x4, 0x2, 0x1f, 0xf0, 0x30, 0x60, 0xec,
    0x76, 0xe8, 0x84, 0x0,

    /* U+30CE "ノ" */
    0x2, 0x4, 0x8, 0x10, 0x40, 0x86, 0x70,

    /* U+30CF "ハ" */
    0x44, 0x21, 0x90, 0xc8, 0x18, 0xc, 0x6, 0x2,

    /* U+30D0 "バ" */
    0x2, 0x9, 0x4, 0x0, 0x0, 0x0, 0x64, 0x62,
    0x62, 0x61, 0x81, 0x81, 0x81,

    /* U+30D1 "パ" */
    0x7, 0x82, 0x41, 0xe0, 0x0, 0x0, 0x1, 0x10,
    0x86, 0x43, 0x20, 0x60, 0x30, 0x18, 0x8,

    /* U+30D2 "ヒ" */
    0x80, 0x40, 0x20, 0x10, 0xcf, 0x84, 0x2, 0x1,
    0x0, 0x80, 0x3f, 0xc0,

    /* U+30D3 "ビ" */
    0x3, 0x4, 0x41, 0x90, 0x8, 0x4, 0x2, 0x1d,
    0xf0, 0x80, 0x40, 0x20, 0x10, 0x7, 0xf8,

    /* U+30D4 "ピ" */
    0x7, 0x82, 0x41, 0xf0, 0x8, 0x4, 0x2, 0x1d,
    0xf0, 0x80, 0x40, 0x20, 0x10, 0x7, 0xf8,

    /* U+30D5 "フ" */
    0xff, 0x1, 0x1, 0x1, 0x2, 0x2, 0x4, 0x38,

    /* U+30D6 "ブ" */
    0x2, 0x19, 0x4, 0x0, 0x0, 0xff, 0x1, 0x1,
    0x1, 0x2, 0x2, 0x4, 0x38,

    /* U+30D7 "プ" */
    0x7, 0x5, 0x7, 0x0, 0x0, 0xff, 0x1, 0x1,
    0x1, 0x2, 0x2, 0x4, 0x38,

    /* U+30D8 "ヘ" */
    0x10, 0x34, 0x21, 0x0, 0x60, 0x30, 0x4,

    /* U+30D9 "ベ" */
    0x3, 0x4, 0x41, 0x0, 0x0, 0x0, 0x0, 0x40,
    0xd0, 0x84, 0x1, 0x80, 0xc0, 0x10,

    /* U+30DA "ペ" */
    0x7, 0x82, 0x41, 0xe0, 0x0, 0x0, 0x0, 0x40,
    0xd0, 0x84, 0x1, 0x80, 0xc0, 0x10,

    /* U+30DB "ホ" */
    0x8, 0x4, 0x3f, 0xff, 0xf0, 0x83, 0x59, 0xa6,
    0xd3, 0x69, 0xc4, 0xc0,

    /* U+30DC "ボ" */
    0x3, 0x4, 0x41, 0x1, 0x0, 0x87, 0xff, 0xfe,
    0x10, 0x6b, 0x34, 0x5a, 0x2d, 0x18, 0x88,

    /* U+30DD "ポ" */
    0x7, 0x82, 0x41, 0xe1, 0x0, 0x87, 0xff, 0xfe,
    0x10, 0x6b, 0x34, 0x5a, 0x2d, 0x18, 0x88,

    /* U+30DE "マ" */
    0xff, 0x1, 0x1, 0x43, 0x42, 0x34, 0x8, 0x4,

    /* U+30DF "ミ" */
    0x7c, 0x0, 0x0, 0x0, 0x7c, 0x0, 0x0, 0x0,
    0xf8, 0x7,

    /* U+30E0 "ム" */
    0x10, 0x10, 0x10, 0x10, 0x62, 0x62, 0x81, 0xff,

    /* U+30E1 "メ" */
    0x3, 0x9, 0x84, 0xc1, 0x60, 0x0, 0x20, 0x1c,
    0x31, 0xe0, 0x0,

    /* U+30E2 "モ" */
    0xff, 0x8, 0x4, 0x1f, 0xf1, 0x0, 0x80, 0x40,
    0x1f,

    /* U+30E3 "ャ" */
    0x43, 0xff, 0xd1, 0x49, 0x0,

    /* U+30E4 "ヤ" */
    0x10, 0x3f, 0xff, 0xfc, 0x43, 0x11, 0x4, 0x81,
    0x20, 0x40, 0x10, 0x0,

    /* U+30E5 "ュ" */
    0x78, 0x20, 0x82, 0xfc,

    /* U+30E6 "ユ" */
    0x7c, 0x2, 0x1, 0x0, 0x80, 0x40, 0x23, 0xfe,

    /* U+30E7 "ョ" */
    0xf8, 0x43, 0xf0, 0xfc,

    /* U+30E8 "ヨ" */
    0xff, 0x80, 0x40, 0x27, 0xf0, 0x8, 0x4, 0x3,
    0xff,

    /* U+30E9 "ラ" */
    0x7e, 0x0, 0xff, 0x1, 0x0, 0x2, 0x4, 0x38,

    /* U+30EA "リ" */
    0x83, 0x6, 0xc, 0x18, 0x20, 0x41, 0x1c,

    /* U+30EB "ル" */
    0x68, 0x34, 0x1a, 0xd, 0x6, 0x83, 0x41, 0xa0,
    0xd1, 0x8f, 0x0,

    /* U+30EC "レ" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x61, 0x5c, 0xc0,

    /* U+30ED "ロ" */
    0xff, 0xc0, 0x60, 0x30, 0x18, 0xc, 0x7, 0xff,
    0x1, 0x80, 0x80,

    /* U+30EE "ヮ" */
    0xfe, 0x10, 0x82, 0x70,

    /* U+30EF "ワ" */
    0xff, 0xc0, 0x60, 0x30, 0x18, 0x8, 0x4, 0xc,
    0x78,

    /* U+30F0 "ヰ" */
    0x4, 0x7f, 0xff, 0xec, 0x86, 0x47, 0xfc, 0x10,
    0x8, 0x4, 0x2, 0x0,

    /* U+30F1 "ヱ" */
    0xff, 0x80, 0xc2, 0x61, 0xf0, 0x80, 0x40, 0x21,
    0xff,

    /* U+30F2 "ヲ" */
    0xff, 0x80, 0x40, 0x27, 0xf0, 0x8, 0x4, 0x4,
    0x7c,

    /* U+30F3 "ン" */
    0xf0, 0x80, 0x40, 0x20, 0x10, 0x8, 0x4, 0x5,
    0xfc,

    /* U+30F4 "ヴ" */
    0x3, 0xc, 0x43, 0x3, 0x1, 0x80, 0xc3, 0xff,
    0x1, 0x80, 0xc0, 0x40, 0x20, 0x61, 0xc0,

    /* U+30F5 "ヵ" */
    0x63, 0xff, 0xd9, 0x84, 0x20,

    /* U+30F6 "ヶ" */
    0x61, 0xf7, 0xe2, 0x8, 0x40,

    /* U+30F7 "ヷ" */
    0x3, 0xc, 0x41, 0x0, 0x0, 0x7, 0xfe, 0x3,
    0x1, 0x80, 0xc0, 0x40, 0x20, 0x63, 0xc0,

    /* U+30F8 "ヸ" */
    0x3, 0x4, 0x41, 0x0, 0x8f, 0xff, 0xfd, 0x90,
    0xc8, 0xff, 0x82, 0x1, 0x0, 0x80, 0x40,

    /* U+30F9 "ヹ" */
    0x3, 0x4, 0x41, 0x0, 0x0, 0x7, 0xfc, 0x2,
    0x11, 0xf, 0x84, 0x2, 0x1, 0xf, 0xf8,

    /* U+30FA "ヺ" */
    0x1, 0x6, 0x40, 0x80, 0x0, 0x7, 0xfc, 0x2,
    0x1, 0x3f, 0x80, 0x40, 0x20, 0x23, 0xe0,

    /* U+30FB "・" */
    0xfc,

    /* U+30FC "ー" */
    0xff,

    /* U+30FD "ヽ" */
    0x83, 0x4, 0x20, 0x80,

    /* U+30FE "ヾ" */
    0x4, 0x46, 0x62, 0x3, 0x6, 0x2, 0x0,

    /* U+30FF "ヿ" */
    0xfe, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81, 0x2
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 160, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 160, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 8, .adv_w = 160, .box_w = 4, .box_h = 3, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 10, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 160, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 25, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 34, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 42, .adv_w = 160, .box_w = 1, .box_h = 3, .ofs_x = 4, .ofs_y = 6},
    {.bitmap_index = 43, .adv_w = 160, .box_w = 5, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 160, .box_w = 5, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 53, .adv_w = 160, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 59, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 160, .box_w = 2, .box_h = 5, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 66, .adv_w = 160, .box_w = 5, .box_h = 1, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 67, .adv_w = 160, .box_w = 3, .box_h = 2, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 68, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 77, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 160, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 108, .adv_w = 160, .box_w = 10, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 117, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 160, .box_w = 3, .box_h = 7, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 160, .box_w = 2, .box_h = 8, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 162, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 168, .adv_w = 160, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 171, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 177, .adv_w = 160, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 187, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 198, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 216, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 225, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 330, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 366, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 375, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 160, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 160, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 160, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 443, .adv_w = 160, .box_w = 4, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 160, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 9},
    {.bitmap_index = 450, .adv_w = 160, .box_w = 9, .box_h = 1, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 452, .adv_w = 160, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 453, .adv_w = 160, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 160, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 160, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 499, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 505, .adv_w = 160, .box_w = 1, .box_h = 7, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 506, .adv_w = 160, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 510, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 160, .box_w = 1, .box_h = 8, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 160, .box_w = 9, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 525, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 530, .adv_w = 160, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 536, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 543, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 550, .adv_w = 160, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 160, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 160, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 573, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 578, .adv_w = 160, .box_w = 9, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 585, .adv_w = 160, .box_w = 10, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 593, .adv_w = 160, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 599, .adv_w = 160, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 605, .adv_w = 160, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 610, .adv_w = 160, .box_w = 1, .box_h = 13, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 612, .adv_w = 160, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 617, .adv_w = 160, .box_w = 7, .box_h = 2, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 619, .adv_w = 160, .box_w = 5, .box_h = 9, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 631, .adv_w = 160, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 639, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 646, .adv_w = 160, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 652, .adv_w = 160, .box_w = 1, .box_h = 13, .ofs_x = 4, .ofs_y = -1},
    {.bitmap_index = 654, .adv_w = 160, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 664, .adv_w = 160, .box_w = 4, .box_h = 1, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 665, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 676, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 684, .adv_w = 160, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 687, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 3},
    {.bitmap_index = 698, .adv_w = 160, .box_w = 6, .box_h = 1, .ofs_x = 0, .ofs_y = 7},
    {.bitmap_index = 699, .adv_w = 160, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 703, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 708, .adv_w = 160, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = 6},
    {.bitmap_index = 709, .adv_w = 160, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 717, .adv_w = 160, .box_w = 3, .box_h = 2, .ofs_x = 4, .ofs_y = 2},
    {.bitmap_index = 718, .adv_w = 160, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 719, .adv_w = 160, .box_w = 8, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 725, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 734, .adv_w = 160, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 744, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 753, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 762, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 771, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 780, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 789, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 798, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 807, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 818, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 827, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 836, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 845, .adv_w = 160, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 855, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 861, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 867, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 873, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 879, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 888, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 897, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 906, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 915, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 924, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 933, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 942, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 947, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 956, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 965, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 974, .adv_w = 160, .box_w = 10, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 984, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 993, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1002, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1011, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1018, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1025, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1032, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1039, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1046, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1053, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1060, .adv_w = 160, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1066, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1073, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1080, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1089, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1096, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1103, .adv_w = 160, .box_w = 2, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1105, .adv_w = 160, .box_w = 2, .box_h = 8, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 1107, .adv_w = 160, .box_w = 3, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1110, .adv_w = 160, .box_w = 3, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1113, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1121, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1128, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1135, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1142, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1149, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1156, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1163, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1168, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1177, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1183, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1189, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1195, .adv_w = 160, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1201, .adv_w = 160, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1208, .adv_w = 160, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1216, .adv_w = 160, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1223, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1230, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1241, .adv_w = 160, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1245, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1253, .adv_w = 160, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1258, .adv_w = 160, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1266, .adv_w = 160, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1271, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1283, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1290, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1301, .adv_w = 160, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1310, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1323, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1334, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1349, .adv_w = 160, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1356, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1368, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1380, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1393, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1402, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1415, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1427, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1442, .adv_w = 160, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1450, .adv_w = 160, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1459, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1470, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1485, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1497, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1512, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1524, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1539, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1551, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1566, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1578, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1593, .adv_w = 160, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1597, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1604, .adv_w = 160, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1616, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1625, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1640, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1652, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1667, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1679, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1690, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1701, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1713, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1721, .adv_w = 160, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1731, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1744, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1757, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1765, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1778, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1791, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1800, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1813, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1828, .adv_w = 160, .box_w = 9, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1835, .adv_w = 160, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1849, .adv_w = 160, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1863, .adv_w = 160, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1873, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1886, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1899, .adv_w = 160, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1908, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1920, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1932, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1944, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1956, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1963, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1975, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1982, .adv_w = 160, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1992, .adv_w = 160, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 1998, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2010, .adv_w = 160, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2018, .adv_w = 160, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2025, .adv_w = 160, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2035, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2047, .adv_w = 160, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2057, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2062, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2074, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2083, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2095, .adv_w = 160, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2102, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2113, .adv_w = 160, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2125, .adv_w = 160, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2131, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2136, .adv_w = 0, .box_w = 5, .box_h = 3, .ofs_x = -10, .ofs_y = 9},
    {.bitmap_index = 2138, .adv_w = 0, .box_w = 4, .box_h = 3, .ofs_x = -10, .ofs_y = 9},
    {.bitmap_index = 2140, .adv_w = 160, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 2143, .adv_w = 160, .box_w = 4, .box_h = 4, .ofs_x = 0, .ofs_y = 5},
    {.bitmap_index = 2145, .adv_w = 160, .box_w = 4, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2148, .adv_w = 160, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2156, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2168, .adv_w = 160, .box_w = 5, .box_h = 4, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 2171, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2176, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2185, .adv_w = 160, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2189, .adv_w = 160, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2198, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2203, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2215, .adv_w = 160, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2219, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2228, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2233, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2245, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2256, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2271, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2283, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2298, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2305, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2320, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2332, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2345, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2352, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 2365, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2377, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2392, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2399, .adv_w = 160, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2411, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2420, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2435, .adv_w = 160, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2445, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2458, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2466, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2479, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2488, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2503, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2514, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2529, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2534, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2541, .adv_w = 160, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2553, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2562, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2577, .adv_w = 160, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2585, .adv_w = 160, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2595, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2606, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2615, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2624, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2636, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2643, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2651, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2664, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2679, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2691, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2706, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2721, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2729, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2742, .adv_w = 160, .box_w = 8, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2755, .adv_w = 160, .box_w = 9, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2762, .adv_w = 160, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2776, .adv_w = 160, .box_w = 9, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2790, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2802, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2817, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2832, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2840, .adv_w = 160, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2850, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2858, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2869, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2878, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2883, .adv_w = 160, .box_w = 10, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2895, .adv_w = 160, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2899, .adv_w = 160, .box_w = 9, .box_h = 7, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2907, .adv_w = 160, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2911, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2920, .adv_w = 160, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2928, .adv_w = 160, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2935, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2946, .adv_w = 160, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2954, .adv_w = 160, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 2965, .adv_w = 160, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2969, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2978, .adv_w = 160, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2990, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 2999, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 3008, .adv_w = 160, .box_w = 9, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3017, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3032, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3037, .adv_w = 160, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3042, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3057, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3072, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 3087, .adv_w = 160, .box_w = 9, .box_h = 13, .ofs_x = -1, .ofs_y = -1},
    {.bitmap_index = 3102, .adv_w = 160, .box_w = 3, .box_h = 2, .ofs_x = 3, .ofs_y = 3},
    {.bitmap_index = 3103, .adv_w = 160, .box_w = 8, .box_h = 1, .ofs_x = 0, .ofs_y = 4},
    {.bitmap_index = 3104, .adv_w = 160, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 3108, .adv_w = 160, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 3115, .adv_w = 160, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -2}
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
const lv_font_t pokemon_font_10 = {
#else
lv_font_t pokemon_font_10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if POKEMON_FONT_10*/

