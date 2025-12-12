#include <stdio.h>
#define MAX 20

typedef struct StackDf
{
    char data[MAX];
    int top;
} stack;

void PUSH(stack *, char);
char POP(stack *);
int chkPrecedence(char);
void DISPLAY(stack *s1);

int main()
{
    stack postfixExpr;
    stack operator;
    postfixExpr.top = -1;
    operator.top = -1;
    char expression[MAX];
    int i = 0;
    printf("Enter the infix expression for conversion to postfix:");
    scanf("%s", expression);
    while (expression[i] != '\0')
    {
        printf("\nFor data %c of the expression: ", expression[i]);
        if ((expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= 'a' && expression[i] <= 'z'))
        {
            PUSH(&postfixExpr, expression[i]);
            printf(" Pushed to the prefix stack %c.\n", expression[i]);
        }

        if (expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-' || expression[i] == '^')
        {

            while (chkPrecedence(operator.data[operator.top]) >= chkPrecedence(expression[i]))
            {
                char y = POP(&operator);
                PUSH(&postfixExpr, y);
                printf(" Pushed to the postfix stack %c.\n", y);
            }

            if (chkPrecedence(operator.data[operator.top]) < chkPrecedence(expression[i]))
            {
                PUSH(&operator, expression[i]);
                printf(" Pushed to the operator stack %c.\n", expression[i]);
            }
        }
        if (expression[i] == '(')
        {
            PUSH(&operator, expression[i]);
        }
        if (expression[i] == ')')
        {

            while (operator.top != -1 && operator.data[operator.top] != '(')
            {
                char y = POP(&operator);
                PUSH(&postfixExpr, y);
                printf(" Pushed to the postfix stack %c.\n", y);
            }

            if (operator.data[operator.top] == '(')
            {
                POP(&operator);
            }
        }

        i++;
        printf("\n\n Postfix expression stack:\n");
        DISPLAY(&postfixExpr);
        printf("\n Operator stack:\n");
        DISPLAY(&operator);
        printf("\n Pass %d completed:\n\n", i);
    }
    if (expression[i] == '\0')
    {
        while (operator.top != -1)
        {
            char y = POP(&operator);
            PUSH(&postfixExpr, y);
            printf(" Pushed to the postfix stack %c.\n", y);
        }
        }

    printf("\n The expression is %s.\n", expression);
    DISPLAY(&postfixExpr);

    return 0;
}

// Function to add new top element to stack.
void PUSH(stack *s1, char newVal)
{

    if (s1->top == MAX - 1)
    {
        printf("\a!!!!The stack is full cannot add any new elements.!!!!\n");
    }
    else
    {
        s1->top++;
        s1->data[s1->top] = newVal;

        // printf("\n%c added to stack successfully.\n", newVal);
    }
}
// Function to remove the top element from an aray....
char POP(stack *s1)
{
    if (s1->top == -1)
        printf("\nThe stack is empty.\n");
    else
    {
        char x = s1->data[s1->top];
        s1->top--;
        // printf("\nThe data %c was removed from the stack.\n", x);
        return x;
    }
}
// Function to check for precedence of the operators....
int chkPrecedence(char a)
{
    int n = 6;
    char ops[6] = {'(', '-', '+', '*', '/', '^'};
    for (int i = 0; i < n; i++)
    {
        if (a == ops[i])
        {
            if (i == 1 || i == 2)
            {
                i = 2;
            }
            if (i == 3 || i == 4)
            {
                i = 4;
            }

            return i;
        }
    }
    return -1;
}

// Function to display all elements present in the stack.
void DISPLAY(stack *s1)
{
    if (s1->top == -1)
        printf("\nThe stack is empty.\n");
    else
    {
        printf("\nDisplaying Stack:\n\t");
        for (int i = 0; i <= s1->top; i++)
        {
            printf(" %c", s1->data[i]);
        }
    }
}