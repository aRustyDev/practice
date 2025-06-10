#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidInput(char target) {
    char validInput[] = {' ', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '+', '-', '*', '/', '(', ')', '^', 's', 'q', 'r', 't'};
    for (int i = 0; i < sizeof(validInput); i++) {
        if (validInput[i] == target) {
            return true; // Or return i for the index
        }
    }
    return false; // Or return -1 if not found
}

int main() {
    char *buffer;
    int size = 10;
    int length = 0;
    char c;

    buffer = malloc(size * sizeof(char));
    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Allowed Operators [+, -, *, /, '()', ^, sqrt]");
    printf("Enter equation: ");
    while ((c = getchar()) != '\n' && c != EOF) {
        buffer[length++] = c;
        if (!isValidInput(c)) {
            printf("Invalid input: %c\n", c);
            return 1;
        }
        if (length >= size) {
            size *= 2;
            buffer = realloc(buffer, size * sizeof(char));
            if (buffer == NULL) {
                printf("Memory reallocation failed.\n");
                return 1;
            }
        }
    }
    buffer[length] = '\0';
    // while (1 == 1) {

    // }


    free(buffer);
    return 0;
}
