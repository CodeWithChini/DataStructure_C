#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int stack[100];
int top = -1;

void push(int c)
{
    stack[++top] = c;
}

int pop()
{
    return stack[top--];
}

void evaluate_postfix(char postfix[])
{
    int i;
    for(i=0; i<strlen(postfix);i++)
    {
        if(isdigit(postfix[i]))
            push(postfix[i] - '0');

        else
        {
            int operand1 = pop();
            int operand2 = pop();

            switch (postfix[i])
            {
                case '+':
                push(operand1 + operand2);
                break;

                case '-':
                push(operand1 - operand2);
                break;

                case '*':
                push(operand1 * operand2);
                break;

                case '/':
                push(operand1 / operand2);
                break;

                case '^':
                push(pow(operand1, operand2));
                break;
            }
        }
    }
}

void main()
{
    char postfix[100];
    printf("Enter a postfix expression: ");
    scanf("%s", postfix);
    evaluate_postfix(postfix);
    printf("Answer: %d\n", pop());
}
