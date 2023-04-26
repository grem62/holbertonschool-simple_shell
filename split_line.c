#include "main.h"
/**
* sshell_split_line - Splits line into tokens using whitespace as delimiters.
* @line: Splits line into an array of tokens, using whitespace as delimiters.
* Dynamically resizes to fit any number of tokens.
* Return: A dynamic alloc array of strings, with the final element being NULL.
**/
char **sshell_split_line(char *line)
{
	char *delimiters = " \t\r\n";
/* Token delimiters definition (spaces, tabs, line breaks)*/
	char *token;
	int length = 0;
	int capacity = 16;
/* Initial memory allocation for the token array* */
	char **tokens = malloc(capacity * sizeof(char *));

	if (!tokens)
	{
		perror("sshell");
		exit(1);
	}
	token = strtok(line, delimiters);
/* Retrieving the first token */
/* Loop to retrieve all tokens in the string*.*/
	while (token != NULL)
/* Adding the token to the token table */
	{
		tokens[length] = token;
		length++;
/* Check if the maximum capacity of the array has been reached*/
		if (length >= capacity)
/* if max capacity, realloc of mem for tok tabl with new capacity */
		{
			capacity = (int) (capacity * 1.5);
			tokens = realloc(tokens, capacity * sizeof(char *));
			if (!tokens) /*check memory */
			{
			perror("sshell");
			exit(1);
			}
		}
	token = strtok(NULL, delimiters); /* take next token */
	}
	tokens[length] = NULL; /* add last null element at the end of array */
	return (tokens); /* return array of token */
}
