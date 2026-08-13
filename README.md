<br>
<p align="center">
<img src="https://github.com/Buddhadeb-ss/EBadge/blob/87a93fea70dd7d97d00e0bfd88fd6489e5ff0ba3/assets/logo.svg" width="400px" alt="Point Blank Logo"/>
</p>

# EBadge

## Overview

Official repository for the Point Blank Club Electronic Badge (EBadge). This project contains all hardware files, 3D printable enclosure designs, documentation, and firmware required to build and program your own feature-packed electronic event badge.

---

## Features

* **Interactive Display & Menu System:** Custom UI driven by dedicated display code.
* **On-Badge Games:**
  * **Dino Game:** Classic side-scrolling obstacle jump game.
  * **Flappy Game:** Flappy Bird style arcade game.
* **Web Portal Interface:** Onboard Wi-Fi web portal for setup and customization.
* **Local Storage Support:** Persistent saving for preferences, high scores, and settings.
* **Tactile Controls:** Dedicated button engine for responsive navigation and gameplay.
* **Custom Hardware & Enclosure:** Complete KiCad PCB design, gerber files, BOM, and 3D printable STL enclosure models.

---

## Repository Structure

```text
EBadge/
├── assets/             # Branding assets and graphics
├── docs/               # Detailed guides and project documentation
│   ├── GUIDE.md        # Development, setup and firmware guide
│   ├── CONTRIBUTING.md # Contribution workflow and guidelines
│   ├── ISSUES.md       # Guide for reporting bugs and problems
│   ├── FUTURE_FEATURES.md # Prioritised software feature backlog
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
    ├── gerbers/        # Production-ready PCB Gerber files
    └── kicad/          # KiCad EDA source files
```
