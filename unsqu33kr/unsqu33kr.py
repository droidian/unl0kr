#!/usr/bin/env python3

import git
import os
import sys
import tempfile
import yaml


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


if __name__ == '__main__':
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

            print(f'/**\n * {name_map[name]}\n **/\n')
            print(f'#define NAME_{name.upper()} "{name_map[name]}"\n')

            for layer in layer_whitelist:
                print(f'/* {layer_to_description[layer]} */')
                if layer not in data['views']:
                    print(f'#define TRIGGER_{map_layer(layer).upper()}_{name.upper()} ""')
                    print(f'#define KEYS_{map_layer(layer).upper()}_{name.upper()} ' + '{ NULL }')
                    print(f'#define ATTRIBUTES_{map_layer(layer).upper()}_{name.upper()} ' + '{ 0 }\n')
                    continue

                if layer == 'eschars':
                    key = map_key('show_eschars', layer, name)[0]
                    print(f'#define TRIGGER_{map_layer(layer).upper()}_{name.upper()} "{key}"')

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

                print(f'#define KEYS_{map_layer(layer).upper()}_{name.upper()} ' + '{ \\')
                for i, keys in enumerate(keys_by_row):
                    joined = ', '.join(keys)
                    suffix = '"\\n", \\' if i < len(rows) - 1 else '"" \\'
                    print(f'    {joined}, {suffix}')
                print('}')
                print(f'#define ATTRIBUTES_{map_layer(layer).upper()}_{name.upper()} ' + '{ \\')
                for i, attrs in enumerate(attrs_by_row):
                    joined = ', '.join(attrs)
                    suffix = ', \\' if i < len(rows) - 1 else ' \\'
                    print(f'    {joined}{suffix}')
                print('}\n')
            
            layouts.append(name)
    
    print('/**\n * All layouts\n **/\n')

    print('static const char * const names =')
    for i, name in enumerate(layouts):
        suffix = ' "\\n"' if i < len(layouts) - 1 else ';\n'
        print(f'    LV_SYMBOL_KEYBOARD " " NAME_{name.upper()}{suffix}')

    for layer in layer_whitelist:
        if layer == 'eschars':
            print(f'static const char * const triggers_{map_layer(layer)}[] = ' + '{')
            for i, name in enumerate(layouts):
                suffix = ',' if i < len(layouts) - 1 else ''
                print(f'    (const char * const)TRIGGER_{map_layer(layer).upper()}_{name.upper()}{suffix}')
            print('};')

        print(f'static const char ** const keys_{map_layer(layer)}[] = ' + '{')
        for i, name in enumerate(layouts):
            suffix = ',' if i < len(layouts) - 1 else ''
            print(f'    (const char * const [])KEYS_{map_layer(layer).upper()}_{name.upper()}{suffix}')
        print('};')
        print()
        print(f'static const lv_btnmatrix_ctrl_t * const attributes_{map_layer(layer)}[] = ' + '{')
        for i, name in enumerate(layouts):
            suffix = ',' if i < len(layouts) - 1 else ''
            print(f'    (lv_btnmatrix_ctrl_t[])ATTRIBUTES_{map_layer(layer).upper()}_{name.upper()}{suffix}')
        print('};')
        print()
