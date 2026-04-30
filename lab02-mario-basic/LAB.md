# Lab 02 — Mario (Basic Pyramid)

## Overview

In this lab, you will write a C program that prints a simple **left-aligned pyramid** of `#` characters, inspired by the classic "Mario" problem from CS50.  
The focus of this exercise is not on graphics, but on:

- Validating user input with a `do ... while` loop.
- Using **nested loops** to print patterns (rows and columns).
- Understanding how each loop variable controls a different part of the output.

## Learning Objectives

By the end of this lab, you should be able to:

- Use a `do ... while` loop to repeatedly prompt the user until a valid value is entered.
- Write and reason about **nested `for` loops**.
- Separate logic into a function (`draw`) that receives a parameter and produces output.
- Think of the pyramid as a combination of **spaces and blocks** per row.

## Problem Description

Write a program that:

1. Prompts the user for an integer `n` representing the **height** of the pyramid.
2. Accepts only values of `n` between **1 and 8**, inclusive.
3. Prints a left-aligned pyramid of height `n` using the `#` character.

The pyramid should look like this for different values of `n`:

For `n = 1`:
#

For n = 3:

  #
 ##
###
For n = 5:

    #
   ##
  ###
 ####
#####
You must use:

A do ... while loop to get a valid height from the user.
At least one function called draw that receives the height as a parameter.
Function Requirements
Define the following function:

void draw(int n);
The function should draw the entire pyramid.
It should not read input or return a value.
It should be called from main after a valid height has been obtained.
Program Requirements
Input validation with do ... while

Repeatedly ask for the height until the user enters a value between 1 and 8:

do
{
    // ask for input
}
while (/* height is not valid */);
Nested loops

Inside draw, use two nested for loops (inside another for for the rows):

One loop to print spaces before the blocks.
One loop to print the # blocks.
Think in terms of rows and columns:

Outer loop: controls the current row (line).
Inner loops: control the columns (spaces and #).
Clean, readable code

Choose meaningful names for loop variables (i, j, k are fine if you comment them well).
Use indentation to make the structure clear.
Suggested Structure
In pseudocode:

function main:
    repeat:
        ask user for height
    until height is between 1 and 8
    call draw(height)
function draw(n):
    for each row i from 0 to n-1:
        print spaces
        print blocks
        move to next line
        
Example Run

Height: 0
Height: 9
Height: 4

   #
  ##
 ###
####

Hints
  For each row i:
  Number of spaces = n - i - 1
  Number of # = i + 1

  Test your program with all values from 1 to 8 to check alignment.
  Start with a small height (like 2 or 3) and manually trace the loops on paper.

Optional Extensions
  If you finish early:
  Modify the program to print two pyramids side by side (a “gap” in the middle).
  Try to write an alternative version of draw using recursion (advanced, to compare with the iterative version).
