#include "sort.h"

void counting_sort(int *array, size_t size);
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
 * counting_sort - this is a counting sort method implementation
 * @array: array to sort
 * @size: array size
 */
void counting_sort(int *array, size_t size)
{
	int the_max, j = 0, *nombre = NULL, *triee = NULL;

	if (!array || size < 2)
		return;

	triee = malloc(sizeof(int) * size);
	if (!triee)
		return;

	the_max = max_func(array, size);

	nombre = malloc(sizeof(int) * (the_max + 1));
	if (!nombre)
	{
		free(triee);
		triee = NULL;
		return;
	}

	while (j < (the_max + 1))
	{
		nombre[j] = 0;
		j++;
	}
	j = 0;
	while (j < (int)size)
	{
		nombre[array[j]] += 1;
		j++;
	}
	j = 0;
	while (j < (the_max + 1))
	{
		nombre[j] += nombre[j - 1];
		j++;
	}
	print_array(nombre, the_max + 1);

	j = 0;
	while (j < (int)size)
	{
		triee[nombre[array[j]] - 1] = array[j];
		nombre[array[j]] -= 1;
		j++;
	}
	j = 0;
	while (j < (int)size)
	{
		array[j] = triee[j];
		j++;
	}

	free(triee);
	free(nombre);
}
