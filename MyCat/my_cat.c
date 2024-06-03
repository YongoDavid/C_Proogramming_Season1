#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 2) {
        // printf("Usage: %s <file1> <file2> ...\n", argv[0]);
        return 1;
    }

    // Buffer for reading from files
    char buffer[BUFFER_SIZE];

    // Iterate through each file provided as an argument
    for (int i = 1; i < argc; i++) {
        // Open the file for reading
        int file = open(argv[i], O_RDONLY);
        if (file == -1) {
            // printf("Error: Unable to open file '%s'\n", argv[i]);
            continue; // Move to the next file
        }

        // Read and print the contents of the file
        ssize_t bytes_read;
        while ((bytes_read = read(file, buffer, BUFFER_SIZE)) > 0) {
            // Write the buffer to standard output
            ssize_t bytes_written = write(STDOUT_FILENO, buffer, bytes_read);
            if (bytes_written != bytes_read) {
                // printf("Error: Incomplete write\n");
                close(file);
                return 1;
            }
        }

        // Check for read error
        if (bytes_read == -1) {
            // printf("Error: Unable to read from file '%s'\n", argv[i]);
            close(file);
            return 1;
        }

        // Close the file
        close(file);
    }

    return 0;
}