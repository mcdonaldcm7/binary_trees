#include "binary_trees.h"

/**
 * binary_tree_rotate_left - A function that performs a left-rotation on a
 * binary tree
 *
 * @tree: Pointer to the root node of the tree to rotate
 *
 * Return: Pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *init_root, *root, *r_left;

	if (!tree || !tree->right)
		return ((void *) 0);
	init_root = tree;
	root = tree->right;
	r_left = root->left;
	init_root->parent = root;
	root->left = init_root;
	init_root->right = r_left;
	tree = root;
	return (root);
}
