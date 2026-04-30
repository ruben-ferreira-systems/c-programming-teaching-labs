## Teaching Context

These labs were developed and used in a vocational training environment (IEFP), where students often have:
- no prior programming experience
- diverse technical backgrounds
- limited exposure to structured problem-solving

The material was adapted to prioritise clarity, repetition, and incremental difficulty.

## Design Philosophy

- Simplicity over cleverness
- Explicit logic over abstraction
- Teaching progression over code optimisation

## Technical Focus

- **Language**: C
- **Core topics**:
  - Input/output and basic types
  - Conditional logic and loops
  - Functions and function prototypes (“promises”)
  - Use of named constants instead of magic numbers
  - Arrays, strings, and simple algorithms (in later labs)
- **Teaching focus**:
  - Code readability over clever one-liners
  - Clear function contracts (parameters and return types)
  - Step-by-step progression of difficulty

## Lab Structure

Each lab lives in its own folder and follows a consistent structure:

- `LAB.md` — Student-facing description of the exercise (in English).
- `solution.c` — Instructor’s reference solution written by the repository author.
- `INSTRUCTOR_NOTES.md` — Teaching notes: learning objectives, common pitfalls, and suggestions for how to present the exercise.

Example layout:

```text
lab01-cash/
  LAB.md
  solution.c
  INSTRUCTOR_NOTES.md

lab03-credit/
  LAB.md
  solution.c
  INSTRUCTOR_NOTES.md

lab04-caesar/
  LAB.md
  solution.c
  INSTRUCTOR_NOTES.md

lab05-tictactoe/
  LAB.md
  INSTRUCTOR_NOTES.md
  (student implementations live in their own repositories)

lab06-final-project/
  LAB.md
  (student projects live in their own repositories: `projeto-final-c`)

## Context

This repository contains a curated set of C programming labs inspired by CS50, adapted for **vocational and practical teaching** contexts.  
The goal is not to copy the original CS50 problem sets, but to **reframe core ideas** (I/O, conditions, loops, functions, types, basic algorithms) into exercises that are explicit, well-structured, and suitable for learners with diverse backgrounds.

All labs are designed to be used **without the CS50 library**, relying only on standard C (`stdio.h`, basic types, arrays, and your own functions).

The focus is on **teaching and learning**, not on “clever” one-off solutions.

---

## Technical Focus

- **Language**: C  

- **Core topics**:
  - Input/output and basic types
  - Conditional logic and loops (`if`, `for`, `while`, `do...while`)
  - Functions and function prototypes (“promises”)
  - Named constants vs magic numbers
  - Arrays (1D and 2D), strings, and simple algorithms
  - Command-line arguments (`argc`, `argv`)
  - Basic algorithmic reasoning (Luhn, Caesar, game logic)

- **Teaching focus**:
  - Code **readability** over clever one-liners
  - Clear **function contracts** (parameters and return types)
  - Step-by-step progression of difficulty
  - Connecting abstract concepts (ASCII, modulo, algorithms) to concrete examples
  - Encouraging **autonomy** and **structured work habits** (Lab 05 and Lab 06)

---

## Lab Structure

Each lab lives in its own folder and follows a consistent structure:

- `LAB.md` — student-facing description of the exercise (in English).
- `solution.c` — instructor’s reference solution written by the repository author.
- `INSTRUCTOR_NOTES.md` — teaching notes: learning objectives, common pitfalls, and suggestions for how to present the exercise.
- Optional extra files, e.g.:
  - `solution_recursive.c` for alternative approaches,
  - additional variants or experiments.

Example layout:

lab01-cash/
  LAB.md
  solution.c
  INSTRUCTOR_NOTES.md

lab02-mario-basic/
  LAB.md
  solution.c
  solution_recursive.c
  INSTRUCTOR_NOTES.md

lab03-credit/
  LAB.md
  solution.c
  INSTRUCTOR_NOTES.md

lab04-caesar/
  LAB.md
  solution.c
  INSTRUCTOR_NOTES.md

lab05-tictactoe/
  LAB.md
  INSTRUCTOR_NOTES.md
  (student implementations live in their own repositories)

lab06-final-project/
  LAB.md
  (student projects live in their own repositories: `projeto-final-c`)

This separation makes it clear what is meant for **students** and what is meant for **instructors**.

---

## Labs Overview

### Lab 01 — Cash (Adapted)

**Inspired by**: CS50 Problem Set 1 — Cash  

**Focus**:

- Function prototypes as **promises**:

    int calculate_quarters(int cents);
  int calculate_dimes(int cents);
  int calculate_nickels(int cents);
  int calculate_pennies(int cents);
  ```

