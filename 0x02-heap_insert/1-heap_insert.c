#include "binary_trees.h"

/**
* Insert_Queue - Inserts at last.
* @root: Heap root.
* @value: New_node node value.
* Return: Pointer to New_node node inserted ,NULL if failure.
*/
heap_t *Insert_Queue(heap_t *root, int value)
{
	queue *Queue_node, *last, *temp;
	heap_t *New_node = NULL;

	Queue_node = push(NULL, root);
	if (!Queue_node)
		return (NULL);
	last = Queue_node;
	while (Queue_node)
	{
		if (New_node)
		{
			temp = Queue_node;
			Queue_node = Queue_node->next;
			free(temp);
		}
		else if (Queue_node->node->left && Queue_node->node->right)
		{
			last = push(last, Queue_node->node->left);
			if (!last)
				return (NULL);
			last = push(last, Queue_node->node->right);
			if (!last)
				return (NULL);
			temp = Queue_node;
			Queue_node = Queue_node->next;
			free(temp);
		}
		else if (!Queue_node->node->left)
		{
			New_node = binary_tree_node(Queue_node->node, value);
			Queue_node->node->left = New_node;
		}
		else
		{
			New_node = binary_tree_node(Queue_node->node, value);
			Queue_node->node->right = New_node;
		}
	}
	return (New_node);
}
/**
* push - Pushes a value into the queue.
* @last: Last element of queue.
* @node: Node to insert.
* Return: Node inserted or NULL if failed.
*/

queue *push(queue *last, heap_t *node)
{
	queue *New_node = malloc(sizeof(queue));

	if (!New_node)
		return (NULL);

	New_node->node = node;
	New_node->next = NULL;

	if (last)
		last->next =  New_node;
	return (New_node);

}


/**
* heap_insert - Inserts into Binary Heap.
* @root: Double pointer to Heap root node.
* @value: Value to store in the node to be inserted.
* Return: Pointer to the inserted node, or NULL on failure.
*/

heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *New_node = NULL;
	int tmp;

	if (!root)
		return (NULL);

	if (!*root)
	{
		*root = binary_tree_node(NULL, value);
		return (*root);
	}
	else
	{
		New_node = Insert_Queue(*root, value);
		if (!New_node)
			return (NULL);
	}
	while (New_node->parent && New_node->parent->n < New_node->n)
	{
		tmp = New_node->n;
		New_node->n = New_node->parent->n;
		New_node->parent->n = tmp;
		New_node = New_node->parent;
	}
	return (New_node);
}

