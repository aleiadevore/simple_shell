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
	char *file = NULL;
	struct dirent *nav;
        DIR *dir;

	node = tok_path(head);
	printf("Inside diresearch\n");
	while (node != NULL)
	{
		if (node->cmdtok != NULL)
		{
			printf("node->cmdtok = [%s]\n", node->cmdtok);
			dir = opendir(node->cmdtok);
			if (dir == NULL)
			{
				printf("directory not found\n");
				return (NULL);
			}
			/*	printf("directory not null");*/
			while ((nav = readdir(dir)) != NULL)
			{
				printf("nav->d_name = [%s]", nav->d_name);
				if ((_strcmp(nav->d_name, ".")) == 0 ||
				    (_strcmp(nav->d_name, "..")) == 0)
					continue;
				printf("_____nav->d_name = [%s], head->token = [%s]____\n", nav->d_name, head->token);
				if (_strcmp(head->token, nav->d_name) == 0)
				{
					printf("Found a match node->token = [%s] nav->d_name [%s]", node->token, nav->d_name);
					file = node->cmdtok;
					closedir(dir);
					excmd(head, file);
					return(file);
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
	int itr;
/*	list_t *node = head;*/
	char *tokenbuf = NULL, *ptrpath = NULL, *ptr;
	printf("made it into tokpath\n");
/*	for (;node != NULL; node = node->next)
	;*/
	for (itr = 0; __environ[itr] != NULL; itr++)
	{
		ptr = _strstr(__environ[itr], "PATH=");
		if (ptr != 0)
			break;
	}
	ptrpath = malloc(sizeof(char) * (_strlen(ptr) + 1));
	_strcpy(ptrpath, ptr);

	tokenbuf = strtok(ptrpath, "=");
	if (!tokenbuf)
	{
		printf("tokenbuf failed, [%s]\n", tokenbuf);
		exit(5);
	}
        while (tokenbuf != NULL)
        {
                tokenbuf = strtok(NULL, ":");
                printf("Parsed PATH by [:] [%s]\n", tokenbuf);
                if (!tokenbuf)
                        break;
		add_node_end(&head, NULL, tokenbuf);
        }

/*	tokenbuf = strtok(ptrpath, ":");
	if(!tokenbuf)
	{
		printf("tokenbuf failed, [%s]\n", tokenbuf);
		exit(5);
	}
	add_node_end(&head, NULL, tokenbuf);
	printf("before whileloop\n");
	while (tokenbuf != NULL)
	{
		tokenbuf = strtok(NULL, ":");
		printf("Parsed PATH by [:] [%s]\n", tokenbuf);
		if (!tokenbuf)
			break;
		add_node_end(&head, NULL, tokenbuf);
	}
*/	free(ptrpath);
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
				ptrpath = malloc(sizeof(char) * (_strlen(&(__environ[itr][j + 1]) + 6)));
				_strcpy(ptrpath, "PATH=");
				_strcat(ptrpath, &(__environ[itr][j + 1]));
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
