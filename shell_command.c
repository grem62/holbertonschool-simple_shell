
#include "main.h"

/**
 * struct builtin - strucutre of builtin
*/
struct builtin builtins[] = 
{
    {"help", shell_help},
    {"exit", shell_exit},
    {"cd", shell_cd},
};

/*====Implémentation des fonctions utilitaires====*/

/**
* sshell_num_builtins - Renvoie le nombre de commandes enregistrées
* Return: la taille
*/
int sshell_num_builtins(void)
{
	int i = 0;

	while (builtins[i].name != NULL)
	{
		i++;
	}
	return (i);
}

/*====Implementation des builtins====*/

/**
 * shell_help - affiche le guide de commande "aide"
 * @args: array of char
 */
void shell_help(char **args __attribute__((unused)))
{
	int i;

	printf("Simple Shell auteur");
	printf("TARTAR Mickael - LENNE Sebastien - GREMONT Matheo");
	printf("Holberton School LILLE #C20\n");
	printf("Les commandes sont disponibles dans le fichier man:\n");

	for (i = 0; i < sshell_num_builtins(); i++)
	{
		printf("  %s\n", builtins[i].name);
	}

	printf("Tapez man suivi du nom d'une commande pour plus d'informations.\n");
}
/**
 * shell_exit - exit the shell
 * @args: array of char
 */
void shell_exit(char **args __attribute__((unused)))
{
	exit(0);
}
/**
 * shell_cd - cd is the command for list files
 * @args: array of char
 */
void shell_cd(char **args __attribute__((unused)))
{
	if (args[1] == NULL)
	{
		fprintf(stderr, "Erreur : argument attendu pour \"cd\".\n");
	}
	else
	{
		if (chdir(args[1]) != 0)
		{
			perror("Erreur");
		}
	}
}
