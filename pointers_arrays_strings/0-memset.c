#include "main.h"

/**
 * _memset - fills the first n bytes of the memory area pointed to by s with b
 * @s: pointer to the memory area to fill
 * @b: byte value to set
 * @n: number of bytes to set
 *
 * Return: s (the original pointer)
 */
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		s[i] = b;

	return (s);
}
