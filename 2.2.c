#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int left;
    int right;
    int state;  // 0 = divide, 1 = merge
} StackNode;

void merge(int arr[], int temp[], int left, int mid, int right) {
    int i = left;
    int j = mid + 1;
    int k = left;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = left; i <= right; i++)
        arr[i] = temp[i];
}

void mergeSortNonRecursive(int arr[], int n) {
    if (n <= 1)
        return;

    int *temp = malloc(n * sizeof(int));
    StackNode *stack = malloc(2 * n * sizeof(StackNode));
    int top = -1;

    // Start with entire array
    stack[++top] = (StackNode){0, n - 1, 0};

    while (top >= 0) {
        StackNode current = stack[top--];

        int left = current.left;
        int right = current.right;

        if (left >= right)
            continue;

        int mid = left + (right - left) / 2;

        if (current.state == 0) {
            /*
             * Divide task:
             * Push merge operation first, then right and left subarrays.
             * Stack is LIFO, so left part is processed first.
             */
            stack[++top] = (StackNode){left, right, 1};
            stack[++top] = (StackNode){mid + 1, right, 0};
            stack[++top] = (StackNode){left, mid, 0};
        } else {
            // Both halves have been sorted; merge them.
            merge(arr, temp, left, mid, right);
        }
    }

    free(temp);
    free(stack);
}

int main(void) {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    mergeSortNonRecursive(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\n");
    return 0;
}