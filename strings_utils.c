#include "shell.h"

/**
 * _strlen - Returns the length of a string.
 * @str: String to find the length of.
 *
 * Return: length of the string.
 */
int _strlen(char *str)
{
	int len = 0;

	while (str[len] != '\0')
		len++;

	return (len);
}
