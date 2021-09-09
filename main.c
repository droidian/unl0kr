#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/reboot.h>
#include <sys/time.h>

#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"

#include "libinput_device_discovery.h"
#include "libinput_multi.h"
#include "libinput_xkb.h"
#include "layouts.h"

// Custom fonts

LV_FONT_DECLARE(montserrat_extended_32);

// Custom symbols

#define SYMBOL_ADJUST "\xef\x81\x82" // 0xF042 https://fontawesome.com/v5.15/icons/adjust?style=solid

// Mouse cursor image (from https://github.com/lvgl/lv_sim_emscripten/blob/master/mouse_cursor_icon.c)

const uint8_t mouse_cursor_icon_map[] = {
#if LV_COLOR_DEPTH == 1 || LV_COLOR_DEPTH == 8
    /*Pixel format: Alpha 8 bit, Red: 3 bit, Green: 3 bit, Blue: 2 bit*/
    0x24, 0xb8, 0x24, 0xc8, 0x00, 0x13, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xcc, 0xdb, 0xff, 0x49, 0xcc, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xc8, 0xff, 0xff, 0xff, 0xff, 0x49, 0xe0, 0x00, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xcb, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0x6d, 0xf3, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xcb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0x00, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xcb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0xb6, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xcb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0xff, 0x24, 0xab, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xcb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0x24, 0xbb, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xcc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0x49, 0xd8, 0x00, 0x37, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xcc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6d, 0xef, 0x00, 0x4f, 0x00, 0x00,
    0x49, 0xcc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x92, 0xff, 0x00, 0x6b,
    0x49, 0xcc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0x92, 0xf7, 0x92, 0xf8, 0x6e, 0xfb, 0x92, 0xf8, 0x6d, 0xff, 0x00, 0xb3,
    0x49, 0xcc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0x24, 0xb7, 0x00, 0x1b, 0x00, 0x14, 0x00, 0x13, 0x00, 0x0c, 0x25, 0x07,
    0x49, 0xcc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6e, 0xf0, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0xcc, 0xff, 0xff, 0xff, 0xff, 0x49, 0xd8, 0x00, 0x78, 0x92, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xff, 0x00, 0x8b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x6d, 0xd3, 0xff, 0xff, 0x6d, 0xef, 0x00, 0x34, 0x00, 0x00, 0x49, 0xc7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x6d, 0xdc, 0x00, 0x14, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00,
    0x49, 0xe0, 0x6d, 0xff, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x92, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0xff, 0x00, 0x78, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00,
    0x00, 0x68, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x49, 0xd0, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0x6d, 0xd8, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6f, 0xb7, 0xff, 0xff, 0xff, 0x92, 0xff, 0x49, 0xac, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x03, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x25, 0xd7, 0x49, 0xc7, 0x00, 0x47, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP == 0
    /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit*/
    0xc3, 0x18, 0xb8, 0xe4, 0x20, 0xc8, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x49, 0x4a, 0xcc, 0x96, 0xb5, 0xff, 0xc7, 0x39, 0xcc, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe7, 0x39, 0xc8, 0xbf, 0xff, 0xff, 0xfb, 0xde, 0xff, 0x28, 0x42, 0xe0, 0x00, 0x00, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x41, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe7, 0x39, 0xcb, 0x3d, 0xef, 0xff, 0xff, 0xff, 0xfc, 0x3d, 0xef, 0xff, 0xcb, 0x5a, 0xf3, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe7, 0x39, 0xcb, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0x8e, 0x73, 0xff, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe8, 0x41, 0xcb, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x51, 0x8c, 0xff, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xd3, 0x9c, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xe8, 0x41, 0xcb, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x14, 0xa5, 0xff, 0xa2, 0x10, 0xab, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x42, 0xcb, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd7, 0xbd, 0xff, 0x04, 0x21, 0xbb, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x42, 0xcc, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x59, 0xce, 0xff, 0xe8, 0x41, 0xd8, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x42, 0xcc, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe6, 0xff, 0xab, 0x5a, 0xef, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00,
    0x08, 0x42, 0xcc, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xf7, 0xff, 0xaf, 0x7b, 0xff, 0x00, 0x00, 0x6b,
    0x28, 0x42, 0xcc, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x7a, 0xd6, 0xff, 0x10, 0x84, 0xf7, 0xae, 0x73, 0xf8, 0x6e, 0x73, 0xfb, 0x8e, 0x73, 0xf8, 0xcb, 0x5a, 0xff, 0x61, 0x08, 0xb3,
    0x28, 0x42, 0xcc, 0x7d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x59, 0xce, 0xff, 0xa2, 0x10, 0xb7, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x14, 0x00, 0x00, 0x13, 0x00, 0x00, 0x0c, 0x45, 0x29, 0x07,
    0x29, 0x4a, 0xcc, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xdb, 0xde, 0xff, 0xec, 0x62, 0xff, 0x1c, 0xe7, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x0c, 0x63, 0xf0, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x29, 0x4a, 0xcc, 0xdf, 0xff, 0xff, 0x7d, 0xef, 0xff, 0x49, 0x4a, 0xd8, 0x00, 0x00, 0x78, 0x51, 0x8c, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x38, 0xc6, 0xff, 0x00, 0x00, 0x8b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0xcb, 0x5a, 0xd3, 0xdb, 0xde, 0xff, 0xec, 0x62, 0xef, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0xe7, 0x39, 0xc7, 0x5d, 0xef, 0xff, 0xff, 0xff, 0xff, 0xbe, 0xf7, 0xff, 0xaa, 0x52, 0xdc, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0xe8, 0x41, 0xe0, 0xaa, 0x52, 0xff, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x72, 0x94, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x96, 0xb5, 0xff, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x61, 0x08, 0x04, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x68, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x69, 0x4a, 0xd0, 0x7d, 0xef, 0xff, 0xff, 0xff, 0xfc, 0xbe, 0xf7, 0xff, 0xaa, 0x52, 0xd8, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe4, 0x20, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6f, 0x75, 0xad, 0xff, 0xbf, 0xff, 0xff, 0x10, 0x84, 0xff, 0x86, 0x31, 0xac, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x41, 0x08, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x66, 0x31, 0xd7, 0xc7, 0x39, 0xc7, 0x00, 0x00, 0x47, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#endif
#if LV_COLOR_DEPTH == 16 && LV_COLOR_16_SWAP != 0
    /*Pixel format: Alpha 8 bit, Red: 5 bit, Green: 6 bit, Blue: 5 bit  BUT the 2  color bytes are swapped*/
    0x18, 0xc3, 0xb8, 0x20, 0xe4, 0xc8, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x4a, 0x49, 0xcc, 0xb5, 0x96, 0xff, 0x39, 0xc7, 0xcc, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x39, 0xe7, 0xc8, 0xff, 0xbf, 0xff, 0xde, 0xfb, 0xff, 0x42, 0x28, 0xe0, 0x00, 0x00, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x41, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x39, 0xe7, 0xcb, 0xef, 0x3d, 0xff, 0xff, 0xff, 0xfc, 0xef, 0x3d, 0xff, 0x5a, 0xcb, 0xf3, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x39, 0xe7, 0xcb, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0x73, 0x8e, 0xff, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x41, 0xe8, 0xcb, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8c, 0x51, 0xff, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x9c, 0xd3, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x41, 0xe8, 0xcb, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa5, 0x14, 0xff, 0x10, 0xa2, 0xab, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x42, 0x08, 0xcb, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xd7, 0xff, 0x21, 0x04, 0xbb, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x42, 0x08, 0xcc, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0x59, 0xff, 0x41, 0xe8, 0xd8, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x42, 0x08, 0xcc, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xe6, 0xfc, 0xff, 0x5a, 0xab, 0xef, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00,
    0x42, 0x08, 0xcc, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0x7b, 0xaf, 0xff, 0x00, 0x00, 0x6b,
    0x42, 0x28, 0xcc, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd6, 0x7a, 0xff, 0x84, 0x10, 0xf7, 0x73, 0xae, 0xf8, 0x73, 0x6e, 0xfb, 0x73, 0x8e, 0xf8, 0x5a, 0xcb, 0xff, 0x08, 0x61, 0xb3,
    0x42, 0x28, 0xcc, 0xef, 0x7d, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0x59, 0xff, 0x10, 0xa2, 0xb7, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x14, 0x00, 0x00, 0x13, 0x00, 0x00, 0x0c, 0x29, 0x45, 0x07,
    0x4a, 0x29, 0xcc, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xde, 0xdb, 0xff, 0x62, 0xec, 0xff, 0xe7, 0x1c, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x63, 0x0c, 0xf0, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x4a, 0x29, 0xcc, 0xff, 0xdf, 0xff, 0xef, 0x7d, 0xff, 0x4a, 0x49, 0xd8, 0x00, 0x00, 0x78, 0x8c, 0x51, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc6, 0x38, 0xff, 0x00, 0x00, 0x8b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x5a, 0xcb, 0xd3, 0xde, 0xdb, 0xff, 0x62, 0xec, 0xef, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x39, 0xe7, 0xc7, 0xef, 0x5d, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xbe, 0xff, 0x52, 0xaa, 0xdc, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00,
    0x41, 0xe8, 0xe0, 0x52, 0xaa, 0xff, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x94, 0x72, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb5, 0x96, 0xff, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x08, 0x61, 0x04, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x68, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x4a, 0x69, 0xd0, 0xef, 0x7d, 0xff, 0xff, 0xff, 0xfc, 0xf7, 0xbe, 0xff, 0x52, 0xaa, 0xd8, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0xe4, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6f, 0xad, 0x75, 0xff, 0xff, 0xbf, 0xff, 0x84, 0x10, 0xff, 0x31, 0x86, 0xac, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x08, 0x41, 0x03, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x31, 0x66, 0xd7, 0x39, 0xc7, 0xc7, 0x00, 0x00, 0x47, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#endif
#if LV_COLOR_DEPTH == 32
    0x19, 0x19, 0x19, 0xb8, 0x1e, 0x1e, 0x1e, 0xc8, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x48, 0x48, 0x48, 0xcc, 0xb2, 0xb2, 0xb2, 0xff, 0x3a, 0x3a, 0x3a, 0xcc, 0x00, 0x00, 0x00, 0x24, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3b, 0x3b, 0x3b, 0xc8, 0xf6, 0xf6, 0xf6, 0xff, 0xdc, 0xdc, 0xdc, 0xff, 0x43, 0x43, 0x43, 0xe0, 0x00, 0x00, 0x00, 0x3b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0a, 0x0a, 0x0a, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3b, 0x3b, 0x3b, 0xcb, 0xe6, 0xe6, 0xe6, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xe5, 0xe5, 0xe5, 0xff, 0x59, 0x59, 0x59, 0xf3, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3c, 0x3c, 0x3c, 0xcb, 0xe9, 0xe9, 0xe9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf5, 0xf5, 0xf5, 0xff, 0x72, 0x72, 0x72, 0xff, 0x00, 0x00, 0x00, 0x73, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3d, 0x3d, 0x3d, 0xcb, 0xe9, 0xe9, 0xe9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x8a, 0x8a, 0x8a, 0xff, 0x00, 0x00, 0x00, 0x90, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x99, 0x99, 0x99, 0x00, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3e, 0x3e, 0x3e, 0xcb, 0xe9, 0xe9, 0xe9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xa2, 0xa2, 0xa2, 0xff, 0x13, 0x13, 0x13, 0xab, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x3f, 0x3f, 0x3f, 0xcb, 0xe9, 0xe9, 0xe9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb7, 0xb7, 0xb7, 0xff, 0x1f, 0x1f, 0x1f, 0xbb, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x41, 0x41, 0x41, 0xcc, 0xea, 0xea, 0xea, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xca, 0xca, 0xca, 0xff, 0x3d, 0x3d, 0x3d, 0xd8, 0x00, 0x00, 0x00, 0x37, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x41, 0x41, 0x41, 0xcc, 0xea, 0xea, 0xea, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xde, 0xde, 0xde, 0xff, 0x56, 0x56, 0x56, 0xef, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00,
    0x42, 0x42, 0x42, 0xcc, 0xea, 0xea, 0xea, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf3, 0xf3, 0xf3, 0xff, 0x76, 0x76, 0x76, 0xff, 0x00, 0x00, 0x00, 0x6b,
    0x43, 0x43, 0x43, 0xcc, 0xea, 0xea, 0xea, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xce, 0xce, 0xce, 0xff, 0x80, 0x80, 0x80, 0xf7, 0x74, 0x74, 0x74, 0xf8, 0x6d, 0x6d, 0x6d, 0xfb, 0x72, 0x72, 0x72, 0xf8, 0x57, 0x57, 0x57, 0xff, 0x0c, 0x0c, 0x0c, 0xb3,
    0x44, 0x44, 0x44, 0xcc, 0xeb, 0xeb, 0xeb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xfb, 0xfb, 0xfb, 0xff, 0xfe, 0xfe, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc9, 0xc9, 0xc9, 0xff, 0x13, 0x13, 0x13, 0xb7, 0x00, 0x00, 0x00, 0x1b, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x0c, 0x29, 0x29, 0x29, 0x07,
    0x45, 0x45, 0x45, 0xcc, 0xe8, 0xe8, 0xe8, 0xff, 0xff, 0xff, 0xff, 0xff, 0xd9, 0xd9, 0xd9, 0xff, 0x5e, 0x5e, 0x5e, 0xff, 0xe2, 0xe2, 0xe2, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x62, 0x62, 0x62, 0xf0, 0x00, 0x00, 0x00, 0x13, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x45, 0x45, 0x45, 0xcc, 0xf9, 0xf9, 0xf9, 0xff, 0xec, 0xec, 0xec, 0xff, 0x4a, 0x4a, 0x4a, 0xd8, 0x00, 0x00, 0x00, 0x78, 0x8a, 0x8a, 0x8a, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xc3, 0xc3, 0xc3, 0xff, 0x00, 0x00, 0x00, 0x8b, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x58, 0x58, 0x58, 0xd3, 0xd9, 0xd9, 0xd9, 0xff, 0x5e, 0x5e, 0x5e, 0xef, 0x00, 0x00, 0x00, 0x34, 0x00, 0x00, 0x00, 0x00, 0x3b, 0x3b, 0x3b, 0xc7, 0xe9, 0xe9, 0xe9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xf4, 0xf4, 0xf4, 0xff, 0x54, 0x54, 0x54, 0xdc, 0x00, 0x00, 0x00, 0x14, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00,
    0x3e, 0x3e, 0x3e, 0xe0, 0x54, 0x54, 0x54, 0xff, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x57, 0x8e, 0x8e, 0x8e, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xb0, 0xb0, 0xb0, 0xff, 0x00, 0x00, 0x00, 0x78, 0x00, 0x00, 0x00, 0x00, 0x0c, 0x0c, 0x0c, 0x04, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x68, 0x00, 0x00, 0x00, 0x4f, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x10, 0x4c, 0x4c, 0x4c, 0xd0, 0xec, 0xec, 0xec, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf4, 0xf4, 0xf4, 0xff, 0x53, 0x53, 0x53, 0xd8, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1e, 0x1e, 0x1e, 0x00, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x6f, 0xab, 0xab, 0xab, 0xff, 0xf6, 0xf6, 0xf6, 0xff, 0x80, 0x80, 0x80, 0xff, 0x31, 0x31, 0x31, 0xac, 0x00, 0x00, 0x00, 0x17, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x09, 0x09, 0x09, 0x03, 0x02, 0x02, 0x02, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x2e, 0x2e, 0x2e, 0xd7, 0x38, 0x38, 0x38, 0xc7, 0x00, 0x00, 0x00, 0x47, 0x00, 0x00, 0x00, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#endif
};

