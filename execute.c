#include "shell.h"

char *append(list_t *head, char *cmd)
{
	char *ptr = NULL;

	
        ptr = malloc(sizeof(char) * (_strlen(head->token) + _strlen(cmd) + 2));
	_strcpy(ptr, cmd);
	_strcat(ptr, "/");
	_strcat(ptr, head->token);
	return (ptr);
}

/**
 *
 *
 *
 *
 */

int excmd(list_t *head, char *cmd)
{
	pid_t child;
	list_t *node = NULL;
	/* cmd = ptr to location, fl = flag, head->token = command, NULL */
	char *argv[4] = {'\0', '\0', '\0', '\0'}, *flag = NULL, *ptr = NULL;
	int bool = 0, status;
	node = head->next;
	flag = node->token;
	ptr = append(head, cmd);
	argv[0] = ptr;
	argv[1] = flag;
	argv[2]= cmd;
	printf("argv[0] = [%s]\n argv[1] = [%s]\n, argv[2] = [%s]\n", argv[0], argv[1], argv[2]);
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
		wait(&status);
		if (WIFEXITED(status))
			printf("Exit status: %d\n", WEXITSTATUS(status));
	}
	free(ptr);
	return (bool);
}
