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


#include "indev.h"

#include "cursor.h"
#include "log.h"

#include "lv_drivers/indev/libinput_drv.h"

#include <limits.h>


/**
 * Defines
 */

#define MAX_KEYBOARD_DEVS 4
#define MAX_POINTER_DEVS 4
#define MAX_TOUCHSCREEN_DEVS 2


/**
 * Static variables
 */

static int num_keyboard_devs = 0;
static char *keyboard_devs[MAX_KEYBOARD_DEVS];
static lv_indev_t *keyboard_indevs[MAX_KEYBOARD_DEVS];
static lv_indev_drv_t keyboard_indev_drvs[MAX_KEYBOARD_DEVS];
static libinput_drv_state_t keyboard_drv_states[MAX_KEYBOARD_DEVS];

static int num_pointer_devs = 0;
static char *pointer_devs[MAX_POINTER_DEVS];
static lv_indev_t *pointer_indevs[MAX_POINTER_DEVS];
static lv_indev_drv_t pointer_indev_drvs[MAX_POINTER_DEVS];
static libinput_drv_state_t pointer_drv_states[MAX_POINTER_DEVS];

static int num_touchscreen_devs = 0;
static char *touchscreen_devs[MAX_TOUCHSCREEN_DEVS];
static lv_indev_t *touchscreen_indevs[MAX_TOUCHSCREEN_DEVS];
static lv_indev_drv_t touchscreen_indev_drvs[MAX_TOUCHSCREEN_DEVS];
static libinput_drv_state_t touchscreen_drv_states[MAX_TOUCHSCREEN_DEVS];


/**
 * Static prototypes
 */

/**
 * Auto-connect available input devices having a specific capability.
 * 
 * @param capability capability to filter devices by
 * @param max_num_devs maximum number of devices to connect
 * @param num_devs pointer for writing the actual number of connected devices into
 * @param devs array for storing device paths
 * @param indevs array for storing LVGL indevs
 * @param indev_drvs array for storing LVGL indev drivers
 * @param drv_states array for storing LVGL libinput driver states
 */
static void auto_connect(libinput_capability capability, int max_num_devs, int *num_devs, char *devs[], lv_indev_t *indevs[],
                  lv_indev_drv_t indev_drvs[], libinput_drv_state_t drv_states[]);

/**
 * Log a message announcing the connection of an input device.
 * 
 * @param capability the device's capability
 * @param dev the device path
 */
static void log_connection(libinput_capability capability, char *dev);

/**
 * Perform an input read on a device using the libinput driver.
 *
 * @param indev_drv input device driver
 * @param data input device data to write into
 */
static void libinput_read_cb(lv_indev_drv_t *indev_drv, lv_indev_data_t *data);


/**
 * Static functions
 */

static void auto_connect(libinput_capability capability, int max_num_devs, int *num_devs, char *devs[], lv_indev_t *indevs[],
                  lv_indev_drv_t indev_drvs[], libinput_drv_state_t drv_states[]) {

    memset(devs, 0, max_num_devs * sizeof(char *));
    memset(indevs, 0, max_num_devs * sizeof(lv_indev_t *));
    memset(indev_drvs, 0, max_num_devs * sizeof(lv_indev_drv_t));
    memset(drv_states, 0, max_num_devs * sizeof(libinput_drv_state_t));

    *num_devs = libinput_find_devs(capability, devs, max_num_devs, false);

    for (int i = 0; i < *num_devs; ++i) {
        log_connection(capability, devs[i]);

        libinput_init_state(&(drv_states[i]), devs[i]);
        lv_indev_drv_init(&(indev_drvs[i]));

        indev_drvs[i].read_cb = libinput_read_cb;
        indev_drvs[i].user_data = &(drv_states[i]);

        if (capability == LIBINPUT_CAPABILITY_KEYBOARD) {
            indev_drvs[i].type = LV_INDEV_TYPE_KEYPAD;
        } else {
            indev_drvs[i].type = LV_INDEV_TYPE_POINTER;
            indev_drvs[i].long_press_repeat_time = USHRT_MAX;
        }

        indevs[i] = lv_indev_drv_register(&(indev_drvs[i]));
    }
}

static void log_connection(libinput_capability capability, char *dev) {
    switch (capability) {
        case LIBINPUT_CAPABILITY_KEYBOARD:
            ul_log(UL_LOG_LEVEL_VERBOSE, "Connecting keyboard device %s", dev);
            break;
        case LIBINPUT_CAPABILITY_POINTER:
            ul_log(UL_LOG_LEVEL_VERBOSE, "Connecting pointer device %s", dev);
            break;
        case LIBINPUT_CAPABILITY_TOUCH:
            ul_log(UL_LOG_LEVEL_VERBOSE, "Connecting touchscreen device %s", dev);
            break;
        case LIBINPUT_CAPABILITY_NONE:
            break;
    }
}

static void libinput_read_cb(lv_indev_drv_t *indev_drv, lv_indev_data_t *data) {
    libinput_read_state(indev_drv->user_data, indev_drv, data);
}


/**
 * Public functions
 */

void ul_indev_auto_connect(bool keyboard, bool pointer, bool touchscreen) {
    if (keyboard) {
        auto_connect(LIBINPUT_CAPABILITY_KEYBOARD, MAX_KEYBOARD_DEVS, &num_keyboard_devs, keyboard_devs, keyboard_indevs,
            keyboard_indev_drvs, keyboard_drv_states);
    }
    if (pointer) {
        auto_connect(LIBINPUT_CAPABILITY_POINTER, MAX_POINTER_DEVS, &num_pointer_devs, pointer_devs, pointer_indevs,
            pointer_indev_drvs, pointer_drv_states);
    }
    if (touchscreen) {
        auto_connect(LIBINPUT_CAPABILITY_TOUCH, MAX_TOUCHSCREEN_DEVS, &num_touchscreen_devs, touchscreen_devs, touchscreen_indevs,
            touchscreen_indev_drvs, touchscreen_drv_states);
    }
}

bool ul_indev_is_keyboard_connected() {
    return num_keyboard_devs > 0;
}

void ul_indev_set_up_textarea_for_keyboard_input(lv_obj_t *textarea) {
    if (!ul_indev_is_keyboard_connected()) {
        return;
    }

    lv_group_t *group = lv_group_create();
    lv_group_add_obj(group, textarea);

    for (int i = 0; i < num_keyboard_devs; ++i) {
        lv_indev_set_group(keyboard_indevs[i], group);
    }
}

void ul_indev_set_up_mouse_cursor() {
    if (num_pointer_devs == 0) {
        return;
    }
    lv_obj_t *cursor_obj = lv_img_create(lv_scr_act());
    lv_img_set_src(cursor_obj, &ul_cursor_img_dsc);
    for (int i = 0; i < num_pointer_devs; ++i) {
        lv_indev_set_cursor(pointer_indevs[i], cursor_obj);
    }
}
