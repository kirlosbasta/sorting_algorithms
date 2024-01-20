#include "sort.h"

/**
 * quick_sort - Implementaion of quick sort
 * @array: Array of integer
 * @size: Size of the array
 *
 * Return: Nothing
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
	{
		return;
	}
	quick_sort_h(array, 0, (int)size - 1, size);
}

/**
 * partition - divide the array to two part
 * @array: Array of integer
 * @low: the left end of the array
 * @high: the right end of the array(pivot)
 * @size: size of the array
 *
 * Return: Pivot final position
 */
int partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j;

	pivot = array[high];
	/*indicate the right position*/
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				swap(&array[i], &array[j]);
				print_array(array, size);
			}
		}
	}
	i++;
	swap(&array[high], &array[i]);
	if (i != high)
		print_array(array, size);
	return (i);
}

/**
 * quick_sort_h - Help quick sort function
 * @array: Array of integer
 * @low: the left end of the array
 * @high: the right end of the array
 * @size: size of the array
 *
 * Return: Nothig
 */
void quick_sort_h(int *array, int low, int high, size_t size)
{
	int p;

	if (low >= high || low < 0)
	{
		return;
	}
	p = partition(array, low, high, size);
	quick_sort_h(array, low, p - 1, size);
	quick_sort_h(array, p + 1, high, size);
}

/**
 * swap - Swap Two integer
 * @num_1: integer 1
 * @num_2: integer 2
 *
 * Return: Nothing
 */
void swap(int *num_1, int *num_2)
{
	int tmp;

	tmp = *num_1;
	*num_1 = *num_2;
	*num_2 = tmp;
}
