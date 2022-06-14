#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lists.h"

/**
 * sum_dlistint - sum of all the data of a doubly linked list
 *@head: head
 * Return: return 0 if list is empty
 */

int sum_dlistint(dlistint_t *head)
{
	unsigned int sum = 0;

	if (head == NULL)
		return (0);
	while (head != NULL)
	{
		sum = sum + head->n;
		head = head->next;
	}
	return (sum);
}
