#include "binary_trees.h"
/**
 * binary_tree_rotate_right - Entry Point
 *
 * Description: a function that performs a right-rotation on a binary tree
 *
 * @tree: a pointer to the root node of the tree to rotate
 *
 * Return: pointer to the new root node of the tree once rotated
 */

binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *x = NULL;
	binary_tree_t *y = NULL;
	binary_tree_t *b = NULL;

	if (!tree)
		return (NULL);

	x = tree;
	y = x->left;
	b = y->right;

	if (b)
	{
		x->left = b;
		y->parent = x->parent;
		x->parent = y;
		y->right = x;
		b->parent = x;
	}
	else
	{
		y->parent = x->parent;
		x->parent = y;
		y->right = x;
		x->left = NULL;
	}

	return (y);
}
