/**
 * @file libinput_device_discovery.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "libinput_device_discovery.h"
#if USE_LIBINPUT || USE_BSD_LIBINPUT

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

#include <libinput.h>

#if USE_BSD_LIBINPUT
#include <dev/evdev/input.h>
#else
#include <linux/input.h>
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static int open_restricted(const char *path, int flags, void *user_data);
static void close_restricted(int fd, void *user_data);
static bool is_keyboard(struct libinput_device *device);
static bool is_pointer_device(struct libinput_device *device);
static bool is_touchscreen(struct libinput_device *device);

/**********************
 *  STATIC VARIABLES
 **********************/
static const struct libinput_interface interface = {
  .open_restricted = open_restricted,
  .close_restricted = close_restricted,
};

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

/**
 * find connected keyboard devices
 * @param match function returning true if device matches desired condition
 * @param devices pre-allocated array to store device paths into
 * @param count maximum number of devices
 * @return number of devices discovered
 */
size_t libinput_discover(bool match(struct libinput_device *), char devices[][32], size_t count) {
  struct libinput * context = libinput_path_create_context(&interface, NULL);

  DIR *dir;
  struct dirent *ent;
  if (!(dir = opendir("/dev/input"))) {
    perror("unable to open directory /dev/input:");
    return 0;
  }

  int index = 0;
  while (index < count && (ent = readdir(dir))) {
    if (strncmp(ent->d_name, "event", strlen("event")) != 0) {
      continue;
    }

    char path[32];
    strcpy(path, "/dev/input/");
    strcat(path, ent->d_name);

    struct libinput_device * device = libinput_path_add_device(context, path);
    if(!device) {
      perror("unable to add device to libinput context:");
      return false;
    }

    device = libinput_device_ref(device);
    if(!device) {
      perror("unable to reference device within libinput context:");
      return false;
    }

    if (match(device)) {
      strcpy(devices[index], path);
      index++;
    }

    device = libinput_device_unref(device);
    libinput_path_remove_device(device);
  }

  libinput_unref(context);
  return index;
}

/**
 * find connected keyboard devices
 * @param devices pre-allocated array to store device paths into
 * @param count maximum number of devices
 * @return number of devices discovered
 */
size_t libinput_discover_keyboards(char devices[][32], size_t count) {
  return libinput_discover(is_keyboard, devices, count);
}

/**
 * find connected pointer devices
 * @param devices pre-allocated array to store device paths into
 * @param count maximum number of devices
 * @return number of devices discovered
 */
size_t libinput_discover_pointer_devices(char devices[][32], size_t count) {
  return libinput_discover(is_pointer_device, devices, count);
}

/**
 * find connected touchscreen devices
 * @param devices pre-allocated array to store device paths into
 * @param count maximum number of devices
 * @return number of devices discovered
 */
size_t libinput_discover_touchscreens(char devices[][32], size_t count) {
  return libinput_discover(is_touchscreen, devices, count);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static int open_restricted(const char *path, int flags, void *user_data)
{
  int fd = open(path, flags);
  return fd < 0 ? -errno : fd;
}

static void close_restricted(int fd, void *user_data)
{
  close(fd);
}

static bool is_keyboard(struct libinput_device * device) {
  return libinput_device_has_capability(device, LIBINPUT_DEVICE_CAP_KEYBOARD)
    && libinput_device_keyboard_has_key(device, KEY_A);
}

static bool is_pointer_device(struct libinput_device * device) {
  return libinput_device_has_capability(device, LIBINPUT_DEVICE_CAP_POINTER);
}

static bool is_touchscreen(struct libinput_device * device) {
  return libinput_device_has_capability(device, LIBINPUT_DEVICE_CAP_TOUCH);
}

#endif /* USE_LIBINPUT || USE_BSD_LIBINPUT */
