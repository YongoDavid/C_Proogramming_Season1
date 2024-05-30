#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* my_upcase(char* param_1) {
    char* ptr = param_1;
    
    // Iterate over each character in the string
    while (*ptr != '\0') {
        // Check if the character is a lowercase letter
        if (*ptr >= 'a' && *ptr <= 'z') {
            // Convert it to uppercase by subtracting the ASCII difference
            *ptr = *ptr - ('a' - 'A');
        }
        ptr++; // Move to the next character
    }
    
    return param_1; // Return the modified string
}

int Case() {
    char str[] = "hello, world!";
    
    printf("Original string: %s\n", str);
    printf("Uppercase string: %s\n", my_upcase(str));
    
    return 0;
}