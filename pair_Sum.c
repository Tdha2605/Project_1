#include <stdio.h>

int a[1000001];

void sort(int a[], int n)
{
    for (int i = 0; i < n - 1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            if (a[i] > a[j])
            {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int process(int a[], int n, int m)
{
    int left = 0, right = n - 1;
    int count = 0;
    while (left < right)
    {
        if (a[left] + a[right] == m)
        {
            ++count;
            ++left;
            --right;
        }
        else if (a[left] + a[right] < m)
        {
            ++left;
        }
        else
        {
            --right;
        }
    }
    return count;
}

int main()
{
    int n, M;
    scanf("%d %d", &n, &M);
    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &a[i]);
    }

    sort(a, n);

    printf("%d\n", process(a, n, M));
    return 0;
}
