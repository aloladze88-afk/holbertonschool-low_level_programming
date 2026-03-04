#include "main.h"

/**
 * _strcat - concatenates two strings
 * @dest: destination buffer (must be large enough)
 * @src: source string to append
 *
 * Return: pointer to dest
 */
char *_strcat(char *dest, char *src)
{
	int i = 0;
	int j = 0;

	/* Find the end of dest */
	while (dest[i] != '\0')
		i++;

	/* Copy src onto the end of dest */
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	/* Add final null terminator */
	dest[i] = '\0';

	return (dest);
}