lv_img_dsc_t mouse_cursor_icon = {
    .header.always_zero = 0,
    .header.w = 14,
    .header.h = 20,
    .data_size = 280 * LV_IMG_PX_SIZE_ALPHA_BYTE,
    .header.cf = LV_IMG_CF_TRUE_COLOR_ALPHA,
    .data = mouse_cursor_icon_map,
};

// Global variables

bool is_dark_theme = false;
bool is_password_hidden = true;

lv_obj_t *textarea = NULL;
lv_obj_t *keyboard = NULL;

lv_style_t style_text_normal;

char *special_layer_trigger = NULL;

// Helpers

void set_theme(bool is_dark);

void set_theme(bool is_dark) {
    lv_theme_default_init(
            NULL, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_CYAN), is_dark, &montserrat_extended_32);
}

void set_password_hidden(bool is_disclosed);

void set_password_hidden(bool is_disclosed) {
    lv_textarea_set_password_mode(textarea, is_password_hidden);
}

// Event callbacks

void keyboard_event_ready_cb(lv_event_t *e);

void keyboard_event_ready_cb(lv_event_t *e) {
    lv_obj_t *obj = lv_keyboard_get_textarea(lv_event_get_target(e));
    char *password = lv_textarea_get_text(obj);
    printf("You entered %s\n", password);
    abort();
}

