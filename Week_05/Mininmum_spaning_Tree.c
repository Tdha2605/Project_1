#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int u, v, w;
} Edge;

int parent[1005];

int cmp(const void *a, const void *b)
{
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void union_set(int x, int y)
{
    parent[find(x)] = find(y);
}

int kruskal(Edge *edge, int M)
{
    qsort(edge, M, sizeof(Edge), cmp);
    int total_weight = 0;
    for (int i = 0; i < M; i++)
    {
        if (find(edge[i].u) != find(edge[i].v))
        {
            total_weight += edge[i].w;
            union_set(edge[i].u, edge[i].v);
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
        parent[i] = i;
    }
    Edge *edge = (Edge *)malloc(M * sizeof(Edge));
    for (int i = 0; i < M; i++)
    {
        scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
    }
    printf("%d\n", kruskal(edge, M));
    free(edge);
    return 0;
}
