#include <stdio.h>
#define MAX 20

typedef struct StackDf
{
    char data[MAX];
    int top;
} stack;
// function prototypes..
void PUSH(stack *, char);
char POP(stack *);
int chkPrecedence(char);
void DISPLAY(stack *s1);
void stackToArr(stack *s1, char *);

int main()
{
    stack postfixExpr, operator;
    postfixExpr.top = -1;
    operator.top = -1;
    char expression[MAX], a[MAX], b[MAX];
    int i = 0;
    printf("Enter the infix expression for conversion to postfix: ");
    scanf("%s", expression);
    printf("\nInfix to postfix conversion table:\n");
    printf("\n| %2s | %-18s | %-24s | %-8s |\n", "SN", "Scanned Character", "Prefix expression stack", "OPstack");

    for (int i = 0; i < 65; i++)
    {
        printf("-");
    }
    printf("\n");
    while (expression[i] != '\0')
    {
        if ((expression[i] >= 'A' && expression[i] <= 'Z') || (expression[i] >= 'a' && expression[i] <= 'z'))
        {
            PUSH(&postfixExpr, expression[i]);
        }

        if (expression[i] == '*' || expression[i] == '/' || expression[i] == '+' || expression[i] == '-' || expression[i] == '^')
        {

            while (chkPrecedence(operator.data[operator.top]) >= chkPrecedence(expression[i]))
            {
                char y = POP(&operator);
                PUSH(&postfixExpr, y);
            }

            if (chkPrecedence(operator.data[operator.top]) < chkPrecedence(expression[i]))
            {
                PUSH(&operator, expression[i]);
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
            }

            if (operator.data[operator.top] == '(')
            {
                POP(&operator);
            }
        }

        stackToArr(&postfixExpr, a);
        stackToArr(&operator, b);
        printf("| %2d | %-18c | %-24s | %-8s |\n", i + 1, expression[i], a, b);
        i++;
    }
    if (expression[i] == '\0')
    {
        while (operator.top != -1)
        {
            char y = POP(&operator);
            PUSH(&postfixExpr, y);
        }
        stackToArr(&postfixExpr, a);
        stackToArr(&operator, b);
        printf("| %2d | %-18c | %-24s | %-8s |\n", i + 1, '!', a, b);
    }

    printf("\n The given infix expression is:\n\t%s.\n", expression);
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
    }
}
// Function to remove the top element from an aray....
char POP(stack *s1)
{
    if (s1->top == -1)
        return '!';
    else
    {
        char x = s1->data[s1->top];
        s1->top--;
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
        printf("\n The stack is empty.\n");
    else
    {
        printf("\n Displaying Stack:\n\t");
        for (int i = 0; i <= s1->top; i++)
        {
            printf("%c", s1->data[i]);
        }
        printf("\n");
    }
}
// function to convert the stack data into an array of characters to display it in the table.
void stackToArr(stack *s1, char *a)
{
    int i = 0;

    if (s1->top == -1)
    {
        a[i] = '!';
        a[i + 1] = '\0';
    }
    else
    {
        for (i = 0; i <= s1->top; i++)
        {
            a[i] = s1->data[i];
        }
        a[i] = '\0';
    }
}