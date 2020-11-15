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
typedef struct list_t
{
	char *token;
	struct list_t *next;

} list_t;

list_t *token(char *input, list_t *head);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t **head);
char *_strncpy(char *dest, char *src, int n);
list_t *getenviron(list_t *head);
size_t print_list(const list_t *h);
#endif
