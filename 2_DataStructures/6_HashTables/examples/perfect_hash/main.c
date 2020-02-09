#include <stdio.h>
#include <string.h>

int main() {
    char* sentence = "This is my example sentence";
    int hash_table[256] = {0};

    // Iterate over the letters of the sentence
    for (int i=0; i<strlen(sentence); i++) {
        // Use the identity hash function to find
        // and increment counter in hash table
        hash_table[(int) sentence[i]]++;
    }

    // Print results
    for (int i=0; i<256; i++) {
        if (hash_table[i] > 0) {
            printf("%c: %d\n", i, hash_table[i]);
        }
    }
}
