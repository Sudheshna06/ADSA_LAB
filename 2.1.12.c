#include <stdio.h>

void addressCalculationSort(int arr[], int n) {
    int min = arr[0], max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] < min) min = arr[i];
        if (arr[i] > max) max = arr[i];
    }

    int range = max - min + 1;
    int count[range];

    for (int i = 0; i < range; i++) {
        count[i] = 0;
    }

    // Calculate address and count occurrences
    for (int i = 0; i < n; i++) {
        int address = arr[i] - min;
        count[address]++;
    }

    // Rebuild the sorted array
    int k = 0;
    for (int i = 0; i < range; i++) {
        while (count[i] > 0) {
            arr[k++] = i + min;
            count[i]--;
        }
    }
}

int main(void) {
    int arr[] = {42, 15, 8, 23, 4, 16, 42, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    addressCalculationSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}