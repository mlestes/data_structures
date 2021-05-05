/******************************************************************************
 * bst.c - version 0.0.1 - last updated 21 Nov 2020
 * Author: Murray L. Estes
 * A generic binary search tree
 ******************************************************************************
 * Function description and usage:
 *
 ******************************************************************************/

#include "bst.h"

/*** STRUCTURES ***/
struct BST_NODE_TYPE {

	void *value;
	struct BST_NODE_TYPE *parent;
	struct BST_NODE_TYPE *left;
	struct BST_NODE_TYPE *right;

} bst_node_t;

struct BST_TYPE {

	bst_node_t *root;
	int size;
	int (*comparator)(void *, void *);
	void (*printer)(FILE *, void *);

} bst_t;

/*** PRIVATE FUNCTION DECLARATIONS ***/
bst_node_t *new_bst_node(void *v);
void swap_node(bst_node_t *src, bst_node_t *dest);
void swap_to_leaf(bst_node_t *node);
int insert_to_left(bst_node_t *node, void *v);
int insert_to_right(bst_node_t *node, void *v);
void *delete_from_left(bst_node_t *node, void *v);
void *delete_from_right(bst_node_t *node, void *v);

/*** PUBLIC FUNCITON DEFINITIONS ***/
bst_t *newBST(int (*c)(void *, void *), void (*p)(FILE *, void *)){

	bst_t tree = malloc(sizeof(bst_t));
	tree->root = NULL;
	tree->size = 0;
	tree->comparator = c;
	tree->printer = p;

	return tree;

}

int insertBST(bst_t *tree, void *v){

	int result;
	if(tree->root = NULL){ //inserting root
		bst_node_t *n = new_bst_node(v);
		if(!n) return FAIL;
		tree->root = n;
		result = SUCCESS;
	}
	else{ //inserting left or right
		if(comparator(tree->root->value, v) == LESS_THAN)
			result = insert_to_left(tree->root, v);
		else result = insert_to_right(tree->root, v);
	}

	tree->size++;
	return result;

}

void *deleteBST(bst_t *tree, void *v){

	void *out;
	if(tree->comparator(tree->root->value, v) == EQUALS){ //delete root
		out = tree->root->value;
		swap_to_leaf(tree->root);
	}
	else if(tree->comparator(tree->root->value, v) == LESS_THAN)
		out = delete_from_left(tree->root, v);
	else out = delete_from_right(tree->root, v);

	if(out) tree->size--;
	return out;

}
