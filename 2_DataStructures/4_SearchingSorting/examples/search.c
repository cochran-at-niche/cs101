#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

const int SIZE = 100; 

bool brute_force(int* arr, int size, int target) {
    for (int i = 0; i<size; i++) {
        if (arr[i] == target) {
            return true;
        }
    }
    return false;
}

bool binary_search(int* arr, int size, int target) {
    int low=0;
    int high=size;

    while (low < high) {
        int mid = (low + high) / 2;
        if (arr[mid] < target) {
            low = mid + 1;
        } else if (arr[mid] > target) {
            high = mid;
        } else {
            return true;
        }
    }

    return false;
}

int comp (const void * elem1, const void * elem2) 
{
    int f = *((int*)elem1);
    int s = *((int*)elem2);
    if (f > s) {
        return  1;
    } else if (f < s) {
        return -1;
    } else {
        return 0;
    }
}

int main() {
    int arr[SIZE];

    srand(time(0));
    for (int i = 0; i<SIZE; i++) {
        arr[i] = rand() % SIZE;
    }

    qsort(arr, SIZE, sizeof(*arr), comp);

    printf("Array:");
    for (int i = 0; i<SIZE; i++) {
        printf(" %d", arr[i]);
    }
    printf("\n");

    printf("Enter an integer to search for:\n");
    int target;
    scanf("%d", &target);

    int j = brute_force(arr, SIZE, target);
    printf("Brute force: %s\n", j ? "true" : "false");

    int k = binary_search(arr, SIZE, target);
    printf("Binary search: %s\n", k ? "true" : "false");
}
