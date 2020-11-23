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
		free_list(head);
		return (NULL);
	}
	newnode->token = _strdup(str);
	newnode->next = *head;
	*head = newnode;

	return (*head);
}

/**
 * add_node_end - adds node to end of list
 * @head: start of list
 * @str: string
 * @cmd: command to duplicate
 * Return: pointer to node or NULL
 */

list_t *add_node_end(list_t **head, const char *str, const char *cmd)
{
	list_t *lastnode, *last = *head;

	lastnode = malloc(sizeof(list_t));
	if (!lastnode)
	{
		free(lastnode);
		return (NULL);
	}
	lastnode->token = _strdup(str);
	lastnode->cmdtok = _strdup(cmd);
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

void free_list(list_t **head)
{
	list_t *tmp;

	if (head != NULL)
	{
		while (*head != NULL)
		{
			tmp = *head;
			*head = (*head)->next;
			if (tmp->token != NULL)
				free(tmp->token);
			if (tmp->cmdtok != NULL)
				free(tmp->cmdtok);
			free(tmp);
		}
		*head = NULL;
	}
}
