#include "linked_list.h"

// Helper functions - not declared in header file because they aren't public

node* new_node() {
    node* n = (node*) malloc(sizeof(node));
    n->next = NULL;
    n->prev = NULL;
    n->val = 0;
    return n;
}

void insert_node_after(node* n, node* newNode) {
    // TODO: Write code to insert newNode after the specified node.
    // This will involve updating:
    //  - The next pointer of the specified node
    //  - The next and prev pointers of newNode
    //  - The prev pointer of the node currently after the specified node
}

void remove_node(node* n) {
    // TODO: Write code to remove newNode from the linked list
    // This will involve updating:
    //  - The next pointer of the node before it in the list
    //  - The prev pointer of the node after it in the list
    // You will also have to free the memory of the removed node
}

// Public functions (declared in the header file)

linked_list* new_linked_list() {
    // Allocate memory for a new linked list
    linked_list* l = (linked_list*) malloc(sizeof(linked_list));

    // Initialize fields
    l->sentinal = new_node();
    l->size = 0;

    return l;
}

void linked_list_push_front(linked_list *l, int i) {
    // TODO: Write code to insert an item at the front of the list.
    // This will involve:
    //  - Allocating memeory for a new node
    //  - Setting the value of the new node
    //  - Calling insert_node_after to insert the new node after the sentinal node
    //  - Incrementing the size field of the linked list
}

int linked_list_pop_front(linked_list *l) {
    // TODO: Write code to remove and return the item at the front of the list.
    // This will involve:
    //  - If the list is empty, return -1
    //  - Calling remove_node to remove the node at the front of the list
    //  - Freeing the memory associated with the removed node
    //  - Returning the value of the removed node (make sure to store the value
    //      before your free the node's memory!)
    //  - Decrementing the size field of the linked list

    return -1;
}

void linked_list_push_back(linked_list *l, int i) {
    // TODO: Write code to insert an item at the back of the list.
    // This will involve:
    //  - Allocating memeory for a new node
    //  - Setting the value of the new node
    //  - Calling insert_node_after to insert the new node before the sentinal
    //      node (i.e. after the node that is currently before the sentinal node)
    //  - Incrementing the size field of the linked list
}

int linked_list_pop_back(linked_list *l) {
    // TODO: Write code to remove and return the item at the back of the list.
    // This will involve:
    //  - If the list is empty, return -1
    //  - Calling remove_node to remove the node at the back of the list
    //  - Freeing the memory associated with the removed node
    //  - Returning the value of the removed node (make sure to store the value
    //      before your free the node's memory!)
    //  - Decrementing the size field of the linked list

    return -1;
}

bool linked_list_contains(linked_list *l, int i) {
    // TODO: Iterate through the list. Return true if it contains the specified
    // int, or false otherwise

    return false;
}

int linked_list_size(linked_list *l) {
    // TODO: Return the current size of the list

    return 0;
}

void free_linked_list(linked_list *l) {
    // TODO: Free the memory associated with any nodes remaining in the list,
    // then free the memory associated with the linked_list struct itself
}