- Choosing appropriate parameter and return **types**.  
- Avoiding magic numbers with **named constants**:

  ```c
  const int QUARTER = 25;
  const int DIME    = 10;
  const int NICKEL  = 5;
  const int PENNY   = 1;
  ```

- Clear and explicit updates rather than compressed expressions:

  ```c
  change = change - quarters * QUARTER;
  ```

**Main idea**: introduce C functions, loops, and simple arithmetic in a realistic way (making change), while building good habits early.

---

### Lab 02 — Mario (Basic Pyramid)

**Inspired by**: CS50 “Mario” (less comfortable)  

**Focus**:

- Input validation with `do ... while`:

  ```c
  do
  {
      printf("Height: ");
      scanf("%d", &n);
  }
  while (n <= 0 || n > 8);
  ```

- Nested `for` loops for **rows and columns**:
  - `i` for rows,
  - `j` for spaces,
  - `k` for `#` blocks.

- Thinking in terms of **patterns** (lines and columns) instead of individual prints.

**Extra**:

- A **recursive version** of `draw` (`solution_recursive.c`) is provided as an optional extension.
- It shows how a pyramid of height `n` can be seen as a pyramid of height `n - 1` plus one more row of `n` blocks.
- This is a natural bridge to later discussions on **recursion vs iteration**.

---

### Lab 03 — Credit (Adapted)

**Inspired by**: CS50 Problem Set 1 — Credit  

**Focus**:

- Breaking a problem into multiple **functions** with clear responsibilities:

  ```c
  long get_number(void);
  int count_digits(long n);
  void fill_array(long n, int size, int array[]);
  int luhn_sum(int size, int array[]);
  void validate_card(int luhnResult, int size, int array[]);
  ```

- Converting a `long` into an **array of digits**.  
- Understanding and implementing the **Luhn algorithm**.  
- Practising integer **division** (`/`) vs **remainder** (`%`) to:
  - extract the last digit,
  - remove the last digit.

**Main idea**: students realise that the hardest part is often not the array itself, but deciding **what each function should do**, and avoiding a `main` that is just a “shopping list” of steps.

---

### Lab 04 — Caesar Cipher (Adapted)

**Inspired by**: CS50 Problem Set 2 — Caesar  

**Focus**:

- Using **command-line arguments**:

  - `argc` (argument count),
  - `argv` (argument vector).

- Validating:

  - the **number** of arguments (`argc == 2`),
  - the **type** of the second argument (only digits).

- Implementing helper functions with clear purposes:

  ```c
  bool only_digits(char *s);
  char rotate(char c, int k);
  ```

- Connecting **ASCII codes** with **modular arithmetic**:

  ```c
  (c - 'A' + k) % 26 + 'A'
  (c - 'a' + k) % 26 + 'a'
  ```

**Main idea**: help students “connect the wires” between characters, numeric codes, and the modulo operator, while adding the new dimension of command-line input.

---

### Lab 05 — Tic-Tac-Toe (Guided Project)

**Type**: guided but more open, project-style lab.

**Focus**:

- **Multidimensional arrays**:

  ```c
  char board[3][3];
  ```

- Passing 2D arrays to functions:

  ```c
  void init_board(char board[3][3]);
  void print_board(char board[3][3]);
  ```

- Input handling with `scanf` and `getchar` for cleaning the buffer.
- A simple **menu** implemented with `switch`.
- Game loop control with `break` and `continue`.
- Winner detection (rows, columns, diagonals) and basic **game logic**.

**Optional challenges**:

- **Player names** using strings and an array of strings:

  ```c
  char players[2][50];
  ```

