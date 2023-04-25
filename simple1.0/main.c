#include "main.h"

/**
 *main - entry point
 *Return: return void
*/

int main(void)
{
	while (true) /*Boucle while infinie*/
	{
		printf("$ "); /*Afficher le symbole "$ " */
		char *line = sshell_read_line();/*Lire la ligne d'entrée de l'utilisateur*/
		char **tokens = sshell_split_line(line);/*spliter ligne d'entrée*/

		if (tokens[0] != NULL)
		{
			shell_exec(tokens);/*Exécuter la commande avec shell_exec*/
		}

		free(tokens);/*Libérer la mémoire allouée pour "tokens"*/
		free(line);/*Libérer la mémoire allouée pour la chaîne de caractères*/
	}
}
