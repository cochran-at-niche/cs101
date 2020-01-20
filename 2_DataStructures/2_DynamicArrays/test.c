#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "dynamic_array.h"
#include "test.h"

int main() {
    test_new_dyn_arr();
    test_dyn_arr_add();
    test_dyn_arr_add_multiple();
    test_dyn_arr_add_many();
    test_dyn_arr_add_duplicates();
    test_dyn_arr_remove();
    test_dyn_arr_remove_multiple();
    test_dyn_arr_remove_many();
    test_dyn_arr_remove_non_existent();
    test_dyn_arr_remove_duplicates();
}

void test_new_dyn_arr() {
    printf("\ntest_new_dyn_arr\n");
    bool success = true;

    dyn_arr* a = new_dyn_arr();
    if (dyn_arr_contains(a, 1)) {
        printf("Expected newly initialized dynamic array to not contain 1\n");
        success = false;
    }
    if (dyn_arr_size(a) != 0) {
		printf("Expected newly initialized dynamic array to have a dyn_arr_size of 0\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}

void test_dyn_arr_add() {
    printf("\ntest_dyn_arr_add\n");
    bool success = true;

    dyn_arr* a = new_dyn_arr();
    dyn_arr_add(a, 1);
    if (!dyn_arr_contains(a, 1)) {
        printf("Expected dynamic array to contain 1 after calling dyn_arr_add(1)\n");
        success = false;
    }
    if (dyn_arr_size(a) != 1) {
		printf("Expected dynamic array to have a dyn_arr_size of 1 after calling dyn_arr_add(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}

void test_dyn_arr_add_multiple() {
    printf("\ntest_dyn_arr_add_multiple\n");
    bool success = true;

    dyn_arr* a = new_dyn_arr();
    dyn_arr_add(a, 1);
    dyn_arr_add(a, 2);
    if (!dyn_arr_contains(a, 1)) {
        printf("Expected dynamic array to contain 1 after calling dyn_arr_add(1) and dyn_arr_add(2)\n");
        success = false;
    }
    if (!dyn_arr_contains(a, 2)) {
        printf("Expected dynamic array to contain 2 after calling dyn_arr_add(1) and dyn_arr_add(2)\n");
        success = false;
    }
    if (dyn_arr_size(a) != 2) {
		printf("Expected dynamic array to have a dyn_arr_size of 2 after calling dyn_arr_add(1) and dyn_arr_add(2)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}

void test_dyn_arr_add_many() {
    printf("\ntest_dyn_arr_add_many\n");
    bool success = true;

    dyn_arr* a = new_dyn_arr();
    for (int i=0; i<100; i++) {
        dyn_arr_add(a, i);
    }
    for (int i=0; i<100; i++) {
        if (!dyn_arr_contains(a, i)) {
            printf("Expected dynamic array to contain %d after calling dyn_arr_add(%d)\n", i, i);
            success = false;
            break;
        }
    }
    if (dyn_arr_size(a) != 100) {
		printf("Expected dynamic array to have a dyn_arr_size of 100 after calling dyn_arr_add 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}

void test_dyn_arr_add_duplicates() {
    printf("\ntest_dyn_arr_add_duplicates\n");
    bool success = true;

    dyn_arr* a = new_dyn_arr();
    dyn_arr_add(a, 1);
    dyn_arr_add(a, 1);
    if (!dyn_arr_contains(a, 1)) {
        printf("Expected dynamic array to contain 1 after calling dyn_arr_add(1)\n");
        success = false;
    }
    if (dyn_arr_size(a) != 2) {
		printf("Expected dynamic array to have a dyn_arr_size of 2 after calling dyn_arr_add(1) twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}

void test_dyn_arr_remove() {
    printf("\ntest_dyn_arr_remove\n");
    bool success = true;

    dyn_arr *a = new_dyn_arr();
    dyn_arr_add(a, 1);
    dyn_arr_remove(a, 1);

    if (dyn_arr_contains(a, 1)) {
        printf("Expected dynamic array to not contain 1 after calling dyn_arr_add(1) and dyn_arr_remove(1)\n");
        success = false;
    }
    if (dyn_arr_size(a) != 0) {
		printf("Expected dynamic array to have a dyn_arr_size of 0 after calling dyn_arr_add(1) and dyn_arr_remove(1)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}

void test_dyn_arr_remove_multiple() {
    printf("\ntest_dyn_arr_remove_multiple)\n");
    bool success = true;

    dyn_arr *a = new_dyn_arr();
    dyn_arr_add(a, 1);
    dyn_arr_add(a, 2);
    dyn_arr_remove(a, 1);
    if (dyn_arr_contains(a, 1)) {
        printf("Expected dynamic array to not contain 1 after calling dyn_arr_add(1), dyn_arr_add(2), and dyn_arr_remove(1)\n");
        success = false;
    }
    if (dyn_arr_size(a) != 1) {
		printf("Expected dynamic array to have a dyn_arr_size of 1 after calling dyn_arr_add(1), dyn_arr_add(2), and dyn_arr_remove(1)\n");
        success = false;
    }
    dyn_arr_remove(a, 2);
    if (dyn_arr_contains(a, 2)) {
        printf("Expected dynamic array to not contain 1 after calling dyn_arr_add(1), dyn_arr_add(2), dyn_arr_remove(1), and dyn_arr_remove(2)\n");
        success = false;
    }
    if (dyn_arr_size(a) != 0) {
		printf("Expected dynamic array to have a dyn_arr_size of 1 after calling dyn_arr_add(1), dyn_arr_add(2), dyn_arr_remove(1), and dyn_arr_remove(2)\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}

void test_dyn_arr_remove_many() {
    printf("\ntest_dyn_arr_remove_many\n");
    bool success = true;

    dyn_arr *a = new_dyn_arr();
    for (int i=0; i<100; i++) {
        dyn_arr_add(a, i);
    }
    for (int i=0; i<100; i++) {
        dyn_arr_remove(a, i);
    }
    for (int i=0; i<100; i++) {
        if (dyn_arr_contains(a, i)) {
            printf("Expected dynamic array to not contain %d after calling dyn_arr_add(%d) and dyn_arr_remove(%d)\n", i, i, i);
            success = false;
            break;
        }
    }
    if (dyn_arr_size(a) != 0) {
		printf("Expected dynamic array to have a dyn_arr_size of 0 after calling dyn_arr_add and dyn_arr_remove 100 times\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}

void test_dyn_arr_remove_non_existent() {
    printf("\ntest_dyn_arr_remove_non_existent\n");
    bool success = true;

    dyn_arr *a = new_dyn_arr();
    dyn_arr_remove(a, 1);
    if (dyn_arr_contains(a, 1)) {
        printf("Expected dynamic array to not contain 1 after calling dyn_arr_remove(1) on an empty dynamic array\n");
        success = false;
    }
    dyn_arr_add(a, 1);
    dyn_arr_remove(a, 2);
    if (dyn_arr_contains(a, 2)) {
        printf("Expected dynamic array to not contain 2 after calling dyn_arr_remove(1), dyn_arr_add(1), and dyn_arr_remove(2) on an empty dynamic array\n");
        success = false;
    }
    if (dyn_arr_size(a) != 1) {
		printf("Expected dynamic array to have a dyn_arr_size of 1 after calling dyn_arr_remove(1), dyn_arr_add(1), and dyn_arr_remove(2) on an empty dynamic array\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}

void test_dyn_arr_remove_duplicates() {
    printf("\ntest_dyn_arr_remove_duplicates\n");
    bool success = true;

    dyn_arr *a = new_dyn_arr();
    dyn_arr_add(a, 1);
    dyn_arr_add(a, 1);
    dyn_arr_remove(a, 1);
    if (!dyn_arr_contains(a, 1)) {
        printf("Expected dynamic array to contain 1 after calling dyn_arr_add(1) twice and dyn_arr_remove(1) once\n");
        success = false;
    }
    if (dyn_arr_size(a) != 1) {
		printf("Expected dynamic array to have a dyn_arr_size of 1 after calling dyn_arr_add(1) twice and dyn_arr_remove(1) once\n");
        success = false;
    }
    dyn_arr_remove(a, 1);
    if (dyn_arr_contains(a, 1)) {
        printf("Expected dynamic array to not contain 1 after calling dyn_arr_add(1) twice and dyn_arr_remove(1) twice\n");
        success = false;
    }
    if (dyn_arr_size(a) != 0) {
		printf("Expected dynamic array to have a dyn_arr_size of 0 after calling dyn_arr_add(1) twice and dyn_arr_remove(1) twice\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
    free_dyn_arr(a);
}
