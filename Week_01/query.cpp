#include <stdio.h>
#include <string.h>

int main()
{
    int n, i, j;
    int input[10000];
    char do_what[20];

    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
    }

    while (scanf("%s", do_what) != EOF)
    {
        if (strcmp(do_what, "find-max") == 0)
        {
            int max_val = input[0];
            for (i = 1; i < n; i++)
            {
                if (input[i] > max_val)
                {
                    max_val = input[i];
                }
            }
             printf("%d\n", max_val);
        }
        else if (strcmp(do_what, "find-min") == 0)
        {
            int min_val = input[0];
            for (i = 1; i < n; i++)
            {
                if (input[i] < min_val)
                {
                    min_val = input[i];
                }
            }
             printf("%d\n", min_val);
        }
        else if (strcmp(do_what, "sum") == 0)
        {
            int sum = 0;
            for (i = 0; i < n; i++)
            {
                sum += input[i];
            }
             printf("%d\n", sum);
        }
        else if (strncmp(do_what, "find-max-segment", 16) == 0)
        {
            scanf("%d %d", &i, &j);
            int max_val_subsequence = input[i - 1];
            for (; i <= j; i++)
            {
                if (input[i - 1] > max_val_subsequence)
                {
                    max_val_subsequence = input[i - 1];
                }
            }
            printf("%d\n", max_val_subsequence);
        }
    }

    return 0;
}
