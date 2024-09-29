# Keyball series

This directory includes source code of Keyball keyboard series:

| Name                     | Description                                                             |
| ------------------------ | ----------------------------------------------------------------------- |
| [Keyball39](./keyball39) | A split keyboard with 39 vertically staggered keys and 34mm track ball. |

* Keyboard Designer: [@Yowkees](https://twitter.com/Yowkees)  
* Hardware Supported: RP2040 Promicro like footprint
* Hardware Availability:

See each directories for each keyboards in a table above.

Maintainer Note: it appears that the [Yowkee's repo](https://github.com/Yowkees/keyball/tree/main/qmk_firmware/keyboards/keyball) is not compatible with modern QMK Firmware. The code was updated for

* native RP2040 Promicro support
* RGB Matrix support
* Using QMK's pointer driver and including BastardKB's drag scroll and sniper code
* Migrating configuration to JSON files

## How to build

This keyboard is a non QMK Tree keyboard, which means you need to manually copy Keyball's keyboard definition files to your local qmk_firmware clone to build firmware

1. Clone this repository to your machine.

    ```console
    $ git clone https://github.com/t4corun/qmk_userspace
    ```

2. Check out [qmk/qmk_firmware](https://github.com/qmk/qmk_firmware/) repository in another place.

    ```console
    $ git clone https://github.com/qmk/qmk_firmware.git --depth 1 --recurse-submodules --shallow-submodules
    ```

    Currently Keyball firmwares are verified to compile with QMK 0.26.5 (2024 September)

3. Copy the `/keyboard/keyball` directory to qmk/qmk_firmware's `keyboards/` directory

4. `make` your Keyball firmware.

    ```console
    # Build Keyball39 firmware with "default" keymap
    $ make keyball/keyball39:default
    ```

5. Follow QMK [documentation](https://docs.qmk.fm/newbs_building_firmware#open-keymap-c-in-your-favorite-text-editor) to add your own keymap
