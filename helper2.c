#include "shell.h"

/**
 * _strlen - returns length of string
 * @s: string
 * Return: length of string
 */

int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		s++;
		length++;
	}
	return (length);
}

/**
 * _strcat - concatenates two strings
 * @dest: destination string
 * @src: source string
 * Return: destination string
 */

char *_strcat(char *dest, char *src)
{
	int srclength = 0, destlength = 0, i;

	while (src[srclength] != '\0')
		srclength++;
	while (dest[destlength] != '\0')
		destlength++;
	for (i = 0 ; i <= srclength && src[i] != '\0' ; i++)
		dest[destlength + i] = src[i];
	dest[destlength + i] = '\0';

	return (dest);
}
