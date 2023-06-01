#include "binary_trees.h"

/**
 * node_depth - Recursively traverses a tree to compute the depth
 *
 * @node: Root node to begin traversal
 * @count: depth of current node
 *
 * Return: Depth of a binary tree
 */
unsigned int node_depth(const binary_tree_t *node, unsigned int count)
{
	if (!node)
		return (count - 1);
	return (node_depth(node->parent, count + 1));
}

/**
 * binary_tree_depth - Measures the depth of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the depth
 *
 * Return: Depth of tree
 */
unsigned int binary_tree_depth(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (node_depth(tree, 0));
}
