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

#include "log.h"
#include "unl0kr.h"

#include <getopt.h>
#include <stdio.h>
#include <stdlib.h>


/**
 * Static prototypes
 */

/**
 * Initialise a command line options struct with default values and exit on failure.
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
    opts->num_config_files = 1;

    opts->config_files = malloc(sizeof(char *));
    if (!opts->config_files) {
        ul_log(UL_LOG_LEVEL_ERROR, "Could not allocate memory for config file paths");
        exit(EXIT_FAILURE);
    }
    opts->config_files[0] = "/etc/unl0kr.conf";

    opts->hor_res = -1;
    opts->ver_res = -1;
    opts->verbose = false;
}

static void print_usage() {
    fprintf(stderr,
        /*-------------------------------- 78 CHARS --------------------------------*/
        "Usage: unl0kr [OPTION]\n"
        "\n"
        "Unl0kr values the CRYPTTAB_TRIED variable. Upon completion, the entered\n"
        "password is printed to STDOUT. All other output happens on STDERR.\n"
        "\n"
        "Mandatory arguments to long options are mandatory for short options too.\n"
        "  -c, --config=PATH      Locaton of the main config file. Defaults to\n"
        "                         /etc/unl0kr.conf.\n"
        "  -C, --config-override  Location of the config override file. Values in\n"
        "                         this file override values for the same keys in the\n"
        "                         main config file. If specified multiple times, the\n"
        "                         values from consecutive files will be merged in\n"
        "                         order.\n"
        "  -g, --geometry=NxM     Force a display size of N horizontal times M\n"
        "                         vertical pixels\n"
        "  -d  --dpi=N            Overrides the DPI\n"
        "  -h, --help             Print this message and exit\n"
        "  -v, --verbose          Enable more detailed logging output on STDERR\n"
        "  -V, --version          Print the unl0kr version and exit\n");
        /*-------------------------------- 78 CHARS --------------------------------*/
}


/**
 * Public functions
 */

void ul_cli_parse_opts(int argc, char *argv[], ul_cli_opts *opts) {
    init_opts(opts);

    struct option long_opts[] = {
        { "config",          required_argument, NULL, 'c' },
        { "config-override", required_argument, NULL, 'C' },
        { "geometry",        required_argument, NULL, 'g' },
        { "dpi",             required_argument, NULL, 'd' },
        { "help",            no_argument,       NULL, 'h' },
        { "verbose",         no_argument,       NULL, 'v' },
        { "version",         no_argument,       NULL, 'V' },
        { NULL, 0, NULL, 0 }
    };

    int opt, index = 0;

    while ((opt = getopt_long(argc, argv, "c:C:g:d:hvV", long_opts, &index)) != -1) {
        switch (opt) {
        case 'c':
            opts->config_files[0] = optarg;
            break;
        case 'C':
            opts->config_files = realloc(opts->config_files, (opts->num_config_files + 1) * sizeof(char *));
            if (!opts->config_files) {
                ul_log(UL_LOG_LEVEL_ERROR, "Could not allocate memory for config file paths");
                exit(EXIT_FAILURE);
            }
            opts->config_files[opts->num_config_files] = optarg;
            opts->num_config_files++;
            break;
        case 'g':
            if (sscanf(optarg, "%ix%i", &(opts->hor_res), &(opts->ver_res)) != 2) {
                ul_log(UL_LOG_LEVEL_ERROR, "Invalid geometry argument \"%s\"\n", optarg);
                exit(EXIT_FAILURE);
            }
            break;
        case 'd':
            if (sscanf(optarg, "%i", &(opts->dpi)) != 1) {
                ul_log(UL_LOG_LEVEL_ERROR, "Invalid dpi argument \"%s\"\n", optarg);
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
