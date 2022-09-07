#include "shell.h"
/**
 * count_wrd - counts words
 * @s: string
 * Return: number or words
 */
int count_wrd(char *s)
{
	int l;
	int count = 1;
	char delimeter = ' ';

	if (!s)
		return (-1);

	for (l = 0; s[l] != '\0'; l++)
	{
		if (s[l] == delimeter)
			count++;
	}
	return (count);
}

/**
 * bridge_line - tokenizes a buffer
 * @buffer: args to tokenize
 * @delimeter: delemiter ""
 * Return: pointer to array of tokens
*/

char **bridge_line(char *buffer, char *delimeter)
{
	char *tokens, *flow;
	int count = count_wrd(buffer);
	int i = 0;
	char **word = malloc(sizeof(char *) * (count + 1));

	if (!word)
	{
		perror("Error\n");
		exit(99);
	}
	flow = _strdup(buffer);
	if (!flow)
	{
		perror("Error\n");
		return (NULL);
	}
	tokens = _strtok(flow, delimeter);

	while (tokens)
	{
		word[i] = malloc(sizeof(char) * (_strlen(tokens) + 1));
		if (!word[i])
		{
			perror("Error");
			while (i >= 0)
			{
				free(word[i]);
				i--;
			}
			free(word);
			return (NULL);
		}
		_strcpy(word[i], tokens);
		i++;
		tokens = _strtok(NULL, delimeter);
	}
	word[i] = NULL;
	free(flow);
	return (word);
}
