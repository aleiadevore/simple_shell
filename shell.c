#include "shell.h"

/**
 * main - This Function executes the simple shell
 * Description: This funtion executes the simple shell that
 * returns commands request
 * @ac: array of commands
 * @av: command input
 * Return: 0
 */

int main(__attribute__((unused))int ac, char **av)
{
	list_t *head = NULL;
	char *b = NULL, n = '\0';
	size_t bufsize;
	int characters = 0, i = 0, check = 0, comment = 0, lncount = 0;

	signal(SIGINT, ctrl_c);
	while (1)
	{
		++lncount, head = NULL, b = NULL, comment = 0;
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "$ ", 2);
		characters = getline(&b, &bufsize, stdin);
		if (characters == EOF)
		{
			free(b);
			_putchar('\n');
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
			errno = ENOMEM;
			perror("head");
			free(b);
			exit(30);
		}
		if (head->token[0] == '#')
			comment = 1;
		check = envfunction(head);
		checkfunction(head);
		if (check != 1 && comment != 1)
			dirsearch(head, lncount, av[0]);
		free_list(&head);
	}
	return (0);
}
