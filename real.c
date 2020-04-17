/******************************************************************************
 * real.c
 * By: Murray Estes
 * Description: A wrapper for float values. In a different repo, I have an
 * 		almost identical one using doubles.
 ******************************************************************************
 * Usage:
 * real_t *newReal(float f):
 * 	Creates a new REALTYPE object.
 * 	real_t r = newReal(3.14);
 *
 * float setReal(real_t *r, float f):
 * 	Sets a new value in the object and returns the old one.
 * 	float old = setReal(r, 1,234);
 *
 * float getReal(real_t *r):
 * 	Returns the stored float.
 * 	float f = getReal(r);
 *
 * float deleteReal(real_t *r):
 * 	Frees the object and returns the stored value
 * 	float f = deleteReal(r);
 *
 * void setPrecisionReal(real_t *r, int p):
 * 	Sets the precision for output up to 7 decimal places.
 * 	setPrecisionReal(r, 5);
 *
 * void printReal(FILE *fp, real_t *r):
 * 	Prints the stored value to the file pointer.
 * 	printReal(stdout, r);
 *
 * int compareReal(void *r1, void *r2):
 * 	Compares the two values and returns GREATER_THAN (1), EQUALS (0), or
 * 	LESS_THAN (-1).
 * 	int compare = compareReal(r1, r2);
 ******************************************************************************/

#include "real.h"

#include <stdio.h>
#include <stdlib.h>

/*** STRUCTS ***/
struct REALTYPE{

	float value;
	int precision;

};

/*** PRIVATE DECLARATIONS ***/
//none

/*** PUBLIC FUNCTIONS ***/
real_t *newReal(float f){

	real_t *r = malloc(sizeof(real_t));
	r->value = f;
	r->precision = 10;
	return r;

}

float setReal(real_t *r, float f){

	float out = r->value;
	r->value = f;
	return out;

}

float getReal(real_t *r){return r->value;}
float deleteReal(real_t *r){

	float f = r->value;
	free(r);
	return f;

}

void setPrecisionReal(real_t *r, int p){r->precision = p;}
void printReal(FILE *fp, void *v){

	real_t *r = (real_t *) v;
	switch(r->precision){
		case 0:
		fprintf(fp, "%0.0f", r->value);
		break;
		case 1:
		fprintf(fp, "%0.1f", r->value);
		break;
		case 2:
		fprintf(fp, "%0.2f", r->value);
		break;
		case 3:
		fprintf(fp, "%0.3f", r->value);
		break;
		case 4:
		fprintf(fp, "%0.4f", r->value);
		break;
		case 5:
		fprintf(fp, "%0.5f", r->value);
		break;
		default:
		fprintf(fp, "%f", r->value);

	}

}

int compareReal(void *r1, void *r2){

	real_t *a = (real_t *) r1; real_t *b = (real_t *) r2;
	if(a - b > 0) return GREATER_THAN;
	else if(a - b < 0) return LESS_THAN;
	else return EQUALS;

}
