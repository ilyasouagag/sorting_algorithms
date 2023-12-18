#include "sort.h"
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
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
    int pivot, above, below;

    pivot = array[finish];
    for (above = start - 1, below = finish + 1; above < below;)
    {
        do
        {
            above++;
        } while (array[above] < pivot);
        do
        {
            below--;
        } while (array[below] > pivot);

        if (above < below)
        {
            swap(array + above, array + below);
            print_array(array, size);
        }
    }

    return (above);
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

        quick_sort_helper2(array, start, pivot - 1, size);

        quick_sort_helper2(array, pivot, finish, size);
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
