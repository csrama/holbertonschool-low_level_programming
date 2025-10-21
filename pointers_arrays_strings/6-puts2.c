#include "main.h"

/**
* puts2 - prints every other character of a string
* 
* 
*
* Description: This function prints only the characters
* whose index numbers are even (0, 2, 4, ...).
* 
* 
*
* 
*/
void puts2(char *str)
{
int i = 0;

while (str[i] != '\0')
{
if (i % 2 == 0)
{
_putchar(str[i]);
}
else
{

}
i++;
}
_putchar('\n');
}