void keyboard_event_cancel_cb(lv_event_t *e);

void keyboard_event_cancel_cb(lv_event_t *e) {
    abort();
}

void keyboard_event_value_changed_cb(lv_event_t * e);

void keyboard_event_value_changed_cb(lv_event_t * e) {
    lv_obj_t *obj = lv_event_get_target(e);

    uint16_t btn_id = lv_btnmatrix_get_selected_btn(obj);
    if(btn_id == LV_BTNMATRIX_BTN_NONE) return;

    const char * txt = lv_btnmatrix_get_btn_text(obj, lv_btnmatrix_get_selected_btn(obj));
    if(txt == NULL) return;

    if(strcmp(txt, special_layer_trigger) == 0) {
        lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_NUMBER);
    } else {
        lv_keyboard_def_event_cb(e);
    }
}

void discloser_event_cb(lv_event_t *e);

void discloser_event_cb(lv_event_t *e) {
    if(lv_event_get_code(e) == LV_EVENT_VALUE_CHANGED) {
        is_password_hidden = !is_password_hidden;
        set_password_hidden(is_password_hidden);
    }
}

void theme_switcher_event_cb(lv_event_t *e);

void theme_switcher_event_cb(lv_event_t *e) {
    if(lv_event_get_code(e) == LV_EVENT_VALUE_CHANGED) {
        is_dark_theme = !is_dark_theme;
        set_theme(is_dark_theme);
    }
}

