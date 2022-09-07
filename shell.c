#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    while (true)
    {
	    printf("> ");
	    char *line = shell_read_line();
	    char **tokens = shell_split_line(line);

        if (tokens[0] != NULL)
	{
		shell_exec(tokens);
        }
	free(tokens);
	free(line);
    }
}
