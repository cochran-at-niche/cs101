#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#include "map.h"

int main() {
    // Initialize a new map
    map* m = new_map();

    // Add some key-value pairs to it
    map_add(m, "key1", 1);
    map_add(m, "key2", 2);
    map_add(m, "key3", 3);


    int val1 = map_get(m, "key1");
    printf("key1: %d\n", val1);

    int val2 = map_get(m, "key2");
    printf("key2: %d\n", val2);

    int val3 = map_get(m, "key3");
    printf("key3: %d\n", val3);

    int invalid = map_get(m, "invalid");
    printf("invalid: %d\n", invalid);
}
