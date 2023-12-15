#include "sort.h"
/**
 * swap_node_ahead - swap slow and fast nodes
 * @list: list to be sorted
 * @slow: pointer to the slow node
 * @fast: pointer to the fast node
 */
void swap_node_ahead(listint_t **list, listint_t **slow, listint_t **fast)
{
	listint_t *tmp = (*fast)->next;

	if ((*fast)->prev != NULL)
		(*fast)->prev->next = tmp;
	else
		*list = tmp;

	tmp->prev = (*fast)->prev;
	(*fast)->next = tmp->next;

	if (tmp->next != NULL)
		tmp->next->prev = *fast;
	else
		*slow = *fast;

	(*fast)->prev = tmp;
	tmp->next = *fast;
	*fast = tmp;
}

/**
 * swap_node_behind - swap slow and fast nodes
 * @list: list to be sorted
 * @slow: pointer to the slow node
 * @fast: pointer to the fast node
 */
void swap_node_behind(listint_t **list, listint_t **slow, listint_t **fast)
{
	listint_t *tmp = (*fast)->prev;

	if ((*fast)->next != NULL)
		(*fast)->next->prev = tmp;
	else
		*slow = tmp;

	tmp->next = (*fast)->next;
	(*fast)->prev = tmp->prev;

	if (tmp->prev != NULL)
		tmp->prev->next = *fast;
	else
		*list = *fast;

	(*fast)->next = tmp;
	tmp->prev = *fast;
	*fast = tmp;
}
/**
 * cocktail_sort_list - sort linked list with the cocktail sort algotrithm
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *slow, *fast;
	int alert = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (slow = *list; slow->next != NULL;)
		slow = slow->next;

	while (alert == 1)
	{
		alert = 0;
		for (fast = *list; fast != slow; fast = fast->next)
		{
			if (fast->n > fast->next->n)
			{
				swap_node_ahead(list, &slow, &fast);
				print_list((const listint_t *)*list);
				alert = 1;
			}
		}
		for (fast = fast->prev; fast != *list;
			 fast = fast->prev)
		{
			if (fast->n < fast->prev->n)
			{
				swap_node_behind(list, &slow, &fast);
				print_list((const listint_t *)*list);
				alert = 1;
			}
		}
	}
}
