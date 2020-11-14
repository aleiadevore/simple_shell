#include "shell.h"
/**
 * getenviron - This gets the environment variable from envrion
 * @name: this is the tokenized path
 *
 * Return: is
 */
char *getenviron(char *name, list_t *head)
{
	char *env, *ptr, *PATH;
	char *name_cpy;
	unsigned int itr = 0, len = 0;

	for(; name[len] != '\0'; len++)
		;
	name_cpy = malloc(sizeof(char) * (len + 1));
	if (!name_cpy)
	{
		free(name_cpy);
		printf("Failed to alloc name copy\n");
		exit(3);
	}
	_strncpy(name_cpy, name, len);
	env = strtok(environ[i], "=");
	while (environ[itr])
	{
		if (_strcmp(env, name_cpy))
		{
			env = strtok(NULL, "\n");
			free(name_cpy);
			return (env);
		}
		++i;
		env = strtok(environ[i], "=");
	}
	free(name_cpy);
	return (NULL);
}
