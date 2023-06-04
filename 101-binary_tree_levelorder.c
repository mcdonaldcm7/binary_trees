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
 * node_depth - Recursively traverses a tree to compute the depth
 *
 * @node: Root node to begin traversal
 * @count: depth of current node
 *
 * Return: Depth of a binary tree
 */
unsigned int node_depth(const binary_tree_t *node, unsigned int count)
{
	if (!node)
		return (count - 1);
	return (node_depth(node->parent, count + 1));
}

/**
 * level_preorder - Traverses a given level of a tree
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to the function to call for each node
 * @level: Level of the node to traverse
 *
 * Return :Nothing
 */
void level_preorder(const binary_tree_t *tree, void (*func)(int),
		unsigned int level)
{
	binary_tree_t *left_node, *right_node;

	if (!tree || !func)
		return;
	left_node = tree->left;
	right_node = tree->right;
	if (node_depth(tree, 0) == level)
		func(tree->n);
	if (left_node)
		level_preorder(left_node, func, level);
	if (right_node)
		level_preorder(right_node, func, level);
}

/**
 * binary_tree_levelorder - Goes through a binary tree using level-order
 * traversal
 *
 * @tree: Pointer to the root node of the tree to traverse
 * @func: Pointer to a function to call for each node
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	unsigned int level, height;

	if (!tree || !func)
		return;
	height = node_height(tree, 0);
	for (level = 0; level <= height; level++)
	{
		level_preorder(tree, func, level);
	}
}
