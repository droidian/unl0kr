/**
 * Auto-generated with squeek2lvgl
 **/

#ifndef SQ2LV_LAYOUTS_H
#define SQ2LV_LAYOUTS_H

#include "lvgl/lvgl.h"

#define SQ2LV_SCANCODES_ENABLED 0

/* Key attributes */
#define SQ2LV_CTRL_NON_CHAR     (LV_BTNMATRIX_CTRL_NO_REPEAT | LV_BTNMATRIX_CTRL_CLICK_TRIG | LV_BTNMATRIX_CTRL_CHECKED)
#define SQ2LV_CTRL_MOD_ACTIVE   (LV_BTNMATRIX_CTRL_NO_REPEAT | LV_BTNMATRIX_CTRL_CLICK_TRIG | LV_BTNMATRIX_CTRL_CHECKABLE)
#define SQ2LV_CTRL_MOD_INACTIVE (LV_BTNMATRIX_CTRL_NO_REPEAT | LV_BTNMATRIX_CTRL_CLICK_TRIG | LV_BTNMATRIX_CTRL_CHECKABLE | LV_BTNMATRIX_CTRL_CHECKED)

/* Layout IDs, values can be used as indexes into the sq2lv_layouts array */
typedef enum {
    SQ2LV_LAYOUT_NONE = -1,
    SQ2LV_LAYOUT_US = 0,
    SQ2LV_LAYOUT_DE = 1,
    SQ2LV_LAYOUT_ES = 2,
    SQ2LV_LAYOUT_FR = 3
} sq2lv_layout_id_t;

/* Layer type */
typedef struct {
    /* Number of keys */
    const int num_keys;
    /* Key caps */
    const char * const * const keycaps;
    /* Key attributes */
    const lv_btnmatrix_ctrl_t * const attributes;
    /* Number of modifier keys */
    const int num_modifiers;
    /* Button indexes of modifier keys */
    const int * const modifier_idxs;
    /* Number of buttons that trigger a layer switch */
    const int num_switchers;
    /* Button indexes that trigger a layer switch */
    const int * const switcher_idxs;
    /* Indexes of layers to jump to when triggering layer switch buttons */
    const int * const switcher_dests;
} sq2lv_layer_t;

/* Layout type */
typedef struct {
    /* Layout name */
    const char * const name;
    /* Layout short name */
    const char * const short_name;
    /* Total number of layers */
    const int num_layers;
    /* Layers array */
    const sq2lv_layer_t * const layers;
} sq2lv_layout_t;

/* Layouts */
extern const int sq2lv_num_layouts;
extern const sq2lv_layout_t sq2lv_layouts[];

/* Layout names (suitable for use in lv_dropdown_t) */
extern const char * const sq2lv_layout_names;
extern const char * const sq2lv_layout_short_names;

#endif /* SQ2LV_LAYOUTS_H */
