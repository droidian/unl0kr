#include "layouts.h"
#include "uskr_layouts.h"

char *get_layout_names(void) {
    return names;
}

char *get_special_layer_trigger(uskr_layout_t layout) {
    if (layout < 0 || layout >= USKR_NUM_LAYOUTS) {
        return NULL;
    }
    return triggers_special[layout];
}

void apply_layout(lv_obj_t *keyboard, uskr_layout_t layout) {
    if (layout < 0 || layout >= USKR_NUM_LAYOUTS) {
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
