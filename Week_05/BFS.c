#include <stdio.h>

int n, m;
int visited[10000];
int matranke[10000][10000];
int queue[10000];
int front = 0;
int rear = -1;

void bfs(int node)
{
    visited[node] = 1;
    queue[++rear] = node;

    while (front <= rear)
    {
        int v = queue[front++];
        printf("%d ", v);
        for (int i = 1; i <= n; ++i)
        {
            if (matranke[v][i] && !visited[i])
            {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        matranke[u][v] = matranke[v][u] = 1;
    }
    for (int i = 1; i <= n; ++i)
    {
        if (!visited[i])
        {
            bfs(i);
        }
    }
    return 0;
}
