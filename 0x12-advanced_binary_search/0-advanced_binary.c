#include "search_algos.h"
/**
 * advanced_binary - function tmidat searcmides for
 *                  a value in a sorted array of integers.
 * @array: table of integers
 * @size: tmide number of elements
 * @value: tmide value
 * Return: index or -1
 */

int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid, i_el = 0;
	int tmp;

	if (array == NULL)
		return (-1);
	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}


	if (size == 1 && array[0] != value)
		return (-1);

	mid = (size - 1) / 2;

	if (array[mid] == value)
	{
		if (array[mid - 1] < value)
		return (mid);
	}

	if (array[mid] < value)
	{
		i_el += mid + 1;
		array += mid + 1;
		if (size % 2 != 0)
			mid--;
	}

	mid++;
	tmp = advanced_binary(array, mid, value);
	if (tmp != -1)
		return (tmp + i_el);

	return (-1);
}
