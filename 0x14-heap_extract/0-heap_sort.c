#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * _switch - switches integers
 * @a: int to _switch
 * @b: int to _switch
 */
void _switch(int *a, int *b)
{
	*a *= *b;
	*b = *a / *b;
	*a = *a / *b;
}

/**
 * convert - convert an array to max heap
 * @array: array of integers
 * @index: index of the array
 * @len: lengt
 * @size: size of the arraya
 */
void convert(int *array, int size, int len, int index)
{
	int left = (index * 2) + 1;
	int right = (index * 2) + 2;
	int max = index;

	if (left > 0  && array[left] > array[max] && left < len)
		max = left;
	if (right > 0 && array[right] > array[max] && right < len)
		max = right;
	if (max != index)
	{
		_switch(array + max, array + index);
		print_array(array, size);
		convert(array, size, len, max);
	}
}
/**
 * heap_sort - sort integers into max heap
 * @array: array of integers
 * @size: size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;
	int last = size - 1;

	for (i = (size / 2) - 1; i >= 0; i--)
		convert(array, size, size, i);
	for (last = size - 1; last > 0; last--)
	{
		_switch(array + last, array);
		print_array(array, size);
		convert(array, size, last, 0);
	}
}
