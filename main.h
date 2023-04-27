#ifndef MAIN_H
#define MAIN_H

/*====Bibliotheques====*/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>

/*====Structure====*/

/**
 * struct builtin - Structure for handling builtin shell commands.
 * @name: name of the built-in command
 * @func: pointer to the built-in command function
 *
 * Description: This structure defines a built-in shell command.
 */
 struct builtin
{
	char *name;
	void (*func)(char **args);
};


/*====Variables globales====*/
/**
 * struct builtin - Structure pour la gestion des commandes shell intégrées.
 * @name: Le nom de la commande.
 * @func: Un pointeur vers la fonction qui implémente la commande.
 *
 * Description : Cette structure contient les info pour chaque cmd shell intégrée.
 */
extern struct builtin builtins[];

/*====fonction====*/

void shell_help(char **args);
void shell_exit(char **args);
void shell_cd(char **args);
int sshell_num_builtins(void);
int shell_execute_external(char **args);
int shell_exec(char **args);
char **sshell_split_line(char *line);
char *sshell_read_line(void);
int main(void);

#endif
