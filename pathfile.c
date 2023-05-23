#include "shell.h"

/**
 * get_path_file - searches in the PATH environment variable for a program file
 * path, stores subdirectories in an array, and validateds if the program file
 * path is available
 * @args: user input array arguments
 * Return: 0 on success, -1 on failure
 */
int get_path_file(char **args)
{
	int index = 0;
	char **subdirs;
	char *path, *path_var;

	subdirs = malloc(sizeof(char *) * BUFFSIZE);
	path = _strdup(_get_env_var("PATH"));

	if (path == NULL || subdirs == NULL)
	{
		_free(1, path);
		return (-1);
	}

	path_var = strtok(path, "=");

	while (path_var != NULL)
	{
		subdirs[index] = _strdup(path_var);

		if (subdirs[index] == NULL)
		{
			_free(1, path);
			_free(2, subdirs);
			return (-1);
		}

		path_var = strtok(NULL, "=:");
		index++;
	}

	subdirs[index] = path_var;

	if (search_dir(subdirs, args) == -1)
	{
		_free(1, path);
		return (-1);
	}

	_free(1, path);
	return (0);
}

