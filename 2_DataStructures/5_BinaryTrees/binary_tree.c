#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"

binary_tree* new_binary_tree() {
    // Allocate memory for a new binary tree
    binary_tree* t = (binary_tree*) malloc(sizeof(binary_tree));
    t->root = 0;
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

void insert_node(node** n, node* new) {
    if (*n == NULL) {
        *n = new;
    } else if (new->val > (*n)->val) {
        insert_node(&(*n)->right, new);
    } else {
        insert_node(&(*n)->left, new);
    }
}

void binary_tree_add(binary_tree *t, int i) {
    node* new = new_node(i);
    insert_node(&t->root, new);
    t->size++;
}

node** find_node(node** n, int i) {
    if ((*n) == NULL) {
        return NULL;
    } else if (i < (*n)->val) {
        return find_node(&(*n)->left, i);
    } else if (i > (*n)->val) {
        return find_node(&(*n)->right, i);
    } else {
        return n;
    }
}

node** predecessor(node** n) {
    n = &(*n)->left;
    while ((*n)->right != NULL) {
        n = &(*n)->right;
    }
    return n;
}

void remove_node(node** n, int i) {
    if ((*n)->left != NULL && (*n)->right != NULL) {
        node** pre = predecessor(n);
        (*n)->val = (*pre)->val;
        node* tmp = *pre;
        *pre = (*pre)->left;
        free(tmp);
    } else if ((*n)->left != NULL) {
        node* tmp = *n;
        *n = (*n)->left;
        free(tmp);
    } else if ((*n)->right != NULL) {
        node* tmp = *n;
        *n = (*n)->right;
        free(tmp);
    } else {
        free(*n);
        *n = NULL;
    }
}

void binary_tree_remove(binary_tree *t, int i) {
    node** n = find_node(&t->root, i);
    if (n != NULL) {
        remove_node(n, i);
        t->size--;
    }
}

bool binary_tree_contains(binary_tree *t, int i) {
    return (find_node(&t->root, i) != NULL);
}

int binary_tree_size(binary_tree *t) {
    return t->size;
}

void print_node(node *n) {
    printf("(");
    if (n->left != NULL) {
        print_node(n->left);
    }
    printf("%d", n->val);
    if (n->right != NULL) {
        print_node(n->right);
    }
    printf(")");
}

void binary_tree_print(binary_tree *t) {
    if (t->root != NULL) {
        print_node(t->root);
    }
}

void free_node(node *n) {
    if (n == NULL) {
        return;
    }
    free_node(n->left);
    free_node(n->right);
    free(n);
}

void free_binary_tree(binary_tree *t) {
    free_node(t->root);
    free(t);
}
