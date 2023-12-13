#include <stdio.h>
#include <string.h>
void replace_Text(char *s, char *p1, char *p2)
{
    char buffer[1000] = {0};
    char *pos;

    while ((pos = strstr(s, p1)) != NULL) // ki?m tra xem trong chu?i s có ch?a chu?i s1 hay không ?
    {
        strncpy(buffer, s, pos - s);
        buffer[pos - s] = '\0';
        strcat(buffer, p2);
        strcat(buffer, pos + strlen(p1));
        strcpy(s, buffer);
    }
}

int main() {
	char P1[1000],P2[1000],T[1000];

	   fgets(P1,1000,stdin);
       P1[strlen(P1)-1] = '\0';

       fgets(P2,1000,stdin);
       P2[strlen(P2)-1] = '\0';
       fgets(T,1000,stdin);
       T[strlen(T)-1] = '\0';
	 replace_Text(T,P1,P2);
	printf("%s",T);
	return 0;
}