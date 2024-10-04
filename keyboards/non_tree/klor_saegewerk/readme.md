```text
█         █    █            ▄▄▄▀▀▀▀▀▀▄▄▄        █▀▀▀▀▀▀▀▀▀▀█
█        █     █          ▄▀            ▀▄      █          █
█       █      █        ▄▀                ▀▄    █          █
█      █       █        █                  █    █          █
█     █        █       █                    █   █          █
█    █         █       █                    █   █▄▄▄▄▄▄▄▄▄▄█
█   █ █        █       █                    █   █      █
█  █   █       █        █                  █    █       █
█ █     █      █        ▀▄                ▄▀    █        █
██       █     █          ▀▄            ▄▀      █         █
█         █    █▄▄▄▄▄▄▄▄    ▀▀▀▄▄▄▄▄▄▀▀▀        █          █
```

# KLOR Saegewerk split keyboard

KLOR is a 36-42 key column-staggered split keyboard. It supports a per key RGB matrix, encoders, OLED displays, haptic feedback, audio, a Pixart Paw3204 trackball and four different layouts, through brake off parts.

![layouts](https://raw.githubusercontent.com/GEIGEIGEIST/qmk-config-klor/refs/heads/main/docs/images/klor-layouts.svg)

* Keyboard Maintainer: [geigeigeist](https://github.com/GEIGEIGEIST)
* Hardware Supported: ?
* Hardware Availability: Beekeeb

## t4corun's Notes

This code enables me to build @geigeigeist's KLOR Saegewerk for my userspace. The original is not currently compatible with modern QMK. You are welcome to copy this custom definition, then alter it for the other variants and your needs. My [other branch](https://github.com/t4corun/qmk_userspace/tree/mouse_usability/keyboards/klor) has the JSON Matrix Layout and RGB Matrix layout for the other variants. Updates:

* Migrated relevant configuration to `.json` files
* This is Sea-Picro RP2040 native
* Only has RGB Matrix
* Removed unnecessary kb code/configuration to reduce code maintenance. Notably, functionality which is handled in the userspace

## How to Build

Please see my [userspace readme](../../../README.md) on how build using this keyboard definition
