#include "main.h"

/**
 * _atoi - convert a string to an integer
 * @s: string to convert
 *
 * Return: converted integer, or 0 if no digits
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int num = 0;
	int started = 0;

	while (s[i] != '\0')
	{
		if (!started)
		{
			if (s[i] == '-')
				sign = -sign;
			else if (s[i] >= '0' && s[i] <= '9')
				started = 1;
		}

		if (started)
		{
			if (s[i] >= '0' && s[i] <= '9')
				num = num * 10 + (s[i] - '0');
			else
				break;
		}

		i++;
	}

	if (!started)
		return (0);

	return (num * sign);
}
