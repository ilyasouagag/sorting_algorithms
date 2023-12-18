#include "deck.h"
/**
 * aux_num_fun - Converts a card value to an integer representation
 * @head_tmp1: Pointer to the node containing the card
 * Return: Integer representation of the card value
 **/
int aux_num_fun(deck_node_t *head_tmp1)
{
	int aux_num, j;
	int num[13] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
	char val[13] = {'A', '2', '3', '4', '5', '6', '7',
		'8', '9', '1', 'J', 'Q', 'K'};

	for (j = 0; j < 13; j++)
	{
		if (head_tmp1->card->value[0] == val[j])
			aux_num = num[j];
	}

	return (aux_num);
}
/**
 * sort_num_sublist - Sorts a sublist of cards based on their values
 * @list: Pointer to the head of the list
 * @k: Kind value to be sorted
 * Return: No return
 **/
void sort_num_sublist(deck_node_t **list, unsigned int k)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int flag = 0, aux_num1, aux_num2;

	head_tmp1 = *list;
	head_tmp2 = *list;

	while (head_tmp1->next && head_tmp1->next->card->kind == k)
	{
		aux_num1 = aux_num_fun(head_tmp1);
		aux_num2 = aux_num_fun(head_tmp1->next);
		flag = 0;
		head_tmp2 = head_tmp1;
		while (head_tmp2 && head_tmp2->card->kind == k && aux_num1 > aux_num2)
		{
			aux1 = head_tmp2;
			aux2 = head_tmp2->next;
			aux1->next = aux2->next;
			if (aux2->next)
				aux2->next->prev = aux1;

			aux2->prev = aux1->prev;
			aux2->next = aux1;
			aux1->prev = aux2;
			if (aux2->prev)
				aux2->prev->next = aux2;
			head_tmp2 = aux2->prev;
			if (!aux2->prev)
				*list = aux2;
			flag = 1;
			if (!head_tmp2)
				break;
			aux_num1 = aux_num_fun(head_tmp2);
			aux_num2 = aux_num_fun(head_tmp2->next);
		}
		if (flag == 0)
			head_tmp1 = head_tmp1->next;
	}
}
/**
 * num_sort - Sorts a doubly linked list of cards based on their values
 * @list: Pointer to the head of the list
 * Return: No return
 **/
void num_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1;
	unsigned int k;

	head_tmp1 = *list;

	for (int i = 0; i < 4; i++)
	{
		k = head_tmp1->card->kind;
		sort_num_sublist(list, k);
		head_tmp1 = head_tmp1->next;
	}
}
/**
 * kind_sort - Sorts a doubly linked list of cards based on their kind
 * @list: Pointer to the head of the list
 * Return: No return
 **/
void kind_sort(deck_node_t **list)
{
	deck_node_t *head_tmp1, *head_tmp2, *aux1, *aux2;
	int flag;

	if (list)
	{
		head_tmp1 = *list;
		head_tmp2 = *list;
		while (list && head_tmp1->next)
		{
			if (head_tmp1->next)
			{
				flag = 0;
				head_tmp2 = head_tmp1;
				while (head_tmp2 && head_tmp2->card->kind > head_tmp2->next->card->kind)
				{
					aux1 = head_tmp2;
					aux2 = head_tmp2->next;
					aux1->next = aux2->next;
					if (aux2->next)
						aux2->next->prev = aux1;
					if (aux2)
					{
						aux2->prev = aux1->prev;
						aux2->next = aux1;
					}
					if (aux1)
						aux1->prev = aux2;
					if (aux2->prev)
						aux2->prev->next = aux2;
					head_tmp2 = aux2->prev;
					if (!aux2->prev)
						*list = aux2;
					flag = 1;
				}
			}
			if (flag == 0)
				head_tmp1 = head_tmp1->next;
		}
	}
}
/**
 * sort_deck - Sorts a deck of cards first by kind, then by value
 * @deck: Pointer to the head of the deck
 * Return: No return
 **/
void sort_deck(deck_node_t **deck)
{
	if (deck)
	{
		kind_sort(deck);
		num_sort(deck);
	}
}
