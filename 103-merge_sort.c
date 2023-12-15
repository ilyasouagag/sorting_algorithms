#include "sort.h"

/**
 * mer - merge 2 sorted arrays
 * @array: original array
 * @size: size of original array
 * @left: pointer to the first array
 * @ls: size of the second array
 * @right: pointer to second array
 * @rs: size of second array
 */
void mer(int *array, size_t size, int *left, size_t ls, int *right, size_t rs)
{
	size_t i = 0, j = 0, k = 0;
	int *temp;

	temp = malloc(size * sizeof(int));
	if (temp == NULL)
		return;
	printf("Merging...\n[left]: ");
	print_array(left, ls);
	printf("[right]: ");
	print_array(right, rs);

	while (i < ls && j < rs)
		if (left[i] <= right[j])
			temp[k++] = left[i++];
		else
			temp[k++] = right[j++];

	while (i < ls)
		temp[k++] = left[i++];
	while (j < rs)
		temp[k++] = right[j++];

	for (i = 0; i < size; i++)
		array[i] = temp[i];

	printf("[Done]: ");
	print_array(array, size);

	free(temp);
}

/**
 * merge_sort_recursive - merge sort recursively
 * @array: pointer to original array
 * @size: size of original array
 */
void merge_sort_recursive(int *array, size_t size)
{
	int *left, *right;

	if (size > 1)
	{
		size_t mid = size / 2;

		left = array;
		right = array + mid;

		printf("Merging...\n[left]: ");
		print_array(left, mid);
		printf("[right]: ");
		print_array(right, size - mid);

		merge_sort_recursive(left, mid);
		merge_sort_recursive(right, size - mid);

		mer(array, size, left, mid, right, size - mid);
	}
}

/**
 * merge_sort - main merge sort function
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void merge_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	merge_sort_recursive(array, size);
}
