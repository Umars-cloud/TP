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
    newNode->next = NULL;

    if (*head == NULL) { // If the list is empty, new node becomes the head
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) { // Traverse to the last node
            temp = temp->next;
        }
        temp->next = newNode; // Link the new node at the end
    }
    printf("Node with value %d inserted at the end.\n", value);
}

// Function to delete a node from the beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = *head; // Store the current head
    *head = (*head)->next; // Move head to the next node
    free(temp); // Free the old head node
    printf("Node deleted from the beginning.\n");
}

// Function to display the linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
