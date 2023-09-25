#include "sort.h"

/**
 * knuth_sequence - knuth sequence generator
 * @size: size of the seq
 *
 * Return: sequence
 */
size_t knuth_sequence(size_t size)
{
	size_t h = 1;

	while (h <= size / 3)
	{
		h = h * 3 + 1;
	}
	return (h);
}

/**
 * shell_sort - Sorts an array of in in ascending order using
 * shell sort algorithm, using the knuth sequence
 * @array: Array to be sorted
 * @size: size of the array
 *
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, interval = knuth_sequence(size);
	int temp;

	if (array == 0 || size < 2)
	{
		return;
	}

	while (interval > 0)
	{
		for (i = interval; i < size; i++)
		{
			temp = array[i];

			for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
			{
				array[j] = array[j - interval];
			}
			array[j] = temp;
		}
		print_array(array, size);
		interval = (interval - 1) / 3;
	}
}
