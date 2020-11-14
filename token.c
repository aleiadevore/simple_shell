#include "shell.h"
/**
 * token - tokenizes user input
 * @input: input from terminal
 * @sz_input: size of user input from terminal
 * @head: head node of linked list
 */
extern char **environ;
list_t *token(char *input, size_t sz_input, list_t *head)
{
	char *tokenbuf;

	printf("Entering token function\n");
	tokenbuf = malloc(sizeof(char) * (sz_input));
	if (!tokenbuf)
	{
		printf("Failed to malloc token\n");
		free(input);
		exit(1);
	}

	tokenbuf = strtok(input, " ");
	printf("Tokenbuff: %s\n", tokenbuf);
	add_node_end(&head, input);

	while (tokenbuf != NULL)
	{
		tokenbuf = strtok(NULL, " ");
		printf("%s\n", tokenbuf);
		add_node_end(&head, input);
	}
	printf("Left while loop\n");
	free(tokenbuf);
	return (head);
}
