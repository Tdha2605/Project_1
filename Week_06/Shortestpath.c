#include <stdio.h>
#include <stdlib.h>

void print(int **dist, int V)
{
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            printf("%d ", dist[i][j]);
        }
        printf("\n");
    }
}

void process(int **matranke, int V)
{
    int **dist = (int **)malloc(V * sizeof(int *));

    for (int i = 0; i < V; i++)
        dist[i] = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            dist[i][j] = matranke[i][j];
        }
    }

    for (int k = 0; k < V; k++)
    {
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    print(dist, V);
}

int main()
{
    int V, E;
    scanf("%d %d", &V, &E);

    int **matranke = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++)
        matranke[i] = (int *)malloc(V * sizeof(int));

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                matranke[i][j] = 0;
            else matranke[i][j] = 99999;
        }
    }

    for (int i = 0; i < E; i++)
    {
        int start, end, weight;
        scanf("%d %d %d", &start, &end, &weight);
        matranke[start - 1][end - 1] = weight;
    }

    process(matranke, V);

    return 0;
}
