#include "shell.h"

/**
 * handle_builtin - Handle Builtin Command
 * @cmd: Parsed Command
 * @er:statue of last Excute
 * Return: -1 Fail 0 Succes (Return :Excute Builtin)
 */

int handle_builtin(char **cmd, int er)
{
	 builtin_t home[] = {
		{"cd", current_dir},
		{"env", open_env},
		{"help", help_check},
		{"echo", echo_builtin},
		{"history", history_check},
		{NULL, NULL}
	};
	int i = 0;

	while ((home + i)->code)
	{
		if (_strcmp(cmd[0], (home + i)->code) == 0)
		{
			return ((home + i)->home(cmd, er));
		}
		i++;
	}
	return (-1);
}
/**
 * check_command - Excute Simple Shell Command (Fork,Wait,Excute)
 * @cmd:Parsed Command
 * @input: User Input
 * @c:Shell Excution Time Case of Command Not Found
 * @argv:Program Name
 * Return: 1 Case Command Null -1 Wrong Command 0 Command Excuted
 */
int check_command(char **cmd, char *input, int c, char **argv)
{
	int status;
	pid_t pid;

	if (*cmd == NULL)
	{
		return (-1);
	}

	pid = fork();
	if (pid == -1)
	{
		perror("Error");
		return (-1);
	}

	if (pid == 0)
	{
		if (_strncmp(*cmd, "./", 2) != 0 && _strncmp(*cmd, "/", 1) != 0)
		{
			path_check(cmd);
		}

		if (execve(*cmd, cmd, environ) == -1)
		{
			print_error(cmd[0], c, argv);
			free(input);
			free(cmd);
			exit(EXIT_FAILURE);
		}
		return (EXIT_SUCCESS);
	}
	wait(&status);
	return (0);
}
/**
 * sign_handle - Handle ^C
 * @sig:Captured Signal
 * Return: Void
 */
void sign_handle(int sig)
{
	if (sig == SIGINT)
	{
		PRINTER("\n$ ");
	}
}
