#include "dynamic_array.h"

const int INITIAL_CAPACITY = 2;

dyn_arr* new_dyn_arr() {
    // Allocate memory for a new dynamic array
    dyn_arr * a = (dyn_arr*) malloc(sizeof(dyn_arr));

    // Initialize fields. Allocate memory equal to the size of an int
    // multiplied by the initial capacity.
    a->array = (int*) malloc(sizeof(int) * INITIAL_CAPACITY);
    a->size = 0;
    a->capacity = INITIAL_CAPACITY;

    return a;
}

void dyn_arr_add(dyn_arr *a, int i) {
    // TODO: Implement the add method. Resize the underlying array if necessary
    // by allocating a new array, copying all of the items over to it, and
    // freeing the memory associated with the current array.
}

void dyn_arr_remove(dyn_arr *a, int i) {
    // TODO: Implement the remove method. Removing an item will require you to
    // move all items after it back one spot in the array.
}

bool dyn_arr_contains(dyn_arr *a, int i) {
    // TODO: Implement the contains method

    return false;
}

int dyn_arr_size(dyn_arr *a) {
    // TODO: Implement the size method

    return 0;
}

void free_dyn_arr(dyn_arr *a) {
    free(a->array);
    free(a); 
}
