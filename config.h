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


#ifndef UL_CONFIG_H
#define UL_CONFIG_H

#include "sq2lv_layouts.h"

#include <stdbool.h>

/**
 * General options
 */
typedef struct {
    /* If true, use animations */
    bool animations;
} ul_config_opts_general;

/**
 * Options related to the password textarea
 */
typedef struct {
    /* If true, disguise the entered text with dots */
    bool obscured;
} ul_config_opts_textarea;

/**
 * Options related to the keyboard
 */
typedef struct {
    /* Keyboard layout */
    sq2lv_layout_id_t layout_id;
    /* If true, display key popovers on press */
    bool popovers;
} ul_config_opts_keyboard;

/**
 * Options parsed from config file(s)
 */
typedef struct {
    /* General options */
    ul_config_opts_general general;
    /* Options related to the password textarea */
    ul_config_opts_textarea textarea;
    /* Options related to the keyboard */
    ul_config_opts_keyboard keyboard;
} ul_config_opts;

/**
 * Parse options from one or more configuration files.
 * 
 * @param files paths to configuration files
 * @param num_files number of configuration files
 * @param opts pointer for writing the parsed options into
 */
void ul_config_parse(const char **files, int num_files, ul_config_opts *opts);

#endif /* UL_CONFIG_H */
