# Lab 06 — Final Project: C Game + Git Workflow

## Overview

In this final lab you will design and implement a **game in C** of your choice, applying the concepts covered throughout the module:

- functions and modularisation,
- arrays and strings,
- control structures (loops, `if`, `switch`),
- and optionally recursion.

This is not just about having a game that works at the end.  
The main goal is to demonstrate an **organized development process**:

- a clear project structure,
- regular commits with meaningful messages,
- and a written record of your progress and difficulties in `LOG.md`.

You have **15 hours of supervised work time** in class, and you are allowed (and encouraged) to continue outside class if you wish.

---

## Objectives

By the end of this project, you should be able to:

- Design a small game in C from scratch.
- Split your code into multiple files (`main.c`, `game.c`, `game.h`).
- Apply functions, arrays, strings, and control structures in a realistic context.
- Use Git and GitHub to track your progress with **regular, meaningful commits**.
- Reflect on your own learning and problem-solving process in `LOG.md`.

---

## Repository Setup

Your **project repository** (not this lab repo) should be:

- Name: `projeto-final-c`
- Visibility: **Public**
- Contents (minimum structure):

projeto-final-c/
├── main.c
├── game.c
├── game.h
├── README.md
└── LOG.md

### `README.md` (project)

Must explain:

- What the game is (short description).
- How to **compile** the project (example `gcc` command).
- How to **run** the game.
- Any controls or keys the player needs to know.

### `LOG.md` (session log)

One entry **per work session**. Each entry should follow this structure:

## Session X – DD/MM/YYYY

**Features implemented today:**
- ...

**Main difficulty encountered and how I solved it (or did not solve it):**
...

**Next planned step:**
...

**Estimated lines of code written today:**
...

Updating `LOG.md` is **part of the grade**.

---

## Git and GitHub Workflow (Mandatory)

Version control is part of the assessment.

### A commit counts as valid if:

- The commit message follows the format:

    [Sessão X] short description
  ```

  Examples:
  - `[Sessão 1] Initial project structure`
  - `[Sessão 3] Implemented game loop and basic input validation`

- `LOG.md` is updated in the same commit.
- The code **compiles** (even if the game is incomplete).

### Not acceptable:

- A single commit at the end with the entire project.
- Empty or generic messages like `update`, `fix`, `changes`.
- A private repository without access shared with the instructor.

---

## Initial Git Setup (Reminder)

You should already have Git installed from the previous module.

Check in the terminal:
bash
git --version

If Git is not installed:

- **Windows**: https://git-scm.com/download/win  
- **macOS**: usually already included  
- **Linux (Debian/Ubuntu)**:

  ```bash
  sudo apt install git
  ```

### Step 1 – Configure your identity
bash
git config --global user.name "Your Name"
git config --global user.email "your_email@example.com"

### Step 2 – Create repository on GitHub

1. Go to https://github.com  
2. Click **New repository**  
3. Name: `projeto-final-c`  
4. Visibility: **Public**  
5. Do **not** initialize with a README

### Step 3 – Create and link local project
bash
mkdir projeto-final-c
cd projeto-final-c
code .     # or open the folder in VS Code

In the VS Code terminal:
bash
git init
git add .
git commit -m "[Sessão 0] Initial project structure"
git branch -M main
git remote add origin URL_OF_YOUR_REPOSITORY
git push -u origin main

From now on, for each work block:

1. Work on the code  
2. Update `LOG.md`  
3. `git add .`  
4. `git commit -m "[Sessão X] short description"`  
5. `git push`

---

## Game Requirements (Core)

You are free to choose the game, but it must meet these **minimum requirements**:

- Implemented in **C**.
- Uses at least:
  - **one header file** (`game.h`) and one additional source file (`game.c`),
  - **functions** to organize the logic (not everything in `main`),
  - **arrays** or **strings** in a meaningful way.
- Contains:
  - an input loop (e.g. turns, menu, or game loop),
  - some form of **state** (score, board, position, etc.),
  - clear feedback to the player (messages, prompts).

Examples of possible games (not mandatory):

- Tic-Tac-Toe with extra features,
- a simple text-based adventure,
- a number guessing game with scores,
- a simple grid-based game (e.g. “minesweeper-lite”, “snake-lite”, etc.).

If in doubt about the scope of your game, discuss it with the instructor.

---

## Optional – ncurses Visual Interface (Bonus)

By default, your game runs in the terminal using `printf`.  
If you want to go further, you can use the **ncurses** library to create a more appealing interface, with:

- colors,
- cursor movement,
- screen updates without scrolling.

This is the same library used by tools like `vim`, `htop`, and `nano`.

### Installation (summary)

- **Windows (MSYS2)**:

  ```bash
  pacman -S mingw-w64-ucrt-x86_64-ncurses
  ```

- **macOS**: usually available by default.
- **Linux (Debian/Ubuntu)**:

  ```bash
  sudo apt install libncurses5-dev libncursesw5-dev
  ```

### Compilation with ncurses
bash
gcc main.c game.c -o game -lncurses

The difference from a normal compile is the `-lncurses` at the end, which links the ncurses library.

Example:
c
#include ,[object Object]
