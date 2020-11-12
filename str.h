/******************************************************************************
 * str.h - header for str.c
 * 1.0.0 - last updated 12 Nov 2020
 * By: Murray Estes
 ******************************************************************************/

#ifndef __STR_H__
#define __STR_H__

#include <stdio.h>
#include <stdlib.h>

/*** CONSTANTS ***/
#define EQUAL 0
#define NOT_EQUAL 1

typedef struct STRING str_t;
str_t *newString(char *);
char *getString(str_t *);
char *setString(str_t *, char *);
int sizeString(str_t *);
char *deleteString(str_t *);
void printString(FILE *, void *);
int compareString(void *, void *);
str_t *combineString(void *, void *);

#endif
