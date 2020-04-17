/******************************************************************************
 * real.h
 * By: Murray Estes
 * Description: A wrapper function for float values.
 ******************************************************************************/

#ifndef __REAL_H__
#define __REAL_H__

#include <stdio.h>
#include <stdlib.h>

/*** CONSTANTS ***/
#define GREATER_THAN 1
#define LESS_THAN -1
#define EQUALS 0

typedef struct REALTYPE real_t;
real_t *newReal(float f);
float setReal(real_t *r, float f);
float getReal(real_t *r);
float deleteReal(real_t *r);
void setPrecisionReal(real_t *r, int p);
void printReal(FILE *fp, void *r);
int compareReal(void *a, void *b);

#endif
