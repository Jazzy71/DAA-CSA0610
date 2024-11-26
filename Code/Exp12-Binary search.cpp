#include <stdio.h>

int binarySearch(int arr[], int left, int right, int key) {
    
    if (left > right) {
        return -1;  
    }

    int mid = left + (right - left) / 2;

    if (arr[mid] == key) {
        return mid;  
    }

    if (arr[mid] > key) {
        return binarySearch(arr, left, mid - 1, key);
    }

    return binarySearch(arr, mid + 1, right, key);
}

int main() {
    int n, key;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements (sorted): ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search for: ");
    scanf("%d", &key);

    int result = binarySearch(arr, 0, n - 1, key);

    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index %d.\n", result);
    }

    return 0;
}

