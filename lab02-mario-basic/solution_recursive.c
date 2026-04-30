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
    // Base case: a pyramid of height 0 has nothing to draw
    if (n == 0)
    {
        return;
    }

    // Recursive case:
    // A pyramid of height n is:
    // - a pyramid of height n - 1
    // - plus one row of n blocks

    // 1. Draw the smaller pyramid of height n - 1
    draw(n - 1);

    // 2. Draw the current row with n blocks
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }

    printf("\n");
}
