#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000
#define MAX_LINES 100

int main()
{
    char lines[MAX_LINES][MAX_LINE];
    int i = 0;

    
    while (i < MAX_LINES && fgets(lines[i], MAX_LINE, stdin) != NULL)
    {
        
         lines[i][strcspn(lines[i], "\\n")] = '\\0';

        if (strlen(lines[i]) == 0)
        {
            break;
        }

        i++;
    }
  

    for (int j = 0; j < i; j++)
    {
        printf("%s\\n", lines[j]);
    }

    return 0;
}

