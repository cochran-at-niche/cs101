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
    printf("Tree: ");
    binary_tree_print(t);
    printf("\n");

    // Prompt user for a number to search for
    while (true) {
        printf("Enter an integer to search for:\n");
        int target;
        scanf("%d", &target);

        // Search
        bool k = binary_tree_contains(t, target);
        printf("Contains: %s\n", k ? "true" : "false");
    }
}
