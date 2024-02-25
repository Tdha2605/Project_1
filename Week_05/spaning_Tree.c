#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int start, end, weight;
} Edge;

int compare(const void *a, const void *b)
{
    return ((Edge *)a)->weight - ((Edge *)b)->weight;
}

int arr[100000];

int find(int x)
{
    if (arr[x] == x)
    {
        return x;
    }
    return arr[x] = find(arr[x]);
}

void union_set(int x, int y)
{
    arr[find(x)] = find(y);
}

int kruskal(Edge *edge, int M)
{
    qsort(edge, M, sizeof(Edge), compare);
    int total_weight = 0;
    for (int i = 0; i < M; i++)
    {
        if (find(edge[i].start) != find(edge[i].end))
        {
            total_weight += edge[i].weight;
            union_set(edge[i].start, edge[i].end);
        }
    }
    return total_weight;
}

int main()
{
    int N, M;
    scanf("%d%d", &N, &M);
    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;
    }
    Edge *edge = (Edge *)malloc(M * sizeof(Edge));
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &edge[i].start, &edge[i].end, &edge[i].weight);
    }
    printf("%d\n", kruskal(edge, M));
    // free(edge);
    return 0;
}
