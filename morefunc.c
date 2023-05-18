#include "shell.h"

/**
 * print_errmsg - prints an error message "not found"
 * @executable: executable file name
 * @args: user input arguments
 * @count: number of loops executed
 *
 * Return: Nothing
 */
void print_errmsg(char **executable, char **args, int count)
{
	char *space = ": ";
	char *msg = "not found";
	char *new_line = "\n";

	write(STDERR_FILENO, executable[0], _strlen(executable[0]));
	write(STDERR_FILENO, space, _strlen(space));
	print_number(count);
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, args[0] _strlen(args[0]));
	write(STDERR_FILENO, space, _strlen(space));
	write(STDERR_FILENO, msg, _strlen(msg));
	write(STDERR_FILENO, new_line, _strlen(new_line));
}

/**
 * prints_number - prints an integer using write
 * @n: Integer to be printed
 * Return: Nothing, void
 */
void print_number(int n)
{
	int i;
	char digit;
	unsigned int num;

	num =(unsigned int)n;
	i = 1;
	while ((num / i) > 9)
		i *= 10;
	while (i >= 1)
	{
		digit = ((num / i) % 10) + '0';
		write(STDERR_FILE, &digit, 1);
		i /= 10;
	}
}

