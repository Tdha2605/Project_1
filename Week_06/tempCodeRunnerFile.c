#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 10000
#define MAX_EDGES 30000
#define INF 99999

typedef struct {
    int node;
    int weight;
} Edge;

typedef struct {
    Edge edges[MAX_EDGES];
    int numEdges;
} GraphNode;

GraphNode graph[MAX_NODES + 1]; // 1-based indexing

typedef struct {
    int node;
    int f; // f = g + h (g: cost from start, h: heuristic estimate to goal)
} AStarNode;

AStarNode createAStarNode(int node, int f) {
    AStarNode n;
    n.node = node;
    n.f = f;
    return n;
}

void aStar(int n, int s, int t) {
    int dist[MAX_NODES + 1];
    bool visited[MAX_NODES + 1] = {false};

    for (int i = 1; i <= n; i++) {
        dist[i] = INF;
    }

    dist[s] = 0;

    AStarNode* openSet = (AStarNode*)malloc((n+1) * sizeof(AStarNode));
    int openSetSize = 0;
    openSet[openSetSize++] = createAStarNode(s, 0);

    while (openSetSize > 0) {
        int u = openSet[0].node;
        int minF = openSet[0].f;
        int minIndex = 0;

        for (int i = 1; i < openSetSize; i++) {
            if (openSet[i].f < minF) {
                u = openSet[i].node;
                minF = openSet[i].f;
                minIndex = i;
            }
        }

        if (u == t) break;

        openSet[minIndex] = openSet[openSetSize-1];
        openSetSize--;

        if (visited[u]) continue;

        visited[u] = true;

        for (int j = 0; j < graph[u].numEdges; j++) {
            int v = graph[u].edges[j].node;
            int w = graph[u].edges[j].weight;

            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                openSet[openSetSize++] = createAStarNode(v, dist[v]);
            }
        }
    }

    free(openSet);

    if (dist[t] == INF) {
        printf("-1\n");
    } else {
        printf("%d\n", dist[t]);
    }
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u].edges[graph[u].numEdges].node = v;
        graph[u].edges[graph[u].numEdges].weight = w;
        graph[u].numEdges++;
    }

    int s, t;
    scanf("%d %d", &s, &t);

    aStar(n, s, t);

    return 0;
}
