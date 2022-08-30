#include "shell.h"

/**
 * shell - Infinite loop that runs shell
 * @ac: Arg count
 * @av: args passed to shell at beginning of prog
 * @env: Environment
 * Return: Void
 */
void shell(int ac, char **av, char **env)
{
	char *line;
	char **args;
	int status = 1;
	char *tmp = NULL;
	char *er;
	char *filename;
	int rise;

	er = "Error";
	do {
		prompt();
		line = _getline();
		args = break_line(line);
		rise = link(args[0], args);
		if (rise == 2)
		{
			filename = args[0];
			args[0] = path_finder(args[0], tmp, er);
			if (args[0] == er)
			{
				 args[0] = cwd_search(filename, er);
				 if (args[0] == filename)
					 write(1, er, 5);
			}
		}
		if (args[0] != er)
			status = execute_agenda(args, line, env, rise);
		free(line);
		free(args);
	} while (status);
	if (!ac)
		(void)ac;
	if (!av)
		(void)av;
	 if (!env)
		 (void)env;
}				
