/******************************************************************************
 * dbl.h - A header file for a double wrapper
 * 1.1.0 - last updated 12 Nov 2020
 * By: Murray Estes
 ******************************************************************************/

#ifndef __DBL_H__
#define __DBL_H__

#include <stdio.h>
#include "const.h"

typedef struct DOUBLETYPE dbl_t;
dbl_t *newDouble(double d, int prec);
void setPrecision(dbl_t *dbl, int prec);
double getDouble(dbl_t *dbl);
double setDouble(dbl_t *dbl, double d);
int printDouble(FILE *fp, void *dbl);
int compareDouble(void *d_a, void *d_b);

#endif
