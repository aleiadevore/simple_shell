#include "shell.h"
/**
 * getenviron - This gets the environment variable from envrion
 * @name: this is the tokenized path
 *
 * Return: is
 */
list_t *getenviron(list_t *head)
{
	while (environ[itr] != NULL)
        {
                if (_strncmp(environ[itr], "PATH", 3) == 0)
                        return (environ[itr]);
                itr++;
        }

	return (head);
}
