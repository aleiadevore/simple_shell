#include "shell.h"


/**
 * _strlen - returns length of string
 * @s: string
 * Return: length of string
 */

int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;

	return (len);
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
	{
		dest[destlength + i] = src[i];
	}
	dest[destlength + i] = '\0';

	return (dest);
}
/**
 * _strncpy - This copes up to n amount of bytes
 * @dest: this is a pointer to the destination
 * @src: this is a pointer to the src
 * @n: This is the ammount of bytes to copy up to
 * Return: is a pointer to dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i;

	for (i = 0; i < n && src[i] != '\0'; i++)
		dest[i] = src[i];

	for (; i < n; i++)
		dest[i] = '\0';

	return (dest);
}

/**
 * _strstr - locates a substring
 * @haystack: string
 * @needle: substring
 * Return: pointer to beginning of substring
 */

char *_strstr(char *haystack, char *needle)
{
	int x = 0, y = 0;

	while (haystack[x] != 0)
	{
		while (needle[y] != 0)
		{
			if (haystack[x + y] != needle[y])
				break;
			y++;
		}
		if (needle[y] == 0)
			return (haystack + x);
		x++;
	}
	return (0);
}
