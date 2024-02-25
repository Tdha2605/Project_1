#include <stdio.h>
#include <stdlib.h>

int process(int **matranke, int V, int s, int t)
{
    int *dist = (int *)malloc(V * sizeof(int));
    int *visited = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
    {
        dist[i] = 99999;
        visited[i] = 0;
    }

    dist[s - 1] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = -1;
        int minDist = 99999;
        for (int i = 0; i < V; i++)
        {
            if (!visited[i] && dist[i] < minDist)
            {
                minDist = dist[i];
                u = i;
            }
        }

        if (u == -1 || u == t - 1)
            break;

        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] && matranke[u][v] != 99999 && dist[u] + matranke[u][v] < dist[v])
            {
                dist[v] = dist[u] + matranke[u][v];
            }
        }
    }

    int shortestDistance = dist[t - 1];

    free(dist);
    free(visited);

    return shortestDistance;
}

int main()
{
    int V, E, s, t;
    scanf("%d %d ", &V, &E);

    int **matranke = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
    {
        matranke[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                matranke[i][j] = 0;
            else
                matranke[i][j] = 99999;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        matranke[start - 1][end - 1] = weight;
    }

    scanf(" %d %d", &s, &t);

    int shortestDistance = process(matranke, V, s, t);
    printf("%d", shortestDistance);

    for (int i = 0; i < V; i++)
    {
        free(matranke[i]);
    }
    free(matranke);

    return 0;
}
