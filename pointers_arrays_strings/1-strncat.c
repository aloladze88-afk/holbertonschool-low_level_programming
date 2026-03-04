#include "main.h"

/**
 * _strncat - concatenates two strings, using at most n bytes from src
 * @dest: destination string buffer (must have enough space)
 * @src: source string
 * @n: maximum number of bytes to copy from src
 *
 * Return: pointer to dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int i, j;

	/* Find the end of dest */
	j = 0;
	while (dest[j] != '\0')
		j++;

	/* Append up to n chars from src */
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[j] = src[i];
		j++;
		i++;
	}

	/* Always null-terminate dest */
	dest[j] = '\0';

	return (dest);
}
