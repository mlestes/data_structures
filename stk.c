/******************************************************************************
 * stk.c - A generic stack object
 * AUTHOR: Murray L. Estes
 ******************************************************************************
 * Function Usage:
 * newStack(void (*p)(FILE *, void *)) - Creates a new Stack object
 * 	stk_t *s = newStack(objPrint);
 *
 * pushStack(stk_t *s, void *v) - Pushes an object onto the stack
 * 	pushStack(s, v);
 *
 * popStack(stk_t *s) - Pops an object off of the stack and returns it
 * 	void *obj = pushStack(s);
 *
 * sizeStack(stk_t *s) - Returns the number of objects in the stack.
 * 	int count = sizeStack(s);
 *
 * printStack(stk_t *s, FILE *fp) - Prints the stack to the passed stream
 * 	printStack(s, stdout);
 *
 ******************************************************************************/

#include "stk.h"

/*** STRUCTURES ***/
typedef struct STACK_NODE {

	void *value;
	struct STACK_NODE *next;

} s_node;

typedef struct STACK_TYPE {

	s_node *node;
	int size;
	void (*printer)(FILE *, void *);

} stk_t;

/*** PRIVATE FUNCTION DECLARATIONS ***/
s_node *new_node(void *v);
void fatal(char *fmt, ...);

/*** PUBLIC FUNCTION DEFINITIONS ***/
stk_t *newStack(void (*p)(FILE *, void *)){

	stk_t *s = malloc(sizeof(stk_t));
	if(!s) fatal("Error: Failed to allocate stack object\n");
	s->node = NULL;
	s->size = 0;
	s->printer = p;

	return s;

}

void pushStack(stk_t *s, void *v){

	if(!s->node) s->node = new_node(v);
	else{
		s_node *n = new_node(v);
		n->next = s->node;
		s->node = n;
	}
	++s->size;

}

void *popStack(stk_t *s){

	void *out = s->node->value;
	s->node = s->node->next;
	if(s->size > 0) --s->size;

	return out;

}

int sizeStack(stk_t *s){return s->size;}

void printStack(stk_t *s, FILE *fp){

	s_node *t = s->node;
	while(t){
		void *v = t->value;
		s->printer(fp, v);
		t = t->next;
		if(t) fprintf(fp, "|");
	}

}

/*** PRIVATE FUNCTION DEFINITIONS ***/
s_node *new_node(void *v){

	s_node *n = malloc(sizeof(s_node));
	if(!n) fatal("Error: Failed to allocate node object\n");
	n->value = v;
	n->next = NULL;

	return n;

}

void fatal(char *fmt, ...){

	va_list listPtr;
	va_start(listPtr, fmt);
	vfprintf(stderr, fmt, listPtr);
	va_end(listPtr);

	exit(-1);
}
