#include "sort.h"
/**
 * max_func - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: The maximum integer in the array.
 */
int max_func(int *array, int size)
{
	int the_max = array[0], j = 1;

	while (j < size)
	{
		if (array[j] > the_max)
			the_max = array[j];
		j++;
	}
	return (the_max);
}

/**
 * radix_c_sort - Sort the significant digits of an array of integers
 *                       in ascending order using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 * @sig: The significant digit to sort on.
 * @ptr: A ptr to store the sorted array.
 */
void radix_c_sort(int *array, size_t size, int sig, int *ptr)
{
	size_t j = 0;
	int nombre[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	while (j < size)
	{
		nombre[(array[j] / sig) % 10] += 1;
		j++;
	}
	j = 0;

	while (j < 10)
	{
		nombre[j] += nombre[j - 1];
		j++;
	}

	j = size - 1;
	for (; (int)j >= 0; j--)
	{
		ptr[nombre[(array[j] / sig) % 10] - 1] = array[j];
		nombre[(array[j] / sig) % 10] -= 1;
	}

	j = 0;
	while (j < size)
	{
		array[j] = ptr[j];
		j++;
	}
}

/**
 * radix_sort - The main function to that sorts arr[]
 * of size n using Radix Sort
 * @array: array
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int the_max, sig = 1, *ptr = NULL;

	if (!array || size < 2)
		return;

	ptr = malloc(sizeof(int) * size);
	if (!ptr)
		return;

	the_max = max_func(array, size);
	while (the_max / sig > 0)
	{
		radix_c_sort(array, size, sig, ptr);
		print_array(array, size);
		sig *= 10;
	}

	free(ptr);
	ptr = NULL;
}
