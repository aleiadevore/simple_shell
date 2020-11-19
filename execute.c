#include "shell.h"

char *append(list_t *head)
{
	list_t *node = NULL;
	char *headtok = NULL;

        node = head->next;
        headtok = malloc(sizeof(char) * (_strlen(head->token) + _strlen(node->token) + 2));
        _strcpy(headtok, head->token);
        if ((node->token)[0] == '-')
        {
                _strcat(headtok, " ");
                _strcat(headtok, node->token);
                printf("Head->token is [%s]\nnode->token is [%s]\n", head->token, node->token);
	}
	return (headtok);
}

/**
 *
 *
 *
 *
 */

int excmd(list_t *head, char *cmd)
{
/*	pid_t child;*/
	/* cmd = ptr to location, fl = flag, head->token = command, NULL */
	char *headtok = NULL;
	int bool = 0;
	(void) cmd;

	headtok = append(head);
	printf("headtok = [%s]\n", headtok);
	free(headtok);
	return (bool);
}
