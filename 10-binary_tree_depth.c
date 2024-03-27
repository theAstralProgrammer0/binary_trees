#include "binary_trees.h"

/**
 * binary_tree_depth - Entry Point
 *
 * Description: measures the depth of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the depth
 *
 * Return: (size_t) depth of the tree, 0 if tree is NULL
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t depth_l = 0;
	size_t depth_r = 0;

	if (!tree)
		return (0);

	if (tree->parent)
		depth_l = 1 + binary_tree_depth(tree->parent);
	else
		depth_l = 0;
	return (depth_l > depth_r ? depth_l : depth_r);
}
