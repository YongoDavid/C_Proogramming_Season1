#include <stdio.h>

void my_swap(int *a, int *b) {
    *a ^= *b;
    *b ^= *a;
    *a ^= *b;
}

int swap() {
    int a = 10;
    int b = 20;

    printf("Before swapping:\n");
    printf("a = %d, b = %d\n", a, b);

    my_swap(&a, &b); // Pass the addresses of a and b to the swap function

    printf("After swapping:\n");
    printf("a = %d, b = %d\n", a, b);

    return 0;
}