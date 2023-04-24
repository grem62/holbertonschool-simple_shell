#include "main.h"
/**
 * main - program main of the shell
 * Return: 0
 */
int main(void)
{
    char *buffer = NULL; // Pointeur vers le buffer de lecture
    size_t buf_size = 2048; // Taille initiale du buffer
    char **cmd; // Pointeur vers un tableau de chaînes de caractères
    struct stat status; // Structure pour stocker les informations sur un fichier

    // Allouer la mémoire pour le buffer
    buffer = calloc(sizeof(char), buf_size);
    if (buffer == NULL)
    {
        perror("Malloc failure");
        return (EXIT_FAILURE);
    }

    signal(SIGINT, SIG_IGN); // Configurer le signal SIGINT pour être ignoré

    // Lire les commandes depuis l'entrée standard jusqu'à la fin du fichier
    while (getline(&buffer, &buf_size, stdin) > 0)
    {
        // Diviser la ligne en un tableau de chaînes de caractères
        cmd = strtok(buffer, " \t\r\n");

        if (!cmd) // Si la commande est null, quitter le programme avec EXIT_SUCCESS
            exit(EXIT_SUCCESS);

        if (strcmp(cmd[0], "exit") == 0) // Si la commande est "exit", quitter le programme avec exit(0)
        {
            free_array(cmd);
            exit(0);
        }

        if (strcmp(cmd[0], "env") == 0) // Si la commande est "env", afficher les variables d'environnement avec print_env()
        {
            free_array(cmd);
            print_env();
            continue; // Continuer la boucle while
        }

        if (stat(cmd[0], &status) != 0) // Si la commande n'est pas un fichier existant, chercher son chemin absolu avec get_absolute_path()
            path_cmd(cmd);

        if (cmd[0] == NULL) // Si la commande n'est toujours pas trouvée, afficher "Command not found"
            printf("Command not found\n");
        else
            exec_comd(cmd); // Exécuter la commande avec exec_comd()

        free_array(cmd); // Libérer la mémoire allouée pour le tableau de chaînes de caractères
    }

    free(buffer); // Libérer la mémoire allouée pour le buffer
    exit(EXIT_SUCCESS); // Quitter le programme avec succès
    return (0);
}

