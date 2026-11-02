#include <stdio.h>

int main() {

    int n, graph[20][20], indegree[20] = {0};
    int queue[20], front = 0, rear = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n; j++) {

            scanf("%d", &graph[i][j]);

            if (graph[i][j])
                indegree[j]++;
        }
    }

    for (int i = 0; i < n; i++)
        if (indegree[i] == 0)
            queue[rear++] = i;

    printf("Topological order: ");

    int count = 0;

    while (front < rear) {

        int v = queue[front++];

        printf("%d ", v);
        count++;

        for (int i = 0; i < n; i++) {

            if (graph[v][i]) {

                indegree[i]--;

                if (indegree[i] == 0)
                    queue[rear++] = i;
            }
        }
    }

    if (count != n)
        printf("\nCycle exists. Topological sort not possible.");

    printf("\n");

    return 0;
}