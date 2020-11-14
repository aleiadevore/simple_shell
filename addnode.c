#include "lists.h"

/**
 * add_node - adds node
 * @head: head node
 * @str: string to copy
 * Return: pointer to new node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *newnode;
	int count;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->str = strdup(str);
	for (count = 0; str[count] != '\0'; count++)
		;
	newnode->len = count;
	newnode->next = *head;
	*head = newnode;
	return (*head);
}
