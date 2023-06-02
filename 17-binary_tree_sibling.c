#include "binary_trees.h"

/**
 * binary_tree_sibling - Finds the sibling of a node
 *
 * @node: Pointer to the node to find the sibling
 *
 * Return: Pointer to the sibling node, NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	binary_tree_t *parent;

	if (!node || !node->parent)
		return ((void *) 0);
	parent = node->parent;
	if (parent->left == node)
		return (parent->right ? parent->right : (void *) 0);
	else if (parent->right == node)
		return (parent->left ? parent->left : (void *) 0);
	return ((void *) 0);
}
