#include "main.h"

/* -------Commandes intégrées--------*/
 
// Quitter le shell.
void shell_exit(char **args)
	{
 	exit(0);
	}
 
// Changer le répertoire de travail.
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
 
// Affiche le texte d'aide du shell.
void shell_help(char **args)
{
 char *helptext =
"« Simple shell – Projet Holberton - Scholl. »"
 " Les commandes suivantes sont intégrées : \n "
 " cd Changer le répertoire de travail. \n "
 " exit Quitte le shell. \n "
 " help Imprimer ce texte d'aide. \n "
;
 printf("%s", helptext);
}
 
/*--------Lanceur de processus/commandes-----------*/
 
void shell_exec(char **args)
{
    int i;
 
 for (i = 0; i < sshell_num_builtins(); i++) 
    {
        if (strcmp(args[0], builtins[i].name) == 0)
            {
            builtins[i].func(args);
            return;
            }
    }
 
 pid_t child_pid = fork();
 
 if (child_pid == 0) {
 execvp(args[0], args);
 perror("sshell");
 exit(1);
 } else if (child_pid > 0) {
 int status;
 do {
 waitpid(child_pid, &status, WUNTRACED);
 } while (!WIFEXITED(status) && !WIFSIGNALED(status));
 } else {
 perror("sshell");
 }
}
 
// -----------------------------------------------------------------------------
// Analyseur d'entrée.
// -----------------------------------------------------------------------------
 
// Tokenise une chaîne, en la divisant sur les caractères d'espacement. En tête et en queue
// les espaces blancs sont ignorés. Les caractères d'espacement consécutifs sont traités comme un
// délimiteur unique. La valeur de retour est un tableau de chaîne terminé par NULL
// pointeurs qui doivent être libérés une fois que nous en avons terminé.

char** sshell_split_line(char *line) 
{
 int length = 0;
 int capacity = 16;
 
 char **tokens = malloc(capacity * sizeof(char*));
 if (!tokens) {
 perror("sshell");
 exit(1);
 }
 
 char *delimiters = " \t\r\n";
 char *token = strtok(line, delimiters);
 
 while (token != NULL) {
 tokens[length] = token;
 length++;
 
 if (length >= capacity) {
 capacity = (int) (capacity * 1.5);
 tokens = realloc(tokens, capacity * sizeof(char*));
 if (!tokens) {
 perror("sshell");
 exit(1);
 }
 }
 
 token = strtok(NULL, delimiters);
 }
 
 tokens[length] = NULL;
 return tokens;
}
 
// Lit une seule ligne d'entrée à partir de stdin. La valeur de retour est un pointeur de chaîne
// qui doit être libéré une fois que nous en avons terminé.
char* sshell_read_line()
{
 char *line = NULL;
 size_t buflen = 0;
 errno = 0;
 ssize_t strlen = getline(&line, &buflen, stdin);
 if (strlen < 0) {
 if (errno) {
 perror("sshell");
 }
 exit(1);
 }
 return line;
}
 
// -----------------------------------------------------------------------------
// Point d'entrée.
// -----------------------------------------------------------------------------
 
int main() 
{
 while (true) {
 printf("$ ");
 char *line = sshell_read_line();
 char **tokens = sshell_split_line(line);
 
 if (tokens[0] != NULL) {
 shell_exec(tokens);
 }
 
 free(tokens);
 free(line);
 }
}