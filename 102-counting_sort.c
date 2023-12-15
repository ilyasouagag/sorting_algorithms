#include "sort.h"
/**
 * counting_sort - sort an array using the couting sort
 * algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void counting_sort(int array[], size_t size)
{
	int i, max, min, range, *count, *sortedArr;

	max = array[0];
	min = array[0];
	for (i = 1; (size_t)i < size; ++i)
	{
		if (array[i] > max)
			max = array[i];
		if (array[i] < min)
			min = array[i];
	}
	range = max - min + 1;
	count = malloc(sizeof(int) * range);
	for (i = 0; i < range; ++i)
		count[i] = 0;

	for (i = 0; (size_t)i < size; ++i)
		count[array[i] - min]++;

	for (i = 1; i < range; ++i)
		count[i] += count[i - 1];

	sortedArr = malloc(sizeof(int) * size);
	for (i = size - 1; i >= 0; --i)
		sortedArr[--count[array[i] - min]] = array[i];

	for (i = 0; (size_t)i < size; ++i)
	{
		array[i] = sortedArr[i];
	}
	print_array(count, range);
	free(count);
	free(sortedArr);
}
