#include <stdio.h>

int n, m;
int graph[20][20];
int selected[20];

int isClique(int count) {

    for (int i = 0; i < count; i++) {

        for (int j = i + 1; j < count; j++) {

            if (!graph[selected[i]][selected[j]])
                return 0;
        }
    }

    return 1;
}

int findClique(int v, int count) {

    if (count == m)
        return isClique(count);

    if (v == n)
        return 0;

    selected[count] = v;

    if (findClique(v + 1, count + 1))
        return 1;

    if (findClique(v + 1, count))
        return 1;

    return 0;
}

int main() {

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter clique size: ");
    scanf("%d", &m);

    if (findClique(0, 0))
        printf("Clique of size %d exists\n", m);
    else
        printf("Clique does not exist\n");

    return 0;
}