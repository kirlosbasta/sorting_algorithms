#include "sort.h"

/**
 * heap_sort - Implementaion of heap sort alogrithm
 * @array: Array of integer
 * @size: Size of the array
 *
 * Return: Nothing
 */
void heap_sort(int *array, size_t size)
{
	int last;

	heapify(array, (int)size);
	last = (int)size;
	while (last > 1)
	{
		last--;
		swap(&array[0], &array[last]);
		print_array(array, size);
		siftDown(array, 0, last, size);
	}
}

/**
 * heapify - turn the array into heap like data structure
 * @array: Array of integers
 * @size: size of the array
 *
 * Return: Nothing
 */
void heapify(int *array, int size)
{
	int start;

	start = ((size - 2) / 2) + 1;
	while (start > 0)
	{
		start--;
		siftDown(array, start, size, size);
	}
}

/**
 * siftDown - Rearrange the root to it's childeren
 * @array: Array of integer
 * @start: Root node to arrange
 * @end: End of the tree
 * @size: size of the array
 *
 * Return: Nothing
 */
void siftDown(int *array, int start, int end, size_t size)
{
	int root = start, child, left;

	left =  root * 2 + 1;
	while (left < end)
	{
		child = left;
		if (child + 1 < end && array[child] < array[child + 1])
			child++;
		if (array[root] < array[child])
		{
			swap(&array[root], &array[child]);
			print_array(array, size);
			root = child;
			left =  root * 2 + 1;
		}
		else
			return;
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
