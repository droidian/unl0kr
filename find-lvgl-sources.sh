#!/bin/sh

# Copyright 2021 Johannes Marbach
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


find "$1" -name "*.mk" | while IFS= read -r makefile; do
    grep "^CSRCS\s*+=" "$makefile" | sed "s|.*=\s*||g" | while read -r expr; do
        # Ignore example code
        if [[ $(dirname $makefile) =~ .*/examples ]]; then
            continue
        fi

        # Handle full & relative paths
        if echo "$expr" | grep -q '$(LVGL_DIR'; then
            expr=$(echo "$expr" \
                | sed 's|$(LVGL_DIR)/||g' \
                | sed 's|$(LVGL_DIR_NAME)/|lvgl/|g' \
                | sed 's|$(LV_DRIVERS_DIR_NAME)/|lv_drivers/|g')
        else
            expr="$(dirname $makefile)/$expr"
        fi

        # Resolve $(wildcard ...)
        expr=$(echo "$expr" | sed 's|$(wildcard\s*\(.*\))|\1|g')

        # Resolve $(shell ...)
        if echo "$expr" | grep -q '$(shell'; then
            expr=$(echo "$expr" | sed 's|$(shell\s*\(.*\))|\1|g')
            expr=$(eval "$expr")
        fi

        # Resolve wildcards
        for file in $expr; do
            echo $file
        done
    done
done
