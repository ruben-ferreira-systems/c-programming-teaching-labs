# Instructor Notes — Lab 02: Mario (Basic Pyramid)

## Purpose of the Lab

This lab is mainly about:

- Using `do ... while` for **input validation**.
- Understanding and controlling **nested loops**.
- Thinking in terms of **rows and columns** when printing patterns.
- Preparing students for later discussions about **recursion vs. iterative solutions**.

While the problem is visually simple, it is rich in opportunities to train structured thinking.

## Key Concepts to Emphasize

- **`do ... while` as a “menu loop”**

  - The program *insists* on a valid height.
  - This pattern will appear in many real programs:
    - menu choices,
    - repeated prompts,
    - simple validation loops.

- **Three loop variables with different roles**

  - `i` → row index (which line are we printing?)
  - `j` → spaces before the blocks
  - `k` → `#` blocks
  - It is useful to draw a small table on the board:

    | row (`i`) | spaces (`j`) | hashes (`k`) |
    |-----------|--------------|--------------|
    | 0         | n - 1        | 1            |
    | 1         | n - 2        | 2            |
    | ...       | ...          | ...          |

- **Pattern printing as a general skill**

  - Once students see this pattern, they can reuse it for:
    - triangles,
    - grids,
    - simple text-based UIs.

## Common Difficulties

- **Off-by-one errors**

  - Students often confuse `<` vs `<=` in the loop conditions.
  - Encourage them to test with small heights (e.g., 1, 2, 3).

- **Mixing spaces and blocks logic**

  - Some students try to print spaces and `#` in the same loop and get confused.
  - Suggest using **two separate inner loops** to keep responsibilities clear.

- **Input validation mistakes**

  - Students may write:
    - `while (n < 0 && n > 8)` instead of `while (n <= 0 || n > 8)`.
  - This is a good opportunity to revisit logical operators.

## Teaching Suggestions

- Start by **drawing the pyramid on the board** for a small height (e.g., 4).
- Ask students:
  - “What changes from line to line?”
  - “How many spaces do we have in the first line? And hashes?”
- Then build the **row formula**:
  - spaces = `n - i - 1`
  - hashes = `i + 1`

- Show the structure of **loops inside loops**:
  - outer `for` for rows,
  - first inner `for` for spaces,
  - second inner `for` for hashes.

## Connection to Recursion (Advanced)

- Once students are comfortable with the iterative solution, you can:
  - Introduce a recursive version of `draw` that:
    - draws all previous rows,
    - then draws the current row.
  - Compare:
    - how the iterative version uses loop counters,
    - how the recursive version uses the call stack.

This lab can serve as a reference point later when discussing **iterative vs. recursive** approaches.

## Possible Variations

- For stronger students:
  - Extend the pyramid to have **two sides** (like the full Mario problem).
  - Allow the user to choose the character used for the blocks.

- For weaker students:
  - Provide a partially completed `draw` function and ask them to fill only one of the inner loops.
  - Or give them a working version for a fixed height and ask them to generalize to variable `n`.
