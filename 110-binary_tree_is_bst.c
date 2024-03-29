#include "binary_trees.h"

int min_val(binary_tree_t *tree)
{
	int value, min_left, min_right;

	if (!tree)
		return (INT_MAX);

	min_left = min_val(tree->left);
	min_right = min_val(tree->right);

	value = 0;
	if (min_left < min_right)
		value = min_left;
	else
		value = min_right;
	if (value > tree->n)
		value = tree->n;

	return (value);
}

int max_val(binary_tree_t *tree)
{
	int value, max_left, max_right;

	if (!tree)
		return (INT_MIN);

	max_left = max_val(tree->left);
	max_right = max_val(tree->right);

	value = 0;
	if (max_left > max_right)
		value = max_left;
	else
		value = max_right;
	if (value < tree->n)
		value = tree->n;

	return (value);
}


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

int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (is_bst((binary_tree_t *)tree));
}
