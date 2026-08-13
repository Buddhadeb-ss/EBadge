# 🏷️ EBadge — Point Blank Club Electronic Badge

Welcome to the official repository for the **Point Blank Club Electronic Badge (EBadge)**! This project contains all the hardware files, 3D printable enclosure designs, documentation, and firmware required to build and program your own feature-packed electronic event badge.

---

## ✨ Features

* **Interactive Display & Menu System:** Custom UI driven by dedicated display code.
* **On-Badge Games:**
  * 🦖 **Dino Game:** Classic side-scrolling obstacle jump game.
  * 🐤 **Flappy Game:** Flappy Bird style arcade game.
* **🌐 Web Portal Interface:** Onboard Wi-Fi web portal for setup and customization.
* **💾 Local Storage Support:** Persistent saving for preferences, high scores, and settings.
* **🕹️ Tactile Controls:** Dedicated button engine for responsive navigation and gameplay.
* **📐 Custom Hardware & Enclosure:** Complete KiCad PCB design, gerber files, BOM, and 3D printable STL enclosure models.

---

## 📁 Repository Structure

```text
EBadge/
├── assets/             # Branding assets and graphics
├── docs/               # Detailed guides and visual documentation
│   ├── guide.md        # Comprehensive setup and usage guide
│   └── Images/         # Documentation screenshots and visual aids
├── enclosure/          # 3D printable files & enclosure visuals
│   ├── Images/         # Photos/renders of the assembled badge
│   └── STL/            # 3D printable STL models
├── firmware/           # Microcontroller source code
│   └── eBadge/         # Main firmware code directory
│       ├── eBadge.ino  # Main entry sketch
│       ├── menu.*      # UI & menu engine
│       ├── webportal.* # Web interface module
│       ├── display.*   # Display driver code
│       ├── buttons.*   # Button input handler
│       ├── storage.*   # Non-volatile memory controller
│       ├── dinogame.*  # Dino game module
│       └── flappygame.*# Flappy game module
└── hardware/           # Hardware and circuit design files
    ├── BOM/            # Bill of Materials
    ├── datasheets/     # Component datasheets
    ├── gerbers/        # Production-ready PCB gerber files
    └── kicad/          # KiCad EDA source files