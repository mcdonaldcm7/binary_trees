#include "binary_trees.h"
#include <stdlib.h>

/**
 * binary_tree_delete - Deletes an entire binary tree
 *
 * @tree: Pointer to the root node of the tree to delete
 *
 * Return: Nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	binary_tree_t *left_node, *right_node;

	if (!tree)
		return;
	if (!tree->left && !tree->right)
	{
		free(tree);
		return;
	}
	left_node = tree->left;
	right_node = tree->right;
	if (left_node)
		binary_tree_delete(left_node);
	if (right_node)
		binary_tree_delete(right_node);
	free(tree);
}
