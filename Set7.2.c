#include <stdio.h>

typedef struct {
    char id;
    int deadline;
    int profit;
} Job;

int main() {

    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job job[n];

    for (int i = 0; i < n; i++) {

        printf("Enter job id, deadline and profit: ");
        scanf(" %c %d %d",
              &job[i].id,
              &job[i].deadline,
              &job[i].profit);
    }

    // Sort by profit
    for (int i = 0; i < n - 1; i++) {

        for (int j = i + 1; j < n; j++) {

            if (job[i].profit < job[j].profit) {

                Job temp = job[i];
                job[i] = job[j];
                job[j] = temp;
            }
        }
    }

    int slot[n + 1];

    for (int i = 0; i <= n; i++)
        slot[i] = -1;

    int profit = 0;

    for (int i = 0; i < n; i++) {

        for (int j = job[i].deadline; j >= 1; j--) {

            if (slot[j] == -1) {

                slot[j] = i;
                profit += job[i].profit;
                break;
            }
        }
    }

    printf("Job sequence: ");

    for (int i = 1; i <= n; i++) {

        if (slot[i] != -1)
            printf("%c ", job[slot[i]].id);
    }

    printf("\nMaximum profit = %d\n", profit);

    return 0;
}