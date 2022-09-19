#include "search.h"

/**
 * helper_func - linear skip list
 * @value: value searching for
 * @prev: start node
 * @exp: end node
 * Return: Node with value for success, else None
 */
skiplist_t *helper_func(int value, skiplist_t *prev, skiplist_t *exp)
{
	printf("Value found between indexes [%li] and [%li]\n",
			prev->index, exp->index);
	while (prev != exp->next)
	{
		printf("Value checked at index [%li] = [%i]\n",
				prev->index, prev->n);
		if (value == prev->n)
			return (prev);
		prev = prev->next;
	}
	return (NULL);
}

/**
 * linear_skip -  find value in sorted skip list
 * @list: list searched through
 * @value: value searched for
 * Return: node with value otherwise None
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *prev, *tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp)
	{
		prev = tmp;
		if (tmp->express)
			tmp = tmp->express;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			break;
		}
		printf("Value checked at index [%li] = [%i]\n", tmp->index, tmp->n);
		if (value <= tmp->n)
			return (helper_func(value, prev, tmp));
	}
	return (helper_func(value, prev, tmp));
}
