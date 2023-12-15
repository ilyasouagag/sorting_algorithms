#include "sort.h"
void print_array(const int *array, size_t size)
{
	size_t i;

	i = 0;
	while (array && i < size)
	{
		if (i > 0)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

void shellsort(int array[], size_t size)
{
	size_t h = 1, i, j;
	int key;

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
