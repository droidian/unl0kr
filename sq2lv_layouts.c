/**
 * Auto-generated with squeek2lvgl
 **/

#include "sq2lv_layouts.h"

#define SQ2LV_SYMBOL_SHIFT "\xef\x8d\x9b"

/**
 * Layout: US English - generated from us
 **/

static const char * const name_us = "US English";
static const char * const short_name_us = "us";

/* Layer: Lowercase letters - generated from base */

static const int num_keys_lower_us = 34;

static const char * const keycaps_lower_us[] = { \
    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "\n", \
    "a", "s", "d", "f", "g", "h", "j", "k", "l", "\n", \
    SQ2LV_SYMBOL_SHIFT, "z", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "123", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_lower_us[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_MOD_INACTIVE | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_lower_us = 0;

static const int * const modifier_idxs_lower_us = NULL;

static const int num_switchers_lower_us = 2;

static const int switcher_idxs_lower_us[] = { \
    19, 28 \
};

static const int switcher_dests_lower_us[] = { \
    1, 2 \
};

/* Layer: Uppercase letters - generated from upper */

static const int num_keys_upper_us = 34;

static const char * const keycaps_upper_us[] = { \
    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "\n", \
    SQ2LV_SYMBOL_SHIFT, "Z", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "123", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_upper_us[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_MOD_ACTIVE | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_upper_us = 0;

static const int * const modifier_idxs_upper_us = NULL;

static const int num_switchers_upper_us = 2;

static const int switcher_idxs_upper_us[] = { \
    19, 28 \
};

static const int switcher_dests_upper_us[] = { \
    0, 2 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const int num_keys_numbers_us = 35;

static const char * const keycaps_numbers_us[] = { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "$", "%", "&", "-", "_", "+", "(", ")", "\n", \
    "*/=", ",", "\"", "'", ":", ";", "!", "?", LV_SYMBOL_BACKSPACE, "\n", \
    "ABC", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_numbers_us[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_numbers_us = 0;

static const int * const modifier_idxs_numbers_us = NULL;

static const int num_switchers_numbers_us = 2;

static const int switcher_idxs_numbers_us[] = { \
    20, 29 \
};

static const int switcher_dests_numbers_us[] = { \
    3, 0 \
};

/* Layer: Symbols - generated from symbols */

static const int num_keys_symbols_us = 35;

static const char * const keycaps_symbols_us[] = { \
    "~", "`", "|", "·", "√", "π", "τ", "÷", "×", "¶", "\n", \
    "©", "®", "£", "€", "¥", "^", "°", "*", "{", "}", "\n", \
    "123", "\\", "/", "<", ">", "=", "[", "]", LV_SYMBOL_BACKSPACE, "\n", \
    "ABC", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_symbols_us[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_symbols_us = 0;

static const int * const modifier_idxs_symbols_us = NULL;

static const int num_switchers_symbols_us = 2;

static const int switcher_idxs_symbols_us[] = { \
    20, 29 \
};

static const int switcher_dests_symbols_us[] = { \
    2, 0 \
};

/* Layer array */

static const int num_layers_us = 4;

static const sq2lv_layer_t layers_us[] = {
    {
        .num_keys = num_keys_lower_us,
        .keycaps = keycaps_lower_us,
        .attributes = attributes_lower_us,
        .num_modifiers = num_modifiers_lower_us,
        .modifier_idxs = modifier_idxs_lower_us,
        .num_switchers = num_switchers_lower_us,
        .switcher_idxs = switcher_idxs_lower_us,
        .switcher_dests = switcher_dests_lower_us
    },
    {
        .num_keys = num_keys_upper_us,
        .keycaps = keycaps_upper_us,
        .attributes = attributes_upper_us,
        .num_modifiers = num_modifiers_upper_us,
        .modifier_idxs = modifier_idxs_upper_us,
        .num_switchers = num_switchers_upper_us,
        .switcher_idxs = switcher_idxs_upper_us,
        .switcher_dests = switcher_dests_upper_us
    },
    {
        .num_keys = num_keys_numbers_us,
        .keycaps = keycaps_numbers_us,
        .attributes = attributes_numbers_us,
        .num_modifiers = num_modifiers_numbers_us,
        .modifier_idxs = modifier_idxs_numbers_us,
        .num_switchers = num_switchers_numbers_us,
        .switcher_idxs = switcher_idxs_numbers_us,
        .switcher_dests = switcher_dests_numbers_us
    },
    {
        .num_keys = num_keys_symbols_us,
        .keycaps = keycaps_symbols_us,
        .attributes = attributes_symbols_us,
        .num_modifiers = num_modifiers_symbols_us,
        .modifier_idxs = modifier_idxs_symbols_us,
        .num_switchers = num_switchers_symbols_us,
        .switcher_idxs = switcher_idxs_symbols_us,
        .switcher_dests = switcher_dests_symbols_us
    }
};

/**
 * Layout: German - generated from de
 **/

static const char * const name_de = "German";
static const char * const short_name_de = "de";

/* Layer: Lowercase letters - generated from base */

static const int num_keys_lower_de = 36;

static const char * const keycaps_lower_de[] = { \
    "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "\n", \
    "a", "s", "d", "f", "g", "h", "j", "k", "l", "\n", \
    SQ2LV_SYMBOL_SHIFT, "y", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "123", "äÄ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ",", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_lower_de[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_MOD_INACTIVE | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_lower_de = 0;

static const int * const modifier_idxs_lower_de = NULL;

static const int num_switchers_lower_de = 3;

static const int switcher_idxs_lower_de[] = { \
    19, 28, 29 \
};

static const int switcher_dests_lower_de[] = { \
    1, 2, 4 \
};

/* Layer: Uppercase letters - generated from upper */

static const int num_keys_upper_de = 36;

static const char * const keycaps_upper_de[] = { \
    "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "\n", \
    SQ2LV_SYMBOL_SHIFT, "Y", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "123", "äÄ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "!", "?", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_upper_de[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_MOD_ACTIVE | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_upper_de = 0;

static const int * const modifier_idxs_upper_de = NULL;

static const int num_switchers_upper_de = 3;

static const int switcher_idxs_upper_de[] = { \
    19, 28, 29 \
};

static const int switcher_dests_upper_de[] = { \
    0, 2, 4 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const int num_keys_numbers_de = 37;

static const char * const keycaps_numbers_de[] = { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "€", "%", "&", "-", "_", "+", "(", ")", "\n", \
    "*/=", ";", "\"", "'", ":", "=", "<", ">", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "äÄ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ",", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_numbers_de[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_numbers_de = 0;

static const int * const modifier_idxs_numbers_de = NULL;

static const int num_switchers_numbers_de = 3;

static const int switcher_idxs_numbers_de[] = { \
    20, 29, 30 \
};

static const int switcher_dests_numbers_de[] = { \
    3, 0, 4 \
};

/* Layer: Symbols - generated from symbols */

static const int num_keys_symbols_de = 37;

static const char * const keycaps_symbols_de[] = { \
    "~", "`", "´", "|", "·", "√", "µ", "÷", "×", "¶", "\n", \
    "©", "®", "£", "$", "¥", "^", "°", "*", "{", "}", "\n", \
    "123", "\\", "/", "§", "π", "τ", "[", "]", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "äÄ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ",", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_symbols_de[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_symbols_de = 0;

static const int * const modifier_idxs_symbols_de = NULL;

static const int num_switchers_symbols_de = 3;

static const int switcher_idxs_symbols_de[] = { \
    20, 29, 30 \
};

static const int switcher_dests_symbols_de[] = { \
    2, 0, 4 \
};

/* Layer: Special characters - generated from eschars */

static const int num_keys_special_de = 37;

static const char * const keycaps_special_de[] = { \
    "ä", "è", "é", "ö", "ü", "Ä", "È", "É", "Ö", "Ü", "\n", \
    "à", "â", "ê", "î", "ô", "À", "Â", "È", "Î", "Ô", "\n", \
    "123", "«", "»", "ç", "Ç", "æ", "œ", "ß", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "äÄ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "„", "“", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_special_de[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_ACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_special_de = 0;

static const int * const modifier_idxs_special_de = NULL;

static const int num_switchers_special_de = 3;

static const int switcher_idxs_special_de[] = { \
    20, 29, 30 \
};

static const int switcher_dests_special_de[] = { \
    2, 0, 0 \
};

/* Layer array */

static const int num_layers_de = 5;

static const sq2lv_layer_t layers_de[] = {
    {
        .num_keys = num_keys_lower_de,
        .keycaps = keycaps_lower_de,
        .attributes = attributes_lower_de,
        .num_modifiers = num_modifiers_lower_de,
        .modifier_idxs = modifier_idxs_lower_de,
        .num_switchers = num_switchers_lower_de,
        .switcher_idxs = switcher_idxs_lower_de,
        .switcher_dests = switcher_dests_lower_de
    },
    {
        .num_keys = num_keys_upper_de,
        .keycaps = keycaps_upper_de,
        .attributes = attributes_upper_de,
        .num_modifiers = num_modifiers_upper_de,
        .modifier_idxs = modifier_idxs_upper_de,
        .num_switchers = num_switchers_upper_de,
        .switcher_idxs = switcher_idxs_upper_de,
        .switcher_dests = switcher_dests_upper_de
    },
    {
        .num_keys = num_keys_numbers_de,
        .keycaps = keycaps_numbers_de,
        .attributes = attributes_numbers_de,
        .num_modifiers = num_modifiers_numbers_de,
        .modifier_idxs = modifier_idxs_numbers_de,
        .num_switchers = num_switchers_numbers_de,
        .switcher_idxs = switcher_idxs_numbers_de,
        .switcher_dests = switcher_dests_numbers_de
    },
    {
        .num_keys = num_keys_symbols_de,
        .keycaps = keycaps_symbols_de,
        .attributes = attributes_symbols_de,
        .num_modifiers = num_modifiers_symbols_de,
        .modifier_idxs = modifier_idxs_symbols_de,
        .num_switchers = num_switchers_symbols_de,
        .switcher_idxs = switcher_idxs_symbols_de,
        .switcher_dests = switcher_dests_symbols_de
    },
    {
        .num_keys = num_keys_special_de,
        .keycaps = keycaps_special_de,
        .attributes = attributes_special_de,
        .num_modifiers = num_modifiers_special_de,
        .modifier_idxs = modifier_idxs_special_de,
        .num_switchers = num_switchers_special_de,
        .switcher_idxs = switcher_idxs_special_de,
        .switcher_dests = switcher_dests_special_de
    }
};

/**
 * Layout: Spanish - generated from es
 **/

static const char * const name_es = "Spanish";
static const char * const short_name_es = "es";

/* Layer: Lowercase letters - generated from base */

static const int num_keys_lower_es = 37;

static const char * const keycaps_lower_es[] = { \
    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "\n", \
    "a", "s", "d", "f", "g", "h", "j", "k", "l", "ñ", "\n", \
    SQ2LV_SYMBOL_SHIFT, "z", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "123", "áÁ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "?", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_lower_es[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_MOD_INACTIVE | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_lower_es = 0;

static const int * const modifier_idxs_lower_es = NULL;

static const int num_switchers_lower_es = 3;

static const int switcher_idxs_lower_es[] = { \
    20, 29, 30 \
};

static const int switcher_dests_lower_es[] = { \
    1, 2, 4 \
};

/* Layer: Uppercase letters - generated from upper */

static const int num_keys_upper_es = 37;

static const char * const keycaps_upper_es[] = { \
    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ñ", "\n", \
    SQ2LV_SYMBOL_SHIFT, "Z", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "123", "áÁ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "¿", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_upper_es[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_MOD_ACTIVE | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_upper_es = 0;

static const int * const modifier_idxs_upper_es = NULL;

static const int num_switchers_upper_es = 3;

static const int switcher_idxs_upper_es[] = { \
    20, 29, 30 \
};

static const int switcher_dests_upper_es[] = { \
    0, 2, 4 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const int num_keys_numbers_es = 37;

static const char * const keycaps_numbers_es[] = { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "€", "%", "&", "-", "_", "+", "(", ")", "\n", \
    "*/=", ",", "\"", "'", ":", ";", "!", "=", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "áÁ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "?", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_numbers_es[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_numbers_es = 0;

static const int * const modifier_idxs_numbers_es = NULL;

static const int num_switchers_numbers_es = 3;

static const int switcher_idxs_numbers_es[] = { \
    20, 29, 30 \
};

static const int switcher_dests_numbers_es[] = { \
    3, 0, 4 \
};

/* Layer: Symbols - generated from symbols */

static const int num_keys_symbols_es = 37;

static const char * const keycaps_symbols_es[] = { \
    "~", "`", "|", "·", "√", "π", "τ", "÷", "×", "¶", "\n", \
    "©", "®", "£", "$", "¥", "^", "°", "*", "{", "}", "\n", \
    "123", "\\", "/", "<", ">", "=", "[", "]", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "áÁ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "?", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_symbols_es[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_symbols_es = 0;

static const int * const modifier_idxs_symbols_es = NULL;

static const int num_switchers_symbols_es = 3;

static const int switcher_idxs_symbols_es[] = { \
    20, 29, 30 \
};

static const int switcher_dests_symbols_es[] = { \
    2, 0, 4 \
};

/* Layer: Special characters - generated from eschars */

static const int num_keys_special_es = 37;

static const char * const keycaps_special_es[] = { \
    "á", "é", "í", "ó", "ú", "Á", "É", "Í", "Ó", "Ú", "\n", \
    "à", "è", "ì", "ò", "ù", "À", "È", "Ì", "Ò", "Ù", "\n", \
    "123", "ü", "ç", "ï", "Ü", "Ç", "Ï", "¡", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "áÁ", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "«", "»", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_special_es[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_MOD_ACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_special_es = 0;

static const int * const modifier_idxs_special_es = NULL;

static const int num_switchers_special_es = 3;

static const int switcher_idxs_special_es[] = { \
    20, 29, 30 \
};

static const int switcher_dests_special_es[] = { \
    2, 0, 0 \
};

/* Layer array */

static const int num_layers_es = 5;

static const sq2lv_layer_t layers_es[] = {
    {
        .num_keys = num_keys_lower_es,
        .keycaps = keycaps_lower_es,
        .attributes = attributes_lower_es,
        .num_modifiers = num_modifiers_lower_es,
        .modifier_idxs = modifier_idxs_lower_es,
        .num_switchers = num_switchers_lower_es,
        .switcher_idxs = switcher_idxs_lower_es,
        .switcher_dests = switcher_dests_lower_es
    },
    {
        .num_keys = num_keys_upper_es,
        .keycaps = keycaps_upper_es,
        .attributes = attributes_upper_es,
        .num_modifiers = num_modifiers_upper_es,
        .modifier_idxs = modifier_idxs_upper_es,
        .num_switchers = num_switchers_upper_es,
        .switcher_idxs = switcher_idxs_upper_es,
        .switcher_dests = switcher_dests_upper_es
    },
    {
        .num_keys = num_keys_numbers_es,
        .keycaps = keycaps_numbers_es,
        .attributes = attributes_numbers_es,
        .num_modifiers = num_modifiers_numbers_es,
        .modifier_idxs = modifier_idxs_numbers_es,
        .num_switchers = num_switchers_numbers_es,
        .switcher_idxs = switcher_idxs_numbers_es,
        .switcher_dests = switcher_dests_numbers_es
    },
    {
        .num_keys = num_keys_symbols_es,
        .keycaps = keycaps_symbols_es,
        .attributes = attributes_symbols_es,
        .num_modifiers = num_modifiers_symbols_es,
        .modifier_idxs = modifier_idxs_symbols_es,
        .num_switchers = num_switchers_symbols_es,
        .switcher_idxs = switcher_idxs_symbols_es,
        .switcher_dests = switcher_dests_symbols_es
    },
    {
        .num_keys = num_keys_special_es,
        .keycaps = keycaps_special_es,
        .attributes = attributes_special_es,
        .num_modifiers = num_modifiers_special_es,
        .modifier_idxs = modifier_idxs_special_es,
        .num_switchers = num_switchers_special_es,
        .switcher_idxs = switcher_idxs_special_es,
        .switcher_dests = switcher_dests_special_es
    }
};

/**
 * Layout: French - generated from fr
 **/

static const char * const name_fr = "French";
static const char * const short_name_fr = "fr";

/* Layer: Lowercase letters - generated from base */

static const int num_keys_lower_fr = 35;

static const char * const keycaps_lower_fr[] = { \
    "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "\n", \
    "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "\n", \
    SQ2LV_SYMBOL_SHIFT, "w", "x", "c", "v", "b", "n", ".", LV_SYMBOL_BACKSPACE, "\n", \
    "123", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "âÂ", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_lower_fr[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_MOD_INACTIVE | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_lower_fr = 0;

static const int * const modifier_idxs_lower_fr = NULL;

static const int num_switchers_lower_fr = 3;

static const int switcher_idxs_lower_fr[] = { \
    20, 29, 33 \
};

static const int switcher_dests_lower_fr[] = { \
    1, 2, 4 \
};

/* Layer: Uppercase letters - generated from upper */

static const int num_keys_upper_fr = 35;

static const char * const keycaps_upper_fr[] = { \
    "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "\n", \
    SQ2LV_SYMBOL_SHIFT, "W", "X", "C", "V", "B", "N", ",", LV_SYMBOL_BACKSPACE, "\n", \
    "123", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "âÂ", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_upper_fr[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_MOD_ACTIVE | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_upper_fr = 0;

static const int * const modifier_idxs_upper_fr = NULL;

static const int num_switchers_upper_fr = 3;

static const int switcher_idxs_upper_fr[] = { \
    20, 29, 33 \
};

static const int switcher_dests_upper_fr[] = { \
    0, 2, 4 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const int num_keys_numbers_fr = 35;

static const char * const keycaps_numbers_fr[] = { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "€", "%", "&", "-", "_", "+", "(", ")", "\n", \
    "*/=", ",", "\"", "'", ":", ";", "!", "?", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "âÂ", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_numbers_fr[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_numbers_fr = 0;

static const int * const modifier_idxs_numbers_fr = NULL;

static const int num_switchers_numbers_fr = 3;

static const int switcher_idxs_numbers_fr[] = { \
    20, 29, 33 \
};

static const int switcher_dests_numbers_fr[] = { \
    3, 0, 4 \
};

/* Layer: Symbols - generated from symbols */

static const int num_keys_symbols_fr = 35;

static const char * const keycaps_symbols_fr[] = { \
    "~", "`", "|", "·", "√", "π", "τ", "÷", "×", "¶", "\n", \
    "©", "®", "£", "$", "¥", "^", "°", "*", "{", "}", "\n", \
    "123", "\\", "/", "<", ">", "=", "[", "]", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "âÂ", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_symbols_fr[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, SQ2LV_CTRL_MOD_INACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_symbols_fr = 0;

static const int * const modifier_idxs_symbols_fr = NULL;

static const int num_switchers_symbols_fr = 3;

static const int switcher_idxs_symbols_fr[] = { \
    20, 29, 33 \
};

static const int switcher_dests_symbols_fr[] = { \
    2, 0, 4 \
};

/* Layer: Special characters - generated from eschars */

static const int num_keys_special_fr = 35;

static const char * const keycaps_special_fr[] = { \
    "à", "â", "ç", "é", "è", "ê", "î", "ô", "ù", "û", "\n", \
    "À", "Â", "Ç", "É", "È", "Ê", "Î", "Ô", "Ù", "Û", "\n", \
    "123", "æ", "œ", "ä", "ë", "ï", "ö", "ü", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "âÂ", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_special_fr[] = { \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, \
    SQ2LV_CTRL_NON_CHAR | 3, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, LV_BTNMATRIX_CTRL_POPOVER | 2, SQ2LV_CTRL_NON_CHAR | 3, \
    SQ2LV_CTRL_NON_CHAR | 3, SQ2LV_CTRL_NON_CHAR | 2, 7, SQ2LV_CTRL_NON_CHAR | 2, SQ2LV_CTRL_MOD_ACTIVE | 3, SQ2LV_CTRL_NON_CHAR | 3 \
};

static const int num_modifiers_special_fr = 0;

static const int * const modifier_idxs_special_fr = NULL;

static const int num_switchers_special_fr = 3;

static const int switcher_idxs_special_fr[] = { \
    20, 29, 33 \
};

static const int switcher_dests_special_fr[] = { \
    2, 0, 0 \
};

/* Layer array */

static const int num_layers_fr = 5;

static const sq2lv_layer_t layers_fr[] = {
    {
        .num_keys = num_keys_lower_fr,
        .keycaps = keycaps_lower_fr,
        .attributes = attributes_lower_fr,
        .num_modifiers = num_modifiers_lower_fr,
        .modifier_idxs = modifier_idxs_lower_fr,
        .num_switchers = num_switchers_lower_fr,
        .switcher_idxs = switcher_idxs_lower_fr,
        .switcher_dests = switcher_dests_lower_fr
    },
    {
        .num_keys = num_keys_upper_fr,
        .keycaps = keycaps_upper_fr,
        .attributes = attributes_upper_fr,
        .num_modifiers = num_modifiers_upper_fr,
        .modifier_idxs = modifier_idxs_upper_fr,
        .num_switchers = num_switchers_upper_fr,
        .switcher_idxs = switcher_idxs_upper_fr,
        .switcher_dests = switcher_dests_upper_fr
    },
    {
        .num_keys = num_keys_numbers_fr,
        .keycaps = keycaps_numbers_fr,
        .attributes = attributes_numbers_fr,
        .num_modifiers = num_modifiers_numbers_fr,
        .modifier_idxs = modifier_idxs_numbers_fr,
        .num_switchers = num_switchers_numbers_fr,
        .switcher_idxs = switcher_idxs_numbers_fr,
        .switcher_dests = switcher_dests_numbers_fr
    },
    {
        .num_keys = num_keys_symbols_fr,
        .keycaps = keycaps_symbols_fr,
        .attributes = attributes_symbols_fr,
        .num_modifiers = num_modifiers_symbols_fr,
        .modifier_idxs = modifier_idxs_symbols_fr,
        .num_switchers = num_switchers_symbols_fr,
        .switcher_idxs = switcher_idxs_symbols_fr,
        .switcher_dests = switcher_dests_symbols_fr
    },
    {
        .num_keys = num_keys_special_fr,
        .keycaps = keycaps_special_fr,
        .attributes = attributes_special_fr,
        .num_modifiers = num_modifiers_special_fr,
        .modifier_idxs = modifier_idxs_special_fr,
        .num_switchers = num_switchers_special_fr,
        .switcher_idxs = switcher_idxs_special_fr,
        .switcher_dests = switcher_dests_special_fr
    }
};

/**
 * Public interface
 **/

const int sq2lv_num_layouts = 4;

const sq2lv_layout_t sq2lv_layouts[] = {
    /* US English */
    {
        .name = name_us,
        .short_name = short_name_us,
        .num_layers = num_layers_us,
        .layers = layers_us
    },
    /* German */
    {
        .name = name_de,
        .short_name = short_name_de,
        .num_layers = num_layers_de,
        .layers = layers_de
    },
    /* Spanish */
    {
        .name = name_es,
        .short_name = short_name_es,
        .num_layers = num_layers_es,
        .layers = layers_es
    },
    /* French */
    {
        .name = name_fr,
        .short_name = short_name_fr,
        .num_layers = num_layers_fr,
        .layers = layers_fr
    }
};

const char * const sq2lv_layout_names =
    "US English" "\n"
    "German" "\n"
    "Spanish" "\n"
    "French";

const char * const sq2lv_layout_short_names =
    "us" "\n"
    "de" "\n"
    "es" "\n"
    "fr";
