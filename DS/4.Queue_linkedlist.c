#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

// Initialize front and rear pointers
struct Node* front = NULL;
struct Node* rear = NULL;

// Function prototypes
void enqueue();
void dequeue();
void displayFront();
void displayQueue();

int main() {
    int choice;

    do {
        // Menu
        printf("\nMenu Driven Program to Implement Queue using Linked List:\n");
        printf("1. Enqueue (Add element)\n");
        printf("2. Dequeue (Remove element)\n");
        printf("3. Display Front Element\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Execute based on user choice
        switch(choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                displayFront();
                break;
            case 4:
                displayQueue();
                break;
            case 5:
                printf("Exiting...\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (1);

    return 0;
}

// Function to add an element to the queue
void enqueue() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }

    printf("Enter the value to be added: ");
    scanf("%d", &value);

    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL) {
        // If the queue is empty
        front = rear = newNode;
    } else {
        // Add the new node at the end and update rear
        rear->next = newNode;
        rear = newNode;
    }

    printf("Element %d added to the queue\n", value);
}

// Function to remove an element from the queue
void dequeue() {
    if (front == NULL) {
        printf("Queue Underflow\n");
        return;
    }

    struct Node* temp = front;
    front = front->next;

    if (front == NULL) {
        // If the queue becomes empty
        rear = NULL;
    }

    printf("Dequeued element: %d\n", temp->data);
    free(temp);
}

// Function to display the front element
void displayFront() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        printf("Front element: %d\n", front->data);
    }
}

// Function to display all elements in the queue
void displayQueue() {
    if (front == NULL) {
        printf("Queue is empty\n");
    } else {
        struct Node* temp = front;
        printf("Queue elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
