#include "binary_trees.h"
#include <stdio.h>

/**
 * both_node - Traverses the both node upward to locate a common ancestor
 *
 * @left: Pointer to the first node (usually the left)
 * @right: Pointer to the second node (usually the right)
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *both_node(const binary_tree_t *left,
		const binary_tree_t *right)
{
	binary_tree_t *parent;

	if (!left || !right)
		return ((void *) 0);
	parent = right->parent;
	if (parent == left || parent == left->parent)
		return (parent);
	return (both_node(left->parent, parent));
}

/**
 * second_node - Traverses the second node upward to locate a common ancestor
 *
 * @left: Pointer to the first node (usually the left)
 * @right: Pointer to the second node (usually the right)
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *second_node(const binary_tree_t *left,
		const binary_tree_t *right)
{
	binary_tree_t *parent;

	if (!left || !right)
		return ((void *) 0);
	parent = right->parent;
	if (parent == left || parent == left->parent)
		return (parent);
	return (second_node(left, parent));
}

/**
 * first_node - Traverses the first node upward to locate a common ancestor
 *
 * @left: Pointer to the first node (usually the left)
 * @right: Pointer to the second node (usually the right)
 *
 * Return: Pointer to the lowest common ancestor node of the two given nodes
 */
binary_tree_t *first_node(const binary_tree_t *left,
		const binary_tree_t *right)
{
	binary_tree_t *parent;

	if (!left || !right)
		return ((void *) 0);
	parent = left->parent;
	if (parent == right || parent == right->parent)
		return (parent);
	return (first_node(parent, right));
}

/**
 * binary_trees_ancestor - Find the lowest common ancestor of two nodes
 *
 * @first: Pointer to the first node
 * @second: Pointer to the second node
 *
 * Return: Pointer to the lowest common ancestor of the two given nodes,
 * 0 otherwise
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
		const binary_tree_t *second)
{
	binary_tree_t *parent;

	parent = (void *) 0;
	if (!first || !second)
		return ((void *) 0);
	else if (first == second)
	{
		parent = first->parent;
		if (parent->left == first)
			return (parent->left);
		else
			return (parent->right);
	}
	parent = first_node(first, second);
	if (parent)
		return (parent);
	parent = second_node(first, second);
	if (parent)
		return (parent);
	parent = both_node(first, second);
	return (parent);
}
