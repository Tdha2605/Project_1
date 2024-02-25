#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int u, v, capacity;
} Edge;

Edge edges[1000000];
int graph[10000][10000];
int parent[10000];
int N, M, s, t;

int bfs()
{
    memset(parent, -1, sizeof(parent));
    parent[s] = -2;
    int queue[10000];
    int front = 0, rear = 0;
    queue[rear++] = s;

    while (front < rear)
    {
        int u = queue[front++];
        for (int v = 1; v <= N; v++)
        {
            if (parent[v] == -1 && graph[u][v] > 0)
            {
                parent[v] = u;
                if (v == t)
                    return 1;
                queue[rear++] = v;
            }
        }
    }
    return 0;
}

int process()
{
    int maxFlow = 0;
    while (bfs())
    {
        int pathFlow = 99999;
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            pathFlow = (pathFlow < graph[u][v]) ? pathFlow : graph[u][v];
        }
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            graph[u][v] -= pathFlow;
            graph[v][u] += pathFlow;
        }
        maxFlow += pathFlow;
    }
    return maxFlow;
}

int main()
{

    scanf("%d %d", &N, &M);
    scanf("%d %d", &s, &t);

    for (int i = 0; i < M; i++)
    {
        int u, v, capacity;
        scanf("%d %d %d", &u, &v, &capacity);
        edges[i].u = u;
        edges[i].v = v;
        edges[i].capacity = capacity;
        graph[u][v] = capacity;
    }

    int maxFlow = process();
    printf("%d\n", maxFlow);

    return 0;
}
