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
	char *comand = head->token, linecount = count + '0';
	int buff = 0;

	buff = _strlen(av) + 1;
	write(STDERR_FILENO, av, buff);
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, &linecount, 1);
	write(STDERR_FILENO, ": ", 3);
	buff = _strlen(comand) + 1;
	write(STDERR_FILENO, comand, buff);
	write(STDERR_FILENO, ": not found", 12);
	write(STDERR_FILENO, "\n", 1);
}
