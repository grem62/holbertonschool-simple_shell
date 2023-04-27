#include "main.h"

/**
 * sshell_read_line - fonction permet de lire la lige écrite par l'utilisateur
 * Return: la ligne tapée par l'utilisateur
 */

char *sshell_read_line(void)
{
	char *line = NULL; /* Initialisation de la chaîne de caractères */
	size_t buflen = 0; /* Initialisation de la taille de la chaîne */
	ssize_t len = 0;

	errno = 0; /* Réinitialiser la variable errno à 0 */

	/* Utiliser la fonct getline pour lire la ligne entrée par l'utili */
	/* et stocker la chaîne de caractères dans la variable line */

	len = getline(&line, &buflen, stdin);

	/* Vérifier si getline() a retourné une erreur */

	if (len < 0)
	{
		if (errno)
		{
			perror("sshell");
		}
		free(line); /* Libération de la mémoire allouée par getline() */
		return (NULL); /* Quitter la fonction avec une erreur */
	}

	/* Si la ligne est vide ou ne contient que des espaces, renvoyer NULL */
	if (len == 1 && line[0] == ' ')
	{
		free(line); /* Libération de la mémoire allouée par getline() */
		return (NULL); /* Sortie dela fonction sans erreur */
	}

	/* Vérification si la mémoire a été allouée correctement */
	if (line == NULL)
	{
		perror("malloc");
		return (NULL); /* Sortie de la fonction avec une erreur */
	}

	return (line); /* Return la chaîne de caractères lue */
}
