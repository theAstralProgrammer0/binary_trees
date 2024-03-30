#include "binary_trees.h"

/**
 * min_val - Aux
 *
 * Description: a function to find the minimum value of a binary tree
 *
 * @tree: pointer to root of tree
 *
 * Return: (int) min_value
 */
int min_val(binary_tree_t *tree)
{
	int min_value, min_left, min_right;

	if (!tree)
		return (INT_MAX);

	min_left = min_val(tree->left);
	min_right = min_val(tree->right);

	min_value = 0;
	if (min_left < min_right)
		min_value = min_left;
	else
		min_value = min_right;
	if (min_value > tree->n)
		min_value = tree->n;

	return (min_value);
}

/**
 * max_val - Aux
 *
 * Description: a function to find the maximum value of a binary tree
 *
 * @tree: pointer to root of tree
 *
 * Return: (int) max_value
 */
int max_val(binary_tree_t *tree)
{
	int max_value, max_left, max_right;

	if (!tree)
		return (INT_MIN);

	max_left = max_val(tree->left);
	max_right = max_val(tree->right);

	max_value = 0;
	if (max_left > max_right)
		max_value = max_left;
	else
		max_value = max_right;
	if (max_value < tree->n)
		max_value = tree->n;

	return (max_value);
}


/**
 * is_bst - Aux
 *
 * Description: a function that recursively checks if the left and right half
 * of a binary tree meet the requirements of a Binary Search Tree
 *
 * @tree: pointer to root of tree
 *
 * Return: (int) 1 if BST, 0 otherwise
 */
int is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (1);

	if (tree->left && max_val(tree->left) >= tree->n)
		return (0);
	if (tree->right && min_val(tree->right) <= tree->n)
		return (0);
	if (!is_bst(tree->left) ||
	    !is_bst(tree->right))
		return (0);

	return (1);
}

/**
 * binary_tree_is_bst - Entry Point
 *
 * Description: a function that checks if a binary tree is a valid
 * Binary Search Tree
 *
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: (int) 1 if tree is a valid BST, and 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst((binary_tree_t *)tree));
}
