#include "shell.h"
/**
 * main - This Function executes the simple shell
 * Description: This funtion executes the simple shell that
 * returns commands request
 *
 */
int main(void)
{
	list_t *head = NULL, *itr = NULL;
        char *b = NULL;
        size_t bufsize;
        int characters;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);

		characters = getline(&b, &bufsize, stdin);
		if (characters == EOF)
		{
			write(STDOUT_FILENO, "EOF\n", 4);
			exit(0);
		}

		head = token(b, characters, head);
		if (!head)
		{
			printf("Failed to create head node\n");
			free(b);
		}
/*		getenviron(b, head);*/
		itr = head;
		while (itr->token != NULL)
		{
			printf("This is token buff %s", itr->token);
			itr = itr->next;
		}
		free(b);
		free_list(head);
	}
        return (0);
}
