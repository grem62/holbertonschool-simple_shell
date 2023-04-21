#include "shell.h"

/**
 * path_cmd - Search in $PATH for executable command
 * @cmd: parsed input
 * Return: 0 on success otherwise 1
 */

int path_cmd(char **cmd)
{
	char *path, *value, cmd_path;
	struct stat buf;

	path = _getenv("PATH")
		value = _strtok(path, ":");
	while (value != NULL)
	{
		cmd_path = build(*cmd, value);
		if (stat(cmd_path, &buf) == 0)
		{
			*cmd = strdup(cmd_path);
			free(cmd_path);
			free(path);
			return (0);
		}
		free(cmd_path);
		value = _strtok(NULL, ":");
	}
	free(path);
	return (1);
}

/**
 * build - build command
 * @token: executable command
 * @value: directory containing command
 * Return: parsed full path od command or NULL case failed
 */

char *build(char *token, char *value)
{
	char *cmd;
	size_t len;

	len = _strlen(value) + _strlen(token) + 2;
	cmd = malloc(sizeof(char) * len);
	if (cmd == NULL)
	{
		return (NULL);
	}

	memset(cmd, 0, len);

	cmd = _strcat(cmd, value);
	cmd = _strcat(cmd, "/");
	cmd = _strcat(cmd, token);

	return (cmd);
}

/**
 * _getenv - gets the value of environment variable by name
 * @name: environment variable name
 * Return: the value of the environment variable otwerwise NULL
 */

char *_getenv(char *name)
{
	size_t n1, v1;
	char *value;
	int i, x, j;

	n1 = strlen(name);
	for (i = 0; environ[i]; i++)
	{
		if (_strcmp(name, environ[i], n1) == 0)
		{
			v1 = _strlen(environ[i]) - n1;
			value = malloc(sizeof(char) * v1);
			if (!value)
			{
				free(value);
				perror("unable to alloc");
				return (NULL);
			}

			j = 0;
			for (x = n1 + 1; environ[i][x]; x++, j++)
			{
				value[j] = environ[i][x];
			}
			value[j] = '\0';
			return (value);
		}
	}
	return (NULL);
}
