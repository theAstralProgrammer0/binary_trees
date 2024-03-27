#include "binary_trees.h"

binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *first_friend = (binary_tree_t *)first;
	binary_tree_t *second_friend = (binary_tree_t *)second;

	if (!first->parent || !second->parent)
		return (NULL);
	if (first->parent == second)
		return (second_friend);
	if (second->parent == first)
		return (first_friend);

	while (first_friend)
	{
		second_friend = (binary_tree_t *)second;
		while (second_friend)
		{
			if (second_friend->parent == first_friend->parent)
				return (second_friend->parent);
			second_friend = second_friend->parent;
		}
		first_friend = first_friend->parent;
	}
	return (NULL);
}
