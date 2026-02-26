#include "main.h"

/**
 * print_diagonal - draws a diagonal line on the terminal
 * @n: number of times the character '\' should be printed
 *
 * Return: void
 */
void print_diagonal(int n)
{
	int row, col;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}

	for (row = 0; row < n; row++)
	{
		for (col = 0; col < row; col++)
			_putchar(' ');

		_putchar('\\');
		_putchar('\n');
	}
}
