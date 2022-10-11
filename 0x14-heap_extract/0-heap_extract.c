#include "binary_trees.h"

/**
 * _swap - switches integers
 * @a: int to be switched
 * @b: int to be switched
 */
void _swap(int *a, int *b)
{
	*a ^= *b;
	*b ^= *a;
	*a ^= *b;
}

/**
 * sizeof_binary_tree - find the sizeof a binary tree
 * @tree: tree being measured
 * Return: size_t of num of nodes
 */
size_t sizeof_binary_tree(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + sizeof_binary_tree(tree->left) + sizeof_binary_tree(tree->right));
}

/**
 * replace - free last node of a binary tree
 * @root: the head of the binary tree
 * Return: integer stored in last node
 */
int replace(heap_t **root)
{
	heap_t *tmp, *final;
	int size;
	int res = 0;
	int bit;
	int flag = 0;

	tmp = *root;
	size = sizeof_binary_tree(*root);
	for (bit = sizeof(size) * 8 - 1; bit >= 0; bit--)
	{
		if (!bit)
		{
			if ((size >> bit) & 1)
			{
				final = tmp->right;
				tmp->right = NULL;
			}
			else
			{
				final = tmp->left;
				tmp->left = NULL;
			}
			res = final->n;
			free(final);
		}
		if ((size >> bit) & 1)
		{
			if (flag)
				tmp = tmp->right;
			flag = 1;
		}
		else if (flag)
			tmp = tmp->left;
	}
	return (res);
}


/**
 * recursive - bubble down heap node to correct location
 * @node: input node
 */
void recursive(heap_t *node)
{
	int high;

	high = node->n;
	if (node->left && node->left->n > high)
		high = node->left->n;
	if (node->right && node->right->n > high)
		high = node->right->n;
	if (high != node->n)
	{
		if (high != node->left->n)
		{
			_swap(&node->n, &node->right->n);
			recursive(node->right);
		}
		else
		{
			_swap(&node->n, &node->left->n);
			recursive(node->left);
		}
	}
}

/**
 * heap_extract - get and replace the root node of a binary heap
 * @root: root of the tree
 * Return: integer value of the root
 */
int heap_extract(heap_t **root)
{
	int node_value;

	if (!*root || !root)
		return (0);
	node_value = (*root)->n;
	if (!(*root)->left && !(*root)->right)
	{
		free(*root);
		*root = NULL;
		root = NULL;
		return (node_value);
	}
	(*root)->n = replace(root);
	recursive(*root);
	return (node_value);
}
