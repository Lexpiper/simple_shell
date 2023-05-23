#include "shell.h"

/**
 * main - Creates a loop for to receive user call functions, parse the input
 * and check program type to execute a program file if success
 * @argc: number of command line arguments
 * @argv: command line arguments
 * Return: 0, success, otherwise errors
 */
int main(int argc, char **argv)
{
	char *input_buffer, **args;
	size_t buffer_size;
	int loops = 1;
	(void)argc;/*unused parameter, silence the warning*/
	/*set up signal handling for Ctrl+C*/
	signal(SIGINT, ss_sighandle);
	while (1)
	{
		input_buffer = NULL;
		args = NULL;
		buffer_size = 0;
		/*Display the shell prompt*/
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "$ ", 2);
		/*Read the user input*/
		if (getline(&input_buffer, &buffer_size, stdin) == EOF)
		{
			/*if EOF is encountered (e.g., Ctrl+D),exit the shell*/
			if (isatty(STDIN_FILENO))
				write(STDOUT_FILENO, "\n", 1);
			free(input_buffer);
			return (0);
		}
		/*Tokenize the input into arguments*/
		args = tokenize_input(input_buffer);
		if (args != NULL && args[0] != NULL)
		{
			/*check if the command is a built-in command*/
			if (handle_builtin(args, input_buffer, loops))
				continue;
			/*Execute the command as a program file*/
			if (execute_file_program(args) == -1)
				print_errmsg(argv, args, loops);
		}
		/*free allocated memory*/
		_free(1, input_buffer);
		_free(2, args);
		loops++;
	}
	return (0);
}
