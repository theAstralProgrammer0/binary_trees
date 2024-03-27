#include "binary_trees.h"

/**
 * is_tree_full - Auxilliary Function
 *
 * Description: checks if left and right subtrees of a binary tree is full
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: (int) 1 if full, 0 otherwise
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


/**
 * binary_tree_is_full - Entry Point
 *
 * Description: checks if a binary tree is a full binary tree
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: (int) 1 if full, 0 otherwise
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (is_tree_full(tree));
}
