#include "shell.h"

/**
<<<<<<< HEAD
 *handle_builtin - handles built-in shell commands.
=======
 *handle_builtin - handles built-in shell commands
 *
>>>>>>> parent of 8013177 (updates description for function)
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
		_free(1, buffer), _free(2, args);
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
		_free(1, buffer), _free(2, args);
		return (1);
	}
	return (0);
}


/**
 *ss_exit - Exits the Simple Shell program
 *@args: Null-terminated array of argument strings
 *args[1] is the exit status number
 *@buffer: Pointer to user input buffer
 *@loops: Number of times the shell loop has been executed
 *
 * Return: Nothing
 */

int ss_exit(char **args, char *buffer, int loops)
{
	int exit_status = 0;
	char error_msg[100];

	/* check if exit status number provided */
	if (args[1] != NULL)
	{
		/* check if provided exit status number is valid */
		if (is_number(args[1]))
		{
			exit_status = _atoi(args[1]);
			/* bigger values result to mod 256 */
			if (exit_status > 255)
				exit_status = exit_status % 256;

			if (exit_status < 0)
			{
				sprintf(error_msg, "./shell: %d: %s: illegal number %s\n",
					loops, args[0], args[1]);
				write(STDERR_FILENO, &error_msg, _strlen(error_msg));
				exit_status = 2;
			}
		}
		else
		{
			sprintf(error_msg, "./shell: %d: %s: Illegal number: %s\n",
				loops, args[0], args[1]);
			write(STDERR_FILENO, &error_msg, _strlen(error_msg));
			exit_status = 2;
		}
	}
	_free(1, buffer), _free(2, args);
	exit(exit_status);
}


/**
 *print_env - Prints the global environment variables
 *This function prints the environment variables of the current process to
 *
 *standard output, each variable in a new line.
 *
 *Return: void
 */
void print_env(void)
{
	int i;

	for (i = 0; environ[i] != NULL; i++)
	{
		write(STDOUT_FILENO, environ[i], _strlen(environ[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 *ss_cd - Changes the current working directory according
 *	to the argument provided
 *@args: Null-terminated array of argument strings
 *argument. It also handles errors such as changing to the home directory or
 *previous directory or when the specified directory does not exist.
 *
 *Return: Nothing
 */

void ss_cd(char **args)
{
	char *home_dir = _get_env_var("HOME");
	char *prev_dir = _get_env_var("OLDPWD");

	/* if no arguments provided or tilde symbol used */
	if ((args[1] == NULL && home_dir) || (args[1][0] == '~' && home_dir))
	{
		chdir(home_dir);
	}
	else if (args[1][0] == '~' && prev_dir)
	{
		chdir(prev_dir);
	}
	else if (chdir(args[1]) != 0)
	{
		perror("ss_cd");
	}
}


/**
 *ss_sighandle - Handles the SIGINT signal triggered by Ctrl-C
 *@sign: The integer signal number
 *This function handles the SIGINT signal triggered by Ctrl-C, and prints a
 *new line followed by the shell prompt to make it clear that the signal
 *was received and the shell is ready to accept new input.
 *Return: void
 */

void ss_sighandle(int sign)
{
	if (sign == SIGINT)
		write(STDOUT_FILENO, "\nSimple_shell~$ ", 3);
}

