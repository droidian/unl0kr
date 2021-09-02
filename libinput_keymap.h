/**
 * @file libinput_keymap.h
 *
 */

#ifndef LVGL_LIBINPUT_KEYMAP_H
#define LVGL_LIBINPUT_KEYMAP_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
// #ifndef LV_DRV_NO_CONF
// #ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
// #else
// #include "../../lv_drv_conf.h"
// #endif
// #endif

#if USE_LIBINPUT || USE_BSD_LIBINPUT

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

#define LV_NUM_KEYS 54
#define LV_NUM_KEYS_MAPPED 47

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    LV_MAPPED_KEY_NONE       = -1,
    LV_MAPPED_KEY_GRAVE      = 0,
    LV_MAPPED_KEY_1          = 1,
    LV_MAPPED_KEY_2          = 2,
    LV_MAPPED_KEY_3          = 3,
    LV_MAPPED_KEY_4          = 4,
    LV_MAPPED_KEY_5          = 5,
    LV_MAPPED_KEY_6          = 6,
    LV_MAPPED_KEY_7          = 7,
    LV_MAPPED_KEY_8          = 8,
    LV_MAPPED_KEY_9          = 9,
    LV_MAPPED_KEY_0          = 10,
    LV_MAPPED_KEY_MINUS      = 11,
    LV_MAPPED_KEY_EQUAL      = 12,
    LV_MAPPED_KEY_Q          = 13,
    LV_MAPPED_KEY_W          = 14,
    LV_MAPPED_KEY_E          = 15,
    LV_MAPPED_KEY_R          = 16,
    LV_MAPPED_KEY_T          = 17,
    LV_MAPPED_KEY_Y          = 18,
    LV_MAPPED_KEY_U          = 19,
    LV_MAPPED_KEY_I          = 20,
    LV_MAPPED_KEY_O          = 21,
    LV_MAPPED_KEY_P          = 22,
    LV_MAPPED_KEY_LEFTBRACE  = 23,
    LV_MAPPED_KEY_RIGHTBRACE = 24,
    LV_MAPPED_KEY_BACKSLASH  = 25,
    LV_MAPPED_KEY_A          = 26,
    LV_MAPPED_KEY_S          = 27,
    LV_MAPPED_KEY_D          = 28,
    LV_MAPPED_KEY_F          = 29,
    LV_MAPPED_KEY_G          = 30,
    LV_MAPPED_KEY_H          = 31,
    LV_MAPPED_KEY_J          = 32,
    LV_MAPPED_KEY_K          = 33,
    LV_MAPPED_KEY_L          = 34,
    LV_MAPPED_KEY_SEMICOLON  = 35,
    LV_MAPPED_KEY_APOSTROPHE = 36,
    LV_MAPPED_KEY_Z          = 37,
    LV_MAPPED_KEY_X          = 38,
    LV_MAPPED_KEY_C          = 39,
    LV_MAPPED_KEY_V          = 40,
    LV_MAPPED_KEY_B          = 41,
    LV_MAPPED_KEY_N          = 42,
    LV_MAPPED_KEY_M          = 43,
    LV_MAPPED_KEY_COMMA      = 44,
    LV_MAPPED_KEY_DOT        = 45,
    LV_MAPPED_KEY_SLASH      = 46
} MappedKey;

/**********************
 *  STATIC VARIABLES
 **********************/

extern const MappedKey mapped_keys[LV_NUM_KEYS]; 
extern const char keymap_lower[LV_NUM_KEYS_MAPPED];
extern const char keymap_upper[LV_NUM_KEYS_MAPPED];

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**********************
 *      MACROS
 **********************/

#endif /* USE_LIBINPUT || USE_BSD_LIBINPUT */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LVGL_LIBINPUT_KEYMAP_H */
