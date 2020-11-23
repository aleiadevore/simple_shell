#include "shell.h"
/**
 * getenviron - This gets the environment variable from envrion
 * @name: this is the tokenized path
 * @node: Specific node to linked list
 * Return: 1 for success and 0 for failure
 */
int getenviron(char *name, list_t *node)
{
	int itr = 0, j = 0;

	while (environ[itr] != NULL)
	{
		while (1)
		{
			if (name[j] == '\0' && environ[itr][j] == '=')
			{
				node->envpth = &(environ[itr][j + 1]);
				return (1);
			}
			if (name[j] != environ[itr][j])
				break;
			j++;
		}
		itr++;
	}
	return (0);
}
