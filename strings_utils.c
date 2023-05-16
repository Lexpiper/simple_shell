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

/**
 * _strcmp - Compares two strings character by character.
 * @s1: First string.
 * @s2: Second string.
 *
 * Return: Difference between the characters in the strings.
 */
int _strcmp(char *sl, char *s2)
{
	int index = 0;

	while ((s1[index] != '\0' && s2[index] != '\0') && s1[index] == s2[index])
	{
		index++;
	}
	
	return (s1[index] - s2[index]);
}

