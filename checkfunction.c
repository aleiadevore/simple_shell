#include "shell.h"

/**
 * envfunction - prints environment
 * @head: head of linked list
 *
 * Return: 1 if env input, 0 if not
 */

int envfunction(list_t *head)
{
	int i, j;
	list_t *node;

	for (node = head; node != NULL; node = node->next)
	{
		if (_strcmp("env", node->token) == 0)
		{
			for (i = 0; __environ[i] != NULL; i++)
			{
				for (j = 0; __environ[i][j] != '\0'; j++)
					_putchar(__environ[i][j]);
				_putchar('\n');
			}
			return (1);
		}
	}
	return (0);
}

/**
 * checkfunction - This checks for builtins in the PATH
 * @head: This is the linked list being passed in
 * Return: is an integer
 */

int checkfunction(list_t *head)
{
	list_t *node = head;
	char *str;
	int success = 0;

	while (node != NULL)
	{
		str = node->token;
/*		if (_strcmp("cd", str) == 0)
		success = cdex(head);*/
		if (_strcmp("exit", str) == 0)
			Exitfunc(head);
/*		if (_strcmp("PATH", str) == 0 || _strcmp("XDG_SESSION_ID", str) == 0)
			getenviron(str, itr);
		if (_strcmp("TERM", str) == 0 || _strcmp("TERM", str) == 0)
			getenviron(str, itr);
		if (_strcmp("SHELL", str) == 0 || _strcmp("SSH_CLIENT", str) == 0)
			getenviron(str, itr);
		if (_strcmp("SSH_TTY", str) == 0 || _strcmp("USER", str) == 0)
			getenviron(str, itr);
		if (_strcmp("LS_COLORS", str) == 0 || _strcmp("MAIL", str) == 0)
			getenviron(str, itr);
		if (_strcmp("LESSOPEN", str) == 0 || _strcmp("OLDPWD", str) == 0)
			getenviron(str, itr);
		if (_strcmp("LANG", str) == 0 || _strcmp("SHLVL", str) == 0)
			getenviron(str, itr);
		if (_strcmp("HOME", str) == 0 || _strcmp("LOGNAME", str) == 0)
			getenviron(str, itr);
		if (_strcmp("SSH_CONNECTION", str) == 0 || _strcmp("PWD", str) == 0)
			getenviron(str, itr);
		if (_strcmp("_", str) == 0 || _strcmp("XDG_RUNTIME_DIR", str) == 0)
			getenviron(str, itr);
		if (_strcmp("LESSCLOSE", str) == 0)
			getenviron(str, itr);
*/
		node = node->next;
	}
	return (success);
}

int cdex(list_t *head)
{
/*	list_t *node;
 */	int success;

/*	node = head->next;
 */
	printf("%s\n", head->token);
	success = chdir("..");

	return (success);
}
/**
 * Exitfunc - This function exits the shell when the user types "exit"
 * @head: head is passed in to free the linked list
 * Return: void
 * Descritption: This function is a replacement for the Exit builtin
 */
void Exitfunc(list_t *head)
{
	free_list(&head);
	exit(0);
}
/**
 * ctrl_c - this handles the ctrl c
 *
 */
void ctrl_c(int sig_num)
{
	signal(sig_num, SIG_IGN);
	printf("\n Cannot be terminated using Ctrl+C \n");
	/*fflush(stdout);*/
}
