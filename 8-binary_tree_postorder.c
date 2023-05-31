#include "binary_trees.h"

/**
 * binary_tree_postorder - Traverses through a binary using post-order
 * traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int))
{
	binary_tree_t *left_node, *right_node;

	if (!tree || !func)
		return;
	left_node = tree->left;
	right_node = tree->right;
	if (left_node)
		binary_tree_postorder(left_node, func);
	if (right_node)
		binary_tree_postorder(right_node, func);
	func(tree->n);
}
