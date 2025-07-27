#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *link;
};

struct Node *First = NULL;

void insertAtFirst() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Value of New Node: ");
    scanf("%d", &newNode->info);

    newNode->link = First;
    First = newNode;
}

void insertAtEnd() {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    printf("Enter Value of New Node: ");
    scanf("%d", &newNode->info);

    newNode->link = NULL;

    if (First == NULL) {
        First = newNode;
    } else {
        struct Node *save = First;
        while (save->link != NULL) {
            save = save->link;
        }
        save->link = newNode;
    }
}

void deleteAtFirst() {
    if (First == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node *save = First;
    First = First->link;
    free(save);
}

void deleteAtEnd() {
    if (First == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    if (First->link == NULL) {
        free(First);
        First = NULL;
        return;
    }
    struct Node *save = First;
    while (save->link->link != NULL) {
        save = save->link;
    }
    free(save->link);
    save->link = NULL;
}

void deleteAtSpecificPosition(int position) {
    if (First == NULL) {
        printf("Linked list is empty\n");
        return;
    }
    struct Node *save = First;

    if (position == 0) {
        First = save->link;
        free(save);
        return;
    }

    for (int i = 0; save != NULL && i < position - 1; i++) {
        save = save->link;
    }

    if (save == NULL || save->link == NULL) {
        printf("Position not found\n");
        return;
    }

    struct Node *temp = save->link;
    save->link = temp->link;
    free(temp);
}

int countNodes() {
    int count = 0;
    struct Node *current = First;

    while (current != NULL) {
        count++;
        current = current->link;
    }
    printf("Number of nodes: %d\n", count);
    return count;
}

void displayLL() {
    struct Node *temp = First;
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->link;
    }
    printf("NULL\n");
}

int main() {
    int choice, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert at first\n");
        printf("2. Delete first node\n");
        printf("3. Insert at end\n");
        printf("4. Delete last node\n");
        printf("5. Delete node at specified position\n");
        printf("6. Count number of nodes\n");
        printf("7. Display all nodes\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                insertAtFirst();
                break;
            case 2:
                deleteAtFirst();
                break;
            case 3:
                insertAtEnd();
                break;
            case 4:
                deleteAtEnd();
                break;
            case 5:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtSpecificPosition(position);
                break;
            case 6:
                countNodes();
                break;
            case 7:
                displayLL();
                break;
            case 0:
                printf("Exit\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 0);

    return 0;
}
