#include "shell.h"
/**
 *  pr_error - Print Custome Error
 * @argv:Program Name
 * @c:Error Count
 * @cmd:Command
 * Return: Void
 */
void pr_error(char **argv, int c, char **cmd)
{
	char *er = _itoa(c);

	PRINTER(argv[0]);
	PRINTER(": ");
	PRINTER(er);
	PRINTER(": ");
	PRINTER(cmd[0]);
	PRINTER(": Invalid number: ");
	PRINTER(cmd[1]);
	PRINTER("\n");
	free(er);
}
