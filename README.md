Unl0kr
======

Framebuffer-based disk unlocker for the initramfs based on [LVGL].

[[_TOC_]]

# About

Unl0kr is an [osk-sdl] clone written in [LVGL] and rendering directly to the Linux framebuffer. As a result, it doesn't depend on GPU hardware acceleration.

For some background on how unl0kr came to be, see postmarketOS/osk-sdl#121.

# Status

We are en route to v1 which aims at providing a useable, visually pleasant application including [osk-sdl]'s most essential features. For details about the current status, see the [v1 milestone]. You may also browse the full list of [open issues] to get an idea of what's planned beyond v1.

Here are a few highlights of what already works:

- Password-entry UI including on-screen keyboard on the framebuffer
- Input device discovery for keyboards, mice, trackpads and touch screens
- On-screen keyboard control via:
  - One or more mice / trackpads (including cursor)
  - One or more hardware keyboards (including support for different layouts using XKB)
  - Touchscreen (tested on PinePhone)
- Switching on-screen keyboard layout at runtime (currently supported layouts: de, es, fr, us)
- Toggling on-screen keyboard with slide in/out animation
- Switching between light and dark theme at runtime
- Disclosing and hiding entered password at runtime
- Shutting down the device via a soft button

## Upstreaming

Over the course of implementing unl0kr, suitable fixes and features have been upstreamed to the [lvgl] and [lv_drivers] repositories. The benefit of this goes both ways. Downstream we can rely on the features being maintained in the future and upstream they can make the features available to the larger audience of [LVGL] users.

Below is a summary of contributions upstreamed thus far.

### lvgl

