#include "sort.h"


/**
 * print_from - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 * @start: the starting index to print from
 */
void print_from(const int *array, size_t size, size_t start)
{
	size_t i;

	i = start;
	while (array && i < size)
	{
		if (i > start)
			printf(", ");
		printf("%d", array[i]);
		++i;
	}
	printf("\n");
}

/**
 * merge - merges 2 sub arrays in a sorted way
 * @array: the array to sort
 * @left: the start of the sub array
 * @mid: the middle element in the sub array
 * @right: the ending index of the sub array (excluded)
 * @tmp: the temp array to store in
 * Return: void
*/
void merge(int *array, size_t left, size_t mid, size_t right, int *tmp)
{
	size_t i = left, j = mid, k = left;

	printf("Merging...\n");
	printf("[left]: ");
	print_from(array, mid, left);
	printf("[right]: ");
	print_from(array, right, mid);
	while (i < mid && j < right)
	{
		if (array[i] <= array[j])
		{
			tmp[k] = array[i];
			i++;
		}
		else
		{
			tmp[k] = array[j];
			j++;
		}
		k++;
	}
	while (i < mid)
	{
		tmp[k] = array[i];
		i++;
		k++;
	}
	while (j < right)
	{
		tmp[k] = array[j];
		j++;
		k++;
	}
	for (k = left; k < right; k++)
		array[k] = tmp[k];
	printf("[Done]: ");
	print_from(array, right, left);

}
/**
 * split - implements merge sort algorithm
 * @array: the array to sort
 * @left: the starting index of the sub array
 * @right: the ending index of the sub array (excluded)
 * @tmp: temp array to store resuls in
 * Return: void
 *
*/
void split(int *array, size_t left, size_t right, int *tmp)
{
	int mid;

	if (left + 1 >= right)
		return;

	mid = left + (right - left) / 2;
	split(array, left, mid, tmp);
	split(array, mid, right, tmp);
	merge(array, left, mid, right, tmp);

}

/**
 * merge_sort - a wrapping function for merge sorting
 * @array: the array to sort
 * @size: the size of the array
 * Reutrn: void
*/
void merge_sort(int *array, size_t size)
{
	int *tmp;

	tmp = malloc(size * sizeof(int));
	if (tmp == NULL)
		return;
	split(array, 0, size, tmp);
	free(tmp);
}
