/******************************************************************************
 * dbl.c
 * By: Murray Estes
 * Description: A wrapper class for reals in double format.
 ******************************************************************************
 * Usage:
 * dbl_t *newDouble(double d, int prec):
 * 	Creates a new object and returns it.
 * 	dbl_t dbl = newDouble(pi, 4);
 *
 * void setPrecision(dbl_t *dbl, int prec):
 * 	Modifies the precision variable for output up to 6 decimal places. 
 * 	setPrecision(dbl, 2);
 *
 * double getDouble(dbl_t *dbl):
 * 	Returns the stored value.
 * 	double d = getDouble(dbl);
 *
 * double setDouble(dbl_t *dbl, double d):
 * 	Sets a new double into the object and returns the old value.
 * 	double d = setDouble(e);
 *
 * int printDouble(FILE *fp, void *dbl):
 * 	Prints the stored value to the given output.
 * 	printDouble(stdout, dbl);
 *
 * int compareDouble(void *d_a, void *d_b):
 * 	Compares the two objects and returns the follow results:
 * 	1 for GREATER_THAN
 * 	0 for EQUALS
 * 	-1 for LESS_THAN
 * 	int comp = compareDouble(dbl_a, dbl_b);
 ******************************************************************************/

#include "dbl.h"

#include <stdlib.h>
#include <stdio.h>

/*** STRUCTURES ***/
struct DOUBLETYPE{

	double value;
	int precision;

};

/*** PRIVATE DECLARATIONS ***/
//none

/*** PUBLIC DEFINITIONS ***/
dbl_t *newDouble(double d, int prec){

	dbl_t *dbl = malloc(sizeof(dbl_t));
	dbl->value = d;
	dbl->precision = prec;

	return dbl;

}

void setPrecision(dbl_t *dbl, int p){dbl->precision = p;}
double getDouble(dbl_t *dbl){return dbl->value;}
double setDouble(dbl_t *dbl, double d){

	double old = dbl->value;
	dbl->value = d;

	return old;

}

int printDouble(FILE *fp, void *dbl){

	dbl_t *d = (dbl_t *) dbl;
	switch(d->precision){
		case 0:
		fprintf(fp, "%0.0lf", d->value);
		break;
		case 1:
		fprintf(fp, "%0.1lf", d->value);
		break;
		case 2:
		fprintf(fp, "%0.2lf", d->value);
		break;
		case 3:
		fprintf(fp, "%0.3lf", d->value);
		break;
		case 4:
		fprintf(fp, "%0.4lf", d->value);
		break;
		case 5:
		fprintf(fp, "%0.5lf", d->value);
		break;
		default:
		fprintf(fp, "%lf", d->value);
	}

	return 0;

}

int compareDouble(void *d_a, void *d_b){

	dbl_t *a = (dbl_t *)d_a; dbl_t *b = (dbl_t *) d_b;
	if(a->value - b->value > 0) return GREATER_THAN;
	else if(a->value - b->value < 0) return LESS_THAN;
	else return EQUALS;

}
