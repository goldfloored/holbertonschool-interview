#include "slide_line.h"

/**
 * merge - merges array adjacent identical array values in specified direction
 * @line: pointer to array of integers
 * @size: size of array
 * @direction: direction to merge values
 */
void merge(int *line, size_t size, int direction)
{
	size_t i;

	if (direction == SLIDE_LEFT)
		for (i = 0; line[i] && i < size; ++i)
			MERGE();
	else
		for (i = size - 1; line[i] && (int) i > -1; --i)
			MERGE();
}

/**
 * slide - slides array values in specified direction
 * @line: pointer to array of integers
 * @size: size of array
 * @direction: direction to slide values
 */
void slide(int *line, size_t size, int direction)
{
	static int merged;
	size_t i, empt;

	if (direction == SLIDE_LEFT)
	{
		for (empt = 0; line[empt] && empt < size; ++empt)
			;
		for (i = empt + 1; i < size; ++i)
			SWAP();
	}
	else
	{
		for (empt = size - 1; line[empt] && (int) empt > -1; --empt)
			;
		for (i = empt - 1; (int) i > -1; --i)
			SWAP();
	}
	merged = 1;
}

/**
 * slide_line - slides and merges array of integers
 * @line: pointer to array of integers
 * @size: size of array
 * @direction: direction to slide and merge
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
	slide(line, size, direction);
	merge(line, size, direction);
	slide(line, size, direction);
	return (1);
}
