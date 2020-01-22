#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "binary_tree.h"

const int SIZE = 100;

int main() {
    // Initialize a new binary tree
    binary_tree* t = new_binary_tree();

    // Add a bunch of random numbers to it
    srand(time(0));
    for (int i = 0; i<SIZE; i++) {
        binary_tree_add(t, rand() % SIZE);
    }

    // TODO: Print it
    printf("Tree: \n");
    binary_tree_print(t);
    printf("\n");

    // Prompt user for a number to search for
    while (true) {
        // Search
        printf("Enter an integer to search for:\n");
        int target;
        scanf("%d", &target);

        bool k = binary_tree_contains(t, target);
        printf("Contains: %s\n", k ? "true" : "false");

        // Remove
        //printf("Enter an integer to remove:\n");
        //int target;
        //scanf("%d", &target);

        //binary_tree_remove(t, target);
        //binary_tree_print(t);
        //printf("\n");
    }
}
