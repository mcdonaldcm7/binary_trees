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
 * node_height - Recursively traverses a tree to compute the max height
 *
 * @node: Root node to begin traversal
 * @count: Height of current node
 *
 * Return: Max height of a binary tree
 */
unsigned int node_height(const binary_tree_t *node, unsigned int count)
{
	unsigned int a, b;

	if (!node)
		return (count - 1);
	a = node_height(node->left, count + 1);
	b = node_height(node->right, count + 1);
	return (a >= b ? a : b);
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
 * is_tree_complete - Checks wether or not a tree is complete
 *
 * @node: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree pointed to by node is complete, 0 otherwise
 */
int is_tree_complete(const binary_tree_t *node)
{
	unsigned int height_left, height_right;

	if (!node)
		return (1);
	if (node->parent && (node == node->parent->right))
		if (!((int) is_tree_full(node->parent->left) &&
				height_check(node->parent->left)))
			return (0);
	height_left = node->left ? node_height(node->left, 0) : 0;
	height_right = node->right ? node_height(node->right, 0) : 0;
	if ((height_right > height_left) || (height_left - height_right) > 1)
		return (0);
	if (!node->left && node->right)
		return (0);
	else if (node->left && !node->right)
	{
		if (node->left->left || node->left->right)
			return (0);
		if (!node->parent)
			return (1);
		if (node == node->parent->left)
			return (1);
		return ((int) is_tree_full(node->parent->left) &&
				height_check(node->parent->left));
	}
	return ((int) is_tree_complete(node->left) &&
			is_tree_complete(node->right));
}

/**
 * binary_tree_is_complete - Checks if a binary tree is complete
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is complete, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_tree_complete(tree));
}
