#include "binary_trees.h"

/**
 * binary_tree_uncle - Entry Point
 *
 * Description: finds the uncle of a node
 *
 * @node: pointer to the node to find the uncle
 *
 * Return: (binary_tree_t *) pointer to the uncle node, NULL otherwise
 */
binary_tree_t *binary_tree_uncle(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	return (node->parent ? node->parent->parent ?
		node->parent->parent->left == node->parent ?
		node->parent->parent->right :
		node->parent->parent->right == node->parent ?
		node->parent->parent->left : NULL : NULL : NULL);
}
