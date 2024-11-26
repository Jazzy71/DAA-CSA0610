#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef struct {
    int src, dest, weight;
} Edge;
typedef struct {
    int parent[MAX], rank[MAX];
} DisjointSet;
void initSet(DisjointSet *set, int n) {
    for (int i = 0; i < n; i++) {
        set->parent[i] = i;
        set->rank[i] = 0;
    }
}
int find(DisjointSet *set, int v) {
    if (set->parent[v] != v)
        set->parent[v] = find(set, set->parent[v]);
    return set->parent[v];
}
void unionSet(DisjointSet *set, int u, int v) {
    int rootU = find(set, u);
    int rootV = find(set, v);
    if (rootU != rootV) {
        if (set->rank[rootU] < set->rank[rootV])
            set->parent[rootU] = rootV;
        else if (set->rank[rootU] > set->rank[rootV])
            set->parent[rootV] = rootU;
        else {
            set->parent[rootV] = rootU;
            set->rank[rootU]++;
        }
    }
}
int cmpEdges(const void *a, const void *b) {
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}
void kruskalMST(Edge edges[], int n, int e) {
    qsort(edges, e, sizeof(Edge), cmpEdges);
    DisjointSet set;
    initSet(&set, n);
    int mstWeight = 0;
    printf("Edges in the MST:\n");
    for (int i = 0; i < e; i++) {
        if (find(&set, edges[i].src) != find(&set, edges[i].dest)) {
            printf("(%d, %d) -> %d\n", edges[i].src, edges[i].dest, edges[i].weight);
            mstWeight += edges[i].weight;
            unionSet(&set, edges[i].src, edges[i].dest);
        }
    }
    printf("Total weight of MST: %d\n", mstWeight);
}
int main() {
    int n = 4;  
    int e = 5; 
    Edge edges[] = {
        {0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
    };
    kruskalMST(edges, n, e);
    return 0;
}
