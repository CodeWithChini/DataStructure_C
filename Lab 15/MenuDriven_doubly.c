#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node* Rptr;
    struct Node* Lptr;
};

struct Node* createNode(int info) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->info = info;
    newNode->Rptr = NULL;
    newNode->Lptr = NULL;
    return newNode;
}

void insertAtFront(struct Node** first, int info) {
    struct Node* newNode = createNode(info);
    if (*first != NULL) {
        newNode->Rptr = *first; // Set right pointer to current head
        (*first)->Lptr = newNode; // Set left pointer of current head to new node
    }
    *first = newNode; // Update head to new node
}

void deleteNodeAtPosition(struct Node** first, int position) {
    if (*first == NULL || position < 0) return;

    struct Node* temp = *first;

    for (int i = 0; i < position; i++) {
        if (temp == NULL) return;
        temp = temp->Rptr; // Move to the right node
    }

    if (temp == NULL) return;

    if (temp->Lptr != NULL)
        temp->Lptr->Rptr = temp->Rptr; // Update right pointer of the previous node
    else
        *first = temp->Rptr; // Update head if the first node is deleted

    if (temp->Rptr != NULL)
        temp->Rptr->Lptr = temp->Lptr; // Update left pointer of the next node

    free(temp); // Free the deleted node
}

void insertAtEnd(struct Node** first, int info) {
    struct Node* newNode = createNode(info);
    if (*first == NULL) {
        *first = newNode; // If the list is empty, set head to new node
        return;
    }
    struct Node* temp = *first;
    while (temp->Rptr != NULL) {
        temp = temp->Rptr; // Move to the rightmost node
    }
    temp->Rptr = newNode; // Set right pointer of last node to new node
    newNode->Lptr = temp; // Set left pointer of new node to last node
}

void displayList(struct Node* node) {
    while (node != NULL) {
        printf("%d <-> ", node->info);
        node = node->Rptr;
    }
    printf("NULL\n");
}

int main() {
    struct Node* first = NULL;
    int choice, x, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at front\n");
        printf("2. Delete from specified position\n");
        printf("3. Insert at end\n");
        printf("4. Display all nodes\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at front: ");
                scanf("%d", &x);
                insertAtFront(&first, x);
                break;
            case 2:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteNodeAtPosition(&first, position);
                break;
            case 3:
                printf("Enter data to insert at end: ");
                scanf("%d", &x);
                insertAtEnd(&first, x);
                break;
            case 4:
                displayList(first);
                break;
            case 5:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
