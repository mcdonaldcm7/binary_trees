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
 * is_tree_complete - Checks wether or not a tree is complete
 *
 * @node: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree pointed to by node is complete, 0 otherwise
 */
int is_tree_complete(const binary_tree_t *node)
{
	if (!node)
		return (1);
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
		return (is_tree_full(node->parent->left));
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
