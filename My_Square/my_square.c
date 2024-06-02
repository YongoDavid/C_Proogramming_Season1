#include <stdio.h>
#include <stdlib.h>

void my_square(int width, int height) {
    if (width <= 0 || height <= 0) {
        return;
}

for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (i == 0 || i == height - 1) {
                if (j == 0 || j == width - 1) {
                    printf("o");
                } else {
                    printf("-");
                }
            } else {
                if (j == 0 || j == width - 1) {
                    printf("|");
                } else {
                    printf(" ");
                }
            }
        }
printf("\n");

   }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        // printf("Usage: %s <width> <height>\n", argv[0]);
        return 0;
    }

    int width = atoi(argv[1]);
    int height = atoi(argv[2]);

    my_square(width, height);

    return 0;
}