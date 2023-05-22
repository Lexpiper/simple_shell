#include "shell.h"


/**
 *run_command - creates a child process and executes a new program
 *@arg_list: pointer to array of arguments
 *
 *Return: 0 on success, 1 on failure
 */

int run_command(char **arg_list)
{
	pid_t pid;
	int status;

	/* fork a child process */
	pid = fork();
	/* if error occured */
	if (pid < 0)
	{
		exit(1);
	}
	else if (pid == 0)
	{
		/* execute the program with provided arguments */
		if (execve(arg_list[0], arg_list, environ) == -1)
		{
			exit(127);
		}
	}
	else
	{
	/* wait for child process to complete */
	wait(&status);
	if (WIFEXITED(status) && status != 0)
		exit(WEXITSTATUS(status));
	}

	return (0);

}

