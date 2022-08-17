#!/bin/sh

# Copyright 2022 Johannes Marbach, Oliver Smith
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

find lv_drivers -name '*.c'
find lvgl/src/core -name '*.c'
find lvgl/src/draw -name '*.c'
find lvgl/src/extra -name '*.c'
find lvgl/src/font -name '*.c'
find lvgl/src/hal -name '*.c'
find lvgl/src/layouts -name '*.c'
find lvgl/src/misc -name '*.c'
find lvgl/src/themes -name '*.c'
find lvgl/src/widgets -name '*.c'
