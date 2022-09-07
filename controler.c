#include "shell.h"

/**
 * rock - takes input from the shell
 * @coral: the shell
 * Return: 0
*/
void rock(char *coral)
{
	char *line;
	char **args;
	int status, i;

	enviornment = _env();
	_path = path_gen();
	count_line = 0;

	status = 1; /*keeps loop running while shell is open */
	while (status)
	{
		signal(SIGINT, sign_handle);
		count_line++;
		line = _readline();/*function to read a line*/
		if (line[0] == '\n')
		{
			free(line);
			continue;
		}
		args = bridge_line(line, "\n"); /*split line into arguments*/
		if (isit_built(args, line) == 1)
			status = _exec(args, colar); /*determine when to exit */

		i = 0;
		while (args[i] != NULL)
		{
			if (args[i])
				free(args[i]);
			i++;
		}
		if (line)
			free(line);
		if (args)
			free(args);
	}
	free_path(_path);
	free_path(environment);
