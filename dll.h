#ifndef __DLL_H__
#define __DLL_H__

/*** INCLUDES ***/
#include <stdio.h>
#include <stdlib.h>

/*** CONSTANTS ***/
#define EQUALS 0
#define FAIL -1

/*** PUBLIC INTERFACE ***/
typedef struct DOUBLE_LINKED_LIST_TYPE dll_t;

dll_t *newDLL(void (*p)(FILE *, void *), int (*c)(void *, void *));
int insertDLL(dll_t *ls, void *v);
int findIndexDLL(dll_t *ls, void *v);
void *findValueDLL(dll_t *ls, int index);
void *deleteValueDLL(dll_t *ls, void *v);
void *deleteIndexDLL(dll_t *ls, int index);
int sizeDLL(dll_t *ls);
void printDLL(dll_t *ls, FILE *fp);

#endif
