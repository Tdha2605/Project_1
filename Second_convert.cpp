#include <bits/stdc++.h>
#include<string.h>


int main()
{
    char time[9];
    scanf("%s", time);

    int hh, mm, ss;
    if (sscanf(time, "%d:%d:%d", &hh, &mm, &ss) != 3 || strlen(time) != 8)
    {
        printf("INCORRECT\n");
        return 0;
    }

    if ((hh < 0 || hh > 23) || (mm < 0 || mm > 59) || (ss < 0 || ss > 59))
    {
        printf("INCORRECT\n");
        return 0;
    }

    int total_seconds = hh * 3600 + mm * 60 + ss;
    printf("%d\n", total_seconds);

    return 0;
}
