#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_insert_left - Inserts a node as the left-child of another node
 *
 * @parent: Pointer to the node to insert the left-child in
 * @value: Value to store in the new node
 *
 * Return: Pointer to the created node, or NULL on failure or if parent is NULL
 */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node, *left_node;

	if (parent == (void *) 0)
		return (parent);
	left_node = parent->left;
	new_node = malloc(sizeof(*new_node));
	if(new_node == (void *) 0)
		return (new_node);
	new_node->n = value;
	new_node->parent = parent;
	new_node->left = left_node;
	if (left_node != (void *) 0)
		left_node->parent = new_node;
	parent->left = new_node;
	return (new_node);
}
