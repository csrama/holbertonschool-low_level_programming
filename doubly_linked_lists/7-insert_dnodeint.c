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
	unsigned int i = 0;

	if (!h)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));

	current = *h;
	while (current && i < idx - 1)
	{
		current = current->next;
		i++;
	}

	if (!current)
	{
		if (i == idx - 1)
			return (add_dnodeint_end(h, n));
		return (NULL);
	}

	new = malloc(sizeof(dlistint_t));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = current->next;
	new->prev = current;

	if (current->next)
		current->next->prev = new;
	current->next = new;

	return (new);
}
