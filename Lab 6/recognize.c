#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define size 100

int stack[size];
int top = -1;

void stackPush(int x) {
    if (top >= size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = x;
}

int stackPop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void recognize()
{
    top = -1; // Reset stack
    stackPush('c'); // Push marker character
    char nextChar = '\0';

    while ((nextChar = getchar()) != '\n' && nextChar != EOF)
    {
        if (nextChar == ' ')
        {
            printf("Invalid String\n");
            return;
        }
        else
        {
            stackPush(nextChar);
        }
    }

    while (top >= 0 && stack[top] != 'c')
    {
        nextChar = getchar();
        char x = stackPop();
        if (nextChar != x) {
            printf("Invalid String\n");
            return;
        }
    }
    nextChar = getchar();
    if (nextChar == ' ' || nextChar == '\n')
    {
        printf("Valid String\n");
    }
    else
    {
        printf("Invalid String\n");
    }
}

int main()
{
    char str[size];
    while (1) {
        fgets(str, size, stdin);
        if (str[0] == '\n') break;
        recognize();
    }
}
