#include "shell.h"
/**
 * getenviron - This gets the environment variable from envrion
 * @name: this is the tokenized path
 *
 * Return: is
 */
list_t *getenviron(char *name, list_t *head)
{
	int itr = 0, j = 0;
	char *envptr = NULL;

	while (__environ[itr] != NULL)
	{
		while(1)
		{
			if (name[j] == '\0' && __environ[itr][j] == '=')
			{
				envptr = &(__environ[itr][j + 1]);
				add_node_end(&head, envptr);
				printf("%s\n", envptr);
				return (head);
			}
			if (name[j] != __environ[itr][j])
				break;
			j++;
		}
                itr++;
	}
		return (NULL);
}
