#include "sort.h"
/**
 * selection_sort - sort an array using the selection sort
 * algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void selection_sort(int *array, size_t size)
{
	int *min, tmp;
	size_t i, j;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		min = array + i;
		for (j = i + 1; j < size; j++)
			min = (array[j] < *min) ? (array + j) : min;

		if ((array + i) != min)
		{
			tmp = array[i];
			array[i] = *min;
			*min = tmp;
			print_array(array, size);
		}
	}
}
