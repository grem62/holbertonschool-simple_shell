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
	return (line);/*Retourner la chaîne de caractère depuis l'entrée standard*/
}
