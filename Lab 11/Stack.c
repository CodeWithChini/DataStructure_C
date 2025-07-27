#include <stdio.h>
#include <stdlib.h>

struct Stack {
    int info;
    struct Stack *link;
};

struct Stack *first = NULL;

void stackPush(int x) {
    struct Stack *newNode = (struct Stack *)malloc(sizeof(struct Stack));
    newNode->info = x; // Set the info for the new node
    newNode->link = first; // Link the new node to the previous first node
    first = newNode; // Update first to point to the new node
}

void stackPop() {
    if (first == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Stack *temp = first; // Save the current first node
        first = first->link; // Update first to the next node
        free(temp); // Free the old first node
    }
}

void printLL() {
    struct Stack *temp = first;
    while (temp != NULL) {
        printf("%d", temp->info);
        temp = temp->link;
        if (temp != NULL) {
            printf(" -> ");
        }
    }
    printf("\n");
}

int main() {
    int n, x;
    printf("Enter the number of nodes you want to create: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter a number: ");
        scanf("%d", &x);
        stackPush(x);
    }

    stackPop(); // Pop the top element
    printLL(); // Print the stack
    return 0;
}
