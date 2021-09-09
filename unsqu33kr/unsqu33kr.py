#!/usr/bin/env python3

import argparse
import git
import os
import sys
import tempfile
import yaml


outfile_c = 'uskr_layouts.c'
outfile_h = 'uskr_layouts.h'

repository_url = 'https://gitlab.gnome.org/World/Phosh/squeekboard.git'
rel_layouts_dir = 'data/keyboards'
layout_whitelist = ['de', 'es', 'fr', 'us']
layer_whitelist = ['base', 'upper', 'numbers', 'eschars']
quote_blacklist = ['LV_SYMBOL_BACKSPACE', 'LV_SYMBOL_LEFT', 'LV_SYMBOL_RIGHT', 'LV_SYMBOL_OK']

key_map = {
    '"': '\\"',
    'colon': ':',
    'BackSpace': 'LV_SYMBOL_BACKSPACE',
    'period': '.',
    'preferences': None,
    'Shift_L': {
        'base': 'ABC',
        'upper': 'abc'
    },
    'show_eschars': {
        'de': 'äöü',
        'es': 'áéí',
        'fr': 'àéô'
    },
    'show_letters': 'abc',
    'show_numbers': '1#',
    'show_numbers_from_symbols': '1#',
    'show_symbols': None,
    'space': ['LV_SYMBOL_LEFT', ' ', 'LV_SYMBOL_RIGHT'],
    'Return': 'LV_SYMBOL_OK'
}

layer_map = {
    'base': 'lower',
    'eschars': 'special'
}

layer_to_description = {
    'base': 'Lowercase layer',
    'upper': 'Uppercase layer',
    'numbers': 'Number / symbol layer',
    'eschars': 'Special characters'
}

name_map = {
    'de': 'German',
    'es': 'Spanish',
    'fr': 'French',
    'us': 'English (US)'
}


def parse_arguments():
    parser = argparse.ArgumentParser(description='Convert squeekboard layouts to LVGL-compatible C code.')
    parser.add_argument('--output', dest='output', type=str, help='output directory for generated files')
    args = parser.parse_args()

    if not args.output or not os.path.isdir(args.output):
        sys.stderr.write('Error: no valid output directory specified')
        sys.exit(1)

    return args


def clone_squeekboard_repo(destination):
    git.Repo.clone_from(repository_url, destination, depth=1)


def load_yaml(path):
    with open(path, 'r') as stream:
        try:
            return yaml.safe_load(stream)
        except yaml.YAMLError as exc:
            print(exc)


def map_key(key, layer, name):
    mapped = key_map[key] if key in key_map else key
    if isinstance(mapped, dict):
        if layer in mapped:
            mapped = mapped[layer]
        elif name in mapped:
            mapped = mapped[name]
        else:
            None
    if not mapped:
        return []
    if isinstance(mapped, list):
        return mapped
    return [mapped]


def map_layer(layer):
    return layer_map[layer] if layer in layer_map else layer


def add_header(lines):
    """Add header comment to a list of lines.

    lines -- list of lines to append to
    """
    lines += ['/**', ' * Auto-generated with unsqu33kr', ' **/', '']


def add_uskr_include(lines):
    """Add an include statement for the generated header to a list of lines.

    lines -- list of lines to append to
    """
    lines += [f'#include "{outfile_h}"', '']


def add_lvgl_include(lines):
    """Add an LVGL include statement to a list of lines.

    lines -- list of lines to append to
    """
    lines += ['#include "lvgl/lvgl.h"', '']


def wrap_header(lines):
    """Wrap header lines to prevent recursive inclusion.

    lines -- list of lines to wrap
    """

    lines.insert(0, '#ifndef USKR_LAYOUTS_H')
    lines.insert(1, '#define USKR_LAYOUTS_H')
    lines.insert(2, '')
    lines += ['#endif /* USKR_LAYOUTS_H */', '']


def write_files(lines_c, lines_h):
    """Write accumulated output to C and header file, respectively.

    lines_c -- sequence of lines to write to C file
    lines_h -- sequence of lines to write to header
    """
    with open(os.path.join(args.output, outfile_c), 'w') as fp:
        fp.write('\n'.join(lines_c))
    with open(os.path.join(args.output, outfile_h), 'w') as fp:
        fp.write('\n'.join(lines_h))


