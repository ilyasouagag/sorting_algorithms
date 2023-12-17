#include "sort.h"

/**
 * get_max - function to get the max elemene in the array
 * @arr: array to iterate through
 * @size: size of the array
 * Return: the max value
 */
int get_max(int *arr, size_t size)
{
	size_t i;
	int max = arr[0];

	for (i = 0; i < size; i++)
		if (arr[i] > max)
			max = arr[i];
	return (max);
}
/**
 * countsort - sort the array using the count sort algorithm
 * @arr: array to be sorted
 * @size: size of array to be sorted
 * @exp: coefficient to jump though digit ranks
 */
void countsort(int arr[], int size, int exp)
{

	int *sortedArr;
	int i, count[10] = {0};

	sortedArr = malloc(sizeof(int) * size);
	if (sortedArr == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		sortedArr[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < size; i++)
		arr[i] = sortedArr[i];
}
/**
 * radix_sort - function to sort array using the radix sort algo
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void radix_sort(int *array, size_t size)
{
	int max, exp;

	max = get_max(array, size);

	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countsort(array, size, exp);
		print_array(array, size);
	}
}
