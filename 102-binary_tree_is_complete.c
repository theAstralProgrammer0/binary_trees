#include "binary_trees.h"

/**
 * root_exclusion - Auxilliary Function
 *
 * Description: measures the size of a binary tree excluding the root
 *
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: (size_t) size of the tree, 0 if tree is NULL
 */
size_t root_exclusion(const binary_tree_t *tree)
{
	size_t size_l = 0;
	size_t size_r = 0;

	if (!tree)
		return (0);

	if (tree->left)
		size_l = 1 + root_exclusion(tree->left);
	else
		size_l = 0;
	if (tree->right)
		size_r = 1 + root_exclusion(tree->right);
	else
		size_r = 0;

	return (size_r + size_l);
}

/**
 * binary_tree_size - Auxilliary Function
 *
 * Description: measures the size of a binary tree including root.
 *
 * @tree: pointer to the root node of the tree to measure the size
 *
 * Return: (size_t) size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (1 + root_exclusion(tree));
}

/**
 * aux - Auxilliary Function
 *
 * Description: this function calls itself recursively and determines
 * whether they abide by the array structure of a complete binary tree
 *
 * @root: pointer to the root of the current tree or subtree
 *
 * @index: index of the root in consideration (left, right, subtree root, etc)
 *
 * @size: total number of nodes in the binary tree
 *
 * Return: (int) 1 if the tree maintains the complete binary tree structure
 * 0 otherwise
 */
int aux(binary_tree_t *root, int index, size_t size)
{
	if (!root)
		return (1);

	if (index >= (int)size)
		return (0);

	return (aux(root->left, (2 * index) + 1, size) &&
		aux(root->right, (2 * index) + 2, size));
}

/**
 * binary_tree_is_complete - Entry Point
 *
 * Description: This a function that checks if a binary tree is complete.
 * This is the driver function.
 *
 * @tree: pointer to the root of the current tree or subtree
 *
 * Return: (int) 1 if the tree maintains the complete binary tree structure
 * 0 otherwise
 */
int binary_tree_is_complete(const binary_tree_t *tree)
{
	size_t size;
	binary_tree_t *t = NULL;

	if (!tree)
		return (0);

	t = (binary_tree_t *)tree;

	size = binary_tree_size(t);

	return (aux(t, 0, size));
}
