/**
 * @file libinput_multi.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "libinput_multi.h"
#if USE_LIBINPUT || USE_BSD_LIBINPUT

#include <stdio.h>
#include <unistd.h>
#include <linux/limits.h>
#include <fcntl.h>
#include <errno.h>
#include <stdbool.h>
#include <poll.h>
#include <libinput.h>

#if USE_BSD_LIBINPUT
#include <dev/evdev/input.h>
#else
#include <linux/input.h>
#endif

#include "libinput_xkb.h"

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

typedef struct {
  int button;
  int libinput_key_val;
  struct libinput_device *device;
  void *keyboard_state;

  int libinput_fd;
  struct libinput *libinput_context;
  struct pollfd fds[1];
} libinput_multi_state;

/**********************
 *  STATIC VARIABLES
 **********************/
static const int timeout = 0; // do not block
static const nfds_t nfds = 1;
static lv_point_t most_recent_touch_point = { .x = 0, .y = 0};

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
 * reconfigure the device file for libinput
 * @param indev_drv driver object (must be initialised)
 * @param dev_name set the libinput device filename
 * @return true: the device file set complete
 *         false: the device file doesn't exist current system
 */
bool libinput_multi_set_file(lv_indev_drv_t * indev_drv, char* dev_name)
{
  libinput_multi_state *state = (libinput_multi_state *)indev_drv->user_data;
  if (!state) {
    perror("unable to read state from driver:");
    return false;
  }

  // This check *should* not be necessary, yet applications crashes even on NULL handles.
  // citing libinput.h:libinput_path_remove_device:
  // > If no matching device exists, this function does nothing.
  if (state->device) {
    state->device = libinput_device_unref(state->device);
    libinput_path_remove_device(state->device);
  }

  state->device = libinput_path_add_device(state->libinput_context, dev_name);
  if(!state->device) {
    perror("unable to add device to libinput context:");
    return false;
  }
  state->device = libinput_device_ref(state->device);
  if(!state->device) {
    perror("unable to reference device within libinput context:");
    return false;
  }

  state->button = LV_INDEV_STATE_REL;
  state->libinput_key_val = 0;

  return true;
}

/**
 * initialise a driver with fresh state data
 * @param indev_drv driver object
 */
void libinput_multi_init_driver(lv_indev_drv_t * indev_drv) {
  libinput_multi_state *state = (libinput_multi_state *)malloc(sizeof(libinput_multi_state));
  state->device = NULL;

  state->libinput_context = libinput_path_create_context(&interface, NULL);
  state->libinput_fd = libinput_get_fd(state->libinput_context);

  /* prepare poll */
  state->fds[0].fd = state->libinput_fd;
  state->fds[0].events = POLLIN;
  state->fds[0].revents = 0;

  state->keyboard_state = libinput_xkb_create_state();

  indev_drv->user_data = (void *)state;
}

/**
 * destroy any existing state data on a driver
 * @param indev_drv driver object
 */
void libinput_multi_deinit_driver(lv_indev_drv_t * indev_drv) {
  if (indev_drv->user_data) {
    libinput_multi_state *state = (libinput_multi_state *)indev_drv->user_data;

    struct libinput_device *device = libinput_device_unref(state->device);
    libinput_path_remove_device(device);
    
    libinput_unref(state->libinput_context);

    // TODO: dealloc keyboard state

    free(indev_drv->user_data);
    indev_drv->user_data = NULL;
  }
}

/**
 * Get the current position and state of the libinput
 * @param indev_drv driver object itself
 * @param data store the libinput data here
 * @return false: because the points are not buffered, so no more data to be read
 */
void libinput_multi_read(lv_indev_drv_t * indev_drv, lv_indev_data_t * data)
{
  libinput_multi_state *state = (libinput_multi_state *)indev_drv->user_data;
  if (!state) {
    perror("unable to read state from driver:");
    return;
  }

  struct libinput_event *event;
  struct libinput_event_touch *touch_event = NULL;
  struct libinput_event_pointer *pointer_event = NULL;
  struct libinput_event_keyboard *keyboard_event = NULL;
  int rc = 0;

  rc = poll(state->fds, nfds, timeout);
  switch (rc){
    case -1:
      perror(NULL);
    case 0:
      goto report_most_recent_state;
    default:
      break;
  }
  libinput_dispatch(state->libinput_context);
  while((event = libinput_get_event(state->libinput_context)) != NULL) {
    enum libinput_event_type type = libinput_event_get_type(event);
    switch (type) {
      case LIBINPUT_EVENT_TOUCH_MOTION:
      case LIBINPUT_EVENT_TOUCH_DOWN:
        touch_event = libinput_event_get_touch_event(event);
        most_recent_touch_point.x = libinput_event_touch_get_x_transformed(touch_event, LV_HOR_RES);
        most_recent_touch_point.y = libinput_event_touch_get_y_transformed(touch_event, LV_VER_RES);
        state->button = LV_INDEV_STATE_PR;
        break;
      case LIBINPUT_EVENT_TOUCH_UP:
        state->button = LV_INDEV_STATE_REL;
        break;
      case LIBINPUT_EVENT_POINTER_MOTION:
        pointer_event = libinput_event_get_pointer_event(event);
        most_recent_touch_point.x += libinput_event_pointer_get_dx(pointer_event);
        most_recent_touch_point.y += libinput_event_pointer_get_dy(pointer_event);
        most_recent_touch_point.x = most_recent_touch_point.x < 0 ? 0 : most_recent_touch_point.x;
        most_recent_touch_point.x = most_recent_touch_point.x > LV_HOR_RES - 1 ? LV_HOR_RES - 1 : most_recent_touch_point.x;
        most_recent_touch_point.y = most_recent_touch_point.y < 0 ? 0 : most_recent_touch_point.y;
        most_recent_touch_point.y = most_recent_touch_point.y > LV_VER_RES - 1 ? LV_VER_RES - 1 : most_recent_touch_point.y;
        break;
      case LIBINPUT_EVENT_POINTER_BUTTON:
        pointer_event = libinput_event_get_pointer_event(event);
        enum libinput_button_state button_state = libinput_event_pointer_get_button_state(pointer_event); 
        state->button = button_state == LIBINPUT_BUTTON_STATE_RELEASED ? LV_INDEV_STATE_REL : LV_INDEV_STATE_PR;
        break;
      case LIBINPUT_EVENT_KEYBOARD_KEY:
        keyboard_event = libinput_event_get_keyboard_event(event);
        enum libinput_key_state key_state = libinput_event_keyboard_get_key_state(keyboard_event);
        uint32_t code = libinput_event_keyboard_get_key(keyboard_event);
        state->libinput_key_val = libinput_xkb_process_key(code, key_state == LIBINPUT_KEY_STATE_PRESSED, state->keyboard_state);
        if (state->libinput_key_val != 0) {
          state->button = (key_state == LIBINPUT_KEY_STATE_RELEASED) ? LV_INDEV_STATE_REL : LV_INDEV_STATE_PR; //
        }
        break;
      default:
        break;
    }
    libinput_event_destroy(event);
  }
report_most_recent_state:
  data->point.x = most_recent_touch_point.x;
  data->point.y = most_recent_touch_point.y;
  data->state = state->button;
  data->key = state->libinput_key_val;
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

#endif /* USE_LIBINPUT || USE_BSD_LIBINPUT */
