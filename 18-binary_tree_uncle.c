#include "binary_trees.h"

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
