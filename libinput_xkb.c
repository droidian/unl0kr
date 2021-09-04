/**
 * @file libinput_xkb.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "libinput_xkb.h"
#if USE_LIBINPUT || USE_BSD_LIBINPUT

#include <stdio.h>
#include <stdlib.h>
#include <xkbcommon/xkbcommon.h>

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static struct xkb_context *ctx = NULL;
static struct xkb_keymap *keymap = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

bool libinput_xkb_init(void) {
    if (ctx) {
        perror("context is already initialised");
        return true;
    }

    ctx = xkb_context_new(XKB_CONTEXT_NO_FLAGS);
    if (!ctx) {
        perror("could not create new XKB context");
        return false;
    }

    struct xkb_rule_names names = {
        .rules = NULL,
        .model = "pc105",
        .layout = "de",
        .variant = "nodeadkeys",
        .options = NULL
    };

    keymap = xkb_keymap_new_from_names(ctx, &names, XKB_KEYMAP_COMPILE_NO_FLAGS);
    if (!keymap) {
        perror("could not create XKB keymap");
        return false;
    }

    keymap = xkb_keymap_ref(keymap);
    if (!keymap) {
        perror("could not reference XKB keymap");
        return false;
    }

    return true;
}

void *libinput_xkb_create_state(void) {
    struct xkb_state *state = xkb_state_new(keymap);
    if (!state) {
        perror("could not create XKB state");
        return false;
    }

    state = xkb_state_ref(state);
    if (!state) {
        perror("could not reference XKB state");
        return false;
    }

    return state;
}

uint32_t libinput_xkb_process_key(uint32_t scancode, bool down, void *state) {
  /* Offset the evdev scancode by 8, see https://xkbcommon.org/doc/current/xkbcommon_8h.html#ac29aee92124c08d1953910ab28ee1997 */
  xkb_keycode_t keycode = scancode + 8;

  uint32_t result = 0;

  switch (xkb_state_key_get_one_sym(state, keycode)) {
    case XKB_KEY_BackSpace:
      result = LV_KEY_BACKSPACE;
      break;
    case XKB_KEY_Return:
      result = LV_KEY_ENTER;
      break;
    case XKB_KEY_Prior:
      result = LV_KEY_PREV;
      break;
    case XKB_KEY_Next:
      result = LV_KEY_NEXT;
      break;
    case XKB_KEY_Up:
      result = LV_KEY_UP;
      break;
    case XKB_KEY_Left:
      result = LV_KEY_LEFT;
      break;
    case XKB_KEY_Right:
      result = LV_KEY_RIGHT;
      break;
    case XKB_KEY_Down:
      result = LV_KEY_DOWN;
      break;
    default:
      break;
  }

  if (result == 0) {
    char buffer[4] = { 0, 0, 0, 0 };
    int size = xkb_state_key_get_utf8((struct xkb_state *)state, keycode, NULL, 0) + 1;
    if (size > 1) {
      xkb_state_key_get_utf8((struct xkb_state *)state, keycode, buffer, size);
      memcpy(&result, buffer, 4);
    }
  }

  xkb_state_update_key((struct xkb_state *)state, keycode, down ? XKB_KEY_DOWN : XKB_KEY_UP);

  return result;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* USE_LIBINPUT || USE_BSD_LIBINPUT */
