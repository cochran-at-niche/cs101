#include "linked_list.h"
#include <stdio.h>


// Helper functions (not defined in header file)

// new_node allocates memory for a new node, initializes it's fields to their
// default values, and returns it.
static node* new_node() {
    node* n = (node*) malloc(sizeof(node));
    n->next = NULL;
    n->prev = NULL;
    n->val = 0;
    return n;
}

// insert_node_after inserts newNode after the specified node in the linked
// list.
static void insert_node_after(node* n, node* newNode) {
    node* next = n->next;
    n->next = newNode;
    newNode->next = next;
    next->prev = newNode;
    newNode->prev = n;
}

// remove_node removes the specified node from the linked list, and frees the
// memory associated with it.
static void remove_node(node* n) {
    n->prev->next = n->next;
    n->next->prev = n->prev;
    free(n);
}


// Public functions (defined in header file)

// new_linked_list allocates memory for a new linked list, initializes its
// fields, and returns it.
linked_list* new_linked_list() {
    // Allocate memory for a new linked list
    linked_list* l = (linked_list*) malloc(sizeof(linked_list));

    // Initialize fields. The sentinal node doesn't contain a value, and
    // therefore doesn't actually count towards the size of the linked list.
    // It's next and prev pointers point back to itself, at the start, since
    // it's a circular linked list
    l->sentinal = new_node();
    l->sentinal->next = l->sentinal;
    l->sentinal->prev = l->sentinal;
    l->size = 0;

    return l;
}

// linked_list_push_front inserts the given item at the front of the linked list.
void linked_list_push_front(linked_list* l, int i) {
    node* newNode = new_node();
    newNode->val = i;
    insert_node_after(l->sentinal, newNode);
    l->size++;
}

// linked_list_pop_front removes the item at the front of the list and returns it.
int linked_list_pop_front(linked_list* l) {
    if (l->sentinal->next == l->sentinal) {
        return -1;
    }

    int val = l->sentinal->next->val;
    remove_node(l->sentinal->next);
    l->size--;
    return val;
}

// linked_list_push_back inserts the given item at the back of the linked list.
void linked_list_push_back(linked_list* l, int i) {
    node* newNode = new_node();
    newNode->val = i;
    insert_node_after(l->sentinal->prev, newNode);
    l->size++;
}

// linked_list_pop_back removes the item at the back of the list and returns it.
int linked_list_pop_back(linked_list* l) {
    if (l->sentinal->prev == l->sentinal) {
        return -1;
    }

    int val = l->sentinal->prev->val;
    remove_node(l->sentinal->prev);
    l->size--;
    return val;
}

// linked_list_remove removes the item out of the linked list, if it exists. If
// there are duplicate items in the linked list, it will only remove one of
// them. If the item does not exist in the linked list, it will silently do
// nothing.
void linked_list_remove(linked_list* l, int i) {
    for (node* n = l->sentinal->next; n!= l->sentinal; n = n->next) {
        if (n->val == i) {
            remove_node(n);
            l->size--;
            return;
        }
    }
}

// linked_list_contains returns true if the given item exists in the linked
// list, and false otherwise.
bool linked_list_contains(linked_list* l, int i) {
    for (node* n = l->sentinal->next; n!= l->sentinal; n = n->next) {
        if (n->val == i) {
            return true;
        }
    }

    return false;
}

// linked_list_size returns the number of items currently in the linked list.
int linked_list_size(linked_list* l) {
    return l->size;
}

// free_linked_list frees the memory allocated for the linked list (the memory
// of any remaining nodes, as well as the linked list header struct itself).
void free_linked_list(linked_list* l) {
    node* next;
    for (node* n = l->sentinal->next; n != l->sentinal; n = next) {
        next = n->next;
        free(n);
    }
    free(l->sentinal);
    free(l);
}
