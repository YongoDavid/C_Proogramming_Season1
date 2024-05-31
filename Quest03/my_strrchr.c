#include <stdio.h>

char *my_strrchr(const char *str, int c) {
    char *last_occurrence = NULL;

    // Iterate through the string
    while (*str != '\0') {
        // If the current character matches the search character
        if (*str == (char)c) {
            // Update the pointer to the last matching character
            last_occurrence = (char *)str;
        }
        str++; // Move to the next character
    }

    // Check if the search character was found
    if ((char)c == '\0') {
        return (char *)str; // Return pointer to the null terminator if searching for null character
    } else {
        return last_occurrence; // Return pointer to the last matching character
    }
}

int Run() {
    // Example usage:
    const char str[] = "hello, world!";
    int search_char = 'l';

    char *result = my_strrchr(str, search_char);
    if (result != NULL) {
        printf("Last occurrence of '%c' found at position: %ld\n", search_char, result - str);
    } else {
        printf("'%c' not found in the string.\n", search_char);
    }

    return 0;
}