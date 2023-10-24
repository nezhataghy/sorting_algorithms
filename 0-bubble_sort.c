#include "sort.h"
/**
 * bubble_sort - sorts in form of a bubble
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t n;
	int flag = 0, temp = 0;

	if (!array || (size < 2))
		return;
	while (!flag)
	{
		n = 0;
		flag = 1;
		while (n < size - 1)
		{
			if (array[n] > array[n + 1])
			{
				temp = array[n];
				array[n] = array[n + 1];
				array[n + 1] = temp;
				flag = 0;
				print_array(array, size);
			}
			n++;
		}
	}
}
