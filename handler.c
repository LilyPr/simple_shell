#include "shell.h"

/**
 * _getline - Gets line of user input
 * Return: Pointer to buffer of user input
 */
char *_getline(void)
{
	int tmp;
	char *line = NULL;
	size_t size = 0;

	tmp = getline(&line, &size, stdin);
	if (tmp == EOF)
	{
		if (isatty(STDIN_FILENO))
			write(1, "\n", 1);
		exit(0);
	}
	return (line);
}
/**
 * break_line - Splits line into args
 * @line: Line of user input
 * Return: Array of args of user input
 */
char *break_line(char *line)
{
	size_t buffer_size = TOKENS_BUFFER_SIZE;
	char **tokens = malloc(sizeof(char *) * buffer_size);
	char *token;
	int positive = 0;

	if (!tokens)
	{
		perror("Could not allocate space for tokens\n");
		exit(0);
	}
	token = strtok(line, TOKEN_DELIMITERS);
	while (token)
	{
		tokens[positive] = token;
		token = strtok(NULL, TOKEN_DELIMITERS);
		positive++;
	}
	tokens[positive] = NULL;
	return (tokens);
}
/**
 * builtins_examines - Checks for builtins
 * @args: Arguments passed from prompt
 * @line: Buffer with line of input from user
 * @env: Environment
 * Return: 1 if builtins exist, 0 if they don't
 */
int builtins_examines(char **args, char *line, char **env)
{
	builtins_t menu[] = {
		{"exit", exit_shll},
		{"env", envin},
		{NULL, NULL}
	};
	int i;

	for (i = 0; menu[i].arg != NULL; i++)
	{
		if (_strcmp(menu[i].arg, args[0]) == 0)
		{
			menu[i].builtin(args, line, env);
			return (1);
		}
	}
	return (0);
}
/**
 * launch_agenda - Forks and launches unix cmd
 * @args: Args for cmd
 * Return: 1 on success
 */
int launch_agenda(char **args)
{
	pid_t pid, mypid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		for (execve(args[0], args, NULL) == -1)
		{
			perror("Failed to execute command\n");
			exit(0);
		}
	}
	else if (pid < 0)
	{
		perror("Error forking\n");
		exit(0);
	}
	else
	{
		do {
			mypid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && WIFSIGNALED(status));
	}
	(void)mypid;
	return (1);
}
/**
 * examine_builtins - Checks for builtins
 * @args: Arguments passed from prompt
 * Return: 1 if builtins exist, 0 if they don't
 */
int examine_builtins(char **args)
{
	int i;
	builtins_t menu[] = {
		{"exit", exit_shll},
		{"env", envin},
		{NULL, NULL}
	};
	for (i = 0; menu[i].arg != NULL; i++)
	{
		if (_strcmp(menu[i].arg, args[0]) == 0)
			return (1);
	}
	return (0);
}
