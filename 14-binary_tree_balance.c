#include "binary_trees.h"

/**
 * binary_tree_height_b - Entry Point
 *
 * Description: measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: (size_t) height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height_b(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + binary_tree_height_b(tree->left);
	else
		height_l = 1;
	if (tree->right)
		height_r = 1 + binary_tree_height_b(tree->right);
	else
		height_r = 1;

	return (height_l > height_r ? height_l : height_r);
}


/**
 * binary_tree_balance - Entry Point
 *
 * Description: measures the balance factor of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: (int) balance factor, 0 if tree is NULL
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	int h_l, h_r;

	if (!tree)
		return (0);

	h_l = binary_tree_height_b(tree->left);
	h_r = binary_tree_height_b(tree->right);

	return (h_l - h_r);
}
