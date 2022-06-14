#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"
/**
 * insert_dnodeint_at_index - inset a new node at a given position
 *@h: head
 *@idx: index
 *@n: data
 * Return: Address of the new node or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	unsigned int i = 0;

	dlistint_t *new, *tmp;

	if (h == NULL)
		return (NULL);
	new = malloc(sizeof(*new));
	new->n = n;
	if (new == NULL)
		return (NULL);
	if (*h == NULL && idx != 0)
		return (NULL);
	if (idx == 0)
		return (add_dnodeint(h, n));
	tmp = *h;
	while (tmp != NULL && i < idx - 1)
	{
		tmp = tmp->next;
		i++;
	}
	if (tmp == NULL)
		return (NULL);
	if (idx == i + 1)
		return (add_dnodeint_end(h, n));
	new->next = tmp->next;
	new->prev = tmp;
	tmp->next->prev = new;
	tmp->next = new;
	return (new);
}
