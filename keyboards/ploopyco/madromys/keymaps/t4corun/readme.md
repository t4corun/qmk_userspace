# Ploopy Adept

Coded this as a standalone mouse as it mainly uses out of the box QMK functionality to achieve the desired features. I use this with my ZMK Totem

Features:
- Momentary Drag scroll for mouse wheel emulation
- Momentary Sniper for precision cursor movements
- Allows a different DPI to be selected for these alt-modes
- Can easily enter bootloader without hardware actions
- Can easily change DPI on the fly where the default keymap doesn't include the
key binds for this
- Adds some keyboard shortcuts to switch tabs without needing to move to the keyboard

Implementation:
- The alt-modes are enabled via layer state changes