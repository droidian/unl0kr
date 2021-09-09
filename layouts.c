#include "layouts.h"

/**
 * English (US)
 **/

#define NAME_US "us"

/* Lowercase layer */
#define KEYS_LOWER_US { \
    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "\n", \
    "a", "s", "d", "f", "g", "h", "j", "k", "l", "\n", \
    "ABC", "z", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_LOWER_US { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Uppercase layer */
#define KEYS_UPPER_US { \
    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "\n", \
    "abc", "Z", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_UPPER_US { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Number / symbol layer */
#define KEYS_NUMBERS_US { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "$", "%", "&", "-", "_", "+", "(", ")", "\n", \
    ",", "\"", "'", ":", ";", "!", "?", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ".", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_NUMBERS_US { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Special characters */
#define TRIGGER_SPECIAL_US ""
#define KEYS_SPECIAL_US { NULL }
#define ATTRIBUTES_SPECIAL_US { 0 }

/**
 * French
 **/

#define NAME_FR "fr"

/* Lowercase layer */
#define KEYS_LOWER_FR { \
    "a", "z", "e", "r", "t", "y", "u", "i", "o", "p", "\n", \
    "q", "s", "d", "f", "g", "h", "j", "k", "l", "m", "\n", \
    "ABC", "w", "x", "c", "v", "b", "n", ".", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "àéô", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_LOWER_FR { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Uppercase layer */
#define KEYS_UPPER_FR { \
    "A", "Z", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "Q", "S", "D", "F", "G", "H", "J", "K", "L", "M", "\n", \
    "abc", "W", "X", "C", "V", "B", "N", ",", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "àéô", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_UPPER_FR { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Number / symbol layer */
#define KEYS_NUMBERS_FR { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "€", "%", "&", "-", "_", "+", "(", ")", "\n", \
    ",", "\"", "'", ":", ";", "!", "?", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "àéô", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_NUMBERS_FR { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Special characters */
#define TRIGGER_SPECIAL_FR "àéô"
#define KEYS_SPECIAL_FR { \
    "à", "â", "ç", "é", "è", "ê", "î", "ô", "ù", "û", "\n", \
    "À", "Â", "Ç", "É", "È", "Ê", "Î", "Ô", "Ù", "Û", "\n", \
    "1#", "æ", "œ", "ä", "ë", "ï", "ö", "ü", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "àéô", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_SPECIAL_FR { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/**
 * Spanish
 **/

#define NAME_ES "es"

/* Lowercase layer */
#define KEYS_LOWER_ES { \
    "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", "\n", \
    "a", "s", "d", "f", "g", "h", "j", "k", "l", "ñ", "\n", \
    "ABC", "z", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", "áéí", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "?", ".", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_LOWER_ES { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Uppercase layer */
#define KEYS_UPPER_ES { \
    "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ñ", "\n", \
    "abc", "Z", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", "áéí", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "¿", ".", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_UPPER_ES { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Number / symbol layer */
#define KEYS_NUMBERS_ES { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "€", "%", "&", "-", "_", "+", "(", ")", "\n", \
    ",", "\"", "'", ":", ";", "!", "=", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "áéí", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "?", ".", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_NUMBERS_ES { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Special characters */
#define TRIGGER_SPECIAL_ES "áéí"
#define KEYS_SPECIAL_ES { \
    "á", "é", "í", "ó", "ú", "Á", "É", "Í", "Ó", "Ú", "\n", \
    "à", "è", "ì", "ò", "ù", "À", "È", "Ì", "Ò", "Ù", "\n", \
    "1#", "ü", "ç", "ï", "Ü", "Ç", "Ï", "¡", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "áéí", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "«", "»", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_SPECIAL_ES { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/**
 * German
 **/

#define NAME_DE "de"

/* Lowercase layer */
#define KEYS_LOWER_DE { \
    "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "\n", \
    "a", "s", "d", "f", "g", "h", "j", "k", "l", "\n", \
    "ABC", "y", "x", "c", "v", "b", "n", "m", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", "äöü", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ",", ".", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_LOWER_DE { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Uppercase layer */
#define KEYS_UPPER_DE { \
    "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "\n", \
    "abc", "Y", "X", "C", "V", "B", "N", "M", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", "äöü", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "!", "?", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_UPPER_DE { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Number / symbol layer */
#define KEYS_NUMBERS_DE { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", "\n", \
    "@", "#", "€", "%", "&", "-", "_", "+", "(", ")", "\n", \
    ";", "\"", "'", ":", "=", "<", ">", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "äöü", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, ",", ".", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_NUMBERS_DE { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/* Special characters */
#define TRIGGER_SPECIAL_DE "äöü"
#define KEYS_SPECIAL_DE { \
    "ä", "è", "é", "ö", "ü", "Ä", "È", "É", "Ö", "Ü", "\n", \
    "à", "â", "ê", "î", "ô", "À", "Â", "È", "Î", "Ô", "\n", \
    "1#", "«", "»", "ç", "Ç", "æ", "œ", "ß", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "äöü", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, "„", "“", LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_SPECIAL_DE { \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, 2, 2, 2, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_KEYBOARD_CTRL_BTN_FLAGS | 7, LV_KEYBOARD_CTRL_BTN_FLAGS | 3, 2, 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 3 \
}

/**
 * All layouts
 **/

static const char * const names =
    LV_SYMBOL_KEYBOARD " " NAME_US "\n"
    LV_SYMBOL_KEYBOARD " " NAME_FR "\n"
    LV_SYMBOL_KEYBOARD " " NAME_ES "\n"
    LV_SYMBOL_KEYBOARD " " NAME_DE;

static const char ** const keys_lower[] = {
    (const char * const [])KEYS_LOWER_US,
    (const char * const [])KEYS_LOWER_FR,
    (const char * const [])KEYS_LOWER_ES,
    (const char * const [])KEYS_LOWER_DE
};

static const lv_btnmatrix_ctrl_t * const attributes_lower[] = {
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_LOWER_US,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_LOWER_FR,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_LOWER_ES,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_LOWER_DE
};

static const char ** const keys_upper[] = {
    (const char * const [])KEYS_UPPER_US,
    (const char * const [])KEYS_UPPER_FR,
    (const char * const [])KEYS_UPPER_ES,
    (const char * const [])KEYS_UPPER_DE
};

static const lv_btnmatrix_ctrl_t * const attributes_upper[] = {
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_UPPER_US,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_UPPER_FR,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_UPPER_ES,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_UPPER_DE
};

static const char ** const keys_numbers[] = {
    (const char * const [])KEYS_NUMBERS_US,
    (const char * const [])KEYS_NUMBERS_FR,
    (const char * const [])KEYS_NUMBERS_ES,
    (const char * const [])KEYS_NUMBERS_DE
};

static const lv_btnmatrix_ctrl_t * const attributes_numbers[] = {
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_NUMBERS_US,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_NUMBERS_FR,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_NUMBERS_ES,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_NUMBERS_DE
};

static const char * const triggers_special[] = {
    (const char * const)TRIGGER_SPECIAL_US,
    (const char * const)TRIGGER_SPECIAL_FR,
    (const char * const)TRIGGER_SPECIAL_ES,
    (const char * const)TRIGGER_SPECIAL_DE
};
static const char ** const keys_special[] = {
    (const char * const [])KEYS_SPECIAL_US,
    (const char * const [])KEYS_SPECIAL_FR,
    (const char * const [])KEYS_SPECIAL_ES,
    (const char * const [])KEYS_SPECIAL_DE
};

static const lv_btnmatrix_ctrl_t * const attributes_special[] = {
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_SPECIAL_US,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_SPECIAL_FR,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_SPECIAL_ES,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_SPECIAL_DE
};

/**
 * Functions
 **/

char *get_layout_names(void) {
    return names;
}

char *get_special_layer_trigger(layout_t layout) {
    if (layout < 0 || layout >= NUM_LAYOUTS) {
        return NULL;
    }
    return triggers_special[layout];
}

void apply_layout(lv_obj_t *keyboard, layout_t layout) {
    if (layout < 0 || layout >= NUM_LAYOUTS) {
        return;
    }
    if (keys_lower[layout][0] != NULL) {
        lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_TEXT_LOWER, keys_lower[layout], attributes_lower[layout]);
    }
    if (keys_upper[layout][0] != NULL) {
        lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_TEXT_UPPER, keys_upper[layout], attributes_upper[layout]);
    }
    if (keys_numbers[layout][0] != NULL) {
        lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_SPECIAL, keys_numbers[layout], attributes_numbers[layout]);
    }
    if (keys_special[layout][0] != NULL) {
        lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_NUMBER, keys_special[layout], attributes_special[layout]);
    }
}
