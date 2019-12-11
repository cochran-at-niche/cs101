#include "test.h"

int main() {
    // new_linked_list:
    test_new_linked_list();

    // push_front:
    test_linked_list_push_front();
    test_linked_list_push_front_multiple();
    test_linked_list_push_front_many();
    test_linked_list_push_front_duplicates();

    // pop_front:
    test_linked_list_pop_front_empty();
    test_linked_list_pop_front();
    test_linked_list_pop_front_multiple();
    test_linked_list_pop_front_many();
    test_linked_list_pop_front_duplicates();

    // push_back:
    test_linked_list_push_back();
    test_linked_list_push_back_multiple();
    test_linked_list_push_back_many();
    test_linked_list_push_back_duplicates();

    // pop_back:
    test_linked_list_pop_back_empty();
    test_linked_list_pop_back();
    test_linked_list_pop_back_multiple();
    test_linked_list_pop_back_many();
    test_linked_list_pop_back_duplicates();

    // push_back, pop_front:
    test_linked_list_push_back_pop_front();
    test_linked_list_push_back_pop_front_multiple();
    test_linked_list_push_back_pop_front_many();

    // push front, pop back:
    test_linked_list_push_front_pop_back();
    test_linked_list_push_front_pop_back_multiple();
    test_linked_list_push_front_pop_back_many();

    // remove:
    test_linked_list_push_front_remove();
    test_linked_list_push_front_remove_multiple();
    test_linked_list_push_front_remove_many();
    test_linked_list_push_front_remove_non_existent();
    test_linked_list_push_front_remove_duplicates();
}

// new_linked_list:

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
    free_linked_list(l);
}

// push_front:

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
    free_linked_list(l);
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
    free_linked_list(l);
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
    free_linked_list(l);
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
    free_linked_list(l);
}

// pop_front:

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
    free_linked_list(l);
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
    free_linked_list(l);
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
    free_linked_list(l);
}

