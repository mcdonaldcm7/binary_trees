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
	else if(!node->left && !node->right)
		return (1);
	return ((int) is_tree_full(node->left) && is_tree_full(node->right));
}

/**
 * binary_tree_is_full - Checks if a binary tree is full
 *
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if tree is full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_tree_full(tree));
}
