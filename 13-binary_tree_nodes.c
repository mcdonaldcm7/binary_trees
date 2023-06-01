#include "binary_trees.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * single_child_node - Counts and returns the number of single child node
 *
 * @node: Pointer to node to begin count
 *
 * Return: Number of single child node
 */
unsigned int single_child_node(const binary_tree_t *node, unsigned int *count)
{
	if (!node)
		return (0);
	if (node->left || node->right)
		(*count) += 1;
	return (single_child_node(node->left, count) +
			single_child_node(node->right, count));
}

/**
 * binary_tree_nodes - Counts the nodes with at least a child in a binary tree
 *
 * @tree: Pointer to the root node of the tree to count the nodes
 *
 * Return: Number of nodes in the tree
 */
unsigned int binary_tree_nodes(const binary_tree_t *tree)
{
	unsigned int *count, nodes;

	if (!tree)
		return (0);
	count = malloc(sizeof(*count));
	*count = 0;
	single_child_node(tree, count);
	nodes = *count;
	free(count);
	return (nodes);
}
