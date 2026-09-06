#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid;
    int k = left;

    while (i < mid && j < right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i < mid)
        temp[k++] = arr[i++];

    while (j < right)
        temp[k++] = arr[j++];

    for (i = left; i < right; i++)
        arr[i] = temp[i];
}

void bottomUpMergeSort(int arr[], int n) {
    int *temp = malloc(n * sizeof(int));

    // size = size of each sorted subarray
    for (int size = 1; size < n; size *= 2) {

        // Merge adjacent subarrays of length `size`
        for (int left = 0; left < n - 1; left += 2 * size) {
            int mid = left + size;
            int right = left + 2 * size;

            if (mid > n)
                mid = n;

            if (right > n)
                right = n;

            merge(arr, temp, left, mid, right);
        }
    }

    free(temp);
}

int main(void) {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    bottomUpMergeSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}