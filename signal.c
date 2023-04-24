#include "main.h"
/**
 * SI_INT - functio signal handler
 * @signal  : input
 */
void sigint_handler(int signal)
{
	if (signal == SIGINT)
	{
		putchar('\n');
			write(STDOUT_FILENO, "$ ", 2);

	}
}
