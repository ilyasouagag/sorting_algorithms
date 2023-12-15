#include "sort.h"
/**
 * bubble_sort - sort array with the bubble sort algotrithm
 * @array: array of integers
 * @size: size of the array of integers
 */
void bubble_sort(int *array, size_t size)
{
	size_t j, size2 = size;
	int temp, alert = 1;

	if (array == NULL || size < 2)
		return;

	while (alert == 1)
	{
		alert = 0;
		for (j = 0; j < size2 - 1; j++)
		{

			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				print_array(array, size);
				alert = 1;
			}
		}
		size2--;
	}
}
