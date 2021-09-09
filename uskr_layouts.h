#ifndef USKR_LAYOUTS_H
#define USKR_LAYOUTS_H

/**
 * Auto-generated with unsqu33kr
 **/

#include "lvgl/lvgl.h"

typedef enum {
    USKR_LAYOUT_US = 0,
    USKR_LAYOUT_FR = 1,
    USKR_LAYOUT_ES = 2,
    USKR_LAYOUT_DE = 3
} uskr_layout_t;

#define USKR_NUM_LAYOUTS 4

extern const char * const names;
extern const char ** const keys_lower[];
extern const lv_btnmatrix_ctrl_t * const attributes_lower[];

extern const char ** const keys_upper[];
extern const lv_btnmatrix_ctrl_t * const attributes_upper[];

extern const char ** const keys_numbers[];
extern const lv_btnmatrix_ctrl_t * const attributes_numbers[];

extern const char * const triggers_special[];
extern const char ** const keys_special[];
extern const lv_btnmatrix_ctrl_t * const attributes_special[];

#endif /* USKR_LAYOUTS_H */
