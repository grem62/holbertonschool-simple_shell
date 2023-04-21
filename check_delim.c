#include "shell.h"

/**
 * check_delim - checks if a character match any char *
 * @c: character to check
 * @str: string to check
 * Return: 1 success otherwise 0
 */

unsigned int check_delim(char c, const char *str)
{
	/* declare a variable to hold the current index */
	unsigned int i;
	/* loop through the string until we reach the null terminator */
	for (i = 0; str[i] != '\0'; i++)
	{
		/* if the current character matches the delimiter character, return 1 */
		if (c == str[i])
			return (1);
	}
	/* if we didn't find a match, return 0 */
	return (0);
}
