#include "binary_trees.h"

/**
 * binary_tree_height - Entry Point
 *
 * Description: measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: (int) height of the tree, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int height_l = 0;
	int height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + binary_tree_balance(tree->left);
	else
		height_l = 0;
	if (tree->right)
		height_r = 1 + binary_tree_balance(tree->right);
	else
		height_r = 0;

	return (height_l - height_r);
}
