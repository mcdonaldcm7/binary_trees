#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_node - Creates the binary tree node
 *
 * @parent: A pointer to the parent node of the node to create
 * @value: The value to put in the new node
 *
 * Return: Pointer to new node, or NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = malloc(sizeof(*new_node));
	if (new_node == (void *) 0)
		return (new_node);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = (void *) 0;
	new_node->right = (void *) 0;
	return (new_node);
}
