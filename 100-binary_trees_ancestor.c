#include "binary_trees.h"

binary_tree_t *ancestor_finder(binary_tree_t *f, binary_tree_t *s)
{
	if (f->parent == s)
		return (s);
	if (s->parent == f)
		return (f);
	if (s->parent == f->parent)
		return (f->parent);

	return (binary_trees_ancestor(f, s->parent));
}
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *f = (binary_tree_t *)first;
	binary_tree_t *s = (binary_tree_t *)second;

	if (!first || !second || !first->parent || !second->parent)
		return (NULL);
	return (ancestor_finder(f, s));
}