void test_linked_list_pop_front_many() {
    printf("\ntest_linked_list_pop_front_many\n");
    bool success = true;

    linked_list* l = new_linked_list();
    for (int i=0; i<100; i++) {
        linked_list_push_front(l, i);
    }
    for (int i=99; i>=0; i--) {
        int result = linked_list_pop_front(l);
        if (result != i) {
            printf("Expected linked_list_pop_front() to return %d\n", i);
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
    free_linked_list(l);
}

void test_linked_list_pop_front_duplicates() {
    printf("\ntest_linked_list_pop_front_duplicates\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_front(l, 1);
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
    free_linked_list(l);
}

// push_back:

void test_linked_list_push_back() {
    printf("\ntest_linked_list_push_back\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_back(l, 1);
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_back(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a size of 1 after calling linked_list_push_back(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_multiple() {
    printf("\ntest_linked_list_push_back_multiple\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_push_back(l, 2);
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_back(1) and linked_list_push_back(2)\n");
        success = false;
    }
    if (!linked_list_contains(l, 2)) {
        printf("Expected linked list to contain 2 after calling linked_list_push_back(1) and linked_list_push_back(2)\n");
        success = false;
    }
    if (linked_list_size(l) != 2) {
		printf("Expected linked list to have a size of 2 after calling linked_list_push_back(1) and linked_list_push_back(2)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_many() {
    printf("\ntest_linked_list_push_back_many\n");
    bool success = true;

    linked_list* l = new_linked_list();
    for (int i=0; i<100; i++) {
        linked_list_push_back(l, i);
    }
    for (int i=0; i<100; i++) {
        if (!linked_list_contains(l, i)) {
            printf("Expected linked list to contain %d after calling linked_list_push_back(%d)\n", i, i);
            success = false;
            break;
        }
    }
    if (linked_list_size(l) != 100) {
		printf("Expected linked list to have a linked_list_size of 100 after calling linked_list_push_back() 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_duplicates() {
    printf("\ntest_linked_list_push_back_duplicates\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_push_back(l, 1);
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_back(1) and linked_list_push_back(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 2) {
		printf("Expected linked list to have a size of 2 after calling linked_list_push_back(1) and linked_list_push_back(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

// pop_back:

void test_linked_list_pop_back_empty() {
    printf("\ntest_linked_list_pop_back_empty\n");
    bool success = true;

    linked_list* l = new_linked_list();
    int result = linked_list_pop_back(l);
    if (result != -1) {
        printf("Expected linked_list_pop_back() to return -1 when called on an empty list\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_pop_back() {
    printf("\ntest_linked_list_pop_back\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_back(l, 1);
    int result = linked_list_pop_back(l);
    if (result != 1) {
        printf("Expected linked_list_pop_back() to return 1 after calling linked_list_push_back(1)\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_back(1) and linked_list_pop_back(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_back(1) and linked_list_pop_back(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_pop_back_multiple() {
    printf("\ntest_linked_list_pop_back_multiple\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_push_back(l, 2);
    int result = linked_list_pop_back(l);
    if (result != 2) {
        printf("Expected linked_list_pop_back() to return 2 after calling linked_list_push_back(1) and linked_list_push_back(2)\n");
        success = false;
    }
    if (linked_list_contains(l, 2)) {
        printf("Expected linked list to not contain 2 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_back()\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a size of 1 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_back()\n");
        success = false;
    }
    result = linked_list_pop_back(l);
    if (result != 1) {
        printf("Expected linked_list_pop_back() to return 1 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_back()\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_back() twice\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_back() twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_pop_back_many() {
    printf("\ntest_linked_list_pop_back_many\n");
    bool success = true;

    linked_list* l = new_linked_list();
    for (int i=0; i<100; i++) {
        linked_list_push_back(l, i);
    }
    for (int i=99; i>=0; i--) {
        int result = linked_list_pop_back(l);
        if (result != i) {
            printf("Expected linked_list_pop_back() to return %d\n", i);
            success = false;
            break;
        }
    }
    for (int i=0; i<100; i++) {
        if (linked_list_contains(l, i)) {
            printf("Expected linked list to not contain %d after calling linked_list_push_back(%d) and linked_list_pop_back()\n", i, i);
            success = false;
            break;
        }
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_back() and linked_list_pop_back() 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_pop_back_duplicates() {
    printf("\ntest_linked_list_pop_back_duplicates\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_push_back(l, 1);
    int result = linked_list_pop_back(l);
    if (result != 1) {
        printf("Expected linked_list_pop_back() to return 1 after calling linked_list_push_back(1) twice\n");
        success = false;
    }
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_back(1) twice and linked_list_pop_back() once\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a size of 1 after calling linked_list_push_back(1) twice and linked_list_pop_back() once\n");
        success = false;
    }
    result = linked_list_pop_back(l);
    if (result != 1) {
        printf("Expected linked_list_pop_back() to return 1 after calling linked_list_push_back(1) twice and linked_list_pop_back() once\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_back(1) twice and linked_list_pop_back() twice\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_back(1) twice and linked_list_pop_back() twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

// push_back, pop_front:

void test_linked_list_push_back_pop_front() {
    printf("\ntest_linked_list_push_back_pop_front\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_back(l, 1);
    int result = linked_list_pop_front(l);
    if (result != 1) {
        printf("Expected linked_list_pop_front() to return 1 after calling linked_list_push_back(1)\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_back(1) and linked_list_pop_front(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_back(1) and linked_list_pop_front(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_pop_front_multiple() {
    printf("\ntest_linked_list_push_back_pop_front_multiple\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_push_back(l, 2);
    int result = linked_list_pop_front(l);
    if (result != 1) {
        printf("Expected linked_list_pop_front() to return 1 after calling linked_list_push_back(1) and linked_list_push_back(2)\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_front()\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a size of 1 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_front()\n");
        success = false;
    }
    result = linked_list_pop_front(l);
    if (result != 2) {
        printf("Expected linked_list_pop_front() to return 2 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_front()\n");
        success = false;
    }
    if (linked_list_contains(l, 2)) {
        printf("Expected linked list to not contain 2 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_front() twice\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_pop_front() twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_pop_front_many() {
    printf("\ntest_linked_list_push_back_pop_front_many\n");
    bool success = true;

    linked_list* l = new_linked_list();
    for (int i=0; i<100; i++) {
        linked_list_push_back(l, i);
    }
    for (int i=0; i<100; i++) {
        int result = linked_list_pop_front(l);
        if (result != i) {
            printf("Expected linked_list_pop_front() to return %d after calling it %d times\n", i, i);
            success = false;
            break;
        }
    }
    for (int i=0; i<100; i++) {
        if (linked_list_contains(l, i)) {
            printf("Expected linked list to not contain %d after calling linked_list_push_back(%d) and linked_list_pop_front()\n", i, i);
            success = false;
            break;
        }
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_back() and linked_list_pop_front() 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

// push front, pop back:

void test_linked_list_push_front_pop_back() {
    printf("\ntest_linked_list_push_front_pop_back\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_front(l, 1);
    int result = linked_list_pop_back(l);
    if (result != 1) {
        printf("Expected linked_list_pop_back() to return 1 after calling linked_list_push_front(1)\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_front(1) and linked_list_pop_back(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_front(1) and linked_list_pop_back(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_front_pop_back_multiple() {
    printf("\ntest_linked_list_push_front_pop_back_multiple\n");
    bool success = true;

    linked_list* l = new_linked_list();
    linked_list_push_front(l, 1);
    linked_list_push_front(l, 2);
    int result = linked_list_pop_back(l);
    if (result != 1) {
        printf("Expected linked_list_pop_back() to return 1 after calling linked_list_push_front(1) and linked_list_push_front(2)\n");
        success = false;
    }
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_back()\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a size of 1 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_back()\n");
        success = false;
    }
    result = linked_list_pop_back(l);
    if (result != 2) {
        printf("Expected linked_list_pop_back() to return 2 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_back()\n");
        success = false;
    }
    if (linked_list_contains(l, 2)) {
        printf("Expected linked list to not contain 2 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_back() twice\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_pop_back() twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_front_pop_back_many() {
    printf("\ntest_linked_list_push_front_pop_back_many\n");
    bool success = true;

    linked_list* l = new_linked_list();
    for (int i=0; i<100; i++) {
        linked_list_push_front(l, i);
    }
    for (int i=0; i<100; i++) {
        int result = linked_list_pop_back(l);
        if (result != i) {
            printf("Expected linked_list_pop_back() to return %d after calling it %d times\n", i, i);
            success = false;
            break;
        }
    }
    for (int i=0; i<100; i++) {
        if (linked_list_contains(l, i)) {
            printf("Expected linked list to not contain %d after calling linked_list_push_front(%d) and linked_list_pop_back()\n", i, i);
            success = false;
            break;
        }
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a size of 0 after calling linked_list_push_front() and linked_list_pop_back() 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

// push_front, remove:

void test_linked_list_push_front_remove() {
    printf("\ntest_linked_list_push_front_remove\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_front(l, 1);
    linked_list_remove(l, 1);

    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_front(1) and linked_list_remove(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a linked_list_size of 0 after calling linked_list_push_front(1) and linked_list_remove(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_front_remove_multiple() {
    printf("\ntest_linked_list_push_front_remove_multiple)\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_front(l, 1);
    linked_list_push_front(l, 2);
    linked_list_remove(l, 1);
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_remove(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a linked_list_size of 1 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_remove(1)\n");
        success = false;
    }
    linked_list_remove(l, 2);
    if (linked_list_contains(l, 2)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_front(1), linked_list_push_front(2), linked_list_remove(1), and linked_list_remove(2)\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a linked_list_size of 1 after calling linked_list_push_front(1), linked_list_push_front(2), linked_list_remove(1), and linked_list_remove(2)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_front_remove_many() {
    printf("\ntest_linked_list_push_front_remove_many\n");
    bool success = true;

    linked_list *l = new_linked_list();
    for (int i=0; i<100; i++) {
        linked_list_push_front(l, i);
    }
    for (int i=0; i<100; i++) {
        linked_list_remove(l, i);
    }
    for (int i=0; i<100; i++) {
        if (linked_list_contains(l, i)) {
            printf("Expected linked list to not contain %d after calling linked_list_push_front(%d) and linked_list_remove(%d)\n", i, i, i);
            success = false;
            break;
        }
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a linked_list_size of 0 after calling linked_list_push_front and linked_list_remove 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_front_remove_non_existent() {
    printf("\ntest_linked_list_push_front_remove_non_existent\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_remove(l, 1);
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_remove(1) on an empty linked list\n");
        success = false;
    }
    linked_list_push_front(l, 1);
    linked_list_remove(l, 2);
    if (linked_list_contains(l, 2)) {
        printf("Expected linked list to not contain 2 after calling linked_list_remove(1), linked_list_push_front(1), and linked_list_remove(2) on an empty linked list\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a linked_list_size of 1 after calling linked_list_remove(1), linked_list_push_front(1), and linked_list_remove(2) on an empty linked list\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_front_remove_duplicates() {
    printf("\ntest_linked_list_push_front_remove_duplicates\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_front(l, 1);
    linked_list_push_front(l, 1);
    linked_list_remove(l, 1);
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_front(1) twice and linked_list_remove(1) once\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a linked_list_size of 1 after calling linked_list_push_front(1) twice and linked_list_remove(1) once\n");
        success = false;
    }
    linked_list_remove(l, 1);
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_front(1) twice and linked_list_remove(1) twice\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a linked_list_size of 0 after calling linked_list_push_front(1) twice and linked_list_remove(1) twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_front_remove_pop_front() {
    printf("\ntest_linked_list_push_front_remove_pop_front\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_front(l, 1);
    linked_list_push_front(l, 2);
    linked_list_remove(l, 2);
    int result = linked_list_pop_front(l);
    if (result != 1) {
        printf("Expected linked_list_pop_front() to return 1 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_remove(2)\n");
        success = false;
    }
    result = linked_list_pop_front(l);
    if (result != -1) {
        printf("Expected linked_list_pop_front() to return -1 after calling linked_list_push_front(1), linked_list_push_front(2), linked_list_remove(2), and linked_list_pop_front()\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_front_remove_pop_back() {
    printf("\ntest_linked_list_push_front_remove_pop_back\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_front(l, 1);
    linked_list_push_front(l, 2);
    linked_list_remove(l, 1);
    int result = linked_list_pop_back(l);
    if (result != 2) {
        printf("Expected linked_list_pop_back() to return 2 after calling linked_list_push_front(1), linked_list_push_front(2), and linked_list_remove(1)\n");
        success = false;
    }
    result = linked_list_pop_back(l);
    if (result != -1) {
        printf("Expected linked_list_pop_back() to return -1 after calling linked_list_push_front(1), linked_list_push_front(2), linked_list_remove(1), and linked_list_pop_back()\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

// push_back, remove:

void test_linked_list_push_back_remove() {
    printf("\ntest_linked_list_push_back_remove\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_remove(l, 1);

    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_back(1) and linked_list_remove(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a linked_list_size of 0 after calling linked_list_push_back(1) and linked_list_remove(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_remove_multiple() {
    printf("\ntest_linked_list_push_back_remove_multiple)\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_push_back(l, 2);
    linked_list_remove(l, 1);
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_remove(1)\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a linked_list_size of 1 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_remove(1)\n");
        success = false;
    }
    linked_list_remove(l, 2);
    if (linked_list_contains(l, 2)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_back(1), linked_list_push_back(2), linked_list_remove(1), and linked_list_remove(2)\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a linked_list_size of 1 after calling linked_list_push_back(1), linked_list_push_back(2), linked_list_remove(1), and linked_list_remove(2)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_remove_many() {
    printf("\ntest_linked_list_push_back_remove_many\n");
    bool success = true;

    linked_list *l = new_linked_list();
    for (int i=0; i<100; i++) {
        linked_list_push_back(l, i);
    }
    for (int i=0; i<100; i++) {
        linked_list_remove(l, i);
    }
    for (int i=0; i<100; i++) {
        if (linked_list_contains(l, i)) {
            printf("Expected linked list to not contain %d after calling linked_list_push_back(%d) and linked_list_remove(%d)\n", i, i, i);
            success = false;
            break;
        }
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a linked_list_size of 0 after calling linked_list_push_back and linked_list_remove 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_remove_non_existent() {
    printf("\ntest_linked_list_push_back_remove_non_existent\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_remove(l, 1);
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_remove(1) on an empty linked list\n");
        success = false;
    }
    linked_list_push_back(l, 1);
    linked_list_remove(l, 2);
    if (linked_list_contains(l, 2)) {
        printf("Expected linked list to not contain 2 after calling linked_list_remove(1), linked_list_push_back(1), and linked_list_remove(2) on an empty linked list\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a linked_list_size of 1 after calling linked_list_remove(1), linked_list_push_back(1), and linked_list_remove(2) on an empty linked list\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_remove_duplicates() {
    printf("\ntest_linked_list_push_back_remove_duplicates\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_push_back(l, 1);
    linked_list_remove(l, 1);
    if (!linked_list_contains(l, 1)) {
        printf("Expected linked list to contain 1 after calling linked_list_push_back(1) twice and linked_list_remove(1) once\n");
        success = false;
    }
    if (linked_list_size(l) != 1) {
		printf("Expected linked list to have a linked_list_size of 1 after calling linked_list_push_back(1) twice and linked_list_remove(1) once\n");
        success = false;
    }
    linked_list_remove(l, 1);
    if (linked_list_contains(l, 1)) {
        printf("Expected linked list to not contain 1 after calling linked_list_push_back(1) twice and linked_list_remove(1) twice\n");
        success = false;
    }
    if (linked_list_size(l) != 0) {
		printf("Expected linked list to have a linked_list_size of 0 after calling linked_list_push_back(1) twice and linked_list_remove(1) twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_remove_pop_back() {
    printf("\ntest_linked_list_push_back_remove_pop_back\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_push_back(l, 2);
    linked_list_remove(l, 2);
    int result = linked_list_pop_back(l);
    if (result != 1) {
        printf("Expected linked_list_pop_back() to return 1 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_remove(2)\n");
        success = false;
    }
    result = linked_list_pop_back(l);
    if (result != -1) {
        printf("Expected linked_list_pop_back() to return -1 after calling linked_list_push_back(1), linked_list_push_back(2), linked_list_remove(2), and linked_list_pop_back()\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}

void test_linked_list_push_back_remove_pop_front() {
    printf("\ntest_linked_list_push_back_remove_pop_front\n");
    bool success = true;

    linked_list *l = new_linked_list();
    linked_list_push_back(l, 1);
    linked_list_push_back(l, 2);
    linked_list_remove(l, 1);
    int result = linked_list_pop_front(l);
    if (result != 2) {
        printf("Expected linked_list_pop_front() to return 2 after calling linked_list_push_back(1), linked_list_push_back(2), and linked_list_remove(1)\n");
        success = false;
    }
    result = linked_list_pop_front(l);
    if (result != -1) {
        printf("Expected linked_list_pop_front() to return -1 after calling linked_list_push_back(1), linked_list_push_back(2), linked_list_remove(1), and linked_list_pop_front()\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_linked_list(l);
}
