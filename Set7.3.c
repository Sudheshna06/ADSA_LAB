#include <stdio.h>

int n, m;
int graph[20][20];
int color[20];

int safe(int v, int c) {

    for (int i = 0; i < n; i++) {

        if (graph[v][i] && color[i] == c)
            return 0;
    }

    return 1;
}

int colorGraph(int v) {

    if (v == n)
        return 1;

    for (int c = 1; c <= m; c++) {

        if (safe(v, c)) {

            color[v] = c;

            if (colorGraph(v + 1))
                return 1;

            color[v] = 0;
        }
    }

    return 0;
}

int main() {

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter number of colors: ");
    scanf("%d", &m);

    if (colorGraph(0)) {

        printf("Coloring possible:\n");

        for (int i = 0; i < n; i++)
            printf("Vertex %d -> Color %d\n",
                   i, color[i]);
    }
    else
        printf("Coloring not possible\n");

    return 0;
}