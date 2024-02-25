#include <stdio.h>

int n, m;
int visited[10000];
int matranke[10000][10000];

void dfs(int node)
{
    visited[node] = 1;
    printf("%d ", node);
    for (int i = 1; i <= n; ++i)
    {
        if (matranke[node][i] && !visited[i])
        {
            dfs(i);
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
            dfs(i);
        }
    }
    return 0;
}
