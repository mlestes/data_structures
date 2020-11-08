/******************************************************************************
 * dll.c - Doubly Linked List
 * Murray L. Estes
 ******************************************************************************
 * Function Usage:
 * newDLL(void (*p)(FILE *, void *), int (*c)(void *, void *)) - Creates a new
 * 	doubly-linked list.
 * 	dll_t *ls = newDLL(printer, comparer);
 *
 * insertDLL(dll_t *ls, void *v) - Inserts an object into the list, returns the
 * 	index of the object.
 * 	int spt = insertDLL(ls, obj);
 *
 * findIndexDLL(dll_t *ls, void *v) - Returns the index of the passed object.
 * 	int spt = findIndexDLL(ls, obj);
 *
 * findValueDLL(dll_t *ls, int index) - Returns the object at the given index.
 * 	Returns NULL if out of bounds.
 * 	void *obj = findValueDLL(ls, spt);
 *
 * deleteIndexDLL(dll_t *ls, int index) - Deletes the value at the given index.
 * 	Returns the orginial object, or NULL if out of bounds.
 * 	void *obj = deleteIndexDLL(ls, spt);
 *
 * deleteValueDLL(dll_t *ls, void *v) - Deletes the first occurance of the
 * 	given object. Returns NULL upon failure.
 * 	void *val = deleteValueDLL(ls, v);
 *
 * sizeDLL(dll_t *ls) - Returns the number of objects in the list.
 * 	int size = sizeDLL(ls);
 *
 * headDLL(dll_t *ls) - Returns the head of the list.
 * 	void *hd = headDLL(ls);
 *
 * tailDLL(dll_t *ls) - Returns the tail of the list.
 * 	void *tl = tailDLL(ls);
 *
 * printDLL(dll_t *ls, FILE *fp) - Prints the list to the given stream.
 * 	printDLL(ls, stdout);
 *
 ******************************************************************************/

#include "dll.h"

/*** STRUCTURES ***/
typedef struct DOUBLE_NODE {

	void *value;
	struct DOUBLE_NODE *prev;
	struct DOUBLE_NODE *next;

} dll_node;

typedef struct DOUBLE_LINKED_LIST_TYPE {

	dll_node *head;
	dll_node *tail;
	int size;
	void (*printer)(FILE *, void *);
	int (*comparator)(void *, void *);

} dll_t;

/*** PRIVATE FUNCTION DECLARATIONS ***/
dll_node *new_dll_node(void *v);

/*** PUBLIC FUNCTION DEFINITIONS ***/
dll_t *newDLL(void (*p)(FILE *, void *), int (*c)(void *, void *)){

	dll_t *ls = malloc(sizeof(dll_t));
	ls->head = NULL;
	ls->tail = NULL;
	ls->size = 0;
	ls->printer = p;
	ls->comparator = c;

	return ls;

}

int insertDLL(dll_t *ls, void *v){

	dll_node *node = new_dll_node(v);
	if(ls->tail){
		ls->tail->next = node;
		node->prev = ls->tail;
	}
	else ls->head = node;
	ls->tail = node;
	int index = ls->size;
	++ls->size;

	return index;

}

int findIndexDLL(dll_t *ls, void *v){

	dll_node *tmp = ls->head;
	int index;
	while(tmp){
		if(ls->comparator(v, tmp->value) == EQUALS) return index;
		++index;
		tmp = tmp->next;
	}

	return FAIL;

}

void *findValueDLL(dll_t *ls, int index){

	//check index
	if(index > ls->size) return NULL;
	if(index < 0) return NULL;
	
	//index is good
	dll_node *tmp = ls->head;
	for(int i = 0; i < index; ++i) tmp = tmp->next;
	
	return tmp->value;

}

void *deleteValueDLL(dll_t *ls, void *v){

	int index = findIndexDLL(ls, v);
	return deleteIndexDLL(ls, index);

}

void *deleteIndexDLL(dll_t *ls, int index){

	void *out;
	if(ls->size == 0) out = NULL;
	else if(index == FAIL) out = NULL;
	else if(index == 0){ //deleting the head
		out = ls->head->value;
		ls->head = ls->head->next;
		if(ls->head) ls->head->prev = NULL;
	}
	else if(index == ls->size - 1){ //deleting the tail
		out = ls->tail->value;
		ls->tail = ls->tail->prev;
		ls->tail->next = NULL;
	}
	else { //deleting somewhere in the middle
		dll_node *tmp = ls->head;
		for(int i = 0; i < index; ++i) tmp = tmp->next;
		out = tmp->value;
		tmp->prev->next = tmp->next;
		tmp->next->prev = tmp->prev;
	}
	if(ls->size > 0) --ls->size;

	return out;

}

void *headDLL(dll_t *ls){return ls->head->value;}
void *tailDLL(dll_t *ls){return ls->tail->value;}
int sizeDLL(dll_t *ls){return ls->size;}
void printDLL(dll_t *ls, FILE *fp){

	dll_node *tmp = ls->head;
	while(tmp){
		fprintf(fp, "[");
		ls->printer(fp, tmp->value);
		fprintf(fp, "]");
		tmp=tmp->next;
	}

}

/*** PRIVATE FUNCTION DEFINITIONS ***/
dll_node *new_dll_node(void *v){

	dll_node *node = malloc(sizeof(dll_node));
	node->value = v;
	node->next = NULL;
	node->prev = NULL;

	return node;

}
