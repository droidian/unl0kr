#ifndef LAYOUTS_H
#define LAYOUTS_H

#include "lvgl/lvgl.h"

typedef enum {
    LAYOUT_ENGLISH_US = 0,
    LAYOUT_FRENCH     = 1,
    LAYOUT_SPANISH    = 2,
    LAYOUT_GERMAN     = 3
} layout_t;

#define NUM_LAYOUTS 4

char *get_layout_names(void);
void apply_layout(lv_obj_t *keyboard, layout_t layout);

#endif /* LAYOUTS_H */