#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Tree
{
    int id;
    struct Tree **children;
    int num_children;
};

struct Tree *makeRoot(int u)
{
    struct Tree *root = (struct Tree *)malloc(sizeof(struct Tree));
    root->id = u;
    root->num_children = 0;
    return root;
}

void insert(struct Tree *root, int u, int v)
{
    if (root == NULL)
    {
        return;
    }
    if (root->id == v)
    {
        if (root->num_children == 0)
        {
            root->children = (struct Tree **)malloc(sizeof(struct Tree *));
        }
        else
        {
            root->children = (struct Tree **)realloc(root->children,
                                                     (root->num_children + 1) * sizeof(struct Tree *));
        }
        root->children[root->num_children] = makeRoot(u);
        root->num_children++;
        return;
    }
    for (int i = 0; i < root->num_children; i++)
    {
        insert(root->children[i], u, v);
        if (root->children[i]->id == v)
        {
            break;
        }
    }
}

void inorder(struct Tree *root)
{
    if (root == NULL)
        return;

    if (root->num_children > 0)
    {
        inorder(root->children[0]);
    }

    printf("%d ", root->id);

    for (int i = 1; i < root->num_children; i++)
    {
        inorder(root->children[i]);
    }
}

void preorder(struct Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    printf("%d ", root->id);
    for (int i = 0; i < root->num_children; i++)
    {
        preorder(root->children[i]);
    }
}

void postorder(struct Tree *root)
{
    if (root == NULL)
    {
        return;
    }
    for (int i = 0; i < root->num_children; i++)
    {
        postorder(root->children[i]);
    }
    printf("%d ", root->id);
}

void print_children(struct Tree *Tree, int v)
{
    if (Tree->id == v)
    {
        for (int i = 0; i < Tree->num_children; i++)
        {
            printf("%d ", Tree->children[i]->id);
        }
        return;
    }
    for (int i = 0; i < Tree->num_children; i++)
    {
        print_children(Tree->children[i], v);
    }
}

int main()
{
    struct Tree *root = NULL;

    char do_what[15];
    int u, v;

    while (1)
    {
        scanf("%s", do_what);

        if (do_what[0] == '*')
        {
            break;
        }

        if (strcmp(do_what, "MakeRoot") == 0)
        {
            scanf("%d", &u);
            root = makeRoot(u);
        }
        else if (strcmp(do_what, "Insert") == 0)
        {
            scanf("%d %d", &u, &v);
            insert(root, u, v);
        }
        else if (strcmp(do_what, "PreOrder") == 0)
        {
            preorder(root);
            printf("\n");
        }
        else if (strcmp(do_what, "InOrder") == 0)
        {
            inorder(root);
            printf("\n");
        }
        else if (strcmp(do_what, "PostOrder") == 0)
        {
            postorder(root);
            printf("\n");
        }
    }

    return 0;
}
