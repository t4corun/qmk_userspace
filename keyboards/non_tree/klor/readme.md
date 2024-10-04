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

This code is a rewrite for @geigeigeist's KLOR Saegewerk for my userspace. The original is not currently compatible with modern QMK. You are welcome to copy this custom definition, then alter it for the other variants.

- [@geigeigeist's repo](https://github.com/GEIGEIGEIST/qmk-config-klor)
- My [other branch](https://github.com/t4corun/qmk_userspace/tree/mouse_usability/keyboards/klor) has the JSON Matrix Layout and RGB Matrix layout for the other variants.

Updates

- Migrated relevant configuration to `.json` files
- This file is Sea-Picro RP2040 native
- Only has RGB Matrix
- Removed unneeded code/default configuration to reduce code maintenance. For example there is minimal OLED rendering. These things are handed in the userspace level

## How to build

Please see my [userspace readme](../../../README.md) on how build using this keyboard definition
