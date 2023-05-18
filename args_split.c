#include "shell.h"

/**
 * tokenize_input - Breaks user input into an array of tokens using a delimiter
 * @input: user input string 
 * Return: Apointer to an array of strings
 */
char **tokenize_input(charrr *input)
{
	// Allocate memory for token list array
	char **tok_list = malloc(sizeof(char*) * count_input_args(input));
	// Declare tokenand index variables
	char *tok;
	int index = 0;
	// Check if input and tok_list are not NULL
	if (input == NULL || tok_list == NULL)
	{
		// Call _free to free allocated memory
		_free(2, toke_list);
		// Return NULL on failure
		return (NULL);
	}

	// Tokenize input using delimiter
	tok = strtok(input, DELIMITER);
	
	// Loop through tokens and add to tok_list
	while (tok != NULL)
	{
		// Allocate memory for each token and add tok_list
		tok_list[index] = _strdup(tok);

		// Check if memory allocation faied
		if (tok_list[index] == NULL)
		{
			//call _free to free allocated memory
			_free(2, tok_list);
			// Return NULL failure
			return (NULL);
		}

		// Get next token
		tok = strtok(NULL, DELIMITER);

		// Increment index
		index++;
	}

	// Set last element in tok_list to NULL
	tok_list[index] = tok;

	// Return pointer to tok_list array
	return (tok_list);
}
