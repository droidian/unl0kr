/**
 * @file libinput_multi.h
 *
 */

#ifndef LVGL_LIBINPUT_MULTI_H
#define LVGL_LIBINPUT_MULTI_H

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

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * initialise a driver with fresh state data
 * @param indev_drv driver object
 */
void libinput_multi_init_driver(lv_indev_drv_t * indev_drv);
/**
 * destroy any existing state data on a driver
 * @param indev_drv driver object
 */
void libinput_multi_deinit_driver(lv_indev_drv_t * indev_drv);
/**
 * reconfigure the device file for libinput
 * @param indev_drv driver object (must be initialised)
 * @param dev_name set the libinput device filename
 * @return true: the device file set complete
 *         false: the device file doesn't exist current system
 */
bool libinput_multi_set_file(lv_indev_drv_t * indev_drv, char* dev_name);
/**
 * Get the current position and state of the libinput
 * @param indev_drv driver object itself
 * @param data store the libinput data here
 * @return false: because the points are not buffered, so no more data to be read
 */
void libinput_multi_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data);


/**********************
 *      MACROS
 **********************/

#endif /* USE_LIBINPUT || USE_BSD_LIBINPUT */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* LVGL_LIBINPUT_MULTI_H */
