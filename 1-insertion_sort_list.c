#include "sort.h"

/**
 * insertion_sort_list - sorts an array of integers
 * @list: doubly-linked list of integers to sort
 */
void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return; /* Nothing to sort or only one element */

	listint_t *current, *nxt, *tmp;

	current = (*list)->next; /* Start with the second node */

	while (current != NULL)
	{
		nxt = current->next; /* Save the next node before rearranging pointers */
		tmp = current;

		while (tmp->prev != NULL && tmp->n < tmp->prev->n)
		{
			/* Swap the nodes (adjusting pointers) */
			if (tmp->prev->prev != NULL)
				tmp->prev->prev->next = tmp;
			else
				*list = tmp; /* Update the head of the list */

			if (tmp->next != NULL)
				tmp->next->prev = tmp->prev;

			tmp->prev->next = tmp->next;
			tmp->next = tmp->prev;
			tmp->prev = tmp->prev->prev;
			tmp->next->prev = tmp;

			print_list(*list); /* Print the state of the list after each swap */
		}

		current = nxt; /* Move to the next unsorted element */
	}
}
