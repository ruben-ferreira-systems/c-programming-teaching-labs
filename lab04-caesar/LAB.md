# Lab 04 — Caesar Cipher

## Overview

In this lab you will implement a **Caesar cipher** in C, using command-line arguments.  
The program will:

- receive a key (a non-negative integer) as a command-line argument,
- read a line of **plaintext** from the user,
- and output the corresponding **ciphertext**, where each letter is shifted by `key` positions in the alphabet.

The focus of this lab is on:

- working with **command-line arguments** (`argc`, `argv`),
- validating the number and type of arguments,
- and understanding how to use **ASCII values and modular arithmetic** to rotate letters.

## Learning Objectives

By the end of this lab, you should be able to:

- Use `argc` and `argv` to read arguments from the command line.
- Validate that exactly one additional argument (the key) is provided.
- Check that a string contains **only digits** before converting it to an integer.
- Implement a Caesar cipher using **ASCII arithmetic** and the modulo operator (`%`).
- Separate your solution into small functions with clear purposes (e.g. `only_digits`, `rotate`).

## Problem Description

Write a program that:

1. Expects exactly **one** command-line argument: the key.
   - If the user does not provide exactly one argument, print:
     ```text
     Usage: ./caesar key
     ```
     and exit with status code `1`.
2. Checks that the key consists only of digits.
   - If it contains any non-digit characters, print:
     ```text
     Usage: ./caesar key
     ```
     and exit with status code `1`.
3. Converts the key from a string to an integer.
4. Prompts the user for a **plaintext** string.
5. Prints the corresponding **ciphertext**, where:
   - uppercase letters (`A`–`Z`) are rotated within `A`–`Z`,
   - lowercase letters (`a`–`z`) are rotated within `a`–`z`,
   - non-alphabetic characters (spaces, punctuation, digits) remain unchanged.

Example (with key = 1):

```text
plaintext: Hello, World!
ciphertext: Ifmmp, Xpsme!# Lab 04 — Caesar Cipher (Adapted)

## Overview

In this lab you will implement a **Caesar cipher** in C, using command-line arguments.  
The program will:

- receive a key (a non-negative integer) as a command-line argument,
- read a line of **plaintext** from the user,
- and output the corresponding **ciphertext**, where each letter is shifted by `key` positions in the alphabet.

The focus of this lab is on:

- working with **command-line arguments** (`argc`, `argv`),
- validating the number and type of arguments,
- and understanding how to use **ASCII values and modular arithmetic** to rotate letters.

## Learning Objectives

By the end of this lab, you should be able to:

- Use `argc` and `argv` to read arguments from the command line.
- Validate that exactly one additional argument (the key) is provided.
- Check that a string contains **only digits** before converting it to an integer.
- Implement a Caesar cipher using **ASCII arithmetic** and the modulo operator (`%`).
- Separate your solution into small functions with clear purposes (e.g. `only_digits`, `rotate`).

## Problem Description

Write a program that:

1. Expects exactly **one** command-line argument: the key.
   - If the user does not provide exactly one argument, print:
     ```text
     Usage: ./caesar key
     ```
     and exit with status code `1`.
2. Checks that the key consists only of digits.
   - If it contains any non-digit characters, print:
     ```text
     Usage: ./caesar key
     ```
     and exit with status code `1`.
3. Converts the key from a string to an integer.
4. Prompts the user for a **plaintext** string.
5. Prints the corresponding **ciphertext**, where:
   - uppercase letters (`A`–`Z`) are rotated within `A`–`Z`,
   - lowercase letters (`a`–`z`) are rotated within `a`–`z`,
   - non-alphabetic characters (spaces, punctuation, digits) remain unchanged.

Example (with key = 1):

plaintext: Hello, World!
ciphertext: Ifmmp, Xpsme!

Required Functions (Promises)
Implement at least the following functions:

bool only_digits(char *s);
char rotate(char c, int k);
only_digits:
Receives a string s.
Returns true if all characters in s are digits, false otherwise.
rotate:
Receives a character c and an integer key k.
If c is an uppercase letter, returns the rotated uppercase letter.
If c is a lowercase letter, returns the rotated lowercase letter.
Otherwise, returns c unchanged.
Command-line Arguments (argc and argv)
Remember:

argc = argument count (how many arguments)
argv = argument vector (array of strings)
Example:

./caesar 13
argc = 2
argv[0] = "./caesar"
argv[1] = "13" (the key as a string)
Your program should:

Check argc:
If argc != 2, print the usage message and exit.
Check argv[1] with only_digits:
If it is not all digits, print the usage message and exit.
ASCII and Rotation Formula
To rotate a letter, we use ASCII codes and modular arithmetic:

For an uppercase letter:

(c - 'A' + k) % 26 + 'A'
This expression works as follows:

c - 'A'
Maps A to 0, B to 1, ..., Z to 25.
+ k
Moves k positions forward.
% 26
Wraps around within the range 0 to 25 (the alphabet size).
+ 'A'
Maps back to the ASCII code of an uppercase letter.
For lowercase letters, it is the same idea, but with 'a':

(c - 'a' + k) % 26 + 'a'
Non-alphabetic characters should be returned unchanged.

Program Structure (Suggested)
In pseudocode:

main:
    if argc != 2:
        print usage and exit
    if only_digits(argv[1]) is false:
        print usage and exit
    key = convert argv[1] to integer
    prompt user for plaintext
    read plaintext (e.g. with fgets)
    for each character in plaintext:
        print rotate(character, key)

Example Runs
Example 1:

$ ./caesar 1
plaintext: Hello, World!
ciphertext: Ifmmp, Xpsme!
Example 2 (non-numeric key):

$ ./caesar abc
Usage: ./caesar key
Example 3 (wrong number of arguments):

$ ./caesar
Usage: ./caesar key

Hints

Use fgets to read a whole line of text from the user.
Use strlen to get the length of the plaintext.
Start by implementing and testing only_digits separately:
Print the result for some test strings (e.g. "123", "12a3").
For rotate, test with:
simple letters (A, Z, a, z),
large keys (e.g. k = 27), to see the % 26 in action.
Optional Extensions
Allow keys larger than 26 (the modulo already supports this).

Print both the ASCII code and the resulting character for a few positions, to make the mapping more explicit.

Add a function that normalizes the key:

int normalize_key(int k) { return k % 26; }
and call rotate with the normalized key.

```text
plaintext: Hello, World!
ciphertext: Ifmmp, Xpsme!
