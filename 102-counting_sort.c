#include "sort.h"
/**
 * counting_sort - sort an array using the couting sort
 * algorithm
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void counting_sort(int array[], size_t size)
{
	int *count, *sortedArr, max, i;

	if (array == NULL || size < 2)
		return;
	sortedArr = malloc(sizeof(int) * size);
	if (sortedArr == NULL)
		return;
	max = array[0];
	for (i = 1; (size_t)i < size; ++i)
		if (array[i] > max)
			max = array[i];
	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
	{
		free(sortedArr);
		return;
	}
	for (i = 0; i < (max + 1); i++)
		count[i] = 0;
	for (i = 0; i < (int)size; i++)
		count[array[i]] += 1;
	for (i = 0; i < (max + 1); i++)
		count[i] += count[i - 1];
	print_array(count, max + 1);
	for (i = 0; i < (int)size; i++)
	{
		sortedArr[count[array[i]] - 1] = array[i];
		count[array[i]] -= 1;
	}
	for (i = 0; i < (int)size; i++)
		array[i] = sortedArr[i];
	free(sortedArr);
	free(count);
}
