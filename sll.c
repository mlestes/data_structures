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
 * 	Inserts an item to the end of the list and returns the item's index.
 * 	int index = insertSLL(ls, object);
 *
 * void *headSLL(sll_t *ls):
 * 	Returns the head of the list.
 * 	void *head = headSLL(ls);
 *
 * void *tailSLL(sll_t *ls):
 * 	Returns the tail of the list.
 * 	void *tail = tailSLL(ls);
 *
 * int findItemSLL(sll_t *ls, void *item):
 * 	Returns the index of the item and -1 upon failure.
 * 	int index = findItemSLL(ls, item);
 *
 * void *findIndexSLL(sll_t *ls, int index):
 * 	Returns the item at the supplied index and NULL.
 * 	void *item = findIndexSLL(ls, index);
 *
 * void *deleteFromSLL(sll_t *ls, void *item):
 * 	Removes the selected item from the list and returns it.
 * 	void *item = deleteFromSLL(ls, item);
 *
 * void deleteIndexSLL(sll_t *ls, int index):
 * 	Removes the item at the given index and returns it.
 * 	void *item = deleteIndexSLL(ls, index);
 *
 * int sizeSLL(sll_t *ls):
 * 	Returns the size of the list.
 *	int size = sizeSLL(ls);
 *
 * int printSLL(sll_t *ls, FILE *fp):
 * 	Prints each item in the list on a separate line.
 * 	printSLL(ls, stdout);
 ******************************************************************************/
#include "sll.h"

#include <stdio.h>
#include <stdlib.h>

/*** CONSTANTS ***/
#ifndef __SLL_CONST__
#define __SLL_CONST__

#define TRUE 1
#define FALSE 0
#define GT 1
#define EQ 0
#define LT -1
#define FAIL -1

#endif

/*** STRUCTURE DEFINITION ***/
struct SinglyLinkedList{

	struct SLLnode *node;
	int size;
	void (*printer)(FILE *, void *);
	int (*comparator)(void *, void *);

};

typedef struct SLLnode{

	void *value;
	int count;
	struct SLLnode *next;

} node;

/*** PRIVATE DECLARATIONS ***/
node *new_node(void *v);

/*** PUBLIC DEFINITIONS ***/
sll_t *newSLL(void (*p)(FILE *, void *), int (*c)(void *, void *)){
	
	sll_t *ls = malloc(sizeof(sll_t));
	ls->node = 0;
	ls->size = 0;
	ls->printer = p;
	ls->comparator = c;

	return ls;

}

int insertSLL(sll_t *ls, void *item){

	int index = 0;
	node *temp = ls->node;
	node *node = new_node(item);
	if(ls->node == NULL) ls->node = node;
	else{
		while(temp->next != NULL){
			temp = temp->next;
			index++;
		}
		temp->next = node;
	}

	ls->size++;
	return index;

}

void *headSLL(sll_t *ls){return ls->node->value;}
void *tailSLL(sll_t *ls){

	node *tmp = ls->node;
	while(tmp->next != NULL) tmp = tmp->next;
	return tmp->value;

}

int findItemSLL(sll_t *ls, void *item){

	int index = 0;
	if(ls == NULL) return FAIL;
	else{
		node *tmp = ls->node;
		while(ls->comparator(tmp->value, item) != EQ){
			if(tmp->next == NULL) return FAIL;
			index++;
			tmp = tmp->next;
		}
	}
	return index;
}

void *findIndexSLL(sll_t *ls, int index){

	node *tmp = ls->node;
	if(index > ls->size) return NULL;
	int i = 0;
	for(i = 0; i < index; i++) tmp = tmp->next;
	return tmp->value;

}

void *deleteFromSLL(sll_t *ls, void *item){

	int index = findItemSLL(ls, item);
	return deleteIndexSLL(ls, index);

}

void *deleteIndexSLL(sll_t *ls, int index){

	node *tmp = ls->node; node *grd = ls->node;
	if(index > ls->size || index == FAIL) return NULL;
	else if(index == 0){
		ls->node = ls->node->next;
	}
	else{
		for(int i = 0; i < index; i++) tmp = tmp->next;
		for(int i = 0; i < index - 1; i++) grd = grd->next;
		grd->next = tmp->next;
	}
	ls->size--;
	void *item = tmp->value;
	free(tmp);
	return item;

}

int sizeSLL(sll_t *ls){return ls->size;}
int printSLL(sll_t *ls, FILE *fp){

	node *tmp = ls->node;
	while(tmp){
		ls->printer(fp, tmp->value);
		fprintf(fp, "\n");
		tmp = tmp->next;
	}
	return 0;

}

/*** PRIVATE FUNCTIONS ***/
node *new_node(void *v){

	node *n = malloc(sizeof(node));
	n->value = v;
	n->count = 1;
	n->next = 0;
	
	return n;
}
