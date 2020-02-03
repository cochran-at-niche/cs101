#include <stdio.h>
#include <string.h>

int main() {
    char* sentence = "This is my example sentence";
    int hash_table[256] = {0};

    for (int i=0; i<strlen(sentence); i++) {
        hash_table[(int) sentence[i]]++;
    }

    for (int i=0; i<256; i++) {
        if (hash_table[i] > 0) {
            printf("%c: %d\n", i, hash_table[i]);
        }
    }
}
