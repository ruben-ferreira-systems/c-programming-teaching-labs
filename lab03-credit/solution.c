#include <stdio.h>

long get_number(void);                    // Promise
int count_digits(long n);                 // Promise
void fill_array(long n, int size, int array[]); // Promise
int luhn_sum(int size, int array[]);      // Promise
void validate_card(int luhnResult, int size, int array[]); // Promise

const int DIV = 10;

int main(void)
{
    long number = get_number();
    printf("Number return: %li\n", number);

    int size = count_digits(number);
    printf("Size return: %i\n", size);

    int digits[size];
    fill_array(number, size, digits);

    printf("Array (digits): ");
    for (int i = 0; i < size; i++)
    {
        printf("%i", digits[i]);
    }
    printf("\n");

    int luhn = luhn_sum(size, digits);
    printf("Luhn value: %i\n", luhn);

    validate_card(luhn, size, digits);
    printf("\n");

    return 0;
}

long get_number(void)
{
    long number;
    int read_ok;
    short digits_count;

    do
    {
        printf("Number: ");
        read_ok = scanf("%li", &number);

        if (read_ok != 1)
        {
            // Clear invalid input from the buffer
            while (getchar() != '\n')
                ;
            digits_count = 0;
        }
        else
        {
            digits_count = count_digits(number);
        }
    }
    while (read_ok != 1 || digits_count < 13 || digits_count > 16 || digits_count == 14);

    return number;
}

int count_digits(long n)
{
    int count = 0;

    if (n == 0)
    {
        return 1;
    }

    while (n > 0)
    {
        n = n / DIV; // integer division (truncate last digit)
        count++;
    }

    return count;
}

void fill_array(long n, int size, int array[])
{
    // Fill array from the last position backwards
    for (int i = size - 1; i >= 0; i--)
    {
        array[i] = n % DIV; // remainder gives the last digit
        n = n / DIV;        // integer division removes the last digit
    }
}

int luhn_sum(int size, int array[])
{
    int sum_doubled = 0;
    int sum_others = 0;

    // Process every second digit from the right (starting from size - 2)
    for (int i = size - 2; i >= 0; i -= 2)
    {
        int aux = array[i] * 2;

        if (aux > 9)
        {
            // Add the digits separately, e.g. 12 -> 1 + 2
            sum_doubled += (aux / DIV) + (aux % DIV);
        }
        else
        {
            sum_doubled += aux;
        }
    }

    // Process the remaining digits (starting from the last)
    for (int i = size - 1; i >= 0; i -= 2)
    {
        sum_others += array[i];
    }

    return sum_doubled + sum_others;
}

void validate_card(int luhnResult, int size, int array[])
{
    if (luhnResult % DIV == 0)
    {
        int first = array[0];
        int second = (size > 1) ? array[1] : -1;

        switch (first)
        {
            case 3:
                // American Express starts with 34 or 37, 15 digits
                if ((second == 4 || second == 7) && size == 15)
                {
                    printf("American Express\n");
                    return;
                }
                break;

            case 4:
                // Visa starts with 4, length 13 or 16
                if (size == 13 || size == 16)
                {
                    printf("Visa\n");
                    return;
                }
                break;

            case 5:
                // MasterCard starts with 51–55, 16 digits
                if (second >= 1 && second <= 5 && size == 16)
                {
                    printf("MasterCard\n");
                    return;
                }
                break;

            default:
                break;
        }

        printf("INVALID\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
