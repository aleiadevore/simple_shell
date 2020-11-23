#include "shell.h"
/**
 * error_handle - This handles the error when a command is not found
 * @head: this is the linked list being passed in
 * @count: this is the line count.
 * Return: Nothing since its void
 */
void error_handle(list_t *head, int count, char *av)
{
	char *comand = head->token, linecount = count + '0';


	write(STDERR_FILENO, av, _strlen(av));
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, &linecount, 1);
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, comand, _strlen(comand));
	write(STDERR_FILENO, ": not found", 12);
	write(STDERR_FILENO, "\n", 1);
}
