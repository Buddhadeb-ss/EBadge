# Contributing to EBadge

Thanks for contributing to EBadge.

This document describes the basic workflow for making changes to the project and keeping the repository organized.

---

## 1. Before You Start

Before working on EBadge:

1. Make sure you are working with the latest version of the repository.
2. Check the existing code and documentation before making changes.
3. Check whether someone is already working on the same part of the project.
4. If your change affects another part of the system, coordinate with the person responsible for it.

Avoid duplicating work that is already in progress.

---

## 2. Repository Structure

Keep changes in the appropriate part of the repository.

```text
EBadge/
├── assets/
├── docs/
├── enclosure/
├── firmware/
│   └── eBadge/
└── hardware/
```

Examples:

* Firmware changes → `firmware/eBadge/`
* Documentation → `docs/`
* PCB/hardware changes → `hardware/`
* Enclosure changes → `enclosure/`
* Project assets → `assets/`

---

## 3. Branches

Create a separate branch for your work instead of directly modifying the main branch.

Use a short, descriptive branch name.

Examples:

```text
feature/diagnostic-mode
feature/new-animation
fix/button-input
docs/guide
hardware/pcb-revision
```

Keep each branch focused on one change or closely related set of changes.

---

## 4. Making Changes

Before committing:

* Understand the existing implementation.
* Keep the change focused.
* Avoid modifying unrelated code.
* Follow the existing structure of the project.
* Remove temporary debug code that is no longer needed.
* Update relevant documentation when the behaviour of the project changes.

For firmware changes, test the result on the physical EBadge whenever possible.

---

## 5. Commits

Write clear commit messages that describe what changed.

Good examples:

```text
Add button input handling
Fix menu navigation
Update display initialization
Add badge storage support
Document firmware structure
```

Avoid vague messages such as:

```text
update
changes
stuff
fix
final
```

Keep commits reasonably focused so that changes are easy to understand and review.

---

## 6. Testing

Before opening a pull request, verify that:

* [ ] The project builds successfully.
* [ ] The changed functionality works as expected.
* [ ] The change has been tested on hardware when applicable.
* [ ] Existing functionality affected by the change still works.
* [ ] No unnecessary debug code or files are included.

If something could not be tested because the required hardware was unavailable, mention that in the pull request.

---

## 7. Pull Requests

When your work is ready:

1. Push your branch to GitHub.
2. Open a pull request against the main branch.
3. Explain what was changed.
4. Explain how the change was tested.
5. Mention any known limitations or things that still need testing.

Keep pull requests focused and easy to review.

### Example

```text
## What changed

Added improved button handling for the menu.

## Testing

- Tested all five buttons on hardware
- Verified menu navigation
- Verified existing badge screen and games
```

---

## 8. Hardware Changes

Hardware changes should be documented clearly.

For PCB changes, include relevant information such as:

* What was changed
* Why it was changed
* Components affected
* PCB revision
* Testing performed

Do not replace existing hardware files without making sure the new version is clearly identifiable.

---

## 9. Documentation

If a change affects how EBadge is built, used, developed, or tested, update the relevant documentation.

Useful documentation should explain the project clearly enough that another member can continue the work without needing to rediscover the same information.

---

## 10. Keep Changes Reviewable

The goal is not to make every change perfect before sharing it.

If you are unsure about an approach, opening a draft pull request can be useful for discussing the implementation early.

Keep the work visible and communicate when a change affects another contributor's work.

---

## 11. General Principle

EBadge is a collaborative project.

Own your part of the work, but keep the rest of the team informed when your changes interact with theirs.

**Build → test → document → share.**
