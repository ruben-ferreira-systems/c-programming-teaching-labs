# Lab 03 — Credit (Adapted)

## Overview

In this lab, you will implement a credit card validator in C, inspired by the **Credit** problem from CS50.  
The program will:

- ask the user for a credit card number,
- apply the **Luhn algorithm** to check its validity,
- and identify the card type (American Express, MasterCard, or Visa).

The main focus of this lab is not only the algorithm itself, but also:

- how to **decompose the problem into functions** with clear responsibilities,
- how to work with **arrays of digits**,
- and how to use **integer division and remainder** correctly.

## Learning Objectives

By the end of this lab, you should be able to:

- Design and use multiple functions, each with a **clear purpose**.
- Convert a long integer into an **array of digits**.
- Apply the **Luhn algorithm** step by step.
- Use **integer division (`/`)** and **remainder (`%`)** to extract and remove digits.
- Understand the difference between **local variables** and **global variables**, and prefer local variables for clarity.

## Problem Description

Write a program that:

1. Prompts the user for a credit card number (as a `long`).
2. Validates the input:
   - Only accept numeric input.
   - Only accept card numbers with **13, 15, or 16 digits**.
   - Reject 14-digit numbers.
3. Stores each digit of the card number in an array.
4. Applies the **Luhn algorithm** to compute a checksum.
5. If the checksum is valid (ends in 0), determines the card type:
   - **American Express**:
     - 15 digits,
     - starts with `34` or `37`.
   - **MasterCard**:
     - 16 digits,
     - starts with `51`, `52`, `53`, `54`, or `55`.
   - **Visa**:
     - 13 or 16 digits,
     - starts with `4`.
6. Prints the result: `American Express`, `MasterCard`, `Visa`, or `INVALID`.

Your program must **not** use the CS50 library. Work only with:

- `stdio.h`
- basic C types (`int`, `long`, etc.)
- arrays and your own functions.

## Required Functions (Promises)

Implement at least the following functions:

long get_number(void);
int count_digits(long n);
void fill_array(long n, int size, int array[]);
int luhn_sum(int size, int array[]);
void validate_card(int luhnResult, int size, int array[]);

Each function has a clear promise:

get_number
Reads input from the user, validates it, and returns a valid card number.
count_digits
Receives a long and returns how many digits it contains.
fill_array
Receives a number, its size, and an array; fills the array with the digits of the number.
luhn_sum
Receives the size and the digit array; returns the Luhn checksum (sum of processed digits).
validate_card
Receives the Luhn result, the size, and the digit array; prints the card type or INVALID.
The goal is not to write everything in main, but to design each function so that it does one job well.

Working with Digits: Division vs Remainder

To break a number into digits, use:

n % 10 — gives the last digit (remainder of division by 10).
n / 10 — removes the last digit (integer division truncates).

Example:

n = 1234
n % 10 → 4 (last digit)
n / 10 → 123 (remaining digits)
You will use this pattern in a loop to fill the array of digits.

The Luhn Algorithm (Summary)

Starting from the second-to-last digit, moving left:
Multiply every second digit by 2.
If the result is greater than 9, add the digits of the result (e.g., 12 → 1 + 2).
Sum all these processed values.
Then, starting from the last digit, moving left:
Add all the digits that were not multiplied by 2.
Add both sums.
If the total ends in 0 (i.e., total % 10 == 0), the card number is valid by Luhn’s algorithm.

Example Structure (Pseudocode)

    number = get_number()
    size = count_digits(number)
    digits[size]
    fill_array(number, size, digits)
    luhn = luhn_sum(size, digits)
    validate_card(luhn, size, digits)
    
Example Run

Number: 4003600000000014
Number return: 4003600000000014
Size return: 16
Array (digits): 4003600000000014
Luhn value: 70
Visa
Number: 1234567890
Number return: 1234567890
Size return: 10
Array (digits): 1234567890
Luhn value: 67
INVALID
(Exact printed text may vary slightly depending on your formatting.)

Hints

Start by getting the input and making sure count_digits is correct.
Test fill_array separately: print the array to check if the digits are where you expect them.
Implement luhn_sum step by step:
First handle only one of the two loops (e.g., the “doubled” digits),
then add the second loop.
Do not try to write everything at once; respect the promises of each function.
Optional Extensions
Add more card types by checking different starting digits and lengths.
Create a function that simply returns a string (e.g. "VISA" or "INVALID") instead of printing directly.
Refactor your code to separate input, processing, and output even more clearly.
void fill_array(long n, int size, int array[]);
int luhn_sum(int size, int array[]);
void validate_card(int luhnResult, int size, int array[]);
