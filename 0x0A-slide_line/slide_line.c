#include "slide_line.h"

/**
*slide_line - a function that slides and merges an array of integers
*@line: points to an array of integers containing size elements
*@size: elements of array
*@direction: direction can be either: SLIDE_LEFT, SLIDE_RIGHT
*Return: 1 upon success, or 0 upon failure
*/
int slide_line(int *line, size_t size, int direction)
{
	if (direction != 0 && direction != 1)
		return (0);
	if (line == NULL || size < 1)
		return (0);
	if (direction == 0)
		direction_left(line, size);
	if (direction == 1)
		direction_right(line, size);
	return (1);
}

/**
 * direction_left - slides a line to the left
 * @line: input array
 * @size: size of array
 */
void direction_left(int *line, size_t size)
{
	int i = 0, j, prev = 0, tmp;

	for (j = 0; j < (int)size; j++)
	{
		tmp = line[j];
		if (!tmp)
			continue;
		if (!prev)
			prev = tmp;
		else if (prev == tmp)
		{
			line[i++] = tmp << 1;
			prev = 0;
		} else
		{
			line[i++] = prev;
			prev = tmp;
		}
	}
	if (prev)
		line[i++] = prev;
	while (i < (int)size)
		line[i++] = 0;
}

/**
 * direction_right - slides a line to the right
 * @line: input array
 * @size: size of array
 */
void direction_right(int *line, size_t size)
{
	int prev = 0, i = size - 1, j, tmp;

	for (j = size - 1; j >= 0; j--)
	{
		tmp = line[j];
		if (!tmp)
			continue;
		if (!prev)
			prev = tmp;
		else if (prev == tmp)
		{
			line[i--] = tmp << 1;
			prev = 0;
		} else
		{
			line[i--] = prev;
			prev = tmp;
		}
	}
	if (prev)
		line[i--] = prev;
	while (i >= 0)
		line[i--] = 0;
}