#include "binary_trees.h"
#include <stdlib.h>

/**
 * node_size - Measures and returns the size of the node
 *
 * @node: Pointer to node to begin measuring
 *
 * Return: Size of node
 */
unsigned int node_size(const binary_tree_t *node)
{
	if (!node)
		return (1);
	return (node_size(node->left) +
			node_size(node->right));
}

/**
 * binary_tree_size - Measure the size of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Size of tree
 */
unsigned int binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (node_size(tree) - 1);
}
