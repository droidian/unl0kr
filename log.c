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


#include "log.h"

#include <stdarg.h>
#include <stdio.h>
#include <string.h>


/**
 * Static variables
 */

static ul_log_level log_level = UL_LOG_LEVEL_ERROR;


/**
 * Public functions
 */

void ul_log_set_level(ul_log_level level) {
    log_level = level;
}

void ul_log(ul_log_level level, const char *format, ...) {
    if (level > log_level) {
        return;
    }

    va_list args;
    va_start(args, format);
    vfprintf(stderr, format, args);
    va_end(args);

    size_t l = strlen(format);
    if (l > 0 && format[l - 1] != '\n') {
        fprintf(stderr, "\n");
    }
}

void ul_log_print_cb(const char *msg) {
    ul_log(UL_LOG_LEVEL_VERBOSE, msg);
}
