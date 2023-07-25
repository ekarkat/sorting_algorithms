#include "sort.h"


/**
 * swap - swap two element
 * @array: the array
 * @i : the first index
 * @j : the sec index
*/
void swap(int *array, size_t i, size_t j)
{
	int tmp;

	tmp = array[i];
	array[i] = array[j];
	array[j] = tmp;
}

/**
 * selection_sort - Sorts an array of integers in ascending order.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, min_index;

	i = 0;
	if (array == NULL || size <= 1)
		return;
	for (; i < size - 1; i++)
	{
		min_index = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}

		if (min_index != i)
		{
			swap(array, i, min_index);
			print_array(array, size);
		}
	}
}
