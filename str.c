/******************************************************************************
 * str.c version 1.0.1 - last updated 12 Nov 2020
 * By: Murray Estes
 * Description: An object for using strings.
 ******************************************************************************
 * Usage:
 * str_t *newString(char *str):
 * 	Creates a new string object.
 * 	str_t *s = newString(str);
 *
 * char *getString(str_t *s):
 * 	Returns the stored C-string.
 * 	char *str = getString(s);
 *
 * char *setString(str_t *s, char *str):
 * 	Replaces the object's C-string with a new one and returns the old
 * 	setStr(s, str);
 *
 * char *deleteString(str_t *s):
 * 	Deallocates the object and returns the stored C-string.
 * 	deleteString(s);
 *
 * int sizeString(str_t *s):
 * 	Returns the size of the stored C-string.
 * 	int size = sizeString(s);
 *
 * void printString(FILE *fp, void *v):
 * 	Prints the C-string.
 * 	printString(stdout, s);
 *
 * int compareString(void *a, void *b):
 * 	Compares the strings and return 0 for equal and 1 for not equal.
 * 	int cmp = compareString(str1, str2);
 *
 * void combineString(void *a, void *b):
 * 	Takes to string objects, combines the stored strings, and returns as a
 * 	new object.
 * 	str_t big = combineString(st, ring);
 ******************************************************************************/

#include "str.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*** STRUCTS ***/
struct STRING{

	char *string;
	int size;

};

/*** PRIVATE DECLARATIONS ***/
//none

/*** PUBLICE FUNCTIONS ***/
str_t *newString(char *str){

	str_t *s = malloc(sizeof(str_t));
	char c = str[0];
	int cnt = 0;
	while(c != '\0') c = str[++cnt];
	s->string = str;
	s->size = cnt;

	return s;

}

char *getString(str_t *s){return s->string;}
char *setString(str_t *s, char *str){

	char *out = s->string;
	s->string = str;
	int cnt = 0; char c = str[0];
	while(c != '\0') c = str[++cnt];
	s->size = cnt;

	return out;

}

char *deleteString(str_t *s){

	char *out = s->string;
	free(s);
	return out;

}

int sizeString(str_t *s){return s->size;}
void printString(FILE *fp, void *v){

	str_t *s = (str_t *) v;
	fprintf(fp, "%s", s->string);

}

int compareString(void *s1, void *s2){

	str_t *a = (str_t *) s1; str_t *b = (str_t *) s2;
	if(a->size != b->size) return NOT_EQUAL;
	else{
		for(int i = 0; i < a->size; i++) 
			if(a->string[i] != b->string[i]) return NOT_EQUAL;
	}

	return EQUAL;

}

str_t *combineString(void *s1, void *s2){

	str_t *a = (str_t *) s1; str_t *b = (str_t *) s2;
	int size = a->size + b->size;
	char *str = malloc(sizeof(char) * size);
	int i = 0; int j = 0;
	while(a->string[i] != '\0'){
		str[i] = a->string[i];
		i++;
	}
	while(b->string[j] != '\0'){
		str[i] = b->string[j];
		i++; j++;
	}
	return newString(str);

}
