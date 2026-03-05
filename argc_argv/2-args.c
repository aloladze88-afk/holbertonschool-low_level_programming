#include <stdio.h>
#include "main.h"

/**
 * main - prints all arguments received, one per line
 * @argc: number of arguments
 * @argv: array of argument strings
 *
 * Return: 0 on success
 */
int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
