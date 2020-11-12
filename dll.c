/******************************************************************************
 * dll.c version 1.2.0 - last updated 12 Nov 2020
 * Author: Murray L. Estes
 * A generic doubly linked list
 ******************************************************************************
 * Function Usage:
 * newDLL(void *v, void (*p)(FILE *, void *), int (*c)(void *, void *)) - 
 * 	Creates a new doubly-linked list.
 * 	dll_t *ls = newDLL(printer, comparer);
 *
 * insertDLL(dll_t *ls, void *v) - Inserts an object into the list, returns the
 * 	index of the object.
 * 	int spt = insertDLL(ls, obj);
 *
 * deleteDLL(dll_t *ls, void *v) - Deletes the first occurance of the
 * 	given object. Returns NULL upon failure.
 * 	void *val = deleteValueDLL(ls, v);
 *
 * sizeDLL(dll_t *ls) - Returns the size of the list.
 * 	int sze = sizeDLL(ls);
 *
 * headDLL(dll_t *ls) - Returns the head of the list.
 * 	dll_node *hd = headDLL(ls);
 *
 * tailDLL(dll_t *ls) - Returns the tail of the list.
 * 	dll_node *tl = tailDLL(ls);
 *
 * getNodeDLL(dll_t *ls) - Returns the underlying dll_node structure.
 * 	dll_node *n = getNodeDLL(ls);
 *
 * nextNodeDLL(dll_node *n) - Returns the next item in the list.
 * 	dll_node *nxt = nextDLL(n);
 *
 * prevNodeDLL(dll_node *n) - Returns the previous item in the list.
 * 	dll_node *prv = prevDLL(n);
 *
 * getNodeValueDLL(dll_node *n) - Returns the value of the element.
 * 	void *val = getNodeValueDLL(n);
 *
 * printDLL(dll_t *ls, FILE *fp) - Prints the list to the given stream.
 * 	printDLL(ls, stdout);
 *
 ******************************************************************************/

#include "dll.h"

/*** STRUCTURES ***/
struct DOUBLE_LINKED_LIST_NODE {

	void *value;
	struct DOUBLE_LINKED_LIST_NODE *next;
	struct DOUBLE_LINKED_LIST_NODE *prev;

};

struct DOUBLE_LINKED_LIST_TYPE {

	dll_node *node;
	dll_node *head;
	dll_node *tail;
	int size;
	void (*printer)(FILE *, void *);
	int (*comparator)(void *, void *);

};

/*** PRIVATE FUNCTION DECLARATIONS ***/
dll_node *new_node(void *v);

/*** PUBLIC FUNCTION DEFINITIONS ***/
dll_t *newDLL(void (*p)(FILE *, void *), int (*c)(void *, void *)){

	dll_t *ls = malloc(sizeof(dll_t));
	if(!ls){
		fprintf(stderr, "Error: failed to allocate memory.\n");
		exit(FAIL);
	}
	ls->node       = NULL;
	ls->head       = ls->node;
	ls->tail       = ls->node;
	ls->size       = 0;
	ls->printer    = p;
	ls->comparator = c;

	return ls;

}

int insertDLL(dll_t *ls, void *v){

	dll_node *n = new_node(v);
	dll_node *t = ls->tail;
	if(t){
		t->next = n;
		n->prev = t;
		ls->tail = n;
	}
	else { //empty list
		ls->node = n;
		ls->head = n;
		ls->tail = n;
	}
	int index = ls->size;
	++ls->size;
	return index;

}

void *deleteDLL(dll_t *ls, void *v){

	dll_node *tmp = ls->node;
	void *out;
	//head is deleted
	if(ls->comparator(tmp->value, v) == EQUALS){
		out = tmp->value;
		ls->node = tmp->next;
		ls->head = ls->node;
		if(ls->node) ls->node->prev = NULL;
	}
	else{
		while(ls->comparator(tmp->next->value, v) != EQUALS){
			tmp = tmp->next;
			if(!tmp->next) return NULL; //not in list
		}
		dll_node *del = tmp->next;
		out = del->value;
		tmp->next = del->next;
		if(!tmp->next) ls->tail = tmp; //is the tail
		else tmp->next->prev = tmp; //somewhere in the middle
		free(del);
	}

	--ls->size;
	return out;

}

int sizeDLL(dll_t *ls){return ls->size;}
dll_node *getNodeDLL(dll_t *ls){return ls->node;}
dll_node *headDLL(dll_t *ls){return ls->head;}
dll_node *tailDLL(dll_t *ls){return ls->tail;}
dll_node *nextNodeDLL(dll_node *n){return n->next;}
dll_node *prevNodeDLL(dll_node *n){return n->prev;}
void *getNodeValueDLL(dll_node *n){return n->value;}
void printDLL(dll_t *ls, FILE *fp){

	dll_node *tmp = ls->node;
	while(tmp){
		fprintf(fp, "[");
		ls->printer(fp, tmp->value);
		fprintf(fp, "]");
		tmp = tmp->next;
	}

}

/*** PRIVATE FUNCTION DEFINITIONS ***/
dll_node *new_node(void *v){

	dll_node *n = malloc(sizeof(dll_node));
	if(!n){
		fprintf(stderr, "Error: Failed to allocate node memory\n");
		exit(FAIL);
	}

	n->value = v;
	n->next = NULL;
	n->prev = NULL;

	return n;

}
