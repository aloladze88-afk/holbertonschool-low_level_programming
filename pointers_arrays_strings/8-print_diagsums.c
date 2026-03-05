#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sums of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix (stored flat in memory)
 * @size: number of rows/cols (matrix is size x size)
 */
void print_diagsums(int *a, int size)
{
	int i;
	long long sum1 = 0;
	long long sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i];
		sum2 += a[i * size + (size - 1 - i)];
	}

	printf("%lld, %lld\n", sum1, sum2);
}
