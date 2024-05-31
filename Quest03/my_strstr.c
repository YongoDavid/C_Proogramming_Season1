#include <stdio.h>

char *my_strstr(const char *haystack, const char *needle) {
    if (*needle == '\0') {
        return (char *)haystack; // If needle is empty, return haystack
    }

    while (*haystack != '\0') {
        const char *hay_ptr = haystack;
        const char *needle_ptr = needle;

        // Check if needle matches the substring starting from haystack
        while (*needle_ptr != '\0' && *hay_ptr == *needle_ptr) {
            hay_ptr++;
            needle_ptr++;
        }

        // If needle_ptr reached the end, then needle was found
        if (*needle_ptr == '\0') {
            return (char *)haystack;
        }

        // Move to the next character in haystack
        haystack++;
    }

    return NULL; // Needle not found
}

int Run() {
    // Example usage:
    const char haystack[] = "hello, world!";
    const char needle[] = "world";

    char *result = my_strstr(haystack, needle);
    if (result != NULL) {
        printf("Needle found at position: %ld\n", result - haystack);
    } else {
        printf("Needle not found in the haystack.\n");
    }

    return 0;
}