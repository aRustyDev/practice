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

int getNextValue(char *buffer, int *index) {
    int value = 0;
    while (buffer[*index] >= '0' && buffer[*index] <= '9') {
        value = value * 10 + (buffer[*index] - '0');
        (*index)++;
    }
    while (true) {
        switch (buffer[i]) {
            case ' ':
                i++;
                continue;
            case '\t':
                i++;
                break;
            case '\n':
                i++;
                break;
            default:
                printf("Invalid input: %c\n", buffer[i]);
                return 1;
        }
    }
    return value;
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

    printf("Allowed Operators [+, -, *, /, '()', ^, sqrt]\n");
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
    int i = 0;
    int res = 0;
    while (c != '\0') {
        c = buffer[i];
        i++;
        switch (c) {
            case '+':
                res += getNextValue(buffer, &i);
                break;
            case '-':
                res -= getNextValue(buffer, &i);
                break;
            case '*':
                res *= getNextValue(buffer, &i);
                break;
            case '/':
                res /= getNextValue(buffer, &i);
                break;
            // case '(':
            //     res = getNextValue(buffer, &i);
            //     break;
            // case ')':
            //     res = getNextValue(buffer, &i);
            //     break;
            // case '^':
            //     res = pow(res, getNextValue(buffer, &i));
            //     break;
            // case 's':
            //     res = sqrt(res);
            //     break;
            default: // spaces
                continue;
            }

    }


    free(buffer);
    return 0;
}
