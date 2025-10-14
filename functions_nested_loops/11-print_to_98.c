#include "main.h"

/**
 * print_to_98 - Prints all natural numbers from n to 98
 * @n: The starting number
 */
void print_to_98(int n)
{
    int num;

    if (n <= 98)
    {
        for (num = n; num <= 98; num++)
        {
            print_number(num);
            if (num != 98)
            {
                _putchar(',');
                _putchar(' ');
            }
        }
    }
    else
    {
        for (num = n; num >= 98; num--)
        {
            print_number(num);
            if (num != 98)
            {
                _putchar(',');
                _putchar(' ');
            }
        }
    }
    _putchar('\n');
}

/**
 * print_number - Prints an integer using _putchar
 * @n: The number to print
 */
void print_number(int n)
{
    unsigned int num;

    if (n < 0)
    {
        _putchar('-');
        num = -n;
    }
    else
    {
        num = n;
    }

    if (num / 10)
        print_number(num / 10);

    _putchar((num % 10) + '0');
}
