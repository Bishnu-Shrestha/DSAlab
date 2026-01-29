/*
This is a C program to evaluate a given postfix expression.
*/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#define MAX 20

typedef struct StackDf
{
    float data[MAX];
    int top;
} vStack;

void PUSH(vStack *, float);
float POP(vStack *);
int main()
{
    vStack s;
    s.top = -1;
    char postfix[MAX + 10];
    int i = 0;
    float op1, op2, result;

    printf("Enter a vallid postfix expression:  ");
    scanf("%s", postfix);
    while (postfix[i] != '\0')
    {
        if (isalpha(postfix[i]))
        {
            float val = 0;
            printf("Enter value for %c: ", postfix[i]);
            scanf("%f", &val);
            PUSH(&s, val);
        }
        else if (postfix[i] == '^' || postfix[i] == '$' || postfix[i] == '/' || postfix[i] == '*' || postfix[i] == '+' || postfix[i] == '-')
        {
            if (s.top < 1)
            {
                printf("\nExiting program\n Invalid postfix expression!!!\n");
                return 1;
            }
            else
            {
                op2 = POP(&s);
                op1 = POP(&s);
                switch (postfix[i])
                {
                case '^':
                case '$':
                    result = pow(op1, op2);
                    break;

                case '/':
                    if (op2 == 0)
                    {
                        printf("\nExiting program\n Division by zero encountered.\a\n");
                        return 2;
                    }
                    else
                        result = op1 / op2;
                    break;
                case '*':
                    result = op1 * op2;
                    break;
                case '+':
                    result = op1 + op2;
                    break;
                case '-':
                    result = op1 - op2;
                    break;
                }
                PUSH(&s, result);
            }
        }

        i++;
    }
    printf("\nThe result is %.2f. ", s.data[s.top]);

    return 0;
}

// Function to add new top element to stack.
void PUSH(vStack *s1, float newVal)
{
    if (s1->top == MAX - 1)
    {
        printf("\n!!!!The stack is full cannot add any new elements.!!!!\n");
    }
    else
    {
        s1->top++;
        s1->data[s1->top] = newVal;
    }
}
// Function to remove the top element from an aray....
float POP(vStack *s1)
{
    if (s1->top == -1)
        return 0;
    else
    {
        float x = s1->data[s1->top];
        s1->top--;
        return x;
    }
}