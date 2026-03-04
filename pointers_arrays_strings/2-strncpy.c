#include "main.h"

/**
 * _strncpy - copies a string up to n bytes, padding with '\0' if needed
 * @dest: destination buffer
 * @src: source string
 * @n: maximum number of bytes to copy
 *
 * Return: dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	if (n <= 0)
		return (dest);

	/* Copy characters from src to dest, up to n */
	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	/* If src ended early, pad dest with '\0' up to n */
	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}
