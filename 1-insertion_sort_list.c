#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *actuel, *tmp;

	if (list == NULL)
		return;

	actuel = *list;
	while (actuel != NULL)
	{
		for (; actuel->next != NULL && (actuel->next->n < actuel->n);)
		{
			tmp = actuel->next;
			actuel->next = tmp->next;
			tmp->prev = actuel->prev;

			if (actuel->prev != NULL)
				actuel->prev->next = tmp;

			if (tmp->next != NULL)
				tmp->next->prev = actuel;

			actuel->prev = tmp;
			tmp->next = actuel;

			if (tmp->prev != NULL)
				actuel = tmp->prev;
			else
				*list = tmp;

			print_list(*list);
		}
		actuel = actuel->next;
	}
}
