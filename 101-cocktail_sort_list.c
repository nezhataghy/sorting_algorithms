#include "sort.h"
/**
 * swap_noeuds - flag the nodes in a list
 * @list: premier node in doubly linked list
 * @premier: address of premier node
 * @deuxieme: address of deuxieme node
 */
void swap_noeuds(listint_t **list, listint_t *premier, listint_t *deuxieme)
{
	if (premier->prev == NULL)
		*list = deuxieme;
	else
		premier->prev->next = deuxieme;

	deuxieme->prev = premier->prev;

	if (deuxieme->next != NULL)
		deuxieme->next->prev = premier;

	premier->prev = deuxieme;
	premier->next = deuxieme->next;
	deuxieme->next = premier;
}

/**
 * cocktail_sort_list - application of the cocktail sort algorithm
 * to sort numbers
 * @list: premier node of doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *my_list;
	int flag = 0;

	if (!list || !(*list) || !(*list)->next)
		return;

	my_list = *list;
	for (; !flag;)
	{
		flag = 1;
		for (; my_list->next;)
		{
			if (my_list->n > my_list->next->n)
			{
				swap_noeuds(list, my_list, my_list->next);
				print_list(*list);
				flag = 0;
				continue;
			}
			my_list = my_list->next;
		}

		if (flag)
			break;

		flag = 1;
		for (; my_list->prev;)
		{
			if (my_list->n < my_list->prev->n)
			{
				swap_noeuds(list, my_list->prev, my_list);
				print_list(*list);
				flag = 0;
				continue;
			}
			my_list = my_list->prev;
		}
	}
}
