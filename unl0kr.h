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


#ifndef UL_UNL0KR_H
#define UL_UNL0KR_H

#include "lvgl/lvgl.h"

#ifndef UL_VERSION
#define UL_VERSION "?" /* Just to silence IDE warning. Real version injected by meson during build. */
#endif

/**
 * Fonts
 */

#define UL_SYMBOL_ADJUST "\xef\x81\x82" // 0xF042 (https://fontawesome.com/v5.15/icons/adjust?style=solid)
#define UL_SYMBOL_CHEVRON_LEFT "\xef\x81\x93" // 0xF053 (https://fontawesome.com/v5/icons/chevron-left?style=solid&s=solid)

#endif /* UL_UNL0KR_H */
