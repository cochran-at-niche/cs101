#include <stdlib.h>
#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


// node represents a node in a doubly-linked list
typedef struct node {
    struct node* next;
    struct node* prev;
    int val;
} node;

// linked_list represents a doubly linked list
typedef struct {
    node* sentinal;
    int size;
} linked_list;

// new_linked_list allocates memory for a new linked list and initializes its
// fields.
linked_list* new_linked_list();

void linked_list_push_front(linked_list *l, int i);

int linked_list_pop_front(linked_list *l);

void linked_list_push_back(linked_list *l, int i);

int linked_list_pop_back(linked_list *l);

bool linked_list_contains(linked_list *l, int i);

// linked_list_size returns the number of items currently in the linked list.
int linked_list_size(linked_list *l);

// linked_list_free frees the memory allocated for the linked_list (both
// the memory of the linked_list struct, as well as any remaining nodes)
void free_linked_list(linked_list *l);

#endif
