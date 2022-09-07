#include "shell.h"
/**
  * _enve - creates a new enviornment variable from input
  * @s: input string
  * @value: value of new variable
  * Return: 0
*/

void _enve(char *s, char *value)
{
	path_t *variable, *copy, *node;
	char *val, *newenv;
	int va_len = 0, length = 0, count = 0;

	if (!str || !value)
	{
		perror("enviornment variable not passed");
		exit(1);
	}
	length = match_enve(s);
	variable = malloc(sizeof(path_t));
	if (!variable)
		perror("error, error, error");
	val = _strcat(s, "=");
	va_len = _strlen(val);
	newenv = _realloc(val, va_len, (va_len + _strlen(value) + 1));
	_strncpy(newenv, value, va_len);
	copy = environment;
	node = environment;
	if (length >= 0)
	{
		while (count != (length - 1))
		{
			node = node->next;
			copy = copy->next;
			count++;
		}
		copy = copy->next;
		variable->ptr = newenv;
		variable->next = node->next->next;
		node->next = variable;
		free(copy);
	}
	else
	{
		while (node->next != NULL)
			node = node->next;
		variable->ptr = newenv;
		node->next = variable;
		variable->next = NULL;
	}
	free(val);
}
