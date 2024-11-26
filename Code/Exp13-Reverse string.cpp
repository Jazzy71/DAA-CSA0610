#include <stdio.h>

// Recursive function to print a string in reverse
void reverseString(char str[], int index) {
    // Base case: When the end of the string is reached
    if (str[index] == '\0') {
        return;
    }

    // Recursive call to process the next character
    reverseString(str, index + 1);

    // Print the current character after the recursive call
    printf("%c", str[index]);
}

int main() {
    char str[100];

    // Input the string
    printf("Enter a string: ");
    scanf("%s", str);

    // Print the reversed string
    printf("Reversed string: ");
    reverseString(str, 0);
    printf("\n");

    return 0;
}

