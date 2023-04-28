#include "main.h"

/**
 *main - entry point
 *Return: return void
*/

int main(void)
{
	char line[MAX_INPUT_LENGTH];
	char **tokens = NULL;


	while (true) /*Boucle while infinie*/
	{
		write(STDOUT_FILENO, "$ ", 1);
		if (fgets(line, MAX_INPUT_LENGTH, stdin) == NULL) /* Lire la ligne d'entrée de l'utilisateur */
			continue;

		tokens = sshell_split_line(line);/*spliter ligne d'entrée*/
		if (tokens == NULL)
		{
			continue;
		}

		if (tokens[0] != NULL)
		{
			shell_exec(tokens);/*Exécuter la commande avec shell_exec*/
		}

		free(tokens);/*Libérer la mémoire allouée pour "tokens"*/
	}
}
