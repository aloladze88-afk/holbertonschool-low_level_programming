#include "lists.h"

/**
 * _strlen - returns the length of a string
 * @str: string to measure
 *
 * Return: length of string
 */
unsigned int _strlen(const char *str)
{
	unsigned int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: pointer to the head of the list
 * @str: string to store in the new node
 *
 * Return: address of the new element, or NULL if it fails
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *new_node;
	unsigned int len, i;

	if (head == NULL || str == NULL)
		return (NULL);

	len = _strlen(str);

	new_node = malloc(sizeof(list_t));
	if (new_node == NULL)
		return (NULL);

	new_node->str = malloc(len + 1);
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}

	for (i = 0; i < len; i++)
		new_node->str[i] = str[i];
	new_node->str[i] = '\0';

	new_node->len = len;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
