#include "shell.h"
/**
 * _readline - reads the line
 * Return: 0
*/
char *_readline(void)
{
	char *line = NULL;
	size_t buffersize = 0; /*will change according to input*/

	write(1, "$ ", 2);
	if (getline(&line, &buffersize, stdin) <= 0)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "\n", 1);
		shell_exit(NULL, line);
	}
	return (line);
}
