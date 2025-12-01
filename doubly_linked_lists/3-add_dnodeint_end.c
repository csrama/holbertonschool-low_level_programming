#include <stdlib.h>
#include "lists.h"

/**
 * add_dnodeint_end - adds a new node at the end of a dlistint_t list
 * @head: double pointer to the head of the list
 * @n: integer value to store in the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *new, *tmp;

	if (!head)
		return (NULL);

	new = malloc(sizeof(*new));
	if (!new)
		return (NULL);

	new->n = n;
	new->next = NULL;
	new->prev = NULL;

	/* If list is empty, new node becomes head */
	if (!*head)
	{
		*head = new;
		return (new);
	}

	/* Traverse to the last node */
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;

	/* Link new node at the end */
	tmp->next = new;
	new->prev = tmp;

	return (new);
}
