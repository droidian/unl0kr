/**
 * Copyright 2021 Johannes Marbach
 *
 * This file is part of unl0kr, hereafter referred to as the program.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */


#include "cursor.h"
#include "libinput_multi.h"
#include "libinput_xkb.h"

#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/libinput_drv.h"

#include "lvgl/lvgl.h"

#include "squeek2lvgl/sq2lv.h"

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/reboot.h>
#include <sys/time.h>


/**
 * Custom fonts
 */

LV_FONT_DECLARE(montserrat_extended_32);

#define SYMBOL_ADJUST "\xef\x81\x82" // 0xF042 (https://fontawesome.com/v5.15/icons/adjust?style=solid)


/**
 * Static variables
 */

bool is_dark_theme = false;
bool is_password_hidden = true;
bool is_keyboard_hidden = false;

lv_obj_t *keyboard = NULL;

lv_style_t style_text_normal;


/**
 * Static prototypes
 */

/**
 * Handle LV_EVENT_CLICKED events from the theme toggle button.
 *
 * @param event the event object
 */
static void toggle_theme_btn_clicked_cb(lv_event_t *event);

/**
 * Toggle between the light and dark theme.
 */
static void toggle_theme(void);

/**
 * Set the UI theme.
 *
 * @param is_dark true if the dark theme should be applied, false if the light theme should be applied
 */
static void set_theme(bool is_dark);

/**
 * Handle LV_EVENT_CLICKED events from the show/hide password toggle button.
 *
 * @param event the event object
 */
static void toggle_pw_btn_clicked_cb(lv_event_t *event);

/**
 * Toggle between showing and hiding the password.
 */
static void toggle_password_hidden(void);

/**
 * Show / hide the password.
 *
 * @param is_hidden true if the password should be hidden, false if it should be shown
 */
static void set_password_hidden(bool is_hidden);

/**
 * Handle LV_EVENT_CLICKED events from the show/hide keyboard toggle button.
 *
 * @param event the event object
 */
static void toggle_kb_btn_clicked_cb(lv_event_t *event);

/**
 * Toggle between showing and hiding the keyboard.
 */
static void toggle_keyboard_hidden(void);

/**
 * Show / hide the keyboard
 *
 * @param is_hidden true if the keyboard should be hidden, false if it should be shown
 */
static void set_keyboard_hidden(bool is_hidden);

/**
 * Callback for the keyboard's vertical slide in / out animation.
 *
 * @param obj keyboard widget
 * @param value y position
 */
static void keyboard_anim_y_cb(void *obj, int32_t value);

/**
 * Handle LV_EVENT_READY events from the keyboard layout dropdown.
 *
 * @param event the event object
 */
static void layout_dropdown_ready_cb(lv_event_t *event);

/**
 * Handle LV_EVENT_VALUE_CHANGED events from the keyboard layout dropdown.
 *
 * @param event the event object
 */
static void layout_dropdown_value_changed_cb(lv_event_t *event);

/**
 * Handle LV_EVENT_CLICKED events from the shutdown button.
 *
 * @param event the event object
 */
static void shutdown_btn_clicked_cb(lv_event_t *event);

/**
 * Handle LV_EVENT_VALUE_CHANGED events from the shutdown message box.
 *
 * @param event the event object
 */
static void shutdown_mbox_value_changed_cb(lv_event_t *event);

/**
 * Handle LV_EVENT_DRAW_PART_BEGIN events from the keyboard widget.
 *
 * @param event the event object
 */
static void keyboard_draw_part_begin_cb(lv_event_t *event);

/**
 * Handle LV_EVENT_VALUE_CHANGED events from the keyboard widget.
 *
 * @param event the event object
 */
static void keyboard_value_changed_cb(lv_event_t *event);

/**
 * Handle LV_EVENT_READY events from the keyboard widget.
 *
 * @param event the event object
 */
static void keyboard_ready_cb(lv_event_t *event);


/**
 * Static functions
 */

static void toggle_theme_btn_clicked_cb(lv_event_t *event) {
    toggle_theme();
}

