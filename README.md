Unl0kr
======

Proof-of-concept framebuffer-based disk unlocker for the initramfs based on [lvgl].

__Disclaimer: Doesn't actually unlock anything 😜__

# About

This is an experiment that attempts to evaluate the fitness of [lvgl] to build a graphical user interface on the Linux framebuffer for unlocking encrypted hard drives during boot. It's neither functional nor meant to replace postmarketOS/osk-sdl. For background see postmarketOS/osk-sdl#121.

# Status

The biggest obstacle is input processing. [lv_drivers] provides an evdev interface (supporting touchscreens, pointer devices and keypads) and a [libinput] interface (supporting touchscreens only). Presently there is no support for full physical keyboards (short of using the SDL interface) and no automated device detection. Additonally, the drivers can currently not be used with multiple devices at the same time.

## What works

- Password-entry UI including on-screen keyboard on the framebuffer
- Input device discovery for keyboards, mice and trackpads
- On-screen keyboard control via one or more mouse / trackpad (including cursor)
- On-screen keyboard control via one or more hardware keyboard (including support for multiple layouts using XKB)
  - Works great on my laptop keyboard but occasionally drops keys on my Ergodox EZ)
- On-screen keyboard control via touchscreen (tested on PinePhone)

## To do

... everything else ...

# Upstreaming

As far as feasible and sensible, [lvgl] and [lv_driver] fixes and enhancements are being upstreamed. Ideally all code outside of `main.c` should be contributed back but I'm not yet sure if that will be possible.

Upstreamed contributions so far:

- [Add support for pointer devices to libinput driver] (⏳ in review)
- [Add support for keypads to libinput driver] (✅ merged)
- [Don't compile example assets when disabled in lv_conf.h] (✅ merged)
- [Add full keyboard support to libinput/evdev driver] (⏳ in review)

# Operation

## Dependencies

- [lvgl] (git submodule / linked statically)
- [lv_drivers] (git submodule / linked statically)
- [libinput]

## Testing

For development and testing you can run the app in a VT. `sudo` is needed to access input device files.

```
$ make
$ sudo chvt 2
$ sudo ./unl0kr
```

# Acknowledgements

The [lv_port_linux_frame_buffer] project served as a starting point for the codebase. The mouse cursor image was taken from [lv_sim_emscripten].

# License

Unl0kr is licensed under the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

[lvgl]: https://github.com/lvgl/lvgl
[lv_drivers]: https://github.com/lvgl/lv_drivers
[lv_port_linux_frame_buffer]: https://github.com/lvgl/lv_port_linux_frame_buffer]
[lv_sim_emscripten]: https://github.com/lvgl/lv_sim_emscripten/blob/master/mouse_cursor_icon.c]
[libinput]: https://gitlab.freedesktop.org/libinput/libinput
[Add support for pointer devices to libinput driver]: https://github.com/lvgl/lv_drivers/pull/150
[Add support for keypads to libinput driver]: https://github.com/lvgl/lv_drivers/pull/152
[Don't compile example assets when disabled in lv_conf.h]: https://github.com/lvgl/lvgl/pull/2523
[Add full keyboard support to libinput/evdev driver]: https://github.com/lvgl/lv_drivers/pull/156
