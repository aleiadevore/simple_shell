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

/**
 * add_node_end - adds node to end of list
 * @head: start of list
 * @str: string
 * Return: pointer to node or NULL
 */

list_t *add_node_end(list_t **head, const char *str)
{
	list_t *lastnode, *last = *head;
	int count;

	lastnode = malloc(sizeof(list_t));
	if (!lastnode)
	{
		free(lastnode);
		return (NULL);
	}
	lastnode->str = strdup(str);
	for (count = 0; str[count] != '\0'; count++)
		;
	lastnode->len = count;
	lastnode->next = NULL;
	if (*head == NULL)
	{
		*head = lastnode;
		return (lastnode);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = lastnode;
	return (lastnode);
}
