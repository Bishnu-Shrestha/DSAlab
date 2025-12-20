/*
This is a menu driven C program that performs the various STACK operations
like PUSH, POP, PEEK and finally also display the contents of the stack.
*/

#include <Stdio.h>
#define MAX 10

typedef struct StackDf
{
    int data[MAX];
    int top;
} stack;

// Function prototypes..
void PUSH(int, stack *);
void POP(stack *);
void PEEK(stack *);
void DISPLAY(stack *);

int main()
{
    stack S;
    S.top = -1;
    int ch = 0, n;
    while (ch != 5)
    {
        printf("\n****MENU****\n  1) PUSH\n  2) POP\n  3) PEEK\n  4) DISPLAY\n  5) EXIT\n");
        printf("Enter your choice of operation(1-5): ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter data to be added: ");
            scanf("%d", &n);
            PUSH(n, &S);
            break;
        case 2:
            POP(&S);
            break;
        case 3:
            PEEK(&S);
            break;
        case 4:
            DISPLAY(&S);
            break;
        case 5:
            printf("Exitted successfully.\n");
            break;
        default:
            printf("\a\nInvalid input try again......\n");
        }
    }
    return 0;
}

// Function to add new top element to stack.
void PUSH(int newVal, stack *s1)
{

    if (s1->top == MAX - 1)
    {
        printf("\n!!!!The stack is full cannot add any new elements.!!!!\n");
    }
    else
    {
        s1->top++;
        s1->data[s1->top] = newVal;

        printf("\n%d added to stack successfully.\n", newVal);
    }
}

// Function to delete the top element in a stack.
void POP(stack *s1)
{
    if (s1->top == -1)
        printf("\nThe stack is empty.\n");
    else
    {
        int x = s1->data[s1->top];
        s1->top--;
        printf("\nThe data %d was removed from the stack.\n", x);
    }
}

// Function to display top element present in the stack.
void PEEK(stack *s1)
{
    if (s1->top == -1)
        printf("\nThe stack is empty.\n");
    else
        printf("\nThe value at top of the stack is %d.\n", s1->data[s1->top]);
}

// Function to display all elements present in the stack.
void DISPLAY(stack *s1)
{
    if (s1->top == -1)
        printf("\nThe stack is empty.\n");
    else
    {
        printf("\nDisplaying the data in stack:\n\t");
        for (int i = s1->top; i >= 0; i--)
        {
            printf("%d\t", s1->data[i]);
        }
    }
}