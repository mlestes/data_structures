/******************************************************************************
 * sll.h - header file for sll.c
 * 1.1.0 - last updated 12 Nov 2020
 * By: Murray Estes
 ******************************************************************************/

#ifndef __SLL_H__
#define __SLL_H__

/*** INCLUDES ***/
#include <stdio.h>
#include <stdlib.h>
#include "const.h"

/*** PUBLIC INTERFACE ***/
typedef struct SINGLE_LINKED_LIST_TYPE sll_t;
typedef struct SINGLE_LINKED_LIST_NODE sll_node;

extern sll_t    *newSLL(void (*p)(FILE *fp, void *item),
		        int (*c)(void *a, void *b));
extern int       sizeSLL(sll_t *ls);
extern int       insertSLL(sll_t *ls, void *item);
extern void     *deleteSLL(sll_t *ls, void *item);
extern sll_node *getNodeSLL(sll_t *ls);
extern sll_node *nextNodeSLL(sll_node *n);
extern void     *getNodeValueSLL(sll_node *n);
extern void      printSLL(sll_t *ls, FILE *fp);

#endif
