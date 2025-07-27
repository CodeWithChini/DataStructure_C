#include <stdio.h>
#include <string.h>

#define MAX 1000

char stack[MAX];
int top = -1;

void push(char ch) {
    if (top < MAX - 1) {
        stack[++top] = ch;
    }
}

char pop() {
    if (top == -1) return '\0';
    return stack[top--];
}

char peek() {
    if (top == -1)
   {
        return '\0';
   }
    return stack[top];
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}


int isBalanced(char *str) {
    top = -1;
    for (int i = 0; str[i]; i++) {
        char ch = str[i];
        if (ch == '(' || ch == '{' || ch == '[') {
            push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            char open = pop();
            if (!isMatchingPair(open, ch)) {
                return 0;
            }
        }
    }
    return top == -1; // If stack is empty
}

int main() {
    int T;
    printf("Enter the string to check for balanced parentheses: ");
    scanf("%d", &T);
    while (T--) {
        char str[MAX];
        scanf("%s", str);
        printf("%d\n", isBalanced(str));
    }
    return 0;
}
