#include "shell.h"

/**
 * free_path - frees the linked list associated with the PATH.
 * @head: pointer to the head node of the list.
 *
 * Return: void.
 */
void free_path(path_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
		free_path(head->next);
	free(head->ptr);
	free(head);
}

/**
 * free_env - frees the linked list associated with the env.
 * @head: pointer to the head node of the list.
 *
 * Return: void.
 */
void free_env(path_t *head)
{
	if (head == NULL)
		return;
	if (head->next != NULL)
		free_path(head->next);
	free(head);
}
