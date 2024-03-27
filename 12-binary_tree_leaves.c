#include "binary_trees.h"

/**
 * get_leaves - Auxilliary Function
 *
 * Description: This function counts the leaves on each side of the tree
 *
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * @leaves: count of the leaf nodes in the binary tree
 *
 * Return: Nothing
 */
void get_leaves(const binary_tree_t *tree, size_t *leaves)
{
	size_t is_leaf = 0;

	if (!tree)
		return;

	if (tree->left)
	{
		is_leaf = 0;
		get_leaves(tree->left, leaves);
	}
	else
		is_leaf = 1;

	if (tree->right)
	{
		is_leaf = 0;
		get_leaves(tree->right, leaves);
	}
	else
		is_leaf = 1;

	if (is_leaf)
		(*leaves)++;
}


/**
 * binary_tree_leaves - Entry Point
 *
 * Description:  counts the leaves in a binary tree
 *
 * @tree: pointer to the root node of the tree to count the number of leaves
 *
 * Return: (size_t) count of leaves of the tree, 0 if tree is NULL
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	if (!tree || (!tree->left && !tree->right))
		return (0);

	get_leaves(tree, &leaves);

	return (leaves);
}
