#include "shell.h"
/**
 * getenviron - This gets the environment variable from envrion
 * @name: this is the tokenized path
 *
 * Return: is
 */
char *getenviron(char *name)
{
	char *env;
	char *name_cpy;
	unsigned int itr = 0, len = 0;

	for(; name[len] != '\0'; len++)
		;
	name_cpy = (char *)malloc((sizeof(char) * len) + 1);
	if (!name_cpy)
		return (NULL);
	_strncpy(name_cpy, name, len);
	env_val = strtok(environ[i], "=");
	while (environ[itr])
	{
		if (_strcmp(env_val, name_cpy))
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
