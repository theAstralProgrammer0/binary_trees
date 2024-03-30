#ifndef _BINARY_TREES_H_
#define _BINARY_TREES_H_

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <limits.h>
#include <ctype.h>

/**
 * struct binary_tree_s - Binary tree node
 *
 * @n: Integer stored in the node
 * @parent: Pointer to the parent node
 * @left: Pointer to the left child node
 * @right: Pointer to the right child node
 */
typedef struct binary_tree_s
{
	int n;
	struct binary_tree_s *parent;
	struct binary_tree_s *left;
	struct binary_tree_s *right;
} binary_tree_t;

/** Auxilliary Functions **/
void recur_delete(binary_tree_t *root);
/* binary tree printer*/
void binary_tree_print(const binary_tree_t *);
/* binary tree pre-order traversal recursor */
void pre_traverse(const binary_tree_t *node, void (*func)(int));
/* binary tree in-order traversal recursor */
void in_traverse(const binary_tree_t *node, void (*func)(int));
/* binary tree post-order traversal recursor */
void post_traverse(const binary_tree_t *node, void (*func)(int));
/* jahsj */
void is_leaves(const binary_tree_t *tree, size_t *leaves);




/** Core Functions **/
/* binary tree node creator */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value);
/* binary tree left node insertor */
binary_tree_t *binary_tree_insert_left(binary_tree_t *parent, int value);
/* binary tree right node insertor */
binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value);
/* binary tree deleter */
void binary_tree_delete(binary_tree_t *tree);
/* is_leaf checker */
int binary_tree_is_leaf(const binary_tree_t *node);
/* is_root checker */
int binary_tree_is_root(const binary_tree_t *node);
/* binary tree pre-order traverser */
void binary_tree_preorder(const binary_tree_t *tree, void (*func)(int));
/* binary tree in-order traverser */
void binary_tree_inorder(const binary_tree_t *tree, void (*func)(int));
/* binary tree post-order traverser */
void binary_tree_postorder(const binary_tree_t *tree, void (*func)(int));
/* height calculator */
size_t binary_tree_height(const binary_tree_t *tree);
/* depth calculator */
size_t binary_tree_depth(const binary_tree_t *tree);
/* size calculator */
size_t binary_tree_size(const binary_tree_t *tree);
/* leaves counter */
size_t binary_tree_leaves(const binary_tree_t *tree);
size_t binary_tree_nodes(const binary_tree_t *tree);
int binary_tree_is_full(const binary_tree_t *tree);
int binary_tree_is_perfect(const binary_tree_t *tree);
binary_tree_t *binary_tree_sibling(binary_tree_t *node);
binary_tree_t *binary_tree_uncle(binary_tree_t *node);
int binary_tree_balance(const binary_tree_t *tree);


/* Advanced */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second);
int binary_tree_is_complete(const binary_tree_t *tree);
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree);
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree);
int binary_tree_is_bst(const binary_tree_t *tree);
int binary_tree_is_avl(const binary_tree_t *tree);

/* Dups */
bst_t *bst_insert(bst_t **tree, int value);
#endif /* _BINARY_TREES_H_ */
