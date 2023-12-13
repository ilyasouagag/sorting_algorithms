#include "sort.h"

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

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}
/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
	int i;

	i = 0;
	while (list)
	{
		if (i > 0)
			printf(", ");
		printf("%d", list->n);
		++i;
		list = list->next;
	}
	printf("\n");
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	listint_t *list;
	int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
	size_t n = sizeof(array) / sizeof(array[0]);

	list = create_listint(array, n);
	if (!list)
		return (1);
	print_list(list);
	printf("\n");
	insertion_sort_list(&list);
	printf("\n");
	print_list(list);
	return (0);
}
