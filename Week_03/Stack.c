#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *top = NULL;

void push(int x)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = top;
    top = temp;
}

void pop()
{
    struct Node *temp;
    if (top == NULL)
    {
        printf("NULL\n");
        return ;
    }
    printf("%d\n", top->data);
    temp = top;
    top = top->next;
    free(temp);
  
}


int main()
{
    char do_what[15];
    int value;
    while (1)
    {
        scanf("%s", do_what);

        if(do_what[0] == '#') break;

        if(strncmp(do_what, "PUSH", 4) == 0)
        {
            scanf("%d", &value);
            push(value);
        }
        else if (strcmp(do_what, "POP") == 0)
        {
            
            pop();
        }
    }
    return 0;
}
