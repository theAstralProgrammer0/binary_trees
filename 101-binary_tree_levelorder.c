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

/**
 * we print the n member of the nodes at this level
 */
void level_print(const binary_tree_t *root, int level, void (*func)(int))
{
	
	if (level == 0)
		func(root->n);

	else if (level > 0)
	{
		level_print(root->left, level - 1, func);
		level_print(root->right, level - 1, func);
	}
}

/**
 * we set the level to be printed
 */
void level_setter(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	h = binary_tree_height(tree);
	for (i = 0; i <= h; i++)
		level_print(tree, i, func);
}

/**
 * driver function to print at all levels
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;

	level_setter(tree, func);
}
