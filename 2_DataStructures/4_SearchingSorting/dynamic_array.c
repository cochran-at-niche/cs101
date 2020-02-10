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

    // Create a holding table to keep values that get sorted during the merge
    int* array2 = (int*) malloc(sizeof(int) * a->size);

    // Copy the elements of our dynamic array into working array
    for (int i = 0; i < a->size; i++) {
        array2[i] = a->array[i];
    }

    // Iteratively sweep over our array. We start at i = 1 here because at
    // sweep 0 we are dealing with N sublists each of length 1 so they are, by
    // definition, sorted
    int sublength = 0;
    int nsublists = 0;
    int idx1 = 0;
    int idx2 = 0;
    int size1 = 0;
    int size2 = 0;
    int k1 = 0;
    int k2 = 0;
    for (int i = 1; i <= nsweeps; i++) {
        // At sweep i, we sort sublists of length 2^i
        // With sublists of length 2^i, there are
        // ceil(N / 2^i) sublists to sort at sweep i
        sublength = pow(2, i);
        nsublists = (int) ceil(
            ((double) a->size) / ((double) sublength)
        );

        // Iterate over all sublists 
        for (int j = 0; j < nsublists; j++) {
            // The first run of the sublist always starts at index j * 2^i
            // If the sublist is not the last, then both runs will have size
            // 2^(i-1); The index of run2 is just the index of run1 + the size
            // of run 1
            // Things are more complicated if we are at the last sublist
            // In this case, run1 still starts at index j * 2^i, but now
            // run1 will contain either 2^(i-1) elements OR however many
            // elements are left in our array, whichever is smaller. In the
            // case that run1 exhausts all remaining elements, run2 will have
            // size 0. In the case that run1 does not exhaust all remaining
            // elements (i.e. N - (idx1 + size1) > 0), then run2 will contain
            // all remaining elements in our array
            idx1 = j * pow(2, i);
            if (j != nsublists - 1) {
                size1 = pow(2, i - 1);
                idx2 = idx1 + size1;
                size2 = pow(2, i - 1);
            } else {
                if (pow(2, i - 1) <= (a->size - idx1)) {
                    size1 = pow(2, i - 1);
                } else {
                    size1 = a->size - idx1;
                }
                idx2 = idx1 + size1;
                size2 = a->size - (idx1 + size1);
            }

            // The second run has no elements
            // The last sublist is already in sorted order
            if (size2 == 0) {
                if (i % 2 == 1) {
                    for (k1 = 0; k1 < size1; k1++) {
                        array2[idx1 + k1] = a->array[idx1 + k1];
                    }
                } else {
                    for (k1 = 0; k1 < size1; k1++) {
                        a->array[idx1 + k1] = array2[idx1 + k1];
                    }
                }
                continue;
            }

            // On odd sweeps we compare values in our primary array
            // (a->array) since these items will be sorted from the
            // previous sweep
            // On even sweeps we compare values in array2 since *these*
            // items will be sorted from the previous sweep
            // We flip back and forth between the arrays
            if (i % 2 == 1) {
                // Compare elements of each run, placing the comparison results
                // in sorted order in the "opposite" array
                for (k1 = 0, k2 = 0; k1 < size1 && k2 < size2; ) {
                    if ((a->array[idx1 + k1]) <= (a->array[idx2 + k2])) {
                        array2[idx1 + k1 + k2] = a->array[idx1 + k1];
                        k1++;
                    } else {
                        array2[idx1 + k1 + k2] = a->array[idx2 + k2];
                        k2++;
                    }
                }

                // Add the leftover, uncompared elements to the end of the
                // sorted results
                if (k1 < size1) {
                    // Run 1 did not have all of its elements used up
                    for ( ; k1 < size1; k1++) {
                        array2[idx1 + k1 + k2] = a->array[idx1 + k1];
                    }
                } else if (k2 < size2) {
                    // Run 2 did not have all of its elements used up
                    for ( ; k2 < size2; k2++) {
                        array2[idx1 + k1 + k2] = a->array[idx2 + k2];
                    }
                }
            } else {
                // Compare elements of each run, placing the comparison results
                // in sorted order in the "opposite" array
                for (k1 = 0, k2 = 0; k1 < size1 && k2 < size2; ) {
                    if (array2[idx1 + k1] <= array2[idx2 + k2]) {
                        a->array[idx1 + k1 + k2] = array2[idx1 + k1];
                        k1++;
                    } else {
                        a->array[idx1 + k1 + k2] = array2[idx2 + k2];
                        k2++;
                    }
                }

                // Add the leftover, uncompared elements to the end of the
                // sorted results
                if (k1 < size1) {
                    // Run 1 did not have all of its elements used up
                    for ( ; k1 < size1; k1++) {
                        a->array[idx1 + k1 + k2] = array2[idx1 + k1];
                    }
                } else if (k2 < size2) {
                    // Run 2 did not have all of its elements used up
                    for ( ; k2 < size2; k2++) {
                        a->array[idx1 + k1 + k2] = array2[idx2 + k2];
                    }
                }
            }
        }
    }

    // If we performed an odd number of sweeps, then the secondary array
    // (array2) will contain the sorted items, so we copy its contents back
    // into our primary array. If the number of sweeps was even then our
    // primary array already contains the results in a sorted order
    if (nsweeps % 2 == 1) {
        for (int i = 0; i < a->size; i++) {
            a->array[i] = array2[i];
        }
    }

    free(array2);
}

int dyn_arr_size(dyn_arr *a) {
    return a->size;
}

void free_dyn_arr(dyn_arr *a) {
    free(a->array);
    free(a); 
}
