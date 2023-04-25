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

/*====fonction====*/
void shell_help(char **args);
void shell_exit(char **args);
void shell_cd(char **args);
int sshell_num_builtins(void);
void shell_exec(char **args);
char **sshell_split_line(char *line);
char *sshell_read_line();
int main(void);

/*====Structure====*/

/**
 *struct builtin - structure gestionnaire de commande
 *@name: nom de la commande
 *@func: function pouvant être utilisé
*/
struct builtin
{
	char *name;
	void (*func)(char **args);
};

 /*Tableau de commandes intégrées*/
struct builtin builtins[] = {
	{"help", shell_help},
	{"exit", shell_exit},
	{"cd", shell_cd},
};

/**
*sshell_num_builtins - Renvoie le nombre de commandes enregistrées
*Return: la taille
*/
int sshell_num_builtins(void)
{
	return (sizeof(builtins) / sizeof(builtins[0]));
};

#endif
