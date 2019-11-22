#include "test.h"

int main() {
    test_new_linked_list();
    test_linked_list_push_front();
    test_linked_list_push_front_multiple();
    test_linked_list_push_front_many();
    test_linked_list_push_front_duplicates();
    test_linked_list_pop_front_empty();
    test_linked_list_pop_front();
    test_linked_list_pop_front_multiple();
    test_linked_list_pop_front_many();
    test_linked_list_pop_front_duplicates();
}

void test_new_linked_list() {
    printf("\ntest_new_linked_list\n");
    bool success = true;

    linked_list* l = new_linked_list();
    if (linked_list_contains(l, 1)) {
        printf("Expected newly initialized linked list to not contain 1\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected newly initialized linked list to have a size of 0\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}


void test_linked_list_push_front() {
    printf("\ntest_linked_list_push_front\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_front(l, 1);
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_front(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a size of 1 after calling linked_list_push_front(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}

void test_linked_list_push_front_multiple() {
    printf("\ntest_linked_list_push_front_multiple\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_front(l, 1);
    linked_list_push_front(l, 2);
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_front(1) and linked_list_push_front(2)\n");
        success = false;
    }
    if (!linked_list_contains(l, 2)) {
        printf("Expected linked list to contain 2 after calling linked_list_push_front(1) and linked_list_push_front(2)\n");
        success = false;
    }
    if (linked_list_size(l) != 2) {
		printf("Expected linked list to have a size of 2 after calling linked_list_push_front(1) and linked_list_push_front(2)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}

void test_linked_list_push_front_many() {
    printf("\ntest_linked_list_push_front_many\n");
    bool success = true;

    linked_list* l = new_linked_list();
    for (int i=0; i<100; i++) {
        linked_list_push_front(l, i);
    }
    for (int i=0; i<100; i++) {
        if (!linked_list_contains(l, i)) {
            printf("Expected linked list to contain %d after calling linked_list_push_front(%d)\n", i, i);
            success = false;
            break;
        }
    }
    if (linked_list_size(l) != 100) {
		printf("Expected linked list to have a linked_list_size of 100 after calling linked_list_push_front() 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}

void test_linked_list_push_front_duplicates() {
    printf("\ntest_linked_list_push_front_duplicates\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_front(l, 1);
    linked_list_push_front(l, 1);
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_front(1) and linked_list_push_front(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 2) {
		printf("Expected linked list to have a size of 2 after calling linked_list_push_front(1) and linked_list_push_front(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}

void test_linked_list_pop_front_empty() {
    printf("\ntest_linked_list_pop_front_empty\n");
    bool success = true;

    linked_list* l = new_linked_list();
    int result = linked_list_pop_front(l);
    if (result != -1) {
        printf("Expected linked_list_pop_front() to return -1 when called on an empty list\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}

void test_linked_list_pop_front() {
    printf("\ntest_linked_list_pop_front\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_front(l, 1);
    int result = linked_list_pop_front(l);
    if (result != 1) {
        printf("Expected linked_list_pop_front() to return 1 after calling linked_list_push_front(1)\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_front(1) and linked_list_pop_front(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_front(1) and linked_list_pop_front(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}

void test_linked_list_pop_front_multiple() {
    printf("\ntest_linked_list_pop_front_multiple\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_front(l, 1);
    linked_list_push_front(l, 2);
    int result = linked_list_pop_front(l);
    if (result != 2) {
        printf("Expected linked_list_pop_front() to return 2 after calling linked_list_push_front(1) and linked_list_push_front(2)\n");
        success = false;
    }
    if (linked_list_contains(l, 2)) {
        printf("Expected linked list to not contain 2 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_front()\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a size of 1 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_front()\n");
        success = false;
    }
    result = linked_list_pop_front(l);
    if (result != 1) {
        printf("Expected linked_list_pop_front() to return 1 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_front()\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_front() twice\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_front() twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}

void test_linked_list_pop_front_many() {
    printf("\ntest_linked_list_pop_front_many\n");
    bool success = true;

    linked_list* l = new_linked_list();
    for (int i=0; i<100; i++) {
        linked_list_push_front(l, i);
    }
    for (int i=0; i<100; i++) {
        int result = linked_list_pop_front(l);
        int expected = 99-i;
        if (result != i) {
            printf("Expected linked_list_pop_front() to return %d after calling it %d times\n", expected, i);
            success = false;
            break;
        }
    }
    for (int i=0; i<100; i++) {
        if (linked_list_contains(l, i)) {
            printf("Expected linked list to not contain %d after calling linked_list_push_front(%d) and linked_list_pop_front()\n", i, i);
            success = false;
            break;
        }
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_front() and linked_list_pop_front() 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}

void test_linked_list_pop_front_duplicates() {
    printf("\ntest_linked_list_pop_front_duplicates\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_front(l, 1);
    int result = linked_list_pop_front(l);
    if (result != 1) {
        printf("Expected linked_list_pop_front() to return 1 after calling linked_list_push_front(1) twice\n");
        success = false;
    }
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_front(1) twice and linked_list_pop_front() once\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a size of 1 after calling linked_list_push_front(1) twice and linked_list_pop_front() once\n");
        success = false;
    }
    result = linked_list_pop_front(l);
    if (result != 1) {
        printf("Expected linked_list_pop_front() to return 1 after calling linked_list_push_front(1) twice and linked_list_pop_front() once\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_front(1) twice and linked_list_pop_front() twice\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_front(1) twice and linked_list_pop_front() twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}
