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
 * Return: is 0 for success
 */

int checkfunction(list_t *head)
{
	list_t *node = head;
	char *str;
	int success = 0;

	while (node != NULL)
	{
		str = node->token;
		if (_strcmp("exit", str) == 0)
			Exitfunc(head);
		node = node->next;
	}
	return (success);
}
/**
 * cdex - This function allows user to chnage directories
 * @head: this is the linked list being passed in.
 * Return: 0 for success
 */

int cdex(list_t *head)
{
	list_t *node;
	int success = 0;

	node = head->next;
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
 * ctrl_c - this handles the ctrl c when wntered by user
 * @sig_num: This is the integer that is passed in.
 * Return: void
 */
void ctrl_c(int sig_num)
{
	signal(sig_num, SIG_IGN);
	write(STDOUT_FILENO, "\n Cannot be terminated using Ctrl+C \n", 39);
	fflush(stdout);
}
