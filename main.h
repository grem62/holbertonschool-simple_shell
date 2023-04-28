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
 *struct builtin - structure gestionnaire de commande
 *@name: nom de la commande
 *@func: function pouvant être utilisé
*/
struct builtin
{
    char *name;
    void (*func)(char **args);
};

/*====Variables globales====*/

extern struct builtin builtins[];

/*====fonction====*/

void shell_help(char **args);
void shell_exit(char **args);
void shell_cd(char **args);
int sshell_num_builtins(void);
void shell_exec(char **args);
char **sshell_split_line(char *line);
char* sshell_read_line(void);
int main(void);

#endif
