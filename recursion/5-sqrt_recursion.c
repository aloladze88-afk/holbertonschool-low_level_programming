#include "main.h"

/**
 * sqrt_helper - checks possible square roots
 * @n: number
 * @guess: current guess
 *
 * Return: natural square root, or -1 if none exists
 */
int sqrt_helper(int n, int guess)
{
	if (guess > n / guess)
		return (-1);

	if (guess * guess == n)
		return (guess);

	return (sqrt_helper(n, guess + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number
 *
 * Return: natural square root, or -1 if none exists
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);

	if (n == 0)
		return (0);

	return (sqrt_helper(n, 1));
}
