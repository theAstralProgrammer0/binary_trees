#include "binary_trees.h"

binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *x = NULL;
	binary_tree_t *y = NULL;
	binary_tree_t *b = NULL;

	if (!tree)
		return (NULL);

	x = tree;
	y = x->right;
	b = y->left;

	if (b)
	{
		x->right = b;
		y->parent = x->parent;
		x->parent = y;
		y->left = x;
		b->parent = x;
	}
	else
	{
		y->parent = x->parent;
		x->parent = y;
		y->left = x;
		x->right = NULL;
	}

	return (y);
}
