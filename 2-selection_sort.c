#include "sort.h"

void selection_sort(int *array, size_t size)
{
    size_t i, j, k;
    int min;
    int temp;

    for (i = 0; i < size - 1; i++)
    {
        min = array[i];
        for (j = i + 1; j < size; j++)
        {
            if (array[j] < min)
            {
                min = array[j];
                k = j;
            }
        }
        if (min != array[i])
        {
            temp = array[k];
            array[k] = array[i];
            array[i] = temp;
            print_array(array, size);
        }
    }
}
