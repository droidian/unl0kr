/**
 * Auto-generated with squeek2lvgl
 **/

#include "sq2lv_layouts.h"

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
    "ABC", "z", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_lower_us[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_lower_us = 0;

static const int modifier_idxs_lower_us[] = { \
     \
};

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
    "abc", "Z", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_upper_us[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_upper_us = 0;

static const int modifier_idxs_upper_us[] = { \
     \
};

static const int num_switchers_upper_us = 2;

static const int switcher_idxs_upper_us[] = { \
    19, 28 \
};

static const int switcher_dests_upper_us[] = { \
    0, 2 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const int num_keys_numbers_us = 34;

static const char * const keycaps_numbers_us[] = { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "$", "%", "&", "-", "_", "+", "(", ")", "\n", \
    ",", "\"", "'", ":", ";", "!", "?", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_numbers_us[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_numbers_us = 0;

static const int modifier_idxs_numbers_us[] = { \
     \
};

static const int num_switchers_numbers_us = 1;

static const int switcher_idxs_numbers_us[] = { \
    28 \
};

static const int switcher_dests_numbers_us[] = { \
    0 \
};

/* Layer array */

static const int num_layers_us = 3;

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
    "ABC", "y", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", "äöü", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ",", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_lower_de[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_lower_de = 0;

static const int modifier_idxs_lower_de[] = { \
     \
};

static const int num_switchers_lower_de = 3;

static const int switcher_idxs_lower_de[] = { \
    19, 28, 29 \
};

static const int switcher_dests_lower_de[] = { \
    1, 2, 3 \
};

/* Layer: Uppercase letters - generated from upper */

static const int num_keys_upper_de = 36;

static const char * const keycaps_upper_de[] = { \
    "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "\n", \
    "abc", "Y", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", "äöü", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "!", "?", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_upper_de[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_upper_de = 0;

static const int modifier_idxs_upper_de[] = { \
     \
};

static const int num_switchers_upper_de = 3;

static const int switcher_idxs_upper_de[] = { \
    19, 28, 29 \
};

static const int switcher_dests_upper_de[] = { \
    0, 2, 3 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const int num_keys_numbers_de = 36;

static const char * const keycaps_numbers_de[] = { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "€", "%", "&", "-", "_", "+", "(", ")", "\n", \
    ";", "\"", "'", ":", "=", "<", ">", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "äöü", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ",", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_numbers_de[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_numbers_de = 0;

static const int modifier_idxs_numbers_de[] = { \
     \
};

static const int num_switchers_numbers_de = 2;

static const int switcher_idxs_numbers_de[] = { \
    28, 29 \
};

static const int switcher_dests_numbers_de[] = { \
    0, 3 \
};

/* Layer: Special characters - generated from eschars */

static const int num_keys_special_de = 37;

static const char * const keycaps_special_de[] = { \
    "ä", "è", "é", "ö", "ü", "Ä", "È", "É", "Ö", "Ü", "\n", \
    "à", "â", "ê", "î", "ô", "À", "Â", "È", "Î", "Ô", "\n", \
    "1#", "«", "»", "ç", "Ç", "æ", "œ", "ß", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "äöü", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "„", "“", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_special_de[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_special_de = 0;

static const int modifier_idxs_special_de[] = { \
     \
};

static const int num_switchers_special_de = 3;

static const int switcher_idxs_special_de[] = { \
    20, 29, 30 \
};

static const int switcher_dests_special_de[] = { \
    2, 0, 0 \
};

/* Layer array */

static const int num_layers_de = 4;

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
    "ABC", "z", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", "áéí", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "?", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_lower_es[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_lower_es = 0;

static const int modifier_idxs_lower_es[] = { \
     \
};

static const int num_switchers_lower_es = 3;

static const int switcher_idxs_lower_es[] = { \
    20, 29, 30 \
};

static const int switcher_dests_lower_es[] = { \
    1, 2, 3 \
};

/* Layer: Uppercase letters - generated from upper */

static const int num_keys_upper_es = 37;

static const char * const keycaps_upper_es[] = { \
    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ñ", "\n", \
    "abc", "Z", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", "áéí", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "¿", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_upper_es[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_upper_es = 0;

static const int modifier_idxs_upper_es[] = { \
     \
};

static const int num_switchers_upper_es = 3;

static const int switcher_idxs_upper_es[] = { \
    20, 29, 30 \
};

static const int switcher_dests_upper_es[] = { \
    0, 2, 3 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const int num_keys_numbers_es = 36;

static const char * const keycaps_numbers_es[] = { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "€", "%", "&", "-", "_", "+", "(", ")", "\n", \
    ",", "\"", "'", ":", ";", "!", "=", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "áéí", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "?", ".", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_numbers_es[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_numbers_es = 0;

static const int modifier_idxs_numbers_es[] = { \
     \
};

static const int num_switchers_numbers_es = 2;

static const int switcher_idxs_numbers_es[] = { \
    28, 29 \
};

static const int switcher_dests_numbers_es[] = { \
    0, 3 \
};

/* Layer: Special characters - generated from eschars */

static const int num_keys_special_es = 37;

static const char * const keycaps_special_es[] = { \
    "á", "é", "í", "ó", "ú", "Á", "É", "Í", "Ó", "Ú", "\n", \
    "à", "è", "ì", "ò", "ù", "À", "È", "Ì", "Ò", "Ù", "\n", \
    "1#", "ü", "ç", "ï", "Ü", "Ç", "Ï", "¡", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "áéí", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "«", "»", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_special_es[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_special_es = 0;

static const int modifier_idxs_special_es[] = { \
     \
};

static const int num_switchers_special_es = 3;

static const int switcher_idxs_special_es[] = { \
    20, 29, 30 \
};

static const int switcher_dests_special_es[] = { \
    2, 0, 0 \
};

/* Layer array */

static const int num_layers_es = 4;

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
    "ABC", "w", "x", "c", "v", "b", "n", ".", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "àéô", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_lower_fr[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_lower_fr = 0;

static const int modifier_idxs_lower_fr[] = { \
     \
};

static const int num_switchers_lower_fr = 3;

static const int switcher_idxs_lower_fr[] = { \
    20, 29, 33 \
};

static const int switcher_dests_lower_fr[] = { \
    1, 2, 3 \
};

/* Layer: Uppercase letters - generated from upper */

static const int num_keys_upper_fr = 35;

static const char * const keycaps_upper_fr[] = { \
    "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "\n", \
    "abc", "W", "X", "C", "V", "B", "N", ",", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "àéô", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_upper_fr[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_upper_fr = 0;

static const int modifier_idxs_upper_fr[] = { \
     \
};

static const int num_switchers_upper_fr = 3;

static const int switcher_idxs_upper_fr[] = { \
    20, 29, 33 \
};

static const int switcher_dests_upper_fr[] = { \
    0, 2, 3 \
};

/* Layer: Numbers / symbols - generated from numbers */

static const int num_keys_numbers_fr = 34;

static const char * const keycaps_numbers_fr[] = { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "€", "%", "&", "-", "_", "+", "(", ")", "\n", \
    ",", "\"", "'", ":", ";", "!", "?", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "àéô", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_numbers_fr[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_numbers_fr = 0;

static const int modifier_idxs_numbers_fr[] = { \
     \
};

static const int num_switchers_numbers_fr = 2;

static const int switcher_idxs_numbers_fr[] = { \
    28, 32 \
};

static const int switcher_dests_numbers_fr[] = { \
    0, 3 \
};

/* Layer: Special characters - generated from eschars */

static const int num_keys_special_fr = 35;

static const char * const keycaps_special_fr[] = { \
    "à", "â", "ç", "é", "è", "ê", "î", "ô", "ù", "û", "\n", \
    "À", "Â", "Ç", "É", "È", "Ê", "Î", "Ô", "Ù", "Û", "\n", \
    "1#", "æ", "œ", "ä", "ë", "ï", "ö", "ü", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "àéô", LV_SYMBOL_OK, "" \
};

static const lv_btnmatrix_ctrl_t attributes_special_fr[] = { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
};

static const int num_modifiers_special_fr = 0;

static const int modifier_idxs_special_fr[] = { \
     \
};

static const int num_switchers_special_fr = 3;

static const int switcher_idxs_special_fr[] = { \
    20, 29, 33 \
};

static const int switcher_dests_special_fr[] = { \
    2, 0, 0 \
};

/* Layer array */

static const int num_layers_fr = 4;

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
