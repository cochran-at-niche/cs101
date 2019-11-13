#include <stdio.h>
#include <stdlib.h>

int main() {
    int b = 17;
    int* a = &b;

    printf("&a: %p\n", &a);
    printf(" a: %p\n", a);
    printf("*a: %d\n", *a);
    printf("&b: %p\n", &b);
    printf(" b: %d\n", b);
}

//int main() {
//    printf("sizeof(int): %lu\n",
//        sizeof(int)
//    );
//    printf("sizeof(int*): %lu\n",
//        sizeof(int*)
//    );
//}


//int* get_int_ptr() {
//    int b = 17;
//    return &b;
//}
//
//int main() {
//    int* a = get_int_ptr();
//    printf("*a: %d\n", *a);
//}

//int* get_int_ptr() {
//    int *b = malloc(sizeof(int));
//    *b = 17;
//    return b;
//}
//
//int main() {
//    int* a = get_int_ptr();
//    printf("*a: %d\n", *a);
//    free(a);
//}

//typedef struct{
//    int i;
//    int* j;
//} my_struct;
//
//int main() {
//    printf("sizeof(int[3]): %lu\n",
//        sizeof(int[3])
//    );
//    printf("sizeof(my_struct): %lu\n",
//        sizeof(my_struct)
//    );
//    printf("sizeof(my_struct*): %lu\n",
//        sizeof(my_struct*)
//    );
//}

//int main() {
//    int j[2] = {1, 2};
//    int k[3] = {1, 2, 3};
//    j[2] = 4; // Out of bounds!
//
//    for (int i=0; i < 3; i++) {
//        printf("k[%d]: %d\n", i, k[i]);
//    }
//}

//int main() {
//    int j[3];
//    int* k = malloc(sizeof(int) * 3);
//
//    // Subscript iteration
//    for (int i=0; i<3; i++) {
//        j[i] = i;
//        k[i] = i;
//    }
//
//    // Pointer arithmetic iteration
//    for (int* i=j; i < j+3; i++) {
//        printf("%p: %d\n", i, *i);
//    }
//    printf("\n");
//
//    for (int* i=k; i < k+3; i++) {
//        printf("%p: %d\n", i, *i);
//    }
//    printf("\n");
//}










