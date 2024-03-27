#include "binary_trees.h"

/**
 * binary_tree_sibling - Entry Point
 *
 * Description: finds the sibling of a node
 *
 * @node: pointer to the node to find the sibling
 *
 * Return: (binary_tree_t *) pointer to the sibling node, NULL otherwise
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (node->parent->left == node ? node->parent->right :
		node->parent->right == node ? node->parent->left : NULL);
}
