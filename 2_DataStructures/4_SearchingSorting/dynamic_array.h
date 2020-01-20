#include <stdbool.h>

#ifndef DYN_ARR_H
#define DYN_ARR_H

// dyn_arr represents an array capable of resizing itself to accomodate
// more items.
typedef struct {
    int* array;
    int size;
    int capacity;
} dyn_arr;

// new_dyn_arr allocates memory for a new dynamic array and initializes its
// fields.
dyn_arr* new_dyn_arr() ;

// dyn_arr_add inserts an item into the dynamic array. The dynamic array is
// capable of storing duplicate items (i.e. it is not a set). If the array is
// not large enough to hold the new item, the array be resized so that it can.
void dyn_arr_add(dyn_arr *a, int i);

// dyn_arr_remove takes an item out of the dynamic array, if it exists. If
// there are duplicate items in the dynamic array, it will only remove one of
// them. If the item does not exist in the dynamic array, it will silently do
// nothing.
void dyn_arr_remove(dyn_arr *a, int i);

// dyn_arr_contains performs a linear search on the array. Returns true
// if the given item exists in the dynamic array, and false otherwise.
bool dyn_arr_contains(dyn_arr *a, int i);

// dyn_arr_insertion_sort uses insertion sort to sort the underlying array.
void dyn_arr_insertion_sort(dyn_arr *a);

// dyn_arr_sort uses a O(n log n) algorithm to sort the underlying array.
void dyn_arr_sort(dyn_arr *a);

// dyn_arr_size returns the number of items currently in the dynamic array.
int dyn_arr_size(dyn_arr *a);

// free_dyn_arr frees the memory allocated for the dynamic array (both the
// underlying array, as well as the dynamic array header struct)
void free_dyn_arr(dyn_arr *a);

#endif
