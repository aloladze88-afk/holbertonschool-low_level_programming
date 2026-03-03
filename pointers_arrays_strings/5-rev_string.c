#include "main.h"

/**
 * rev_string - reverses a string in place
 * @s: pointer to the first character of the string
 */
void rev_string(char *s)
{
	int len = 0;
	int i;
	char tmp;

	if (s == 0)
		return;

	while (s[len] != '\0')
		len++;

	for (i = 0; i < len / 2; i++)
	{
		tmp = s[i];
		s[i] = s[len - 1 - i];
		s[len - 1 - i] = tmp;
	}
}
