#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Function prototypes
void insertAtEnd(struct Node** head, int value);
void deleteFromBeginning(struct Node** head);
void displayList(struct Node* head);

int main() {
    struct Node* head = NULL; // Initialize the head of the list
    int choice, value;

    do {
        // Menu
        printf("\n1. Insert at End\n");
        printf("2. Delete from Beginning\n");
        printf("3. Display List\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;
            case 2:
                deleteFromBeginning(&head);
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

// Function to insert a node at the end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL; // New node's next will be updated later

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
    }
    printf("Node with value %d inserted at the end.\n", value);
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head;

    if (temp->next == *head) { // Only one node in the list
        free(temp); // Free the only node
        *head = NULL; // List is now empty
    } else {
        struct Node* last = *head;
        while (last->next != *head) { // Find the last node
            last = last->next;
        }
        last->next = temp->next; // Link the last node to the second node
        *head = temp->next; // Update head to the second node
        free(temp); // Free the old head
    }
    printf("Node deleted from the beginning.\n");
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
