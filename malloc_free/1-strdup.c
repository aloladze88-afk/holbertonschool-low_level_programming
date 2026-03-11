#include "main.h"
#include <stdlib.h>

/**
 * _strdup - returns a pointer to a newly allocated space in memory
 * containing a copy of the string given as a parameter
 * @str: string to copy
 *
 * Return: pointer to duplicated string, or NULL if str is NULL
 * or memory allocation fails
 */
char *_strdup(char *str)
{
    int i, len;
    char *copy;

    if (str == NULL)
        return (NULL);

    len = 0;
    while (str[len] != '\0')
        len++;

    copy = malloc(len +1 );
    if (copy == NULL)
        return (NULL);

    i = 0;
    while (i <= len)
    {
        copy[i] = str[i];
        i++;
    }
    return (copy);
}
