#include <bits/stdc++.h>

int main()
{
    char text[99999] = "";
    char line[999];

    while (fgets(line, sizeof(line), stdin))
    {
        strcat(text, line);
    }

    int count = 0;
    for (char *p = text; *p; p++)
    {
        if (!isspace(*p))
        {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}

