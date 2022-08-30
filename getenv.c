#include "shell.h"

/**
 * _getenv - gets env of input
 * @env: input
 * Return: env without =
 */
char *_getenv(char *env)
{
	int i = 0, m = 0;
	char *tmp, *res;

	while (environ[i] != NULL)
	{
		if (_strcmp(environ[i], env) == 0)
			tmp = environ[i];
		 i++;
	}
	while (tmp[m] != '\0')
	{
		if (_strcmp(tmp, env) == 0)
			res = _strstr(tmp, "/");
		m++;
	}
	return (res);
}
