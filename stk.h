/******************************************************************************
 * stk.h - Header for stk.c
 * 1.0.0 - last updated 12 Nov 2020
 * Author: Murray L. Estes
 ******************************************************************************/

#ifndef __MY_STK__
#define __MY_STK__

/*** INCLUDES ***/
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

/*** PUBLIC INTERFACE ***/
typedef struct STACK_TYPE stk_t;

stk_t *newStack(void (*p)(FILE *, void *));
void pushStack(stk_t *s, void *v);
void *popStack(stk_t *s);
int sizeStack(stk_t *s);
void printStack(stk_t *s, FILE *fp);

#endif
