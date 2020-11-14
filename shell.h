#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

extern char **environ;
/**
 * tokenmach - This stucture holdes the values of the PATH
 * @token: The tokenized Path
 * @next: this is a pointer to the next node in the list
 * Description: This si a singly linked list for the tokenized PATH
 */
typedef struct tokenmach
{
	char *token;
	struct tokenmach *next;

} tm;

char **token(char *input, size_t sz_input);

#endif
