#include <stdio.h>

/**
 * main - Prints all single digit numbers using printf
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i = 0;

	while (i <= 9)
	{
		printf("%d", i);
		i++;
	}
	printf("\n");

	return (0);
}
