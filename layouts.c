#include "layouts.h"

/**
 * English (US)
 **/

#define NAME_ENGLISH_US "English (US)"

/* Lowercase layer */
#define KEYS_LOWER_ENGLISH_US { \
    "1#", "q", "w", "e", "r", "t", "y", "u", "i", "o", "p", LV_SYMBOL_BACKSPACE, "\n", \
    "ABC", "a", "s", "d", "f", "g", "h", "j", "k", "l", LV_SYMBOL_NEW_LINE, "\n", \
    "_", "-", "z", "x", "c", "v", "b", "n", "m", ".", ",", ":", "\n", \
    LV_SYMBOL_KEYBOARD, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_LOWER_ENGLISH_US { \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BTNMATRIX_CTRL_CHECKED | 7, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, LV_BTNMATRIX_CTRL_CHECKED | 7, \
    LV_BTNMATRIX_CTRL_CHECKED | 1, LV_BTNMATRIX_CTRL_CHECKED | 1,  1, 1, 1, 1, 1, 1, 1, LV_BTNMATRIX_CTRL_CHECKED | 1, LV_BTNMATRIX_CTRL_CHECKED | 1, LV_BTNMATRIX_CTRL_CHECKED | 1, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 6, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2 \
}

/* Uppercase layer */
#define KEYS_UPPER_ENGLISH_US { \
    "1#", "Q", "W", "E", "R", "T", "Y", "U", "I", "O", "P", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "A", "S", "D", "F", "G", "H", "J", "K", "L", LV_SYMBOL_NEW_LINE, "\n", \
    "_", "-", "Z", "X", "C", "V", "B", "N", "M", ".", ",", ":", "\n", \
    LV_SYMBOL_KEYBOARD, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_UPPER_ENGLISH_US { \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 5, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, LV_BTNMATRIX_CTRL_CHECKED | 7, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 6, 3, 3, 3, 3, 3, 3, 3, 3, 3, LV_BTNMATRIX_CTRL_CHECKED | 7, \
    LV_BTNMATRIX_CTRL_CHECKED | 1, LV_BTNMATRIX_CTRL_CHECKED | 1, 1, 1, 1, 1, 1, 1,  1, LV_BTNMATRIX_CTRL_CHECKED | 1, LV_BTNMATRIX_CTRL_CHECKED | 1, LV_BTNMATRIX_CTRL_CHECKED | 1, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 6, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2 \
}

/* Symbol layer */
#define KEYS_SYMBOL_ENGLISH_US { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "+", "-", "/", "*", "=", "%", "!", "?", "#", "<", ">", "\n", \
    "\\",  "@", "$", "(", ")", "{", "}", "[", "]", ";", "\"", "'", "\n", \
    LV_SYMBOL_KEYBOARD, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_SYMBOL_ENGLISH_US { \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, LV_BTNMATRIX_CTRL_CHECKED | 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 6, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2 \
}

/**
 * German
 **/

#define NAME_GERMAN "German"

/* Lowercase layer */
#define KEYS_LOWER_GERMAN { \
    "q", "w", "e", "r", "t", "z", "u", "i", "o", "p", "ü", "\n", \
    "a", "s", "d", "f", "g", "h", "j", "k", "l", "ö", "ä", "\n", \
    "ABC", "_", "y", "x", "c", "v", "b", "n", "m", "_", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_LOWER_GERMAN { \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_BTNMATRIX_CTRL_HIDDEN | 1, 2, 2, 2, 2, 2, 2, 2, LV_BTNMATRIX_CTRL_HIDDEN | 1, LV_BTNMATRIX_CTRL_CHECKED | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 7, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2 \
}

/* Uppercase layer */
#define KEYS_UPPER_GERMAN { \
    "Q", "W", "E", "R", "T", "Z", "U", "I", "O", "P", "Ü", "\n", \
    "A", "S", "D", "F", "G", "H", "J", "K", "L", "Ö", "Ä", "\n", \
    "abc", "_", "Y", "X", "C", "V", "B", "N", "M", "_", LV_SYMBOL_BACKSPACE, "\n", \
    "1#", LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_UPPER_GERMAN { \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 3, LV_BTNMATRIX_CTRL_HIDDEN | 1, 2, 2, 2, 2, 2, 2, 2, LV_BTNMATRIX_CTRL_HIDDEN | 1, LV_BTNMATRIX_CTRL_CHECKED | 3, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 7, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2 \
}

/* Symbol layer */
#define KEYS_SYMBOL_GERMAN { \
    "1", "2", "3", "4", "5", "6", "7", "8", "9", "0", LV_SYMBOL_BACKSPACE, "\n", \
    "abc", "+", "-", "/", "*", "=", "%", "!", "?", "#", "<", ">", "\n", \
    "\\",  "@", "$", "(", ")", "{", "}", "[", "]", ";", "\"", "'", "\n", \
    LV_SYMBOL_KEYBOARD, LV_SYMBOL_LEFT, " ", LV_SYMBOL_RIGHT, LV_SYMBOL_OK, "" \
}
#define ATTRIBUTES_SYMBOL_GERMAN { \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, LV_BTNMATRIX_CTRL_CHECKED | 2, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, \
    LV_KEYBOARD_CTRL_BTN_FLAGS | 2, LV_BTNMATRIX_CTRL_CHECKED | 2, 6, LV_BTNMATRIX_CTRL_CHECKED | 2, LV_KEYBOARD_CTRL_BTN_FLAGS | 2 \
}

/**
 * All layouts
 **/

static const char * const names =
    LV_SYMBOL_KEYBOARD " " NAME_ENGLISH_US "\n"
    LV_SYMBOL_KEYBOARD " " NAME_GERMAN;

static const char ** const keys_lower[] = {
    (const char * const [])KEYS_LOWER_ENGLISH_US,
    (const char * const [])KEYS_LOWER_GERMAN
};

static const lv_btnmatrix_ctrl_t * const attributes_lower[] = {
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_LOWER_ENGLISH_US,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_LOWER_GERMAN
};

static const char ** const keys_upper[] = {
    (const char * const [])KEYS_UPPER_ENGLISH_US,
    (const char * const [])KEYS_UPPER_GERMAN
};

static const lv_btnmatrix_ctrl_t *attributes_upper[] = {
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_UPPER_ENGLISH_US,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_UPPER_GERMAN
};

static const char ** const keys_symbol[] = {
    (const char * const [])KEYS_SYMBOL_ENGLISH_US,
    (const char * const [])KEYS_SYMBOL_GERMAN
};

static const lv_btnmatrix_ctrl_t *attributes_symbol[] = {
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_SYMBOL_ENGLISH_US,
    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_SYMBOL_GERMAN
};

/**
 * Functions
 **/

char *get_layout_names(void) {
    return names;
}

void apply_layout(lv_obj_t *keyboard, layout_t layout) {
    if (layout < 0 || layout >= NUM_LAYOUTS) {
        return;
    }
    lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_TEXT_LOWER, keys_lower[layout], attributes_lower[layout]);
    lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_TEXT_UPPER, keys_upper[layout], attributes_upper[layout]);
    lv_keyboard_set_map(keyboard, LV_KEYBOARD_MODE_SPECIAL, keys_symbol[layout], attributes_symbol[layout]);
}
