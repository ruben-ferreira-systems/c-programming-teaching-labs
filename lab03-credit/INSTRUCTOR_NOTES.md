# Instructor Notes — Lab 03: Credit

## Purpose of the Lab

This lab is especially useful for:

- Training **problem decomposition** into multiple functions.
- Making students think about what each function **should do** and what it **should not do**.
- Reinforcing the difference between:
  - **local variables** (inside functions),
  - and the temptation to use **global variables**.
- Practising integer **division vs remainder** (`/` vs `%`) in a meaningful context.

The algorithm (Luhn) is important, but the main pedagogical value is in **structuring the solution**.

## Key Concepts to Emphasize

- **Functions as building blocks, not a “shopping list” in `main`**

  - Students often try to write everything in `main` as a sequence of steps.
  - This is a good opportunity to insist on:
    - clear function names,
    - clear input/output (parameters and return values),
    - each function doing **one job**.

- **Local vs global variables**

  - All important data in this lab (number, size, digits array, sums) can be passed as parameters.
  - There is no real need for global variables here.
  - This makes the code easier to test, read, and reason about.

- **Arrays of digits**

  - Converting a number into an array of digits is a reusable technique.
  - It also visualizes the card number as a sequence of values, making the Luhn steps easier to follow.

- **Division vs remainder**

  - `/ 10` → remove the last digit (truncate).
  - `% 10` → get the last digit.
  - Encourage students to trace a small example on paper (e.g. `n = 1234`) and follow the loop.

## Common Difficulties

- **Misunderstanding the role of each function**

  - Some students want `get_number` to also validate the card type.
  - Others want `luhn_sum` to also print the result.
  - Use this to reinforce the idea of **single responsibility**.

- **Indexing errors in the Luhn algorithm**

  - Off-by-one errors when starting from `size - 2` vs `size - 1`.
  - Confusion about “every second digit from the right”.
  - It can help to number the positions on the board and mark which ones are doubled.

- **Reading input and cleaning the buffer**

  - When `scanf` fails, the input buffer needs to be cleared.
  - This is also a good example of how robust input validation can get complicated in C.

## Teaching Suggestions

- Start by explaining the **Luhn algorithm** with a simple example on the board.
- Then, before showing any code, ask:
  - “What are the main steps?”
  - “Which steps could be separate functions?”
- Write the function prototypes as **promises**, for example:

  long get_number(void);
  int count_digits(long n);
  int luhn_sum(int size, int array[]);

  

  long get_number(void);
  int count_digits(long n);and discuss what each one guarantees.

Ask students to implement the functions one by one:

count_digits
fill_array
luhn_sum
validate_card
testing each piece separately.

Possible Variations

For stronger students:

Ask them to return a string from validate_card instead of printing.
Ask them to support more card types or to encapsulate card metadata (prefixes, lengths) in a small structure.
For weaker students:

Provide partial implementations of some functions (e.g. fill_array) and ask them to complete luhn_sum.
Or give them a correct count_digits and focus only on the array + Luhn part.
Reflection
In practice, the hardest part for many students is not the use of arrays, but deciding what each function should do. This lab is a good moment to discuss how to avoid turning main into a “shopping list” of steps, and instead design a small set of functions with clear responsibilities.

It is also a strong exercise to illustrate the difference between local variables (inside functions) and the idea of using global state.
  int luhn_sum(int size, int array[]);
