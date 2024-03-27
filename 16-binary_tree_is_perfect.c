#include "binary_trees.h"

/**
 * is_tree_perfect - Auxilliary Function
 *
 * Description: tracks the leaf level and checks for perfection
 *
 * @tree: pointer to the root node of the tree to check
 *
 * @level: current level in the recusion.
 *
 * @leaf_level: current leaf node's level
 *
 * Return: (int) 1 if perfect, 0 otherwise
 */
int is_tree_perfect(const binary_tree_t *tree, int level, int *leaf_level)
{
	if (!tree)
		return (1);

	if (!tree->left && !tree->right)
	{
		if (*leaf_level == -1)
			*leaf_level = level;
		return (*leaf_level == level);
	}

	if (!tree->left || !tree->right)
		return (0);

	return (is_tree_perfect(tree->left, level + 1, leaf_level) &&
		is_tree_perfect(tree->right, level + 1, leaf_level));
}

/**
 * binary_tree_is_perfect - Entry Point
 *
 * Description: checks if a binary tree is perfect
 *
 * @tree: pointer to the root node of the tree to check
 *
 * Return: (int) 1 if perfect, 0 otherwise
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leaf_level = -1;

	if (!tree)
		return (0);

	return (is_tree_perfect(tree, 0, &leaf_level));
}
