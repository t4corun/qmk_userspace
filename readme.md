# T4CORUN

My userspace for building QMK firmware via GitHub Actions. This does not require a local build environment where files are placed within keyboard subfolders.

The custom layout optimizes for programming (SQL, Powershell, C) and minimizes holds for comfort. It started from [Manna Harbor Miryoku](https://github.com/manna-harbour/miryoku) and took heavy influence from [Jonas Hietala T-34](https://www.jonashietala.se/series/t-34/).

## Features

### Layout Wrapper Macros

A single keymap layout can be shared with multiple keyboards by using C preprocessor macros. These macros are referenced in the keyboard JSON files, and the build process will expand them into a transient keymap.c file during compile time.

In this userspace, the base split 3x5_3 layout can be adapted for other split keyboards by expanding it with macros. For example, there is a wrapper that will add extra columns to the base layout for a Corne's 42-key 3x6_3 layout.

### Tri-Layer

Hold both thumb momentary layer keys `NAV` and `SYM` to access the `_NUMBER` layer

### One Shot Mods

One Shot Mods is here to minimize holding and simplify layers as mods are not required on every layer. Here we have bi-lateral(ish) GACS mods.

### Auto-Shift

Auto-Shift was implemented to reduce the need to hold shift for to get capital letters or particular symbols. This implementation also supports repeated output when a key is held

### Caps Word

Caps Word goes in tandem with Auto-Shift so we can temporarily type in all caps, such as programming variables. Tap `shift`  twice to enable Caps Word. It cancels when any key is pressed except

- `numbers 0-9`
- `backspace`
- `delete`
- `underscore`

### Repeat Key

Repeat Key was also implemented to help with RSI, with focus on reducing same finger bi-grams (SFBs) and minimizing repeating commands (e.g., `ctrl left-arrow` to navigate words). The repeat key is placed so it is available on most layers to help with muscle memory

### Tap-Holds

Certain keys have different behaviors when held vs tapped. For example, tapping `TR_LBRC '['` will give `[` and holding this will give `[]` and put the cursor inside. Only custom behaviors are implemented.

| Keycode   | When tapped | When held               | Comments                         |
| --------- | ----------- | ----------------------- | -------------------------------- |
| `TR_LBRC` | `[`         | `[]` with cursor inside | Use shift to get `{` / `{}`      |
| `TR_LABK` | `<`         | `<>` with cursor inside |                                  |
| `TR_LPRN` | `(`         | `()`with cursor inside  |                                  |
| `TR_PERC` | `%`         | `^`                     |                                  |
| `TR_COMM` | `,`         | `(`                     | to get parenthesis on base layer |
| `TR_DOT`  | `.`         | `)`                     |                                  |

## Optional Features

These features can be disabled due to MCU size constraints or because certain keyboards do not support it

### Pointing Device

This is specific to the Bastardkb Charybdis Nano and uses the charybdis.c to get pointing features as Sniper and Drag Scroll. `MOUSEKEY_ENABLE` do not need to be enabled in tandem with this to get the mouse buttons.

**Known Issue**: the layout needs to be adjusted for other keyboards if they don't have Charybdis Nano keycodes like `SNIPING` and `DRGSCRL`

### Mouse Keys

Enables mouse emulation for boards other than the Bastardkb Charybdis Nano

### RGB Matrix

Only for the Bastardkb Charybdis Nano as some keyboards have MCU Size constraints or others have barely visible LEDs. The primary focus is to provide an indicator for layer changes, mod status, lock status, dynamic macro and quantum key helpers

Review the keyboard files to identify the key position for each LED and update the preprocessor definitions in `config\rgbmatrix_config.h`

### OLED

Only enabled for the CRKBD Split keyboard (Corne). Here we will show the current layer,  current mods, and lock status

### Combos

Only for the Bastardkb Charybdis Nano. The current implementation provides critical mouse keys on the base layer. Only enable this when `POINTING_DEVICE_ENABLE = yes`

- Drag Scroll Toggle `DRG_TOG`
- Sniper Toggle `SNP_TOG`
- Mouse Button 4 (back) `KC_BTN4`

## Layout

```text
╭──────┬──────┬──────┬──────┬──────╮		 ╭──────┬──────┬──────┬──────┬──────╮
│ q    │ w    │ e    │ r    │ t    │		 │ y    │ u    │ i    │ o    │ p    │
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│ a    │ s    │ d    │ f    │ g    │ qwerty  │ h    │ j    │ k    │ l    │repeat│
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│ z    │ x    │ c    │ v    │ b    │		 │ n    │ m    │ , (  │ . )  │ - _  │
╰──────┴──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┴──────╯
              │ mb1  │ sym  │ mou  │		 │ spc  │ nav  │      │
              ╰──────┴──────┴──────╯		 ╰──────┴──────┴──────╯

╭──────┬──────┬──────┬──────┬──────╮		 ╭──────┬──────┬──────┬──────┬──────╮
│ q    │ w    │ f    │ p    │ b    │		 │ j    │ l    │ u    │ y    │ o    │
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│ a    │ r    │ s    │ t    │ g    │ colemak │ m    │ n    │ e    │ i    │repeat│
├──────┼──────┼──────┼──────┼──────┤   dh    ├──────┼──────┼──────┼──────┼──────┤
│ z    │ x    │ c    │ d    │ v    │		 │ k    │ h    │ , (  │ . )  │ - _  │
╰──────┴──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┴──────╯
              │ mb1  │ sym  │ mou  │		 │ spc  │ nav  │      │
              ╰──────┴──────┴──────╯		 ╰──────┴──────┴──────╯

Notes:
- swapped o and repeat on this keymap to keep repeat key in the same position across layers



╭──────┬──────┬──────┬──────┬──────╮		 ╭──────┬──────┬──────┬──────┬──────╮
│ esc  │ home │ up   │ end  │ pgup │		 │      │ ins  │      │      │ cfg  │
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│      │ left │ down │ rght │ pgdn │   nav   │ bksp │ shft │ ctrl │ alt  │ gui  │
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│ undo │ cut  │ copy │ pste │ redo │		 │ del  │ app  │ vol- │ vol+ │ mute │
╰──────┴──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┴──────╯
              │ tab  │ sym  │ ent  │		 │      │ nav  │      │
              ╰──────┴──────┴──────╯		 ╰──────┴──────┴──────╯

╭──────┬──────┬──────┬──────┬──────╮		 ╭──────┬──────┬──────┬──────┬──────╮
│ esc  │ &    │ @    │ $    │ % ^  │		 │ = +  │ #    │ < <> │ >    │ `    │
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│ ent  │ *    │ !    │ \ |  │ ; :  │ symbols │ bksp │ / ?  │ [ [] │ ]    │repeat│
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│ undo │ cut  │ copy │ pste │ redo │		 │ del  │ ' "  │ , () │ , )  │ - _  │
╰──────┴──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┴──────╯
              │      │ sym  │      │		 │ spc  │ nav  │      │
              ╰──────┴──────┴──────╯		 ╰──────┴──────┴──────╯

Notes:
- auto shift takes care of the symbols not found here
- manually press shift to get { and }


╭──────┬──────┬──────┬──────┬──────╮		 ╭──────┬──────┬──────┬──────┬──────╮
│ 9    │ 5    │ 1    │ 3    │ 7    │		 │ 6    │ 2    │ 0    │ 4    │ 8    │
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│ gui  │ alt  │ ctrl │ shft │ f11  │ numbers │ bksp │ spc  │      │ f12  │repeat│
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│ f9   │ f5   │ f1   │ f3   │ f7   │		 │ f6   │ f2   │ f10  │ f4   │ f8   │
╰──────┴──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┴──────╯
              │      │ sym  │      │		 │      │ nav  │      │
              ╰──────┴──────┴──────╯		 ╰──────┴──────┴──────╯

Notes:
- tri layer: Activate this layer by holding down symbol and navigation


╭──────┬──────┬──────┬──────┬──────╮		 ╭──────┬──────┬──────┬──────┬──────╮
│      │      │ dmr1 │ dmp1 │prnscr│		 │      │      │ boot │      │ cfg  │
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│rgbtog│rgbMod│ dmr2 │ dmp2 │scrlck│ config  │ caps │ shft │ ctrl │ alt  │ gui  │
├──────┼──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┼──────┤
│ hue+ │ sat+ │ vib+ │ spd+ │paubrk│		 │      │      │      │      │      │
╰──────┴──────┼──────┼──────┼──────┤		 ├──────┼──────┼──────┼──────┴──────╯
              │      │clmkdh│qwerty│		 │      │ nav  │      │
              ╰──────┴──────┴──────╯		 ╰──────┴──────┴──────╯
```

## Keyboards

- Bastardkb Charybdis Nano 3x5
- Crkbd 3x6
- Planck Rev6

## GitHub Action Notes

- Containers `ghcr.io/qmk/qmk_cli` and `qmkfm/qmk_cli` are the same. The former is hosted by GitHub and later by dockerhub
- I believe for best results, the values for the following item needs to be the same and matching case. If not, there may be issues building firmware
	- github username
	- `username.c` and `username.h`
	- this line in `rules.mk`: `SRC += $(USER_PATH)/username.c`

## Links

- [caksoylar/qmk_userspace](https://github.com/caksoylar/qmk_userspace/tree/main). Contains code to allow userspace custom keyboards to be visible in `/qmk_firmware/keyboards`
- [filterpaper/qmk_userspace](https://github.com/filterpaper/qmk_userspace/tree/main)
- [filterpaper's notes about Standalone Userspace](https://filterpaper.github.io/qmk/userspace.html)
