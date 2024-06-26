#include "binary_trees.h"

/**
 * root_exclusion - Auxilliary Function
 *
 * Description: measures the size of a binary tree excluding the root
 *
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: (size_t) size of the tree, 0 if tree is NULL
 */
size_t root_exclusion(const binary_tree_t *tree)
{
	size_t size_l = 0;
	size_t size_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		size_l = 1 + root_exclusion(tree->left);
	else
		size_l = 0;
	if (tree->right)
		size_r = 1 + root_exclusion(tree->right);
	else
		size_r = 0;

	return (size_r + size_l);
}

/**
 * binary_tree_size - Auxilliary Function
 *
 * Description: measures the size of a binary tree including root.
 *
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: (size_t) size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + root_exclusion(tree));
}

/**
 * binary_tree_leaves - Auxilliary Function
 *
 * Description:  counts the leaves in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Return: (size_t) count of leaves of the tree, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->left || !tree->right)
		return (1);

	return (binary_tree_leaves(tree->left) + binary_tree_leaves(tree->right));
}

/**
 * binary_tree_nodes - Entry Point
 *
 * Description: counts the nodes with at least 1 child in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of nodes
 *
 * Return: (size_t) count of nodes, If tree is NULL, 0
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t size, leaves;

	if (!tree)
		return (0);

	size = binary_tree_size(tree);
	leaves = binary_tree_leaves(tree);
	return (size - leaves);
}
