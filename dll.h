/******************************************************************************
 * dll.h - header file for dll.c
 * Author: Murray L. Estes
 ******************************************************************************/

#ifndef __DLL_H__
#define __DLL_H__

/*** INCLUDES ***/
#include <stdio.h>
#include <stdlib.h>
#include "const.h"

/*** PUBLIC INTERFACE ***/
typedef struct DOUBLE_LINKED_LIST_TYPE dll_t;
typedef struct DOUBLE_LINKED_LIST_NODE dll_node;

dll_t *   newDLL(void (*p)(FILE *, void *), 
		 int (*c)(void *, void *));
int       insertDLL(dll_t *ls, void *v);
void     *deleteDLL(dll_t *ls, void *v);
int       sizeDLL(dll_t *ls);
dll_node *headDLL(dll_t *ls);
dll_node *tailDLL(dll_t *ls);
dll_node *nextNodeDLL(dll_node *n);
dll_node *prevNodeDLL(dll_node *n);
dll_node *getNodeDLL(dll_t *ls);
void     *getNodeValueDLL(dll_node *n);
void      printDLL(dll_t *ls, FILE *fp);

#endif
