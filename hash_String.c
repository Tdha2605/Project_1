#include <stdio.h>
#include <string.h>



int main()
{
    int n, m;
    char s[201];
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; ++i)
    {
        scanf("%s", s);
        int k = strlen(s);
        int h = 0;
        for (int j = 0; j < k; ++j)
        {
            h = (h * 256 + s[j]) % m;
        }
        printf("%d\n", h);
    }
    return 0;
}
