#include "binary_trees.h"

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
