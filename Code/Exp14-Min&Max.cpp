#include <stdio.h>

// Function to find the minimum and maximum values in a list
void findMinAndMax(int arr[], int size, int *min, int *max) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] < *min) {
            *min = arr[i];
        }
        if (arr[i] > *max) {
            *max = arr[i];
        }
    }
}

int main() {
    int n;

    // Input the number of elements in the list
    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    // Declare the array and input its elements
    int arr[n];
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Variables to store the minimum and maximum values
    int min, max;

    // Call the function to find minimum and maximum
    findMinAndMax(arr, n, &min, &max);

    // Output the results
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);

    return 0;
}

