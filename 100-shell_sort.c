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
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void shell_sort(int *array, size_t size)
{
    size_t the_g = 1, m = 0, n = 0;

    if (!array || size < 2)
        return;

    while (the_g < (size / 3))
        the_g = the_g * 3 + 1;

    while (the_g >= 1)
    {
        m = the_g;
        while (m < size)
        {
            n = m;
            for (; n >= the_g && array[n - the_g] > array[n];)
            {
                swap_int(array + n, array + (n - the_g));
                n -= the_g;
            }
            m++;
        }
        print_array(array, size);
        the_g /= 3;
    }
}
