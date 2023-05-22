#include "shell.h"

/**
 * _free - Frees memory allocated by malloc accoding to the number of arguments
 * passed
 * @n: the number of arguments passed to the function
 * Return: nothing
 */
void _free(int n, ...)
{
	char **str_array, *str;
	va_list args;
	int i;

	va_start(args, n);

	if (n == 1)
	{
		str = va_arg(args, char *);
		if (str == NULL)
			return;
		free(str);
	}
	if (n == 2)
	{
		str_array = va_arg(args, char **);
		if (str_array == NULL)
			return;
		for (i = 0; str_array[i] != NULL; i++)
			free(str_array[i]);
		free(str_array);
	}

	va_end(args);
}
