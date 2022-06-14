#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index
 *@head: head
 *@index: index
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *current, *tmp;
	unsigned int i = 0;

	if (head == NULL || *head == NULL)
		return (-1);
	current = *head;
	if (index == 0)
	{
		*head = (*head)->next;
		free(current);
		if (*head != NULL)
			(*head)->prev = NULL;
		return (1);
	}
	while (current != NULL && (i < index - 1))
	{
		current = current->next;
		i++;
	}
	if (current == NULL)
		return (-1);
	tmp = current->next;
	if (current->next->next == NULL)
		current->next = NULL;
	else
	{
		tmp->prev->next = tmp->next;
		tmp->next->prev = current;
	}
	free(tmp);
	return (1);
}
