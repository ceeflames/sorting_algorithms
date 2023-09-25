#include "sort.h"

/**
 * swap - swaps indices of the array
 * @a: int ptr
 * @b: second ptr to array[]
 *
 * Return: void
 */

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * bubble_sort - Sorts an array of int in ascending order using Bubble sort
 * @array: Array to be sorted
 * @size: Size of the array
 *
 * Return: void
 */

void bubble_sort(int *array, size_t size)
{
	int prev_swap;
	size_t i, j, k;
	(void)k;

	for (i = 0; i < size - 1; i++)
	{
		prev_swap = 0; /**Flag to check if any swap occurs in this pass*/

		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(&array[j], &array[j + 1]);
				prev_swap = 1; /**Set the flag to 1 to indicate a swap*/
			}
		}
		/** if no swap occured the the array is already sorted */
		if (prev_swap == 0)
		{
			break;
		}
		print_array(array, size);

		/**Print the array after each pass*/

	}
}