static void toggle_theme(void) {
    is_dark_theme = !is_dark_theme;
    set_theme(is_dark_theme);
}

static void set_theme(bool is_dark) {
    lv_theme_default_init(NULL, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_CYAN), is_dark, &montserrat_extended_32);
}

static void toggle_pw_btn_clicked_cb(lv_event_t *event) {
    toggle_password_hidden();
}

static void toggle_password_hidden(void) {
    is_password_hidden = !is_password_hidden;
    set_password_hidden(is_password_hidden);
}

static void set_password_hidden(bool is_hidden) {
    lv_obj_t *textarea = lv_keyboard_get_textarea(keyboard);
    lv_textarea_set_password_mode(textarea, is_hidden); 
}

static void toggle_kb_btn_clicked_cb(lv_event_t *event) {   
    toggle_keyboard_hidden();
}

static void toggle_keyboard_hidden(void) {
    is_keyboard_hidden = !is_keyboard_hidden;
    set_keyboard_hidden(is_keyboard_hidden);
}

static void set_keyboard_hidden(bool is_hidden) {
    lv_anim_t keyboard_anim;
    lv_anim_init(&keyboard_anim);
    lv_anim_set_var(&keyboard_anim, keyboard);

    if (is_hidden) {
        lv_anim_set_values(&keyboard_anim, 0, lv_obj_get_y(keyboard));
        lv_anim_set_path_cb(&keyboard_anim, lv_anim_path_ease_in_out);
    } else {
        lv_anim_set_values(&keyboard_anim, lv_obj_get_height(keyboard), 0);
        lv_anim_set_path_cb(&keyboard_anim, lv_anim_path_overshoot);
    }

    lv_anim_set_time(&keyboard_anim, 500);
    lv_anim_set_exec_cb(&keyboard_anim, keyboard_anim_y_cb);
    lv_anim_start(&keyboard_anim);
}

static void keyboard_anim_y_cb(void *obj, int32_t value) {
    lv_obj_set_y(obj, value);
}

static void layout_dropdown_ready_cb(lv_event_t *event) {
    lv_obj_t *dropdown = lv_event_get_target(event);
    lv_obj_t *list = lv_dropdown_get_list(dropdown);
    lv_obj_add_style(list, &style_text_normal, 0);
}

static void layout_dropdown_value_changed_cb(lv_event_t *event) {
    lv_obj_t *dropdown = lv_event_get_target(event);
    uint16_t idx = lv_dropdown_get_selected(dropdown);
    sq2lv_switch_layout(keyboard, idx);
}

