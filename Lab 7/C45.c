// 45. You have an array A of integers of size N, an array B (initially empty) and a stack
// S (initially empty). You are allowed to do the following operations:
// • Take the first element of array A and push it into S and remove it from A.
// • Take the top element from stack S, append it to the end of array B and
// remove it from S.
// You have to tell if it possible to move all the elements of array A to array B using
// the above operations such that finally the array B is sorted in ascending order.

#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<math.h>

int A[100];
int stack[100];
int ans[100];
int top = -1;

void push(int c)
{
    stack[++top] = c;
}

int pop()
{
    if(top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int peek(){
    if(top < 0) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

int isEmpty() {
    return top == -1;
}

int stack_(int n)
{
    top = -1;
    int exp = 1;

    for (int i = 0; i < n;i++){

    }
}
