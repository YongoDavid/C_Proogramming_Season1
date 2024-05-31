#include <stdio.h>
#include <string.h>
char* reverse_string(char* str) {
    int begin = 0;
    int end = strlen(str) - 1;

    while (begin < end) {
        char temp = str[begin];
        str[begin] = str[end];
        str[end] = temp;
        begin++;
        end--;
    }
    return str;
}