#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node that should be deleted (starting from 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current;
	unsigned int i = 0;

	if (!head || !*head)
		return (-1);

	current = *head;

	/* Special case: delete first node */
	if (index == 0)
	{
		*head = current->next;
		if (*head)
			(*head)->prev = NULL;
		free(current);
		return (1);
	}

	/* Traverse to the node to delete */
	while (current && i < index)
	{
		current = current->next;
		i++;
	}

	/* If node not found */
	if (!current)
		return (-1);

	/* Update previous node's next pointer */
	if (current->prev)
		current->prev->next = current->next;

	/* Update next node's prev pointer */
	if (current->next)
		current->next->prev = current->prev;

	free(current);
	return (1);
}
