#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

void my_putstr(char* str) {
    while (*str) {
        putchar(*str);
        str++;
    }
}

void my_print_words_array(string_array* param_1) {
    if (param_1 == NULL || param_1->array == NULL) {
        return; // Handle invalid input
    }

    // Iterate through each word in the array and print it followed by a newline
    for (int i = 0; i < param_1->size; i++) {
        my_putstr(param_1->array[i]);
        putchar('\n');
    }
}

int Run() {
    // Example usage
    string_array words;
    words.size = 3;
    words.array = (char**)malloc(words.size * sizeof(char*));
    words.array[0] = "apple";
    words.array[1] = "banana";
    words.array[2] = "orange";

    my_print_words_array(&words);

    // Don't forget to free the allocated memory
    free(words.array);

    return 0;
}
