/******************************************************************************
 * int.h - wrapper for int
 * 1.0.0 - last updated 12 Nov 2020
 * By: Murray Estes
 ******************************************************************************/

#ifndef __INT_H__
#define __INT_H__

#include <stdio.h>
#include <stdlib.h>

#define GREATER_THAN 1
#define EQUALS 0
#define LESS_THAN -1

typedef struct INTEGER int_t;
extern int_t *newInt(int i);
extern int deleteInt(int_t *i);
extern int getInt(int_t *i);
extern int setInt(int_t *it, int i);
extern void printInt(FILE *fp, void *i);
extern int compareInt(void *a, void *b);

#endif
