#include "sort.h"

/**
 * cocktail_sort_list - Implementaion of cocktail sort algorithms
 * @list: Head of the list
 *
 * Return: Nothing
 */
void cocktail_sort_list(listint_t **list)
{
	int stat = 1;
	listint_t *current, *start, *end;

	if (list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	end = NULL;
	start = NULL;
	while (stat)
	{
		stat = 0;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				swap_node_forward(current, current->next, list);
				print_list(*list);
				stat = 1;
				continue;
			}
			current = current->next;
		}
		if (!stat)
			break;
		stat = 0;
		end = current;
		current = current->prev;
		while (current->prev != start)
		{
			if (current->n < current->prev->n)
			{
				swap_node(current, current->prev, list);
				print_list(*list);
				stat = 1;
				continue;
			}
			current = current->prev;
		}
		start = current;
	}
}

/**
 * swap_node_forward - swap the two nodes in a list
 * @key: Node in a list
 * @ne: previous node to key
 * @list: Head of the list
 *
 * Return: Nothing
 */
void swap_node_forward(listint_t *key, listint_t *ne, listint_t **list)
{
	key->next = ne->next;
	ne->prev = key->prev;
	key->prev = ne;
	ne->next = key;
	if (key->next)
	{
		key->next->prev = key;
	}
	if (ne->prev)
	{
		ne->prev->next = ne;
	}
	else
	{
		*list = ne;
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
