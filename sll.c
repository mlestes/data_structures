/******************************************************************************
 * sll.c
 * By: Murray Estes
 * Description: Implements a generic singly-linked list. Duplicates are  
 * inserted.
 ******************************************************************************
 * Function usage:
 * sll_t *newSLL( void (*p)(FILE *fp, void *item), int (*c)(void *a, void *b)):
 * 	Creates a new singly-linked object.
 * 	sll_t *ls = newSLL(printObject, comparatorObject);
 *
 * int insertSLL(sll_t *ls, void *item):
 * 	Inserts an item to the end of the list and returns the item "index".
 * 	int index = insertSLL(ls, object);
 *
 * void *deleteSLL(sll_t *ls, void *item):
 * 	Removes the first matching object from the list and returns it or NULL 
 * 	upon failure.
 * 	void *obj = deleteFromSLL(ls, item);
 *
 * int sizeSLL(sll_t *ls):
 * 	Returns the size of the list.
 * 	size = sizeSLL(ls);
 *
 * sll_node *getNodeSLL(sll_t *ls):
 * 	Returns the underlying node structure of the list.
 * 	sll_node *node = getNodeSLL(ls);
 *
 * sll_node *nextNodeSLL(sll_node *node):
 * 	Returns the next element in the list.
 * 	sll_node *nxt = nextNodeSLL(node);
 *
 * void *getNodeValueSLL(sll_node *node):
 * 	Returns the value of the list element.
 * 	void *obj = getNodeValueSLL(node);
 *
 * void printSLL(sll_t *ls, FILE *fp):
 * 	Prints each object in the list on a separate line.
 * 	printSLL(ls, stdout);
 ******************************************************************************/
#include "sll.h"

#include <stdio.h>
#include <stdlib.h>

/*** STRUCTURE DEFINITION ***/
struct SINGLE_LINKED_LIST_NODE{

	void *value;
	struct SINGLE_LINKED_LIST_NODE *next;

};

struct SINGLE_LINKED_LIST_TYPE{

	sll_node *node;
	int size;
	void (*printer)(FILE *, void *);
	int (*comparator)(void *, void *);

};

/*** PRIVATE DECLARATIONS ***/
sll_node *new_node(void *v);

/*** PUBLIC DEFINITIONS ***/
sll_t *newSLL(void (*p)(FILE *, void *), int (*c)(void *, void *)){
	
	sll_t *ls = malloc(sizeof(sll_t));
	if(!ls){
		fprintf(stderr, "Error: failed to allocate memory.\n");
		exit(FAIL);
	}
	ls->node = NULL;
	ls->size = 0;
	ls->printer = p;
	ls->comparator = c;

	return ls;

}

int insertSLL(sll_t *ls, void *item){

	sll_node *n = new_node(item);
	if(ls->node){
		sll_node *tmp = ls->node;
		while(tmp->next) tmp = tmp->next;
		tmp->next = n;
	}
	else ls->node = n; //empty list
	int index = ls->size;
	ls->size++;
	
	return index;

}

void *deleteSLL(sll_t *ls, void *item){

	sll_node *tmp = ls->node;
	void *out;
	if(!tmp) return NULL; //empty list
	else if(ls->comparator(ls->node->value, item) == EQUALS){ //deleting head
		out = ls->node->value;
		ls->node = ls->node->next;
	}
	else{
		while(ls->comparator(tmp->next->value, item) != EQUALS){
			tmp = tmp->next;
			if(!tmp->next) return NULL;
		}
		out = tmp->next->value;
		tmp->next = tmp->next->next;
	}
	--ls->size;

	return out;

}

int sizeSLL(sll_t *ls){return ls->size;}
sll_node *getNodeSLL(sll_t *ls){return ls->node;}
sll_node *nextNodeSLL(sll_node *node){return node->next;}
void *getNodeValueSLL(sll_node *node){return node->value;}
void printSLL(sll_t *ls, FILE *fp){

	sll_node *tmp = ls->node;
	while(tmp){
		fprintf(fp, "[");
		ls->printer(fp, tmp->value);
		fprintf(fp, "]");
		tmp = tmp->next;
	}

}

/*** PRIVATE FUNCTION DEFINITIONS ***/
sll_node *new_node(void *v){

	sll_node *n = malloc(sizeof(sll_node));
	if(!n){
		fprintf(stderr, "Error: failed to allocate node\n");
		exit(FAIL);
	}

	n->value = v;
	n->next = NULL;

	return n;

}
