#include "binary_trees.h"

/**
 * binary_tree_height - Auxilliary Function
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
 * level_print - Auxilliary Function
 *
 * Description: we print the n member of the nodes at a certain level
 *
 * @root: pointer to root of tree or subtree at a certain level
 *
 * @level: level of tree or subtree to be printed
 *
 * @func: function pointer to print the n member of the root
 *
 * Return: Nothing
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
 * level_setter - Auxilliary Function
 *
 * Description: we set the level to be printed
 *
 * @tree: pointer to the root of the tree or subtree to be printed
 *
 * @func: function pointer to print the n member of the root
 *
 * Return: Nothing
 */
void level_setter(const binary_tree_t *tree, void (*func)(int))
{
	size_t h, i;

	h = binary_tree_height(tree);
	for (i = 0; i <= h; i++)
		level_print(tree, i, func);
}

/**
 * binary_tree_levelorder - Driver Function
 *
 * Description: a function that goes through a binary tree using level-order
 * traversal. Driver function to print at all levels
 *
 * @tree: pointer to the root node of the tree to traverse
 *
 * @func: pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
 * Return: Nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	if (!tree || !func)
		return;
	level_setter(tree, func);
}
