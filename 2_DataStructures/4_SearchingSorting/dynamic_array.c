#include <stdlib.h>
#include <stdio.h>

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

void dyn_arr_remove(dyn_arr *a, int i) {
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

bool dyn_arr_contains(dyn_arr *a, int i) {
    for (int j=0; j < a->size; j++) {
        if (a->array[j] == i) {
            return true;
        }
    }
    return false;
}

void dyn_arr_insertion_sort(dyn_arr *a) {
    for (int i = 0; i < a->size; i++) {
        int tmp = a->array[i];
        int j;
        for (j = i; j > 0; j--) {
            if (tmp >= a->array[j-1]) {
                break;
            }
            a->array[j] = a->array[j-1];
        }
        a->array[j] = tmp;
    }
}

void swap(dyn_arr *a, int i, int j) {
    int tmp = a->array[i];
    a->array[i] = a->array[j];
    a->array[j] = tmp;
}

int partition(dyn_arr *a, int start, int end) {
    int pivot = a->array[(start + end) / 2];

    int i = start - 1;
    int j = end + 1;
    while (true) {
        do i++; while (a->array[i] < pivot);
        do j--; while (a->array[j] > pivot);
        if (i >= j) {
            return j;
        }
        swap(a, i, j);
    }
}

void quick_sort(dyn_arr *a, int start, int end) {
    if (end <= start) {
        return;
    }

    int pivot = partition(a, start, end);
    quick_sort(a, start, pivot);
    quick_sort(a, pivot+1, end);
}

void dyn_arr_sort(dyn_arr *a) {
    quick_sort(a, 0, a->size-1);
}

int dyn_arr_size(dyn_arr *a) {
    return a->size;
}

void free_dyn_arr(dyn_arr *a) {
    free(a->array);
    free(a); 
}
