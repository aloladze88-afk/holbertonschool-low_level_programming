#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings
 * @s1: the first string
 * @s2: the second string
 *
 * Return: pointer to the concatenated string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *concat;
	unsigned int len1;
	unsigned int len2;
	unsigned int i;
	unsigned int j;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	len1 = 0;
	while (s1[len1])
		len1++;

	len2 = 0;
	while (s2[len2])
		len2++;

	concat = malloc(len1 + len2 + 1);
	if (concat == NULL)
		return (NULL);

	i = 0;
	while (i < len1)
	{
		concat[i] = s1[i];
		i++;
	}

	j = 0;
	while (j < len2)
	{
		concat[i + j] = s2[j];
		j++;
	}

	concat[i + j] = '\0';
	return (concat);
}
