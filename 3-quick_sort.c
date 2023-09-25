#include "sort.h"

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * lomuto_partition - Partition an array of integers using Lomuto's scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @low: The starting index of the subarray to partition.
 * @high: The ending index of the subarray to partition.
 *
 * Return: The final partition index.
 */
int lomuto_partition(int *array, size_t size, int low, int high)
{
	int *pivot, i, j;

	pivot = array + high;
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] < *pivot)
		{
			i++;
			if (i != j)
			{
				swap(array + i, array + j);
				print_array(array, size);
			}
		}
	}

	if (array[i + 1] > *pivot)
	{
		swap(array + (i + 1), pivot);
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * lomuto_sort - Implement Quick Sort algorithm using Lomuto's partition.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @low: The starting index of the array partition to sort.
 * @high: The ending index of the array partition to sort.
 */
void lomuto_sort(int *array, size_t size, int low, int high)
{
	int part;

	if (low < high)
	{
		part = lomuto_partition(array, size, low, high);
		lomuto_sort(array, size, low, part - 1);
		lomuto_sort(array, size, part + 1, high);
	}
}

/**
 * quick_sort - Sort an array of integers using Quick Sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	lomuto_sort(array, size, 0, size - 1);
}
