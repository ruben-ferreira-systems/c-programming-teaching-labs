## Teaching Context

These labs were developed and used in a vocational training environment (IEFP), where students often have:
- no prior programming experience
- diverse technical backgrounds
- limited exposure to structured problem-solving

The material was adapted to prioritise clarity, repetition, and incremental difficulty.

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
