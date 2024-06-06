#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_ARRAY_SIZE 128

void ArrayCount(int* array, char* my_str){
    int i = 0;
    while (my_str[i] != '\0'){
        if (my_str[i] != '"'){
            array[(unsigned char)my_str[i]]++;
        }
        i++;
    };
};

void Array_Prnt(int* array, int size_of_array){
    int i = 0;

    while (i < size_of_array){
        if (array[i] > 0){
            printf("%c:%d\n", (char)i, array[i]);
        }
        i++;
    };
};

int Run(int ac, char **av){
    int i = 1;
    int array[MAX_ARRAY_SIZE] = {0};
    while (i < ac) {
        ArrayCount(array, av[i]);
        i++;
    }
    Array_Prnt(array, MAX_ARRAY_SIZE);
    return 0;
};