#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/reboot.h>
#include <sys/time.h>

#include "lvgl/lvgl.h"
#include "lv_drivers/display/fbdev.h"
#include "lv_drivers/indev/libinput_drv.h"

#include "cursor.h"
#include "libinput_multi.h"
#include "libinput_xkb.h"

#include "squeek2lvgl/sq2lv.h"

// Custom fonts

LV_FONT_DECLARE(montserrat_extended_32);

// Custom symbols

#define SYMBOL_ADJUST "\xef\x81\x82" // 0xF042 https://fontawesome.com/v5.15/icons/adjust?style=solid

// Global variables

bool is_dark_theme = false;
bool is_password_hidden = true;

lv_obj_t *textarea = NULL;
lv_obj_t *keyboard = NULL;

lv_style_t style_text_normal;

// Helpers

void set_theme(bool is_dark);

void set_theme(bool is_dark) {
    lv_theme_default_init(
            NULL, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_CYAN), is_dark, &montserrat_extended_32);
}

void set_password_hidden(bool is_disclosed);

void set_password_hidden(bool is_disclosed) {
    lv_textarea_set_password_mode(textarea, is_password_hidden);
}

// Animations

void keyboard_anim_y_cb(void *obj, int32_t value);

void keyboard_anim_y_cb(void *obj, int32_t value) {
    lv_obj_set_y(obj, value);
}

// Event callbacks

void keyboard_event_ready_cb(lv_event_t *e);

void keyboard_event_ready_cb(lv_event_t *e) {
    lv_obj_t *obj = lv_keyboard_get_textarea(lv_event_get_target(e));
    char *password = lv_textarea_get_text(obj);
    printf("You entered %s\n", password);
    abort();
}

void keyboard_event_cancel_cb(lv_event_t *e);

void keyboard_event_cancel_cb(lv_event_t *e) {
    abort();
}

void keyboard_event_value_changed_cb(lv_event_t * e);

void keyboard_event_value_changed_cb(lv_event_t * e) {
    lv_obj_t *obj = lv_event_get_target(e);

    uint16_t btn_id = lv_btnmatrix_get_selected_btn(obj);
    if (btn_id == LV_BTNMATRIX_BTN_NONE) {
        return;
    }

    if (sq2lv_is_layer_switcher(obj, btn_id)) {
        sq2lv_switch_layer(obj, btn_id);
        return;
    }

    lv_keyboard_def_event_cb(e);
}

void discloser_event_cb(lv_event_t *e);

void discloser_event_cb(lv_event_t *e) {
    if(lv_event_get_code(e) == LV_EVENT_VALUE_CHANGED) {
        is_password_hidden = !is_password_hidden;
        set_password_hidden(is_password_hidden);
    }
}

void theme_switcher_event_cb(lv_event_t *e);

void theme_switcher_event_cb(lv_event_t *e) {
    if(lv_event_get_code(e) == LV_EVENT_VALUE_CHANGED) {
        is_dark_theme = !is_dark_theme;
        set_theme(is_dark_theme);
    }
}

void keyboard_toggle_event_cb(lv_event_t *e);

