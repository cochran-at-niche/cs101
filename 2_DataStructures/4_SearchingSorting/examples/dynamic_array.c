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

bool dyn_arr_sequential_search(dyn_arr *a, int i) {
    for (int j=0; j < a->size; j++) {
        if (a->array[j] == i) {
            return true;
        }
    }
    return false;
}

bool dyn_arr_binary_search(dyn_arr* a, int i) {
    int low=0;
    int high=a->size;

    while (low < high) {
        int mid = (low + high) / 2;
        if (a->array[mid] < i) {
            low = mid + 1;
        } else if (a->array[mid] > i) {
            high = mid;
        } else {
            return true;
        }
    }

    return false;
}

void swap(dyn_arr* a, int i, int j) {
    int tmp = a->array[i];
    a->array[i] = a->array[j];
    a->array[j] = tmp;
}

void dyn_arr_selection_sort(dyn_arr* a) {
    for (int i = 0; i < a->size; i++) {
        int min = i;
        for (int j = i+1; j < a->size; j++) {
            if (a->array[j] < a->array[min]) {
                min = j;
            }
        }
        swap(a, i, min);
    }
}

void dyn_arr_insertion_sort(dyn_arr* a) {
    for (int i = 0; i < a->size; i++) {
        for (int j = i; j > 0; j--) {
            if (a->array[j] >= a->array[j-1]) {
                break;
            }
            swap(a, j, j-1);
        }
    }
}

int dyn_arr_size(dyn_arr *a) {
    return a->size;
}

void dyn_arr_print(dyn_arr *a) {
    for (int i = 0; i < a->size; i++) {
        printf(" %d", a->array[i]);
    }
    printf("\n");
}

void free_dyn_arr(dyn_arr *a) {
    free(a->array);
    free(a); 
}
