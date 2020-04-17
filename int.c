/******************************************************************************
 * int.c
 * By: Murray Estes
 * Description: A wrapper object for int type
 ******************************************************************************
 * Function usage:
 * int_t *newInt(int):
 * 	Creates a new object and sets the value.
 * 	int_t *i_t = newInt(3);
 *
 * int deleteInt(int_t *i_t):
 * 	Frees the object and returns its value.
 * 	int value = deleteInt(i_t);
 *
 * int getInt(int_t *i_t):
 * 	Returns the stored value.
 * 	int i = getInt(i_t);
 *
 * void setInt(int_t *i_t, int i):
 * 	Sets a given integer to the object's value.
 * 	setInt(i_t, i);
 *
 * printInt(FILE *fp, void *i_t):
 * 	Prints the integer object to the supplied output mode.
 * 	printInt(stdout, i_t);
 *
 * int compareInt(void *a, void *b):
 * 	Compares the objects and retures the result.
 * 	int comp = compareInt(i_a, i_b);
 ******************************************************************************/
#include "int.h"

#include <stdio.h>
#include <stdlib.h>

/*** STRUCTS ***/
struct INTEGER{

	int value;

};

/*** PRIVATE DECLARATIONS ***/
//none

/*** PUBLIC DEFINITIONS ***/
int_t *newInt(int val){

	int_t *i_t = malloc(sizeof(int_t));
	i_t->value = val;
	return i_t;

}

int deleteInt(int_t *i){

	int x = i->value;
	free(i);
	return x;

}

int getInt(int_t *i_t){return i_t->value;}
void setInt(int_t *i_t, int val){i_t->value = val;}
void printInt(FILE *fp, void *i){

	int_t *i_t = (int_t *) i;
	fprintf(fp, "%d", i_t->value);

}

int compareInt(void *i_a, void *i_b){

	int_t *a = (int_t *) i_a; int_t *b = (int_t *) i_b;
	if(a->value - b->value > 0) return GREATER_THAN;
	else if(a->value - b->value < 0) return LESS_THAN;
	else return EQUALS;

}
