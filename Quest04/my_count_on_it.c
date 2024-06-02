#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definition of the structures
#ifndef STRUCT_STRING_ARRAY
#define STRUCT_STRING_ARRAY
typedef struct s_string_array
{
    int size;
    char** array;
} string_array;
#endif

#ifndef STRUCT_INTEGER_ARRAY
#define STRUCT_INTEGER_ARRAY
typedef struct s_integer_array
{
    int size;
    int* array;
} integer_array;
#endif

integer_array* my_count_on_it(string_array* param_1) {
    if (param_1 == NULL || param_1->array == NULL) {
        return NULL; // Handle invalid input
    }

    // Allocate memory for the integer array
    integer_array* result = (integer_array*)malloc(sizeof(integer_array));
    if (result == NULL) {
        return NULL; // Memory allocation failed
    }

    // Set the size of the integer array
    result->size = param_1->size;

    // Allocate memory for the array inside the integer array
    result->array = (int*)malloc(param_1->size * sizeof(int));
    if (result->array == NULL) {
        free(result); // Free previously allocated memory
        return NULL; // Memory allocation failed
    }

    // Calculate the length of each string and store it in the integer array
    for (int i = 0; i < param_1->size; i++) {
        result->array[i] = strlen(param_1->array[i]);
    }

    return result; // Return the pointer to the integer array
}

int Run() {
    // Example usage
    string_array input;
    input.size = 3;
    input.array = (char**)malloc(input.size * sizeof(char*));
    input.array[0] = "apple";
    input.array[1] = "banana";
    input.array[2] = "orange";

    integer_array* result = my_count_on_it(&input);
    if (result == NULL) {
        printf("Error: Memory allocation failed or invalid input.\n");
        return 1;
    }

    printf("Length of each string:\n");
    for (int i = 0; i < result->size; i++) {
        printf("%d ", result->array[i]);
    }
    printf("\n");

    // Don't forget to free the allocated memory
    free(result->array);
    free(result);

    return 0;
}


