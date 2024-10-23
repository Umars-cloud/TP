#include <stdio.h>
#include <stdlib.h>

// Define a node structure
struct Node {
    int data;
    struct Node* next;
};

struct Node* top = NULL;  // Initialize top to NULL

// Function prototypes
void push();
void pop();
void peek();
void display();

int main() {
    int choice;
    
    do {
        // Menu
        printf("\nMenu Driven Program to Implement Stack using Linked List:\n");
        printf("1. Push the element\n");
        printf("2. Pop the element\n");
        printf("3. Peek (Top element)\n");
        printf("4. Display Stack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        // Execute based on user choice
        switch(choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
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

// Function to push an element to the stack
void push() {
    int value;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    
    if (!newNode) {
        printf("Heap Overflow\n");
        return;
    }
    
    printf("Enter the value to be pushed: ");
    scanf("%d", &value);
    
    newNode->data = value;
    newNode->next = top;
    top = newNode;
    
    printf("Element %d pushed to stack\n", value);
}

// Function to pop an element from the stack
void pop() {
    if (top == NULL) {
        printf("Stack Underflow\n");
        return;
    }
    
    struct Node* temp = top;
    top = top->next;
    printf("Popped element: %d\n", temp->data);
    free(temp);
}

// Function to display the top element (Peek)
void peek() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        printf("Top element: %d\n", top->data);
    }
}

// Function to display the entire stack
void display() {
    if (top == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Node* temp = top;
        printf("Stack elements: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
