#include <stdio.h>

int main() {
    int list[100], n, num, pos;

    // Input the size of the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Input the elements of the list
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &list[i]);
    }

    // Input the number to insert and the position
    printf("Enter the number to insert: ");
    scanf("%d", &num);
    printf("Enter the position to insert (1 to %d): ", n + 1);
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Please run the program again.\n");
        return 1;
    }

    // Shift elements to the right to make space for the new element
    for (int i = n; i >= pos - 1; i--) {
        list[i + 1] = list[i];
    }

    // Insert the new number
    list[pos - 1] = num;

    // Increment the size of the list
    n++;

    // Print the updated list
    printf("Updated list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");

    return 0;
}