void keymap_dropdown_event_cb(lv_event_t *e);

void keymap_dropdown_event_cb(lv_event_t *e) {
    switch (lv_event_get_code(e)) {
        case LV_EVENT_READY: {
            lv_obj_add_style(lv_dropdown_get_list(lv_event_get_target(e)), &style_text_normal, 0);
            break;
        }
        case LV_EVENT_VALUE_CHANGED: {
            uint16_t idx = lv_dropdown_get_selected(lv_event_get_target(e));
            apply_layout(keyboard, idx);
            special_layer_trigger = get_special_layer_trigger(idx);
            break;
        }
        default:
            break;
    }
}

void mbox_event_cb(lv_event_t *e);

void mbox_event_cb(lv_event_t *e) {
    lv_obj_t *obj = lv_event_get_current_target(e);
    if (strcmp(lv_msgbox_get_active_btn_text(obj), "Yes") == 0) {
        abort();
        // TODO: actually shut down
        // sync();
        // reboot(RB_POWER_OFF);
    }
    lv_msgbox_close(obj);
}

void power_btn_event_cb(lv_event_t *e);

void power_btn_event_cb(lv_event_t *e) {
    static const char *btns[] ={ "Yes", "No", "" };
    lv_obj_t * mbox = lv_msgbox_create(NULL, NULL, "Do you want to shutdown the device?", btns, false);
    lv_obj_add_event_cb(mbox, mbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_center(mbox);
}


// Main

int main(void)
{
    // Initialise lvgl, framebuffer driver and XKB system
    lv_init(); 
    fbdev_init();
    libinput_xkb_init();

    // Query display size
    uint32_t hor_res;
    uint32_t ver_res;
	fbdev_get_sizes(&hor_res, &ver_res);

    // hor_res = ver_res * 0.6; /* To simulate mobile screen */

    // Prepare display buffer
    const size_t buf_size = hor_res * ver_res / 10; // At least 1/10 of the display size is recommended
    lv_disp_draw_buf_t disp_buf;
    lv_color_t *buf = (lv_color_t *)malloc(buf_size * sizeof(lv_color_t));
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, buf_size);    

    // Initialise display driver
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &disp_buf;
    disp_drv.flush_cb = fbdev_flush;
    disp_drv.hor_res = hor_res;
    disp_drv.ver_res = ver_res;
    lv_disp_drv_register(&disp_drv);

    // Connect keyboards
    #define MAX_KEYBOARDS 3
    char keyboard_devices[MAX_KEYBOARDS][32] = { "", "", "" };
    lv_indev_drv_t keyboard_indev_drvs[MAX_KEYBOARDS];
    lv_indev_t *keyboard_indevs[MAX_KEYBOARDS] = { 0, 0, 0 };
    int num_keyboards = libinput_discover_keyboards(keyboard_devices, MAX_KEYBOARDS);
    for (int i = 0; i < num_keyboards; ++i) {
        printf("found keyboard device %s\n", keyboard_devices[i]);
        lv_indev_drv_init(&keyboard_indev_drvs[i]);
        keyboard_indev_drvs[i].type = LV_INDEV_TYPE_KEYPAD;
        keyboard_indev_drvs[i].read_cb = libinput_multi_read;
        libinput_multi_init_driver(&keyboard_indev_drvs[i]);
        libinput_multi_set_file(&keyboard_indev_drvs[i], keyboard_devices[i]);
        keyboard_indevs[i] = lv_indev_drv_register(&keyboard_indev_drvs[i]);
    }

    // Connect mice and trackpads
    #define MAX_POINTER_DEVICES 4
    char pointer_devices[MAX_POINTER_DEVICES][32] = { "", "", "", "" };
    lv_indev_drv_t pointer_indev_drvs[MAX_POINTER_DEVICES];
    lv_indev_t *pointer_indevs[MAX_POINTER_DEVICES] = { 0, 0, 0, 0 };
    int num_pointer_devices = libinput_discover_pointer_devices(pointer_devices, MAX_POINTER_DEVICES);
    for (int i = 0; i < num_pointer_devices; ++i) {
        printf("found pointer device %s\n", pointer_devices[i]);
        lv_indev_drv_init(&pointer_indev_drvs[i]);
        pointer_indev_drvs[i].type = LV_INDEV_TYPE_POINTER;
        pointer_indev_drvs[i].read_cb = libinput_multi_read;
        pointer_indev_drvs[i].long_press_repeat_time = USHRT_MAX;
        libinput_multi_init_driver(&pointer_indev_drvs[i]);
        libinput_multi_set_file(&pointer_indev_drvs[i], pointer_devices[i]);
        pointer_indevs[i] = lv_indev_drv_register(&pointer_indev_drvs[i]);
    }

    // Connect touchscreens
    #define MAX_TOUCHSCREENS 1
    char touchscreens[MAX_TOUCHSCREENS][32] = { "" };
    lv_indev_drv_t touchscreen_indev_drvs[MAX_TOUCHSCREENS];
    lv_indev_t *touchscreen_indevs[MAX_TOUCHSCREENS] = { 0 };
    int num_touchscreens = libinput_discover_touchscreens(touchscreens, MAX_TOUCHSCREENS);
    for (int i = 0; i < num_touchscreens; ++i) {
        printf("found touchscreen %s\n", touchscreens[i]);
        lv_indev_drv_init(&touchscreen_indev_drvs[i]);
        touchscreen_indev_drvs[i].type = LV_INDEV_TYPE_POINTER;
        touchscreen_indev_drvs[i].read_cb = libinput_multi_read;
        touchscreen_indev_drvs[i].long_press_repeat_time = USHRT_MAX;
        libinput_multi_init_driver(&touchscreen_indev_drvs[i]);
        libinput_multi_set_file(&touchscreen_indev_drvs[i], touchscreens[i]);
        touchscreen_indevs[i] = lv_indev_drv_register(&touchscreen_indev_drvs[i]);
    }

    // Set mouse cursor
    if (num_pointer_devices > 0) {
        lv_obj_t *cursor_obj = lv_img_create(lv_scr_act());
        lv_img_set_src(cursor_obj, &mouse_cursor_icon);
        for (int i = 0; i < num_pointer_devices; ++i) {
            lv_indev_set_cursor(pointer_indevs[i], cursor_obj);
        }
    }

    // Build the UI...

    // Initialise theme
    set_theme(is_dark_theme);

    // Initialise styles
    lv_style_init(&style_text_normal);
    lv_style_set_text_font(&style_text_normal, &montserrat_extended_32);

    // Figure out a few numbers for sizing and positioning
    const int keyboard_height = ver_res / 3;
    const int row_height = keyboard_height / 4;

    // Textarea
    textarea = lv_textarea_create(lv_scr_act());
    lv_textarea_set_one_line(textarea, true);
    lv_textarea_set_password_mode(textarea, true);
    lv_textarea_set_placeholder_text(textarea, "Enter password...");
    lv_obj_set_size(textarea, hor_res - 60 > 512 ? 512 : hor_res - 60, 64);
    lv_obj_align(textarea, LV_ALIGN_CENTER, 0, ver_res / 2 - keyboard_height - 3 * row_height / 2);
    lv_obj_add_state(textarea, LV_STATE_FOCUSED);
    lv_obj_add_style(textarea, &style_text_normal, 0);

    // Label
    lv_obj_t *spangroup = lv_spangroup_create(lv_scr_act());
    lv_spangroup_set_align(spangroup, LV_TEXT_ALIGN_CENTER);
    lv_spangroup_set_mode(spangroup, LV_SPAN_MODE_BREAK);
    lv_obj_set_size(spangroup, hor_res - 40, 2 * row_height);
    lv_obj_align(spangroup, LV_ALIGN_CENTER, 0, ver_res / 2 - keyboard_height);
    lv_obj_add_style(spangroup, &style_text_normal, 0);
    lv_span_t *span1 = lv_spangroup_new_span(spangroup);
    lv_span_set_text(span1, "Password required to unlock ");
    lv_span_t *span2 = lv_spangroup_new_span(spangroup);
    lv_span_set_text(span2, "/dev/sda1");
    lv_style_set_text_color(&span2->style, lv_palette_main(LV_PALETTE_RED));

    // Keyboard (after textarea / label to draw key popovers over them)
    keyboard = lv_keyboard_create(lv_scr_act());
    lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_TEXT_LOWER);
    // lv_btnmatrix_set_popovers(keyboard, true);
    lv_obj_set_pos(keyboard, 0, 0);
    lv_obj_set_size(keyboard, hor_res, keyboard_height);
    lv_obj_add_style(keyboard, &style_text_normal, 0);

    // Disclosure button
    lv_obj_t *discloser = lv_btn_create(lv_scr_act());
    lv_obj_align(discloser, LV_ALIGN_CENTER, (hor_res - 60 > 512 ? 512 : hor_res - 60) / 2 + 32, ver_res / 2 -keyboard_height - 3 * row_height / 2);
    lv_obj_add_flag(discloser, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_size(discloser, 64, 64);
    lv_obj_t *discloser_label = lv_label_create(discloser);
    lv_obj_center(discloser_label);
    lv_label_set_text(discloser_label, LV_SYMBOL_EYE_OPEN);
    lv_obj_add_event_cb(discloser, discloser_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_style(discloser_label, &style_text_normal, 0);
    set_password_hidden(is_password_hidden);
    
    // Route keyboard input into textarea
    lv_group_t *group = lv_group_create();
    lv_group_add_obj(group, textarea);
    for (int i = 0; i < num_keyboards; ++i) {
        lv_indev_set_group(keyboard_indevs[i], group);
    }

    lv_keyboard_set_textarea(keyboard, textarea); // Connect keyboard and textarea

    // Set up handlers for keyboard events
    lv_obj_remove_event_cb(keyboard, lv_keyboard_def_event_cb);
    lv_obj_add_event_cb(keyboard, keyboard_event_value_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(keyboard, keyboard_event_cancel_cb, LV_EVENT_CANCEL, NULL);
    lv_obj_add_event_cb(keyboard, keyboard_event_ready_cb, LV_EVENT_READY, NULL);

    // Button row
    static lv_coord_t btn_row_col_dsc[] = { 64, 300, LV_GRID_FR(1), 64, LV_GRID_TEMPLATE_LAST };
    static lv_coord_t btn_row_row_dsc[] = { 64, LV_GRID_TEMPLATE_LAST };
    lv_obj_t *btn_row = lv_obj_create(lv_scr_act());
    lv_obj_set_size(btn_row, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_align(btn_row, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_grid_dsc_array(btn_row, btn_row_col_dsc, btn_row_row_dsc);

    // Theme switcher
    lv_obj_t *theme_switcher = lv_btn_create(btn_row);
    lv_obj_add_flag(theme_switcher, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_size(theme_switcher, 64, 64);
    lv_obj_set_grid_cell(theme_switcher, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_t *theme_switcher_label = lv_label_create(theme_switcher);
    lv_obj_add_style(theme_switcher_label, &style_text_normal, 0);
    lv_obj_center(theme_switcher_label);
    lv_label_set_text(theme_switcher_label, SYMBOL_ADJUST);
    lv_obj_add_event_cb(theme_switcher, theme_switcher_event_cb, LV_EVENT_ALL, NULL);

    // Keymap dropdown
    lv_obj_t *dropdown = lv_dropdown_create(btn_row);
    lv_dropdown_set_options(dropdown, get_layout_names());
    lv_obj_set_height(dropdown, 64);
    lv_obj_set_width(dropdown, 300);
    lv_obj_set_grid_cell(dropdown, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_add_style(dropdown, &style_text_normal, 0);
    lv_obj_add_event_cb(dropdown, keymap_dropdown_event_cb, LV_EVENT_ALL, NULL);

    // Power button
    lv_obj_t *power_btn = lv_btn_create(btn_row);
    lv_obj_set_size(power_btn, 64, 64);
    lv_obj_set_grid_cell(power_btn, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_t *power_btn_label = lv_label_create(power_btn);
    lv_obj_add_style(power_btn_label, &style_text_normal, 0);
    lv_obj_center(power_btn_label);
    lv_label_set_text(power_btn_label, LV_SYMBOL_POWER);
    lv_obj_add_event_cb(power_btn, power_btn_event_cb, LV_EVENT_CLICKED, NULL);

    // Apply default layout
    apply_layout(keyboard, 0);
    special_layer_trigger = get_special_layer_trigger(0);

    // Run lvgl in tickless mode
    while(1) {
        lv_task_handler();
        usleep(5000);
    }

    return 0;
}

// Tick generator

uint32_t custom_tick_get(void)
{
    static uint64_t start_ms = 0;
    if (start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
