#include "sort.h"


/**
 * bubble_sort - sort a list of integer using bubble sort
 * @array: Array of integer
 * @size: Size of the array
 *
 * Return: Nothing
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j, stat;

	if (size < 2)
	{
		return;
	}
	for (i = 0; i < size - 1; i++)
	{
		stat = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				print_array(array, size);
				stat = 1;
			}
		}
		if (stat == 0)
		{
			break;
		}
	}
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
