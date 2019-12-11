#include <stdlib.h>
#include <stdbool.h>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H


// node represents a node in a doubly-linked list. The next field holds a
// pointer to the next item in the list, the prev field holds a pointer to the
// previous item in the list, and the val field holds the data stored at this
// node in the linked list.
typedef struct node {
    struct node* next;
    struct node* prev;
    int val;
} node;

// linked_list represents a circular, doubly linked list. The sentinal node
// does not store any data, and therefore does not count towards the size of
// the linked list.
typedef struct {
    node* sentinal;
    int size;
} linked_list;

// new_linked_list allocates memory for a new linked list, initializes its
// fields, and returns it.
linked_list* new_linked_list();

// linked_list_push_front inserts the given item at the front of the linked list.
void linked_list_push_front(linked_list *l, int i);

// linked_list_pop_front removes the item at the front of the list and returns it.
int linked_list_pop_front(linked_list *l);

// linked_list_push_back inserts the given item at the back of the linked list.
void linked_list_push_back(linked_list *l, int i);

// linked_list_pop_back removes the item at the back of the list and returns it.
int linked_list_pop_back(linked_list *l);

// linked_list_remove removes the item out of the linked list, if it exists. If
// there are duplicate items in the linked list, it will only remove one of
// them. If the item does not exist in the linked list, it will silently do
// nothing.
void linked_list_remove(linked_list *l, int i);

// linked_list_contains returns true if the given item exists in the linked
// list, and false otherwise.
bool linked_list_contains(linked_list *l, int i);

// linked_list_size returns the number of items currently in the linked list.
int linked_list_size(linked_list *l);

// free_linked_list frees the memory allocated for the linked list (the memory
// of any remaining nodes, as well as the linked list header struct itself).
void free_linked_list(linked_list *l);

#endif
