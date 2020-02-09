#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "map.h"

map* new_map() {
    // Allocate memory for a new map
    map* t = (map*) malloc(sizeof(map));
    t->root = 0;
    t->size = 0;
    return t;
}

node* new_node(char* key, int val) {
    node* n = (node*) malloc(sizeof(node));
    n->left = NULL;
    n->right = NULL;
    n->key = key;
    n->val = val;
    return n;
}

void insert_node(node** n, node* new) {
    if (*n == NULL) {
        *n = new;
    } else if (strcmp(new->key, (*n)->key) > 0) {
        insert_node(&(*n)->right, new);
    } else {
        insert_node(&(*n)->left, new);
    }
}

void map_add(map *t, char* key, int val) {
    node* new = new_node(key, val);
    insert_node(&t->root, new);
    t->size++;
}

node** find_node(node** n, char* key) {
    if ((*n) == NULL) {
        return NULL;
    } else if (strcmp(key, (*n)->key) < 0) {
        return find_node(&(*n)->left, key);
    } else if (strcmp(key, (*n)->key) > 0) {
        return find_node(&(*n)->right, key);
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

void remove_node(node** n, char* key) {
    if ((*n)->left != NULL && (*n)->right != NULL) {
        node** pre = predecessor(n);
        (*n)->key = (*pre)->key;
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

void map_remove(map *t, char* key) {
    node** n = find_node(&t->root, key);
    if (n != NULL) {
        remove_node(n, key);
        t->size--;
    }
}

int map_get(map *t, char* key) {
    node** node = find_node(&t->root, key);
    if (node == NULL) {
        return 0;
    }
    return (*node)->val;
}

int map_size(map *t) {
    return t->size;
}

void free_node(node *n) {
    if (n == NULL) {
        return;
    }
    free_node(n->left);
    free_node(n->right);
    free(n);
}

void free_map(map *t) {
    free_node(t->root);
    free(t);
}
