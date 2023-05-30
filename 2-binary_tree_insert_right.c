#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_right - Inserts a node as the right-child of another node
 *
 * @parent: Pointer to the node to insert the right-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *right_node;

	if (parent == (void *) 0)
		return (parent);
	right_node = parent->right;
	new_node = malloc(sizeof(*new_node));
	if (new_node == (void *) 0)
		return (new_node);
	new_node->n = value;
	new_node->parent = parent;
	new_node->right = right_node;
	new_node->left = (void *) 0;
	if (right_node != (void *) 0)
		right_node->parent = new_node;
	parent->right = new_node;
	return (new_node);
}
