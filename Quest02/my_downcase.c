#include <stdio.h>
#include <string.h>
#include <ctype.h>

char* my_downcase(char* param_1) {
    char* ptr = param_1;
    
    // Iterate over each character in the string
    while (*ptr != '\0') {
        // Check if the character is a Uppercase letter
        if (*ptr >= 'A' && *ptr <= 'Z') {
            // Convert it to lowercase by subtracting the ASCII difference
            *ptr = *ptr - ('A' - 'a');
        }
        ptr++; // Move to the next character
    }
    
    return param_1; // Return the modified string
}

int Case() {
    char str[] = "hello, world!";
    
    printf("Original string: %s\n", str);
    printf("Uppercase string: %s\n", my_downcase(str));
    
    return 0;
}