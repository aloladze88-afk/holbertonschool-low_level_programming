#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of integers
 * @min: smallest value
 * @max: largest value
 *
 * Return: pointer to the new array, or NULL
 */
int *array_range(int min, int max)
{
	int *arr;
	unsigned int size;
	unsigned int i;

	if (min > max)
		return (NULL);

	size = max - min + 1;
	arr = malloc(sizeof(int) * size);
	if (arr == NULL)
		return (NULL);

	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}

	return (arr);
}
