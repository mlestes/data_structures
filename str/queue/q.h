/******************************************************************************
 * q.h - header for a queue class
 * 1.0.0 - last updated 12 Nov 2020
 * Author Murray L. Estes
 ******************************************************************************/

#ifndef __Q_H__
#define __Q_H__

/*** INCLUDES ***/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/*** PUBLIC INTERFACE ***/
typedef struct QUEUE_TYPE q_t;

q_t *newQueue(void (*p)(FILE *, void *));
void enqueue(q_t *q, void *v);
void *dequeue(q_t *q);
int sizeQueue(q_t *q);
void printQueue(q_t *q, FILE *fp);

#endif
