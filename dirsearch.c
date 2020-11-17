#include "shell.h"
/**
 * dirsearch - This function looks for a alias match along the PATH
 * @head: this is the linked list reference
 * Return: is a char pointer
 * Description: This looks throught the directories
 */
char *dirsearch(list_t *head)
{
	list_t *node = NULL;
	struct dirent *nav;
        DIR *dir;
        char *directory = NULL;

	printf("entered Dirserch function\n");
	node = tok_path(head);
	while (node != NULL)
	{
		directory = node->cmdtok;
		if (directory != NULL)
		{
			printf("node->cmdtok = [%s]\n", directory);
			dir = opendir(directory);
			if (dir == NULL)
			{
				printf("directory not found\n");
				return (NULL);
			}
			printf("directory not null");
			while ((nav = readdir(dir)) != NULL)
			{
				if ((_strcmp(nav->d_name, ".")) == 0 ||
				    (_strcmp(nav->d_name, "..")) == 0)
				{
					printf("____\nfound a match!\n____\n");
					continue;
				}
				if (_strcmp(node->token, nav->d_name) == 0)
				{
					printf("Returning slash\n");
					return (_strcat(directory, "/"));
				}
			}
			closedir(dir);
		}
		node = node->next;
	}
	return (NULL);
}
/**
 * tok_path - This tokenizes the PATH by ":"
 * @head: a refernce to he linked list which contians path and input
 *
 * Return: head
 */
list_t *tok_path(list_t *head)
{
	list_t *node = head;
	char *tokenbuf = NULL, *ptrpath = NULL;
	printf("made it into tokpath\n");
	for (;node != NULL; node = node->next)
		;
	ptrpath = parsedenv();
	tokenbuf = strtok(ptrpath, ":");
	if(!tokenbuf)
	{
		printf("tokenbuf failed, [%s]\n", tokenbuf);
		exit(5);
	}
	add_node_end(&head, tokenbuf);
	printf("before whileloop\n");
	while (tokenbuf != NULL)
	{
		tokenbuf = strtok(NULL, ":");
		printf("This is in tok_path %s\n", tokenbuf);
		if (!tokenbuf)
			break;
		add_node_end(&head, tokenbuf);
	}
	return (head);
}
/**
 * getenviron - This gets the environment variable from envrion
 * @name: this is the tokenized path
 * @head: head of linked list
 * Return: is
 */
char *parsedenv(void)
{
	int itr = 0, j = 0;
	char *name = "PATH", *ptrpath = NULL;
/*      char *envptr = NULL;*/

	printf("name is %s\n", name);
	while (__environ[itr] != NULL)
	{
		while (1)
		{
			if (name[j] == '\0' && __environ[itr][j] == '=')
			{
/*                              envptr = &(__environ[itr][j + 1]);*/
				ptrpath = &(__environ[itr][j + 1]);
				printf("This is ptrpath in the parsed env [%s]\n", ptrpath);
				return (ptrpath);
			}
                        if (name[j] != __environ[itr][j])
				break;
			j++;
		}
                itr++;
	}
        return (NULL);
}
