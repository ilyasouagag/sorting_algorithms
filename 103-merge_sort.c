#include "sort.h"
/**
 * mer - Sort a subarray of integers.
 * @Arr: subarray of an array of integers to sort
 * @tmpArr: buffer to store the sorted subarray
 * @front: the front index of the array
 * @mid: the middle index of the array
 * @back: the back index of the array
 */
void mer(int *Arr, int *tmpArr, size_t front, size_t mid, size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(Arr + front, mid - front);

	printf("[right]: ");
	print_array(Arr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		tmpArr[k] = (Arr[i] < Arr[j]) ? Arr[i++] : Arr[j++];
	for (; i < mid; i++)
		tmpArr[k++] = Arr[i];
	for (; j < back; j++)
		tmpArr[k++] = Arr[j];
	for (i = front, k = 0; i < back; i++)
		Arr[i] = tmpArr[k++];

	printf("[Done]: ");
	print_array(Arr + front, back - front);
}
/**
 * merge_sort_recursive - merge sort recursively
 * @Arr: subtitute array
 * @tmpArr: buffer
 * @front: the front index of the Arr
 * @back: the back index of the Arr
 */
void merge_sort_recursive(int *Arr, int *tmpArr, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_sort_recursive(Arr, tmpArr, front, mid);
		merge_sort_recursive(Arr, tmpArr, mid, back);
		mer(Arr, tmpArr, front, mid, back);
	}
}
/**
 * merge_sort - main merge sort function
 * @array: array to be sorted
 * @size: size of the array to be sorted
 */
void merge_sort(int *array, size_t size)
{
	int *tmpArr;

	if (array == NULL || size < 2)
		return;

	tmpArr = malloc(sizeof(int) * size);
	if (tmpArr == NULL)
		return;
	merge_sort_recursive(array, tmpArr, 0, size);
	free(tmpArr);
}
