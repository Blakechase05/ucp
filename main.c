#include <stdio.h>

int main() {
    // Define the dimensions of the 2D array
    int rows = 3;
    int cols = 4;

    // Declare and initialize a 2D array of chars
    char charArray[rows][cols];

    // Initialize the elements of the array
    // For example, you can use nested loops to assign values
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            charArray[i][j] = 'A';
        }
    }

    // Print the elements of the array
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", charArray[i][j]);
        }
        printf("\n");
    }

    return 0;
}