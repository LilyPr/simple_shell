#include "shell.h"

/**
 * _env - sets a linked list for the enviornment
 * Return: head of the linked list
*/
path_t *_env(void)
{
	path_t *head;
	path_t *flow;
	int count = 0;

	flow = malloc(sizeof(path_t)); /*linked list*/
	if (!flow)
	{
		free(flow);
		return (NULL);
	}
	head = flow; /*pointer to beginning of list */
	while (environ[count]) /*enviorn makes user enviornment*/
	{
		flow->ptr = _strdup(environ[count]);/*dup variable into list*/
		if (environ[count + 1] != NULL)
		{
			flow->next = malloc(sizeof(path_t));
			flow = flow->next;
		}
		count++;
	}
	flow->next = NULL;
	return (head);
}

/**
 * find_enve - searches for a match in the enviornment list
 * @var: argument passed in
 * Return: pointer to matched variable
*/
char *find_enve(char *var)
{
	char *area, *keep;
	path_t *node;
	unsigned int count;

	area = NULL;
	node = environment; /*runs enviornment list (man env)*/

	while (node)
	{
		count = 0;
	/*while there are arguments*/
		while (var[count])
		{
			if (var[count] != node->ptr[count])
				break;
			if (var[count + 1] == '\0' && node->ptr[count + 1] == '=')
			area = node->ptr;
			count++;
		}
		/** once we find a match exit loop*/
		if (area)
			break;
		node = node->next;
	}
	keep = malloc(sizeof(char) * (_strlen(keep) + 1));
	if (!keep)
		/*free (keep);*/
		return (NULL);
	_strcpy(keep, area);
	return (keep);
}
/**
 * match_enve - finds the matching enviornment with the argument passed
 * @input: argument passed
 * Return: 0 on success, -1 if no match
*/
int match_enve(char *input)
{
	path_t *flower;
	int count = 0, count2 = 0;

	flower = environment; /*setting enviornment*/
	while (flower)
	{
		count = 0;
		while (input[count] == flower->ptr[count])
		{
			count++;
			if (input[count + 1] == '\0' && (flower->ptr)[count + 1] == '=')
				return (count2);
		}
		count2++;
		flower = flower->next;
		if (flower == NULL)
			return (-1);
	}
	return (count2);
}
