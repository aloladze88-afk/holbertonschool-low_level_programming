#include <stdio.h>

/**
 * main - Prints lowercase and uppercase alphabet
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		putchar(c);    /* putchar #1: lowercase */
		c++;
	}

	c = 'A';            /* reset the same variable */

	while (c <= 'Z')
	{
		putchar(c);    /* putchar #2: uppercase */
		c++;
	}

	putchar('\n');      /* putchar #3: newline */

	return (0);
}
