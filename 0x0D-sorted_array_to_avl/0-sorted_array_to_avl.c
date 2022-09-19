#include "binary_trees.h"

/**
 * helper - recursive function
 * @p: p of the current node
 * @ar: array to be converted
 * @position: position of ar
 * @stop: end of ar
 * Return: new node
 */
avl_t *helper(avl_t *p, int *ar, int stop, int position)
{
	avl_t *node;
	int half;

	if (position > stop)
		return (NULL);
	node = malloc(sizeof(avl_t));
	if (node == NULL)
		return (NULL);
	half = (position + stop) / 2;
	node->n = ar[half];
	node->parent = p;
	node->left = helper(node, ar, half - 1, position);
	node->right = helper(node, ar, stop, half + 1);
	return (node);
}

/**
 * sorted_array_to_avl - AVL tree
 * @array: to be sorted
 * @size: size the array
 * Return: AVL tree on success, or NULL
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{

	if (array == NULL)
		return (NULL);
	return (helper(NULL, array, size - 1, 0));
}
