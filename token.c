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
		/*free(tokenbuf);*/
		exit(4);
	}
	printf("Tokenbuff: %s\n", tokenbuf);
	add_node_end(&head, tokenbuf, NULL);

	while (tokenbuf != NULL)
	{
		print_list(head);
		tokenbuf = strtok(NULL, " ");
		if (!tokenbuf)
			break;
		add_node_end(&head, tokenbuf, NULL);
		printf("%s\n", tokenbuf);
	}

	printf("Left while loop\n");
	free(input);

	/*free(tokenbuf);*/
	return (head);
}
