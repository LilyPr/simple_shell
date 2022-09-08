#include "shell.h"

/**
 * prompt - Display Shell Prompt
 */
void prompt(void)
{
	PRINTER("$ ");
}
/**
 * print_error - Display Error Based on Command and How Many Time Shell Looped
 * @input:User Input
 * @count:Simple Shell Count Loop
 * @argv:Program Name
 * Return: Void
 */
void print_error(char *input, int count, char **argv)
{
	char *er;

	PRINTER(argv[0]);
	PRINTER(": ");
	er = _itoa(count);
	PRINTER(er);
	free(er);
	PRINTER(": ");
	PRINTER(input);
	PRINTER(": not found\n");
}
