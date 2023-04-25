#include "shell.h"
/**
 * read_line - function that read the commande line
 * Return: char*
 */
// Lit une ligne de texte depuis l'entrée standard (stdin) et renvoie un pointeur vers la chaîne de caractères correspondante
	char *read_line(void)
{
	// Initialise le pointeur 'line' à NULL et la taille du tampon 'buflen' à 0
	char *line = NULL;
	size_t buflen = 0;

	// Lit une ligne de texte depuis l'entrée standard et stocke la chaîne de caractères dans 'line', en augmentant dynamiquement la taille du tampon si nécessaire
	ssize_t len = getline(&line, &buflen, stdin);

	// Si une erreur s'est produite lors de la lecture de la ligne, affiche un message d'erreur et quitte le programme
	if (len < 0)
	{
		perror("shell");
		free(line);
		exit(0);
	}

	// Retourne la chaîne de caractères lue depuis l'entrée standard
	return (line);
}
