#include <stdio.h>

char *my_strncpy(char *dest, const char *src, size_t n) {
    char *original_dest = dest;
    size_t i;

    // Copy at most n characters from src to dest
    for (i = 0; i < n && *src != '\0'; i++) {
        *dest++ = *src++;
    }

    // Fill the remaining space in dest with null characters if necessary
    for (; i < n; i++) {
        *dest++ = '\0';
    }

    return original_dest;
}

int Cpyy() {
    // Example usage:
    char dest[20];
    const char src[] = "Hello, world!";

    printf("Original source string: %s\n", src);
    printf("Copying...\n");
    my_strncpy(dest, src, 5); // Copy first 5 characters
    printf("Copied string: %s\n", dest);

    return 0;
}
