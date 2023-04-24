#include "main.h"

/**
 * exec_cmd - function execute the commande
 * @comd: the commande to execute
 */
void exec_comd(char **cmd)
{
	pid_t	pid = 0; /*id du processus */
	int		status = 0; // status du processus enfant

	pid = fork(); // on crée un nouveau processus enfant
	if (pid == -1) // si le fork a échoué
		perror("fork"); /* affiche un message d'erreur*/
	else if (pid > 0) // si on est dans le processus parent
	{
		waitpid(pid, &status, 0); // on attend la fin du processus enfant
		kill(pid, SIGTERM); // on envoie un signal SIGTERM pour terminer le processus enfant
	}
	else // sinon, on est dans le processus enfant
	{
		if (execve(cmd[0], cmd, NULL) == -1) // on exécute la commande passée en paramètre
			perror("shell"); // si ça a échoué, on affiche un message d'erreur
		exit(EXIT_FAILURE); // on quitte le processus enfant avec un code de retour d'erreur
	}
}
