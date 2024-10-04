# Rollow Split Keyboard

Rollow is ultra low-profile 3x6+2 or 3x5+2 keys column-staggered split keyboard with dual horizontal thumb encoders.

<img src="https://assets.bigcartel.com/product_images/327532800/BothBoards_Logo.png" height="300"><img src="https://i.imgur.com/bfkJtzK.jpeg" height="300">

The current build guide is [available here](https://github.com/barbellboards/Rollow/blob/main/Instructions/BuildGuide.md)

* Keyboard Maintainer: [Barbell Boards](https://github.com/barbellboards)
* Hardware Supported: Rollow Rev 1
* Hardware Availability: No longer available after initial Summer 2022 production run

## t4corun's Notes

This code enables me to build Rollow 3x5 firmware for my userspace. The original is not currently compatible with modern QMK. You are welcome to copy this custom definition, then alter it for your needs. My [other branch](https://github.com/t4corun/qmk_userspace/tree/mouse_usability/keyboards/barbellboards/rollow) may have more code that I removed. Updates:

* Migrated relevant configuration to `.json` files
* This is Sea-Picro RP2040 native
* Only 3x5 layout is defined
* Removed unnecessary kb code/configuration to reduce code maintenance. Notably, functionality which is handled in the userspace

## How to Build

Please see my [userspace readme](../../README.md) on how build using this keyboard definition
