#include <stdio.h>

int my_string_index(const char *haystack, char needle) {
    int index = 0;

    // Iterate over the characters of the string until we encounter '\0'
    while (*haystack != '\0') {
        if (*haystack == needle) {
            return index; // Return the position if the character matches
        }
        index++;
        haystack++; // Move the pointer to the next character
    }

    return -1; // Return -1 if the character is not found
}

int string() {
    const char *haystack = "hello";
    char needle = 'l';

    int position = my_string_index(haystack, needle);
    if (position != -1) {
        printf("The character '%c' is found at position %d in the string '%s'.\n", needle, position, haystack);
    } else {
        printf("The character '%c' is not found in the string '%s'.\n", needle, haystack);
    }

    return 0;
}