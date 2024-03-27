#include "binary_trees.h"

/**
 * binary_tree_nodes - Entry Point
 *
 * Description: measures the nodes of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the nodes
 *
 * Return: (size_t) nodes of the tree, 0 if tree is NULL
 */
int is_tree_full(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (1);

	if (!tree->left || !tree->right)
		return (0);

	return (is_tree_full(tree->left) && is_tree_full(tree->right));
}


int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_tree_full(tree));
}
