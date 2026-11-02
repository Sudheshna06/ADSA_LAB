#include <stdio.h>

#define INF 99999

int n;
int cost[20][20];
int visited[20];
int minCost = INF;

void tsp(int city, int count, int total) {

    if (count == n) {

        if (cost[city][0] != INF) {

            int tourCost = total + cost[city][0];

            if (tourCost < minCost)
                minCost = tourCost;
        }

        return;
    }

    for (int i = 0; i < n; i++) {

        if (!visited[i] && cost[city][i] != INF) {

            visited[i] = 1;

            tsp(i, count + 1,
                total + cost[city][i]);

            visited[i] = 0;
        }
    }
}

int main() {

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    visited[0] = 1;

    tsp(0, 1, 0);

    printf("Minimum TSP cost = %d\n", minCost);

    return 0;
}