#include <stdbool.h>

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

typedef struct node {
    struct node* left;
    struct node* right;
    int val;
    int count;
} node;

// binary_tree represents a binary search tree.
typedef struct {
    node* root;
    int size;
} binary_tree;

// new_binary_tree allocates memory for a new binary tree and initializes
// its fields.
binary_tree* new_binary_tree() ;

// new_node allocates memory for a new node and initializes its fields
node* new_node(int i);

// binary_tree_add inserts an item into the binary tree.
void binary_tree_add(binary_tree *t, int i);

// node_add inserts a new node into the tree of which root is a member
void node_add(node **root, int i);

// binary_tree_remove deletes an item from the binary tree.
void binary_tree_remove(binary_tree *t, int i);

// node_remove deletes the given node from the tree
void node_remove(node **d);

// binary_tree_contains returns true if the given item exists in the binary
// tree, and false otherwise.
bool binary_tree_contains(binary_tree *t, int i);

// find_node returns a pointer to the node in the tree that has the value i
// if no such node exists, find_node returns NULL. find_node recursively traverses the tree
node* find_node(node *root, int i);

// find_max_parent returns a (pointer-to-a-pointer-to the) parent node of the node
// that has the largest value in a subtree
node** find_max_parent(node **root);

// find_min_parent returns a (pointer-to-a-pointer-to the) parent node of the node
// that has the smallest value in a subtree
node** find_min_parent(node **root);

// binary_tree_size returns the number of items currently in the binary tree.
int binary_tree_size(binary_tree *t);

// binary_tree_print prints the contents of the binary tree.
void binary_tree_print(binary_tree *t);

// free_binary_tree frees the memory allocated for the binary tree (both the
// nodes of the tree, as well as the binary tree header struct)
void free_binary_tree(binary_tree *t);

// free_node frees the memory allocated for the node,
// recursively freeing memory for all child nodes below it
void free_node(node *root);

#endif
