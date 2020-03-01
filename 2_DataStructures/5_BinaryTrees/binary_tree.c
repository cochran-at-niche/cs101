#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

binary_tree* new_binary_tree() {
    // Allocate memory for a new binary tree
    binary_tree* t = (binary_tree*) malloc(sizeof(binary_tree));
    t->root = NULL;
    t->size = 0;
    return t;
}

node* new_node(int i) {
    node* n = (node*) malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->val = i;
    return n;
}

void binary_tree_add(binary_tree *t, int i) {
    node_add(&t->root, i);
    t->size++;
}

void node_add(node **root, int i) {
    if (!(*root)) {
        *root = new_node(i);
    } else if (i < (*root)->val) {
        node_add(&(*root)->left, i);
    } else if (i > (*root)->val) {
        node_add(&(*root)->right, i);
    } else {
        // The value i already exists in the tree
        return;
    }
}

void binary_tree_remove(binary_tree *t, int i) {
    // TODO
}

bool binary_tree_contains(binary_tree *t, int i) {
    if (find_node(t->root, i)) {
        return true;
    } else {
        return false;
    }
}

node* find_node(node *root, int i) {
    if (!root) {
        return NULL;
    } else if (i == root->val) {
        return root;
    } else if (i < root->val) {
        return find_node(root->left, i);
    } else {
        return find_node(root->right, i);
    }
}

int binary_tree_size(binary_tree *t) {
    return t->size;
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
    free_node(t->root);
    free(t);
}

void free_node(node *root) {
    if (!root) {
        return;
    }
    free_node(root->left);
    free_node(root->right);
    free(root);
}
