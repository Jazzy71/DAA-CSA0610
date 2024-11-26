#include <stdio.h>
#include <stdbool.h>

#define MAX_ITEMS 50
#define MAX_CAPACITY 100

// Function to solve the container loader problem
void containerLoader(int weights[], int n, int capacity) {
    int container[MAX_ITEMS] = {0}; // Tracks the weight in each container
    int containerCount = 0;         // Number of containers used

    // Place each item in the first container it fits into
    for (int i = 0; i < n; i++) {
        bool placed = false;

        for (int j = 0; j < containerCount; j++) {
            if (container[j] + weights[i] <= capacity) {
                container[j] += weights[i];
                placed = true;
                break;
            }
        }

        // If the item doesn't fit in any existing container, use a new container
        if (!placed) {
            container[containerCount++] = weights[i];
        }
    }

    // Print the result
    printf("Number of containers used: %d\n", containerCount);
    for (int i = 0; i < containerCount; i++) {
        printf("Container %d: %d weight\n", i + 1, container[i]);
    }
}

int main() {
    int n, capacity;
    int weights[MAX_ITEMS];

    // Input the number of items
    printf("Enter the number of items: ");
    scanf("%d", &n);

    // Input the weights of the items
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &weights[i]);
    }

    // Input the maximum capacity of each container
    printf("Enter the maximum capacity of each container: ");
    scanf("%d", &capacity);

    // Solve the container loader problem
    containerLoader(weights, n, capacity);

    return 0;
}

