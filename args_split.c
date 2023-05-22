#include "shell.h"
/**
 * tokenize_input - Breaks user input into an array of tokens using a delimiter
 * @input: user input string
 * Return: Apointer to an array of strings
 */
char **tokenize_input(charrr *input)
{
	/* Allocate memory for token list array*/
	char **tok_list = malloc(sizeof(char *) * count_input_args(input));
	/* Declare token and index variables*/
	char *tok;
	int index = 0;
	/* Check if input and tok_list are not NULL*/
	if (input == NULL || tok_list == NULL)
	{
		/* Call _free to free allocated memory*/
		_free(2, toke_list);
		/* Return NULL on failure*/
		return (NULL);
	}
	/* Tokenize input using delimiter*/
	tok = strtok(input, DELIMITER);
	/* Loop through tokens and add to tok_list*/
	while (tok != NULL)
	{
		/* Allocate memory for each token and add tok_list*/
		tok_list[index] = _strdup(tok);
		/* Check if memory allocation faied*/
		if (tok_list[index] == NULL)
		{
			/* call _free to free allocated memory*/
			_free(2, tok_list);
			/* Return NULL failure*/
			return (NULL);
		}
		/* Get next token*/
		tok = strtok(NULL, DELIMITER);
		/* Increment index*/
		index++;
	}
	/* Set last element in tok_list to NULL*/
	tok_list[index] = tok;
	/*Return pointer to tok_list array */
	return (tok_list);
}
/**
 * count_input_args - Counts the number of arguments in a user input string
 * @input: user input string
 * Return: number of arguments
 */
int count_input_args(char *input)
{
	int i, arg_count, arg_flag, j;
	char *delimiters = " :"; /*define possible delimiters*/

	arg_flag = i = 0;
	arg_count = 1;

	if (input == NULL) /*check for null input*/
		return (arg_count);
	while (input[i] != '\0') /*iterate through input*/
	{
		for (j = 0; delimiters[j] != '\0'; j++) /*iterate through delimiters*/
		{
			if (input[i] == delimiters[j] && narg_flag == 0)
				/*check for delimiter and flag*/
			{
				arg_count++;  /*increment argument count*/
				arg_flag = 1 /*set flag to 1*/
				break;
			}
		}
		if (delimiters[j] == '\0') /*check if reached end of delimiters*/
			arg_flag = 0;  /*reset flag*/
		i++;  /*increment index*/
	}

	return (arg_count + 1); /*add 1 to account for NULL terminator*/
}

