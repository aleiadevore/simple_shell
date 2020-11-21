#include "shell.h"

/**
 * main - This Function executes the simple shell
 * Description: This funtion executes the simple shell that
 * returns commands request
 * Return: 0
 */
int main(void)
{
	list_t *head = NULL;
	char *b = NULL, n = '\0';
	size_t bufsize;
	int characters = 0, i = 0, bool = 0;

	while (1)
	{
		head = NULL;
		b = NULL;
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
		}
		head = token(b, head);

		if (!head)
		{
			perror("Failed to create head node\n");
			free(b);
		}
		bool = envfunction(head);
		/*bool = checkfunction(head);*/
		if (bool != 1)
			dirsearch(head);
		free_list(&head);
	}
	return (0);
}
