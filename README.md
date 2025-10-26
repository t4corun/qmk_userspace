# T4CORUN Userspace

My External Userspace to build QMK firmware through GitHub Actions. 

*Note: Please feel free to leverage this at your own risk. I am not responsible for any damage or loss that may occur from using my userspace.*

## Layout

The custom layout optimizes for programming (SQL, Powershell, C) and minimizes holds for comfort. It started from [Manna Harbor Miryoku](https://github.com/manna-harbour/miryoku) and took heavy influence from [Jonas Hietala T-34](https://www.jonashietala.se/series/t-34/). Themes:

- Keymap targets split 3x5 boards with five thumb keys (three left and two right) and integrated pointing device.
- Optional support for
  - Dual encoders. Favor the right side encoder when there is only one
  - tight integration with a Ploopy Nano Trackball
- Releasing all keys always brings you back to base layer
- Layers are designed orthogonally with a single purpose per hand and are accessed by holding a thumb key on the opposite hand
- Reworking Symbols for programming focus
  - Common symbols are positioned under stronger fingers
  - Custom behavior from holds
- Advanced macros to minimize/simplify layers

![image](keymap-drawer.svg)

## Target Keyboards

QMK Tree

- Bastardkb Charybdis Nano 3x5
- Ferris Swoop
- Ploopy Nano

Non Tree

- Keyball39
- KLOR Saegewerk
- Rollow

## How to Build

Since I have keyboards that are not part of QMK Firmware (e.g. Keyball39) I need to take extra steps to build these. Below are instructions on how to do this either through Github Actions or your local build environment.

### via GitHub Actions

This method will enable one to build firmware without a local build environment on their computer. The GitHub Actions have been extended to copy keyboard definitions from your userspace to the build container's keyboards folder before compiling. The customizations include

- Using `Bastardkb/bastardkb-qmk:bkb-master`branch to include the latest and greatest keyboard definition for the Charybdis Nano
- Copying my keyboard definitions for keyboards not included with qmk_firmware so they can be built using the GitHub Action

`qmk_userspace_build.yml` and `qmk_userspace_publish.yml` were copied from [qmk/.github](https://github.com/qmk/.github), then extended to add these customizations

### via Local Build Environment

The same customizations as described in the build via GitHub Actions need to be applied to a local qmk_firmware clone or fork.

```bash
# alter the source userspace path and target qmk_firmware path as needed
cp -r /d/Repo/qmk_userspace/keyboards/non_tree /d/Repo/qmk_firmware/keyboards/.

# alter the paths as necessary to copy the 
git clone https://github.com/Bastardkb/bastardkb-qmk.git
cd bastardkb-qmk
git checkout bkb-master
rm -rf qmk_firmware/keyboards/bastardkb
cp bastardkb-qmk/keyboards/bastardkb qmk_firmware/keyboards -R

# build firmware
qmk compile -kb non-tree/keyball39 -km t4corun
qmk compile -kb bastardkb/charybdis/3x5 -km t4corun
```

## Notable Features

Quick summary of features. Some of these can be enabled/disabled if they are not needed and/or fit on smaller MCUs

- Tri-Layer: Hold both thumb momentary layer keys `NAVIGATION` and `NUMBER` to access the `SYMBOL` layer
- Implemented bi-lateral GACS Homerow mods.
- Caps Word: enables temporary all-caps typing without holding shift. Useful to typing programming variables
- Pointing Device: enable trackball on certain boards (e.g. Keyball39 and Bastardkb Charybdis Nano). Note
- OLED Displays: Displays active layers, modifiers, host state, and feature status. Shows Pointer CPI and RGB values. Support for 128x32 or 128x64 screens

Additional features below

### Layout Wrapper Macros

A single keymap layout can be shared with multiple keyboards by using C preprocessor macros. These macros are referenced in the keyboard JSON files, and the build process will expand them into a transient keymap.c file during compile time.

In this userspace, my keymap can adapted for various split keyboards by adding/removing keys with macros. For example, there is a wrapper that will add the outer columns for a Corne's 42-key 3x6_3 layout.

### Integrated Pointer Device

This is for my boards with integrated trackball (e.g., `Keyball39`). My goal is to have a fully functional mouse without needing a separate mouse layer

- `MOUSEKEY_ENABLE` do not need to be enabled get the mouse click buttons
- Drag Scrolling is enabled whenver `NUMBER` layer is active
- Can use the mouse one handed

### Ploopy Nano Integration

When enabled, use host state LED macros to allow the keyboard to control Ploopy Nano function.

| Press on Keyboard        | Result on Ploopy Nano            | Comment                                                    |
| ------------------------ | -------------------------------- | ---------------------------------------------------------- |
| Scroll Lock              | momentary Drag Scrolling         |                                                            |
| Num Lock                 | switches DPI                     |                                                            |
| Scroll + Num + Caps Lock | puts Ploopy Nano into bootloader | See [Toggle Configuration](#toggle-configuration) for this |

### Tap-Holds

Certain keys have different behaviors when held vs tapped allowing commonly typed programming syntax or shifting certain keycodes without actually pressing/holding shift. Opted to implement overrides here instead of using built-in Key Override functionality because this implementation does not require pressing/holding shift to get the alternate key

| Keycode   | When tapped | When held               | Comments                          |
| --------- | ----------- | ----------------------- | --------------------------------- |
| `BK_LBRC` | `[`         | `[]` with cursor inside |                                   |
| `BK_LABK` | `<`         | `<>` with cursor inside |                                   |
| `BK_LPRN` | `(`         | `()` with cursor inside |                                   |
| `BK_DQUO` | `"`         | `""` with cursor inside |                                   |
| `BK_SQUO` | `'`         | `''` with cursor inside |                                   |
| `DT_BSLS` | `\`         | `\\`                    |                                   |
| `DT_SLSH` | `/`         | `//`                    |                                   |
| `DT_PIPE` | `\|`        | `\|\|`                  |                                   |
| `OR_COMM` | `,`         | `(`                     | enables parenthesis on base layer |
| `OR_DOT`  | `.`         | `)`                     |                                   |
| `AS_MINS` | `-`         | `_`                     |                                   |
| `AS_QUOT` | `'`         | `"`                     |                                   |

### Advanced Encoder Functionality

- Super Tabbing: in the `NUMBER`, the encoder will send `Tab` and `Shift + Tab`. Holding `alt` or `ctrl` while turning the encoder will allow Window or Browser tab switching. Active on 
- Zoom: the encoder will send `Ctrl + Mouse Wheel Up` and `Ctrl + Mouse Wheel Down` without having to hold modifiers

### Super Configuration Macros

Implemented custom macros which enable modifiers to change output. This allows us to combine all the QMK configuration change macros into three keys. These can be used with encoders too.

#### Increment/Decrement configuration

| Held Modifier      | Increase (`FWD_CFG`) or Decrease (`REV_CFG`) |
| ------------------ | -------------------------------------------- |
| None               | nothing                                      |
| Shift              | RGB Matrix Hue                               |
| Ctrl               | RGB Matrix Sat                               |
| Alt                | RGB Matrix Brightness                        |
| Gui                | RGB Matrix Animation Speed                   |
| Shift + Ctrl       | RGB Matrix Animation                         |
| Ctrl  + Alt        | Audio Click Frequency                        |
| Shift + Ctrl + Alt | Haptic Feedback Mode                         |

#### Toggle Configuration

| Held Modifier      | Toggles (`TOG_CFG`)                          |
| ------------------ | -------------------------------------------- |
| None               | Cycles base layers: QWERTY, COLEMAK DH, GAME |
| Shift              | Enter Bootloader                             |
| Ctrl               | Reset EEPROM                                 |
| Alt                | Tell Ploopy Nano to enter Bootloader         |
| Shift + Ctrl       | RGB Matrix On/Off                            |
| Shift + Alt        | Combo On/Off                                 |
| Shift + Gui        | Audio On/Off                                 |
| Ctrl  + Alt        | Audio Clicky On/Off                          |
| Shift + Ctrl + Alt | Haptic Feedback On/Off                       |
| Shift + Ctrl + Gui | Haptic Feedback Reset                        |
| Shift + Alt  + Gui | Haptic Key Toggle                            |
| Ctrl  + Alt  + Gui | Haptic Continuous Toggle                     |

## Links

- [qmk documentation](https://docs.qmk.fm/#/)
- [qmk/awesome-userspaces Github](https://github.com/qmk/awesome-userspaces?tab=readme-ov-file). Links to fantastic userspaces to draw inspiration from, such as Drashna's
