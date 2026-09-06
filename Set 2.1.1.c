#include<stdio.h>
void insertsort(int arr[], int n) {

    for (int i = 1; i < n; i++) {

        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {

            arr[j + 1] = arr[j];
            j--;
        }

        arr[j + 1] = key;
    }
}

int main() {
    int arr[] = {21, 8, 24, 19, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertsort(arr, n);
    printf("Before Sorting: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }

    printf("After Sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}