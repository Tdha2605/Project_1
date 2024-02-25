
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct BST_Tree
{
    int data;
    struct BST_Tree *left;
    struct BST_Tree *right;
};

struct BST_Tree *new_Node(int data)
{
    struct BST_Tree *newNode = (struct BST_Tree *)malloc(sizeof(struct BST_Tree));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert_Value(struct BST_Tree **root, int Value)
{
    if (*root == NULL)
    {
        *root = new_Node(Value);
        return;
    }
    if (Value < (*root)->data)
    {
        insert_Value(&(*root)->left, Value);
    }
    else if (Value > (*root)->data)
    {
        insert_Value(&(*root)->right, Value);
    }
}

void preOrder(struct BST_Tree *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    struct BST_Tree *root = NULL;
    char do_what[15];
    int Value;
    while (1)
    {
        scanf("%s", do_what);
        if (do_what[0] == '#')
        {
            break;
        }
        
        if (   do_what[0] == 'i' && do_what[1] == 'n' 
            && do_what[2] == 's' && do_what[3] == 'e'
            && do_what[4] == 'r' && do_what[5] == 't')
        {
            scanf("%d", &Value);
            insert_Value(&root, Value);
        }
    }

    preOrder(root);
    return 0;
}
