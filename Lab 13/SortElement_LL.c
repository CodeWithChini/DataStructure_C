#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int info;
    struct Node* link;
};

struct Node* First = NULL;

// Function to create a new node and add it to the linked list
void CreateNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("New node not created\n");
        return;
    }

    newNode->info = info;
    newNode->link = NULL;

    if (First == NULL) {
        First = newNode;
    } else {
        struct Node* save = First;
        while (save->link != NULL) {
            save = save->link;
        }
        save->link = newNode;
    }
}

// Function to sort the linked list using bubble sort
void sortLL() {
    if (First == NULL || First->link == NULL) {
        printf("List is empty or has one element, no need to sort\n");
        return;
    }

    struct Node* save = First;
    struct Node* temp = NULL;
    int swapLL;

    while (save != NULL) {
        temp = save->link;
        while (temp != NULL) {
            if (save->info > temp->info) {
                swapLL = save->info;
                save->info = temp->info;
                temp->info = swapLL;
            }
            temp = temp->link;
        }
        save = save->link;
    }
}

// Function to print the linked list
void printList() {
    struct Node* current = First;
    while (current != NULL) {
        printf("%d -> ", current->info);
        current = current->link;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n, info;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter value for node %d: ", i + 1);
        scanf("%d", &info);
        CreateNode(info);
    }

    printf("Original Linked List: ");
    printList();

    sortLL();

    printf("Sorted Linked List: ");
    printList();

    return 0;
}
