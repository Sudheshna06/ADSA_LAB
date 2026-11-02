#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

// Enqueue
void enqueue(int value)
{
    struct Node *newNode;

    newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = value;

    if (front == NULL)
    {
        front = newNode;
        rear = newNode;
        newNode->next = front;
    }
    else
    {
        newNode->next = front;
        rear->next = newNode;
        rear = newNode;
    }

    printf("%d inserted\n", value);
}

// Dequeue
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;

    printf("%d deleted\n", front->data);

    if (front == rear)
    {
        front = NULL;
        rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }

    free(temp);
}

// Display
void display()
{
    if (front == NULL)
    {
        printf("Queue is Empty\n");
        return;
    }

    struct Node *temp = front;

    printf("Queue: ");

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while (temp != front);

    printf("\n");
}

int main()
{
    int choice, value;

    while (1)
    {
        printf("\n1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}