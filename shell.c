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
        int characters = 0;

	while (1)
	{
		head = NULL;
		b = NULL;
	       	/*handels the ctrl - d option*/
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);

		characters = getline(&b, &bufsize, stdin);

		b = strtok(b, "\n");

		if (characters == EOF)
		{
			write(STDOUT_FILENO, "EOF\n", 4);
			free(b);
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
		printf("itr = [%s]", itr->token);
		while (itr != NULL)
		{

			printf("This is token buff %s\n", itr->token);
			itr = itr->next;
		}
		free_list(&head);
	}
        return (0);
}
