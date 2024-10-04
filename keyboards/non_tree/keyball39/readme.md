# Keyball39

A split keyboard with 39 vertically staggered keys and 34mm track ball

<img src="https://raw.githubusercontent.com/Yowkees/keyball/refs/heads/main/keyball39/doc/rev1/images/kb39_001.jpg" height="500">

* Keyboard Designer: [@Yowkees](https://github.com/Yowkees/keyball)  
* Hardware Supported: RP2040 Promicro like footprint
* Hardware Availability: [yushakobo](https://shop.yushakobo.jp/products/5357), [shirogane lab](https://shirogane-lab.net/items/64b8f8693ee3fd0045280190), [holykeebs](https://holykeebs.com/products/keyball39)

## t4corun's Notes

This code enables me to build Keyball39 firmware for my userspace. The original is not currently compatible with modern QMK. You are welcome to copy this custom definition, then alter it for your needs. My [other branch](https://github.com/t4corun/qmk_userspace/tree/mouse_usability/keyboards/keyball/keyball39) may have more code that I removed. Updates:

* Migrated relevant configuration to `.json` files
* Sea Picro RP2040 Promicro native
* enabled RGB Matrix
* Using QMK's pointer driver and including BastardKB's drag scroll and sniper code
* Only right ball layout is defined
* Removed unnecessary kb code/configuration to reduce code maintenance. Notably, functionality which is handled in the userspace

## How to Build

Please see my [userspace readme](../../../README.md) on how build using this keyboard definition
