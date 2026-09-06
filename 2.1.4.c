#include <stdio.h>

void shellSort(int arr[], int n) {
    int gap, i, j, current;

    // Start with a gap equal to half the array size
    for (gap = n / 2; gap > 0; gap /= 2) {

        // Perform insertion sort for elements `gap` positions apart
        for (i = gap; i < n; i++) {
            current = arr[i];
            j = i;

            // Shift larger gap-separated elements to the right
            while (j >= gap && arr[j - gap] > current) {
                arr[j] = arr[j - gap];
                j -= gap;
            }

            // Put current value in its correct position
            arr[j] = current;
        }
    }
}

int main() {
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    shellSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

