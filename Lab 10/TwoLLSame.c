#include <stdio.h>
#include <stdlib.h>

struct Node1{
    int info;
    struct Node1 *link;
};

struct Node2{
    int info;
    struct Node2 *link;
};

struct Node1 *first1 = NULL;
struct Node2 *first2 = NULL;

void createNode1(){
    struct Node1 *newNode1 = (struct Node1 *)malloc(sizeof(struct Node1));
    newNode1->link = NULL;

    if(first1==NULL){
        first1 = newNode1;
    }
    else{
        struct Node1 *save1 = first1;

        while(save1->link!=NULL){
            save1 = save1->link;
        }
        save1->link = newNode1;
    }
}

void createNode2(){
    struct Node2 *newNode2 = (struct Node2 *)malloc(sizeof(struct Node2));
    newNode2->link = NULL;

    if(first2==NULL){
        first2 = newNode2;
    }
    else{
        struct Node2 *save2 = first2;

        while(save2->link!=NULL){
            save2 = save2->link;
        }
        save2->link = newNode2;
    }
}

void insertInfo1(){
    struct Node1 *save1 = first1;

    if(first1==NULL){
        printf("Linked list is empty.\n");
        return;
    }

    printf("Enter elements: ");
    while(save1!=NULL){
        scanf("%d", &save1->info);
        printf("%d->", save1->info);
        save1 = save1->link;
    }
    printf("NULL\n");

}

void insertInfo2(){
    struct Node2 *save2 = first2;

    if(first2==NULL){
        printf("Linked list is empty.\n");
        return;
    }

    printf("Enter elements: ");
    while(save2!=NULL){
        scanf("%d", &save2->info);
        printf("%d->", save2->info);
        save2 = save2->link;
    }
    printf("NULL\n");
}

void sameLinkedlist(){

    struct Node1 *save1 = first1;
    struct Node2 *save2 = first2;

    while(save1 != NULL && save2 != NULL){
        if(save1->info != save2->info){
            printf("Linked lists are not same (different data at a node).\n");
            return;
        }
        save1 = save1->link;
        save2 = save2->link;
    }

    if(save1 == NULL && save2 == NULL){
        printf("Linked lists are same.\n");
    }
    else{
        printf("Linked lists are not same (different lengths).\n");
    }

}

void main(){
    int a;
    printf("Enter a number of total nodes for first linkedlist: ");
    scanf("%d", &a);

    for(int i=1 ; i<=a ; i++){
        createNode1();
    }

    insertInfo1();

    int b;
    printf("Enter a number of total nodes for second linkedlist: ");
    scanf("%d", &b);

    for(int i=1 ; i<=b ; i++){
        createNode2();
    }

    insertInfo2();

    sameLinkedlist();

}
