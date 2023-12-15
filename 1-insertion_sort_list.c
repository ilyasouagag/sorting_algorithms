#include "sort.h"
/**
 * insertion_sort_list - sort a linked list using the insertion
 * algorithm
 * @list: linked list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *current2;
	listint_t *current3;
	listint_t *tmp;

	while (current && current->next)
	{
		current2 = current;
		if (current->n > current->next->n)
		{
			tmp = current2->next;
			if (current2->prev != NULL)
				current2->prev->next = tmp;
			else
				*list = tmp;

			tmp->prev = current2->prev;
			current2->prev = tmp;
			current2->next = tmp->next;

			if (tmp->next != NULL)
				tmp->next->prev = current2;

			tmp->next = current2;
			print_list(*list);
			current3 = tmp;
			while (current3->prev && tmp->n <= current3->n)
				current3 = current3->prev;
			current = current3;
			continue;
		}
		current = current->next;
	}
}
