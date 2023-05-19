#include "shell.h"

/**
 *handle_builtin - handles built-in shell commands
 *
 *@args: Null-terminated array of argument strings
 *@buffer: pointer to user input buffer
 *@loops: number of times the shell loop has been execute
 *
 *Return: 0 on successful exit, 1 to continue with the shell loop
 */

int handle_builtin(char **args, char *buffer, int loops)
{
	if (_strcmp(args[0], "env") == 0)
	{
	/* call built-in env function */
		print_env();
	/* free allocated memory and rwturn 1 to continue shell loop */
		_free(1, buffer), _free(2,args);
		return (1);
	}
	else if (_strcmp(buffer, "exit") == 0)
	{
		/* call built-in exit function */
		ss_exit(args, buffer, loops);
	}
	else if (_strcmp(args[0], "cd") == 0)
	{
		/* call built-in cd function */
		ss_cd(args);

		/* free allocated memory and return 1 to continue shell loop */
		_free(1, buffer), _free(2, args);
		return (1);
	}
	return (0);
}

