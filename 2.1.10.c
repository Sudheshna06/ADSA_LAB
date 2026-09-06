#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    float value;
    struct Node *next;
} Node;

void insertSorted(Node **head, float value) {
    Node *newNode = malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= value) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL && current->next->value < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void bucketSort(float arr[], int n) {
    Node *buckets[n];

    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Put each number in its bucket
    for (int i = 0; i < n; i++) {
        int index = (int)(arr[i] * n);
        insertSorted(&buckets[index], arr[i]);
    }

    // Copy sorted buckets back to array
    int k = 0;
    for (int i = 0; i < n; i++) {
        Node *current = buckets[i];

        while (current != NULL) {
            arr[k++] = current->value;

            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }
}

int main(void) {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    bucketSort(arr, n);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}