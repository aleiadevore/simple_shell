#include "shell.h"

/**
 * _strcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: negative, zero, or positive value if s1 is greater than, equal to,
 * or less than s2
 */

int _strcmp(char *s1, char *s2)
{
	int a = 0, b = 0, c;

	while (s1[a] == s2[b])
	{
		if (s1[a] == '\0' || s2[b] == '\0')
			break;
		a++, b++;
	}
	c = s1[a] - s2[b];
	return (c);
}

/**
 * _strcpy - copies string to buffer
 * @dest: destination
 * @src: source
 * Return: destination value
 */

char *_strcpy(char *dest, char *src)
{
	int length = 0, spot;

	while (src[length] != '\0')
		length++;

	for (spot = 0; spot < length; spot++)
		dest[spot] = src[spot];
	dest[spot] = '\0';

	return (dest);
}

/**
 * _strdup - returns a pointer to a new string
 * @str: string to duplicate
 * Return: pointer or null if null
 */

char *_strdup(const char *str)
{
	unsigned int x, length;
	char  *ptr;

	if (str == NULL)
		return (NULL);
	for (length = 0; str[length] != '\0'; length++)
		;
	ptr = malloc((length + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	for (x = 0; x <= length; x++)
	{
		ptr[x] = str[x];
	}

	return (ptr);
}
