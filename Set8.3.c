#include <stdio.h>

int main() {

    int n;
    int graph[20][20];
    int color[20];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        color[i] = -1;

    for (int start = 0; start < n; start++) {

        if (color[start] != -1)
            continue;

        int queue[20];
        int front = 0, rear = 0;

        queue[rear++] = start;
        color[start] = 0;

        while (front < rear) {

            int u = queue[front++];

            for (int v = 0; v < n; v++) {

                if (graph[u][v]) {

                    if (color[v] == -1) {

                        color[v] = 1 - color[u];
                        queue[rear++] = v;
                    }

                    else if (color[v] == color[u]) {

                        printf("Graph is NOT bipartite\n");
                        return 0;
                    }
                }
            }
        }
    }

    printf("Graph is bipartite\n");

    return 0;
}