#include "main.h"
#include <stdio.h>

/**
 * main - Entry point of the program
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int num = 42;

	printf("Before: %d\n", num);
	reset_to_98(&num);
	printf("After: %d\n", num);

	return (0);
}
