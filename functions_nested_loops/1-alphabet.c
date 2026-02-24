/*
 * 1-alphabet.c
 * Prints the lowercase alphabet followed by a newline.
 * _putchar is used exactly twice.
 */
#include "main.h"

void print_alphabet(void)
{
char c;

for (c = 'a'; c <= 'z'; c++)
_putchar(c);

_putchar('\n');
}
