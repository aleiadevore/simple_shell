#include "shell.h"
/**
 * main - This Function executes the simple shell
 * Description: This funtion executes the simple shell that
 * returns commands request
 *
 */
int main(void)
{
	int i = 0;
	char **tokenbuf = NULL;
	list_t *head = NULL;
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

		tokenbuf = token(b, characters, head);

		while (tokenbuf[i] != NULL)
		{
			printf("This is token buff %s", tokenbuf[i]);
			i++;
		}
		free(tokenbuf);
	}
        return (0);
}
