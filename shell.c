#include "shell.h"
/**
 * main - This Function executes the simple shell
 * Description: This funtion executes the simple shell that
 * returns commands request
 * Return: 0
 */
int main(void)
{
	list_t *head = NULL, *itr = NULL;
	char *b = NULL, n = '\0';
	size_t bufsize;
	int characters = 0, i = 0;

	while (1)
	{
		head = NULL;
		b = NULL;
		itr = NULL;
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);

		characters = getline(&b, &bufsize, stdin);
                if (characters == EOF)
                {
                        write(STDOUT_FILENO, "EOF\n", 4);
                        free(b);
                        exit(0);
                }
		for (i = 0; b[i] != '\0'; i++)
		{
			if (b[i] == '\n' && b[i + 1] == '\0')
				b[i] = n;
			printf("b[i] equals[%c]\n", b[i]);
		}
		head = token(b, head);

		if (!head)
		{
			printf("Failed to create head node\n");
			free(b);
		}
		checkfunction(head);
		dirsearch(head);
		itr = head;
		printf("itr = [%s]", itr->token);
		while (itr != NULL)
		{
			printf("This is token buff [%s]\n", itr->token);
			if (itr->cmdtok != NULL)
				printf("This is parsed PATH [%s]\n", itr->cmdtok);
			itr = itr->next;
		}
		free_list(&head);
 	}
	return (0);
}
