#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TARGET_SUM 2772

/**
 * main - generates a random valid password for 101-crackme
 *
 * Return: 0
 */
int main(void)
{
	int sum = 0;
	char c;

	srand(time(NULL));

	while (sum < TARGET_SUM - 33)
	{
		c = (rand() % (126 - 33 + 1)) + 33;
		putchar(c);
		sum += c;
	}

	putchar(TARGET_SUM - sum);
	putchar('\n');

	return (0);
}
