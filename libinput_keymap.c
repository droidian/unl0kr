/**
 * @file libinput_keymap.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "libinput_keymap.h"
#if USE_LIBINPUT || USE_BSD_LIBINPUT

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
 
/**********************
 *  STATIC VARIABLES
 **********************/
const MappedKey mapped_keys[LV_NUM_KEYS] = {
    LV_MAPPED_KEY_NONE,       // KEY_RESERVED
    LV_MAPPED_KEY_NONE,       // KEY_ESC
    LV_MAPPED_KEY_1,          // KEY_1
    LV_MAPPED_KEY_2,          // KEY_2
    LV_MAPPED_KEY_3,          // KEY_3
    LV_MAPPED_KEY_4,          // KEY_4
    LV_MAPPED_KEY_5,          // KEY_5
    LV_MAPPED_KEY_6,          // KEY_6
    LV_MAPPED_KEY_7,          // KEY_7
    LV_MAPPED_KEY_8,          // KEY_8
    LV_MAPPED_KEY_9,          // KEY_9
    LV_MAPPED_KEY_0,          // KEY_0
    LV_MAPPED_KEY_MINUS,      // KEY_MINUS
    LV_MAPPED_KEY_EQUAL,      // KEY_EQUAL
    LV_MAPPED_KEY_NONE,       // KEY_BACKSPACE
    LV_MAPPED_KEY_NONE,       // KEY_TAB
    LV_MAPPED_KEY_Q,          // KEY_Q
    LV_MAPPED_KEY_W,          // KEY_W
    LV_MAPPED_KEY_E,          // KEY_E
    LV_MAPPED_KEY_R,          // KEY_R
    LV_MAPPED_KEY_T,          // KEY_T
    LV_MAPPED_KEY_Y,          // KEY_Y
    LV_MAPPED_KEY_U,          // KEY_U
    LV_MAPPED_KEY_I,          // KEY_I
    LV_MAPPED_KEY_O,          // KEY_O
    LV_MAPPED_KEY_P,          // KEY_P
    LV_MAPPED_KEY_LEFTBRACE,  // KEY_LEFTBRACE
    LV_MAPPED_KEY_RIGHTBRACE, // KEY_RIGHTBRACE
    LV_MAPPED_KEY_NONE,       // KEY_ENTER
    LV_MAPPED_KEY_NONE,       // KEY_LEFTCTRL
    LV_MAPPED_KEY_A,          // KEY_A
    LV_MAPPED_KEY_S,          // KEY_S
    LV_MAPPED_KEY_D,          // KEY_D
    LV_MAPPED_KEY_F,          // KEY_F
    LV_MAPPED_KEY_G,          // KEY_G
    LV_MAPPED_KEY_H,          // KEY_H
    LV_MAPPED_KEY_J,          // KEY_J
    LV_MAPPED_KEY_K,          // KEY_K
    LV_MAPPED_KEY_L,          // KEY_L
    LV_MAPPED_KEY_SEMICOLON,  // KEY_SEMICOLON
    LV_MAPPED_KEY_APOSTROPHE, // KEY_APOSTROPHE
    LV_MAPPED_KEY_GRAVE,      // KEY_GRAVE
    LV_MAPPED_KEY_NONE,       // KEY_LEFTSHIFT
    LV_MAPPED_KEY_BACKSLASH,  // KEY_BACKSLASH
    LV_MAPPED_KEY_Z,          // KEY_Z
    LV_MAPPED_KEY_X,          // KEY_X
    LV_MAPPED_KEY_C,          // KEY_C
    LV_MAPPED_KEY_V,          // KEY_V
    LV_MAPPED_KEY_B,          // KEY_B
    LV_MAPPED_KEY_N,          // KEY_N
    LV_MAPPED_KEY_M,          // KEY_M
    LV_MAPPED_KEY_COMMA,      // KEY_COMMA
    LV_MAPPED_KEY_DOT,        // KEY_DOT
    LV_MAPPED_KEY_SLASH       // KEY_SLASH
};

const char keymap_lower[LV_NUM_KEYS_MAPPED] = {
    '`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '=',
    'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']', '\\',
    'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'',
    'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/'
};

const char keymap_upper[LV_NUM_KEYS_MAPPED] = {
    '~', '!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+',
    'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I', 'O', 'P', '{', '}', '|',
    'A', 'S', 'D', 'F', 'G', 'H', 'J', 'K', 'L', ':', '"',
    'Z', 'X', 'C', 'V', 'B', 'N', 'M', '<', '>', '?'
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* USE_LIBINPUT || USE_BSD_LIBINPUT */
