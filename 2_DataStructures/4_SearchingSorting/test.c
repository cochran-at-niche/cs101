#include <string.h>
#include <stdio.h>
#include <time.h>

#include "test.h"

const int MAX_INT = 1000;

int main() {
    test_dyn_arr_sort_random();
    test_dyn_arr_sort_in_order();
    test_dyn_arr_sort_reverse_order();
}

int comp (const void* elem1, const void* elem2) 
{
    int a = *((int*)elem1);
    int b = *((int*)elem2);
    if (a > b) {
        return  1;
    } else if (a < b) {
        return -1;
    } else {
        return 0;
    }
}

void print_array(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

void test_dyn_arr_sort_in_order() {
    printf("\ntest_dyn_arr_sort_in_order\n");
    int sizes[] = {0, 1, 2, 5, 10, 50, 100};

    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {
        int size = sizes[i];
        printf("\nSorting in-order array of length %d:\n", size);

        dyn_arr *a = new_dyn_arr();
        int oracle[size];
        for (int j = 0; j < size; j++) {
            dyn_arr_add(a, j);
            oracle[j] = j;
        }

        qsort(oracle, size, sizeof(int), comp);
        dyn_arr_sort(a);

        if (memcmp(a->array, oracle, sizeof(int)) != 0) {
            printf("Expected: ");
            print_array(oracle, size);
            printf("Actual: ");
            print_array(a->array, a->size);
        } else {
            printf("Success\n");
        }

        free_dyn_arr(a);
    }
}

void test_dyn_arr_sort_reverse_order() {
    printf("\ntest_dyn_arr_sort_in_order\n");
    int sizes[] = {0, 1, 2, 5, 10, 50, 100};

    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {
        int size = sizes[i];
        printf("\nSorting reverse-order array of length %d:\n", size);

        dyn_arr *a = new_dyn_arr();
        int oracle[size];
        for (int j = size-1; j >= 0; j--) {
            dyn_arr_add(a, j);
            oracle[j] = j;
        }

        qsort(oracle, size, sizeof(int), comp);
        dyn_arr_sort(a);

        if (memcmp(a->array, oracle, sizeof(int)) != 0) {
            printf("Expected: ");
            print_array(oracle, size);
            printf("Actual: ");
            print_array(a->array, a->size);
        } else {
            printf("Success\n");
        }

        free_dyn_arr(a);
    }
}

void test_dyn_arr_sort_random() {
    printf("\ntest_dyn_arr_sort\n");
    int sizes[] = {0, 1, 2, 5, 10, 50, 100};

    srand(time(0));
    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {
        int size = sizes[i];
        printf("\nSorting random array of length %d:\n", size);

        dyn_arr *a = new_dyn_arr();
        int oracle[size];
        for (int j = 0; j < size; j++) {
            int num = rand() % MAX_INT;
            dyn_arr_add(a, num);
            oracle[j] = num;
        }

        dyn_arr_sort(a);
        qsort(oracle, size, sizeof(int), comp);

        if (memcmp(a->array, oracle, sizeof(int)) != 0) {
            printf("Expected: ");
            print_array(oracle, size);
            printf("Actual: ");
            print_array(a->array, a->size);
        } else {
            printf("Success\n");
        }

        free_dyn_arr(a);
    }
}

