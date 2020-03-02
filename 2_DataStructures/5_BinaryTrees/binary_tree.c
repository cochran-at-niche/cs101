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
    n->count = 1;
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
        // The value already exists in the tree
        (*root)->count++;
    }
}

void binary_tree_remove(binary_tree *t, int i) {
    node *d = NULL;
    d = find_node(t->root, i);
    if (d) {
        d->count--;
        t->size--;
        if (d->count == 0) {
            node_remove(&d);
        }
        if (t->size == 0) {
            t->root = NULL;
        }
    }
}

// TODO: Reduce boilerplate, perhaps adding an auxillary method to help detect
// predecessors / successors
void node_remove(node **d) {
    if (!(*d)->left && !(*d)->right) {
        // The node is a leaf, i.e. it has no descendants
        free(*d);
    } else if ((*d)->left && !(*d)->right) {
        // The node has a left child but not a right child
        if (((*d)->left)->right) {
            // d has a nearest predecessor (greatest lower bound (glb))
            
            // Find the parent of the max-value node (glb) in d's left branch
            node **glb_parent = find_max_parent(&(*d)->left);
            node *glb = (*glb_parent)->right;

            // Update glb parent's (right) reference to point to glb's (left) child
            (*glb_parent)->right = glb->left;

            // Update d's values to be those of glb
            (*d)->val = glb->val;
            (*d)->count = glb->count;

            // Free glb now that it has been "pivoted up" to d's position
            free(glb);
        } else {
            // d has a left child, but this left child has values that are only
            // strictly less than it
            node *tmp = (*d)->left;

            // Update d's (left) reference to point to tmp's (left) child
            (*d)->left = tmp->left;

            // Update d's values to be those of tmp
            (*d)->val = tmp->val;
            (*d)->count = tmp->count;

            // Free tmp
            free(tmp);
        }
    } else if (!(*d)->left && (*d)->right) {
        // The node has a right child but not a left child
        if (((*d)->right)->left) {
            // d has a nearest successor (least upper bound (lub))

            // Find the parent of the min-value node (lub) in d's right branch
            node **lub_parent = find_min_parent(&(*d)->right);
            node *lub = (*lub_parent)->left;

            // Update lub parent's (left) reference to point to lub's (right)
            // child
            (*lub_parent)->left = lub->right;

            // Update d's values to be those of lub
            (*d)->val = lub->val;
            (*d)->count = lub->count;

            // Free lub now that it has been "pivoted up" to d's position
            free(lub);
        } else {
            // d has a right child, but this right child has values that are
            // only strictly greater than it
            node *tmp = (*d)->right;

            // Update d's (right) reference to point to tmp's (right) child
            (*d)->right = tmp->right;

            // Update d's values to be those of tmp
            (*d)->val = tmp->val;
            (*d)->count = tmp->count;

            // Free tmp
            free(tmp);
        }
    } else {
        // The node has both left and right children
        if (((*d)->left)->right) {
            // d has a nearest predecessor (greatest lower bound (glb))
            
            // Find the parent of the max-value node (glb) in d's left branch
            node **glb_parent = find_max_parent(&(*d)->left);
            node *glb = (*glb_parent)->right;

            // Update glb parent's (right) reference to point to glb's (left) child
            (*glb_parent)->right = glb->left;

            // Update d's values to be those of glb
            (*d)->val = glb->val;
            (*d)->count = glb->count;

            // Free glb now that it has been "pivoted up" to d's position
            free(glb);
        } else if (((*d)->right)->left) {
            // d has a nearest successor (least upper bound (lub))

            // Find the parent of the min-value node (lub) in d's right branch
            node **lub_parent = find_min_parent(&(*d)->right);
            node *lub = (*lub_parent)->left;

            // Update lub parent's (left) reference to point to lub's (right)
            // child
            (*lub_parent)->left = lub->right;

            // Update d's values to be those of lub
            (*d)->val = lub->val;
            (*d)->count = lub->count;

            // Free lub now that it has been "pivoted up" to d's position
            free(lub);
        } else {
            // d has neither a nearest predecessor nor successor
            // Just swap in the left child
            node *tmp = (*d)->left;

            // Update d's (left) reference to point to tmp's (left) child
            (*d)->left = tmp->left;

            // Update d's values to be those of tmp
            (*d)->val = tmp->val;
            (*d)->count = tmp->count;

            // Free tmp
            free(tmp);
        }
    }
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

node** find_max_parent(node **root) {
    if (((*root)->right)->right) {
        return find_max_parent(&(*root)->right);
    } else {
        return root;
    }
}

node** find_min_parent(node **root) {
    if (((*root)->left)->left) {
        return find_min_parent(&(*root)->left);
    } else {
        return root;
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
