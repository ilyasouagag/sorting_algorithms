#include "sort.h"
/**
 * sift_down - sift down function in heap sorting
 * @array: the array to be sorted
 * @start: the index for the root of the tree
 * @end: the index of the last element in tree
 * @size: the size of the array to be sorted
 */
void sift_down(int *array, size_t start, size_t end, size_t size)
{
    size_t root = start;
    size_t child;

    while (2 * root + 1 <= end)
    {
        child = 2 * root + 1;
        if (child + 1 <= end && array[child] < array[child + 1])
            child++;

        if (array[root] < array[child])
        {
            int temp = array[root];
            array[root] = array[child];
            array[child] = temp;
            root = child;
            print_array(array, size);
        }
        else
            return;
    }
}

/**
 * heap_sort - Sorts an array of integers in ascending order using Heap sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void heap_sort(int *array, size_t size)
{
    int i, tmp;

    if (array == NULL || size < 2)
        return;

    for (i = size / 2 - 1; i >= 0; i--)
        sift_down(array, i, size - 1, size);

    for (i = size - 1; i > 0; i--)
    {
        tmp = array[0];
        array[0] = array[i];
        array[i] = tmp;
        print_array(array, size);
        sift_down(array, 0, i - 1, size);
    }
}
