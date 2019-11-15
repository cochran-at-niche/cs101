#include "dynamic_array.h"

const int INITIAL_CAPACITY = 2;

dyn_arr* new_dyn_arr() {
	// Allocate memory for a new dynamic array
	dyn_arr *a = (dyn_arr*) malloc(sizeof(dyn_arr));

	// Initialize fields. Allocate memory equal to the size of an int
	// multiplied by the initial capacity.
	a->array = (int*) malloc(sizeof(int) * INITIAL_CAPACITY);
	a->size = 0;
	a->capacity = INITIAL_CAPACITY;

	return a;
}

void dyn_arr_resize(dyn_arr *a) {
	int j;
	int new_cap = (a->capacity) * 2;
	int *new_arr = malloc(sizeof(int) * new_cap);

	// Copy over every element of the current array to the new array
	for (j = 0; j < (a->size); j++) {
		new_arr[j] = (a->array)[j];
	}

	// Free the memory occupied by the current array
	free(a->array);

	// Assign the new array to the dynamic array's array attribute
	a->array = new_arr;
}

void dyn_arr_add(dyn_arr *a, int i) {
	// Resize the array
	// Adding this new element will bring the array to full capacity
	if ((a->size) + 1 == (a->capacity)) {
		dyn_arr_resize(a);
	}

	// Add the new element to the end of the array
	(a->array)[(a->size)] = i;

	// Increment the size of the array by one
	(a->size)++;
}

void dyn_arr_remove(dyn_arr *a, int i) {
	// The array is empty
	if ((a->size) == 0) {
		return;
	}

	int j;
	int idx = -1;

	for (j = 0; j < (a->size); j++) {
		if ((a->array)[j] == i) {
			idx = j;
			break;
		}
	}

	if (idx >= 0) {
		(a->array)[idx] = (a->array)[(a->size) - 1];
		(a->size)--;
	}
}

bool dyn_arr_contains(dyn_arr *a, int i) {
	bool contains = false;
	int j;

	for (j = 0; j < (a->size); j++) {
		if ((a->array)[j] == i) {
			contains = true;
			break;
		}
	}

	return contains;
}

int dyn_arr_size(dyn_arr *a) {
	int size = a->size;
	return size;
}

void dyn_arr_free(dyn_arr *a) {
	free(a->array);
	free(a); 
}
