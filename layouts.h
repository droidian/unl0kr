#ifndef LAYOUTS_H
#define LAYOUTS_H

#include "lvgl/lvgl.h"

typedef enum {
    LAYOUT_ENGLISH_US = 0,
    LAYOUT_GERMAN     = 1
} layout_t;

#define NUM_LAYOUTS 2

char *get_layout_names(void);
void apply_layout(lv_obj_t *keyboard, layout_t layout);

#endif /* LAYOUTS_H */