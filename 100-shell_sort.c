#include "sort.h"

/**
 * shell_sort - Implementation of sell sort
 * @array: Array of integer
 * @size: size of the array
 *
 * Return: Nothing
 */
void shell_sort(int *array, size_t size)
{
	int gap, i, tmp, j;

	for (gap = 1; gap < (int)size; gap = gap * 3 + 1)
	{}
	gap = (gap - 1) / 3;
	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < (int)size; i++)
		{
			tmp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > tmp); j -= gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = tmp;
		}
		print_array(array, size);
	}
}
