#include "binary_trees.h"

/**
 * is_tree_full - Recursively traverse a binary tree to check if is full
 *
 * @node: Pointer to the root node of the tree (or subtree) to check
 *
 * Return: 1 if tree is full, 0 otherwise
 */
int is_tree_full(const binary_tree_t *node)
{
	if ((!node->left && node->right) || (node->left && !node->right))
		return (0);
	else if (!node->left && !node->right)
		return (1);
	return ((int) is_tree_full(node->left) && is_tree_full(node->right));
}

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
 * height_check - Performs a height check for each and every level of the tree
 *
 * @node: Pointer to the node to begin check from (may or my not be the root)
 *
 * Return: 1 if all levels of the tree (or subtree) pointed to by node has the
 * same level, 0 otherwise
 */
int height_check(const binary_tree_t *node)
{
	if (!node->left && !node->right)
		return (1);
	if (node_height(node->left, 0) != node_height(node->right, 0))
		return (0);
	return ((int) height_check(node->left) && height_check(node->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return ((int) (is_tree_full(tree) && height_check(tree)));
}
