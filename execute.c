#include "shell.h"
/**
 * append - This appends the command to the flags
 * @head: this is refernce to linked list
 * @cmd: This is the command passed
 * Return: pointer to concatenated string
 */
char *append(list_t *head, char *cmd)
{
	char *ptr = NULL;

	ptr = malloc(sizeof(char) * (_strlen(head->token) + _strlen(cmd) + 2));
	if (!ptr)
	{
		perror("Failed to allocate memeory");
		free(ptr);
		exit(102);
	}
	_strcpy(ptr, cmd);
	_strcat(ptr, "/");
	_strcat(ptr, head->token);
	return (ptr);
}

/**
 * excmd - this function forks the process and executes it
 * @head: this is refernce to linked list
 * @cmd: this is a refrence to command
 * Return: This returns boolen to show if command was executed
 */
int excmd(list_t *head, char *cmd)
{
	pid_t child;
	list_t *node = NULL;
	char *argv[4] = {'\0', '\0', '\0', '\0'}, *flag = NULL, *ptr = NULL;
	int bool = 0, status;

	node = head->next;
	flag = node->token;
	if (cmd != NULL)
		ptr = append(head, cmd);

	argv[0] = ptr;
	argv[1] = flag;
	argv[2] = cmd;

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
	free(ptr);

	return (bool);
}
