#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
  const int n;
  struct listint_s *prev;
  struct listint_s *next;
} listint_t;

void print_list(const listint_t *list);
void print_array(const int *array, size_t size);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort_helper(int *array, size_t start, size_t finish, size_t size);
void quick_sort(int *array, size_t size);
size_t partition(int *array, size_t start, size_t finish, size_t size);
void shell_sort(int *array, size_t size);
void shell_sort_helper(int *array, size_t size, int *gaps, int count);
int generate_gaps(size_t size, int *gaps);
void cocktail_sort_list(listint_t **list);
void counting_sort(int array[], size_t size);
void merge_sort_recursive(int *Arr, int *tmpArr, size_t front, size_t back);
void mer(int *Arr, int *tmpArr, size_t front, size_t mid, size_t back);
void merge_sort(int *array, size_t size);
void sift_down(int *array, size_t start, size_t end, size_t size);
void heap_sort(int *array, size_t size);

#endif
