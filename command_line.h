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


#ifndef UL_COMMAND_LINE_H
#define UL_COMMAND_LINE_H

#include <stdbool.h>

/**
 * Options parsed from command line arguments
 */
typedef struct {
    /* Number of config files */
    int num_config_files;
    /* Paths of config file */
    const char **config_files;
    /* Horizontal display resolution */
    int hor_res;
    /* Vertical display resolution */
    int ver_res;
    /* Horizontal display offset */
    int x_offset;
    /* Vertical display offset */
    int y_offset;
    /* DPI */
    int dpi;
    /* Verbose mode. If true, provide more detailed logging output on STDERR. */
    bool verbose;
} ul_cli_opts;

/**
 * Parse command line arguments and exit on failure.
 * 
 * @param argc number of provided command line arguments
 * @param argv arguments as an array of strings
 * @param opts pointer for writing the parsed options into
 */
void ul_cli_parse_opts(int argc, char *argv[], ul_cli_opts *opts);

#endif /* UL_COMMAND_LINE_H */
