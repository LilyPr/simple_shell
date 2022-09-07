#include "shell.h"
/**
 * shell_exit - exit current process
 * @args: arguments
 * @input: input
 * Return: nothing
*/
void shell_exit(char **args, char *input)
{
		unsigned int l = 0;

		if (input)
			free(input);
		if (args)
		{
			while (args[l])
			{
				if (args[l])
					free(args[l]);
				l++;
			}
			free(args);
		}
		free_path(the_path);
		free_path(environment);
		exit(0);
}

/**
 * print_enviornment - prints enviornment
 * Return: 0
*/
void print_environ(void)
{
	path_t *node;

	node = environment;
	while (node)
	{
		write(1, node->ptr, _strlen(node->ptr));
		write(1, "\n", 1);
		node = node->next;
	}
}
