#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct node {
    struct node* left;
    struct node* right;
    int val;
} node;

// binary_tree represents a binary search tree.
typedef struct {
    node* root;
    int size;
} binary_tree;

// new_binary_tree allocates memory for a new dynamic array and initializes
// its fields.
binary_tree* new_binary_tree() ;

// binary_tree_add inserts an item into the binary tree.
void binary_tree_add(binary_tree *t, int i);

// binary_tree_remove takes an item out of the binary tree.
void binary_tree_remove(binary_tree *t, int i);

// binary_tree_contains returns true if the given item exists in the binary
// tree, and false otherwise.
bool binary_tree_contains(binary_tree *t, int i);

// binary_tree_size returns the number of items currently in the binary tree.
int binary_tree_size(binary_tree *t);

// binary_tree_print prints the contents of the binary tree.
void binary_tree_print(binary_tree *t);

// free_binary_tree frees the memory allocated for the binary tree (both the
// nodes of the tree, as well as the binary tree header struct)
void free_binary_tree(binary_tree *t);

#endif
