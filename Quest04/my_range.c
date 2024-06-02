#include <stdio.h>
#include <stdlib.h>
int* my_range(int min, int max) {
    // Check if min is greater or equal to max
    if (min >= max) {
        return NULL; // Return null pointer
    }

    // Calculate the size of the array
    int size = max - min;

    // Allocate memory for the array
    int* arr = (int*)malloc(size * sizeof(int));
    if (arr == NULL) {
        // Allocation failed, return null pointer
        return NULL;
    }

    // Populate the array with values from min to max - 1
    for (int i = 0; i < size; i++) {
        arr[i] = min + i;
    }

    return arr; // Return the pointer to the array
}

int Cal_culation() {
    int min = 5;
    int max = 10;

    int* result = my_range(min, max);
    if (result == NULL) {
        printf("Error: min value is greater or equal to max's value.\n");
    } else {
        printf("Generated array: ");
        for (int i = 0; i < max - min; i++) {
            printf("%d ", result[i]);
        }
        printf("\n");

        // Don't forget to free the allocated memory
        free(result);
    }

    return 0;
}




// https://www.phind.com/search?cache=lfqtjjlms3h7fss5q70t8id7    THIS IS FOR NGRAM