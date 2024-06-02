#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to simulate the spaceship's flight path
char* my_spaceship(char* flight_path) {
    // Initial position and orientation of the spaceship
    int x = 0;
    int y = 0;
    char* direction = "up"; // Default orientation in lowercase

    // Iterate through each character in the flight path
    for (int i = 0; i < strlen(flight_path); i++) {
        char move = flight_path[i];

        // Update orientation based on the movement command
        if (move == 'R') {
            // Turn right
            if (strcmp(direction, "up") == 0) {
                direction = "right"; // Facing right after turning right
            } else if (strcmp(direction, "right") == 0) {
                direction = "down"; // Facing down after turning right
            } else if (strcmp(direction, "down") == 0) {
                direction = "left"; // Facing left after turning right
            } else if (strcmp(direction, "left") == 0) {
                direction = "up"; // Facing up after turning right
            }
        } else if (move == 'L') {
            // Turn left
            if (strcmp(direction, "up") == 0) {
                direction = "left"; // Facing left after turning left
            } else if (strcmp(direction, "right") == 0) {
                direction = "up"; // Facing up after turning left
            } else if (strcmp(direction, "down") == 0) {
                direction = "right"; // Facing right after turning left
            } else if (strcmp(direction, "left") == 0) {
                direction = "down"; // Facing down after turning left
            }
        } else if (move == 'A') {
            // Advance
            if (strcmp(direction, "up") == 0) {
                y--; // Move upward
            } else if (strcmp(direction, "right") == 0) {
                x++; // Move to the right
            } else if (strcmp(direction, "down") == 0) {
                y++; // Move downward
            } else if (strcmp(direction, "left") == 0) {
                x--; // Move to the left
            }
        }
    }

    // Create a string to store the result
    char* result = (char*)malloc(100 * sizeof(char)); // Allocate memory for the result string
    sprintf(result, "{x: %d, y: %d, direction: '%s'}", x, y, direction);

    return result;
}

int Run() {
    // Example usage
    char* flight_path = "RRALAA";
    char* result = my_spaceship(flight_path);
    printf("%s\n", result);

    // Don't forget to free the allocated memory
    free(result);

    return 0;
}