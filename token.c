#include "shell.h"
/**
 * token - tokenizes user input
 * @input: input from terminal
 * @head: head node of linked list
 */
extern char **environ;
list_t *token(char *input, size_t sz_input, list_t *head)
{
	char *tokenbuf;
/*remove code sz_input And from prototype we do no need it to malloc anymore*/
	(void)sz_input;

	/*tokenbuf = malloc(sizeof(char) * 40);*/

/*	if (!tokenbuf)
	{
		printf("Failed to malloc token\n");
		free(input);
		exit(1);
	}
*/
	tokenbuf = strtok(input, " ");
	if (!tokenbuf)
	{
		free(input);
		/*free(tokenbuf);*/
		exit(4);
	}
	printf("Tokenbuff: %s\n", tokenbuf);
	add_node_end(&head, tokenbuf);

	while (tokenbuf != NULL)
	{
		print_list(head);
		tokenbuf = strtok(NULL, " ");
		if (!tokenbuf)
			break;
		add_node_end(&head, tokenbuf);
		printf("%s\n", tokenbuf);
	}

	printf("Left while loop\n");
	free(input);

	/*free(tokenbuf);*/
	return (head);
}
