#include <stdlib.h>
#include <stdio.h>

struct node {
    int val;
    struct node* next;
};

struct node* new_node(int val) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->val = val;
    return new_node;
}

void traverse(struct node* n) {
    for (struct node* cur = n; cur != NULL; cur = cur->next) {
        printf("%d\n", cur->val);
    }
}

struct node* insert_after(struct node* n, int val) {
    struct  node* new = new_node(val);
    new->next = n->next;
    n->next = new;
    return new;
}

void remove_after(struct node* n) {
    if (n->next == NULL) {
        return;
    }

    struct node* tmp = n->next;
    n->next = tmp->next;
    free(tmp);
}

int main() {
    struct node* head = new_node(0);
    struct node* n = head;
    for (int i=1; i<=10; i++) {
        n = insert_after(n, i);
    }

    printf("Traversal 1\n");
    traverse(head);

    remove_after(head->next->next); // remove "3"

    printf("Traversal 2\n");
    traverse(head);
}
