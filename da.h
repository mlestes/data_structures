#ifndef __DA_H__
#define __DA_H__

#define DEFAULT 1
#define FAIL -1

#include <stdio.h>
#include <stdlib.h>

typedef struct DynamicArray d_arr_t;
d_arr_t *newDynamicArray(int size, void (*p)(FILE *, void *));
int insertDynamicArray(d_arr_t *arr, void *item);
void *setDynamicArray(d_arr_t *arr, void *item, int index);
void *deleteObjectDynamicArray(d_arr_t *arr, int index);
void deleteDynamicArray(d_arr_t *arr);
void printDynamicArray(d_arr_t *arr, FILE *fp);
int sizeDynamicArray(d_arr_t *arr);
int capacityDynamicArray(d_arr_t *arr);

#endif
