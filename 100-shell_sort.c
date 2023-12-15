#include "sort.h"

/**
 * shell_sort - sort an array using the shell sort
 * algorithm
 * @array: array to be sorted
 * @size: size of array to be sorted
 */
void shell_sort(int array[], size_t size)
{
	size_t h = 1, i, j;
	int key;

	if (array == NULL || size < 2)
		return;
	while (h < size / 3)
		h = 3 * h + 1;

	while (h >= 1)
	{
		for (i = h; i < size; i++)
		{
			key = array[i];
			j = i;
			while (j >= h && array[j - h] > key)
			{
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = key;
		}
		h /= 3;
		print_array(array, size);
	}
}
