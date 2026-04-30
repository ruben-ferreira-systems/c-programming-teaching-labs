# Lab 01 — Cash (Adapted)

## Overview

This lab is an adaptation of the CS50 Problem Set 1 **Cash**, but implemented **without the CS50 library** and with a focus on **function design**, **types**, and **readability**.

You will write a C program that calculates how many coins are needed to give a certain amount of change, using the **fewest coins possible**.  
The program will use separate functions for each coin type and named constants instead of magic numbers.

## Learning Objectives

By the end of this lab, you should be able to:

- Declare and use **function prototypes** (function “promises”) in C.
- Choose appropriate **parameter types** and **return types**.
- Replace “magic numbers” with **named constants**.
- Write **clear and readable** C code, even if it is not the shortest possible.

## Problem Description

Write a program that:

1. Prompts the user for a **non-negative** amount of change, in **cents** (integer).
2. Calculates how many:
   - quarters (25¢)
   - dimes (10¢)
   - nickels (5¢)
   - pennies (1¢)
   are needed to make that amount, using the smallest number of coins.
3. Prints how many coins of each type will be used.

Your program must **not** use the CS50 library. You should work only with:

- `stdio.h`
- basic C types (`int`, etc.)
- your own functions.

## Functions (Promises)

You must implement four functions, one for each coin type:

```c
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

Each function:

Receives an integer cents (the remaining change).
Returns how many coins of that type should be used.
These function prototypes are promises:

“If you give me an int (cents), I will return an int (number of coins).”

They must be declared before main, and the function bodies should be defined after main.

Requirements
Input validation

If the user enters a negative number, ask again until a non-negative value is provided.
Use a do ... while loop to repeat the prompt when needed.
Named constants

Do not use raw numbers like 25, 10, 5, 1 directly in the logic.

Define constants at the top of your file, for example:

const int QUARTER = 25;
const int DIME    = 10;
const int NICKEL  = 5;
const int PENNY   = 1;
Explicit, readable updates

When you update the remaining change, prefer a clear, explicit style:

change = change - quarters * QUARTER;
Avoid overly compact code if it makes the logic harder to read.

Single responsibility for functions

The helper functions (calculate_quarters, etc.) must not read input or print output.
They should only calculate and return the number of coins of that type.
Example Run
Enter the change (in cents): -5
Enter the change (in cents): 87
Quarters: 3
Dimes: 1
Nickels: 0
Pennies: 2
(3 × 25 = 75, 1 × 10 = 10, 0 × 5 = 0, 2 × 1 = 2 → total 87.)

Hints
Start by implementing and testing only one function, for quarters.
Once it works correctly, copy the same pattern for dimes, nickels, and pennies.
Use a while loop inside each function:
While the remaining cents is greater than or equal to the coin value:
increment the coin count
subtract the coin value from the remaining cents.
Optional Extensions
If you finish early:

Add a final line that prints the total number of coins used.
Experiment with different input values and check if the greedy approach always uses the smallest number of coins with this coin system.
Add a second version of the program that uses a single function to handle all coins (more advanced).
