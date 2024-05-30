#include <stdio.h>
#include <string.h>


int my_strlen(const char *str) {
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
}

int string() {
    const char *str = "Hello, world!";
    int length = my_strlen(str);

    return length;
}