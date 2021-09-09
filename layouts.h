#ifndef LAYOUTS_H
#define LAYOUTS_H

#include "uskr_layouts.h"

char *get_layout_names(void);
char *get_special_layer_trigger(uskr_layout_t layout);
void apply_layout(lv_obj_t *keyboard, uskr_layout_t layout);

#endif /* LAYOUTS_H */