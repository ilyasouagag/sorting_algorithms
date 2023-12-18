#include "sort.h"
/**
 * hoare_partition - Helper function for quicksort algorithm that partitions
 * the array into two segments: elements less than or equal to the pivot,
 * and elements greater than the pivot.
 * @array: The array to be partitioned
 * @start: The starting index of the segment to be partitioned
 * @finish: The ending index of the segment to be partitioned
 * @size: The size of the array
 *
 * Return: The index of the pivot element after partitioning
 */
size_t hoare_partition(int *array, size_t start, size_t finish, size_t size)
{
	int *pivot, prev, next, tmp;

	pivot = array + start;
	prev = start - 1;
	next = finish + 1;
	while (1)
	{
		do {
			prev++;
		} while (array[prev] < *pivot);
		do {
			next--;
		} while (array[next] > *pivot);

		if (prev < next)
		{
			tmp = array[prev];
			array[prev] = array[next];
			array[next] = tmp;
			print_array(array, size);
		}
		else
			return (next);
	}
}

/**
 * quick_sort_helper_hoare - Helper function for the quicksort algorithm that
 * recursively sorts subarrays.
 * @array: The array to be sorted
 * @start: The starting index of the subarray
 * @finish: The ending index of the subarray
 * @size: The size of the array
 */
void quick_sort_helper2(int *array, size_t start, size_t finish, size_t size)
{
	size_t pivot;

	if (start < finish)
	{
		pivot = hoare_partition(array, start, finish, size);

		quick_sort_helper2(array, start, pivot, size);

		quick_sort_helper2(array, pivot + 1, finish, size);
	}
}

/**
 * quick_sort_hoare - Sorts an array using the quicksort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper2(array, 0, size - 1, size);
}
