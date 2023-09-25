#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list.
 * @list: Pointer to the head of the linked list.
 * @a: First node to be swapped.
 * @b: Second node to be swapped.
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
	if (!a || !b)
		return;

	if (a->prev)
		a->prev->next = b;
	if (b->next)
		b->next->prev = a;
	a->next = b->next;
	b->prev = a->prev;
	a->prev = b;
	b->next = a;

	if (!b->prev)
		*list = b;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list in ascending order.
 * @list: Pointer to the head of the linked list.
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current;

	if (!list || !*list || !(*list)->next)
		return;

	while (swapped)
	{
		swapped = 0;
		for (current = *list; current->next; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_nodes(list, current, current->next);
				print_list(*list);
				swapped = 1;
			}
		}

		if (!swapped)
			break;

		swapped = 0;
		for (; current->prev; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_nodes(list, current->prev, current);
				print_list(*list);
				swapped = 1;
			}
		}
	}
}
