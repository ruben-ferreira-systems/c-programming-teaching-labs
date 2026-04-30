# Instructor Notes — Lab 04: Caesar (Adapted)

## Purpose of the Lab

This lab is especially valuable for:

- Introducing **command-line arguments** (`argc`, `argv`).
- Showing that a program can receive **more than one argument**.
- Practising **input validation** at the command-line level (number and type of arguments).
- Making the connection between:
  - ASCII codes,
  - modular arithmetic (`%`),
  - and character manipulation.

## Key Concepts to Emphasize

- **Two levels of input**:

  1. Command-line argument: the key (`argv[1]`).
  2. Standard input: the plaintext (with `fgets`).

  Many students confuse these, so it is important to clearly separate:
  - “First we validate the key (before the program really starts).”
  - “Then we ask the user for the text to encrypt.”

- **`argc` and `argv` mental model**:

  - `argc` = how many strings.
  - `argv` = array of those strings.
  - On the board, draw something like:

    ```text
    argv[0] --> "./caesar"
    argv[1] --> "13"
    ```

- **`only_digits` as a gatekeeper**:

  - This is a good example of a helper function with a very clear responsibility:
    - it does not print,
    - it does not convert,
    - it only answers: “Is this string all digits?”

- **ASCII and `(c - 'A' + k) % 26 + 'A'`**

  - This is the “big idea” of the lab.
  - Many students do not spontaneously connect this to ASCII.
  - It helps to show a small table:

    | char | ASCII | `c - 'A'` |
    |------|-------|-----------|
    | A    | 65    | 0         |
    | B    | 66    | 1         |
    | C    | 67    | 2         |

  - Then show how `% 26` keeps values between 0 and 25.

## Common Difficulties

- **Understanding the argument count check**

  - Students may not understand why `argc != 2` is an error.
  - You can show different invocations:
    - `./caesar`
    - `./caesar 13`
    - `./caesar 13 extra`

- **Order of validation**

  - It is important to:
    1. Check the number of arguments.
    2. Then check if `argv[1]` is all digits (with `only_digits`).
  - This is a good moment to talk about *defensive programming*.

- **ASCII vs characters**

  - Students may see `'A'` as just a letter, not as a number.
  - It can help to print some values with `%d`:
    - `printf("%d\n", 'A');`

- **Misusing the key**

  - Some students forget to use `% 26`, so large keys break the logic.
  - Others try to apply the key directly to the ASCII code without normalizing.

## Teaching Suggestions

- Start with a **simple Caesar example** on the board:
  - `ABC` with key 1 → `BCD`
  - `XYZ` with key 1 → `YZA`
- Then write the expression:
- and explain each part slowly.

Ask students to implement only_digits first:

This function is small and builds confidence.
Only then move to rotate.

Regarding types (size_t vs int):

You can mention that size_t is the “correct” type for sizes and indices,
but using int is acceptable at this level; do not let this become a distraction.

Reflection
In practice, the hardest part here is not the loop or the fgets, but helping students understand how:

characters are stored as numbers (ASCII),
and how a simple arithmetic expression can map letters to positions in the alphabet and back.
Another important teaching point is that functions like only_digits and rotate make the code more readable and testable, instead of putting everything in main.

Possible Variations
For stronger students:

Ask them to support negative keys or to implement a decoding mode.
Ask them to move the Caesar logic into a separate file and use a header file.

For weaker students:

Provide the skeleton of rotate and let them fill only the uppercase case.
Or provide a fully working Caesar and ask them to implement only only_digits.

  ```c
  (c - 'A' + k) % 26 + 'A'
