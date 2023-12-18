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
size_t hoare_partition(int *array, size_t start, size_t finish, size_t size)
{
    int *pivot, prev, next, tmp;

    pivot = array + start;
    prev = start - 1;
    next = finish + 1;
    while (1)
    {
        do
        {
            prev++;
        } while (array[prev] < *pivot);
        do
        {
            next--;
        } while (array[next] > *pivot);

        if (prev < next)
        {
            tmp = array[prev];
            array[prev] = array[next];
            array[next] = tmp;
        }
        else
            return next;
    }
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

    pivot = hoare_partition(array, start, finish, size);

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
int main(void)
{
    int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    quick_sort(array, n);
    printf("\n");
    print_array(array, n);
    return (0);
}