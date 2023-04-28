#include "main.h"



char *sshell_read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t len;

    /* Lire la ligne d'entrée */
    len = getline(&line, &bufsize, stdin);

    /* Vérifier si une erreur s'est produite */
    if (len == -1)
    {
        /* Si la fin de fichier est atteinte, quitter le programme */
        if (feof(stdin))
        {
            exit(EXIT_SUCCESS);
        }
        /* Sinon, afficher une erreur */
        perror("getline");
        exit(EXIT_FAILURE);
    }

    /* Supprimer le retour à la ligne final si présent */
    if (len > 0 && line[len - 1] == '\n')
    {
        line[len - 1] = '\0';
    }

    return line;
}















