#include "main.h"

/**
 * shell_exec - Executes a command using a builtin or a new process
 * @args: An array of strings representing the command and its arguments
 * Return: Returns 1 if the command is a builtin and was executed, 0 otherwise
 */

int shell_exec(char **args)
{
	int i;
	pid_t child_pid;
	int status;
	int is_builtin = 0;
	/* Vérification si la commande est un builtin */
	for (i = 0; i < sshell_num_builtins(); i++)
	{
		if (strcmp(args[0], builtins[i].name) == 0)
		{
			builtins[i].func(args);
			is_builtin = 1;
			break;
		}
	}
	if (!is_builtin)
	{
		/* Création d'un nouveau processus fils */
		child_pid = fork();

		if (child_pid == 0)
		{
			/* Dans le processus fils, exécution de la commande */
			execvp(args[0], args);
			perror("sshell");
			exit(1);
		}
		else if (child_pid > 0)
		{
			/* Dans le processus parent, attente de la fin du processus fils */
			do {
				waitpid(child_pid, &status, WUNTRACED);
			} while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
		else
		{
			perror("sshell");
			return (0);
		}
	}
	return (is_builtin);
}
