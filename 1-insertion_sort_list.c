#include "sort.h"

/**
 * switchi - switch two nodes in a list
 * @node1 : node 1
 * @node2 : node 2
 * @list : list
*/

void switchi(listint_t *node1, listint_t *node2, listint_t **list)
{
	if (node1->prev == NULL)
	{
		node2->next->prev = node1;
		node2->prev = NULL;
		node1->next = node2->next;
		node1->prev = node2;
		node2->next = node1;
		*list = node2;
		return;
	}
	if (node2->next == NULL)
	{
		(node1->prev)->next = node2;
		node1->next = NULL;
		node2->prev = node1->prev;
		node2->next = node1;
		node1->prev = node2;
		return;
	}
	else
	{
		node1->prev->next = node2;
		node2->next->prev = node1;
		node1->next = node2->next;
		node2->prev = node1->prev;
		node2->next = node1;
		node1->prev = node2;
		return;
	}
}

/**
 * insertion_sort_list - sorting list
 * @list : a list the head of it
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *next, *current;
	listint_t *prev, *rec;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	current = *list;
	next = current->next;

	while (current != NULL)
	{
		if (current->next == NULL)
			break;
		if (current->next != NULL)
			next = current->next;
		if (current->n > next->n)
		{
			switchi(current, next, list);
			print_list(*list);
			rec = next;
			prev = next->prev;
			while ((rec->n < prev->n))
			{
				switchi(prev, rec, list);
				print_list(*list);
				if (rec->prev == NULL)
					break;
				prev = rec->prev;
			}
			continue;
		}
		current = current->next;
	}
}
