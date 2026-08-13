# EBadge Developer Guide

A guide for understanding and working on the EBadge firmware.

## 1. Repository Structure

```text
EBadge/
├── assets/
├── docs/
├── enclosure/
├── firmware/
│   └── eBadge/
└── hardware/
```

### Main directories

* `firmware/eBadge/` — EBadge firmware
* `hardware/` — PCB and hardware files
* `enclosure/` — enclosure/3D files
* `assets/` — project assets
* `docs/` — project documentation

---

## 2. Firmware Structure

The firmware is located in:

```text
firmware/eBadge/
```

Current source files:

| File               | Purpose                                     |
| ------------------ | ------------------------------------------- |
| `eBadge.ino`       | Main firmware and application state machine |
| `badge.cpp/h`      | Badge functionality                         |
| `buttons.cpp/h`    | Button input handling                       |
| `display.cpp/h`    | Display handling                            |
| `menu.cpp/h`       | Menu functionality                          |
| `storage.cpp/h`    | Persistent storage                          |
| `webportal.cpp/h`  | Web portal functionality                    |
| `flappygame.cpp/h` | Flappy game                                 |
| `dinogame.cpp/h`   | Dino game                                   |

The main application includes the display, buttons, storage, web portal, badge, menu, and game modules.

---

## 3. Application States

The main application uses a state machine defined in `eBadge.ino`.

The current states are:

```text
ST_CONFIG
ST_BADGE
ST_MENU
ST_FLAPPY
ST_DINO
ST_FLAPPY_OVER
ST_DINO_OVER
```

New application-level functionality should be considered in the context of this existing state structure rather than unnecessarily adding logic directly to unrelated states.

---

## 4. Buttons

The firmware currently defines five button inputs:

* `BTN_FLAP`
* `BTN_BACK`
* `BTN_UP`
* `BTN_DOWN`
* `BTN_MENU`

The pins are initialized using `INPUT_PULLUP`, and the button functions return `true` when their respective button is pressed. Button handling is contained in `buttons.cpp/h`.

---

## 5. Display

Display-related functionality is contained in:

```text
display.cpp
display.h
```

Display initialization and display operations should be kept within this module where practical.

When adding new UI, keep application logic separate from display-specific code.

---

## 6. Menu

Menu functionality is contained in:

```text
menu.cpp
menu.h
```

The menu is part of the main application state flow.

When modifying navigation, check how the change interacts with the other application states.

---

## 7. Storage

Persistent storage functionality is contained in:

```text
storage.cpp
storage.h
```

Storage-related operations should be handled through this module rather than being implemented independently throughout the firmware.

---

## 8. Adding Changes

Before modifying the firmware:

1. Understand the module you are changing.
2. Check where that module is used.
3. Keep changes limited to the relevant functionality.
4. Build the firmware.
5. Test the change on the actual hardware.
6. Check that existing functionality still works.

For larger functionality, consider separating it into its own source/header pair instead of adding unrelated code to `eBadge.ino`.

---

## 9. Debugging

When debugging a problem, try to isolate whether it originates from:

```text
Application logic
       ↓
Module
       ↓
Peripheral interface
       ↓
Hardware
```

Make one change at a time where possible and verify the result before moving on.

Hardware-related behaviour should be verified on the physical EBadge rather than relying only on compilation or code inspection.

---

## 10. Hardware Bring-Up

When working with a newly assembled board, verify the hardware progressively:

```text
Visual inspection
        ↓
Power
        ↓
MCU
        ↓
Display
        ↓
Buttons
        ↓
Other peripherals
        ↓
Full firmware
```

The exact bring-up procedure should be updated after the final hardware has been physically tested.

---

## 11. Keeping This Guide Updated

This guide should describe the **current implementation and development process**.

When the firmware architecture or hardware changes, update the relevant section so that future contributors can understand the current version of EBadge without having to reconstruct it from the source code.

