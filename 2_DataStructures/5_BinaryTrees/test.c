#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "binary_tree.h"
#include "test.h"

int main() {
    test_new_binary_tree();
    test_binary_tree_add();
    test_binary_tree_add_multiple();
    test_binary_tree_add_many();
    test_binary_tree_add_many_reverse();
    test_binary_tree_add_duplicates();
    test_binary_tree_remove();
    test_binary_tree_remove_multiple();
    test_binary_tree_remove_many();
    test_binary_tree_remove_non_existent();
    test_binary_tree_remove_duplicates();
}

void test_new_binary_tree() {
    printf("\ntest_new_binary_tree\n");
    bool success = true;

    binary_tree* a = new_binary_tree();
    if (binary_tree_contains(a, 1)) {
        printf("Expected newly initialized binary tree to not contain 1\n");
        success = false;
    }
    if (binary_tree_size(a) != 0) {
		printf("Expected newly initialized binary tree to have a size of 0\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_add() {
    printf("\ntest_binary_tree_add\n");
    bool success = true;

    binary_tree* a = new_binary_tree();
    binary_tree_add(a, 1);
    if (!binary_tree_contains(a, 1)) {
        printf("Expected binary tree to contain 1 after calling binary_tree_add(1)\n");
        success = false;
    }
    if (binary_tree_size(a) != 1) {
		printf("Expected binary tree to have a size of 1 after calling binary_tree_add(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_add_multiple() {
    printf("\ntest_binary_tree_add_multiple\n");
    bool success = true;

    binary_tree* a = new_binary_tree();
    binary_tree_add(a, 1);
    binary_tree_add(a, 2);
    if (!binary_tree_contains(a, 1)) {
        printf("Expected binary tree to contain 1 after calling binary_tree_add(1) and binary_tree_add(2)\n");
        success = false;
    }
    if (!binary_tree_contains(a, 2)) {
        printf("Expected binary tree to contain 2 after calling binary_tree_add(1) and binary_tree_add(2)\n");
        success = false;
    }
    if (binary_tree_size(a) != 2) {
		printf("Expected binary tree to have a size of 2 after calling binary_tree_add(1) and binary_tree_add(2)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_add_many() {
    printf("\ntest_binary_tree_add_many\n");
    bool success = true;

    binary_tree* a = new_binary_tree();
    for (int i=0; i<100; i++) {
        binary_tree_add(a, i);
    }
    for (int i=0; i<100; i++) {
        if (!binary_tree_contains(a, i)) {
            printf("Expected binary tree to contain %d after calling binary_tree_add(%d)\n", i, i);
            success = false;
            break;
        }
    }
    if (binary_tree_size(a) != 100) {
		printf("Expected binary tree to have a size of 100 after calling binary_tree_add 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_add_many_reverse() {
    printf("\ntest_binary_tree_add_many_reverse\n");
    bool success = true;

    binary_tree* a = new_binary_tree();
    for (int i=99; i>=0; i--) {
        binary_tree_add(a, i);
    }
    for (int i=99; i>=0; i--) {
        if (!binary_tree_contains(a, i)) {
            printf("Expected binary tree to contain %d after calling binary_tree_add(%d)\n", i, i);
            success = false;
            break;
        }
    }
    if (binary_tree_size(a) != 100) {
		printf("Expected binary tree to have a size of 100 after calling binary_tree_add 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_add_duplicates() {
    printf("\ntest_binary_tree_add_duplicates\n");
    bool success = true;

    binary_tree* a = new_binary_tree();
    binary_tree_add(a, 1);
    binary_tree_add(a, 1);
    if (!binary_tree_contains(a, 1)) {
        printf("Expected binary tree to contain 1 after calling binary_tree_add(1)\n");
        success = false;
    }
    if (binary_tree_size(a) != 2) {
		printf("Expected binary tree to have a size of 2 after calling binary_tree_add(1) twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_remove() {
    printf("\ntest_binary_tree_remove\n");
    bool success = true;

    binary_tree *a = new_binary_tree();
    binary_tree_add(a, 1);
    binary_tree_remove(a, 1);

    if (binary_tree_contains(a, 1)) {
        printf("Expected binary tree to not contain 1 after calling binary_tree_add(1) and binary_tree_remove(1)\n");
        success = false;
    }
    if (binary_tree_size(a) != 0) {
		printf("Expected binary tree to have a size of 0 after calling binary_tree_add(1) and binary_tree_remove(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_remove_multiple() {
    printf("\ntest_binary_tree_remove_multiple)\n");
    bool success = true;

    binary_tree *a = new_binary_tree();
    binary_tree_add(a, 1);
    binary_tree_add(a, 2);
    binary_tree_remove(a, 1);
    if (binary_tree_contains(a, 1)) {
        printf("Expected binary tree to not contain 1 after calling binary_tree_add(1), binary_tree_add(2), and binary_tree_remove(1)\n");
        success = false;
    }
    if (binary_tree_size(a) != 1) {
		printf("Expected binary tree to have a size of 1 after calling binary_tree_add(1), binary_tree_add(2), and binary_tree_remove(1)\n");
        success = false;
    }
    binary_tree_remove(a, 2);
    if (binary_tree_contains(a, 2)) {
        printf("Expected binary tree to not contain 1 after calling binary_tree_add(1), binary_tree_add(2), binary_tree_remove(1), and binary_tree_remove(2)\n");
        success = false;
    }
    if (binary_tree_size(a) != 0) {
		printf("Expected binary tree to have a size of 1 after calling binary_tree_add(1), binary_tree_add(2), binary_tree_remove(1), and binary_tree_remove(2)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_remove_many() {
    printf("\ntest_binary_tree_remove_many\n");
    bool success = true;

    binary_tree *a = new_binary_tree();
    for (int i=0; i<100; i++) {
        binary_tree_add(a, i);
    }
    for (int i=0; i<100; i++) {
        binary_tree_remove(a, i);
    }
    for (int i=0; i<100; i++) {
        if (binary_tree_contains(a, i)) {
            printf("Expected binary tree to not contain %d after calling binary_tree_add(%d) and binary_tree_remove(%d)\n", i, i, i);
            success = false;
            break;
        }
    }
    if (binary_tree_size(a) != 0) {
		printf("Expected binary tree to have a size of 0 after calling binary_tree_add and binary_tree_remove 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_remove_non_existent() {
    printf("\ntest_binary_tree_remove_non_existent\n");
    bool success = true;

    binary_tree *a = new_binary_tree();
    binary_tree_remove(a, 1);
    if (binary_tree_contains(a, 1)) {
        printf("Expected binary tree to not contain 1 after calling binary_tree_remove(1) on an empty binary tree\n");
        success = false;
    }
    binary_tree_add(a, 1);
    binary_tree_remove(a, 2);
    if (binary_tree_contains(a, 2)) {
        printf("Expected binary tree to not contain 2 after calling binary_tree_remove(1), binary_tree_add(1), and binary_tree_remove(2) on an empty binary tree\n");
        success = false;
    }
    if (binary_tree_size(a) != 1) {
		printf("Expected binary tree to have a size of 1 after calling binary_tree_remove(1), binary_tree_add(1), and binary_tree_remove(2) on an empty binary tree\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}

void test_binary_tree_remove_duplicates() {
    printf("\ntest_binary_tree_remove_duplicates\n");
    bool success = true;

    binary_tree *a = new_binary_tree();
    binary_tree_add(a, 1);
    binary_tree_add(a, 1);
    binary_tree_remove(a, 1);
    if (!binary_tree_contains(a, 1)) {
        printf("Expected binary tree to contain 1 after calling binary_tree_add(1) twice and binary_tree_remove(1) once\n");
        success = false;
    }
    if (binary_tree_size(a) != 1) {
		printf("Expected binary tree to have a size of 1 after calling binary_tree_add(1) twice and binary_tree_remove(1) once\n");
        success = false;
    }
    binary_tree_remove(a, 1);
    if (binary_tree_contains(a, 1)) {
        printf("Expected binary tree to not contain 1 after calling binary_tree_add(1) twice and binary_tree_remove(1) twice\n");
        success = false;
    }
    if (binary_tree_size(a) != 0) {
		printf("Expected binary tree to have a size of 0 after calling binary_tree_add(1) twice and binary_tree_remove(1) twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_binary_tree(a);
}
