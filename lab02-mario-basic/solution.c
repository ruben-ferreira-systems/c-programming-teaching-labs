#include <stdio.h>

void draw(int n);

int main(void)
{
    int n;

    // Ask the user for the height of the pyramid (between 1 and 8)
    do
    {
        printf("Height: ");
        scanf("%d", &n);
    }
    while (n <= 0 || n > 8);

    draw(n);

    return 0;
}

void draw(int n)
{
    // Outer loop: controls the number of rows
    for (int i = 0; i < n; i++)
    {
        // First inner loop: print leading spaces
        for (int j = 0; j < n - i - 1; j++)
        {
            printf(" ");
        }

        // Second inner loop: print the blocks ('#')
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        printf("\n");
    }
}
