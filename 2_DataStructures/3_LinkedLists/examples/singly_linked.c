#include <stdlib.h>
#include <stdio.h>

typedef struct node {
    int val;
    struct node* next;
} node;

node* new_node(int val) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->val = val;
    return new_node;
}

void traverse(node* head) {
    for (node* cur = head; cur != NULL; cur = cur->next) {
        printf("%d\n", cur->val);
    }
}

node* insert_after(node* n, int val) {
    struct  node* new = new_node(val);
    new->next = n->next;
    n->next = new;
    return new;
}

void remove_after(node* n) {
    if (n->next == NULL) {
        return;
    }

    node* tmp = n->next;
    n->next = tmp->next;
    free(tmp);
}

int main() {
    node* head = new_node(0);

    node* n = head;
    for (int i=1; i<=10; i++) {
        n = insert_after(n, i);
    }

    printf("Traversal 1\n");
    traverse(head);

    remove_after(head->next->next); // remove "3"

    printf("Traversal 2\n");
    traverse(head);
}
