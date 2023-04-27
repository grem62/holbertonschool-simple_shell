#include "main.h"
/**
 * builtins - structure pour la gestion des commandes shell intégrées.
 * @shell_help: pointeur vers la fonction help.
 * @shell_exit: pointeur vers la fonction exit.
 * @shell_cd: pointeur vers la fonction cd.
 */
struct builtin builtins[] = {
	{"help", shell_help},
	{"exit", shell_exit},
	{"cd", shell_cd}
};

