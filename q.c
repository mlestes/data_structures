/******************************************************************************
 * q.c - A generic queue structure
 * AUTHOR: Murray L. Estes
 ******************************************************************************
 * Function Usages:
 * newQueue(void (*p)(FILE *, void *)) - Creates a new queue struct
 * 	q_t *q = newQueue(objectPrinter);
 *
 * enqueue(q_t *q, void *v) - Adds an object to the end of the queue
 * 	enqueue(q, v);
 *
 * dequeue(q_t *q) - Removes the first object in the queue and returns it
 * 	void *obj = dequeue(q);
 *
 * sizeQueue(q_t *q) - Returns how many objects are in the queue
 * 	int count = sizeQueue(q);
 *
 * printQueue(q_t *q, FILE *fp) - Prints the objects in the queue via the 
 * 				  passed stream
 * 	printQueue(q, stdout);
 *
 ******************************************************************************/

#include "q.h"
#include "const.h"

/*** STRUCTURES ***/
//private node structure
typedef struct QUEUE_NODE_TYPE {

	void *value;
	struct QUEUE_NODE_TYPE *next;

} q_node;

typedef struct QUEUE_TYPE {
	
	q_node *node;
	q_node *tail;
	int size;
	void (*printer)(FILE *, void *);

} q_t;

/*** PRIVATE FUNCTION DECLARATIONS ***/
q_node *new_node(void *v);
void fatal(char *fmt, ...);

/*** PUBLIC FUNCTION DEFINITIONS ***/
q_t *newQueue(void (*p)(FILE *, void *)){

	q_t *q = malloc(sizeof(q_t));
	if(!q) fatal("Error: Failed to allocate memory for q_t * object\n");
	q->node = NULL;
	q->tail = NULL;
	q->size = 0;
	q->printer = p;

	return q;

}

void enqueue(q_t *q, void *v){

	if(!q->node){
		q->node = new_node(v);
		q->tail = q->node;
	}
	else{
		q_node *t = q->tail;
		t->next = new_node(v);
		q->tail = t->next;
	}
	++q->size;

}

void *dequeue(q_t *q){

	void *out = q->node->value;
	q->node = q->node->next;
	--q->size;
	return out;

}

int sizeQueue(q_t *q){return q->size;}

void printQueue(q_t *q, FILE *fp){

	q_node *tmp = q->node;
	while(tmp){
		void *out = tmp->value;
		q->printer(fp, out);
		tmp = tmp->next;
		if(tmp) fprintf(fp, "|");
	}

}

/*** PRIVATE FUNCTION DEFINITIONS ***/
q_node *new_node(void *v){

	q_node *n = malloc(sizeof(q_node));
	if(!n) fatal("Error: failed to allocate node\n");
	n->value = v;
	n->next = NULL;

	return n;

}

void fatal(char *fmt, ...){

	va_list listPtr;
	va_start(listPtr, fmt);
	vfprintf(stderr, fmt, listPtr);
	va_end(listPtr);

	exit(FAIL);

}
