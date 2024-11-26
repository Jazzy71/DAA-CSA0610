#include <stdio.h>
typedef struct { int weight, value; } Item;
int main() {
    Item items[] = {{2, 3}, {3, 4}, {4, 5}, {5, 6}};
    int n = sizeof(items) / sizeof(items[0]), capacity = 5, totalValue = 0;
    for (int i = 0; i < n && capacity > 0; i++) {
        if (items[i].weight <= capacity) {
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
    }
    printf("Maximum value: %d\n", totalValue);
    return 0;
}
