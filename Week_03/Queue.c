#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue(int value)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = value;
    new_node->next = NULL;

    if (front == NULL && rear == NULL)
    {
        front = rear = new_node;
        return;
    }
    rear->next = new_node;
    rear = new_node;
}

void dequeue()
{
    struct node *temp = front;
 
    if (front == NULL)
    {
        printf("NULL\n");
        return;
    }
    printf("%d\n", front->data);
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
    }
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
            enqueue(value);
        }
        else if (strcmp(do_what, "POP") == 0)
        {
            
            dequeue();
        }
    }
    return 0;
}
