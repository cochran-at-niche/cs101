#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

binary_tree* new_binary_tree() {
    // Allocate memory for a new binary tree
    binary_tree* t = (binary_tree*) malloc(sizeof(binary_tree));
    t->size = 0;
    return t;
}

node* new_node() {
    node* n = (node*) malloc(sizeof(node));
    n->val = 0;
    return n;
}

void binary_tree_add(binary_tree *t, int i) {
    // TODO
}

void binary_tree_remove(binary_tree *t, int i) {
    // TODO
}

bool binary_tree_contains(binary_tree *t, int i) {
    // TODO
    return false;
}

int binary_tree_size(binary_tree *t) {
    // TODO
    return 0;
}

void print_node(node *n) {
    printf("( ");
    if (n->left != NULL) {
        print_node(n->left);
    }
    printf("%d ", n->val);
    if (n->right != NULL) {
        print_node(n->right);
    }
    printf(" )");
}

void binary_tree_print(binary_tree *t) {
    if (t->root != NULL) {
        print_node(t->root);
    }
}

void free_binary_tree(binary_tree *t) {
    // TODO
}
