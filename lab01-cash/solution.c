#include <stdio.h>

// Coin values in cents
const int QUARTER = 25;
const int DIME    = 10;
const int NICKEL  = 5;
const int PENNY   = 1;

// Function "promises" (prototypes)
// Each function receives an amount in cents and returns
// how many coins of that type should be used.
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    int change;

    // Ensure non-negative input
    do
    {
        printf("Enter the change (in cents): ");
        scanf("%d", &change);
    }
    while (change < 0);

    // 1. Calculate quarters
    int quarters = calculate_quarters(change);
    printf("Quarters: %d\n", quarters);
    change = change - quarters * QUARTER;

    // 2. Calculate dimes
    int dimes = calculate_dimes(change);
    printf("Dimes: %d\n", dimes);
    change = change - dimes * DIME;

    // 3. Calculate nickels
    int nickels = calculate_nickels(change);
    printf("Nickels: %d\n", nickels);
    change = change - nickels * NICKEL;

    // 4. Calculate pennies
    int pennies = calculate_pennies(change);
    printf("Pennies: %d\n", pennies);
    change = change - pennies * PENNY;

    return 0;
}

int calculate_quarters(int cents)
{
    int count = 0;
    while (cents >= QUARTER)
    {
        count++;
        cents = cents - QUARTER;
    }
    return count;
}

int calculate_dimes(int cents)
{
    int count = 0;
    while (cents >= DIME)
    {
        count++;
        cents = cents - DIME;
    }
    return count;
}

int calculate_nickels(int cents)
{
    int count = 0;
    while (cents >= NICKEL)
    {
        count++;
        cents = cents - NICKEL;
    }
    return count;
}

int calculate_pennies(int cents)
{
    int count = 0;
    while (cents >= PENNY)
    {
        count++;
        cents = cents - PENNY;
    }
    return count;
}
