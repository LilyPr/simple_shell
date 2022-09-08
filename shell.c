#include "shell.h"

/**
 * main - Simple Shell (Hsh)
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Exit Value By Status
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int total = 0, status = 1, lis = 0;

	if (argv[1] != NULL)
		file_read(argv[1], argv);
	signal(SIGINT, sign_handle);
	while (status)
	{
		total++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bultin(cmd, input, argv, total);
		}
		else if (check_builtin(cmd) == 0)
		{
			lis = handle_builtin(cmd, lis);
			free_all(cmd, input);
			continue;
		}
		else
		{
			st = check_cmd(cmd, input, total, argv);

		}
		free_all(cmd, input);
	}
	return (status);
}
/**
 * check_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	built_t show[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int i = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((show + i)->code)
	{
		if (_strcmp(cmd[0], (show + i)->code) == 0)
			return (0);
		i++;
	}
	return (-1);
}
/**
 * set_env - Creat Array of Enviroment Variable
 * @env: Array of Enviroment Variable
 * Return: Void
 */
void set_env(char **env)
{
	int i;

	for (i = 0; environ[i]; i++)
		env[i] = _strdup(environ[i]);
	env[i] = NULL;
}
