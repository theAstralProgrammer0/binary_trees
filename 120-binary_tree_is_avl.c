#include "binary_trees.h"

/**
 * binary_tree_height - Entry Point
 *
 * Description: measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height
 *
 * Return: (size_t) height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		height_l = 1 + binary_tree_height(tree->left);
	else
		height_l = 0;
	if (tree->right)
		height_r = 1 + binary_tree_height(tree->right);
	else
		height_r = 0;

	return (height_l > height_r ? height_l : height_r);
}


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

int binary_tree_is_avl(const binary_tree_t *tree)
{
	size_t height_l, height_r;

	if (!tree)
		return (0);

	height_l = binary_tree_height(tree->left);
	height_r = binary_tree_height(tree->right);

	printf("height_l - height_r = %d\n", (int)(height_l - height_r)); 
	printf("height_l - height_r = %d\n", abs((int)(height_l - height_r)));
	printf("height_r - height_l = %d\n", (int)(height_r - height_l)); 
	if (!binary_tree_is_bst(tree))
		return (0);
	if (abs((int)(height_l - height_r)) > 1)
		return (0);

	return (1);
}
