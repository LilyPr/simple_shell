#include "shell.h"
/**
 * cwd_search - look for current working dir
 * @filename: file name
 * @er: for display an error
 * Return: current working dir
 */

char *cwd_search(char *filename, char *er)
{
	DIR *dir;
	struct dirent *sd;
	char *ret;
	int data = 0;
	int i = 0;

	while (filename[data])
		data++;
	ret = malloc(sizeof(char) * (data + 3));
	dir = opendir(".");
	if (!dir)
	{
		printf("Error! Unable to open directory.\n");
		exit(0);
	}
	while ((sd = readdir(dir)))
	{
		for (i = 0; sd->d_name[i] && filename[i]; i++)
		{
			if (sd->d_name[i] != filename[i])
				break;
			if (i == (len - 1) && !(sd->d_name[i + 1]))
			{
				strcpy(ret, "./");
				strcat(ret, filename);
				closedir(dir);
				if (!(access(ret, X_OK)))
					return (ret);
				write(2, er, 5);
			}
		}
	}
	closedir(dir);
	return (er);
}
