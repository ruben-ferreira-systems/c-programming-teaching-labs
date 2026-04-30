#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

bool only_digits(char *s);
char rotate(char c, int k);

int main(int argc, char *argv[])
{
    // Check number of command-line arguments
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Check that the key contains only digits
    if (!only_digits(argv[1]))
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert key from string to integer
    int k = atoi(argv[1]);

    char plaintext[100];

    printf("plaintext: ");
    // Read one line of input (up to 99 characters + '\n')
    fgets(plaintext, sizeof(plaintext), stdin);

    printf("ciphertext: ");

    int n = strlen(plaintext);

    for (size_t i = 0; i < (size_t)n; i++)
    {
        printf("%c", rotate(plaintext[i], k));
    }

    printf("\n");

    return 0;
}

bool only_digits(char *s)
{
    // Check that every character in s is a digit
    for (size_t i = 0; s[i] != '\0'; i++)
    {
        if (!isdigit((unsigned char)s[i]))
        {
            return false;
        }
    }

    return true;
}

char rotate(char c, int k)
{
    // Uppercase letters
    if (isupper((unsigned char)c))
    {
        // Map 'A'..'Z' to 0..25, rotate, then map back
        return (char)((c - 'A' + k) % 26 + 'A');
    }
    // Lowercase letters
    else if (islower((unsigned char)c))
    {
        // Map 'a'..'z' to 0..25, rotate, then map back
        return (char)((c - 'a' + k) % 26 + 'a');
    }

    // Non-alphabetical characters are not changed
    return c;
}
