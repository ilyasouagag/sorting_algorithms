#include "sort.h"
/**
 * partition - Helper function for quicksort algorithm that partitions the
 * array into two segments: elements less than or equal to the pivot,
 * and elements greater than the pivot.
 * @array: The array to be partitioned
 * @start: The starting index of the segment to be partitioned
 * @finish: The ending index of the segment to be partitioned
 * @size: The size of the array
 *
 * Return: The index of the pivot element after partitioning
 */
size_t partition(int *array, size_t start, size_t finish, size_t size)
{
	int *pivot, prev, curr, tmp;

	pivot = array + finish;
	for (prev = curr = start; curr < (int)finish; curr++)
		if (array[curr] < *pivot)
		{
			if (prev < curr)
			{
				tmp = array[curr];
				array[curr] = array[prev];
				array[prev] = tmp;
				print_array(array, size);
			}
			prev++;
		}

	if (array[prev] > *pivot)
	{
		tmp = array[prev];
		array[prev] = *pivot;
		*pivot = tmp;
		print_array(array, size);
	}

	return (prev);
}

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