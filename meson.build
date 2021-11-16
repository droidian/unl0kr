# Copyright 2021 Clayton Craft
#
# This file is part of unl0kr, hereafter referred to as the program.
#
# This program is free software: you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# (at your option) any later version.
#
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along with this program. If not, see <https://www.gnu.org/licenses/>.


project(
  'unl0kr',
  'c',
  version: '0.0.0',
  default_options: 'warning_level=1',
  meson_version: '>=0.53.0'
)

add_project_arguments('-DUL_VERSION="@0@"'.format(meson.project_version()), language: ['c'])

unl0kr_sources = [
  'command_line.c',
  'config.c',
  'cursor.c',
  'font_32.c',
  'indev.c',
  'log.c',
  'main.c',
  'sq2lv_layouts.c',
  'theme.c',
  'themes.c'
]

squeek2lvgl_sources = [
  'squeek2lvgl/sq2lv.c',
]

lvgl_sources = run_command('find-lvgl-sources.sh', 'lvgl').stdout().strip().split('\n')

lv_drivers_sources = run_command('find-lvgl-sources.sh', 'lv_drivers').stdout().strip().split('\n')

install_data(sources: 'unl0kr.conf', install_dir : get_option('sysconfdir'))

executable(
  'unl0kr',
  sources: unl0kr_sources + squeek2lvgl_sources + lvgl_sources + lv_drivers_sources,
  include_directories: ['lvgl', 'lv_drivers'],
  dependencies: [
    dependency('inih'),
    dependency('libinput'),
    dependency('xkbcommon')
  ],
  install: true
)
