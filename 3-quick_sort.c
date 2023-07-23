#include "sort.h"

/**
 * lomuto_partition - partitions an array using the Lomuto scheme
 * @array: the array to partition
 * @low: the lowest index of the partition
 * @high: the highest index of the partition
 * @size: the size of the array
 *
 * Return: the index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot, i, j, tmp;

	pivot = array[high];
	i = low - 1;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high)
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quicksort - sorts an array of integers using the quicksort algorithm
 * @array: the array of integers to sort
 * @low: the lowest index of the partition
 * @high: the highest index of the partition
 * @size: the size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high, size);

		quicksort(array, low, pivot - 1, size);
		quicksort(array, pivot + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using
 *              the quicksort algorithm
 * @array: the array of integers to sort
 * @size: the size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}
