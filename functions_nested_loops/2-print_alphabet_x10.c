/**
 * 2-print_alphabet_x10.c - prints the alphabet 10 times in lowercase
 */

#include "main.h"

/**
 * print_alphabet_x10 - prints 10 alphabets
 */
void print_alphabet_x10(void)
{
	int i;
	char c;

	i = 0;
	while (i < 10)
	{
		c = 'a';
		while (c <= 'z')
		{
			_putchar(c);
			c++;
		}
		_putchar('\n');
		i++;
	}
}
