#include "shell.h"

/**
 *_get_env_var - Searches for a specific environment variable and returns its value
 *@name: Name of the environment variable to search for
 *Return: Pointer to the corresponding value string
 */

char *_get_env_var(char *name)
{
	int index = 0;

	while (environ[index])
	{
		if (_strncmp(environ[index], name, _strlen(name)) == 0)
			return (environ[index] + (_strlen(name) + 1));

		++index;
	}
	return (NULL);
}

