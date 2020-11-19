#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <dirent.h>

extern char **environ;
/**
 * struct list_t - This stucture holdes the values of the PATH
 * @token: The tokenized Path
 * @next: this is a pointer to the next node in the list
 * Description: This is a singly linked list for the tokenized PATH
 */
typedef struct list_t
{
	char *token;
	char *envpth;
	char *cmdtok;
	struct list_t *next;

} list_t;

list_t *token(char *input, list_t *head);
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strlen(char *s);
char *_strcat(char *dest, char *src);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str, const char *cmd);
void free_list(list_t **head);
char *_strncpy(char *dest, char *src, int n);
int getenviron(char *name, list_t *node);
size_t print_list(const list_t *h);
int checkfunction(list_t *head);
char *dirsearch(list_t *head);
list_t *tok_path(list_t *head);
char *parsedenv(void);
int excmd(list_t *head, char *cmd);
char *append(list_t *head, char *cmd);
#endif
