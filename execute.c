#include "shell.h"

/**
 * execute_agenda - Executes binary or builtin
 * @args: Argument buffer
 * @line: Line buffer
 * @env: Environment
 * @rise: Helps decide what code to run
 * Return: 1 if success
 */
int execute_agenda(char **args, char *line, char **env, int rise)
{
	int status;

	if (args[0] == NULL)
		return (1);
	if (rise == 1)
	{
		if (check_for_builtins(args, line, env) == 1)
			return (1);
	}
	status = launch_agendag(args);
	return (status);
}
