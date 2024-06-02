#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

char* my_join(string_array* param_1, char* param_2) {
    if (param_1 == NULL || param_1->array == NULL || param_2 == NULL) {
        return NULL; // Handle invalid input
    }

    // Calculate the total length of the joined string
    int total_length = 0;
    for (int i = 0; i < param_1->size; i++) {
        total_length += strlen(param_1->array[i]);
    }

    // Add space for separators
    total_length += (param_1->size - 1) * strlen(param_2);

    // Allocate memory for the joined string
    char* result = (char*)malloc((total_length + 1) * sizeof(char)); // +1 for null terminator
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    // Concatenate the strings with separators
    result[0] = '\0'; // Initialize result as an empty string
    for (int i = 0; i < param_1->size; i++) {
        strcat(result, param_1->array[i]); // Append current string
        if (i < param_1->size - 1) {
            strcat(result, param_2); // Append separator if not the last string
        }
    }

    return result; // Return the pointer to the joined string
}

int Run() {
    // Example usage
    string_array input;
    input.size = 3;
    input.array = (char**)malloc(input.size * sizeof(char*));
    input.array[0] = "apple";
    input.array[1] = "banana";
    input.array[2] = "orange";

    char* separator = ", ";
    char* result = my_join(&input, separator);
    if (result == NULL) {
        printf("Error: Memory allocation failed or invalid input.\n");
        return 1;
    }

    printf("Joined string: %s\n", result);

    // Don't forget to free the allocated memory
    free(result);
    free(input.array);

    return 0;
}
