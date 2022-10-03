# Changelog

## Unreleased

- feat: Update lvgl & lv_drivers to git master (2022-08-17)
- feat: Add config option to customise bullet character (#17)
- fix: Use actual screen DPI value to compute sizes and spaces
- feat: Allow shutting down the device on inactivity
- fix: Disable terminal keyboard while unl0kr is running
- feat: Extend --geometry flag to also accept display offsets
- fix: Swap order of KDSKBMODE and KDSETMODE to prevent blank screen (#34)

## 0.2.0 (2022-05-27)

- fix: Make meson actually install things (thanks @craftyguy)
- feat!: Make en-US the default layout
- fix: Use correct pointer type in memset to avoid segfault
- feat: Set correct version in meson.build
- feat: Add postmarketOS theme (thanks @dylanvanassche)
- feat: Handle physical return key (#19)
- fix: Avoid TTY cursor blinking (#26)
- fix: Specify `check: true` when running external commands from meson (#23)
- feat!: Hide partition name (#27)
- fix: Prevent scrolling when keyboard hides (#21)
- feat!: Do not show last typed character when typing (#25)
- feat: Update lvgl & lv_drivers to git master (2022-02-21)
- feat: allow runtime selection of the lvgl display driver ("backend")
- feat: allow overriding dpi with the --dpi command line parameter

## 0.1.0 (2021-11-15)

Initial release
