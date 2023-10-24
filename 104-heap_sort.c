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
 * heap_max - Turn a binary tree into a complete binary heap.
 * @array: An array of integers representing a binary tree.
 * @size: The size of the array/tree.
 * @base: The index of the base row of the tree.
 * @racine: The racine node of the binary tree.
 */
void heap_max(int *array, size_t size, size_t base, size_t racine)
{
	size_t gauche, droite, the_L;

	gauche = 2 * racine + 1;
	droite = 2 * racine + 2;
	the_L = racine;

	if (gauche < base && array[gauche] > array[the_L])
		the_L = gauche;
	if (droite < base && array[droite] > array[the_L])
		the_L = droite;

	if (the_L != racine)
	{
		swap_int(array + racine, array + the_L);
		print_array(array, size);
		heap_max(array, size, base, the_L);
	}
}

/**
 * heap_sort -  The main function to sort an array of given size
 * @array: array to sort
 * @size: size of the array
 **/
void heap_sort(int *array, size_t size)
{
	int j = (size / 2) - 1;

	if (!array || size < 2)
		return;

	while (j >= 0)
	{
		heap_max(array, size, size, j);
		j--;
	}

	j = size - 1;
	while (j > 0)
	{
		swap_int(array, array + j);
		print_array(array, size);
		heap_max(array, size, j, 0);
		j--;
	}
}
