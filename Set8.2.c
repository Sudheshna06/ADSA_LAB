#include <stdio.h>

int n;
int graph[20][20];
int path[20];

int safe(int v, int pos) {

    if (!graph[path[pos - 1]][v])
        return 0;

    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return 0;

    return 1;
}

int solve(int pos) {

    if (pos == n)
        return graph[path[n - 1]][path[0]];

    for (int v = 1; v < n; v++) {

        if (safe(v, pos)) {

            path[pos] = v;

            if (solve(pos + 1))
                return 1;

            path[pos] = -1;
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

    for (int i = 0; i < n; i++)
        path[i] = -1;

    path[0] = 0;

    if (solve(1)) {

        printf("Hamiltonian cycle exists:\n");

        for (int i = 0; i < n; i++)
            printf("%d ", path[i]);

        printf("%d\n", path[0]);
    }
    else
        printf("Hamiltonian cycle does not exist\n");

    return 0;
}