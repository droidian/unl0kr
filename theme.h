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


#ifndef UL_THEME_H
#define UL_THEME_H

#include "lvgl/lvgl.h"

#include <stdbool.h>
#include <stdint.h>

#define UL_WIDGET_HEADER LV_OBJ_FLAG_USER_1

/**
 * Theming structs
 */

/* Window theme */
typedef struct {
    uint32_t bg_color;
} ul_theme_window;

/* Header theme */
typedef struct {
    uint32_t bg_color;
    lv_coord_t border_width;
    uint32_t border_color;
    lv_coord_t pad;
    lv_coord_t gap;
} ul_theme_header;

/* Key theme for one specific key type and state */
typedef struct {
    uint32_t fg_color;
    uint32_t bg_color;
    uint32_t border_color;
} ul_theme_key_state;

/* Key theme for one specific key type and all states */
typedef struct {
    ul_theme_key_state normal;
    ul_theme_key_state pressed;
} ul_theme_key;

/* Key theme */
typedef struct {
    lv_coord_t border_width;
    lv_coord_t corner_radius;
    ul_theme_key key_char;
    ul_theme_key key_non_char;
    ul_theme_key key_mod_act;
    ul_theme_key key_mod_inact;
} ul_theme_keys;

/* Keyboard theme */
typedef struct {
    uint32_t bg_color;
    lv_coord_t border_width;
    uint32_t border_color;
    lv_coord_t pad;
    lv_coord_t gap;
    ul_theme_keys keys;
} ul_theme_keyboard;

/* Button theme for one specific button state */
typedef struct {
    uint32_t fg_color;
    uint32_t bg_color;
    uint32_t border_color;
} ul_theme_button_state;

/* Button theme */
typedef struct {
    lv_coord_t border_width;
    lv_coord_t corner_radius;
    lv_coord_t pad;
    ul_theme_button_state normal;
    ul_theme_button_state pressed;
} ul_theme_button;

/* Text area cursor theme */
typedef struct {
    lv_coord_t width;
    uint32_t color;
    int period;
} ul_theme_textarea_cursor;

/* Text area theme */
typedef struct {
    uint32_t fg_color;
    uint32_t bg_color;
    lv_coord_t border_width;
    uint32_t border_color;
    lv_coord_t corner_radius;
    lv_coord_t pad;
    uint32_t placeholder_color;
    ul_theme_textarea_cursor cursor;
} ul_theme_textarea;

/* Dropdown list theme */
typedef struct {
    uint32_t fg_color;
    uint32_t bg_color;
    uint32_t selection_fg_color;
    uint32_t selection_bg_color;
    lv_coord_t border_width;
    uint32_t border_color;
    lv_coord_t corner_radius;
    lv_coord_t pad;
} ul_theme_dropdown_list;

/* Dropdown theme */
typedef struct {
    ul_theme_button button;
    ul_theme_dropdown_list list;
} ul_theme_dropdown;

/* Label */
typedef struct {
    uint32_t fg_color;
} ul_theme_label;

/* Message box buttons theme */
typedef struct {
    lv_coord_t gap;
} ul_theme_msgbox_buttons;

/* Message box dimming theme */
typedef struct {
    uint32_t color;
    short opacity;
} ul_theme_msgbox_dimming;

/* Message box theme */
typedef struct {
    uint32_t fg_color;
    uint32_t bg_color;
    lv_coord_t border_width;
    uint32_t border_color;
    lv_coord_t corner_radius;
    lv_coord_t pad;
    lv_coord_t gap;
    ul_theme_msgbox_buttons buttons;
    ul_theme_msgbox_dimming dimming;
} ul_theme_msgbox;

/* Progress bar indicator theme */
typedef struct {
    uint32_t bg_color;
} ul_theme_bar_indicator;

/* Progress bar theme */
typedef struct {
    lv_coord_t border_width;
    uint32_t border_color;
    lv_coord_t corner_radius;
    ul_theme_bar_indicator indicator;
} ul_theme_bar;

/* Full theme */
typedef struct {
    char *name;
    ul_theme_window window;
    ul_theme_header header;
    ul_theme_keyboard keyboard;
    ul_theme_button button;
    ul_theme_textarea textarea;
    ul_theme_dropdown dropdown;
    ul_theme_label label;
    ul_theme_msgbox msgbox;
    ul_theme_bar bar;
} ul_theme;

/**
 * Prepare a keyboard widget to be themed with a theme.
 *
 * @param keyboard keyboard widget
 */
void ul_theme_prepare_keyboard(lv_obj_t *keyboard);

/**
 * Apply a UI theme.
 *
 * @param theme the theme to apply
 */
void ul_theme_apply(const ul_theme *theme);

#endif /* UL_THEME_H */
