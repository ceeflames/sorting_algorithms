#include "sort.h"

/**
 * bubble_sort - Sorts an array of int in ascending order using Bubble sort
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int tmp;
	size_t i, j, n;

	if (array == NULL || size < 2)
		return;

	n = size;
	j = 0;
	while (n > 0)
	{
		for (i = 0; i < n - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				j = i + 1;
				print_array(array, size);
			}
		}
		n = j;
	}

}
