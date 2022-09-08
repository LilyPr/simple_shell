#include "shell.h"
/**
 * file_check - Read Command From File
 * @filename:Filename
 * @argv:Program Name
 * Return: -1 or  0
 */

void file_read(char *filename, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	fp = fopen(filename, "r");
	if (fp == NULL)
	{
		exit(EXIT_FAILURE);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		count;
		file_check(line, count, fp, argv);

	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}
/**
 * file_check - PARSE Check Command Fork Wait Excute in Line of File
 * @line: Line From A File
 * @counter:Error Counter
 * @fp:File Descriptor
 * @argv:Program Name
 * Return : Excute A line void
 */
void file_check(char *line, int count, FILE *fp, char **argv)
{
	char **cmd;
	int lis = 0;

	cmd = parse_command(line);

		if (_strncmp(cmd[0], "exit", 4) == 0)
		{
			exit_bultinfile(cmd, line, fp);
		}
		else if (check_builtin(cmd) == 0)
		{
			lis = handle_builtin(cmd, st);
			free(cmd);
		}
		else
		{
			lis = check_cmd(cmd, line, count, argv);
			free(cmd);
		}
}
/**
 * exit_bultinfile - Exit Shell Case Of File
 * @line: Line From A File
 * @cmd: Parsed Command
 * @fd:File Descriptor
 * Return : Case Of Exit in A File Line
 */
void exit_bultinfile(char **cmd, char *line, FILE *fd)
{
	int rank, i = 0;

	if (cmd[1] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
		{
			perror("invalid number");
		}
	}
	rank = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(rank);



}
