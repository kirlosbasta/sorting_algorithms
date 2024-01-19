#include "sort.h"

/**
 * insertion_sort_list - implement the insertion sort algorithem
 * @list: Head of the list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *pre;

	if (list == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list)->next;
	while (current)
	{
		key = current;
		pre = current->prev;
		while (pre && key->n < pre->n)
		{
			swap_node(key, pre, list);
			pre = key->prev;
			print_list(*list);
		}
		current = current->next;
	}
}

/**
 * swap_node - swap the two nodes in a list
 * @key: Node in a list
 * @pre: previous node to key
 * @list: Head of the list
 *
 * Return: Nothing
 */
void swap_node(listint_t *key, listint_t *pre, listint_t **list)
{
	key->prev = pre->prev;
	pre->next = key->next;
	key->next = pre;
	pre->prev = key;
	if (key->prev)
	{
		key->prev->next = key;
	}
	else
	{
		*list = key;
	}
	if (pre->next)
	{
		pre->next->prev = pre;
	}
}
