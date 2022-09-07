#include "shell.h"
/**
 * _exec - compares arguments to executable commands
 * @args: argument recieved
 * @coral: shell
 * Return: 1
*/
int _exec(char **args, char *coral)
{
	char *xc;

	if (args[0][0] == '/')
	{
		if (execve(args[0], args, NULL) == -1)
			errenous(args, corall, 3);
	}
	else
	{
		ex = (path_check(the_path, args[0]));
		if (!xc)
			errenous(args, coral, 1);
		if (execve(ex, args, NULL) == -1)
			errenous(args, coral, 2);
	}
	return (1);
}
/**
 * _execute- forks the current process and exectues the command
 * @args: argument recieved
 * @coral: shell
 * Return: -1, 0, 1
*/

int _execute(char **args, char *coral)
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == 0)
	{
		_exec(args, corall);
		exit(0);
	}
	else if (child_pid == -1)
	{
		perror("Error: there is no fork");
		exit(99);
	}
	else
	{
		do {
			waitpid(child_pid, &status, WUNTRACED);
		} while (WIFEXITED(status) == 0 && WIFSIGNALED(status) == 0);
	}
	return (1);
}
