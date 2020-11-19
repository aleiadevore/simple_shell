#include "shell.h"
/**
 * getenviron - This gets the environment variable from envrion
 * @name: this is the tokenized path
 * @head: head of linked list
 * Return: is
 */
int getenviron(char *name, list_t *node)
{
	int itr = 0, j = 0;
/*	char *envptr = NULL;*/

	printf("name is %s\n", name);
	while (__environ[itr] != NULL)
	{
		while (1)
		{
			if (name[j] == '\0' && __environ[itr][j] == '=')
			{
/*				envptr = &(__environ[itr][j + 1]);*/
				node->envpth = &(__environ[itr][j + 1]);
				printf("%s\n", node->token);
				return (1);
			}
			if (name[j] != __environ[itr][j])
				break;
			j++;
		}
		itr++;
	}
	return (0);
}

