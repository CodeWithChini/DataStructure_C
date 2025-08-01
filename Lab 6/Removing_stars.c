// 38. Removing starts from a string Problem
// You are given a string s, which contains stars *. In one operation, you can:
// Choose a star in s. Remove the closest non-star character to its left, as well as
// remove the star itself. Return the string after all stars have been removed.
// Note :
// • The input will be generated such that the operation is always possible.
// • It can be shown that the resulting string will always be unique.



#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

char stack[MAX_LENGTH];
int top = -1;

void push(char ch)
{
    if (top < MAX_LENGTH - 1)
    {
        stack[++top] = ch;
    }
}

char pop()
{
    if (top == -1)
    {
        return '\0';
    }
    return stack[top--];
}

void removeStars(char s[])
{
    top = -1;  // Reset stack

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == '*')
        {
            pop();  // Remove the last non-star character
        }
         else
         {
            push(s[i]);  // Push non-star characters onto the stack
        }
    }

    int Idx = 0;
    while (top != -1)
    {
        s[Idx++] = pop();  // Pop characters from the stack
    }
    s[Idx] = '\0';  // Null-terminate the modified string

    for (int i = 0; i < Idx / 2; i++)
    {
        char temp = s[i];
        s[i] = s[Idx - 1 - i];
        s[Idx - 1 - i] = temp;
    }
}

int main()
{
    char input[MAX_LENGTH];

    printf("Enter a string with stars: ");
    fgets(input, MAX_LENGTH, stdin);

    printf("Original string: \"%s\"\n", input);

    removeStars(input);

    printf("After star removal: \"%s\"\n", input);

    return 0;
}
