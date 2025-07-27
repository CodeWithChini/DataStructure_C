#include <stdio.h>
#include <stdlib.h>

struct Node{
    int info;
    struct Node *link;
};

struct Node *first = NULL;

void createNode(){
    first = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *four = (struct Node *)malloc(sizeof(struct Node));

    first->info = 18;
    first->link = second;

    second->info = 6;
    second->link = third;

    third->info = 10;
    third->link = four;

    four->info = 3;
    four->link = NULL;

    struct Node *save = first;

    printf("Original Likedlist:-\n");
    while(save!=NULL){
        printf("%d->", save->info);
        save = save->link;
    }
    printf("NULL\n");

}

void addNodeByGcd(){

    if(first==NULL || first->link==NULL){
        printf("List too short to insert GCD nodes.\n");
        return;
    }

    struct Node *save = first;

    while(save!=NULL && save->link!=NULL){
        int a = save->info;
        int b = save->link->info;

        int min = a < b ? a : b;
        int g;

        for(int i=1 ; i<=min ; i++){
            if(a%i==0 && b%i==0){
                g = i;
            }
        }

        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->info = g;
        newNode->link = save->link;
        save->link = newNode;

        save = newNode->link;
    }

    printf("After inserting GCD nodes:\n");

    struct Node *temp = first;
    while(temp != NULL){
        printf("%d->", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");

}

void main(){

    createNode();
    addNodeByGcd();

}
