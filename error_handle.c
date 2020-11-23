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


	write(1, av, _strlen(av));
	write(1, ": ", 3);
	write(1, &linecount, 1);
	write(1, ": ", 3);
	write(1, comand, _strlen(comand));
	write(1, ": not found", 12);
	write(1, "\n", 1);
}
