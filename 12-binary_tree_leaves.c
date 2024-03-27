#include "binary_trees.h"

/**
 * binary_tree_leaves - Entry Point
 *
 * Description: measures the leaves of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the leaves
 *
 * Return: (size_t) leaves of the tree, 0 if tree is NULL
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


size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t leaves = 0;

	get_leaves(tree, &leaves);

	return (leaves);
}
