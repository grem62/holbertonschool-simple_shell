 #include "main.h"
/**
* sshell_split_line - Splits line into tokens using whitespace as delimiters.
* @line: Splits line into an array of tokens, using whitespace as delimiters.
* Dynamically resizes to fit any number of tokens.
* Return: A dynamic alloc array of strings, with the final element being NULL.
**/
char **sshell_split_line(char *line)
{
	char *delimiters = " \t\r\n";
/*Définition délimiteurs token (espaces, tabulations, sauts de ligne)*/
	char *token;
	int length = 0;
	int capacity = 15;
/*Allocation initiale de la mémoire pour le tableau de tokens*/
	char **tokens = malloc(capacity * sizeof(char *));

	if (!tokens)
	{
		perror("sshell");
		exit(1);
	}
	token = strtok(line, delimiters);
/*Récupération du premier token*/
/*Boucle pour récupérer tous les tokens de la chaîne de caractères*/
	while (token != NULL)
/*Ajout du token au tableau de tokens*/
	{
		tokens[length] = token;
		length++;
/*Vérif si capacité maximale du tableau a été atteinte*/
		if (length >= capacity)
/*Si capacité max, réalloc de mém pour tabl de tokens avc nvl capacité*/
		{
			capacity = (int) (capacity * 1.5);
			tokens = realloc(tokens, capacity * sizeof(char *));
/*Vérif si la réallocation de la mémoire a réussi*/
			if (!tokens)
			{
			perror("sshell");
			exit(1);
			}
		}
	token = strtok(NULL, delimiters);
/*Récupération du prochain token*/
	}
	tokens[length] = NULL;
/*Ajout d'un dernier élément NULL pour indiquer la fin du tableau de tokens*/
	return (tokens);
/*Retour le tableau de tokens sépare*/
}
