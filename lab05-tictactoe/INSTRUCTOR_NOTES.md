# Instructor Notes — Lab 05: Tic-Tac-Toe (Guided Project)

## Pedagogical Purpose

This lab is designed as a **guided project** with a deliberately open structure.

The goals are:

- To consolidate several C topics in a single, coherent project:
  - multidimensional arrays,
  - functions with array parameters,
  - input handling (`scanf`, `getchar`),
  - `switch`, `break`, `continue`,
  - simple game logic (winner/draw detection),
  - and, in the challenges, strings and `static`.
- To give students **freedom to explore**:
  - they can stop after the core game,
  - or continue with optional challenges (names, scores, draw detection, etc.).

In practice, this lab is also a test of **autonomy** and **intrinsic motivation**.

## Observations from the Classroom

> In this lab, students were given a lot of freedom. The core specification is relatively open, and the challenges are optional. The reaction was very positive: several students used this freedom to implement **all** the challenges and extra features.
>
> The lab works well as a “reward” project: once they realise that they can choose how far to go, many of them decide to go further than expected.

Key points:

- Some students focused on the **minimum functional game**.
- Others implemented:
  - player names,
  - a running scoreboard with `static`,
  - draw detection,
  - and even additional features not specified (custom board size, etc.).
- The open design seems to **increase engagement**, especially for students who enjoy ownership of their work.

## Common Technical Difficulties

- **Indexing the board correctly**

  - Students may confuse row/column order (`board[row][col]`) or use `1`–`3` instead of `0`–`2`.
  - It helps to draw the board on the whiteboard and map positions explicitly.

- **`scanf` + `getchar` interaction**

  - Forgetting to clear the buffer can lead to “stuck” input or skipped prompts.
  - Revisit the idea that `scanf("%d", ...)` leaves a `'\n'` in the buffer, and `getchar()` consumes it.

- **Missing `break` in `switch`**

  - Classic error: options “fall through”.
  - Having at least one example where this happens makes the concept very concrete.

- **Game loop conditions**

  - Deciding when to `break` (winner or draw) and when to `continue` (invalid move) can be confusing.
  - Encourage students to write the loop logic in plain language first.

## Suggested Teaching Strategy

1. **Start from the board**

   - Make sure everyone understands `char board[3][3]` and `board[i][j]`.
   - Have them complete `init_board` and `print_board` before talking about the game loop.

2. **Introduce the loop only when the board is visible**

   - Once they see the board printed, the idea of “one move → reprint board” becomes natural.

3. **Delay the menu and challenges**

   - First: single game, no menu, no names, no scores.
   - Then: add menu and **optionally** the extra features.

4. **Encourage exploration**

   - Make it explicit that:
     - there is a minimum core for passing,
     - but the challenges are a chance to “show off” and try new ideas.
   - This lab can be a good moment to let stronger students go deeper without penalising others.

## Possible Variations

- For stronger students:
  - Allow arbitrary board sizes (e.g. 4×4, 5×5) and generalise the winner check.
  - Ask them to separate the game logic into a separate module (different `.c` file).

- For weaker students:
  - Provide a working `init_board` and `print_board`, and focus only on reading moves and updating the board.
  - Or provide a partial implementation of `check_winner` and ask them to complete only rows or columns.

## Reflection

> This lab is a good example of how **structured freedom** can increase engagement. The specification defines clear phases and core requirements, but leaves space for students to choose how far they want to go. Some will implement only the essentials; others will tackle every challenge. Both outcomes are acceptable, and the lab still achieves its pedagogical goals in each case.
