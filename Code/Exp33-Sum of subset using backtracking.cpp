#include <stdio.h>

#define MAX 20

int subset[MAX]; // Array to store the current subset

// Backtracking function to find subsets that sum to the target
void sumOfSubsets(int arr[], int n, int target, int index, int currentSum) {
    // If the current sum matches the target, print the subset
    if (currentSum == target) {
        printf("{ ");
        for (int i = 0; i < index; i++) {
            printf("%d ", subset[i]);
        }
        printf("}\n");
        return;
    }

    // If the current sum exceeds the target or there are no more elements, return
    if (currentSum > target || n == 0) {
        return;
    }

    // Include the first element in the subset
    subset[index] = arr[0];
    sumOfSubsets(arr + 1, n - 1, target, index + 1, currentSum + arr[0]);

    // Exclude the first element from the subset and move to the next element
    sumOfSubsets(arr + 1, n - 1, target, index, currentSum);
}

int main() {
    int n, target;

    // Input the number of elements in the set
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    int arr[MAX];

    // Input the elements of the set
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input the target sum
    printf("Enter the target sum: ");
    scanf("%d", &target);

    // Find subsets with the target sum
    printf("Subsets with sum %d are:\n", target);
    sumOfSubsets(arr, n, target, 0, 0);

    return 0;
}

