#include <stdio.h>
#include <stdlib.h>

// Pointers example

void pointers() {
    int b = 17;
    int* a = &b;

    printf("&a: %p\n", &a);
    printf(" a: %p\n", a);
    printf("*a: %d\n", *a);
    printf("&b: %p\n", &b);
    printf(" b: %d\n", b);
}

// Sizeof example

void sizes() {
    printf("sizeof(int): %lu\n",
        sizeof(int)
    );
    printf("sizeof(int*): %lu\n",
        sizeof(int*)
    );
}

// Segmentation fault example

int* get_int_ptr1() {
    int b = 17;
    return &b;
}

void segmentation_fault() {
    int* a = get_int_ptr1();
    printf("*a: %d\n", *a);
}

// Malloc and free example

int* get_int_ptr2() {
    int *b = malloc(sizeof(int));
    *b = 17;
    return b;
}

void malloc_and_free() {
    int* a = get_int_ptr2();
    printf("*a: %d\n", *a);
    free(a);
}

// Structs and arrays example

typedef struct{
    int i;
    int* j;
} my_struct;

void structs_and_arrays() {
    printf("sizeof(int[3]): %lu\n",
        sizeof(int[3])
    );
    printf("sizeof(my_struct): %lu\n",
        sizeof(my_struct)
    );
    printf("sizeof(my_struct*): %lu\n",
        sizeof(my_struct*)
    );
}

// Out of bounds example

void out_of_bounds() {
    int j[2] = {1, 2};
    int k[3] = {1, 2, 3};
    j[2] = 4; // Out of bounds!

    for (int i=0; i < 3; i++) {
        printf("k[%d]: %d\n", i, k[i]);
    }
}

// Pointer arithmetic example

void pointer_arithmetic() {
    int j[3];
    int* k = malloc(sizeof(int) * 3);

    // Subscript iteration
    for (int i=0; i<3; i++) {
        j[i] = i;
        k[i] = i;
    }

    // Pointer arithmetic iteration
    for (int* i=j; i < j+3; i++) {
        printf("%p: %d\n", i, *i);
    }
    printf("\n");

    for (int* i=k; i < k+3; i++) {
        printf("%p: %d\n", i, *i);
    }
    printf("\n");
}

int main() {
    pointers();
    //sizes();
    //segmentation_fault();
    //malloc_and_free();
    //structs_and_arrays();
    //out_of_bounds();
    //pointer_arithmetic();
}