static void shutdown_btn_clicked_cb(lv_event_t *event) {
    static const char *btns[] = { "Yes", "No", "" };
    lv_obj_t *mbox = lv_msgbox_create(NULL, NULL, "Shutdown device?", btns, false);
    lv_obj_add_event_cb(mbox, shutdown_mbox_value_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_center(mbox);
}

static void shutdown_mbox_value_changed_cb(lv_event_t *event) {
    lv_obj_t *mbox = lv_event_get_current_target(event);
    if (lv_msgbox_get_active_btn(mbox) == 0) {
        sync();
        reboot(RB_POWER_OFF);
    }
    lv_msgbox_close(mbox);
}

static void keyboard_draw_part_begin_cb(lv_event_t *event) {
    lv_obj_t *obj = lv_event_get_target(event);
    lv_btnmatrix_t *btnm = (lv_btnmatrix_t *)obj;
    lv_obj_draw_part_dsc_t *dsc = lv_event_get_param(event);

    if (dsc->part != LV_PART_ITEMS) {
        return;
    }

    if (lv_btnmatrix_get_selected_btn(obj) == dsc->id) { /* key is held down */
        if ((btnm->ctrl_bits[dsc->id] & SQ2LV_CTRL_MOD_INACTIVE) == SQ2LV_CTRL_MOD_INACTIVE) {
            dsc->rect_dsc->bg_color = lv_palette_lighten(LV_PALETTE_TEAL, 1);
        } else if ((btnm->ctrl_bits[dsc->id] & SQ2LV_CTRL_MOD_ACTIVE) == SQ2LV_CTRL_MOD_ACTIVE) {
            dsc->rect_dsc->bg_color = lv_palette_lighten(LV_PALETTE_TEAL, 1);
        } else if ((btnm->ctrl_bits[dsc->id] & SQ2LV_CTRL_NON_CHAR) == SQ2LV_CTRL_NON_CHAR) {
            dsc->rect_dsc->bg_color = lv_palette_darken(LV_PALETTE_BLUE_GREY, 3);
        } else {
            dsc->rect_dsc->bg_color = lv_palette_lighten(LV_PALETTE_BLUE_GREY, 1);
        }
    } else { /* key is not held down */
        if ((btnm->ctrl_bits[dsc->id] & SQ2LV_CTRL_MOD_INACTIVE) == SQ2LV_CTRL_MOD_INACTIVE) {
            dsc->rect_dsc->bg_color = lv_palette_darken(LV_PALETTE_BLUE_GREY, 4);
        } else if ((btnm->ctrl_bits[dsc->id] & SQ2LV_CTRL_MOD_ACTIVE) == SQ2LV_CTRL_MOD_ACTIVE) {
            dsc->rect_dsc->bg_color = lv_palette_main(LV_PALETTE_TEAL);
        } else if ((btnm->ctrl_bits[dsc->id] & SQ2LV_CTRL_NON_CHAR) == SQ2LV_CTRL_NON_CHAR) {
            dsc->rect_dsc->bg_color = lv_palette_darken(LV_PALETTE_BLUE_GREY, 4);
        } else {
            dsc->rect_dsc->bg_color = lv_palette_main(LV_PALETTE_BLUE_GREY);
        }
    }
}

static void keyboard_value_changed_cb(lv_event_t *event) {
    lv_obj_t *kb = lv_event_get_target(event);

    uint16_t btn_id = lv_btnmatrix_get_selected_btn(kb);
    if (btn_id == LV_BTNMATRIX_BTN_NONE) {
        return;
    }

    if (sq2lv_is_layer_switcher(kb, btn_id)) {
        sq2lv_switch_layer(kb, btn_id);
        return;
    }

    lv_keyboard_def_event_cb(event);
}

static void keyboard_ready_cb(lv_event_t *event) {
    lv_obj_t *kb = lv_event_get_target(event);
    lv_obj_t *ta = lv_keyboard_get_textarea(kb);
    printf("%s\n", lv_textarea_get_text(ta));
    exit(0);
}


/**
 * Main
 */

int main(void) {
    /* Initialise lvgl and framebuffer driver */
    lv_init(); 
    fbdev_init();

    /* Query display size */
    uint32_t hor_res;
    uint32_t ver_res;
	fbdev_get_sizes(&hor_res, &ver_res);

    // hor_res = ver_res * 0.6; /* Simulate mobile screen */

    /* Prepare display buffer */
    const size_t buf_size = hor_res * ver_res / 10; /* At least 1/10 of the display size is recommended */
    lv_disp_draw_buf_t disp_buf;
    lv_color_t *buf = (lv_color_t *)malloc(buf_size * sizeof(lv_color_t));
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, buf_size);    

    /* Initialise display driver */
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &disp_buf;
    disp_drv.flush_cb = fbdev_flush;
    disp_drv.hor_res = hor_res;
    disp_drv.ver_res = ver_res;
    lv_disp_drv_register(&disp_drv);

    /* Connect keyboards */
    libinput_xkb_init();
    #define MAX_KEYBOARDS 3
    char *keyboard_devices[MAX_KEYBOARDS] = { NULL, NULL, NULL };
    lv_indev_drv_t keyboard_indev_drvs[MAX_KEYBOARDS];
    lv_indev_t *keyboard_indevs[MAX_KEYBOARDS] = { NULL, NULL, NULL };
    size_t num_keyboards = libinput_find_devs(LIBINPUT_CAPABILITY_KEYBOARD, keyboard_devices, MAX_KEYBOARDS, false);
    for (int i = 0; i < num_keyboards; ++i) {
        printf("found keyboard device %s\n", keyboard_devices[i]);
        lv_indev_drv_init(&keyboard_indev_drvs[i]);
        keyboard_indev_drvs[i].type = LV_INDEV_TYPE_KEYPAD;
        keyboard_indev_drvs[i].read_cb = libinput_multi_read;
        libinput_multi_init_driver(&keyboard_indev_drvs[i]);
        libinput_multi_set_file(&keyboard_indev_drvs[i], keyboard_devices[i]);
        keyboard_indevs[i] = lv_indev_drv_register(&keyboard_indev_drvs[i]);
    }

    /* Hide the on-screen keyboard by default if a physical keyboard is connected */
    if (num_keyboards > 0) {
        is_keyboard_hidden = true;
    }

    /* Connect mice and trackpads */
    #define MAX_POINTER_DEVICES 4
    char *pointer_devices[MAX_POINTER_DEVICES] = { NULL, NULL, NULL, NULL };
    lv_indev_drv_t pointer_indev_drvs[MAX_POINTER_DEVICES];
    lv_indev_t *pointer_indevs[MAX_POINTER_DEVICES] = { NULL, NULL, NULL, NULL };
    size_t num_pointer_devices = libinput_find_devs(LIBINPUT_CAPABILITY_POINTER, pointer_devices, MAX_POINTER_DEVICES, false);
    for (int i = 0; i < num_pointer_devices; ++i) {
        printf("found pointer device %s\n", pointer_devices[i]);
        lv_indev_drv_init(&pointer_indev_drvs[i]);
        pointer_indev_drvs[i].type = LV_INDEV_TYPE_POINTER;
        pointer_indev_drvs[i].read_cb = libinput_multi_read;
        pointer_indev_drvs[i].long_press_repeat_time = USHRT_MAX;
        libinput_multi_init_driver(&pointer_indev_drvs[i]);
        libinput_multi_set_file(&pointer_indev_drvs[i], pointer_devices[i]);
        pointer_indevs[i] = lv_indev_drv_register(&pointer_indev_drvs[i]);
    }

    /* Set mouse cursor */
    if (num_pointer_devices > 0) {
        lv_obj_t *cursor_obj = lv_img_create(lv_scr_act());
        lv_img_set_src(cursor_obj, &ul_cursor_img_dsc);
        for (int i = 0; i < num_pointer_devices; ++i) {
            lv_indev_set_cursor(pointer_indevs[i], cursor_obj);
        }
    }

    /* Connect touchscreens */
    #define MAX_TOUCHSCREENS 1
    char *touchscreens[MAX_TOUCHSCREENS] = { NULL };
    lv_indev_drv_t touchscreen_indev_drvs[MAX_TOUCHSCREENS];
    size_t num_touchscreens = libinput_find_devs(LIBINPUT_CAPABILITY_TOUCH, touchscreens, MAX_TOUCHSCREENS, false);
    for (int i = 0; i < num_touchscreens; ++i) {
        printf("found touchscreen %s\n", touchscreens[i]);
        lv_indev_drv_init(&touchscreen_indev_drvs[i]);
        touchscreen_indev_drvs[i].type = LV_INDEV_TYPE_POINTER;
        touchscreen_indev_drvs[i].read_cb = libinput_multi_read;
        touchscreen_indev_drvs[i].long_press_repeat_time = USHRT_MAX;
        libinput_multi_init_driver(&touchscreen_indev_drvs[i]);
        libinput_multi_set_file(&touchscreen_indev_drvs[i], touchscreens[i]);
        lv_indev_drv_register(&touchscreen_indev_drvs[i]);
    }

    /* Initialise theme and styles */
    set_theme(is_dark_theme);
    lv_style_init(&style_text_normal);
    lv_style_set_text_font(&style_text_normal, &montserrat_extended_32);

    /* Figure out a few numbers for sizing and positioning */
    const int keyboard_height = ver_res / 3;
    const int row_height = keyboard_height / 4;

    /* Button row */
    lv_obj_t *btn_row = lv_obj_create(lv_scr_act());
    static lv_coord_t btn_row_col_dsc[] = { 64, 64, LV_GRID_FR(1), 64, LV_GRID_TEMPLATE_LAST };
    static lv_coord_t btn_row_row_dsc[] = { 64, LV_GRID_TEMPLATE_LAST };
    lv_obj_set_grid_dsc_array(btn_row, btn_row_col_dsc, btn_row_row_dsc);
    lv_obj_set_size(btn_row, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_align(btn_row, LV_ALIGN_TOP_MID, 0, 0);

    /* Theme switcher button */
    lv_obj_t *toggle_theme_btn = lv_btn_create(btn_row);
    lv_obj_add_event_cb(toggle_theme_btn, toggle_theme_btn_clicked_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_grid_cell(toggle_theme_btn, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_size(toggle_theme_btn, 64, 64);
    lv_obj_t *toggle_theme_btn_label = lv_label_create(toggle_theme_btn);
    lv_label_set_text(toggle_theme_btn_label, SYMBOL_ADJUST);
    lv_obj_center(toggle_theme_btn_label);
    lv_obj_add_style(toggle_theme_btn_label, &style_text_normal, 0);

    /* Show / hide keyboard button */
    lv_obj_t *toggle_kb_btn = lv_btn_create(btn_row);
    lv_obj_add_event_cb(toggle_kb_btn, toggle_kb_btn_clicked_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_grid_cell(toggle_kb_btn, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_size(toggle_kb_btn, 64, 64);
    lv_obj_t *toggle_kb_btn_label = lv_label_create(toggle_kb_btn);
    lv_label_set_text(toggle_kb_btn_label, LV_SYMBOL_KEYBOARD);
    lv_obj_center(toggle_kb_btn_label);
    lv_obj_add_style(toggle_kb_btn_label, &style_text_normal, 0);

    /* Keyboard layout dropdown */
    lv_obj_t *layout_dropdown = lv_dropdown_create(btn_row);
    lv_dropdown_set_options(layout_dropdown, sq2lv_layout_short_names);
    lv_obj_add_event_cb(layout_dropdown, layout_dropdown_ready_cb, LV_EVENT_READY, NULL);
    lv_obj_add_event_cb(layout_dropdown, layout_dropdown_value_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_set_grid_cell(layout_dropdown, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_height(layout_dropdown, 64);
    lv_obj_set_width(layout_dropdown, 160);
    lv_obj_add_style(layout_dropdown, &style_text_normal, 0);

    /* Shutdown button */
    lv_obj_t *shutdown_btn = lv_btn_create(btn_row);
    lv_obj_add_event_cb(shutdown_btn, shutdown_btn_clicked_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_set_grid_cell(shutdown_btn, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_set_size(shutdown_btn, 64, 64);
    lv_obj_t *shutdown_btn_label = lv_label_create(shutdown_btn);
    lv_label_set_text(shutdown_btn_label, LV_SYMBOL_POWER);
    lv_obj_center(shutdown_btn_label);
    lv_obj_add_style(shutdown_btn_label, &style_text_normal, 0);

    /* Textarea */
    lv_obj_t *textarea = lv_textarea_create(lv_scr_act());
    lv_textarea_set_one_line(textarea, true);
    lv_textarea_set_password_mode(textarea, true);
    lv_textarea_set_placeholder_text(textarea, "Enter password...");
    lv_obj_set_size(textarea, hor_res - 60 > 512 ? 512 : hor_res - 60, 64);
    lv_obj_align(textarea, LV_ALIGN_CENTER, 0, ver_res / 2 - keyboard_height - 3 * row_height / 2);
    lv_obj_add_state(textarea, LV_STATE_FOCUSED);
    lv_obj_add_style(textarea, &style_text_normal, 0);

    /* Route physical keyboard input into textarea */
    lv_group_t *group = lv_group_create();
    lv_group_add_obj(group, textarea);
    for (int i = 0; i < num_keyboards; ++i) {
        lv_indev_set_group(keyboard_indevs[i], group);
    }

    /* Show / hide password button */
    lv_obj_t *toggle_pw_btn = lv_btn_create(lv_scr_act());
    lv_obj_align(toggle_pw_btn, LV_ALIGN_CENTER, (hor_res - 60 > 512 ? 512 : hor_res - 60) / 2 + 32, ver_res / 2 - keyboard_height - 3 * row_height / 2);
    lv_obj_set_size(toggle_pw_btn, 64, 64);
    lv_obj_t *toggle_pw_btn_label = lv_label_create(toggle_pw_btn);
    lv_obj_center(toggle_pw_btn_label);
    lv_label_set_text(toggle_pw_btn_label, LV_SYMBOL_EYE_OPEN);
    lv_obj_add_event_cb(toggle_pw_btn, toggle_pw_btn_clicked_cb, LV_EVENT_CLICKED, NULL);
    lv_obj_add_style(toggle_pw_btn_label, &style_text_normal, 0);

    /* Label */
    lv_obj_t *spangroup = lv_spangroup_create(lv_scr_act());
    lv_spangroup_set_align(spangroup, LV_TEXT_ALIGN_CENTER);
    lv_spangroup_set_mode(spangroup, LV_SPAN_MODE_BREAK);
    lv_obj_set_size(spangroup, hor_res - 40, 2 * row_height);
    lv_obj_align(spangroup, LV_ALIGN_CENTER, 0, ver_res / 2 - keyboard_height);
    lv_obj_add_style(spangroup, &style_text_normal, 0);
    lv_span_t *span1 = lv_spangroup_new_span(spangroup);
    lv_span_set_text(span1, "Password required to unlock ");
    lv_span_t *span2 = lv_spangroup_new_span(spangroup);
    lv_span_set_text(span2, "/dev/sda1");
    lv_style_set_text_color(&span2->style, lv_palette_main(LV_PALETTE_RED));

    /* Keyboard (after textarea / label so that key popovers are not drawn over) */
    keyboard = lv_keyboard_create(lv_scr_act());
    lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_TEXT_LOWER);
    lv_keyboard_set_textarea(keyboard, textarea);
    // lv_btnmatrix_set_popovers(keyboard, true);
    lv_obj_remove_event_cb(keyboard, lv_keyboard_def_event_cb);
    lv_obj_add_event_cb(keyboard, keyboard_draw_part_begin_cb, LV_EVENT_DRAW_PART_BEGIN, NULL);
    lv_obj_add_event_cb(keyboard, keyboard_value_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(keyboard, keyboard_ready_cb, LV_EVENT_READY, NULL);
    lv_obj_set_pos(keyboard, 0, is_keyboard_hidden ? keyboard_height : 0);
    lv_obj_set_size(keyboard, hor_res, keyboard_height);
    lv_obj_add_style(keyboard, &style_text_normal, 0);

    /* Apply defaults */
    sq2lv_switch_layout(keyboard, 0);
    set_password_hidden(is_password_hidden);

    /* Run lvgl in "tickless" mode */
    while(1) {
        lv_task_handler();
        usleep(5000);
    }

    return 0;
}


/**
 * Tick generation
 */

/**
 * Generate tick for LVGL.
 * 
 * @return tick in ms
 */
uint32_t ul_get_tick(void) {
    static uint64_t start_ms = 0;
    if (start_ms == 0) {
        struct timeval tv_start;
        gettimeofday(&tv_start, NULL);
        start_ms = (tv_start.tv_sec * 1000000 + tv_start.tv_usec) / 1000;
    }

    struct timeval tv_now;
    gettimeofday(&tv_now, NULL);
    uint64_t now_ms;
    now_ms = (tv_now.tv_sec * 1000000 + tv_now.tv_usec) / 1000;

    uint32_t time_ms = now_ms - start_ms;
    return time_ms;
}
