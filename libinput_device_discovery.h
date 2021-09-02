/**
 * @file libInput_device_discovery.h
 *
 */

#ifndef LVGL_DEVICE_DISCOVERY_H
#define LVGL_DEVICE_DISCOVERY_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
// #ifndef LV_DRV_NO_CONF
// #ifdef LV_CONF_INCLUDE_SIMPLE
#include "lv_drv_conf.h"
// #else
// #include "../../lv_drv_conf.h"
// #endif
// #endif

#if USE_LIBINPUT || USE_BSD_LIBINPUT

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
#include "lvgl.h"
#else
#include "lvgl/lvgl.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/
struct libinput_device;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * find connected keyboard devices
 * @param match function returning true if device matches desired condition
 * @param devices pre-allocated array to store device paths into
 * @param count maximum number of devices
 * @return number of devices discovered
 */
size_t libinput_discover(bool match(struct libinput_device *), char devices[][32], size_t count);

/**
 * find connected keyboard devices
 * @param devices pre-allocated array to store device paths into
 * @param count maximum number of devices
 * @return number of devices discovered
 */
size_t libinput_discover_keyboards(char devices[][32], size_t count);

/**
 * find connected pointer devices
 * @param devices pre-allocated array to store device paths into
 * @param count maximum number of devices
 * @return number of devices discovered
 */
size_t libinput_discover_pointer_devices(char devices[][32], size_t count);

/**
 * find connected touchscreen devices
 * @param devices pre-allocated array to store device paths into
 * @param count maximum number of devices
 * @return number of devices discovered
 */
size_t libinput_discover_touchscreens(char devices[][32], size_t count);

/**********************
 *      MACROS
 **********************/

#endif /* USE_LIBINPUT || USE_BSD_LIBINPUT */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LVGL_DEVICE_DISCOVERY_H */
