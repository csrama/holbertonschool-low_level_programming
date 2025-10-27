#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to search
 * @accept: string containing acceptable characters
 *
 * Return: number of bytes in initial segment of s
 *         consisting only of bytes from accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int found;
	char *a;

	while (*s != '\0')
	{
		found = 0;
		a = accept;

		/* Check if current character is in accept */
		while (*a != '\0')
		{
			if (*s == *a)
			{
				found = 1;
				break;
			}
			a++;
		}

		/* If character not found in accept, stop counting */
		if (found == 0)
		{
			break;
		}

		count++;
		s++;
	}

	return (count);
}
