#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "dynamic_array.h"

const int RUNS = 100;
const int MAX_INT = 1000;

int main() {
    int sizes[] = {100, 1000, 10000, 100000, 1000000};

    srand(time(0));
    for (int i = 0; i < sizeof(sizes) / sizeof(int); i++) {
        int size = sizes[i];
        printf("\nSorting random array of length %d:\n", size);

        double total1, total2;
        for (int j = 0; j < RUNS; j++) {
            dyn_arr *a1 = new_dyn_arr();
            dyn_arr *a2 = new_dyn_arr();
            for (int j = 0; j < size; j++) {
                int num = rand() % MAX_INT;
                dyn_arr_add(a1, num);
                dyn_arr_add(a2, num);
            }

            clock_t start = clock();
            dyn_arr_insertion_sort(a1);
            clock_t end = clock();
            total1 += (end - start);

            start = clock();
            dyn_arr_sort(a2);
            end = clock();
            total2 += (end - start);

            free_dyn_arr(a1);
            free_dyn_arr(a2);
        }

        double avg1 = (total1 / CLOCKS_PER_SEC) / RUNS;
        double avg2 = (total2 / CLOCKS_PER_SEC) / RUNS;

        printf("Insertion sort: %fs\n", avg1);
        printf("Custom sort: %fs\n", avg2);
    }
}