if __name__ == '__main__':
    args = parse_arguments()

    lines_c = []
    lines_h = []

    add_header(lines_c)
    add_uskr_include(lines_c)
    add_header(lines_h)
    add_lvgl_include(lines_h)

    layouts = []

    with tempfile.TemporaryDirectory() as tmp:
        clone_squeekboard_repo(tmp)

        layouts_dir = os.path.join(tmp, rel_layouts_dir)

        for file in os.listdir(layouts_dir):
            path = os.path.join(layouts_dir, file)

            if not os.path.isfile(path):
                continue

            name, extension = os.path.splitext(file)
            if name not in layout_whitelist:
                continue

            data = load_yaml(path)
            if not data:
                continue
            
            if not 'views' in data:
                continue
            
            buttons = data['buttons'] if 'buttons' in data else {}

            lines_c.append(f'/**\n * {name_map[name]}\n **/\n')
            lines_c.append(f'#define NAME_{name.upper()} "{name}"\n')

            for layer in layer_whitelist:
                lines_c.append(f'/* {layer_to_description[layer]} */')
                if layer not in data['views']:
                    lines_c.append(f'#define TRIGGER_{map_layer(layer).upper()}_{name.upper()} ""')
                    lines_c.append(f'#define KEYS_{map_layer(layer).upper()}_{name.upper()} ' + '{ NULL }')
                    lines_c.append(f'#define ATTRIBUTES_{map_layer(layer).upper()}_{name.upper()} ' + '{ 0 }\n')
                    continue

                if layer == 'eschars':
                    key = map_key('show_eschars', layer, name)[0]
                    lines_c.append(f'#define TRIGGER_{map_layer(layer).upper()}_{name.upper()} "{key}"')

                rows = data['views'][layer]
                keys_by_row = []
                attrs_by_row = []
                
                for i, row in enumerate(rows):
                    keys = []
                    attrs = []
                    for key in row.split():
                        for mapped in map_key(key, layer, name):
                            keys.append(f'"{mapped}"' if mapped not in quote_blacklist else mapped)
                            if key in buttons and key not in ['period', 'colon', '"']:
                                attrs.append(f'LV_KEYBOARD_CTRL_BTN_FLAGS | {7 if mapped == " " else 3}')
                            else:
                                attrs.append('2')
                    keys_by_row.append(keys)
                    attrs_by_row.append(attrs)

                lines_c.append(f'#define KEYS_{map_layer(layer).upper()}_{name.upper()} ' + '{ \\')
                for i, keys in enumerate(keys_by_row):
                    joined = ', '.join(keys)
                    suffix = '"\\n", \\' if i < len(rows) - 1 else '"" \\'
                    lines_c.append(f'    {joined}, {suffix}')
                lines_c.append('}')
                lines_c.append(f'#define ATTRIBUTES_{map_layer(layer).upper()}_{name.upper()} ' + '{ \\')
                for i, attrs in enumerate(attrs_by_row):
                    joined = ', '.join(attrs)
                    suffix = ', \\' if i < len(rows) - 1 else ' \\'
                    lines_c.append(f'    {joined}{suffix}')
                lines_c.append('}\n')
            
            layouts.append(name)
    
    lines_c.append('/**\n * All layouts\n **/\n')

    lines_h.append('typedef enum {')
    for i, name in enumerate(layouts):
        suffix = ',' if i < len(layouts) - 1 else ''
        lines_h.append(f'    USKR_LAYOUT_{name.upper()} = {i}{suffix}')
    lines_h.append('} uskr_layout_t;')
    lines_h.append ('')
    lines_h.append(f'#define USKR_NUM_LAYOUTS {len(layouts)}')
    lines_h.append ('')

    lines_h.append('extern const char * const names;')
    lines_c.append('const char * const names =')
    for i, name in enumerate(layouts):
        suffix = ' "\\n"' if i < len(layouts) - 1 else ';\n'
        lines_c.append(f'    LV_SYMBOL_KEYBOARD " " NAME_{name.upper()}{suffix}')

    for layer in layer_whitelist:
        if layer == 'eschars':
            lines_h.append(f'extern const char * const triggers_{map_layer(layer)}[];')
            lines_c.append(f'const char * const triggers_{map_layer(layer)}[] = ' + '{')
            for i, name in enumerate(layouts):
                suffix = ',' if i < len(layouts) - 1 else ''
                lines_c.append(f'    (const char * const)TRIGGER_{map_layer(layer).upper()}_{name.upper()}{suffix}')
            lines_c.append('};')

        lines_h.append(f'extern const char ** const keys_{map_layer(layer)}[];')
        lines_c.append(f'const char ** const keys_{map_layer(layer)}[] = ' + '{')
        for i, name in enumerate(layouts):
            suffix = ',' if i < len(layouts) - 1 else ''
            lines_c.append(f'    (const char * const [])KEYS_{map_layer(layer).upper()}_{name.upper()}{suffix}')
        lines_c.append('};')
        lines_c.append('')
        lines_h.append(f'extern const lv_btnmatrix_ctrl_t * const attributes_{map_layer(layer)}[];')
        lines_c.append(f'const lv_btnmatrix_ctrl_t * const attributes_{map_layer(layer)}[] = ' + '{')
        for i, name in enumerate(layouts):
            suffix = ',' if i < len(layouts) - 1 else ''
            lines_c.append(f'    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_{map_layer(layer).upper()}_{name.upper()}{suffix}')
        lines_c.append('};')

        lines_h.append('')
        lines_c.append('')

    wrap_header(lines_h)
    write_files(lines_c, lines_h)