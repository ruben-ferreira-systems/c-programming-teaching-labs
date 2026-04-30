# cs50-c-labs-adapted

## Context

This repository contains a curated set of C programming labs inspired by CS50, adapted for **vocational and practical teaching** contexts.  
The goal is not to copy the original CS50 problem sets, but to **reframe core ideas** (I/O, conditions, loops, functions, types, basic algorithms) into exercises that are explicit, well-structured, and suitable for learners with diverse backgrounds.

All labs are designed to be used **without the CS50 library**, relying only on standard C (`stdio.h`, basic types, and your own functions).

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

lab02-.../
  LAB.md
  solution.c
  INSTRUCTOR_NOTES.md
