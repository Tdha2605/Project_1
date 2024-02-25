#include <stdio.h>

int n, m;
int matranke[1000][1000];
int visitted[1000];

int dfs(int u, int cnt)
{
    visitted[u] = 1;
    if (cnt == n)
    {
        for (int v = 0; v < n; ++v)
        {
            if (matranke[u][v] && v == 0)
            {
                return 1;
            }
        }
        return 0;
    }
    for (int v = 0; v < n; ++v)
    {
        if (matranke[u][v] && !visitted[v])
        {
            if (dfs(v, cnt + 1))
                return 1;
        }
    }
    visitted[u] = 0;
    return 0;
}

int hamilton_Cycle()
{
    for (int i = 0; i < n; ++i)
    {
        visitted[i] = 0;
    }
    for (int i = 0; i < n; ++i)
    {
        if (dfs(i, 1))
        {
            for (int j = 0; j < n; ++j)
            {
                if (!visitted[j])
                {
                    return 0;
                }
            }
            return 1;
        }
    }
    return 0;
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                matranke[i][j] = 0;
            }
        }
        while (m--)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            --u;
            --v;
            matranke[u][v] = matranke[v][u] = 1;
        }
        printf("%d\n", hamilton_Cycle());
    }
    return 0;
}
