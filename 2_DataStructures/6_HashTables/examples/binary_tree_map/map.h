#include <stdbool.h>

#ifndef MAP_H
#define MAP_H

typedef struct node {
    struct node* left;
    struct node* right;
    char* key;
    int val;
} node;

// map represents a map implemented as a binary search tree.
typedef struct {
    node* root;
    int size;
} map;

// new_map allocates memory for a new map and initializes its fields.
map* new_map() ;

// map_add inserts a key-value pair into the map.
void map_add(map *t, char* key, int val);

// map_remove deletes a key-value pair from the associative array.
void map_remove(map *t, char* key);

// map_get looks up a value up by key and returns it. Returns 0 if the key does
// not exist in the map.
int map_get(map *t, char* key);

// map_size returns the number of items currently in the map.
int map_size(map *t);

// free_map frees the memory allocated for the map
void free_map(map *t);

#endif
