#include <stdio.h>

void merge(int arr[], int low, int mid, int high) {
    int leftSize = mid - low + 1;
    int rightSize = high - mid;

    int left[leftSize];
    int right[rightSize];

    // Copy values into temporary arrays
    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[low + i];
    }

    for (int j = 0; j < rightSize; j++) {
        right[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = low;

    // Merge both sorted halves
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy remaining left-side values
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy remaining right-side values
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;

        // Divide array into two halves
        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        // Merge the sorted halves
        merge(arr, low, mid, high);
    }
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}




























































































































































































































