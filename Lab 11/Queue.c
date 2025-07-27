#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int info;
    struct Queue *link;
};

struct Queue *first = NULL;

void queuePush(int x) {
    struct Queue *newNode = (struct Queue *)malloc(sizeof(struct Queue));
    newNode->info = x;
    newNode->link = NULL;
    if(first == NULL)
    {
        first = newNode;
    }
    else
    {
        struct Queue *save = first;
        while (save->link != NULL)
        {
            save = save->link;
        }
        save->link = newNode;
    }

}

void queuePop() {
    if (first == NULL) {
        printf("Stack is empty\n");
    } else {
        struct Queue *temp = first;
        first = first->link;
        free(temp);
    }
}

void printLL() {
    struct Queue *temp = first;
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
        queuePush(x);
    }

    queuePop();
    printLL();
    return 0;
}
