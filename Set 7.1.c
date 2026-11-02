#include <stdio.h>

int main() {

    int n, amount;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    int coin[n];

    printf("Enter coins in descending order:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &coin[i]);

    printf("Enter amount: ");
    scanf("%d", &amount);

    printf("Coins used: ");

    for (int i = 0; i < n; i++) {

        while (amount >= coin[i]) {

            printf("%d ", coin[i]);
            amount -= coin[i];
        }
    }

    if (amount != 0)
        printf("\nExact change not possible");

    printf("\n");

    return 0;
}