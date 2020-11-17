#include "shell.h"

/**
 * checkfunction: This checks for builtins in the PATH
 * @head: This is the linked list being passed in
 * Return: is an integer
 */

int checkfunction(list_t *head)
{
	list_t *itr = head;
	char *str;

	while (itr != NULL)
	{
  		str = itr->token;
		if (_strcmp("PATH", str) == 0 || _strcmp("XDG_SESSION_ID", str) == 0)
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
		itr = itr->next;
	}
	return(0);
}
