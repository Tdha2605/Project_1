#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node
{
    int x, y, dist;
};

bool visited[901][901];

void BFS(int a, int b, int c)
{
    struct Node queue[100000];
    int front = 0, rear = 0;
    queue[rear++] = (struct Node){0, 0, 0};
    visited[0][0] = true;
    while (front != rear)
    {
        struct Node curr = queue[front++];
        if (curr.x == c || curr.y == c)
        {
            printf("%d\n", curr.dist);
            return;
        }
        if (curr.x != 0 && !visited[0][curr.y])
        {
            visited[0][curr.y] = true;
            queue[rear++] = (struct Node){0, curr.y, curr.dist + 1};
        }
        if (curr.y != 0 && !visited[curr.x][0])
        {
            visited[curr.x][0] = true;
            queue[rear++] = (struct Node){curr.x, 0, curr.dist + 1};
        }
        if (curr.x != a && !visited[a][curr.y])
        {
            visited[a][curr.y] = true;
            queue[rear++] = (struct Node){a, curr.y, curr.dist + 1};
        }
        if (curr.y != b && !visited[curr.x][b])
        {
            visited[curr.x][b] = true;
            queue[rear++] = (struct Node){curr.x, b, curr.dist + 1};
        }
        if (curr.x + curr.y <= b && !visited[0][curr.x + curr.y])
        {
            visited[0][curr.x + curr.y] = true;
            queue[rear++] = (struct Node){0, curr.x + curr.y, curr.dist + 1};
        }
        if (curr.x + curr.y > b && !visited[curr.x + curr.y - b][b])
        {
            visited[curr.x + curr.y - b][b] = true;
            queue[rear++] = (struct Node){curr.x + curr.y - b, b, curr.dist + 1};
        }
        if (curr.x + curr.y <= a && !visited[curr.x + curr.y][0])
        {
            visited[curr.x + curr.y][0] = true;
            queue[rear++] = (struct Node){curr.x + curr.y, 0, curr.dist + 1};
        }
        if (curr.x + curr.y > a && !visited[a][curr.x + curr.y - a])
        {
            visited[a][curr.x + curr.y - a] = true;
            queue[rear++] = (struct Node){a, curr.x + curr.y - a, curr.dist + 1};
        }
    }
    printf("-1\n");
}

int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    BFS(a, b, c);
    return 0;
}
