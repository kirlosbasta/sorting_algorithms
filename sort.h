#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void swap(int *num_1, int *num_2);
void insertion_sort_list(listint_t **list);
void swap_node(listint_t *key, listint_t *pre, listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
int partition(int *array, int low, int high, size_t size);
void quick_sort_h(int *array, int low, int high, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void swap_node_forward(listint_t *key, listint_t *ne, listint_t **list);
void counting_sort(int *array, size_t size);
void print_from(const int *array, size_t size, size_t start);
void merge(int *array, size_t left, size_t mid, size_t right, int *tmp);
void split(int *array, size_t left, size_t right, int *tmp);
void merge_sort(int *array, size_t size);

#endif
