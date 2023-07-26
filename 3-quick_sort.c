#include "sort.h"

/**
 * swap - Swaps
 * @array: The array
 * @prv: The index
 * @nxt: The index
 */
void swap(int *array, size_t prv, size_t nxt)
{
	int tmp;

	tmp = array[prv];
	array[prv] = array[nxt];
	array[nxt] = tmp;
}

/**
 * lomuto_sort - Sorts an array using the lomuto sort
 * @array: The array
 * @low: The low
 * @high: The high
 * @size: The size
 */
void lomuto_sort(int *array, size_t low, size_t high, size_t size)
{
	size_t idx, i;
	int pivot;

	if (low - high <= 1 || array == NULL)
		return;
	pivot = array[high];
	idx = low;
	i = low;

	while (i < high)
	{
		if (array[i] <= pivot)
		{
			if (idx != i)
			{
				swap(array, i, idx);
				print_array(array, size);
			}
			idx++;
		}
		i++;
	}
	if (high != idx)
	{
		swap(array, high, idx);
		print_array(array, size);
	}
	lomuto_sort(array, low, idx - 1, size);
	lomuto_sort(array, idx + 1, high, size);
}

/**
 * quick_sort - Sorts an array using the quick sort algorithm
 * @array: The array
 * @size: The size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL)
		return;
	lomuto_sort(array, 0, size - 1, size);

}
