#include "shell.h"
/**
 * _itoa - This makes a int to a char
 * @n: integer that will become char
 *
 * Return: is count
 */
int _itoa(int n)
{
	int k, count = 1;

	if (n / 10 != 0)
		count += _itoa(n / 10);
	k = (n % 10) + '0';

	_eputchar(k + '\0');

	return (count);
}

/**
 * _eputchar - prints character to standard error
 * @c: character to print
 * Return: write
 */

int _eputchar(char c)
{
	return (write(2, &c, 1));
}
