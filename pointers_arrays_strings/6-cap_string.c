#include "main.h"

/**
 * cap_string - Capitalizes all words of a string.
 * @s: Pointer to the string to modify.
 *
 * Return: Pointer to the modified string.
 */
char *cap_string(char *s)
{
	int i, j;
	int cap_next = 1;
	char seps[] = " \t\n,;.!?\"(){}";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; seps[j] != '\0'; j++)
		{
			if (s[i] == seps[j])
			{
				cap_next = 1;
				break;
			}
		}

		if (seps[j] != '\0')
			continue;

		if (cap_next && (s[i] >= 'a' && s[i] <= 'z'))
			s[i] -= ('a' - 'A');

		cap_next = 0;
	}

	return (s);
}
