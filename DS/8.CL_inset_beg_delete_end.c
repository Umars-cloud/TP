#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtBeginning(struct Node** head, int value);
void deleteFromEnd(struct Node** head);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL; // Initialize the head of the list
    int choice, value;

    do {
        // Menu
        printf("\n1. Insert at Beginning\n");
        printf("2. Delete from End\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;
            case 2:
                deleteFromEnd(&head);
                break;
            case 3:
                displayList(head);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

// Function to insert a node at the beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;

    if (*head == NULL) { // If the list is empty
        newNode->next = newNode; // Point to itself
        *head = newNode; // New node becomes the head
    } else {
        struct Node* temp = *head;
        while (temp->next != *head) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link the last node to new node
        newNode->next = *head; // New node points to the head
        *head = newNode; // Update head to new node
    }
    printf("Node with value %d inserted at the beginning.\n", value);
}

// Function to delete a node from the end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;
    if (temp->next == *head) { // Only one node in the list
        free(*head);
        *head = NULL; // List is now empty
        printf("Node deleted from the end.\n");
        return;
    }

    // Traverse to the second last node
    while (temp->next->next != *head) {
        temp = temp->next;
    }
    free(temp->next); // Free the last node
    temp->next = *head; // Update the second last node's next to head
    printf("Node deleted from the end.\n");
}

// Function to display the circular linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Circular Linked List: ");
    do {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(back to %d)\n", head->data);
}
