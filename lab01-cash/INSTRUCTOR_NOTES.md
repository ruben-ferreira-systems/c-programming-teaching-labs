# Instructor Notes — Lab 01: Cash (Adapted)

## Purpose of the Lab

This lab is an adaptation of CS50 Problem Set 1 **Cash**, but:

- Implemented **without the CS50 library**.
- Focused on:
  - Function prototypes as **promises**.
  - Correct use of **parameter** and **return** types.
  - Avoiding **magic numbers** with named constants.
  - Writing **clear and explicit** code instead of clever one-liners.

The algorithm itself (greedy change) is simple and secondary. The main goal is **software engineering basics in C**.

## Common Difficulties

- **Using magic numbers**
  - Students often write:
    ```c
    while (cents >= 25)
    ```
    instead of:
    ```c
    while (cents >= QUARTER)
    ```
  - This is a good moment to talk about:
    - “What happens if the coin values change?”
    - “What does 25 mean here if you read the code in 6 months?”

- **Mixing input/output with logic**
  - Students may try to:
    - Read input inside `calculate_quarters`.
    - Print inside helper functions.
  - Insist on **single responsibility**:
    - Functions calculate and return values.
    - `main` coordinates input and output.

- **Incorrect variable updates**
  - Typical bugs (good for discussion):
    - Incrementing the wrong variable.
    - Subtracting from the counter instead of from the remaining cents.
  - It can be useful to show a buggy version and walk through it step by step.

- **Not understanding prototypes**
  - Some students see prototypes as “extra work”.
  - Explain that the compiler needs to know:
    - the **name**,
    - the **parameter types**,
    - and the **return type**
    before the function is used.

## Teaching Suggestions

- Start from the **problem in natural language**:
  - “We need to give change with the fewest coins.”
  - “First we try the largest coin (25), then the next one (10), etc.”

- Introduce the idea of **promises**:
  - Write on the board:
    ```c
    int calculate_quarters(int cents);
    ```
  - Ask students:
    - “What does this function need?”
    - “What does it give back?”
    - “What would be an invalid use of this function?”

- Emphasize **readability**:
  - Compare:
    ```c
    change -= quarters * QUARTER;
    ```
    with:
    ```c
    change = change - quarters * QUARTER;
    ```
  - For beginners, the second form is often easier to read and debug.
  - Tell them it’s okay to prefer **explicit code** while learning.

## Possible Variations

- For stronger students:
  - Ask them to compute and print the **total number of coins**.
  - Ask them to implement a generic function that receives a coin value and computes how many of that coin to use.

- For weaker students:
  - Provide the constants and prototypes already written.
  - Ask them to complete only one function (e.g., `calculate_quarters`).
  - Or give them a partially completed solution and ask them to fix specific bugs.

## Links to CS50 Context (Optional)

- If students know CS50:
  - Explain that this lab mirrors Problem Set 1 **Cash**.
  - Emphasize the difference:
    - No CS50 library.
    - More emphasis on function design and readability.
