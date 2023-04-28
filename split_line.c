#include "main.h"

/**
 * sshell_split_line - Splits line into tokens using whitespace as delimiters.
 * @line: Splits line into an array of tokens, using whitespace as delimiters.
 * Dynamically resizes to fit any number of tokens.
 * Return: A dynamic alloc array of strings, with the final element being NULL.
 */
char **sshell_split_line(char *line)
{
    const char *delimiters = " \t\r\n";
    /* Définition des délimiteurs de tokens (espaces, tabulations, sauts de ligne) */
    char *token;
    int length = 0;
    int capacity = 16;
    /* Allocation initiale de mémoire pour le tableau de tokens */
    char **tokens = malloc(capacity * sizeof(char *));
    if (!tokens)
    {
        perror("sshell");
        exit(1);
    }
    token = strtok(line, delimiters);
    /* Récupération du premier token */
    /* Boucle pour récupérer tous les tokens dans la chaîne */
    while (token != NULL)
    {
        /* Ajout du token au tableau de tokens */
        tokens[length] = strdup(token);
        if (!tokens[length])
        {
            perror("sshell");
            exit(1);
        }
        length++;
        /* Vérification si la capacité maximale du tableau a été atteinte */
        if (length >= capacity)
        {
            capacity *= 2;
            tokens = realloc(tokens, capacity * sizeof(char *));
            if (!tokens)
            {
                perror("sshell");
                exit(1);
            }
        }
        token = strtok(NULL, delimiters); /* Récupération du token suivant */
    }
    tokens[length] = NULL; /* Ajout d'un dernier élément nul à la fin du tableau */
    return tokens; /* Retourne le tableau de tokens */
}
