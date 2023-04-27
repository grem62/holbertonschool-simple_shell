#include "main.h"

/**
 * main - point d'entrée
 *
 * Return: 0 si tout est exécuté correctement
 */
int main(void)
{
	while (true) /* Boucle while infinie */
	{
		char *line;
		char **tokens;

		printf("$ "); /* Afficher le symbole "$ " */
		line = sshell_read_line(); /* Lire la ligne d'entrée de l'utilisateur */

		if (line[0] != '\0') /* Vérifier si la ligne est vide */
		{
			tokens = sshell_split_line(line); /* spliter ligne d'entrée */

			if (tokens[0] != NULL)
			{
				shell_exec(tokens); /* Exécuter la commande avec shell_exec */
				if (strcmp(tokens[0], "exit") == 0) /*check si la commande est "exit" */
				{
					free(tokens); /* Libérer la mémoire allouée pour "tokens" */
					free(line); /* free la mémoire allouée pour la chaîne de caractères */
					return (0); /* Terminer le programme */
				}
			}

			free(tokens); /* Libérer la mémoire allouée pour "tokens" */
		}

		free(line); /* free la mémoire allouée pour la chaîne de caractères */
	}

	return (0);
}
