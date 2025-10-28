#include "main.h"

/**
 * _sqrt_helper - checks natural square root recursively
 * @n: number to find square root
 * @i: current guess
 *
 * Return: square root of n, or -1 if none
 */
int _sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of n
 * @n: number to find square root
 *
 * Return: square root of n, or -1 if none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 0));
}
