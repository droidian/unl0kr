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
- Switching on-screen keyboard layout at runtime (layouts still to be refined, currently based on squeekboard subset)
- Switching between light and dark theme at runtime
- Disclosing and hiding entered password at runtime
- Powering off via soft button

## To do

... everything else ...

# Upstreaming

As far as feasible and sensible, [lvgl] and [lv_drivers] fixes and enhancements are being upstreamed. Ideally all code outside of `main.c` should be contributed back but I'm not yet sure if that will be possible.

Upstreamed contributions so far:

## lvgl

- [fix(examples) don't compile assets unless needed] (✅ merged)
- [feat(btnmatrix): add option to show popovers on button press] (⏳ in review)
- [feat(msgbox): add function to get selected button index] (⏳ in review)
- [feat(msgbox): omit title label unless needed] (⏳ in review)

## lv_drivers

- [Add support for pointer devices to libinput driver] (✅ merged)
- [Add support for keypads to libinput driver] (✅ merged)
- [Add full keyboard support to libinput/evdev driver] (⏳ in review)
- [Automatic device discovery via libinput] (⏳ in review)

# Development

## Dependencies

- [lvgl] (git submodule / linked statically)
- [lv_drivers] (git submodule / linked statically)
- [libinput]
- [libxkbcommon]

## Building & running

For development and testing you can run the app in a VT. `sudo` is needed to access input device files.

```
$ make
$ sudo chvt 2
$ sudo ./unl0kr
```

## Changing fonts

Fonts need to be converted to C arrays before they can be used with [lvgl]. This is most conveniently done using the official [online font converter]. Useful unicode ranges for the conversion are 0x0020-0x007F (basic Latin), 0x00A0-0x00FF (Latin-1 supplement), 0x0100-0x017F (Latin extended A) and 0x20A0-0x20CF (currency symbols). For the various `LV_SYMBOL_...` glyphs, make sure to also add [Font Awesome] with the following code points:

```
0xF001, 0xF008, 0xF00B, 0xF00C, 0xF00D, 0xF011, 0xF013, 0xF015, 0xF019, 0xF01C, 0xF021, 0xF026, 0xF027, 0xF028, 0xF03E, 0xF0E0, 0xF304, 0xF043, 0xF048, 0xF04B, 0xF04C, 0xF04D, 0xF051, 0xF052, 0xF053, 0xF054, 0xF067, 0xF068, 0xF06E, 0xF070, 0xF071, 0xF074, 0xF077, 0xF078, 0xF079, 0xF07B, 0xF093, 0xF095, 0xF0C4, 0xF0C5, 0xF0C7, 0xF0C9, 0xF0E7, 0xF0EA, 0xF0F3, 0xF11C, 0xF124, 0xF158, 0xF1EB, 0xF240, 0xF241, 0xF242, 0xF243, 0xF244, 0xF287, 0xF293, 0xF2ED, 0xF55A, 0xF7C2, 0xF8A2
```

as well as `0xF042` for the [adjust] icon.

It's also possible to do the conversion on the commandline, e.g.

```
$ npx lv_font_conv --bpp 4 --size 32 --no-compress -o montserrat_extended_32.c --format lvgl \
    --font Montserrat-Regular.ttf \
      --range '0x0020-0x007F' \
      --range '0x00A0-0x00FF' \
      --range '0x20A0-0x20CF' \
      --range '0x0100-0x017F' \
    --font FontAwesome5-Solid+Brands+Regular.woff \
      --range '0xF001,0xF008,0xF00B,0xF00C,0xF00D,0xF011,0xF013,0xF015,0xF019,0xF01C,0xF021,0xF026,0xF027,0xF028,0xF03E,0xF0E0,0xF304,0xF043,0xF048,0xF04B,0xF04C,0xF04D,0xF051,0xF052,0xF053,0xF054,0xF067,0xF068,0xF06E,0xF070,0xF071,0xF074,0xF077,0xF078,0xF079,0xF07B,0xF093,0xF095,0xF0C4,0xF0C5,0xF0C7,0xF0C9,0xF0E7,0xF0EA,0xF0F3,0xF11C,0xF124,0xF158,0xF1EB,0xF240,0xF241,0xF242,0xF243,0xF244,0xF287,0xF293,0xF2ED,0xF55A,0xF7C2,0xF8A2' \
      --range '0xF042'
```

# Acknowledgements

The [lv_port_linux_frame_buffer] project served as a starting point for the codebase. The mouse cursor image was taken from [lv_sim_emscripten].

# License

Unl0kr is licensed under the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

The Montserrat font is licensed under the Open Font License.

The Font Awesome font is licensed under the Open Font License version 1.1.

[lvgl]: https://github.com/lvgl/lvgl
[lv_drivers]: https://github.com/lvgl/lv_drivers
[lv_port_linux_frame_buffer]: https://github.com/lvgl/lv_port_linux_frame_buffer]
[lv_sim_emscripten]: https://github.com/lvgl/lv_sim_emscripten/blob/master/mouse_cursor_icon.c]
[libinput]: https://gitlab.freedesktop.org/libinput/libinput
[libxkbcommon]: https://github.com/xkbcommon/libxkbcommon
[online font converter]: https://lvgl.io/tools/fontconverter
[Font Awesome]: https://lvgl.io/assets/others/FontAwesome5-Solid+Brands+Regular.woff
[adjust]: https://fontawesome.com/v5.15/icons/adjust?style=solid
[fix(examples) don't compile assets unless needed]: https://github.com/lvgl/lvgl/pull/2523
[feat(btnmatrix): add option to show popovers on button press]: https://github.com/lvgl/lvgl/pull/2537
[feat(msgbox): add function to get selected button index]: https://github.com/lvgl/lvgl/pull/2538
[feat(msgbox): omit title label unless needed]: https://github.com/lvgl/lvgl/pull/2539
[Add support for pointer devices to libinput driver]: https://github.com/lvgl/lv_drivers/pull/150
[Add support for keypads to libinput driver]: https://github.com/lvgl/lv_drivers/pull/152
[Add full keyboard support to libinput/evdev driver]: https://github.com/lvgl/lv_drivers/pull/156
[Automatic device discovery via libinput]: https://github.com/lvgl/lv_drivers/pull/157
