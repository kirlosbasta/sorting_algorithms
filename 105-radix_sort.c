#include "sort.h"

/**
 * radix_sort - Implementation of Radix sort
 * @array: Array of integer
 * @size: Size of array
 *
 * Return: Nothing
 */
void radix_sort(int *array, size_t size)
{
	int m, exp;

	if (size < 2)
	{
		return;
	}
	m = max_t(array, (int)size);
	for (exp = 1; m / exp > 0; exp *= 10)
	{
		count(array, size, exp);
		print_array(array, size);
	}
}

/**
 * count - Do counting sort of array
 * @array: Array of integer
 * @size: Size of array
 * @exp: Sort according to exp
 *
 * Return: Nothing
 */
void count(int *array, int size, int exp)
{
	int *output, *count, i;

	output = malloc(sizeof(int) * size);
	if (!output)
		return;
	count = malloc(sizeof(int) * 10);
	if (!count)
	{
		free(output);
		return;
	}
	for (i = 0; i < 10; i++)
		count[i] = 0;
	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
	{
		array[i] = output[i];
	}
	free(output);
	free(count);
}

/**
 * max_t - get the max digit of the array
 * @array: Array of integer
 * @size: size of the array
 *
 * Return: Max integer
 */
int max_t(int *array, int size)
{
	int m = array[0], i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > m)
		{
			m = array[i];
		}
	}
	return (m);
}
