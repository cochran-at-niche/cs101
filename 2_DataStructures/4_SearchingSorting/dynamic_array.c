#include <stdlib.h>
#include <stdio.h>
#include <math.h>

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

// Implements the merge sort algorithm
// For shorthand, N := array size
void dyn_arr_sort(dyn_arr *a) {
    // The total number of sweeps we must perform is
    // the smallest integer that is greater than or equal to
    // log2(N)
    // To compute log2 we use the change of base formula:
    // logy(x) = log(x) / log(y)
    int nsweeps;
    nsweeps = (int) ceil(
        log((double) a->size) / log(2.0)
    );

    // For each sublist we analyze at sweep i, we can build two "runs" which
    // are both already sorted lists from the previous step. For example, after
    // sweep i-1, we might have two sorted sublists A and B; we will call these
    // run A and run B. At sweep i, sublist C is composed of run A and run B
    // appended together. Both A and B have capacity 2^(i-1) and will usually
    // have size = capacity EXCEPT for a sublist whose right endpoint coincides
    // with the end of the array
    int maxrunsize = pow(2, nsweeps - 1);
    int run1[maxrunsize];
    int run2[maxrunsize];
    int size1 = 0, size2 = 0;

    // Iteratively sweep over our array. We start at i = 1 here because at
    // sweep 0 we are dealing with N sublists each of length 1 so they are, by
    // definition, sorted
    int sublength = 0;
    int nsublists = 0;
    for (int i = 1; i < nsweeps; i++) {
        // At sweep i, we sort sublists of length 2^i
        // With sublists of length 2^i, there are
        // ceil(N / 2^i) sublists to sort at sweep i
        sublength = pow(2, i);
        nsublists = (int) ceil(
            ((double) a->size) / ((double) sublength)
        );

        // Iterate over all sublists 
        for (int j = 0; j < nsublists; j++) {
            // Populate the runs

            // If not the last sublist, then both runs will be of the same
            // size: 2^(i-1) = 2^i / 2
            if j != nsublists - 1 {
                size1 = sublength / 2;
                size2 = sublength / 2;
            } else {
                size1 = sublength / 2;
                size2 = a->size - (j * pow(2, i) + pow(2, i - 1));
            }
        }
    }
}

int dyn_arr_size(dyn_arr *a) {
    return a->size;
}

void free_dyn_arr(dyn_arr *a) {
    free(a->array);
    free(a); 
}
