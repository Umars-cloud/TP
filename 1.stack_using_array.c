#include <stdio.h>
#include <stdlib.h>
#define SIZE 5
int top = -1, inp_array[SIZE];

void push();
void pop();
void peek();

int main()
{
    int choice;
    do
    {
        printf("\nPerform operation on stack:");
        printf("\n1. Push the element");
        printf("\n2. Pop the element");
        printf("\n3. Peek");
        printf("\n4. End\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
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
            printf("Exiting...\n");
            exit(0);
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    } while (1);  // Keep running until user chooses to exit
    return 0;
}

void push()
{
    int x;
    if (top == SIZE - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter element to be pushed: ");
        scanf("%d", &x);
        top++;
        inp_array[top] = x;
        printf("Element %d is added into the stack\n", x);
    }
}

void pop()
{
    if (top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Popped Element: %d\n", inp_array[top]);
        top--;
    }
}

void peek()
{
    if (top == -1)
    {
        printf("Stack is empty (Underflow)\n");
    }
    else
    {
        printf("Top element of stack: %d\n", inp_array[top]);
    }
}
