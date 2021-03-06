#include "shell.h"

/**
 * dirsearch - This function looks for a alias match along the PATH
 * @head: this is the linked list reference
 * @lncount: line count
 * @av: av[0]
 * Return: is a char pointer
 * Description: This looks throught the directories
 */

char *dirsearch(list_t *head, int lncount, char *av)
{
	list_t *node = NULL;
	char *file = NULL;
	struct dirent *nav;
	DIR *dir;

	tok_path(head), node = head;
	if (pathval(head) == 0)
	{
		for (; node != NULL; node = node->next)
		{
			if (node->cmdtok != NULL)
			{
				dir = opendir(node->cmdtok);
				if (dir == NULL)
				{
					perror("directory not found\n");
					return (NULL);
				}
				while ((nav = readdir(dir)) != NULL)
				{
					if (_strcmp(nav->d_name, ".") == 0)
						continue;
					else if (_strcmp(nav->d_name, "..") == 0)
						continue;
					if (_strcmp(head->token, nav->d_name) == 0)
					{
						file = node->cmdtok;
						closedir(dir);
						excmd(head, file);
						return (file);
					}
				}
				closedir(dir);
			}
		}
		error_handle(head, lncount, av);
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
	char *tokenbuf = NULL, *ptrpath = NULL, *ptr;

	for (itr = 0; environ[itr] != NULL; itr++)
	{
		if (environ[itr][0] == 'P')
		{
			ptr = _strstr(environ[itr], "PATH=");
			if (ptr != 0)
				break;
		}
	}
	if (!ptr)
		helpererror("ptr", ENOMEM);

	ptrpath = malloc(sizeof(char) * (_strlen(ptr) + 1));

	if (!ptrpath)
		helpererror("tokenbuf", ENOMEM);

	_strcpy(ptrpath, ptr);

	tokenbuf = strtok(ptrpath, "=");

	if (!tokenbuf)
		helpererror("tokenbuf", ENOENT);
	while (tokenbuf != NULL)
	{
		tokenbuf = strtok(NULL, ":");
		if (!tokenbuf)
			break;
		add_node_end(&head, NULL, tokenbuf);
	}
	free(ptrpath);
	return (head);
}

/**
 * helpererror - This function handles the error cases for functions
 * @errorstat: this is the name of the variable we are checking
 * @errornum: this is the macro that checks for the appropriate error message
 */
void helpererror(char *errorstat, int errornum)
{
	errno = errornum;
	perror(errorstat);
	exit(2);
}

/**
 * pathval - executes path if it begins with a slash
 * @head: head of linked list
 *
 * Return: 0 if it does not begin with slash, 1 if it does
 */

int pathval(list_t *head)
{
	int val = 0, status;
	char *ptr = head->token;
	pid_t child;
	list_t *node = head->next;
	char *argv[3] = {'\0', '\0', '\0'};

	if (ptr[0] == '/')
	{
		val = access(head->token, F_OK);
		if (val != 0)
			perror("File does not exist\n");
		else
		{
			argv[0] = head->token;
			argv[1] = node->token;

			child = fork();

			if (child == -1)
			{
				perror("Error");
				exit(3);
			}
			else if (child == 0)
			{
				if (execve(argv[0], argv, NULL) != -1)
					perror("Error");
			}
			else
				wait(&status);
		}
		return (1);
	}
	return (0);
}

/**
 * error_handle - This function helps print the error handling
 * @head: this is a refernce to the linke list.
 * @count: This is a count of the number of lines that are recived
 * @av: This hold the first argument from the command line av[0]
 * Return: void
 */
void error_handle(list_t *head, int count, char *av)
{
	char *input = av, *command = head->token;

	errno = ENOENT;

	write(STDERR_FILENO, input, _strlen(input));
	write(STDERR_FILENO, ": ", 3);
	_itoa(count);
	write(STDERR_FILENO, ": ", 3);
	perror(command);
}
