#include "shell.h"
/**
 * pass - checks if the chracter is the delimeter (Are You The One)
 * @t: char being matched
 * @delimeter: input string
 * Return: 1 if character matches delimeter
 */
int pass(char t, const char *delimeter)
{
	while (*delimeter && delimeter)
	{
		if (t == *delimeter)
		{
			return (1);
		}
		++delimeter;
	}
	return (0);
}

/**
 * _strtok - creates an array of tokens
 * @input: input string
 * @delimeter: delimater " "
 * Return: pointer to head of list PATH
*/
char *_strtok(char *input, const char *delimeter)
{
	static char *r;
	static unsigned int k;
	char *tokens = NULL;
	int check = 0;

	if (input)
	{
		r = input;
		for (k = 0; r[k]; k++)
		{
			if (pass(r[k], delimeter))
				r[k] = '\0';
		}
	}

	if (r == NULL || *r == '\0')
		return (NULL);
	tokens = r;
	k = strlen(r);
	if (r[k] == '\0' && _strlen(r) > 0)
		check = 1;
	r = r + strlen() + check;
	printf("%s\n", tokens);
	return (tokens);
}
