#include <stdio.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char c){
    stack[++top] = c;
}

int pop(){
    return stack[top--];
}

int stackPrecedence(char c){
    if(c == '+' || c == '-'){
        return 2;
    }
    else if(c == '*' || c == '/'){
        return 4;
    }
    else if(c == '^'){
        return 5;
    }
    else if(c == '('){
        return 0;
    }
    else{
        return 8;
    }
}

int inputPrecedence(char c){
    if(c == '+' || c == '-'){
        return 1;
    }
    else if(c == '*' || c == '/'){
        return 3;
    }
    else if(c == '^'){
        return 6;
    }
    else if(c == '('){
        return 9;
    }
    else if(c == ')'){
        return 0;
    }
    else{
        return 7;
    }
}

int rankUpdate(char c){
    if(c == '+' || c == '-' || c == '*' || c == '/' || c =='^'){
        return -1;
    }
    else{
        return 1;
    }
}

void revpol(char infix[]){
    char prefix[100];
    int rank = 0;
    int i = 0, j = 0;

    push('(');

    while(i != strlen(infix)){
        char next = infix[i];

        if(top<0){
            printf("Invalid Expression.");
            return;
        }

        while(stackPrecedence(stack[top]) > inputPrecedence(next)){
            char temp = pop();
            prefix[j++] = temp;
            rank += rankUpdate(temp);
            if(rank < 1){
                printf("Invalid Expression.");
                return;
            }
        }

        if(stackPrecedence(stack[top]) != inputPrecedence(next)){
            push(next);
        }
        else{
            char temp = pop();
        }
        i++;
    }

    prefix[j] = '\0';
    if(top != -1 || rank != 1){
        printf("Invalid");
    }
    else{
        printf("Prefix Expression is: %s", strrev(prefix));
    }
}

void main(){
    char infix[100], revInfix[100];
    int i, k = 0;

    printf("Enter the infix expression: ");
    scanf("%s",infix);

    for(i = strlen(infix)-1 ; i>=0 ; i--){
        if(infix[i] == ')'){
            revInfix[k++] = '(';
        }
        else if(infix[i] == '('){
            revInfix[k++] = ')';
        }
        else{
            revInfix[k++] = infix[i];
        }
    }

    revInfix[k] = '\0';
    strcat(revInfix,")");
    revpol(revInfix);
}
