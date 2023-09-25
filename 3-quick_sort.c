#include "sort.h"

/**
 * swap - Swaps two integers
 * @a: Pointer to the first integer
 * @b: Pointer to the second integer
 */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * lomuto_partition - Lomuto partition scheme
 * @array: Pointer to the array to be partitioned
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 * Return: The pivot index
 */
int lomuto_partition(int *array, int low, int high)
{
    int pivot = array[high];
    int i = low - 1;
    int j; /* Declare j outside the loop in C90 mode */

    for (j = low; j < high; j++)
    {
        if (array[j] <= pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);

    return i + 1;
}

/**
 * quick_sort_helper - Recursive helper function for quick_sort
 * @array: Pointer to the array to be sorted
 * @low: Starting index of the partition
 * @high: Ending index of the partition
 */
void quick_sort_helper(int *array, int low, int high)
{
    if (low < high)
    {
        int pivot_index = lomuto_partition(array, low, high);
        quick_sort_helper(array, low, pivot_index - 1);
        quick_sort_helper(array, pivot_index + 1, high);
    }
}

/**
 * quick_sort - Sorts an array of integers using Quick Sort
 * @array: Pointer to the array to be sorted
 * @size: Size of the array
 */
void quick_sort(int *array, size_t size)
{
    if (size <= 1)
    {
        return;  /* Array is already sorted */
    }
    quick_sort_helper(array, 0, size - 1);
}
