#include "binary_trees.h"

/**
 * max - Checks and returns the maximum of two unsigned integers
 *
 * @a: First integer to compare
 * @b: Second integer to compare
 *
 * Return: Maximum between a, b
 */
unsigned int max(unsigned int a, unsigned int b)
{
	if (a >= b)
		return (a);
	return (b);
}

/**
 * node_height - Recursively traverses a tree to compute the max height
 *
 * @node: Root node to begin traversal
 * @count: Height of current node
 *
 * Return: Max height of a binary tree
 */
unsigned int node_height(const binary_tree_t *node, unsigned int count)
{
	if (!node)
		return (count - 1);
	return (max(node_height(node->left, count + 1),
			node_height(node->right, count + 1)));
}

/**
 * binary_tree_height - Measures the height of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the height
 *
 * Return: Height of tree
 */
unsigned int binary_tree_height(const binary_tree_t *tree)
{
	return (node_height(tree, 0));
}
