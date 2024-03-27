#include "binary_trees.h"
/**
 * get_nodes - Entry Point
 *
 * Description: counts the nodes of a binary tree
 *
 * @tree: pointer to the root node of the tree to count the nodes
 *
 * @nodes: count of the nodes in the binary tree
 *
 * Return: Nothing
 */
void get_nodes(const binary_tree_t *tree, size_t *nodes)
{
	size_t is_node = 0;

	if (!tree)
		return;

	if (tree->left)
	{
		is_node = 1;
		get_nodes(tree->left, nodes);
	}
	else
		is_node = 0;

	if (tree->right)
	{
		is_node = 1;
		get_nodes(tree->right, nodes);
	}
	else
		is_node = 0;

	if (is_node)
		(*nodes)++;
}


/**
 * binary_tree_nodes - Entry Point
 *
 * Description: measures the nodes of a binary tree
 *
 * @tree: pointer to the root node of the tree to measure the nodes
 *
 * Return: (size_t) nodes of the tree, 0 if tree is NULL
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t nodes = 0;

	if (!tree)
		return (0);

	get_nodes(tree, &nodes);

	return (nodes);
}
