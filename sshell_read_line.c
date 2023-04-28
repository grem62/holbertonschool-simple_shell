#include "main.h"



char *sshell_read_line(void)
{
    char *line = NULL;
    size_t bufsize = 0;
    ssize_t nread;

    /* Afficher le prompt */
    write(STDOUT_FILENO, "$ ", 2);

    /* Lire la ligne d'entrée */
    nread = getline(&line, &bufsize, stdin);

    /* Vérifier si une erreur s'est produite */
    if (nread == -1)
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
    if (nread > 0 && line[nread - 1] == '\n')
    {
        line[nread - 1] = '\0';
    }

    return line;
}















