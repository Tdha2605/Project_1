#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct Node
{
    char data[51];
    struct Node *next_Node;
};

struct Node *table[TABLE_SIZE];

int hash(char *key)
{
    int sum = 0;
    for (int i = 0; i < strlen(key); i++)
    {
        sum += key[i];
    }
    return sum % TABLE_SIZE;
}

int find(char *data)
{
    int index = hash(data);
    struct Node *current = table[index];
    while (current != NULL)
    {
        if (strcmp(current->data, data) == 0)
        {
            return 1;
        }
        current = current->next_Node;
    }
    return 0;
}

int insert(char *data)
{
    if (find(data))
    {
        return 0;
    }
    int index = hash(data);
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    strcpy(new_node->data, data);
    new_node->next_Node = table[index];
    table[index] = new_node;
    return 1;
}

int main()
{
    char do_what[20], data[51];
    while (scanf("%s", data) == 1 && strcmp(data, "*") != 0)
    {
        insert(data);
    }
    while (scanf("%s%s", do_what, data) == 2 && strcmp(do_what, "***") != 0)
    {
        if (strcmp(do_what, "find") == 0)
        {
            printf("%d\n", find(data));
        }
        else if (strcmp(do_what, "insert") == 0)
        {
            printf("%d\n", insert(data));
        }
    }
    return 0;
}
