#include <stdio.h>

/**
 * main - Prints all hexadecimal digits (base 16) in lowercase
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;
	char c;

	while (i <= 9)
	{
		putchar(i + '0');
		i++;
	}

	c = 'a';
	while (c <= 'f')
	{
		putchar(c);
		c++;
	}

	putchar('\n');

	return (0);
}
