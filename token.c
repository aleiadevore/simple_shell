#include "shell.h"
/**
 *
 *
 *
 */
extern char **environ;
char *token(char *input, size_t sz_input, list_t *head)
{
	char *tokenbuf, sizeofname;
	int itr = 0;

	tokenbuf = malloc(sizeof(char) * (sz_input));
	if (!tokenbuf)
	{
		free(input);
		exit(1);
	}

	tokenbuf = strtok(input, " ");

	add_node_end(&head, input);

	while (tokenbuf != NULL)
	{
		tokenbuf = strtok(NULL, " ");
		printf("%s", tokenbuf);
		add_node_end(&head, input);
	}
	return (head);
}
man 
