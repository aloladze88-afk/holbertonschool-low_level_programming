#include "function_pointers.h"

/**
 * print_name - prints a name using a function pointer
 * @name: the name to print
 * @f: function used to print the name
 * 
 * Return: nothing
 */
void print_name(char *name, void (*f)(char *))
{
    if (name == 0 || f == 0)
    return;

    f(name);
    
}