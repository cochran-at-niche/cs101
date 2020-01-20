#include "binary_tree.h"

binary_tree* new_binary_tree() {
    // Allocate memory for a new binary tree
    binary_tree* t = (binary_tree*) malloc(sizeof(binary_tree));
    t->size = 0;
    return t;
}

node* new_node(int i) {
    node* n = (node*) malloc(sizeof(node));
    n->val = i;
    return n;
}

void insert_node(node* n, node* new) {
    if (new->val > n->val) {
        if (n->right == NULL) {
            n->right = new;
        } else {
            insert_node(n->right, new);
        }
    } else {
        if (n->left == NULL) {
            n->left = new;
        } else {
            insert_node(n->left, new);
        }
    }
}

void binary_tree_add(binary_tree *t, int i) {
    node* new = new_node(i);
    if (t->root == NULL) {
        t->root = new;
    } else {
        insert_node(t->root, new);
    }
    t->size++;
}

void node_remove(node* n, int i) {
    // TODO
}

void binary_tree_remove(binary_tree *t, int i) {
    return;
}

bool node_contains(node* n, int i) {
    if (n == NULL) {
        return false;
    } else if (i == n->val) {
        return true;
    } else if (i > n->val) {
        return node_contains(n->right, i);
    } else {
        return node_contains(n->left, i);
    }
}

bool binary_tree_contains(binary_tree *t, int i) {
    return node_contains(t->root, i);
}

int binary_tree_size(binary_tree *t) {
    return t->size;
}

void print_node(node *n) {
    if (n->left != NULL) {
        print_node(n->left);
    }
    printf("%d ", n->val);
    if (n->right != NULL) {
        print_node(n->right);
    }
}

void binary_tree_print(binary_tree *t) {
    if (t->root != NULL) {
        print_node(t->root);
    }
}

void free_binary_tree(binary_tree *t) {
    // TODO: Free nodes
    free(t);
}
