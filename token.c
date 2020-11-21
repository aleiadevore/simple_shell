#include "shell.h"
/**
 * token - tokenizes user input
 * @input: input from terminal
 * @head: head node of linked list
 * Return: is head
 */
list_t *token(char *input, list_t *head)
{
	char *tokenbuf;

	tokenbuf = strtok(input, " ");
	if (!tokenbuf)
	{
		free(input);
		exit(4);
	}

	add_node_end(&head, tokenbuf, NULL);

	while (tokenbuf != NULL)
	{
		tokenbuf = strtok(NULL, " ");
		if (!tokenbuf)
			break;
		add_node_end(&head, tokenbuf, NULL);
	}

	free(input);
	return (head);
}
