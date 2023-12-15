#include "sort.h"
/**
 * insertion_sort_list - sort a linked list using the insertion
 * algorithm
 * @list: linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *current2, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (current = (*list)->next; current != NULL; current = tmp)
	{
		tmp = current->next;
		current2 = current->prev;
		while (current2 != NULL && current->n < current2->n)
		{
			current2->next = current->next;
			if (current->next != NULL)
				current->next->prev = current2;
			current->prev = current2->prev;
			current->next = current2;
			if (current2->prev != NULL)
				current2->prev->next = current;
			else
				*list = current;
			current2->prev = current;
			current2 = current->prev;
			print_list((const listint_t *)*list);
		}
	}
}
