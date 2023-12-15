#include "sort.h"
/**
 * swap - swap to integers
 * @x: first integer to be swaped
 * @y: second integer to be swaped
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}
/**
 * bubble_sort - sort array with the bubble sort algotrithm
 * @array: array of integers
 * @size: size of the array of integers
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, size2 = size;
	int alert = 1;

	if (array == NULL || size < 2)
		return;

	while (alert == 1)
	{
		alert = 0;
		for (j = 0; j < size2 - 1; j++)
		{

			if (array[j] > array[j + 1])
			{
				swap(array + j, array + j + 1);
				print_array(array, size);
				alert = 1;
			}
		}
		size2--;
	}
}
