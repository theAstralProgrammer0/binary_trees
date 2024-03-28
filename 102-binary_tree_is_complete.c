#include "binary_trees.h"

/**
 * is_tree_comp - Auxilliary Function
 *
 * Description: checks if left and right subtrees of a binary tree is comp
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: (int) 1 if comp, 0 otherwise
 */
int is_tree_comp(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
		return (1);

	if ((!tree->left || !tree->right) && tree->right)
		return (0);

	return (is_tree_comp(tree->left) && is_tree_comp(tree->right));
}


/**
 * binary_tree_is_comp - Entry Point
 *
 * Description: checks if a binary tree is a comp binary tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: (int) 1 if comp, 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_tree_comp(tree));
}
