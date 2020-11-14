#include "shell.h"

/**
 * add_node - adds node at beginning of linked list
 * @head: head node
 * @str: string to copy
 * Return: pointer to new node
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *newnode;

	newnode = malloc(sizeof(list_t));
	if (newnode == NULL)
	{
		free(newnode);
		return (NULL);
	}
	newnode->token = strdup(str);
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

	lastnode = malloc(sizeof(list_t));
	if (!lastnode)
	{
		free(lastnode);
		return (NULL);
	}
	lastnode->token = strdup(str);

	lastnode->next = NULL;
	if (*head == NULL)
	{
		*head = lastnode;
		return (lastnode);
	}
	while (last->next != NULL)
		last = last->next;
	last->next = lastnode;
	lastnode->next = NULL;
	return (lastnode);
}

/**
 * free_list - frees list
 * @head: head of list
 * Return: void
 */

void free_list(list_t *head)
{
	list_t *place;

	while (head != NULL)
	{
		place = head;
		head = head->next;
		free(place->token);
		free(place);
	}
}
