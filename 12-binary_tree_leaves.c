#include "binary_trees.h"
#include <stdlib.h>

/**
 * leaf_node - Counts and returns the number of leaf nodes
 *
 * @node: Pointer to node to begin count
 *
 * Return: Number of leaf node
 */
unsigned int leaf_node(const binary_tree_t *node)
{
	if (!node)
		return (0);
	if (!node->left && !node->right)
		return (1);
	return (leaf_node(node->left) +
			leaf_node(node->right));
}

/**
 * binary_tree_leaves - Counts the leaves in a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the size
 *
 * Return: Number of leaves in the tree
 */
unsigned int binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (leaf_node(tree));
}