void keyboard_toggle_event_cb(lv_event_t *e) {
    if(lv_event_get_code(e) == LV_EVENT_VALUE_CHANGED) {
        lv_anim_t keyboard_anim;
        lv_anim_init(&keyboard_anim);
        lv_anim_set_var(&keyboard_anim, keyboard);

        lv_obj_t *btn = lv_event_get_target(e);
        if (lv_obj_has_state(btn, LV_STATE_CHECKED)) {
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
}

void keymap_dropdown_event_cb(lv_event_t *e);

void keymap_dropdown_event_cb(lv_event_t *e) {
    switch (lv_event_get_code(e)) {
        case LV_EVENT_READY: {
            lv_obj_add_style(lv_dropdown_get_list(lv_event_get_target(e)), &style_text_normal, 0);
            break;
        }
        case LV_EVENT_VALUE_CHANGED: {
            uint16_t idx = lv_dropdown_get_selected(lv_event_get_target(e));
            sq2lv_switch_layout(keyboard, idx);
            break;
        }
        default:
            break;
    }
}

void mbox_event_cb(lv_event_t *e);

void mbox_event_cb(lv_event_t *e) {
    lv_obj_t *obj = lv_event_get_current_target(e);
    if (strcmp(lv_msgbox_get_active_btn_text(obj), "Yes") == 0) {
        abort();
        // TODO: actually shut down
        // sync();
        // reboot(RB_POWER_OFF);
    }
    lv_msgbox_close(obj);
}

void power_btn_event_cb(lv_event_t *e);

void power_btn_event_cb(lv_event_t *e) {
    static const char *btns[] ={ "Yes", "No", "" };
    lv_obj_t * mbox = lv_msgbox_create(NULL, NULL, "Do you want to shutdown the device?", btns, false);
    lv_obj_add_event_cb(mbox, mbox_event_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_center(mbox);
}


// Main

int main(void)
{
    // Initialise lvgl, framebuffer driver and XKB system
    lv_init(); 
    fbdev_init();
    libinput_xkb_init();

    // Query display size
    uint32_t hor_res;
    uint32_t ver_res;
	fbdev_get_sizes(&hor_res, &ver_res);

    // hor_res = ver_res * 0.6; /* To simulate mobile screen */

    // Prepare display buffer
    const size_t buf_size = hor_res * ver_res / 10; // At least 1/10 of the display size is recommended
    lv_disp_draw_buf_t disp_buf;
    lv_color_t *buf = (lv_color_t *)malloc(buf_size * sizeof(lv_color_t));
    lv_disp_draw_buf_init(&disp_buf, buf, NULL, buf_size);    

    // Initialise display driver
    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.draw_buf = &disp_buf;
    disp_drv.flush_cb = fbdev_flush;
    disp_drv.hor_res = hor_res;
    disp_drv.ver_res = ver_res;
    lv_disp_drv_register(&disp_drv);

    // Connect keyboards
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

    // Connect mice and trackpads
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

    // Connect touchscreens
    #define MAX_TOUCHSCREENS 1
    char *touchscreens[MAX_TOUCHSCREENS] = { NULL };
    lv_indev_drv_t touchscreen_indev_drvs[MAX_TOUCHSCREENS];
    lv_indev_t *touchscreen_indevs[MAX_TOUCHSCREENS] = { NULL };
    size_t num_touchscreens = libinput_find_devs(LIBINPUT_CAPABILITY_TOUCH, touchscreens, MAX_TOUCHSCREENS, false);
    for (int i = 0; i < num_touchscreens; ++i) {
        printf("found touchscreen %s\n", touchscreens[i]);
        lv_indev_drv_init(&touchscreen_indev_drvs[i]);
        touchscreen_indev_drvs[i].type = LV_INDEV_TYPE_POINTER;
        touchscreen_indev_drvs[i].read_cb = libinput_multi_read;
        touchscreen_indev_drvs[i].long_press_repeat_time = USHRT_MAX;
        libinput_multi_init_driver(&touchscreen_indev_drvs[i]);
        libinput_multi_set_file(&touchscreen_indev_drvs[i], touchscreens[i]);
        touchscreen_indevs[i] = lv_indev_drv_register(&touchscreen_indev_drvs[i]);
    }

    // Set mouse cursor
    if (num_pointer_devices > 0) {
        lv_obj_t *cursor_obj = lv_img_create(lv_scr_act());
        lv_img_set_src(cursor_obj, &ul_cursor_img_dsc);
        for (int i = 0; i < num_pointer_devices; ++i) {
            lv_indev_set_cursor(pointer_indevs[i], cursor_obj);
        }
    }

    // Build the UI...

    // Initialise theme
    set_theme(is_dark_theme);

    // Initialise styles
    lv_style_init(&style_text_normal);
    lv_style_set_text_font(&style_text_normal, &montserrat_extended_32);

    // Figure out a few numbers for sizing and positioning
    const int keyboard_height = ver_res / 3;
    const int row_height = keyboard_height / 4;

    // Textarea
    textarea = lv_textarea_create(lv_scr_act());
    lv_textarea_set_one_line(textarea, true);
    lv_textarea_set_password_mode(textarea, true);
    lv_textarea_set_placeholder_text(textarea, "Enter password...");
    lv_obj_set_size(textarea, hor_res - 60 > 512 ? 512 : hor_res - 60, 64);
    lv_obj_align(textarea, LV_ALIGN_CENTER, 0, ver_res / 2 - keyboard_height - 3 * row_height / 2);
    lv_obj_add_state(textarea, LV_STATE_FOCUSED);
    lv_obj_add_style(textarea, &style_text_normal, 0);

    // Label
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

    // Keyboard (after textarea / label to draw key popovers over them)
    keyboard = lv_keyboard_create(lv_scr_act());
    lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_TEXT_LOWER);
    // lv_btnmatrix_set_popovers(keyboard, true);
    lv_obj_set_pos(keyboard, 0, 0);
    lv_obj_set_size(keyboard, hor_res, keyboard_height);
    lv_obj_add_style(keyboard, &style_text_normal, 0);

    // Disclosure button
    lv_obj_t *discloser = lv_btn_create(lv_scr_act());
    lv_obj_align(discloser, LV_ALIGN_CENTER, (hor_res - 60 > 512 ? 512 : hor_res - 60) / 2 + 32, ver_res / 2 -keyboard_height - 3 * row_height / 2);
    lv_obj_add_flag(discloser, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_size(discloser, 64, 64);
    lv_obj_t *discloser_label = lv_label_create(discloser);
    lv_obj_center(discloser_label);
    lv_label_set_text(discloser_label, LV_SYMBOL_EYE_OPEN);
    lv_obj_add_event_cb(discloser, discloser_event_cb, LV_EVENT_ALL, NULL);
    lv_obj_add_style(discloser_label, &style_text_normal, 0);
    set_password_hidden(is_password_hidden);
    
    // Route keyboard input into textarea
    lv_group_t *group = lv_group_create();
    lv_group_add_obj(group, textarea);
    for (int i = 0; i < num_keyboards; ++i) {
        lv_indev_set_group(keyboard_indevs[i], group);
    }

    lv_keyboard_set_textarea(keyboard, textarea); // Connect keyboard and textarea

    // Set up handlers for keyboard events
    lv_obj_remove_event_cb(keyboard, lv_keyboard_def_event_cb);
    lv_obj_add_event_cb(keyboard, keyboard_event_value_changed_cb, LV_EVENT_VALUE_CHANGED, NULL);
    lv_obj_add_event_cb(keyboard, keyboard_event_cancel_cb, LV_EVENT_CANCEL, NULL);
    lv_obj_add_event_cb(keyboard, keyboard_event_ready_cb, LV_EVENT_READY, NULL);

    // Button row
    static lv_coord_t btn_row_col_dsc[] = { 64, 64, LV_GRID_FR(1), 64, LV_GRID_TEMPLATE_LAST };
    static lv_coord_t btn_row_row_dsc[] = { 64, LV_GRID_TEMPLATE_LAST };
    lv_obj_t *btn_row = lv_obj_create(lv_scr_act());
    lv_obj_set_size(btn_row, LV_PCT(100), LV_SIZE_CONTENT);
    lv_obj_align(btn_row, LV_ALIGN_TOP_MID, 0, 0);
    lv_obj_set_grid_dsc_array(btn_row, btn_row_col_dsc, btn_row_row_dsc);

    // Theme switcher
    lv_obj_t *theme_switcher = lv_btn_create(btn_row);
    lv_obj_add_flag(theme_switcher, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_size(theme_switcher, 64, 64);
    lv_obj_set_grid_cell(theme_switcher, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_t *theme_switcher_label = lv_label_create(theme_switcher);
    lv_obj_add_style(theme_switcher_label, &style_text_normal, 0);
    lv_obj_center(theme_switcher_label);
    lv_label_set_text(theme_switcher_label, SYMBOL_ADJUST);
    lv_obj_add_event_cb(theme_switcher, theme_switcher_event_cb, LV_EVENT_ALL, NULL);

    // Keyboard toggle
    lv_obj_t *keyboard_toggle = lv_btn_create(btn_row);
    lv_obj_add_flag(keyboard_toggle, LV_OBJ_FLAG_CHECKABLE);
    lv_obj_set_size(keyboard_toggle, 64, 64);
    lv_obj_set_grid_cell(keyboard_toggle, LV_GRID_ALIGN_CENTER, 1, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_t *keyboard_toggle_label = lv_label_create(keyboard_toggle);
    lv_obj_add_style(keyboard_toggle_label, &style_text_normal, 0);
    lv_obj_center(keyboard_toggle_label);
    lv_label_set_text(keyboard_toggle_label, LV_SYMBOL_KEYBOARD);
    lv_obj_add_event_cb(keyboard_toggle, keyboard_toggle_event_cb, LV_EVENT_ALL, NULL);

    // Keymap dropdown
    lv_obj_t *dropdown = lv_dropdown_create(btn_row);
    lv_dropdown_set_options(dropdown, sq2lv_layout_short_names);
    lv_obj_set_height(dropdown, 64);
    lv_obj_set_width(dropdown, 160);
    lv_obj_set_grid_cell(dropdown, LV_GRID_ALIGN_START, 2, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_add_style(dropdown, &style_text_normal, 0);
    lv_obj_add_event_cb(dropdown, keymap_dropdown_event_cb, LV_EVENT_ALL, NULL);

    // Power button
    lv_obj_t *power_btn = lv_btn_create(btn_row);
    lv_obj_set_size(power_btn, 64, 64);
    lv_obj_set_grid_cell(power_btn, LV_GRID_ALIGN_CENTER, 3, 1, LV_GRID_ALIGN_CENTER, 0, 1);
    lv_obj_t *power_btn_label = lv_label_create(power_btn);
    lv_obj_add_style(power_btn_label, &style_text_normal, 0);
    lv_obj_center(power_btn_label);
    lv_label_set_text(power_btn_label, LV_SYMBOL_POWER);
    lv_obj_add_event_cb(power_btn, power_btn_event_cb, LV_EVENT_CLICKED, NULL);

    /* Apply default keyboard layout */
    sq2lv_switch_layout(keyboard, 0);

    // Run lvgl in tickless mode
    while(1) {
        lv_task_handler();
        usleep(5000);
    }

    return 0;
}

// Tick generator

uint32_t custom_tick_get(void)
{
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
