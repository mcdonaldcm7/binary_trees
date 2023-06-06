#include "binary_trees.h"

/**
 * binary_tree_rotate_right - A function that performs a right-rotation on a
 * binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *init_root, *root, *r_right;

	if (!tree || !tree->left)
		return ((void *) 0);
	init_root = tree;
	root = tree->left;
	r_right = root->right;
	init_root->parent = root;
	root->right = init_root;
	init_root->left = r_right;
	tree = root;
	return (root);
}
