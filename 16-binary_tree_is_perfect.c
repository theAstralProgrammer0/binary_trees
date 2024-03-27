#include "binary_trees.h"

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

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int leaf_level = -1;

	if (!tree)
		return (0);

	return (is_tree_perfect(tree, 0, &leaf_level));
}
