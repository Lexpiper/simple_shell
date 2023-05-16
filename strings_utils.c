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
/**
 * _strncmp - Compares two strings up to a certain number of characters
 * @s1: First string.
 * @s2: Second string.
 * @n: Number of characters to compare.
 *
 * Return: 0 if both strings are equal, n or -n if they are not.
 */
char *_strdup(char *str)
{
	int index, len;
	char *new_str;

	len = _strlen(str);

	new_str = malloc((len + 1) * sizeof(char));

	if (new_str == NULL)
		return (NULL);
	for (index = 0; index < len; index++)
	{
		new_str[index] = str[index];
	}
	new_str[index] = '\0';

	return (new_str);
}

