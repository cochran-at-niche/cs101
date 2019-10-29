#include <stdlib.h>
#include <stdbool.h>

const int INITIAL_CAPACITY = 2;

// dynamic_array represents an array capable of resizing itself to accomodate
// more items.
struct dynamic_array {
    int* array;
    int size;
    int capacity;
};

struct dynamic_array * new_dynamic_array() {
    // Allocate memory for a new dynamic array
    struct dynamic_array * a = (struct dynamic_array *) malloc(sizeof(struct dynamic_array));

    // Initialize fields. Allocate memory equal to the size of an int
    // multiplied by the initial capacity.
    a->array = (int*) malloc(sizeof(int) * INITIAL_CAPACITY);
    a->size = 0;
    a->capacity = INITIAL_CAPACITY;

    return a;
}

// Add inserts an item into the dynamic array. The dynamic array should accept
// and store duplicate items (i.e. it is not a set). If the array is not large
// enough to hold the new item, the array will need to be resized so that it
// can (typically, this is done by doubling the current capacity.
void add(struct dynamic_array *a, int i) {
    // Resize array if necessary
    if (a->size == a->capacity) {
        int* array2 = (int*) malloc(sizeof(int) * a->capacity*2);
        for (int j=0; j < a->size; j++) {
            array2[j] = a->array[j];
        }
        free(a->array);
        a->array = array2;
        a->capacity = a->capacity*2;
    }

    // Add item to end of array and increment the size
    a->array[a->size] = i;
    a->size++;
}

// Remove takes an item out of the dynamic array, if it exists. If there are
// duplicate items in the dynamic array, it should only remove one of them. If
// the item does not exist in the dynamic array, it should silently do nothing.
void remove(struct dynamic_array *a, int i) {
    // Iterate through array to find item to remove
    for (int j=0; j < a->size; j++) {
        if (a->array[j] == i) {
            // To remove the item, we move all elements after it back one spot,
            // then decrement the size of the array
            for (int k=j; k+1 < a->size; k++) {
                a->array[k] = a->array[k+1];
            }
            a->size--;
            return;
        }
    }
}

// Contains returns true if the given item exists in the dynamic array, and
// false otherwise.
bool contains(struct dynamic_array *a, int i) {
    for (int j=0; j < a->size; j++) {
        if (a->array[j] == i) {
            return true;
        }
    }

    return false;
}

// Size returns the number of items currently in the dynamic array.
int size(struct dynamic_array *a) {
    return a->size;
}

// Frees the memory allocated for the dynamic array (both the underlying array,
// as well as the dynamic array header struct)
void free_dynamic_array(struct dynamic_array *a) {
    free(a->array);
    free(a); 
}
