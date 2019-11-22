#include "test.h"

int main() {
    test_new_linked_list();
}

void test_new_linked_list() {
    printf("\ntest_new_linked_list\n");
    bool success = true;

    linked_list* a = new_linked_list();
    if (linked_list_contains(a, 1)) {
        printf("Expected newly initialized linked list to not contain 1\n");
        success = false;
    }
    if (linked_list_size(a) != 0) {
		printf("Expected newly initialized linked list to have a size of 0\n");
        success = false;
    }

    if (success) {
        printf("Success\n");
    }
}
