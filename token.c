#include "shell.h"
/**
 *
 *
 *
 */
extern char **environ;
char *token(char *input, size_t sz_input)
{
	char *tokenbuf, sizeofname;
	int itr = 0;

	tokenbuf = malloc(sizeof(char) * (sz_input));
	if (!tokenbuf)
	{
		free(input);
		exit(1);
	}

	tokenbuf[itr] = strtok(input, " ");

	itr++;
	while (tokenbuf[itr] != NULL)
	{
		tokenbuf[itr] = strtok(NULL, " ");
		printf("%s", tokenbuf[itr]);
		itr++;
	}
	return (tokenbuf);
}
