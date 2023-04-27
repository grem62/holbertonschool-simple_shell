#include "main.h"

/**
 * shell_execute_external - Executes a command in a new process
 * @args: An array of strings representing the command and its arguments
 * Return: Returns 0 if the command was executed successfully, 1 otherwise
 */
int shell_execute_external(char **args)
{
	int status;
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == 0)
	{
		execvp(args[0], args);
		perror("sshell");
		exit(1);
	}
	else if (child_pid > 0)
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	else
	{
		perror("sshell");
		return (1);
	}

	return (0);
}

/**
 * shell_exec - Executes a command using a builtin or a new process
 * @args: An array of strings representing the command and its arguments
 * Return: Returns 1 if the command is a builtin and was executed, 0 otherwise
 */
int shell_exec(char **args)
{
	int i;
	int is_builtin = 0;

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
		shell_execute_external(args);
	}

	for (i = 0; args[i] != NULL; i++)
	{
		free(args[i]);
	}
	free(args);

	return (is_builtin);
}
