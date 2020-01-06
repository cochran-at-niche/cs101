#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "dynamic_array.h"

const int SIZE = 100; 

int main() {
    // Initialize a new dynamic array
    dyn_arr* a = new_dyn_arr();

    // Add a bunch of random numbers to it
    srand(time(0));
    for (int i = 0; i<SIZE; i++) {
        dyn_arr_add(a, rand() % SIZE);
    }

    // Sort it
    dyn_arr_sort(a);

    // Print it
    printf("Array:");
    dyn_arr_print(a);

    // Prompt user for a number to search for
    printf("Enter an integer to search for:\n");
    int target;
    scanf("%d", &target);

    // Brute force search
    int j = dyn_arr_brute_force(a, target);
    printf("Brute force: %s\n", j ? "true" : "false");

    // Binary search
    int k = dyn_arr_binary_search(a, target);
    printf("Binary search: %s\n", k ? "true" : "false");
}