- [fix(examples) don't compile assets unless needed] (✅ merged)
- [feat(btnmatrix): add option to show popovers on button press] (⏳ in review)
- [feat(msgbox): add function to get selected button index] (✅ merged)
- [feat(msgbox): omit title label unless needed] (✅ merged)
- [fix(btnmatrix): make ORed values work correctly with lv_btnmatrix_has_btn_ctrl] (⏳ in review)

### lv_drivers

- [Add support for pointer devices to libinput driver] (✅ merged)
- [Add support for keypads to libinput driver] (✅ merged)
- [Add full keyboard support to libinput/evdev driver] (✅ merged)
- [Automatic device discovery via libinput] (✅ merged)
- [Make it possible to use multiple devices with the libinput and XKB drivers] (⏳ in review)

# Development

## Dependencies

- [lvgl] (git submodule / linked statically)
- [lv_drivers] (git submodule / linked statically)
- [squeek2lvgl] (git submodule / linked statically)
- [libinput]
- [libxkbcommon]
- evdev kernel module

## Building & running

For development and testing you can run the app in a VT. Unless your user account has special privileges, `sudo` will be needed to access input device files.

```
$ make
$ sudo chvt 2
$ sudo ./unl0kr
```

## Fonts

In order to work with [LVGL], fonts need to be converted to bitmaps, stored as C arrays. Unl0kr currently uses a combination of the [Montserrat] font for text and the [FontAwesome] font for pictograms. For both fonts only limited character ranges are included to reduce the binary size. To (re)generate the C file containing the combined font, run the following command

```
$ npx lv_font_conv --bpp 4 --size 32 --no-compress -o montserrat_extended_32.c --format lvgl \
    --font Montserrat-Regular.ttf \
      --range '0x0020-0x007F' \
      --range '0x00A0-0x00FF' \
      --range '0x0100-0x017F' \
      --range '0x2000-0x206F' \
      --range '0x20A0-0x20CF' \
    --font FontAwesome5-Solid+Brands+Regular.woff \
      --range '0xF001,0xF008,0xF00B,0xF00C,0xF00D,0xF011,0xF013,0xF015,0xF019,0xF01C,0xF021,0xF026,0xF027,0xF028,0xF03E,0xF0E0,0xF304,0xF043,0xF048,0xF04B,0xF04C,0xF04D,0xF051,0xF052,0xF053,0xF054,0xF067,0xF068,0xF06E,0xF070,0xF071,0xF074,0xF077,0xF078,0xF079,0xF07B,0xF093,0xF095,0xF0C4,0xF0C5,0xF0C7,0xF0C9,0xF0E7,0xF0EA,0xF0F3,0xF11C,0xF124,0xF158,0xF1EB,0xF240,0xF241,0xF242,0xF243,0xF244,0xF287,0xF293,0xF2ED,0xF55A,0xF7C2,0xF8A2' \
      --range '0xF042' \
      --range '0xF35B'
```

Below is a short explanation of the different unicode ranges used above.

- [Montserrat]
  - Basic Latin (`0x0020-0x007F`)
  - Latin-1 supplement (`0x00A0-0x00FF`)
  - Latin extended A (`0x0100-0x017F`)
  - General punctuation (`0x2000-0x206F`)
  - Currency symbols (`0x20A0-0x20CF`)
- [FontAwesome]
  - Standard `LV_SYMBOL_*` glyphs (`0xF001,0xF008,0xF00B,0xF00C,0xF00D,0xF011,0xF013,0xF015,0xF019,0xF01C,0xF021,0xF026,0xF027,0xF028,0xF03E,0xF0E0,0xF304,0xF043,0xF048,0xF04B,0xF04C,0xF04D,0xF051,0xF052,0xF053,0xF054,0xF067,0xF068,0xF06E,0xF070,0xF071,0xF074,0xF077,0xF078,0xF079,0xF07B,0xF093,0xF095,0xF0C4,0xF0C5,0xF0C7,0xF0C9,0xF0E7,0xF0EA,0xF0F3,0xF11C,0xF124,0xF158,0xF1EB,0xF240,0xF241,0xF242,0xF243,0xF244,0xF287,0xF293,0xF2ED,0xF55A,0xF7C2,0xF8A2`)
  - [adjust] (`0xF042`)
  - [arrow-alt-circle-up] (`0xF35B`)

## Keyboard layouts

Unl0kr uses [squeekboard layouts] converted to C via [squeek2lvgl]. To regenerate the layouts, run

```
$ ./regenerate-layouts.sh
```

from the root of the repository.

## Screen recording

For demonstration purposes you can record the framebuffer device, e.g. with ffmpeg:

```
$ sudo ffmpeg -f fbdev -i /dev/fb0 -r 24 -c:v libx264 -b:v 500k demo.avi
```

# Acknowledgements

The [lv_port_linux_frame_buffer] project served as a starting point for the codebase.

The mouse cursor image was taken from [lv_sim_emscripten].

# License

Unl0kr is licensed under the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

The [Montserrat] font is licensed under the Open Font License.

The [FontAwesome] font is licensed under the Open Font License version 1.1.

[Add full keyboard support to libinput/evdev driver]: https://github.com/lvgl/lv_drivers/pull/156
[Add support for keypads to libinput driver]: https://github.com/lvgl/lv_drivers/pull/152
[Add support for pointer devices to libinput driver]: https://github.com/lvgl/lv_drivers/pull/150
[Automatic device discovery via libinput]: https://github.com/lvgl/lv_drivers/pull/157
[FontAwesome]: https://fontawesome.com
[LVGL]: https://lvgl.io
[Make it possible to use multiple devices with the libinput and XKB drivers]: https://github.com/lvgl/lv_drivers/pull/165
[Montserrat]: https://fonts.google.com/specimen/Montserrat
[adjust]: https://fontawesome.com/v5.15/icons/adjust?style=solid
[arrow-alt-circle-up]: https://fontawesome.com/v5.15/icons/arrow-alt-circle-up?style=solid
[feat(btnmatrix): add option to show popovers on button press]: https://github.com/lvgl/lvgl/pull/2537
[feat(msgbox): add function to get selected button index]: https://github.com/lvgl/lvgl/pull/2538
[feat(msgbox): omit title label unless needed]: https://github.com/lvgl/lvgl/pull/2539
[fix(btnmatrix): make ORed values work correctly with lv_btnmatrix_has_btn_ctrl]: https://github.com/lvgl/lvgl/pull/2571
[fix(examples) don't compile assets unless needed]: https://github.com/lvgl/lvgl/pull/2523
[libinput]: https://gitlab.freedesktop.org/libinput/libinput
[libxkbcommon]: https://github.com/xkbcommon/libxkbcommon
[lv_drivers]: https://github.com/lvgl/lv_drivers
[lv_port_linux_frame_buffer]: https://github.com/lvgl/lv_port_linux_frame_buffer
[lv_sim_emscripten]: https://github.com/lvgl/lv_sim_emscripten/blob/master/mouse_cursor_icon.c
[lvgl]: https://github.com/lvgl/lvgl
[online font converter]: https://lvgl.io/tools/fontconverter
[open issues]: https://gitlab.com/cherrypicker/unl0kr/-/issues
[osk-sdl]: https://gitlab.com/postmarketOS/osk-sdl
[squeek2lvgl]: https://gitlab.com/cherrypicker/squeek2lvgl
[squeekboard layouts]: https://gitlab.gnome.org/World/Phosh/squeekboard/-/tree/master/data/keyboards
[v1 milestone]: https://gitlab.com/cherrypicker/unl0kr/-/milestones/1
