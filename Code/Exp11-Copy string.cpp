#include <stdio.h>

// Recursive function to copy one string to another
void copyString(char source[], char destination[], int index) {
    // Base case: when the end of the source string is reached
    if (source[index] == '\0') {
        destination[index] = '\0';  // Add null terminator to the destination string
        return;
    }

    // Copy the current character from source to destination
    destination[index] = source[index];

    // Recursive call to copy the next character
    copyString(source, destination, index + 1);
}

int main() {
    char source[100], destination[100];

    // Input the source string
    printf("Enter a string: ");
    scanf("%s", source);

    // Copy the string using recursion
    copyString(source, destination, 0);

    // Output the copied string
    printf("Source String: %s\n", source);
    printf("Destination String: %s\n", destination);

    return 0;
}

