/******************************************************************************
 * sll.h
 * By: Murray Estes
 * Description: A header file for sll.c
 ******************************************************************************/

#ifndef __SLL_H__
#define __SLL_H__

#include <stdio.h>
#include <stdlib.h>

typedef struct SinglyLinkedList sll_t;
extern sll_t *newSLL(
		     void (*p)(FILE *fp, void *item),
		     int (*c)(void *a, void *b));
extern int insertSLL(sll_t *ls, void *item);
extern void *headSLL(sll_t *ls);
extern void *tailSLL(sll_t *ls);
extern int findItemSLL(sll_t *ls, void *item);
extern void *findIndexSLL(sll_t *ls, int index);
extern void *deleteFromSLL(sll_t *ls, void *item);
extern void *deleteIndexSLL(sll_t *ls, int index);
extern int sizeSLL(sll_t *ls);
extern int printSLL(sll_t *ls, FILE *fp);

#endif
