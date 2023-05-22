#include "shell.h"

/**
 * execute_file_program - Check if command is a local executable,
 * or in the PATH, and execute it.
 * @args: user input array arguments
 *
 * Return: 0 on success, 1 on failure
 */
int execute_file_program(char **args)
{
	struct stat stat_buf;

	if (state(args[0], &state_buf) == 0 && access(args[0], X_OK) == 0)
	{
		run_command(args);
		return (0);
	}

	get_path_file(args);
	if (stat(args[0], &stat_buf) == -1)
		return (-1);

	return (run_command(args));
}

/**
 * search_dir - Search in the directories specified in the
 * PATH environment variable
 * and appends the given filename to the path of the first matching directory
 * @directories: Pointer to an array of directory paths in the PATH
 * environment variable.
 * @args: Pointer to an array of user_provided arguments,
 * where the first argument is the filename to search.
 * Return: 0 on success, -1 on failure.
 */
int search_dir(char **directories, char **args)
{
	char *current_working_dir;
	int i;
	stat sb;

	current_working_dir = getcwd(NULL, 0);

	for (i = 0; directories[i] != NULL; i++)
	{
		chdir(directories[i]);
		if (stat(args[0], &sb) == 0)
		{
			args[0] = append_path(directories[i], args[0]);
			if (args[0] == NULL)
			{
				_free(1, current_working_dir);
				_free(2, directories);
				return (-1);
				}
				break;
		}
	}
	chdir(current_working_dir);
	_free(1, current_working_dir);
	if (directories[i] == NULL)
	{
		_free(2, directories);
		return (-1);
	}
	_free(2, directories);
	return (0);
}
