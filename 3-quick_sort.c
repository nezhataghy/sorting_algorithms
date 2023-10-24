#include "sort.h"

/**
 * swap_int - Swap two integers in an array.
 * @m: The first integer to swap.
 * @n: The second integer to swap.
 */
void swap_int(int *m, int *n)
{
	int temp;

	temp = *m;
	*m = *n;
	*n = temp;
}

/**
 * partition - Order a subset of an array of integers
 * @array: The array of integers.
 * @size: The size of the array.
 * @gauche: The starting index of the subset to order.
 * @droite: The ending index of the subset to order.
 * Return: The final partition index.
 */
int partition(int *array, size_t size, int gauche, int droite)
{
	int *pivot, au_dessus, au_dessous;

	pivot = array + droite;
	au_dessus = au_dessous = gauche;
	while (au_dessous < droite)
	{
		if (array[au_dessous] < *pivot)
		{
			if (au_dessus < au_dessous)
			{
				swap_int(array + au_dessous, array + au_dessus);
				print_array(array, size);
			}
			au_dessus++;
		}
		au_dessous++;
	}

	if (array[au_dessus] > *pivot)
	{
		swap_int(array + au_dessus, pivot);
		print_array(array, size);
	}

	return (au_dessus);
}

/**
 * sort - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @gauche: The starting index of the array partition to order.
 * @droite: The ending index of the array partition to order.
 */
void sort(int *array, size_t size, int gauche, int droite)
{
	int part;

	if (droite - gauche > 0)
	{
		part = partition(array, size, gauche, droite);
		sort(array, size, gauche, part - 1);
		sort(array, size, part + 1, droite);
	}
}

/**
 * quick_sort - Sort an array of integers in ascending
 *              order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (!array || (size < 2))
		return;

	sort(array, size, 0, size - 1);
}
