/******************************************************************************
 * dbl.h
 * By: Murray Estes
 * Description: A header file for a wrapper for doubles.
 ******************************************************************************/

#ifndef __DBL_H__
#define __DBL_H__

#include <stdio.h>

/*** CONSTANTS ***/
#define GREATER_THAN 1
#define LESS_THAN -1
#define EQUALS 0

typedef struct DOUBLETYPE dbl_t;
dbl_t *newDouble(double d, int prec);
void setPrecision(dbl_t *dbl, int prec);
double getDouble(dbl_t *dbl);
double setDouble(dbl_t *dbl, double d);
int printDouble(FILE *fp, void *dbl);
int compareDouble(void *d_a, void *d_b);

#endif
