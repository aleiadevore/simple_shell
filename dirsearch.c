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

	tok_path(head);
	node = head;
	printf("node->cmdtok = [%s]\n", node->cmdtok);
	if (pathval(head) == 0)
	{
		for(; node != NULL; node = node->next)
		{
			if (node->cmdtok != NULL)
			{
				printf("made it into if statment\n");
				dir = opendir(node->cmdtok);
				if (dir == NULL)
				{
					perror("directory not found\n");
					return (NULL);
				}

				while ((nav = readdir(dir)) != NULL)
				{
					printf("nav->d_name: [%s]\nhead->token: [%s]\n",nav->d_name, head->token);
					/*		if (_strcmp(nav->d_name, ".") == 0 || _strcmp(nav->d_name, "..") == 0)
							continue;*/
					if (_strcmp(head->token, nav->d_name) == 0)
					{
						printf("we made it insode the last if statment\n");
						file = node->cmdtok;
						closedir(dir);
						excmd(head, file);
						return (file);
					}
				}
				closedir(dir);
			}
			/*node = node->next;*/
		}
	}
	write(STDOUT_FILENO, head->token, _strlen(head->token));
	perror(": Command not found");
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
	char *tokenbuf = NULL, *ptrpath = NULL, *ptr;

	for (itr = 0; __environ[itr] != NULL; itr++)
	{
		if (__environ[itr][0] == 'P')
		{

			ptr = _strstr(__environ[itr], "PATH=");
			if (ptr != 0)
				break;
		}
	}

	ptrpath = malloc(sizeof(char) * (_strlen(ptr) + 1));

	_strcpy(ptrpath, ptr);

	tokenbuf = strtok(ptrpath, "=");
	if (!tokenbuf)
	{
		perror("tokenbuf failed");
		exit(5);
	}
	while (tokenbuf != NULL)
	{
		tokenbuf = strtok(NULL, ":");
		if (!tokenbuf)
			break;
		printf("tokenbuf is: [%s]\n", tokenbuf);
		add_node_end(&head, NULL, tokenbuf);
	}

	free(ptrpath);
	return (head);
}

int pathval(list_t *head)
{
	int val = 0,status;
	char *ptr = head->token;
	pid_t child;
	list_t *node = head->next;
	char *argv[3] = {'\0', '\0', '\0'};


	if (ptr[0] == '/')
	{
		val = access(head->token, F_OK);
		if (val != 0)
		{
			perror("File does not exist\n");
		}
		else
		{
			argv[0] = head->token;
			argv[1] = node->token;

			child = fork();

			if (child == -1)
			{
				perror("Error");
			}

			else if (child == 0)
			{
				if (execve(argv[0], argv, NULL) != -1)
					perror("Error");
				sleep(2);
			}
			else
			{
/*NOTE TO FUTURE SELVES: REPLACE PRINT statement*/
				wait(&status);
				if (WIFEXITED(status))
					printf("Exit status: %d\n", WEXITSTATUS(status));
			}

		}
		return (1);
	}
	return (0);
}
