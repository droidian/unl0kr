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


#include "command_line.h"

#include "unl0kr.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * Static prototypes
 */

/**
 * Initialise a command line options struct with default values.
 * 
 * @param opts pointer to the options struct
 */
static void init_opts(ul_cli_opts *opts);

/**
 * Output usage instructions.
 */
static void print_usage();


/**
 * Static functions
 */

static void init_opts(ul_cli_opts *opts) {
    opts->hor_res = -1;
    opts->ver_res = -1;
    opts->verbose = false;
}

static void print_usage() {
    fprintf(stderr,
        "Usage: unl0kr [OPTION]\n"
        "\n"
        "Mandatory arguments to long options are mandatory for short options too.\n"
        "  -g, --geometry=NxM  Force a display size of N horizontal times M vertical pixels\n"
        "  -h, --help          Print this message and exit\n"
        "  -v, --verbose       Enable more detailed logging output on STDERR\n"
        "  -V, --version       Print the unl0kr version and exit\n");
}


/**
 * Public functions
 */

void ul_cli_parse_opts(int argc, char *argv[], ul_cli_opts *opts) {
    init_opts(opts);

    struct option long_opts[] = {
        { "geometry", required_argument, NULL, 'g' },
        { "help",     no_argument,       NULL, 'h' },
        { "verbose",  no_argument,       NULL, 'v' },
        { "version",  no_argument,       NULL, 'V' },
        { NULL, 0, NULL, 0 }
    };

    int opt, index = 0;

    while ((opt = getopt_long(argc, argv, "g:hvV", long_opts, &index)) != -1) {
        switch (opt) {
        case 'g':
            if (sscanf(optarg, "%ix%i", &(opts->hor_res), &(opts->ver_res)) != 2) {
                fprintf(stderr, "Error: invalid geometry argument \"%s\"\n", optarg);
                exit(EXIT_FAILURE);
            }
            break;
        case 'h':
            print_usage();
            exit(EXIT_SUCCESS);
        case 'v':
            opts->verbose = true;
            break;
        case 'V':
            fprintf(stderr, "unl0kr %s\n", UL_VERSION);
            exit(0);
        default:
            print_usage();
            exit(EXIT_FAILURE);
        }
    }
}
