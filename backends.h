/**
 * Copyright 2022 Eugenio Paolantonio (g7)
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


#ifndef UL_BACKENDS_H
#define UL_BACKENDS_H

#include "lv_drv_conf.h"

#include "log.h"

/* NOTE: Only UL_BACKENDS_BACKEND_NONE is ought to have an explicit value assigned */
typedef enum {
    UL_BACKENDS_BACKEND_NONE = -1,
#if USE_FBDEV
    UL_BACKENDS_BACKEND_FBDEV,
#endif /* USE_FBDEV */
#if USE_DRM
    UL_BACKENDS_BACKEND_DRM,
#endif /* USE_DRM */
} ul_backends_backend_id_t;

/* Backends */
extern const char *ul_backends_backends[];

/**
 * Find the first backend with a given name.
 *
 * @param name backend name
 * @return ID of the first matching backend or UL_BACKENDS_BACKEND_NONE if no backend matched
 */
ul_backends_backend_id_t ul_backends_find_backend_with_name(const char *name);

#endif /* UL_BACKENDS_H */
