#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void replace_Text(char *s, char *p1, char *p2)
{
    char buffer[MAX_LEN] = {0};
    char *pos;

    while ((pos = strstr(s, p1)) != NULL) // kiểm tra xem trong chuỗi s có chứa chuỗi s1 hay không ?
    {
        strncpy(buffer, s, pos - s);
        buffer[pos - s] = '\0';
        strcat(buffer, p2);
        strcat(buffer, pos + strlen(p1));
        strcpy(s, buffer);
    }
}

int main()
{
    char p1[MAX_LEN], p2[MAX_LEN], t[MAX_LEN];

    printf("Enter P1: ");
    fgets(p1, MAX_LEN, stdin);
    p1[strlen(p1) - 1] = '\0'; 

    printf("Enter P2: ");
    fgets(p2, MAX_LEN, stdin);
    p2[strlen(p2) - 1] = '\0'; 

    printf("Enter T: ");
    fgets(t, MAX_LEN, stdin);
    t[strlen(t) - 1] = '\0'; 

    replace_Text(t, p1, p2);

    printf("%s\n", t);

    return 0;
}
