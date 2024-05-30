#include <stdio.h>

void my_string_formatting(const char *firstname, const char *lastname, int age) {
    printf("Hello, my name is %s %s, I'm %d.\n", firstname, lastname, age);
}

int string() {
    const char *firstname = "John";
    const char *lastname = "Doe";
    int age = 30;
    
    my_string_formatting(firstname, lastname, age);
    
    return 0;
}