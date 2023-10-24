#include "sort.h"
/**
 * selection_sort - uses the selection algo to sort
 * an array
 * @array: array to be sorted
 * @size: size of the array
 */
void selection_sort(int *array, size_t size)
{
	int counter, temp, drapeau;
	size_t m = 0, n;

	if (!array)
		return;
	while (m < size)
	{
		drapeau = 0;
		n = m + 1;
		counter = m;
		while (n < size)
		{
			if (array[counter] > array[n])
			{
				counter = n;
				drapeau += 1;
			}
			n++;
		}
		temp = array[m];
		array[m] = array[counter];
		array[counter] = temp;
		if (drapeau != 0)
			print_array(array, size);
		m++;
	}
}
