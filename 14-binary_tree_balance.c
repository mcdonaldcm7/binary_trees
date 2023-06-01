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
 * tree_height - Recursively traverses a tree to compute the max height
 *
 * @node: Root node to begin traversal
 * @count: Height of current node
 *
 * Return: Max height of a binary tree
 */
unsigned int tree_height(const binary_tree_t *node, unsigned int count)
{
	if (!node)
		return (count - 1);
	return (max(tree_height(node->left, count + 1),
				tree_height(node->right, count + 1)));
}

/**
 * binary_tree_balance - Measures the balance factor of a binary tree
 *
 * @tree: Pointer to the root node of the tree to measure the balance factor
 *
 * Return: Balance factor of tree (or subtree) pointed to by tree
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	unsigned int left_height, right_height;

	left_height = right_height = 0;
	if (!tree)
		return (0);
	left_height = tree_height(tree->left, 0);
	right_height = tree_height(tree->right, 0);
	return (left_height - right_height);
}
