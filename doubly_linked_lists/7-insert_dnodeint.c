#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added (starting from 0)
 * @n: data for the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *new, *current;
	unsigned int i;

	if (!h)
		return (NULL);

	/* Special case: insert at beginning (index 0) */
	if (idx == 0)
		return (add_dnodeint(h, n));

	/* Create new node */
	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	/* Traverse to the node before the insertion point */
	current = *h;
	i = 0;

	while (current)
	{
		if (i == idx - 1)
		{
			/* Insert new node between current and current->next */
			new->next = current->next;
			new->prev = current;

			if (current->next)
				current->next->prev = new;

			current->next = new;
			return (new);
		}
		current = current->next;
		i++;
	}

	/* If idx is exactly one past the end, add at the end */
	if (i == idx)
	{
		free(new);
		return (add_dnodeint_end(h, n));
	}

	/* Index out of bounds */
	free(new);
	return (NULL);
}
