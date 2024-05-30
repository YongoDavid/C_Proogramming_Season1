#include <stdio.h>

void my_putstr(const char *str) {
    // Iterate over the characters of the string until we encounter '\0'
    while (*str != '\0') {
        putchar(*str); // Print the character
        str++; // Move the pointer to the next character
    }
}

int string() {
    const char *str = "Hello, world!";
    my_putstr(str);
}
