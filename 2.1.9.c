#include <stdio.h>

#define MAX 100  // maximum possible value in the array

void countingSort(int arr[], int n) {
    int count[MAX + 1] = {0};
    int output[n];

    // Count frequency of each value
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Convert count[] to cumulative positions
    for (int i = 1; i <= MAX; i++) {
        count[i] += count[i - 1];
    }

    // Build sorted output (right-to-left keeps it stable)
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    // Copy back
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main(void) {
    int arr[] = {4, 2, 2, 8, 3, 3, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    countingSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}