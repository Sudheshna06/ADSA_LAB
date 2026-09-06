#include <stdio.h>

void radixExchangeSort(int a[], int left, int right, int bit) {
    if (left >= right || bit < 0)
        return;

    int i = left;
    int j = right;
    int mask = 1 << bit;

    while (i <= j) {
        while (i <= right && (a[i] & mask) == 0)
            i++;

        while (j >= left && (a[j] & mask) != 0)
            j--;

        if (i < j) {
            int temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }

    radixExchangeSort(a, left, j, bit - 1);
    radixExchangeSort(a, i, right, bit - 1);
}

int main(void) {
    int a[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(a) / sizeof(a[0]);

    // 9 because 802 needs bits 9 down to 0
    radixExchangeSort(a, 0, n - 1, 9);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    return 0;
}