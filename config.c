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


#include "config.h"

#include "log.h"

#include <ini.h>

#include "squeek2lvgl/sq2lv.h"


/**
 * Static prototypes
 */

/**
 * Initialise a config options struct with default values.
 * 
 * @param opts pointer to the options struct
 */
static void init_opts(ul_config_opts *opts);

/**
 * Parse options from a configuration file.
 * 
 * @param path path to configuration file
 * @param opts pointer for writing the parsed options into
 */
static void parse_file(const char *path, ul_config_opts *opts);

/**
 * Handle parsing events from INIH.
 *
 * @param user_data pointer to user data
 * @param section current section name
 * @param key option key
 * @param value option value
 * @return 0 on error, non-0 otherwise
 */
static int parsing_handler(void* user_data, const char* section, const char* key, const char* value);

/**
 * Attempt to parse a boolean value.
 *
 * @param value string to parse
 * @param result pointer to write result into if parsing is successful
 * @return true on success, false otherwise
 */
static bool parse_bool(const char *value, bool *result);


/**
 * Static functions
 */

static void init_opts(ul_config_opts *opts) {
    opts->general.animations = false;
    opts->general.backend = ul_backends_backends[0] == NULL ? UL_BACKENDS_BACKEND_NONE : 0;
    opts->keyboard.autohide = true;
    opts->keyboard.layout_id = SQ2LV_LAYOUT_US;
    opts->keyboard.popovers = false;
    opts->textarea.obscured = true;
    opts->theme.default_id = UL_THEMES_THEME_BREEZY_DARK;
    opts->theme.alternate_id = UL_THEMES_THEME_BREEZY_LIGHT;
}

static void parse_file(const char *path, ul_config_opts *opts) {
    if (ini_parse(path, parsing_handler, opts) != 0) {
        ul_log(UL_LOG_LEVEL_ERROR, "Ignoring invalid config file %s", path);
    }
}

static int parsing_handler(void* user_data, const char* section, const char* key, const char* value) {
    ul_config_opts *opts = (ul_config_opts *)user_data;

    if (strcmp(section, "general") == 0) {
        if (strcmp(key, "animations") == 0) {
            if (parse_bool(value, &(opts->general.animations))) {
                return 1;
            }
        } else if (strcmp(key, "backend") == 0) {
            ul_backends_backend_id_t id = ul_backends_find_backend_with_name(value);
            if (id != UL_BACKENDS_BACKEND_NONE) {
                opts->general.backend = id;
                return 1;
            }
        }
    } else if (strcmp(section, "keyboard") == 0) {
        if (strcmp(key, "autohide") == 0) {
            if (parse_bool(value, &(opts->keyboard.autohide))) {
                return 1;
            }
        } else if (strcmp(key, "layout") == 0) {
            sq2lv_layout_id_t id = sq2lv_find_layout_with_short_name(value);
            if (id != SQ2LV_LAYOUT_NONE) {
                opts->keyboard.layout_id = id;
                return 1;
            }
        } else if (strcmp(key, "popovers") == 0) {
            if (parse_bool(value, &(opts->keyboard.popovers))) {
                return 1;
            }
        }
    } else if (strcmp(section, "textarea") == 0) {
        if (strcmp(key, "obscured") == 0) {
            if (parse_bool(value, &(opts->textarea.obscured))) {
                return 1;
            }
        }
    } else if (strcmp(section, "theme") == 0) {
        if (strcmp(key, "default") == 0) {
            ul_themes_theme_id_t id = ul_themes_find_theme_with_name(value);
            if (id != UL_THEMES_THEME_NONE) {
                opts->theme.default_id = id;
                return 1;
            }
        } else if (strcmp(key, "alternate") == 0) {
            ul_themes_theme_id_t id = ul_themes_find_theme_with_name(value);
            if (id != UL_THEMES_THEME_NONE) {
                opts->theme.alternate_id = id;
                return 1;
            }
        }
    }

    ul_log(UL_LOG_LEVEL_ERROR, "Ignoring invalid config value \"%s\" for key \"%s\" in section \"%s\"", value, key, section);
    return 1; /* Return 1 (true) so that we can use the return value of ini_parse exclusively for file-level errors (e.g. file not found) */
}

static bool parse_bool(const char *value, bool *result) {
    if (strcmp(value, "true") == 0) {
        *result = true;
        return true;
    }

    if (strcmp(value, "false") == 0) {
        *result = false;
        return true;
    }

    return false;
}


/**
 * Public functions
 */

void ul_config_parse(const char **files, int num_files, ul_config_opts *opts) {
    init_opts(opts);
    for (int i = 0; i < num_files; ++i) {
        parse_file(files[i], opts);
    }
}
