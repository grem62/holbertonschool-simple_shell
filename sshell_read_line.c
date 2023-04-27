#include "main.h"

/**
 *sshell_read_line - fonction permet de lire la lige écrit par l'utilisateur
 *Return: la ligne tapé par l'utilisateur
*/


char *sshell_read_line(void)
{
	char *line = NULL;/*Initialisation de la chaîne de caractères*/
	size_t buflen = 0;/*Initialisation de la taille de la chaine*/
	ssize_t len = 0;

	errno = 0;/*Réinitialiser la variable errno à 0*/

	/*Utiliser la fonction getline pour lire la ligne entrée par l'utilisateur*/
	/* et stocker la chaîne de caractères dans la variable line*/

	len = getline(&line, &buflen, stdin);

	/*Vérifier si getline() a retourné une erreur*/

	if (len < 0)
	{
		if (errno)
		{
			perror("sshell");
		}
			return (NULL); /*Quitter le programme */
	}
/* si la ligne est vide ou ne contient que des espaces, renvoyer NULL */
		if (len == 1 && line[0] == ' ')
		{
		free(line); /* libération de la mémoire allouée par malloc() */
		return (NULL); /* sortie de la fonction sans erreur */
		}

/* vérification si la mémoire a été allouée correctement */
	if (line == NULL)
	{
	perror("malloc");
	return (NULL); /* sortie de la fonction avec une erreur */
	}
	return (line);/*Retourner la chaîne de caractère depuis l'entrée standard*/
}
