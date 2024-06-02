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