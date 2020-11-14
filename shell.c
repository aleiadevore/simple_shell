#include "shell.h"
/**
 *
 *
 *
 */

int main(void)
{
	int i = 0;
	char **tokenbuf = NULL;
        char *b = NULL;
        size_t bufsize;
        size_t characters;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		characters = getline(&b, &bufsize, stdin);

		tokenbuf = NULL;

		tokenbuf = token(b, characters);

		while (tokenbuf[i] != NULL)
		{
			printf("This is token buff %s", tokenbuf[i]);
			i++;
		}
		free(tokenbuf);
	}
        return (0);
}
