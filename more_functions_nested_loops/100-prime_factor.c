#include <stdio.h>
#include <math.h>

/**
 * main - finds and prints the largest prime factor of 612852475143
 *
 * Return: Always 0
 */
int main(void)
{
	long num = 612852475143;
	long largest = -1;
	long i;

	/* Divide out all factors of 2 */
	while (num % 2 == 0)
	{
		largest = 2;
		num = num / 2;
	}

	/* Check odd factors from 3 upwards */
	for (i = 3; i <= sqrt(num); i += 2)
	{
		while (num % i == 0)
		{
			largest = i;
			num = num / i;
		}
	}

	/* If what remains is greater than 2, it's prime */
	if (num > 2)
		largest = num;

	printf("%ld\n", largest);

	return (0);
}
