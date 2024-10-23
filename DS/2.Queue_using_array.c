#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int rear = -1, front = -1;
int Q[SIZE];
void enqueue();
void dequeue();
void isEmpty();
void isFull();
int main()
{
    int choice, k;
    do
    {
        printf("\nPerform operations on the queue:\n");
        printf("1. Enqueue\n2. Dequeue\n3. isFull\n4. isEmpty\n5. Exit\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            isFull();
            break;
        case 4:
            isEmpty();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
            break;
        }
        printf("\nEnter 1 to continue or any other key to exit: ");
        scanf("%d", &k);
    } while (k == 1);
    return 0;
}
void enqueue()
{
    int x;
    printf("Enter an element: ");
    scanf("%d", &x);
    if (rear == SIZE - 1)
    {
        printf("Overflow\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear++;
        Q[rear] = x;
        printf("Enqueued: %d\n", x);
    }
}
void dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Underflow\n");
    }
    else
    {
        printf("Dequeued: %d\n", Q[front]);
        front++;
    }
    if (front > rear)
    {
        front = rear = -1; // Reset the queue after dequeuing the last element
    }
}
void isFull()
{

    if (rear == SIZE - 1)
    {
        printf("Queue is full\n");
    }
    else
    {
        printf("Queue is not full\n");
    }
}
void isEmpty()
{
    if (front == -1 || front > rear)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("Queue is not empty\n");
    }
}