- A running **scoreboard** using `static` inside a function (state that persists between games).
- Draw detection (`is_draw`) when the board is full and no one has won.

**Pedagogical note**:

This lab is deliberately more **open**. Students are guided by phases, but they are free to:

- stop after a minimal working game, or  
- implement all the challenges and extra features.

In practice, this “structured freedom” tends to increase engagement: many students choose to go further and implement everything when given the opportunity.

---

### Lab 06 — Final Project: C Game + Git Workflow

**Type**: open final project — student-designed game in C, with a focus on process and version control.

**Focus**:

- Designing and implementing a **complete game in C**, chosen by the student.
- Applying concepts from the whole module:
  - functions and modularisation,
  - arrays and strings,
  - control structures (loops, `if`, `switch`),
  - optionally recursion.
- Working with a **disciplined Git/GitHub workflow**:
  - regular, meaningful commits,
  - a session log (`LOG.md`) documenting progress, difficulties, and next steps.

**Typical student repository structure** (`projeto-final-c`):
text
projeto-final-c/
├── main.c
├── game.c
├── game.h
├── README.md   // explains the game, how to compile and run
└── LOG.md      // one entry per work session

**Versioning rules** (part of the evaluation):

- Each work block must have **at least one commit**.
- Commit messages follow the format:

  ```text
  [Sessão X] short description
  ```

- Each commit must:
  - update `LOG.md`,
  - contain code that **compiles** (even if incomplete).

Not acceptable:

- A single “big” commit at the end with the whole project.
- Empty or generic messages like `update` or `fix`.
- A private repository without shared access for the instructor.

**LOG.md structure** (per session):
md
## Sessão X – DD/MM/AAAA
**Features implemented today:**
- ...

**Main difficulty encountered and how I solved it (or did not solve it):**
...

**Next planned step:**
...

**Estimated lines of code written today:**
...
```

**Optional enhancement** — **ncurses** interface:

- By default, games run in the terminal with `printf`.
- Students who want to go further can use the **ncurses** library to create a richer text UI (colors, cursor movement, screen updates without scroll), similar to tools like `vim`, `htop`, or `nano`.
- Example compilation:

  ```bash
  gcc main.c -o game -lncurses
  ```

  (the `-lncurses` flag links the ncurses library).

**Assessment criteria** (typical):

- Game functionality: **40%**
- Code quality and organization: **20%**
- Regular commits (Git discipline): **20%**
- Updated `LOG.md`: **10%**
- ncurses interface (bonus): **+10%**

**Main idea**: this lab is not just “have a game running at the end”. It is about demonstrating a **disciplined development process**:

- clear structure (`main.c`, `game.c`, `game.h`),
- incremental progress with commits,
- reflection on difficulties and next steps in `LOG.md`.

---

## Intended Audience

These materials are intended for:

- Students in vocational / professional training (e.g., programming and IT courses).
- Instructors who want **ready-to-use labs** with:
  - clear objectives,
  - reference solutions,
  - and notes about common student difficulties.

A basic familiarity with using the terminal and compiling C programs is assumed, but the labs are designed to be approachable for beginners.

---

## Constraints and Limitations

- This repository **does not** include original CS50 problem statements or official solutions.  
  It contains independent adaptations inspired by similar learning goals and teaching experience.
- The focus is on **fundamentals and pedagogy**, not on advanced C features:
  - no deep pointer manipulation in the early labs,
  - no dynamic memory or complex data structures at the beginning.
- Error handling (especially for invalid input) is kept at a realistic but accessible level.

---

## Lifecycle Status

- **Status**: In Progress  
  Labs and notes are being added, refined, and extended over time.

---

## Course Scope

This lab sequence (Lab 01 to Lab 06) represents a complete C module as delivered in class:

- Labs 01–04: core C foundations (functions, control flow, arrays, strings, algorithms).
- Lab 05: guided project (Tic-Tac-Toe) consolidating multiple topics.
- Lab 06: open final project with Git/GitHub and a student-designed game.

Students have 15 hours of supervised work time for the final project and are encouraged to continue working outside class if they wish.

At this stage, no additional labs are planned for this repository. Future extensions, if any, will be documented as separate additions.
