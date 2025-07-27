#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define size 100

int stack[size];
int top = -1;

void stackPush(int x) {
    if (top >= size - 1) {
        printf("Stack Overflow\n");
        return;
    }
    top++;
    stack[top] = x;
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
    top = 0;
    stack[top] = 'c';
    char nextChar;

    while(nextChar != 'c' && nextChar != '\0') {
        nextChar = getchar();
        if (nextChar == ' ') {
            printf("Invalid String\n");
            return;
        } else {
            stackPush(nextChar);
        }

    }
    while(stack[top] != 'c') {
        nextChar = getchar();
        char x = stackPop();
        if (nextChar != x) {
            printf("Invalid String\n");
            return;
        }
    }
    nextChar = getchar();
    if(nextChar == ' ') {
        printf("Valid String\n");
    } else {
        printf("Invalid String\n");
    }
}
 int main() {
    char str[size];
    while (1) {
        char str[size];
        fgets(str, size, stdin);
        if (str[0] == '\n') break; // Exit on empty line
        recognize(str);
    }

}







/*


/*#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAXSIZE 100

typedef struct Stack {
    char items[MAXSIZE];
    int top;
} Stack;

void initStack(Stack *s) {
    s->top = -1;
    s->items[s->top + 1] = 'c'; // Initialize stack with 'c'
}

bool isFull(Stack *s) {
    return s->top == MAXSIZE - 1;
}

bool isEmpty(Stack *s) {
    return s->top == -1;
}

void push(Stack *s, char item) {
    if (!isFull(s)) {
        s->items[++s->top] = item;
    }
}

char pop(Stack *s) {
    if (!isEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0'; // Stack is empty, return null character
}

void recognize(char *string) {
    Stack s;
    initStack(&s);

    char nextChar;
    int i = 0;

    // Get and PUSH symbols until 'c' or blank is encountered
    while (string[i] != '\0' && string[i] != 'c') {
        nextChar = string[i++];
        if (nextChar == ' ') {
            printf("Invalid String\n");
            return;
        }
        push(&s, nextChar);
    }

    // Scan characters following 'c'; Compare them to the characters on stack
    if (string[i] == 'c') {
        i++; // Move past 'c'

        while (!isEmpty(&s)) {
            nextChar = string[i++];
            char x = pop(&s);
            if (nextChar != x) {
                printf("Invalid String\n");
                return;
            }
        }

        // Next symbol must be blank
        nextChar = string[i];
        if (nextChar == ' ') {
            printf("Valid String\n");
        } else {
            printf("Invalid String\n");
        }
    } else {
        printf("Invalid String\n");
    }
}

int main() {
    char *strings[] = {"aca", "bcb", "abcba", "abbcbba", NULL};
    for (int j = 0; strings[j] != NULL; j++) {
        printf("Testing string: %s\n", strings[j]);
        recognize(strings[j]);
    }
    return 0;
}
*/


















/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100 // Maximum size of the stack

// Function prototypes
void push(char stack[], int *top, char value);
char pop(char stack[], int *top);
char nextChar(char *string, int *index);

int main() {
    char stack[MAX];
    int top = 0;
    char inputString[MAX];
    char nextCharValue;
    char x;

    // Step 1: Initialize stack by placing a letter 'c' on the top
    stack[top++] = 'c';

    // Step 2: Get and PUSH symbols until either 'c' or blank is encountered
    printf("Enter a string: ");
    fgets(inputString, sizeof(inputString), stdin);

    int index = 0; // To track the current character in the input string
    nextCharValue = nextChar(inputString, &index);

    while (nextCharValue != 'c' && nextCharValue != '\0') {
        if (nextCharValue == ' ') {
            printf("Invalid String\n");
            return 0;
        } else {
            push(stack, &top, nextCharValue);
        }
        nextCharValue = nextChar(inputString, &index);
    }

    // Step 3: Scan characters following 'c'; compare them to the characters on stack
    while (stack[top - 1] != 'c') {
        nextCharValue = nextChar(inputString, &index);
        x = pop(stack, &top);

        if (nextCharValue != x) {
            printf("INVALID STRING\n");
            return 0;
        }
    }

    // Step 4: Next symbol must be blank
    nextCharValue = nextChar(inputString, &index);
    if (nextCharValue == ' ') {
        printf("VALID STRING\n");
    } else {
        printf("INVALID STRING\n");
    }

    return 0;
}

// Function to push a character onto the stack
void push(char stack[], int *top, char value) {
    stack[(*top)++] = value;
}

// Function to pop a character from the stack
char pop(char stack[], int *top) {
    return stack[--(*top)];
}

// Function to get the next character from the string
char nextChar(char *string, int *index) {
    if (string[*index] == '\0') {
        return '\0'; // No more characters in the string
    }
    return string[(*index)++];
}
*/
