#include "main.h"

/* exit shell with exit command */
void shell_exit(char **args)
	{
 	exit(0);
	}
 
/* repertory of shell */
void shell_cd(char **args) 
{
 	if (args[1] == NULL) 
	{
 	fprintf(stderr, "sshell: cd: missing argument\n");
 	}
 	else 
	{
 		if (chdir(args[1]) != 0) 
		{
 		perror("sshell: cd");
 		}
 	}
}
 
/* print help of the shell */
void shell_help(char **args)
{
 char *helptext =
"« Simple shell – Projet Holberton - Scholl. »"
 " The following commands are integrated : \n "
 " cd change working directory. \n "
 " exit exit the shell. \n "
 " help print the help text . \n "
;
 printf("%s", helptext);
}
