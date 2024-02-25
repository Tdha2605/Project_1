#include <stdio.h>


int process(int a[], int hash_table[], int n, int m)
{
    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        int j = m - a[i];
        if (j >= 0 && hash_table[j])
        {
            ++count;
        }
        hash_table[a[i]] = 1;
    }
    return count;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    static int a[1000001];
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    int hash_table[m];
    for (int i = 0; i < m; ++i)
    {
        hash_table[i] = 0;
    }

    printf("%d\n", process(a, hash_table, n, m));
    return 0;
}
