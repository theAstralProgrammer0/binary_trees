#include "binary_trees.h"

/**
 * height_checker - Auxilliary Funcntion
 *
 * Description: This is a function that recursively counts the tree levels
 *
 * @node: pointer to subject node
 *
 * @height: pointer to height of the tree
 *
 * Return: Nothing
 */
void height_checker_left(const binary_tree_t *node, size_t *h)
{
	if (!node)
		return;

	(*h)++;
	if (node->left)
		height_checker_left(node->left, h);
}

void height_checker_right(const binary_tree_t *node, size_t *h)
{
	if (!node)
		return;

	(*h)++;
	if (node->right)
		height_checker_right(node->right, h);
}


/**
 * binary_tree_height - Entry Point
 *
 * Description: This is a function that measures the height of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the height.
 *
 * Return: (size_t) height of binary tree
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = -1;
	size_t height_r = -1;

	if (!tree)
		return (0);

	height_checker_left(tree, &height_l);
	height_checker_right(tree, &height_r);

	return (height_l > height_r ? height_l : height_r);
}
