#include <stdio.h>
void findMaxMin(int arr[], int l, int r, int *max, int *min) {
    if (l == r) { *max = *min = arr[l]; return; }
    int mid = (l + r) / 2, max1, min1;
    findMaxMin(arr, l, mid, max, min);
    findMaxMin(arr, mid + 1, r, &max1, &min1);
    if (max1 > *max) *max = max1;
    if (min1 < *min) *min = min1;
}
int main() {
    int arr[] = {3, 1, 4, 1, 5, 9};
    int n = sizeof(arr) / sizeof(arr[0]), max, min;
    findMaxMin(arr, 0, n - 1, &max, &min);
    printf("Max: %d, Min: %d\n", max, min);
    return 0;
}
