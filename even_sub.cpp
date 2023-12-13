#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int input[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }

    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += input[i];
    }

    int even_k_subsequences = (sum % 2 == 0) ? 1 : 0;
    

    for (int i = k; i < n; i++)
    {
        sum = sum - input[i - k] + input[i];
        if (sum % 2 == 0)
        {
            even_k_subsequences++;
        }
    }

    printf("%d\n", even_k_subsequences);
    return 0;
}
