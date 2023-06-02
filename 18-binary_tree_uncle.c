#include "binary_trees.h"

/**
 * binary_tree_uncle - Finds the uncle of a node
 *
 * @node: Pointer to the node to find the uncle
 *
 * Return: Pointer to uncle node, NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	binary_tree_t *grand_parent;

	if (!node || !node->parent || !node->parent->parent)
		return ((void *) 0);
	grand_parent = node->parent->parent;
	if (grand_parent->left == node->parent)
		return (grand_parent->right);
	if (grand_parent->right == node->parent)
		return (grand_parent->left);
	return ((void *) 0);
}
