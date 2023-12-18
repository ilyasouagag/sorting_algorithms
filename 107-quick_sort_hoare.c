#include "sort.h"


/**
 * quick_sort_helper - Helper function for the quicksort algorithm that
 * recursively sorts subarrays.
 * @array: The array to be sorted
 * @start: The starting index of the subarray
 * @finish: The ending index of the subarray
 * @size: The size of the array
 */
void quick_sort_helper(int *array, size_t start, size_t finish, size_t size)
{
	size_t pivot;

	if (start >= finish)
		return;

	pivot = partition(array, start, finish, size);

	if (pivot > 0)
		quick_sort_helper(array, start, pivot - 1, size);
	quick_sort_helper(array, pivot + 1, finish, size);
}

/**
 * quick_sort - Sorts an array using the quicksort algorithm
 * @array: The array to be sorted
 * @size: The size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quick_sort_helper(array, 0, size - 1, size);
}




/**
 * quick_sort_hoare - sorts an array of integers in ascending order
 * @array: array input
 * @size: size of array
*/
void quick_sort_hoare(int *array, size_t size)
{
    
}