#include "sort.h"
/**
 * swap - swap 2 ints
 * @x: first int to be swapped
 * @y: second int to be swapped
 */
void swap(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bitonic_mer - Sort a bitonic sequence
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of the sequence in array to sort.
 * @sq: The size of the sequence to sort.
 * @flag: The direction to sort in.
 */
void bitonic_mer(int *array, size_t size, size_t start, size_t sq,
				 char flag)
{
	size_t i, jump = sq / 2;

	if (sq > 1)
	{
		for (i = start; i < start + jump; i++)
			if ((flag == 0 && array[i] > array[i + jump]) ||
				(flag == 1 && array[i] < array[i + jump]))
				swap(array + i, array + i + jump);
		bitonic_mer(array, size, start, jump, flag);
		bitonic_mer(array, size, start + jump, jump, flag);
	}
}

/**
 * bitonic_seq - Convert an array of integers into a bitonic sequence.
 * @array: An array of integers.
 * @size: The size of the array.
 * @start: The starting index of a block of the building bitonic sequence.
 * @sq: The size of a block of the building bitonic sequence.
 * @flag: The direction to sort the bitonic sequence block in.
 */
void bitonic_seq(int *array, size_t size, size_t start, size_t sq, char flag)
{
	size_t cut = sq / 2;
	char *str = (flag == 0) ? "UP" : "DOWN";

	if (sq > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + start, sq);
		bitonic_seq(array, size, start, cut, 0);
		bitonic_seq(array, size, start + cut, cut, 1);
		bitonic_mer(array, size, start, sq, flag);
		printf("Result [%lu/%lu] (%s):\n", sq, size, str);
		print_array(array + start, sq);
	}
}

/**
 * bitonic_sort - Sort an array of integers in ascending order
 * @array: An array of integers.
 * @size: The size of the array.
 */
void bitonic_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	bitonic_seq(array, size, 0, size, 0);
}
