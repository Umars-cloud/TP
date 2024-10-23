#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int stack[MAX_SIZE];
int top = -1;
void push(int item);
int pop();
int main()
{
    char expression[] = "567+*8-";
    int result;
    int i = 0;
    int operand1, operand2;
    while (expression[i] != '\0')
    {

        if (expression[i] >= '0' && expression[i] <= '9')
        {
            int num = expression[i] - '0';
            push(num);
        }
        else
        {
            operand2 = pop();
            operand1 = pop();
            switch (expression[i])
            {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }

            push(result);
        }
        i++;
    }
    result = pop();
    printf("result = %d\n", result);
    return 0;
}
void push(int item)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("stack overflow\n");
        return;
    }
    top++;
    stack[top] = item;
}
int pop()
{
    if (top < 0)
    {
        printf("stack overflow\n");
        return -1;
    }
    int item = stack[top];
    top--;
    return item;
}