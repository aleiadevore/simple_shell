#include "shell.h"
/**
 * error_handle - This handles the error when a command is not found
 * @head: this is the linked list being passed in
 * @count: this is the line count.
 * @av: shell function
 * Return: Nothing since its void
 */
void error_handle(list_t *head, int count, char *av)
{
	char *command = head->token, linecount = count + '0';
	int buff = 0;

	buff = _strlen(av);
	write(STDERR_FILENO, av, buff);
	write(STDERR_FILENO, ": ", 2);
	write(STDERR_FILENO, &linecount, 1);
	write(STDERR_FILENO, ": ", 2);
	buff = _strlen(command);
	write(STDERR_FILENO, command, buff);
	write(STDERR_FILENO, ": not found", 11);
	write(STDERR_FILENO, "\n", 1);
}
