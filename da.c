/******************************************************************************
 * da.c
 * AUTHOR: Murray Estes
 * Description: A generic object for dynamic arrays (non-circular).
 ******************************************************************************
 * Function Usage:
 * newDynamicArray(int size, void (*p)(FILE *, void *)):
 * 	Creates a new dynamic array object and returns it.
 * 	d_arr_t *arr = newDynamicArray(DEFAULT, printer);
 * 	DEFAULT = 1 and is defined in da.h
 *
 * insertDynamicArray(d_arr_t *arr, void *item):
 * 	Inserts an object into the internal array. Grows if necessary. The index
 * 	the object was inserted into is returned.
 * 	int index = insertDynamicArray(arr, x);
 *
 * setDynamicArray(d_arr_t *arr, void *item, int index):
 * 	Replaces an object stored at the index with the given one and returns
 * 	the old object. Returns NULL upon failure.
 * 	void *old = setDynamicArray(arr, x, index);
 *
 * deleteObjectDynamicArray(d_arr_t *arr, int index):
 * 	Deletes the object from the array, rearranges the array, and shrinks
 * 	if necessary. Returns the old object or NULL upon failure.
 * 	void *old = deleteObjectDynamicArray(arr, index);
 *
 * deleteDynamicArray(d_arr_t *arr):
 * 	Frees the array object. 
 * 	NOT TO BE CONFUSED WITH deleteObjectDynamicArray(), which deletes object
 * 	inside the stored array.
 * 	deleteDynamicArray(arr);
 *
 * sizeDynamicArray(d_arr_t *arr):
 * 	Returns the number of elements in the array.
 * 	int count = sizeDynamicArray(arr);
 *
 * capacityDynamicArray(d_arr_t *arr):
 * 	Returns the number of elements the array can currently hold.
 * 	int max = capacityDynamicArray(arr);
 *
 * printDynamicArray(d_arr_t *arr, FILE *fp):
 * 	Prints the array with each element braced. Prints "-null-" if
 * 	a null value is encountered.
 * 	printDynamicArray(arr, stdout);
 *
 ******************************************************************************/

#include "da.h"

/*** STRUCTURES ***/
typedef struct DynamicArray {

	void **array;
	int size; //number of elements in the array
	int capacity; //max number of elements in the current array
	void (*print)(FILE *, void *);

} d_arr_t;

/*** PRIVATE DECLARATIONS ***/
void **new_array(int size);
void grow_array(d_arr_t *arr);
void shrink_array(d_arr_t *arr);
void reallocate_array(d_arr_t *arr);

/*** PUBLIC DEFINITONS ***/
d_arr_t *newDynamicArray(int size, void (*p)(FILE *, void *)){

	d_arr_t *arr = malloc(sizeof(d_arr_t));
	if(arr == NULL){
		fprintf(stderr, "Error: Failed to allocate object\n");
		exit(-1);
	}
	arr->array = size == DEFAULT ? new_array(1) : new_array(size);
	arr->size = 0;
	arr->capacity = size == DEFAULT ? 1 : size;
	arr->print = p;

	return arr;

}

int insertDynamicArray(d_arr_t *arr, void *item){

	if(item == NULL) return FAIL;
	if(arr->size == arr->capacity) grow_array(arr);
	int index = arr->size++;
	arr->array[index] = item;

	return index;

}

void *setDynamicArray(d_arr_t *arr, void *item, int index){

	if(item == NULL) return NULL;
	if(index >= arr->size) return NULL;
	void *out = arr->array[index];
	arr->array[index] = item;

	return out;

}

void *deleteObjectDynamicArray(d_arr_t *arr, int index){

	if(index >= arr->size) return NULL;
	void *out = arr->array[index];
	arr->array[index] = NULL;
	reallocate_array(arr);
	if(arr->size < arr->capacity / 4) shrink_array(arr);

	return out;

}

void deleteDynamicArray(d_arr_t *arr){free(arr);}
void printDynamicArray(d_arr_t *arr, FILE *fp){

	int i;
	for(i = 0; i < arr->size; i++){
		fprintf(fp, "[");
		if(arr->array[i] != NULL) arr->print(fp, arr->array[i]);
		else fprintf(fp, "-null-");
		fprintf(fp, "]");
	}

}

int sizeDynamicArray(d_arr_t *arr){return arr->size;}
int capacityDynamicArray(d_arr_t *arr){return arr->capacity;}

/*** PRIVATE DEFINTIONS ***/
void **new_array(int size){

	void **a = malloc(sizeof(void *) * size);
	if(a == NULL){
		fprintf(stderr, "Error: Failed to allocate memory for array\n");
		exit(-1);
	}
	for(int i = 0; i < size; i++) a[i] = NULL;

	return a;

}

void grow_array(d_arr_t *arr){

	arr->capacity *= 2;
	arr->array = realloc(arr->array, sizeof(void *) * arr->capacity);

}

void shrink_array(d_arr_t *arr){

	arr->capacity /= 2;
	arr->array = realloc(arr->array, sizeof(void *) * arr->capacity);

}

void reallocate_array(d_arr_t *arr){

	void **tmp = malloc(sizeof(void *) * arr->capacity);
	if(tmp == NULL){
		fprintf(stderr, "Error: failed to allocate memory for array\n");
		exit(-1);
	}
	for(int i = 0; i < arr->capacity; i++) tmp[i] = NULL;
	int j = 0;
	for(int i = 0; i < arr->capacity; i++)
		if(arr->array[i] != NULL) tmp[j++] = arr->array[i];
	for(int i = 0; i < arr->capacity; i++) arr->array[i] = tmp[i];
	arr->size = j;
	free(tmp);

}
