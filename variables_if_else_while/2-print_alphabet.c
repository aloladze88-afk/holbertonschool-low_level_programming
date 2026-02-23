#include <stdio.h>

/**
 * main - Prints the lowercase alphabet followed by a newline
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c = 'a';

	while (c <= 'z')
	{
		putchar(c);    /* putchar #1: runs 26 times */
		c++;
	}
	putchar('\n');      /* putchar #2: runs once */

	return (0);
}
