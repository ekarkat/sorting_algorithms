#include "sort.h"
/**
 * bubble_sort - sort an array using bubble alghortihm
 * @array: the array
 * @size : the size
*/
void bubble_sort(int *array, size_t size)
{
	size_t i;
	size_t tmp;
	size_t j;

	for (j = 0; j < size; j++)
	{
		i = 0;
		for (;i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
			}
		}
		print_array(array, size);
	}
}
