#include "sort.h"

/**
 * counting_sort - Implementation of counting sort algorithm
 * @array: Array of integer
 * @size: Size of the array
 *
 * Return: Nothing
 */
void counting_sort(int *array, size_t size)
{
	int i, max, *countarr, *outputarr;

	if (size < 2)
		return;
	max = array[0];
	for (i = 0; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	countarr = malloc(sizeof(int) * (max + 1));
	if (!countarr)
		return;
	for (i = 0; i <= max; i++)
		countarr[i] = 0;
	for (i = 0; i < (int)size; i++)
		countarr[array[i]]++;
	for (i = 1; i <= max; i++)
		countarr[i] += countarr[i - 1];
	print_array(countarr, max + 1);
	outputarr = malloc(sizeof(int) * size);
	if (!outputarr)
	{
		free(countarr);
		return;
	}
	for (i = size - 1; i >= 0; i--)
		outputarr[countarr[array[i]] - 1] = array[i];
	for (i = 0; i < (int)size; i++)
		array[i] = outputarr[i];
	free(countarr);
	free(outputarr);
}
