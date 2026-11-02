#include <stdio.h>

int n;
int graph[20][20];
int visited[20];
int stack[20], top = -1;

void dfs1(int v) {

    visited[v] = 1;

    for (int i = 0; i < n; i++)
        if (graph[v][i] && !visited[i])
            dfs1(i);

    stack[++top] = v;
}

void dfs2(int v) {

    visited[v] = 1;

    printf("%d ", v);

    for (int i = 0; i < n; i++)
        if (graph[i][v] && !visited[i])
            dfs2(i);
}

int main() {

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs1(i);

    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("Strongly Connected Components:\n");

    while (top >= 0) {

        int v = stack[top--];

        if (!visited[v]) {
            dfs2(v);
            printf("\n");
        }
    }

    return 0;
}