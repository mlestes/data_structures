/******************************************************************************
 * real.h - wrapper for float
 * 1.0.0 - last updated 12 Nov 2020
 * By: Murray Estes
 ******************************************************************************/

#ifndef __REAL_H__
#define __REAL_H__

#include <stdio.h>
#include <stdlib.h>
#include "const.h"

typedef struct REALTYPE real_t;
real_t *newReal(float f);
float setReal(real_t *r, float f);
float getReal(real_t *r);
float deleteReal(real_t *r);
void setPrecisionReal(real_t *r, int p);
void printReal(FILE *fp, void *r);
int compareReal(void *a, void *b);

#endif
