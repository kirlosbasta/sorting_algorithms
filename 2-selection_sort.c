#include "sort.h"

/**
 * selection_sort - Implementation of selection sort algorithm
 * @array: Array of integer to sort
 * @size: Size of the array
 *
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
	int i, min, j;

	for (i = 0; i < (int)size - 1; i++)
	{
		min = i;
		for (j = i + 1; j < (int)size; j++)
		{
			if (array[j] < array[min])
			{
				min = j;
			}
		}
		if (i != min)
		{
			swap(&array[i], &array[min]);
			print_array(array, size);
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
